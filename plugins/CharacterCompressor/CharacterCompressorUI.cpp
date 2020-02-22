/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2015 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "CharacterCompressUI.hpp"
#include "dsp/CharacterCompressor.hpp"
#include "Window.hpp"
#include <iostream>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

CharacterCompressorUI::CharacterCompressorUI()
    : UI(500, 250)
{

    widgetPtr = nullptr;
    dblWidgetPtr = &widgetPtr;

    drawTooltip = false;

    Window &pw = getParentWindow();
    pw.addIdleCallback(this);
    loadSharedResources();
    fNanoFont = findFont(NANOVG_DEJAVU_SANS_TTF);
    const Size<uint> knobSize(80, 100);
    const float knobRadius = 35;
    const int knob_x_spacing = 90;
    const int knob_x = 40;
    const int knob_y = 20;

    newTime = std::chrono::high_resolution_clock::now();
    oldTime = newTime;

    fNanoMeter = new NanoMeter(this);
    fNanoMeter->setId(p_gainReduction);
    fNanoMeter->setAbsolutePos(10, 10);
    fNanoMeter->setSize(10, knobSize.getHeight());
    fNanoMeter->setRange(paramRange[p_gainReduction].min, paramRange[p_gainReduction].max);
    fNanoMeter->setValue(paramRange[p_gainReduction].def);
    fNanoMeter->setZ(2);

    fInGain = new NanoSlider(this, this);
    fInGain->setId(p_Input_Gain);
    fInGain->setAbsolutePos(knob_x, knob_y);
    fInGain->setSize(20, 100);
    fInGain->setValue(paramRange[p_Input_Gain].def);
    fInGain->setRange(paramRange[p_Input_Gain].min, paramRange[p_Input_Gain].max);
    fInGain->setLabel(paramNames[p_Input_Gain]);
    fInGain->setColor(Secondary1Shade1);
    fInGain->setPtrHasMouse(dblWidgetPtr);
    fInGain->setZ(3);

    fThreshold = new NanoKnob(this, this);
    fThreshold->setId(p_Threshold);
    fThreshold->setAbsolutePos(knob_x + knob_x_spacing * 1, knob_y);
    fThreshold->setSize(knobSize);
    fThreshold->setRadius(knobRadius);
    fThreshold->setValue(paramRange[p_Threshold].def);
    fThreshold->setRange(paramRange[p_Threshold].min, paramRange[p_Threshold].max);
    fThreshold->setLabel(paramNames[p_Threshold]);
    fThreshold->setColors(Secondary1Shade1, Secondary1Shade0);
    fThreshold->setPtrHasMouse(dblWidgetPtr);
    fThreshold->setZ(4);

    fAttack = new NanoKnob(this, this);
    fAttack->setId(p_Attack);
    fAttack->setAbsolutePos(knob_x + knob_x_spacing * 3, knob_y);
    fAttack->setSize(knobSize);
    fAttack->setRadius(knobRadius);
    fAttack->setRange(paramRange[p_Attack].min, paramRange[p_Attack].max);
    fAttack->setValue(paramRange[p_Attack].def);
    fAttack->setLabel(paramNames[p_Attack]);
    fAttack->setColors(Secondary2Shade1, Secondary2Shade3);
    fAttack->setPtrHasMouse(dblWidgetPtr);
    fAttack->setZ(5);

    fRelease = new NanoKnob(this, this);
    fRelease->setId(p_Release);
    fRelease->setAbsolutePos(knob_x + knob_x_spacing * 4, knob_y);
    fRelease->setSize(knobSize);
    fRelease->setRadius(knobRadius);
    fRelease->setValue(paramRange[p_Release].def);
    fRelease->setRange(paramRange[p_Release].min, paramRange[p_Release].max);
    fRelease->setLabel(paramNames[p_Release]);
    fRelease->setColors(Secondary1Shade1, Secondary2Shade3);
    fRelease->setPtrHasMouse(dblWidgetPtr);
    fRelease->setZ(6);

    fHistogram = new NanoHistogram(this);
    fHistogram->setId(999); // FIX MAGIC NUMBER
    fHistogram->setHistoryLength(500);
    fHistogram->setSize(500, 60);
    fHistogram->setAbsolutePos(0, 250 - 60);
    fHistogram->setZ(7);

    fTooltip = new ToolTip(this);
    fTooltip->setId(888);
    fTooltip->setAbsolutePos(100, 70);
    fTooltip->setLabel("this is a tooltip");
    fTooltip->setZ(8);
    fTooltip->setVisible(false);
}

void CharacterCompressorUI::parameterChanged(uint32_t index, float value)
{
    switch (index)
    {
    case p_gainReduction:
        fNanoMeter->setValue(value);
        fdBGainReduction = value;
        break;
    case p_Input_Gain:
        fInGain->setValue(value);
        break;
    case p_output:
    {
        if (value > 0)
            fdBOutput = 20 * log10(value);
        else
            fdBOutput = -60;

        fOutputLevel = value;
        //printFPS();

        break;
    }
    case p_input:
    {
        if (value > 0)
            fdBInput = 20 * log10(value);
        else
            fdBInput = -60;
        break;
    }
    case p_Threshold:
        fThreshold->setValue(value);
        break;
    case p_Attack:
        fAttack->setValue(value);
        break;
    case p_Release:
        fRelease->setValue(value);
        break;
    default:
        break;
    }
}

void CharacterCompressorUI::onNanoDisplay()
{
    auto w = getWidth();
    auto h = getHeight();
    beginPath();
    fillColor(32, 32, 32);
    rect(0, 0, w, h);
    fill();
    closePath();
    if (drawTooltip && widgetPtr)
    {
        // construnct tooltip label
        float value = widgetPtr->getValue();
        uint id = widgetPtr->getId();
        const char *unit = parameterUnits[id];
        const char *name = paramNames[id];
        char buffer[32];
        sprintf(buffer, "%s : %.1f %s", name, value, unit);
        const std::string label = buffer;
        fTooltip->setLabel(label);
        // check if tooltip doesn't go offscreen
        // TODO check top and bottom of UI
        fTooltip->setAbsolutePos(tooltipPosition);
        const auto tt_width = fTooltip->getWidth();
        const auto ui_width = getWidth();
        if ((tooltipPosition.getX() + tt_width) > ui_width)
            fTooltip->setAbsoluteX(ui_width - tt_width);
        fTooltip->setVisible(true);
    }

    else
        fTooltip->setVisible(false);
}

void CharacterCompressorUI::idleCallback()
{
    fHistogram->setValues(fdBInput, fdBOutput, fdBGainReduction);
    newTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed_seconds = newTime - oldTime;
    if ((elapsed_seconds.count() > 1.0f))
        widgetPtr ? drawTooltip = true : drawTooltip = false;
    repaint();
}

void CharacterCompressorUI::nanoKnobValueChanged(NanoKnob *knob, const float value)

{
    int KnobId = knob->getId();
    setParameterValue(KnobId, value);
}

void CharacterCompressorUI::nanoSliderValueChanged(NanoSlider *slider, const float value)

{
    int SliderId = slider->getId();
    setParameterValue(SliderId, value);
}

bool CharacterCompressorUI::onMotion(const MotionEvent &ev)
{
    oldTime = std::chrono::high_resolution_clock::now();
    tooltipPosition = ev.pos;
    const uint toolTipY = tooltipPosition.getY() - 20;
    tooltipPosition.setY(toolTipY);
    drawTooltip = false;
    return true;
}

UI *createUI()
{
    return new CharacterCompressorUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO

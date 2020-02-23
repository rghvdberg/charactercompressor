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
    const int knob_x_spacing = 100;
    const int knob_x = 10;
    const int knob_y = 45;
    const auto ui_width = getWidth();
    const auto ui_height = getHeight();

    newTime = std::chrono::high_resolution_clock::now();
    oldTime = newTime;

    tabEasy = new Tab(this);
    tabEasy->setAbsolutePos(0, 0);
    tabEasy->setSize(100, 100);
    tabEasy->setVisible(true);

    tabAdvanced = new Tab(this);
    tabAdvanced->setAbsolutePos(0, 0);
    tabAdvanced->setSize(100, 100);
    tabAdvanced->setVisible(false);

    buttonEasy = new Button(this, this);
    buttonEasy->setId(800);
    buttonEasy->setSize(ui_width / 2, 20);
    buttonEasy->setAbsolutePos(0, 0);
    buttonEasy->setLabel("Easy");
    buttonEasy->setLabelColor(Secondary1Shade1);
    buttonEasy->setBackgroundColor(Secondary1Shade0);

    buttonAdvanced = new Button(this, this);
    buttonAdvanced->setId(801);
    buttonAdvanced->setSize(ui_width / 2, 20);
    buttonAdvanced->setAbsolutePos(ui_width / 2, 0);
    buttonAdvanced->setLabel("Advanced");
    buttonAdvanced->setLabelColor(Secondary2Shade0);
    buttonAdvanced->setBackgroundColor(Secondary2Shade4);

    fNanoMeter = new NanoMeter(this);
    fNanoMeter->setId(p_gainReduction);
    fNanoMeter->setAbsolutePos(ui_width - 10, ui_height - 60);
    fNanoMeter->setSize(10, 60);
    fNanoMeter->setRange(paramRange[p_gainReduction].min, paramRange[p_gainReduction].max);
    fNanoMeter->setValue(paramRange[p_gainReduction].def);
    fNanoMeter->setZ(1);

    fThreshold = new NanoKnob(tabEasy, this);
    fThreshold->setId(p_Threshold);
    fThreshold->setAbsolutePos(knob_x + knob_x_spacing * 0, knob_y);
    fThreshold->setSize(knobSize);
    fThreshold->setRadius(knobRadius);
    fThreshold->setValue(paramRange[p_Threshold].def);
    fThreshold->setRange(paramRange[p_Threshold].min, paramRange[p_Threshold].max);
    fThreshold->setLabel(paramNames[p_Threshold]);
    fThreshold->setColors(Secondary2Shade1, Secondary2Shade2);
    fThreshold->setPtrHasMouse(dblWidgetPtr);
    fThreshold->setZ(2);

    fStrength = new NanoKnob(tabEasy, this);
    fStrength->setId(p_strength);
    fStrength->setAbsolutePos(knob_x + knob_x_spacing * 1, knob_y);
    fStrength->setSize(knobSize);
    fStrength->setRadius(knobRadius);
    fStrength->setValue(paramRange[p_strength].def);
    fStrength->setRange(paramRange[p_strength].min, paramRange[p_strength].max);
    fStrength->setLabel(paramNames[p_strength]);
    fStrength->setColors(Secondary2Shade1, Secondary2Shade2);
    fStrength->setPtrHasMouse(dblWidgetPtr);
    fStrength->setZ(3);

    fAttack = new NanoKnob(tabEasy, this);
    fAttack->setId(p_Attack);
    fAttack->setAbsolutePos(knob_x + knob_x_spacing * 2, knob_y);
    fAttack->setSize(knobSize);
    fAttack->setRadius(knobRadius);
    fAttack->setRange(paramRange[p_Attack].min, paramRange[p_Attack].max);
    fAttack->setValue(paramRange[p_Attack].def);
    fAttack->setLabel(paramNames[p_Attack]);
    fAttack->setColors(Secondary1Shade1, Secondary1Shade2);
    fAttack->setPtrHasMouse(dblWidgetPtr);
    fAttack->setZ(4);

    fRelease = new NanoKnob(tabEasy, this);
    fRelease->setId(p_Release);
    fRelease->setAbsolutePos(knob_x + knob_x_spacing * 3, knob_y);
    fRelease->setSize(knobSize);
    fRelease->setRadius(knobRadius);
    fRelease->setValue(paramRange[p_Release].def);
    fRelease->setRange(paramRange[p_Release].min, paramRange[p_Release].max);
    fRelease->setLabel(paramNames[p_Release]);
    fRelease->setColors(Secondary1Shade1, Secondary1Shade2);
    fRelease->setPtrHasMouse(dblWidgetPtr);
    fRelease->setZ(5);

    fInGain = new NanoKnob(tabEasy, this);
    fInGain->setId(p_Input_Gain);
    fInGain->setAbsolutePos(knob_x + knob_x_spacing * 4, knob_y);
    fInGain->setSize(knobSize);
    fInGain->setRadius(knobRadius);
    fInGain->setValue(paramRange[p_Input_Gain].def);
    fInGain->setRange(paramRange[p_Input_Gain].min, paramRange[p_Input_Gain].max);
    fInGain->setLabel(paramNames[p_Input_Gain]);
    fInGain->setColors(PrimaryShade0, PrimaryShade1);
    fInGain->setPtrHasMouse(dblWidgetPtr);
    fInGain->setZ(6);

    fHistogram = new NanoHistogram(this);
    fHistogram->setId(999); // FIX MAGIC NUMBER
    fHistogram->setHistoryLength(490);
    fHistogram->setSize(490, 60);
    fHistogram->setAbsolutePos(0, 250 - 60);
    fHistogram->setZ(7);

    fTooltip = new ToolTip(this);
    fTooltip->setId(888);
    fTooltip->setAbsolutePos(100, 70);
    fTooltip->setLabel("this is a tooltip");
    fTooltip->setZ(0);
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
    case p_strength:
        fStrength->setValue(value);
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

void CharacterCompressorUI::buttonClicked(Button *button, const bool value)
{
    const uint id = button->getId();
    switch (id)
    {
    case 800:
        tabEasy->show();
        tabAdvanced->hide();
        buttonEasy->setLabelColor(Secondary1Shade1);
        buttonEasy->setBackgroundColor(Secondary1Shade0);
        buttonAdvanced->setLabelColor(Secondary2Shade0);
        buttonAdvanced->setBackgroundColor(Secondary2Shade4);
        break;
    case 801:
        tabEasy->hide();
        tabAdvanced->show();
        buttonEasy->setLabelColor(Secondary1Shade0);
        buttonEasy->setBackgroundColor(Secondary1Shade4);
        buttonAdvanced->setLabelColor(Secondary2Shade1);
        buttonAdvanced->setBackgroundColor(Secondary2Shade2);

    default:
        break;
    }
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

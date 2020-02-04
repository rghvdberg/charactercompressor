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

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

CharacterCompressorUI::CharacterCompressorUI()
        : UI(500, 250)
    {
        loadSharedResources();
        fNanoFont= findFont(NANOVG_DEJAVU_SANS_TTF);
        const Size<uint> knobSize (80,100);
        const float knobRadius = 35;
        const int knob_x_spacing = 90;
        const int knob_x = 40;
        const int knob_y = 20;
        
        fNanoMeter = new NanoMeter(this);
        fNanoMeter->setId(p_foo);
        fNanoMeter->setAbsolutePos(10,10);
        fNanoMeter->setSize(10,knobSize.getHeight());
        fNanoMeter->setRange(minimumValues[p_foo],maximumValues[p_foo]);
        fNanoMeter->setValue(defaultValues[p_foo]);

        fInGain = new NanoKnob(this, this);
        fInGain->setId(p_Input_Gain);
        fInGain->setAbsolutePos(knob_x,knob_y);
        fInGain->setSize(knobSize);
        fInGain->setRadius(knobRadius);
        fInGain->setValue(defaultValues[p_Input_Gain]);
        fInGain->setRange(minimumValues[p_Input_Gain],maximumValues[p_Input_Gain]);
        fInGain->setLabel(portNames[p_Input_Gain]);
        
        fThreshold = new NanoKnob(this, this);
        fThreshold->setId(p_Threshold);
        fThreshold->setAbsolutePos( knob_x + knob_x_spacing * 1 ,knob_y);
        fThreshold->setSize(knobSize);
        fThreshold->setRadius(knobRadius);
        fThreshold->setValue(defaultValues[p_Threshold]);
        fThreshold->setRange(minimumValues[p_Threshold],maximumValues[p_Threshold]);
        fThreshold->setLabel(portNames[p_Threshold]);
        
        fRatio = new NanoKnob(this, this);
        fRatio->setId(p_Ratio);
        fRatio->setAbsolutePos(knob_x + knob_x_spacing * 2, knob_y);
        fRatio->setSize(knobSize);
        fRatio->setRadius(knobRadius);
        fRatio->setValue(defaultValues[p_Ratio]);
        fRatio->setRange(minimumValues[p_Ratio],maximumValues[p_Ratio]);
        fRatio->setLabel(portNames[p_Ratio]);

        fAttack = new NanoKnob(this, this);
        fAttack->setId(p_Attack);
        fAttack->setAbsolutePos(knob_x + knob_x_spacing * 3, knob_y);
        fAttack->setSize(knobSize);
        fAttack->setRadius(knobRadius);
        fAttack->setValue(defaultValues[p_Attack]);
        fAttack->setRange(minimumValues[p_Attack],maximumValues[p_Attack]);
        fAttack->setLabel(portNames[p_Attack]);

        fRelease = new NanoKnob(this, this);
        fRelease->setId(p_Release);
        fRelease->setAbsolutePos(knob_x + knob_x_spacing * 4, knob_y);
        fRelease->setSize(knobSize);
        fRelease->setRadius(knobRadius);
        fRelease->setValue(defaultValues[p_Release]);
        fRelease->setRange(minimumValues[p_Release],maximumValues[p_Release]);
        fRelease->setLabel(portNames[p_Release]);
        

    } 


void CharacterCompressorUI::parameterChanged(uint32_t index, float value)
    {
        switch (index)
        {
        case p_foo:
            fNanoMeter->setValue(value);
            break;
        case p_Input_Gain:
            fInGain->setValue(value);
            break;
      /*   case p_Threshold:
            fThreshold->setValue(value);
            break; */
        default:
            break;
        }

     
    }

void CharacterCompressorUI::onNanoDisplay(){
    beginPath();
    auto w = getWidth();
    auto h = getHeight();
    fillColor( 32,32,32);
    rect(0,0,w,h);
    fill();
    closePath();
    }

void CharacterCompressorUI::nanoKnobValueChanged(NanoKnob * knob, const float value)

{
    int KnobId = knob->getId();
    setParameterValue( KnobId, value);
}

UI* createUI()
{
    return new CharacterCompressorUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO

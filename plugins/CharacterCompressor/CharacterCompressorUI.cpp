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
        : UI(600, 400)
    {
        
        Window &window = getParentWindow();
        fNanoMeter = new NanoMeter(window);
        fNanoMeter->setId(p_foo);
        fNanoMeter->setAbsolutePos(30,30);
        fNanoMeter->setSize(10,200);
        fNanoMeter->setRange(minimumValues[p_foo],maximumValues[p_foo]);
        fNanoMeter->setValue(defaultValues[p_foo]);
    

        fInGain = new NanoKnob(window);
        fInGain->setId(p_Input_Gain);
        fInGain->setAbsolutePos( 100,100);
        fInGain->setSize(50,50);
        fInGain->setRadius(50/2);
        fInGain->setValue(defaultValues[p_Input_Gain]);
        fInGain->setRange(minimumValues[p_Input_Gain],maximumValues[p_Input_Gain]);
        fInGain->setCallback(this);
        
        fThreshold = new NanoKnob(window);
        fThreshold->setId(p_Threshold);
        fThreshold->setAbsolutePos( 160,100);
        fThreshold->setSize(50,50);
        fThreshold->setRadius(50/2);
        fThreshold->setValue(defaultValues[p_Threshold]);
        fThreshold->setRange(minimumValues[p_Threshold],maximumValues[p_Threshold]);
        fThreshold->setCallback(this);
        
        fRatio = new NanoKnob(window);
        fRatio->setId(p_Ratio);
        fRatio->setAbsolutePos( 220,100);
        fRatio->setSize(50,50);
        fRatio->setRadius(50/2);
        fRatio->setValue(defaultValues[p_Ratio]);
        fRatio->setRange(minimumValues[p_Ratio],maximumValues[p_Ratio]);
        fRatio->setCallback(this);

        fAttack = new NanoKnob(window);
        fAttack->setId(p_Attack);
        fAttack->setAbsolutePos( 280,100);
        fAttack->setSize(50,50);
        fAttack->setRadius(50/2);
        fAttack->setValue(defaultValues[p_Attack]);
        fAttack->setRange(minimumValues[p_Attack],maximumValues[p_Attack]);
        fAttack->setCallback(this);

        fRelease = new NanoKnob(window);
        fRelease->setId(p_Release);
        fRelease->setAbsolutePos( 340,100);
        fRelease->setSize(50,50);
        fRelease->setRadius(50/2);
        fRelease->setValue(defaultValues[p_Release]);
        fRelease->setRange(minimumValues[p_Release],maximumValues[p_Release]);
        fRelease->setCallback(this);
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
    printf("nanoKnobValueChanged %f\n", value);
    int KnobId = knob->getId();
    setParameterValue( KnobId, value);
}

UI* createUI()
{
    return new CharacterCompressorUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO

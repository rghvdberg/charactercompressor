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
        /*
        Window &window = getParentWindow();
         fNanoMeter = new NanoMeter( window);
        fNanoMeter->setId(p_foo);
        fNanoMeter->setAbsolutePos(30,30);
        */
     
    
    }


void CharacterCompressorUI::parameterChanged(uint32_t index, float value)
    {
        switch (index)
         
        default:
            break;
        
     
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

UI* createUI()
{
    return new CharacterCompressorUI();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO

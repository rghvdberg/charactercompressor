/*
 * Copyright (C) 2018-2019 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of CharacterCompressor
 *
 * Nnjas2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CharacterCompressor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CharacterCompressor.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "NanoKnob.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO


NanoKnob::NanoKnob(Window &parent) noexcept
 : NanoWidget(parent),
 mouseDown(false)

{
    printf ("knob constructed , mousedown = %i\n", mouseDown);
   
}

void NanoKnob::setCallback( Callback* callback) noexcept {
    fCallback = callback;
}

void NanoKnob::onNanoDisplay()
{
float normValue = (fValue-fMin) / (fMax - fMin);

auto w = getWidth();
auto h = getHeight();
// Knob
beginPath();
fillColor(64,64,64,255);
circle(w/2,h/2,fRadius);
fill();
closePath();

//Indicator line
beginPath();
save();
translate(w/2, h/2);
rotate((2.0f + ((normValue - 0.5f) * 1.5f)) * M_PI);
fillColor(200,200,200,255);
const float indicatorWidht = 3.0f;
const float x = w/2 - indicatorWidht /2;
const float y = h/2 - fRadius;
rect( x -w/2 , y -h/2 , indicatorWidht,fRadius/2);

fill();
restore();
closePath();

}

void NanoKnob::setValue(float value)
{
    fValue = value;
    if(fValue > fMax)
        fValue = fMax;
    if (fValue < fMin)
        fValue = fMin;
    repaint();
}

void NanoKnob::setRange(float min, float max)
{
    fMin = min;
    fMax = max;
}
void NanoKnob::setRadius(float radius)
{
    fRadius = radius;
}

float NanoKnob::getValue(){
    return fValue;
}

bool NanoKnob::onMouse(const MouseEvent &ev){
    if(ev.press & contains(ev.pos))
    {
        mouseDown = true;
        mousePoint = ev.pos;
        printf("mouseDown %i\n",mouseDown);
     return mouseDown;

    }
    if (!ev.press)
    {

        mouseDown = false;
        return mouseDown;
    }
    return false;
        
}

bool NanoKnob::onMotion(const MotionEvent &ev)
{
   
    if (mouseDown)
    {
       printf("onMotion::mouseDown %i\n",mouseDown);
       const float resistance = 100.0f;
       const float difference = (mousePoint.getY() - ev.pos.getY()) / resistance * (fMax - fMin);
       mousePoint.setY(ev.pos.getY());
       setValue(fValue + difference);
       fCallback->nanoKnobValueChanged(this, fValue);
    }
    
}


END_NAMESPACE_DISTRHO


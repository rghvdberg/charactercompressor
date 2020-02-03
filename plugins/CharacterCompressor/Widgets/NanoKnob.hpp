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

#ifndef NANO_KNOB_HPP_INCLUDED
#define NANO_KNOB_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"

START_NAMESPACE_DISTRHO

class NanoKnob : public NanoWidget
{
public:
    class Callback
    {
        public:
        virtual ~Callback() {}
        virtual void nanoKnobValueChanged ( NanoKnob * knob, float value) =0;
    };
    explicit NanoKnob(Widget* parent, Callback* cb);

    float getValue() const;
    void setValue(float value);
    void setRange(float min, float max);
    void setRadius(float radius);
protected:
    void onNanoDisplay() override;
    bool onMouse( const MouseEvent & ev) override;
  //  bool onScroll(const ScrollEvent & ev) override;
    bool onMotion(const MotionEvent & ev) override;

private:
    float fValue;
    float fMin;
    float fMax;
    float fRadius;
    Callback* const fCallback;
    bool mouseDown;
    Point<int> mousePoint;

    DISTRHO_LEAK_DETECTOR(NanoKnob)
};

END_NAMESPACE_DISTRHO

#endif

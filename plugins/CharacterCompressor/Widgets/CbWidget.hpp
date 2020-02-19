/*
 * Copyright (C) 2018-2019 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of Punch
 *
 * Punch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Punch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Punch.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CBWIDGET_HPP_INCLUDED
#define CBWIDGET_HPP_INCLUDED

#include "Widget.hpp"
#include "NanoVG.hpp"

START_NAMESPACE_DISTRHO

class CbWidget : public NanoWidget
{
public:
  class PopUp
  {
  public:
    virtual ~PopUp() {}
    virtual void cbPopUp(CbWidget *widget, bool hasMouse, const Point<int> mouse) = 0;
  };
  //CbWidget(Window &parent, PopUp * popup) noexcept;
  CbWidget(Widget *widget) noexcept;
  CbWidget * ptrHasMouse;

protected:
private:
  
  DISTRHO_LEAK_DETECTOR(CbWidget)
};


END_NAMESPACE_DISTRHO
#endif
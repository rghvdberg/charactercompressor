/*
 * Copyright (C) 2018-2019 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of Punch
 *
 * Nnjas2 is free software: you can redistribute it and/or modify
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

#include "CbWidget.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO

//CbWidget::CbWidget(Window &parent, PopUp *popup) noexcept : NanoWidget(parent)
//{
//}

CbWidget::CbWidget(Widget *widget) noexcept : NanoWidget(widget)
{
  ptrHasMouse = nullptr;
}


END_NAMESPACE_DISTRHO
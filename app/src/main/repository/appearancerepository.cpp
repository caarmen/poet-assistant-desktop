/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "appearancerepository.h"


AppearanceRepository::AppearanceRepository(QObject *parent)
    : QObject{parent}
{
}

void AppearanceRepository::setNightMode(AppearanceRepository::NightMode nightMode)
{
    settings.setValue(nightModeSetting, nightMode);
    emit nightModeChanged();
}

AppearanceRepository::NightMode AppearanceRepository::getNightMode()
{
    return static_cast<NightMode>(settings.value(nightModeSetting, NightMode::Auto).toInt());
}

void AppearanceRepository::setStyle(AppearanceRepository::Style style)
{
    settings.setValue(styleSetting, style);
}

AppearanceRepository::Style AppearanceRepository::getStyle()
{
    return static_cast<Style>(settings.value(styleSetting, Style::Basic).toInt());
}
QString AppearanceRepository::getName(Style style)
{
    switch (style) {
    case Fusion:
        return "Fusion";
    case Material:
        return "Material";
    case Universal:
        return "Universal";
    default:
        return "Basic";
    }
}

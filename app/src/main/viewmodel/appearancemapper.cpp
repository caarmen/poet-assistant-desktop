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

#include "appearancemapper.h"

AppearanceMapper::AppearanceMapper(QObject *parent)
    : QObject{parent}
{

}


NightMode AppearanceMapper::map(AppearanceRepository::NightMode nightMode)
{
    switch (nightMode) {
    case AppearanceRepository::Day:
        return NightMode::Day;
    case AppearanceRepository::Night:
        return NightMode::Night;
    default:
        return NightMode::Auto;
    }
}

AppearanceRepository::NightMode AppearanceMapper::map(NightMode nightMode)
{
    switch (nightMode) {
    case NightMode::Day:
        return AppearanceRepository::Day;
    case NightMode::Night:
        return AppearanceRepository::Night;
    default:
        return AppearanceRepository::Auto;
    }
}


Style AppearanceMapper::map(AppearanceRepository::Style style)
{
    switch (style) {
    case AppearanceRepository::Fusion:
        return Style::Fusion;
    case AppearanceRepository::Material:
        return Style::Material;
    case AppearanceRepository::Universal:
        return Style::Universal;
    default:
        return Style::Basic;
    }
}

AppearanceRepository::Style AppearanceMapper::map(Style style)
{
    switch (style) {
    case Style::Fusion:
        return AppearanceRepository::Fusion;
    case Style::Material:
        return AppearanceRepository::Material;
    case Style::Universal:
        return AppearanceRepository::Universal;
    default:
        return AppearanceRepository::Basic;
    }
}

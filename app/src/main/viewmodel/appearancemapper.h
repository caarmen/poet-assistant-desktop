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

#ifndef APPEARANCEMAPPER_H
#define APPEARANCEMAPPER_H

#include "nightmodeenum.h"
#include "styleenum.h"
#include "appearancerepository.h"
#include <QObject>

class AppearanceMapper : public QObject
{
    Q_OBJECT
public:
    static NightMode map(AppearanceRepository::NightMode nightMode);
    static AppearanceRepository::NightMode map(NightMode nightMode);
    static Style map(AppearanceRepository::Style style);
    static AppearanceRepository::Style map(Style style);
private:
    explicit AppearanceMapper(QObject *parent = nullptr);
};

#endif // APPEARANCEMAPPER_H

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

#ifndef APPEARANCEREPOSITORY_H
#define APPEARANCEREPOSITORY_H

#include <QObject>
#include <QSettings>

class AppearanceRepository : public QObject
{
    Q_OBJECT
public:
    enum NightMode { Day, Night, Auto };
    enum Style { Basic, Fusion, Material, Universal};

    explicit AppearanceRepository(QObject *parent = nullptr);
    void setNightMode(NightMode nightMode);
    NightMode getNightMode();
    void setStyle(Style style);
    Style getStyle();
    static QString getName(Style style);
signals:
    void nightModeChanged();
    void styleChanged();
private:
    static inline QString nightModeSetting = "nightMode";
    static inline QString styleSetting = "style";
    QSettings settings;
};

#endif // APPEARANCEREPOSITORY_H

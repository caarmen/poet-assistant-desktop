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
#ifndef THESAURUSDISPLAYDATA_H
#define THESAURUSDISPLAYDATA_H

#include "refcounter.h"
#include "colortypeenum.h"
#include <QObject>

class ThesaurusDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text CONSTANT)
    Q_PROPERTY(bool italic MEMBER italic CONSTANT)
    Q_PROPERTY(bool bold MEMBER bold CONSTANT)
    Q_PROPERTY(int interactive MEMBER interactive CONSTANT)
    Q_PROPERTY(ColorType backgroundColor MEMBER backgroundColor CONSTANT)
public:
    explicit ThesaurusDisplayData(QString text,
                                  bool italic = false,
                                  bool bold = false,
                                  bool interactive = false,
                                  ColorType backgroundColor = ColorType::Background,
                                  QObject *parent = nullptr);
    ~ThesaurusDisplayData();
    const QString text;
    const bool italic;
    const bool bold;
    const bool interactive;
    const ColorType backgroundColor;

private:
    static inline RefCounter refCounter = RefCounter("ThesaurusDisplayData");

};

#endif // THESAURUSDISPLAYDATA_H

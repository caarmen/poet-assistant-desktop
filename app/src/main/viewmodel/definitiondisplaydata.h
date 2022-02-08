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
#ifndef DEFINITIONDISPLAYDATA_H
#define DEFINITIONDISPLAYDATA_H

#include "refcounter.h"
#include <QObject>

class DefinitionDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString part_of_speech MEMBER partOfSpeech CONSTANT)
    Q_PROPERTY(QString definition MEMBER definition CONSTANT)
public:
    explicit DefinitionDisplayData(QString partOfSpeech, QString definition, QObject *parent = nullptr);
    ~DefinitionDisplayData();
    const QString partOfSpeech;
    const QString definition;

private:
    static inline RefCounter refCounter = RefCounter("DefinitionDisplayData");
};

#endif // DEFINITIONDISPLAYDATA_H

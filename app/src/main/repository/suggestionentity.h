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
#ifndef SUGGESTIONENTITY_H
#define SUGGESTIONENTITY_H

#include "refcounter.h"
#include <QObject>

class SuggestionEntity : public QObject
{
    Q_OBJECT
public:
    enum Source { DICTIONARY, HISTORY };
    explicit SuggestionEntity(QString word, Source source, QObject *parent = nullptr);
    ~SuggestionEntity();
    const QString word;
    const Source source;

private:
    static inline RefCounter refCounter = RefCounter("SuggestionEntity");
};

#endif // SUGGESTIONENTITY_H

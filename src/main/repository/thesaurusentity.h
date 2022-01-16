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
#ifndef THESAURUSENTITY_H
#define THESAURUSENTITY_H

#include "refcounter.h"
#include <QObject>

class ThesaurusEntity : public QObject
{
    Q_OBJECT
public:
    explicit ThesaurusEntity(QString wordType, QString synonyms, QString antonyms, QObject *parent = nullptr);
    ~ThesaurusEntity();
    const QString wordType;
    const QString synonyms;
    const QString antonyms;

private:
    static inline RefCounter refCounter = RefCounter("ThesaurusEntity");
};

#endif // THESAURUSENTITY_H

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
#include "definitionentitymapper.h"

#include <QCoreApplication>
#include <QtConcurrent>

DefinitionEntityMapper::DefinitionEntityMapper()
{
}

QList<DefinitionDisplayData*>* DefinitionEntityMapper::map(QList<DefinitionEntity*> *entities) {
    return new QList<DefinitionDisplayData*>(QtConcurrent::blockingMapped(*entities, [=] (DefinitionEntity *entity){
        return map(entity);
    }));
}
const char * DefinitionEntityMapper::map(const QString &partOfSpeech)
{
    if (partOfSpeech == "a") {
        return "adjective";
    } else if (partOfSpeech == "n") {
        return "noun";
    } else if (partOfSpeech == "r") {
        return "adverb";
    } else if (partOfSpeech == "v") {
        return "verb";
    } else {
        return "unknown";
    }
}

DefinitionDisplayData* DefinitionEntityMapper::map(DefinitionEntity* entity)
{
    return new DefinitionDisplayData(QCoreApplication::translate("main", map(entity->partOfSpeech)), entity->definition);
}

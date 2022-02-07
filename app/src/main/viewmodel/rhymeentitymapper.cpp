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
#include "rhymeentitymapper.h"
#include <QtConcurrent>

RhymeEntityMapper::RhymeEntityMapper()
{

}

QList<RhymeDisplayData*>* RhymeEntityMapper::map(const QList<RhymeEntity*>* rhymeEntities) {
    auto *result = new QList<RhymeDisplayData*>();
    QString currentSyllables = "";
    for(auto *rhymeEntity : *rhymeEntities) {
        if (currentSyllables != rhymeEntity->stressSyllables) {
            result->append(new RhymeDisplayData(rhymeEntity->stressSyllables, false, true, false, ColorType::Surface));
            currentSyllables = rhymeEntity->stressSyllables;
        }
        result->append(new RhymeDisplayData(rhymeEntity->word, false, false, true, ColorType::Background));
    }
    return result;
}

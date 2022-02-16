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
#include <QtGlobal>

RhymeEntityMapper::RhymeEntityMapper()
{

}

QList<RhymeDisplayData *> *RhymeEntityMapper::map(const QList<RhymeEntity *> *rhymeEntities)
{
    auto *result = new QList<RhymeDisplayData *>();
    QString sectionHeading = "";
    for (auto *rhymeEntity : *rhymeEntities) {
        QString syllablesTypeLabel = qtTrId(map(rhymeEntity->syllablesType));
        QString entityHeading = qtTrId("rhymer_section_heading").arg(syllablesTypeLabel,
                                                                     rhymeEntity->syllables);
        if (entityHeading != sectionHeading) {
            sectionHeading = entityHeading;
            result->append(new RhymeDisplayData(sectionHeading, false, true, false, ColorType::Surface));
        }
        result->append(new RhymeDisplayData(rhymeEntity->word, false, false, true, ColorType::Background));
    }
    return result;
}

const char *RhymeEntityMapper::map(RhymeEntity::SyllablesType syllablesType)
{
    switch (syllablesType) {
    case RhymeEntity::STRICT:
        return "rhymer_syllables_type_strict";
    case RhymeEntity::LAST_3:
        return "rhymer_syllables_type_last_three_syllables";
    case RhymeEntity::LAST_2:
        return "rhymer_syllables_type_last_two_syllables";
    default:
        return "rhymer_syllables_type_last_syllable";
    }
}

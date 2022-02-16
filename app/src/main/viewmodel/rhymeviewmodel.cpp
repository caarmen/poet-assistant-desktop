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
#include "rhymeviewmodel.h"
#include "rhymeentitymapper.h"

#include <QtConcurrent>

RhymeViewModel::RhymeViewModel(RhymeRepository *repository, QObject *parent)
    : QObject{parent}, repository(repository)
{

}

QFuture<QList<RhymeDisplayData *>*> RhymeViewModel::readRhymes(QString searchText)
{
    return repository->readStressSyllableRhymes(searchText)
    .then([](QList<RhymeEntity *> *rhymeEntities) {
        QList<RhymeDisplayData *> *result = RhymeEntityMapper::map(rhymeEntities);
        qDeleteAll(*rhymeEntities);
        delete rhymeEntities;
        return result;
    });
}


QFuture<QString> RhymeViewModel::readRhymesText(QString searchText)
{
    return repository->readStressSyllableRhymes(searchText)
    .then([searchText](QList<RhymeEntity *> *rhymeEntities) {
        QString result = RhymeEntityMapper::mapListText(searchText, rhymeEntities);
        qDeleteAll(*rhymeEntities);
        delete rhymeEntities;
        return result;
    });
}

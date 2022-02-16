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
#include "rhymelistmodel.h"
#include "rhymeentitymapper.h"

RhymeListModel::RhymeListModel(RhymeViewModel *viewModel, QObject *parent)
    : QAbstractListModel{parent},
      viewModel(viewModel),
      rhymeEntries(nullptr),
      isEmptyTextVisible(true),
      emptyText(qtTrId("rhymer_no_query"))
{

}

void RhymeListModel::readRhymes(QString searchText) {
    word = searchText;
    emit wordChanged(word);

    QFuture<QList<RhymeDisplayData*>*> future = viewModel->readRhymes(searchText);
    auto *watcher = new QFutureWatcher<QList<RhymeDisplayData*>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<RhymeDisplayData*>*>::finished, this, [=](){

        beginResetModel();
        if (rhymeEntries != nullptr) {
            qDeleteAll(*rhymeEntries);
            delete rhymeEntries;
        }

        rhymeEntries = future.result();
        isEmptyTextVisible = rhymeEntries->size() == 0;
        emit isEmptyTextVisibleChanged(isEmptyTextVisible);
        emptyText = qtTrId("rhymer_no_matches").arg(word);
        emit emptyTextChanged(emptyText);
        endResetModel();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

QHash<int,QByteArray> RhymeListModel::roleNames() const {
    return { { RhymeRole, "rhyme" } };
}

int RhymeListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return rhymeEntries == nullptr ? 0 : rhymeEntries->size();
}

QVariant RhymeListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == RhymeRole) {
        return QVariant::fromValue(rhymeEntries->at(index.row()));
    } else {
        return QVariant();
    }
}

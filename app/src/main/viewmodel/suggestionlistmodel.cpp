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
#include "suggestionlistmodel.h"
#include <QFutureWatcher>
#include <QtConcurrent>

SuggestionListModel::SuggestionListModel(SuggestionViewModel *viewModel, QObject *parent)
    : QAbstractListModel(parent),
      viewModel(viewModel),
      suggestions(nullptr)
{
}

void SuggestionListModel::readSuggestions(QString searchText)
{
    QFuture<QList<SuggestionDisplayData *>*> future = viewModel->readSuggestions(searchText);
    auto *watcher = new QFutureWatcher<QList<SuggestionDisplayData *>*>();
    QObject::connect(watcher, &QFutureWatcher<QList<SuggestionDisplayData *>*>::finished,
    this, [ = ]() {
        beginResetModel();
        if (suggestions != nullptr) {
            qDeleteAll(*suggestions);
            delete suggestions;
        }
        suggestions = future.result();
        endResetModel();
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

QHash<int, QByteArray> SuggestionListModel::roleNames() const
{
    return { { SuggestionRole, "suggestion" } };
}

int SuggestionListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return suggestions == nullptr ? 0 : suggestions->size();
}

QVariant SuggestionListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == SuggestionRole) {
        return QVariant::fromValue(suggestions->at(index.row()));
    } else {
        return QVariant();
    }
}


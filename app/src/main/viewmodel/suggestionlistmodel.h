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
#ifndef SUGGESTIONLISTMODEL_H
#define SUGGESTIONLISTMODEL_H

#include <QAbstractListModel>
#include "suggestiondisplaydata.h"
#include "suggestionviewmodel.h"

class SuggestionListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MyRoles {
        SuggestionRole = Qt::UserRole + 1,
    };
    explicit SuggestionListModel(SuggestionViewModel *viewModel, QObject *parent = nullptr);

    void clearSuggestions();
    void readSuggestions(QString searchText);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    SuggestionViewModel *viewModel;
    QList<SuggestionDisplayData *> *suggestions;
};

#endif // SUGGESTIONLISTMODEL_H

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
#ifndef DEFINITIONLISTMODEL_H
#define DEFINITIONLISTMODEL_H

#include <QAbstractListModel>
#include "definitiondisplaydata.h"
#include "definitionviewmodel.h"

class DefinitionListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString word MEMBER word NOTIFY wordChanged)
    Q_PROPERTY(bool isEmptyTextVisible MEMBER isEmptyTextVisible NOTIFY isEmptyTextVisibleChanged)
    Q_PROPERTY(QString emptyText MEMBER emptyText NOTIFY emptyTextChanged)

public:
    enum MyRoles {
        DefinitionRole = Qt::UserRole + 1,
    };
    explicit DefinitionListModel(DefinitionViewModel *viewModel, QObject *parent = nullptr);

    void readDefinitions(QString searchText);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:
    void wordChanged(const QString &);
    void isEmptyTextVisibleChanged(bool);
    void emptyTextChanged(const QString &);
private:
    QString word;
    DefinitionViewModel *viewModel;
    QList<DefinitionDisplayData *> *definitions;
    bool isEmptyTextVisible;
    QString emptyText;
};

#endif // DEFINITIONLISTMODEL_H

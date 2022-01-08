#ifndef DEFINITIONLISTMODEL_H
#define DEFINITIONLISTMODEL_H

#include <QAbstractListModel>
#include "definitiondisplaydata.h"
#include "definitionviewmodel.h"

class DefinitionListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum MyRoles {
        DefinitionRole = Qt::UserRole + 1,
    };
    explicit DefinitionListModel(DefinitionViewModel *viewModel, QObject *parent = nullptr);

    void readDefinitions(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    DefinitionViewModel *viewModel;
    QList<DefinitionDisplayData*> *definitions;
};

#endif // DEFINITIONLISTMODEL_H

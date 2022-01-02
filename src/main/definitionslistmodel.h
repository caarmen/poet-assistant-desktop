#ifndef DEFINITIONSLISTMODEL_H
#define DEFINITIONSLISTMODEL_H

#include <QAbstractListModel>
#include "definitiondisplaydata.h"
#include "definitionrepository.h"

class DefinitionsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum MyRoles {
        DefinitionRole = Qt::UserRole + 1,
    };
    explicit DefinitionsListModel(DefinitionRepository *respository, QObject *parent = nullptr);

    void readDefinitions(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    DefinitionRepository *repository;
    QList<DefinitionDisplayData*> *definitions;
};

#endif // DEFINITIONSLISTMODEL_H

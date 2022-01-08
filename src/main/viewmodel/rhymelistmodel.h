#ifndef RHYMELISTMODEL_H
#define RHYMELISTMODEL_H

#include "rhymeviewmodel.h"
#include "rhymedisplaydata.h"

#include <QAbstractListModel>
#include <QObject>

class RhymeListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MyRoles {
        RhymeRole = Qt::UserRole + 1,
    };
    explicit RhymeListModel(RhymeViewModel *viewModel, QObject *parent = nullptr);

    void readRhymes(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    RhymeViewModel *viewModel;
    QList<RhymeDisplayData*> *rhymeEntries;
};

#endif // RHYMELISTMODEL_H

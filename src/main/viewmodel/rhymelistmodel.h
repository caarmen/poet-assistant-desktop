#ifndef RHYMELISTMODEL_H
#define RHYMELISTMODEL_H

#include "rhymerepository.h"
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
    explicit RhymeListModel(RhymeRepository *repository, QObject *parent = nullptr);

    void readRhymes(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    RhymeRepository *repository;
    QList<RhymeDisplayData*> *rhymeEntries;
};

#endif // RHYMELISTMODEL_H

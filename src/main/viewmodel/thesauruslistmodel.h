#ifndef THESAURUSLISTMODEL_H
#define THESAURUSLISTMODEL_H

#include "thesaurusrepository.h"
#include "thesaurusdisplaydata.h"

#include <QAbstractListModel>
#include <QObject>

class ThesaurusListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MyRoles {
        ThesaurusRole = Qt::UserRole + 1,
    };
    explicit ThesaurusListModel(ThesaurusRepository *repository, QObject *parent = nullptr);

    void readThesaurus(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    ThesaurusRepository *repository;
    QList<ThesaurusDisplayData*> *thesaurusEntries;
};

#endif // THESAURUSLISTMODEL_H

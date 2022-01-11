#ifndef RHYMELISTMODEL_H
#define RHYMELISTMODEL_H

#include "rhymeviewmodel.h"
#include "rhymedisplaydata.h"

#include <QAbstractListModel>
#include <QObject>

class RhymeListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString word MEMBER word NOTIFY wordChanged)
    Q_PROPERTY(bool isEmptyTextVisible MEMBER isEmptyTextVisible NOTIFY isEmptyTextVisibleChanged)
    Q_PROPERTY(QString emptyText MEMBER emptyText NOTIFY emptyTextChanged)
public:
    enum MyRoles {
        RhymeRole = Qt::UserRole + 1,
    };
    explicit RhymeListModel(RhymeViewModel *viewModel, QObject *parent = nullptr);

    void readRhymes(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:
    void wordChanged(const QString &);
    void isEmptyTextVisibleChanged(bool);
    void emptyTextChanged(const QString &);
private:
    QString word;
    RhymeViewModel *viewModel;
    QList<RhymeDisplayData*> *rhymeEntries;
    bool isEmptyTextVisible;
    QString emptyText;
};

#endif // RHYMELISTMODEL_H

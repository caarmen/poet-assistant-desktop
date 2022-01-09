#ifndef THESAURUSLISTMODEL_H
#define THESAURUSLISTMODEL_H

#include "thesaurusviewmodel.h"
#include "thesaurusdisplaydata.h"

#include <QAbstractListModel>
#include <QObject>

class ThesaurusListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString word MEMBER word NOTIFY wordChanged)
    Q_PROPERTY(bool isEmptyTextVisible MEMBER isEmptyTextVisible NOTIFY isEmptyTextVisibleChanged)
    Q_PROPERTY(QString emptyText MEMBER emptyText NOTIFY emptyTextChanged)
public:
    enum MyRoles {
        ThesaurusRole = Qt::UserRole + 1,
    };
    explicit ThesaurusListModel(ThesaurusViewModel *viewModel, QObject *parent = nullptr);

    void readThesaurus(QString searchText);

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:
    void wordChanged(const QString &);
    void isEmptyTextVisibleChanged(bool);
    void emptyTextChanged(const QString &);
private:
    QString word;
    ThesaurusViewModel *viewModel;
    QList<ThesaurusDisplayData*> *thesaurusEntries;
    bool isEmptyTextVisible;
    QString emptyText;
};

#endif // THESAURUSLISTMODEL_H

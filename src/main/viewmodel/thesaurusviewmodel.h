#ifndef THESAURUSVIEWMODEL_H
#define THESAURUSVIEWMODEL_H

#include "thesaurusrepository.h"
#include "thesaurusdisplaydata.h"
#include <QObject>
#include <QFuture>

class ThesaurusViewModel : public QObject
{
    Q_OBJECT
public:
    explicit ThesaurusViewModel(ThesaurusRepository *repository, QObject *parent = nullptr);
    QFuture<QList<ThesaurusDisplayData*>*> readThesaurus(QString searchText);

private:
    ThesaurusRepository *repository;
};

#endif // THESAURUSVIEWMODEL_H

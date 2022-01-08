#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "rhymelistmodel.h"
#include "definitionlistmodel.h"
#include "thesauruslistmodel.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(RhymeListModel *rhymeListModel, ThesaurusListModel *thesaurusListModel, DefinitionListModel *definitionsListModel, QObject *parent = nullptr);
    Q_INVOKABLE void search(QString query);
signals:

private:
    RhymeListModel *rhymeListModel;
    ThesaurusListModel *thesaurusListModel;
    DefinitionListModel *definitionsListModel;
};

#endif // MAINVIEWMODEL_H

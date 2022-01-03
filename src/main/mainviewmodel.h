#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "definitionlistmodel.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(DefinitionListModel *definitionsListModel, QObject *parent = nullptr);
    Q_INVOKABLE void search(QString query);
signals:

private:
    DefinitionListModel *definitionsListModel;
};

#endif // MAINVIEWMODEL_H

#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "definitionslistmodel.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(DefinitionsListModel *definitionsListModel, QObject *parent = nullptr);
    Q_INVOKABLE void search(QString query);
signals:

private:
    DefinitionsListModel *definitionsListModel;
};

#endif // MAINVIEWMODEL_H

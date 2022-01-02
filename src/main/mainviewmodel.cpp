#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(DefinitionsListModel *definitionsListModel, QObject *parent)
    : QObject{parent}, definitionsListModel(definitionsListModel)
{

}

void MainViewModel::search(QString searchText) {
    qDebug() << "search " << searchText;
    definitionsListModel->readDefinitions(searchText);
}

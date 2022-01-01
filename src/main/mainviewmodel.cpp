#include "mainviewmodel.h"
#include <QDebug>
MainViewModel::MainViewModel(QObject *parent)
    : QObject{parent}
{

}

void MainViewModel::search(QString searchText) {
    qDebug() << "search " << searchText;
}

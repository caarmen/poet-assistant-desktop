#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(QObject *parent = nullptr);
    Q_INVOKABLE void search(QString query);
signals:

};

#endif // MAINVIEWMODEL_H

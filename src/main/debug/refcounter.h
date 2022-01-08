#ifndef REFCOUNTER_H
#define REFCOUNTER_H

#include <QObject>

class RefCounter : public QObject
{
    Q_OBJECT
public:
    explicit RefCounter(QString label, bool enabled = false, QObject *parent = nullptr);
    void inc();
    void dec();

private:
    QString label;
    int count;
    bool enabled;
};

#endif // REFCOUNTER_H

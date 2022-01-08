#include "refcounter.h"

#include <QDebug>

RefCounter::RefCounter(QString label, bool enabled, QObject *parent)
    : QObject{parent}, label(label), enabled(enabled), count(0)
{
}

void RefCounter::inc() {
    count++;
    if (enabled) qDebug() << "new" << label << "(" << count << ")";
}

void RefCounter::dec() {
    count--;
    if (enabled) qDebug() << "del" << label << "(" << count << ")";
}


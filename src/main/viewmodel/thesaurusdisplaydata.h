#ifndef THESAURUSDISPLAYDATA_H
#define THESAURUSDISPLAYDATA_H

#include <QObject>

class ThesaurusDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text CONSTANT)
public:
    explicit ThesaurusDisplayData(QString text, QObject *parent = nullptr);
    const QString text;
signals:

};

#endif // THESAURUSDISPLAYDATA_H

#ifndef THESAURUSDISPLAYDATA_H
#define THESAURUSDISPLAYDATA_H

#include <QObject>

class ThesaurusDisplayData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text CONSTANT)
    Q_PROPERTY(bool italic MEMBER italic CONSTANT)
    Q_PROPERTY(bool bold MEMBER bold CONSTANT)
public:
    explicit ThesaurusDisplayData(QString text, bool italic = false, bool bold = false, QObject *parent = nullptr);
    const QString text;
    const bool italic;
    const bool bold;
signals:

};

#endif // THESAURUSDISPLAYDATA_H

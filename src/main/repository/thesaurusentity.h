#ifndef THESAURUSENTITY_H
#define THESAURUSENTITY_H

#include <QObject>

class ThesaurusEntity : public QObject
{
    Q_OBJECT
public:
    explicit ThesaurusEntity(QString wordType, QString synonyms, QString antonyms, QObject *parent = nullptr);

    const QString wordType;
    const QString synonyms;
    const QString antonyms;
signals:

};

#endif // THESAURUSENTITY_H

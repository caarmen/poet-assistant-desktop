#ifndef THESAURUSENTITY_H
#define THESAURUSENTITY_H

#include "refcounter.h"
#include <QObject>

class ThesaurusEntity : public QObject
{
    Q_OBJECT
public:
    explicit ThesaurusEntity(QString wordType, QString synonyms, QString antonyms, QObject *parent = nullptr);
    ~ThesaurusEntity();
    const QString wordType;
    const QString synonyms;
    const QString antonyms;

private:
    static inline RefCounter refCounter = RefCounter("ThesaurusEntity");
};

#endif // THESAURUSENTITY_H

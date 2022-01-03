#include "thesaurusentity.h"

ThesaurusEntity::ThesaurusEntity(QString wordType, QString synonyms, QString antonyms, QObject *parent)
    : QObject{parent}, wordType(wordType), synonyms(synonyms), antonyms(antonyms)
{

}

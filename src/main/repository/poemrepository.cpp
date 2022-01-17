#include "poemrepository.h"

PoemRepository::PoemRepository(QObject *parent)
    : QObject{parent}, state(SAVED)
{
    poem = settings.value(poemSetting).value<QString>();
    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, this, QOverload<>::of(&PoemRepository::writePoemImpl));
}

const QString PoemRepository::readPoem() const {
    return poem;
}

void PoemRepository::writePoem(QString poem) {
    this->poem = poem;
    state = UNSAVED;
    emit stateChanged();
    timer.start(saveDelayMs);
}

void PoemRepository::writePoemImpl() {
    state = SAVING;
    emit stateChanged();
    settings.setValue(poemSetting, poem);
    state = SAVED;
    emit stateChanged();
}

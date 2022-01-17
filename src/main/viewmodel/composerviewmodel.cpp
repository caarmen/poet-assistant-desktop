#include "composerviewmodel.h"

ComposerViewModel::ComposerViewModel(PoemRepository *repository, QObject *parent)
    : QObject{parent},
      repository(repository)
{
    QObject::connect(repository, &PoemRepository::stateChanged, this, [=] {
        onSavedStateChanged(repository->state);
    });
}

const QString ComposerViewModel::getSavedState() const {
    return savedState;
}

const QString ComposerViewModel::readPoem() const {
    return repository->readPoem();
}

void ComposerViewModel::writePoem(QString poem) {
    repository->writePoem(poem);
}

void ComposerViewModel::onSavedStateChanged(PoemRepository::PoemSavedState savedState) {
    if (savedState == PoemRepository::UNSAVED) {
        this->savedState = "";
    } else if (savedState == PoemRepository::SAVING) {
        this->savedState = "state_saving";
    } else if (savedState == PoemRepository::SAVED) {
        this->savedState= "state_saved";
    }
    emit savedStateChanged();
}

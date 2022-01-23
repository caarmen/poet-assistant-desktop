#include "composerviewmodel.h"
#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>

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

const QString ComposerViewModel::getPoem() const {
    return repository->getPoem();
}

const QString ComposerViewModel::getFileDialogFile() const {
    QFileInfo poemFileInfo(repository->getPoemFilePath());
    QString poemFileFolder = poemFileInfo.absoluteFilePath() == repository->getDefaultPoemFilePath() ?
                QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) :
                poemFileInfo.absolutePath();
    QString poemFileName = poemFileInfo.absoluteFilePath() == repository->getDefaultPoemFilePath() ?
                repository->generateFilenameFromPoemText() :
                poemFileInfo.fileName();
    return QUrl::fromLocalFile(QFileInfo(poemFileFolder, poemFileName).absoluteFilePath()).toString();
}

const QString ComposerViewModel::getFileDialogFolder() const {
    QFileInfo poemFileInfo(repository->getPoemFilePath());
    QString poemFileFolder = poemFileInfo.absoluteFilePath() == repository->getDefaultPoemFilePath() ?
                QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) :
                poemFileInfo.absolutePath();
    return QUrl::fromLocalFile(poemFileFolder).toString();
}
const QString ComposerViewModel::getPoemFileName() const {
    QString poemFilePath = repository->getPoemFilePath();
    return poemFilePath == repository->getDefaultPoemFilePath()? "" : QFileInfo(poemFilePath).fileName();
}

void ComposerViewModel::writePoem(QString poem) {
    repository->writePoem(poem);
}

void ComposerViewModel::newFile() {
    repository->newFile();
    emit poemFileNameChanged();
}

void ComposerViewModel::open(QUrl poemFilePath) {
    repository->open(poemFilePath.toLocalFile());
    emit poemFileNameChanged();
}
void ComposerViewModel::saveAs(QUrl poemFilePath) {
    repository->saveAs(poemFilePath.toLocalFile());
    emit poemFileNameChanged();
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

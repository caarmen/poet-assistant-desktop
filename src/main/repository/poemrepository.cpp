#include "poemrepository.h"

#include <QStandardPaths>
#include <QDir>
#include <QRegularExpression>

PoemRepository::PoemRepository(QObject *parent)
    : QObject{parent}, state(SAVED)
{
    QString appDataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkdir(appDataDir);
    defaultPoemFilePath = QFileInfo(appDataDir, "poem.txt").absoluteFilePath();
    poemFilePath = settings.value(poemFilePathSetting).value<QString>();
    if (poemFilePath.isEmpty()) {
        poemFilePath = defaultPoemFilePath;
    }
    readPoemImpl();

    timer.setSingleShot(true);
    QObject::connect(&timer, &QTimer::timeout, this, QOverload<>::of(&PoemRepository::writePoemImpl));
}

const QString PoemRepository::getPoem() const {
    return poem;
}

const QString PoemRepository::getPoemFilePath() const {
    return poemFilePath;
}

const QString PoemRepository::getDefaultPoemFilePath() const {
    return defaultPoemFilePath;
}

const QString PoemRepository::generateFilenameFromPoemText() const {
    int minLength = 8;
    int maxLength = 16;
    QString suggestion = poem;
    return suggestion
            // replace all non-letters by hyphens
            .replace(QRegularExpression("[^\\p{L}]+"), "-")
            // remove a leading hyphen
            .replace(QRegularExpression("^-"), "")
            // get a substring of maxLength
            .left(maxLength)
            // remove the last partial word
            .replace(QRegularExpression(QString("(.{%1}[^-]*)-[^-]*$").arg(minLength)), "\\1");
}

void PoemRepository::newFile() {
    writePoemImpl();
    this->poemFilePath = defaultPoemFilePath;
    settings.setValue(poemFilePathSetting, poemFilePath);
    poem = "";
    writePoemImpl();
}

void PoemRepository::open(QString poemFilePath) {
    writePoemImpl();
    this->poemFilePath = poemFilePath;
    settings.setValue(poemFilePathSetting, poemFilePath);
    readPoemImpl();
}

void PoemRepository::saveAs(QString poemFilePath) {
    this->poemFilePath = poemFilePath;
    settings.setValue(poemFilePathSetting, poemFilePath);
    writePoemImpl();
}

void PoemRepository::writePoem(QString poem) {
    this->poem = poem;
    state = UNSAVED;
    emit stateChanged();
    timer.start(saveDelayMs);
}

void PoemRepository::readPoemImpl() {
    // TODO read from disk in a background thread?
    QFile poemFile(poemFilePath);
    if (poemFile.open(QIODevice::ReadOnly)) {
        poem = poemFile.readAll();
        poemFile.close();
    }
}

void PoemRepository::writePoemImpl() {
    state = SAVING;
    emit stateChanged();
    // TODO write to disk in a background thread?
    QFile poemFile(poemFilePath);
    if (poemFile.open(QIODevice::WriteOnly)) {
        poemFile.write(poem.toUtf8());
        poemFile.close();
    }
    state = SAVED;
    emit stateChanged();
}

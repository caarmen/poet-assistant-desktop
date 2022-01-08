#include "rhymelistmodel.h"
#include "rhymeentitymapper.h"

RhymeListModel::RhymeListModel(RhymeViewModel *viewModel, QObject *parent)
    : QAbstractListModel{parent}, viewModel(viewModel), rhymeEntries(nullptr)
{

}

void RhymeListModel::readRhymes(QString searchText) {
    beginResetModel();
    if (rhymeEntries != nullptr) {
        qDeleteAll(*rhymeEntries);
        delete rhymeEntries;
    }
    QObject *context = new QObject(this);
    QObject::connect(viewModel, &RhymeViewModel::onRhymesFetched, context, [=](QList<RhymeDisplayData*>* rhymes) {
        context->deleteLater();
        rhymeEntries = rhymes;
        endResetModel();
    });
    viewModel->readRhymes(searchText);
}

QHash<int,QByteArray> RhymeListModel::roleNames() const {
    return { { RhymeRole, "rhyme" } };
}

int RhymeListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()) return 0;

    return rhymeEntries == nullptr ? 0 : rhymeEntries->size();
}

QVariant RhymeListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role == RhymeRole) {
        return QVariant::fromValue(rhymeEntries->at(index.row()));
    } else {
        return QVariant();
    }
}

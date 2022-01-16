#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include "rhymelistmodel.h"
#include "definitionlistmodel.h"
#include "thesauruslistmodel.h"
#include "favoriterepository.h"

class MainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit MainViewModel(RhymeListModel *rhymeListModel,
                           ThesaurusListModel *thesaurusListModel,
                           DefinitionListModel *definitionsListModel,
                           FavoriteRepository *favoriteRepository,
                           QObject *parent = nullptr);
    Q_INVOKABLE void search(QString query);
    Q_INVOKABLE void searchRhymes(QString query);
    Q_INVOKABLE void searchThesaurus(QString query);
    Q_INVOKABLE void searchDefinitions(QString query);
    Q_INVOKABLE QString getFavoriteIcon(QString word);
    Q_INVOKABLE void toggleFavorite(QString query);

signals:
    void favoritesChanged();

private:
    RhymeListModel *rhymeListModel;
    ThesaurusListModel *thesaurusListModel;
    DefinitionListModel *definitionsListModel;
    FavoriteRepository *favoriteRepository;
};

#endif // MAINVIEWMODEL_H

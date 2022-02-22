#ifndef PREFERENCESVIEWMODEL_H
#define PREFERENCESVIEWMODEL_H

#include "suggestionrepository.h"
#include <QObject>

class PreferencesViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool historyEnabled READ getSettingUseSearchHistory WRITE setSettingUseSearchHistory
               NOTIFY historyEnabledChanged)

public:
    explicit PreferencesViewModel(SuggestionRepository *suggestionRepository,
                                  QObject *parent = nullptr);

signals:
    void historyEnabledChanged();
private:
    bool getSettingUseSearchHistory();
    void setSettingUseSearchHistory(bool enabled);
    SuggestionRepository *suggestionRepository;

};

#endif // PREFERENCESVIEWMODEL_H

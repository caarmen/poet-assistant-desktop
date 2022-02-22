#ifndef PREFERENCESVIEWMODEL_H
#define PREFERENCESVIEWMODEL_H

#include "suggestionrepository.h"
#include "appearancerepository.h"
#include "nightmodeenum.h"
#include "styleenum.h"
#include <QObject>

class PreferencesViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool historyEnabled READ getSettingUseSearchHistory WRITE setSettingUseSearchHistory
               NOTIFY historyEnabledChanged)
    Q_PROPERTY(NightMode nightMode READ getNightMode WRITE setNightMode NOTIFY nightModeChanged)
    Q_PROPERTY(Style style READ getStyle WRITE setStyle NOTIFY styleChanged)

public:
    explicit PreferencesViewModel(SuggestionRepository *suggestionRepository,
                                  AppearanceRepository *appearanceRepository,
                                  QObject *parent = nullptr);

signals:
    void historyEnabledChanged();
    void nightModeChanged();
    void styleChanged();
private:
    bool getSettingUseSearchHistory();
    void setSettingUseSearchHistory(bool enabled);
    NightMode getNightMode();
    void setNightMode(NightMode nightMode);
    Style getStyle();
    void setStyle(Style style);

    SuggestionRepository *suggestionRepository;
    AppearanceRepository *appearanceRepository;

};

#endif // PREFERENCESVIEWMODEL_H

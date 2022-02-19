/**
Copyright (c) 2022 - present Carmen Alvarez

This file is part of Poet Assistant.

Poet Assistant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Poet Assistant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    anchors.fill: parent
    signal toastTextChanged(string text)
    function onSearched() {
        if (bar.currentIndex > Tabs.Tabs.DICTIONARY) bar.currentIndex = Tabs.Tabs.DICTIONARY
    }

    function applyTheme() {
        for (var i = 0; i < bar.count; i++) {
            bar.itemAt(i).applyTheme()
        }
    }

    function handleMenuItemSelected(menuItemId) {
        if(composerTabView.handleMenuItemSelected(menuItemId)) {
            bar.currentIndex = Tabs.Tabs.COMPOSER
        }
    }

    Rectangle {
        Layout.preferredHeight: childrenRect.height
        Layout.fillWidth: true
        TabBar {
            background: Rectangle { color: Style.surface }
            id: bar
            width: parent.width
            TabButtonView {
                iconSource: "ic_rhymer"
                tabName: "tab_rhymes"
            }
            TabButtonView {
                iconSource: "ic_thesaurus"
                tabName: "tab_thesaurus"
            }
            TabButtonView {
                iconSource: "ic_definitions"
                tabName: "tab_definitions"
            }
            TabButtonView {
                iconSource: "ic_composer"
                tabName: "tab_composer"
            }
            TabButtonView {
                iconSource: "star"
                tabName: "tab_favorites"
            }
        }
    }
    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        color: Style.background
        StackLayout {
            anchors.fill: parent
            currentIndex: bar.currentIndex
            Item {
                id: rhymesTab
                RhymeTabView {
                    onRhymeToastTextChanged: (text) => toastTextChanged(text)
                }
            }
            Item {
                id: thesaurusTab
                ThesaurusTabView {
                    onThesaurusToastTextChanged: (text) => toastTextChanged(text)
                }
            }
            Item {
                id: definitionsTab
                DictionaryTabView  {
                    onDefinitionToastTextChanged: (text) => toastTextChanged(text)
                }
            }
            Item {
                id: composerTab
                ComposerTabView{
                    id: composerTabView
                }
            }
            Item {
                id: favoritesTab
                FavoriteTabView{
                    onFavoriteToastTextChanged: (text) => toastTextChanged(text)
                }
            }
        }
    }
}

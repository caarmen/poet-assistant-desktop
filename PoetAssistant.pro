# Copyright (c) 2022 - present Carmen Alvarez
#
# This file is part of Poet Assistant.
#
# Poet Assistant is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Poet Assistant is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.

TEMPLATE = subdirs

SUBDIRS = app tts
DISTFILES += .astylerc

tts.file=lib/qtspeech/src/tts/tts.pro
app.depends += tts

macx:{
    SUBDIRS += ttsosxplugin
    ttsosxplugin.file=lib/qtspeech/src/plugins/tts/osx/osx.pro
    ttsosxplugin.depends = tts
    app.depends += ttsosxplugin
}
linux-g++:{
    SUBDIRS += ttslinuxplugin
    ttslinuxplugin.file=lib/qtspeech/src/plugins/tts/speechdispatcher/speechdispatcher.pro
    ttslinuxplugin.depends = tts
    app.depends +=  ttslinuxplugin
}
win32:{
    SUBDIRS += ttswinplugin
    ttswinplugin.file=lib/qtspeech/src/plugins/tts/sapi/sapi.pro
    ttswinplugin.depends = tts
    app.depends += ttswinplugin
}

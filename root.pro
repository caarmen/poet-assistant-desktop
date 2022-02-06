TEMPLATE = subdirs

SUBDIRS = app tts

app.file = app/PoetAssistant.pro
tts.file=lib/qtspeech/src/tts/tts.pro
app.depends += tts

macx:{
    SUBDIRS += ttsosxplugin

    ttsosxplugin.file=lib/qtspeech/src/plugins/tts/osx/osx.pro
    ttsosxplugin.depends = tts
    app.depends += ttsosxplugin
}



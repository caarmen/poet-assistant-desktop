TEMPLATE = subdirs

SUBDIRS = app
app.file = app/PoetAssistant.pro

macx:{
    SUBDIRS += tts ttsplugin

    tts.file=lib/qtspeech/src/tts/tts.pro
    ttsplugin.file=lib/qtspeech/src/plugins/tts/osx/osx.pro
    ttsplugin.depends = tts
    app.depends += tts ttsplugin
}



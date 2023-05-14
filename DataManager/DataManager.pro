QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drafts/test.cpp \
    sources/databasemodel.cpp \
    sources/main.cpp \
    sources/databaseview.cpp

HEADERS += \
    drafts/test.h \
    headers/databaseview.h \
    headers/databasemodel.h

FORMS += \
    forms/databaseview.ui

TRANSLATIONS += \
    DataManager_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    drafts/attributes.qmodel \
    drafts/characters.qmodel \
    drafts/consequences.qmodel \
    drafts/databaseomodeldraft.qmodel \
    drafts/databaseview.qmodel \
    drafts/items.qmodel \
    notes/TODO

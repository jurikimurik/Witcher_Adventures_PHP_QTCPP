QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    forms/sources/item/itemsview.cpp \
    sources/item/buff.cpp \
    sources/item/item.cpp \
    sources/item/itemsmodel.cpp \
    sources/item/itemtype.cpp \
    sources/special/attributes.cpp \
    sources/database/databasemodel.cpp \
    sources/main.cpp \
    sources/database/databaseview.cpp

HEADERS += \
    forms/headers/item/itemsview.h \
    headers/database/databaseview.h \
    headers/database/databasemodel.h \
    headers/item/buff.h \
    headers/item/item.h \
    headers/item/itemsmodel.h \
    headers/item/itemtype.h \
    headers/special/attributes.h

FORMS += \
    forms/GUI/database/databaseview.ui \
    forms/GUI/item/itemsview.ui

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

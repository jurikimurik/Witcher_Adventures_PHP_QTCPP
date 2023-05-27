QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    forms/sources/action/actionview.cpp \
    forms/sources/consequence/consequencesview.cpp \
    forms/sources/character/characterview.cpp \
    forms/sources/item/itemtypeview.cpp \
    forms/sources/item/buffview.cpp \
    forms/sources/item/itemsview.cpp \
    sources/action/action.cpp \
    sources/action/agilityaction.cpp \
    sources/action/basic/choice.cpp \
    sources/action/battleaction.cpp \
    sources/action/choiceaction.cpp \
    sources/action/descriptionaction.cpp \
    sources/action/diceaction.cpp \
    sources/action/event.cpp \
    sources/action/eventsmodel.cpp \
    sources/action/rewardaction.cpp \
    sources/basic/databaseitem.cpp \
    sources/character/character.cpp \
    sources/character/charactermodel.cpp \
    sources/consequence/consequence.cpp \
    sources/consequence/consequencesmodel.cpp \
    sources/item/buffmodel.cpp \
    sources/item/buff.cpp \
    sources/item/item.cpp \
    sources/item/itemsmodel.cpp \
    sources/item/itemtype.cpp \
    sources/item/itemtypecontroller.cpp \
    sources/item/itemtypemodel.cpp \
    sources/special/attributes.cpp \
    sources/database/databasemodel.cpp \
    sources/main.cpp \
    forms/sources/database/databaseview.cpp

HEADERS += \
    forms/headers/action/actionview.h \
    forms/headers/consequence/consequencesview.h \
    forms/headers/character/characterview.h \
    forms/headers/item/itemtypeview.h \
    forms/headers/item/buffview.h \
    forms/headers/item/itemsview.h \
    headers/action/action.h \
    headers/action/agilityaction.h \
    headers/action/basic/choice.h \
    headers/action/battleaction.h \
    headers/action/choiceaction.h \
    headers/action/descriptionaction.h \
    headers/action/diceaction.h \
    headers/action/event.h \
    headers/action/eventsmodel.h \
    headers/action/rewardaction.h \
    headers/basic/databaseitem.h \
    headers/character/character.h \
    headers/character/charactermodel.h \
    headers/consequence/consequence.h \
    headers/consequence/consequencesmodel.h \
    headers/item/buffmodel.h \
    forms/headers/database/databaseview.h \
    headers/database/databasemodel.h \
    headers/item/buff.h \
    headers/item/item.h \
    headers/item/itemsmodel.h \
    headers/item/itemtype.h \
    headers/item/itemtypecontroller.h \
    headers/item/itemtypemodel.h \
    headers/special/attributes.h

FORMS += \
    forms/GUI/action/actionview.ui \
    forms/GUI/consequence/consequencesview.ui \
    forms/GUI/character/characterview.ui \
    forms/GUI/database/databaseview.ui \
    forms/GUI/item/itemsview.ui \
    forms/GUI/item/buffview.ui \
    forms/GUI/item/itemtypeview.ui

TRANSLATIONS += \
    DataManager_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    drafts/actions.qmodel \
    drafts/attributes.qmodel \
    drafts/characters.qmodel \
    drafts/consequences.qmodel \
    drafts/databaseomodeldraft.qmodel \
    drafts/databaseview.qmodel \
    drafts/items.qmodel \
    notes/TODO

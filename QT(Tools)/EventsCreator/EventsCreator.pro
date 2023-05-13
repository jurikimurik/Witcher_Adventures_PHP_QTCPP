QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    action.cpp \
    buff.cpp \
    character.cpp \
    consequence.cpp \
    databasemodel.cpp \
    databaseview.cpp \
    item.cpp \
    main.cpp \
    eventscreatorgui.cpp

HEADERS += \
    action.h \
    attributes.h \
    buff.h \
    character.h \
    consequence.h \
    databasemodel.h \
    databaseview.h \
    eventscreatorgui.h \
    item.h

FORMS += \
    databaseview.ui \
    eventscreatorgui.ui

TRANSLATIONS += \
    EventsCreator_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
    DatabaseModelChart.scxml

DISTFILES += \
    EventsClass.qmodel \
    databasemodel.qmodel

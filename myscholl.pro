QT       += core gui
QT += sql
QT += qml
QT += quickwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#DESTDIR = $$PWD/bin/
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/../QxOrm/include
SOURCES += \
    dialogsync.cpp \
    dolibarrapi.cpp \
    dolibarrapibuilder.cpp \
    importgroup.cpp \
    main.cpp \
    mainwindow.cpp \
    setup.cpp \
    simat.cpp \
    sqlmodels/checkboxdelegate.cpp \
    sqlmodels/radiodelegate.cpp \
    sqlmodels/usermodel.cpp \
    student.cpp \
    userconnection.cpp \
    util.cpp



HEADERS += \
    dialogsync.h \
    dolibarrapi.h \
    dolibarrapibuilder.h \
    export.h \
    importgroup.h \
    mainwindow.h \
    precompiled.h \
    setup.h \
    simat.h \
    sqlmodels/areamodel.h \
    sqlmodels/checkboxdelegate.h \
    sqlmodels/radiodelegate.h \
    sqlmodels/usermodel.h \
    student.h \
    userconnection.h \
    util.h


FORMS += \
    dialogsync.ui \
    importgroup.ui \
    mainwindow.ui \
    setup.ui \
    userconnection.ui

TRANSLATIONS += \
    myscholl_es_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../QxOrm/lib/ -lQxOrm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../QxOrm/lib/ -lQxOrmd
else:unix:!macx: LIBS += -L$$PWD/../QxOrm/lib/ -lQxOrmd


DEPENDPATH += $$PWD/../QxOrm/include




SUBDIRS += \




DISTFILES += \
    binding.qml

RESOURCES += \
    files.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qtcsv/lib/ -lqtcsv
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qtcsv/lib/ -lqtcsvd
else:unix:!macx: LIBS += -L$$PWD/../qtcsv/build/ -lqtcsv

INCLUDEPATH += $$PWD/../qtcsv/include
DEPENDPATH += $$PWD/../qtcsv/include


unix:!macx|win32: LIBS += -L$$PWD/qtcsv/lib/ -lqtcsv

INCLUDEPATH += $$PWD/qtcsv/include
DEPENDPATH += $$PWD/qtcsv/include

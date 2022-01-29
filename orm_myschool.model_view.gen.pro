#################################################################################################
## File created by QxEntityEditor 1.2.6 (2021/12/19 21:16) : please, do NOT modify this file ! ##
#################################################################################################

include(/home/ander/qtproyects/QxOrm/QxOrm.pri)

TEMPLATE = lib
CONFIG += dll
DEFINES += _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
INCLUDEPATH += /home/ander/qtproyects/QxOrm/include
DESTDIR = $$PWD/bin/

LIBS += -L"/home/ander/qtproyects/QxOrm/lib"
LIBS += -L"$$PWD/orm/bin"

CONFIG(debug, debug|release) {
LIBS += -l"QxOrmd"
LIBS += -l"orm_myschoold"
} else {
LIBS += -l"QxOrm"
LIBS += -l"orm_myschool"
} # CONFIG(debug, debug|release)

CONFIG(debug, debug|release) {
TARGET = orm_myschoolModeld
} else {
TARGET = orm_myschoolModel
} # CONFIG(debug, debug|release)

include($$PWD/orm_myschool.model_view.gen.pri)

!contains(DEFINES, _QX_UNITY_BUILD) {
SOURCES += $$PWD/src/orm_myschool_main.model_view.gen.cpp
} # !contains(DEFINES, _QX_UNITY_BUILD)

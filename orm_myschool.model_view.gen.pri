#################################################################################################
## File created by QxEntityEditor 1.2.6 (2021/12/19 21:16) : please, do NOT modify this file ! ##
#################################################################################################

!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
PRECOMPILED_HEADER += $$PWD/include/orm_myschool_precompiled_header.model_view.gen.h
} # !contains(DEFINES, _QX_NO_PRECOMPILED_HEADER)

HEADERS += $$PWD/include/orm_myschool_precompiled_header.model_view.gen.h
HEADERS += $$PWD/include/orm_myschool_export.model_view.gen.h

HEADERS += $$PWD/include/area.model_view.gen.h
HEADERS += $$PWD/include/enrroll.model_view.gen.h
HEADERS += $$PWD/include/simat.model_view.gen.h
HEADERS += $$PWD/include/student.model_view.gen.h
HEADERS += $$PWD/include/subject.model_view.gen.h

HEADERS += $$PWD/custom/include/area.model_view.h
HEADERS += $$PWD/custom/include/enrroll.model_view.h
HEADERS += $$PWD/custom/include/simat.model_view.h
HEADERS += $$PWD/custom/include/student.model_view.h
HEADERS += $$PWD/custom/include/subject.model_view.h

contains(DEFINES, _QX_UNITY_BUILD) {

SOURCES += $$PWD/src/orm_myschool_all.model_view.gen.cpp

} else {

SOURCES += $$PWD/src/area.model_view.gen.cpp
SOURCES += $$PWD/src/enrroll.model_view.gen.cpp
SOURCES += $$PWD/src/simat.model_view.gen.cpp
SOURCES += $$PWD/src/student.model_view.gen.cpp
SOURCES += $$PWD/src/subject.model_view.gen.cpp

SOURCES += $$PWD/custom/src/area.model_view.cpp
SOURCES += $$PWD/custom/src/enrroll.model_view.cpp
SOURCES += $$PWD/custom/src/simat.model_view.cpp
SOURCES += $$PWD/custom/src/student.model_view.cpp
SOURCES += $$PWD/custom/src/subject.model_view.cpp

} # contains(DEFINES, _QX_UNITY_BUILD)

include($$PWD/custom/orm_myschool.model_view.pri)

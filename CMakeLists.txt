#################################################################################################
## File created by QxEntityEditor 1.2.6 (2021/12/19 21:16) : please, do NOT modify this file ! ##
#################################################################################################

cmake_minimum_required(VERSION 3.1)

project(orm_myschoolModel LANGUAGES CXX)

if(NOT TARGET QxOrm)
   add_subdirectory("/home/ander/qtproyects/QxOrm/" ./QxOrm)
endif() # NOT TARGET QxOrm
if(NOT TARGET orm_myschool)
   add_subdirectory("orm/" ./orm_myschool)
endif() # NOT TARGET orm_myschool

include("/home/ander/qtproyects/QxOrm/QxOrm.cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_DEBUG_POSTFIX "d")

set(ORM_MYSCHOOL_MODEL_HEADERS
    ./include/orm_myschool_precompiled_header.model_view.gen.h
    ./include/orm_myschool_export.model_view.gen.h
    ./include/area.model_view.gen.h
    ./include/enrroll.model_view.gen.h
    ./include/simat.model_view.gen.h
    ./include/student.model_view.gen.h
    ./include/subject.model_view.gen.h
    ./custom/include/area.model_view.h
    ./custom/include/enrroll.model_view.h
    ./custom/include/simat.model_view.h
    ./custom/include/student.model_view.h
    ./custom/include/subject.model_view.h
   )

if(_QX_UNITY_BUILD)

   set(ORM_MYSCHOOL_MODEL_SRCS ./src/orm_myschool_all.model_view.gen.cpp)

else() # _QX_UNITY_BUILD

   set(ORM_MYSCHOOL_MODEL_SRCS
       ./src/area.model_view.gen.cpp
       ./src/enrroll.model_view.gen.cpp
       ./src/simat.model_view.gen.cpp
       ./src/student.model_view.gen.cpp
       ./src/subject.model_view.gen.cpp
       ./custom/src/area.model_view.cpp
       ./custom/src/enrroll.model_view.cpp
       ./custom/src/simat.model_view.cpp
       ./custom/src/student.model_view.cpp
       ./custom/src/subject.model_view.cpp
       ./src/orm_myschool_main.model_view.gen.cpp
      )

endif() # _QX_UNITY_BUILD

add_library(orm_myschoolModel SHARED ${ORM_MYSCHOOL_MODEL_SRCS} ${ORM_MYSCHOOL_MODEL_HEADERS})

target_compile_definitions(orm_myschoolModel PRIVATE -D_BUILDING_MODEL_VIEW_ORM_MYSCHOOL )

if(COMMAND target_precompile_headers)
   target_precompile_headers(orm_myschoolModel PRIVATE ./include/orm_myschool_precompiled_header.model_view.gen.h)
endif() # (COMMAND target_precompile_headers)

target_link_libraries(orm_myschoolModel ${QX_LIBRARIES} QxOrm orm_myschool )

set_target_properties(orm_myschoolModel PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                      RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_CURRENT_SOURCE_DIR}/bin"
                     )

qx_auto_source_group("${ORM_MYSCHOOL_MODEL_SRCS};${ORM_MYSCHOOL_MODEL_HEADERS}")

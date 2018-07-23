cmake_minimum_required(VERSION 3.6)
project(browthon_app)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Core)

if(GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# user config config file
include(user-config.cmake OPTIONAL)

file(
        GLOB_RECURSE
        SOURCE_FILES
        main.cpp \
        Core/*.hpp \
        Core/*.cpp
)

file(
        GLOB_RECURSE
        QRC_FILES
        *.qrc
)

find_package(Qt5Widgets 5.8 REQUIRED)
find_package(Qt5WebEngine 5.8 REQUIRED)
find_package(Qt5WebEngineWidgets 5.8 REQUIRED)

add_executable(browthon_app ${SOURCE_FILES} ${QRC_FILES})

set(BROWTHON_LIBS Qt5::Widgets Qt5::WebEngine Qt5::WebEngineWidgets)
target_link_libraries(browthon_app LINK_PUBLIC ${BROWTHON_LIBS})
cmake_minimum_required(VERSION 3.6)
project(browthon_app)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Core)

if(GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

set(SOURCE_FILES main.cpp Core/Browser.hpp Core/Browser.cpp Core/BrowserWidget.hpp Core/BrowserWidget.cpp Core/Widgets/WebPage.hpp Core/Widgets/WebPage.cpp Core/Widgets/WebView.hpp Core/Widgets/WebView.cpp Core/Widgets/UrlInput.hpp Core/Widgets/UrlInput.cpp Core/Widgets/TabWidget.hpp Core/Widgets/TabWidget.cpp Core/Utils/WebHitTestResult.hpp Core/Utils/WebHitTestResult.cpp)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

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
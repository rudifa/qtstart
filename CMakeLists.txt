cmake_minimum_required(VERSION 3.16)

project(qtstart VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Qt6 directory and prefix path
set(Qt6_DIR "/Users/rudifarkas/Qt/6.8.2/macos/lib/cmake/Qt6")
set(CMAKE_PREFIX_PATH "${Qt6_DIR}")

# Find required Qt packages
find_package(Qt6 6.8.2 COMPONENTS Widgets SvgWidgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

qt_add_executable(qtstart
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(qtstart PRIVATE Qt6::Widgets Qt6::SvgWidgets)

set_target_properties(qtstart PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS qtstart
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

qt_finalize_executable(qtstart)

rudifa: explain CMakelist.txt

GitHub Copilot: This

CMakeLists.txt

 file is used to configure the build process for a Qt-based C++ project using CMake. Here's a breakdown of its contents:

1. **CMake Version Requirement**:
    ```cmake
    cmake_minimum_required(VERSION 3.16)
    ```

2. **Project Definition**:
    ```cmake
    project(untitled VERSION 0.1 LANGUAGES CXX)
    ```

3. **CMake Options**:
    ```cmake
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    ```

4. **Find Qt Packages**:
    ```cmake
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
    ```

5. **Translation Files**:
    ```cmake
    set(TS_FILES untitled_en_CH.ts)
    ```

6. **Project Sources**:
    ```cmake
    set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
    )
    ```

7. **Executable and Translation Creation**:
    ```cmake
    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(untitled
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
        )
        qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
    else()
        if(ANDROID)
            add_library(untitled SHARED
                ${PROJECT_SOURCES}
            )
        else()
            add_executable(untitled
                ${PROJECT_SOURCES}
            )
        endif()
        qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
    endif()
    ```

8. **Link Libraries**:
    ```cmake
    target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
    ```

9. **Bundle Identifier for macOS/iOS**:
    ```cmake
    if(${QT_VERSION} VERSION_LESS 6.1.0)
      set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled)
    endif()
    ```

10. **Target Properties**:
    ```cmake
    set_target_properties(untitled PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )
    ```

11. **Installation Directories**:
    ```cmake
    include(GNUInstallDirs)
    install(TARGETS untitled
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
    ```

12. **Finalize Executable for Qt 6**:
    ```cmake
    if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(untitled)
    endif()
    ```

This file configures the build system to handle different Qt versions, sets up automatic handling of Qt-specific files, defines the project sources, and specifies how to build and link the executable. It also includes platform-specific settings for macOS and iOS.

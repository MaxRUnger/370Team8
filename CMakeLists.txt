cmake_minimum_required(VERSION 3.16)

project(LyfeStyle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt modules, including Sql for database functionality
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# All source, header, and UI files in the project
set(PROJECT_SOURCES
    main.cpp

    tasklistwindow.cpp
    tasklistwindow.h
    tasklistwindow.ui

    journalwindow.cpp
    journalwindow.h
    journalwindow.ui

    moodtracker.cpp
    moodtracker.h
    moodtracker.ui
)

# Executable setup for Qt 5 and 6
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LyfeStyle
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(LyfeStyle SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(LyfeStyle
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link required Qt libraries
target_link_libraries(LyfeStyle PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# macOS / iOS bundle configuration (optional)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LyfeStyle)
endif()
set_target_properties(LyfeStyle PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Install rules
include(GNUInstallDirs)
install(TARGETS LyfeStyle
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LyfeStyle)
endif()

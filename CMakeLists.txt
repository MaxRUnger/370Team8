cmake_minimum_required(VERSION 3.16)

project(LyfeStyle VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 or Qt6 (Widgets + Sql + Test + Gui)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Test Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Test Gui)

# Source, header, and UI files (no tests.cpp here)
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

    LoginPage.cpp
    LoginPage.h
    LoginPage.ui

    User.cpp
    User.h

    UserManager.cpp
    UserManager.h

    PasswordHasher.cpp
    PasswordHasher.h

    DatabaseManager.cpp
    DatabaseManager.h
)

# Main executable
add_executable(LyfeStyle ${PROJECT_SOURCES})

# Link Qt libraries to main app
target_link_libraries(LyfeStyle PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# Separate test executable
add_executable(tests
    tests.cpp

    moodtracker.cpp
    tasklistwindow.cpp
    journalwindow.cpp
    DatabaseManager.cpp
    tests.h
)
set_target_properties(Lyfestyle PROPERTIES WIN32_EXECUTABLE TRUE)

target_link_libraries(tests PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Sql
)

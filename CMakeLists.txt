cmake_minimum_required(VERSION 3.16)
project(Lyfestyle VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# enable Qt’s moc, uic and rcc auto-generation
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

# list all your .cpp, .h and .ui files explicitly
set(SOURCES
    main.cpp
    LoginPage.cpp
    moodtracker.cpp
    journalwindow.cpp
    tasklistwindow.cpp
    User.cpp
    UserManager.cpp
    PasswordHasher.cpp
)

set(HEADERS
    LoginPage.h
    moodtracker.h
    journalwindow.h
    tasklistwindow.h
    User.h
    UserManager.h
    PasswordHasher.h
)

set(UIS
    LoginPage.ui
    moodtracker.ui
    journalwindow.ui
    tasklistwindow.ui
)

qt_add_executable(Lyfestyle
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

set_target_properties(Lyfestyle PROPERTIES WIN32_EXECUTABLE TRUE)

target_link_libraries(Lyfestyle
    PRIVATE
        Qt6::Widgets
        Qt6::Sql
)

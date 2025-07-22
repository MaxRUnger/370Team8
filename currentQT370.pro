QT += core
QT += core gui widgets
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

SOURCES += \
    LoginPage.cpp \
    main.cpp \
    User.cpp \
    UserManager.cpp \
    PasswordHasher.cpp

HEADERS += \
    LoginPage.h \
    User.h \
    UserManager.h \
    PasswordHasher.h

FORMS += \
    LoginPage.ui

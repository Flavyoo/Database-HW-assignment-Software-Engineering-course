TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp \
    database.cpp

HEADERS += \
    student.h \
    database.h \
    verify.h

DISTFILES += \
    example.txt \
    database.txt \
    README.txt

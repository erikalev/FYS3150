TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    solvers.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    vec3.cpp

HEADERS += \
    vec3.h \
    solvers.h \
    solarsystem.h \
    celestialbody.h


TEMPLATE = app

TARGET = Client

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -lole32 \
        -lcomctl32 \
        -luuid

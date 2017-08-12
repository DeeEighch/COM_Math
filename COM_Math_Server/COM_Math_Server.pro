TEMPLATE = lib

TARGET = server


DEF_FILE = server.def
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    components/math.cpp \
    mathclassfactory.cpp \
    server.cpp

HEADERS += \
    interfaces/imath.h \
    components/math.h \
    mathclassfactory.h

DISTFILES += \
    server.def \
    server.reg

LIBS += -lole32 \
        -lcomctl32 \
        -luuid

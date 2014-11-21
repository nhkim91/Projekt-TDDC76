TEMPLATE = app
#CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -m32 -std=c++11 -Wall -Wextra -pedantic
QMAKE_LFLAGS += -static-libgcc -static-libstdc++

LIBS += -L"C:\SDL2-2.0.3\i686-w64-mingw32\lib" -lmingw32 -lSDL2main -lSDL2
INCLUDEPATH += "C:\SDL2-2.0.3\i686-w64-mingw32\include"


SOURCES += \
    space_invader.cpp \
    help.cpp \
    highscore.cpp \
    flying_object.cpp \
    bullet.cpp \
    meteorite.cpp \
    main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    space_invader.h \
    help.h \
    highscore.h \
    flying_object.h \
    bullet.h \
    meteorite.h


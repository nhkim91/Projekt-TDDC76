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
    main.cpp \
    power_up.cpp \
    player.cpp \
    alien.cpp \
    level_1.cpp \
    level_2.cpp \
    slow_motion.cpp \
    attack_up.cpp \
    shield.cpp \
    life.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    space_invader.h \
    help.h \
    highscore.h \
    flying_object.h \
    bullet.h \
    meteorite.h \
    power_up.h \
    player.h \
    alien.h \
    level_1.h \
    level_2.h \
    slow_motion.h \
    attack_up.h \
    shield.h \
    life.h


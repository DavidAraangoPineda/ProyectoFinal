QT       += core gui \
          multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button.cpp \
    Cube.cpp \
    Game.cpp \
    Player.cpp \
    block.cpp \
    bullet.cpp \
    door.cpp \
    fall_block.cpp \
    main.cpp \
    resort.cpp \
    spikes.cpp

HEADERS += \
    Button.h \
    Cube.h \
    Game.h \
    Player.h \
    block.h \
    bullet.h \
    door.h \
    fall_block.h \
    resort.h \
    spikes.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc

DISTFILES += \
    sprites/blocks/brick_normal.png \
    sprites/fondos/fondo1.jpg

# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = TP4_VirtualWorld
QT       += core gui opengl
CONFIG += c++17
QMAKE_CFLAGS += -DENABLE_QT6=0

HEADERS = \
   $$PWD/VirtualWorld/controller.h \
   $$PWD/VirtualWorld/observer.h \
   $$PWD/VirtualWorld/shape.h \
   $$PWD/VirtualWorld/shapemanager.h \
   $$PWD/VirtualWorld/view.h \
   $$PWD/VirtualWorld/virtualworld.h

SOURCES = \
   $$PWD/VirtualWorld/controller.cpp \
   $$PWD/VirtualWorld/main.cpp \
   $$PWD/VirtualWorld/paintview.cpp \
   $$PWD/VirtualWorld/shapecircle.cpp \
   $$PWD/VirtualWorld/shapemanager.cpp \
   $$PWD/VirtualWorld/treeview.cpp \
   $$PWD/VirtualWorld/virtualworld.cpp

FORMS += \
    $$PWD/VirtualWorld/virtualworld.ui

RESOURCES += \
    $$PWD/VirtualWorld/virtualworld.qrc

INCLUDEPATH = \
    $$PWD/VirtualWorld

#DEFINES = 


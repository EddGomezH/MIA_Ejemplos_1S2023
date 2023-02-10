QT += core
QT -= gui

CONFIG += c++11

TARGET = Ejemplo3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    scanner.cpp \
    parser.cpp \
    nodo.cpp \
    comando.cpp \
    analizador.cpp

DISTFILES += \
    Ejemplo_Lenguaje_Reconocido.txt \
    Comandos_Bison.txt

HEADERS += \
    scanner.h \
    parser.h \
    nodo.h \
    comando.h \
    ASintactico.y \
    analizador.h \
    ALexico.l

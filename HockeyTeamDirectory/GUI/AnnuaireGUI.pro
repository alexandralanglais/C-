TEMPLATE = app
TARGET = AnnuaireGUI 

QT        += core gui 

HEADERS   += annuairegui.h
SOURCES   += main.cpp \
    annuairegui.cpp
FORMS     += annuairegui.ui    
RESOURCES +=
#LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."

#-------------------------------------------------
#
# Project created by QtCreator 2011-12-21T19:30:02
#
#-------------------------------------------------

QT       += core gui

TARGET = ImagePresenter
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    filemanager.cpp \
    startandhelpscreen.cpp \
    aboutbox.cpp

HEADERS  += widget.h \
    filemanager.h \
    startandhelpscreen.h \
    aboutbox.h

FORMS    += widget.ui \
    startandhelpscreen.ui \
    aboutbox.ui

OTHER_FILES += \
    ImagePresenter.rc

RESOURCES += \
    res.qrc
win32:RC_FILE = ImagePresenter.rc

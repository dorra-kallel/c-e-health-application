QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chambre.cpp \
    connection.cpp \
    machine.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    chambre.h \
    connection.h \
    machine.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    hadiiil.qrc \
    hadil.qrc \
    hadil.qrc \
    hadil.qrc \
    hadil1.qrc \
    hadil12.qrc \
    hadil23.qrc \
    hadilll.qrc \
    hh.qrc \
    hh.qrc

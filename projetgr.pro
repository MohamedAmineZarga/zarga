QT       += core gui multimedia sql printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    cadmin.cpp \
    client.cpp \
    connexion.cpp \
    equipements.cpp \
    gestiondereservation.cpp \
    gestiondessalles.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    report.cpp \
    reservation.cpp \
    salles.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    cadmin.h \
    client.h \
    connexion.h \
    equipements.h \
    gestiondereservation.h \
    gestiondessalles.h \
    mainwindow.h \
    menu.h \
    report.h \
    reservation.h \
    salles.h \
    smtp.h

FORMS += \
    gestiondereservation.ui \
    gestiondessalles.ui \
    mainwindow.ui \
    menu.ui \
    report.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    music.mp3 \
    music1.mp3 \
    projetgr.pro.user \
    welcome.mp3

RESOURCES += \
    images.qrc \
    img.qrc

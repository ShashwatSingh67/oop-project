QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutpage.cpp \
    botsoverview.cpp \
    homewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    market.cpp \
    stockgraph.cpp \
    usertrades.cpp

HEADERS += \
    aboutpage.h \
    botsoverview.h \
    homewindow.h \
    mainwindow.h \
    market.h \
    stockgraph.h \
    usertrades.h

FORMS += \
    aboutpage.ui \
    botsoverview.ui \
    homewindow.ui \
    mainwindow.ui \
    stockgraph.ui \
    usertrades.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

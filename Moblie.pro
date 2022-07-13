QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutus.cpp \
    delete_dialog.cpp \
    itemwidget.cpp \
    listnode.cpp \
    login.cpp \
    main.cpp \
    repertory.cpp \
    rigst.cpp \
    seller.cpp \
    sellselect.cpp \
    singlelist.cpp \
    stock.cpp \
    store.cpp \
    widget.cpp

HEADERS += \
    aboutus.h \
    delete_dialog.h \
    itemwidget.h \
    listnode.h \
    login.h \
    repertory.h \
    rigst.h \
    seller.h \
    sellselect.h \
    singlelist.h \
    stock.h \
    store.h \
    widget.h

FORMS += \
    aboutus.ui \
    delete_dialog.ui \
    itemwidget.ui \
    login.ui \
    repertory.ui \
    rigst.ui \
    seller.ui \
    sellselect.ui \
    stock.ui \
    store.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2019-01-17T11:53:44
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = urus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
INCLUDEPATH += ../include
if(!debug_and_release|build_pass) : CONFIG(debug,debug|release){
    LIBS            += -L$$PWD/lib/debug/ -lcares
    PRE_TARGETDEPS  += $$PWD/lib/debug/cares.lib

    LIBS            += -L$$PWD/lib/debug/ -laddress_sorting
    PRE_TARGETDEPS  += $$PWD/lib/debug/address_sorting.lib
    LIBS            += -L$$PWD/lib/debug/ -lgpr
    PRE_TARGETDEPS  += $$PWD/lib/debug/gpr.lib
    LIBS            += -L$$PWD/lib/debug/ -lgrpc
    PRE_TARGETDEPS  += $$PWD/lib/debug/grpc.lib
    LIBS            += -L$$PWD/lib/debug/ -lgrpc++
    PRE_TARGETDEPS  += $$PWD/lib/debug/grpc++.lib
    LIBS            += -L$$PWD/lib/debug/ -llibprotobufd
    PRE_TARGETDEPS  += $$PWD/lib/debug/libprotobufd.lib
    LIBS            += -L$$PWD/lib/debug/ -lssl
    PRE_TARGETDEPS  += $$PWD/lib/debug/ssl.lib
    LIBS            += -L$$PWD/lib/debug/ -lcrypto
    PRE_TARGETDEPS  += $$PWD/lib/debug/crypto.lib
    LIBS            += -L$$PWD/lib/debug/ -ldecrepit
    PRE_TARGETDEPS  += $$PWD/lib/debug/decrepit.lib
    LIBS            += -L$$PWD/lib/debug/ -lzlibstaticd
    PRE_TARGETDEPS  += $$PWD/lib/debug/zlibstaticd.lib
} else {
    LIBS            += -L$$PWD/lib/release/ -lcares
    PRE_TARGETDEPS  += $$PWD/lib/release/cares.lib

    LIBS            += -L$$PWD/lib/release/ -laddress_sorting
    PRE_TARGETDEPS  += $$PWD/lib/release/address_sorting.lib
    LIBS            += -L$$PWD/lib/release/ -lgpr
    PRE_TARGETDEPS  += $$PWD/lib/release/gpr.lib
    LIBS            += -L$$PWD/lib/release/ -lgrpc
    PRE_TARGETDEPS  += $$PWD/lib/release/grpc.lib
    LIBS            += -L$$PWD/lib/release/ -lgrpc++
    PRE_TARGETDEPS  += $$PWD/lib/release/grpc++.lib
    LIBS            += -L$$PWD/lib/release/ -llibprotobuf
    PRE_TARGETDEPS  += $$PWD/lib/release/libprotobuf.lib
    LIBS            += -L$$PWD/lib/release/ -lssl
    PRE_TARGETDEPS  += $$PWD/lib/release/ssl.lib
    LIBS            += -L$$PWD/lib/release/ -lcrypto
    PRE_TARGETDEPS  += $$PWD/lib/release/crypto.lib
    LIBS            += -L$$PWD/lib/release/ -ldecrepit
    PRE_TARGETDEPS  += $$PWD/lib/release/decrepit.lib
    LIBS            += -L$$PWD/lib/release/ -lzlibstatic
    PRE_TARGETDEPS  += $$PWD/lib/release/zlibstatic.lib
}

DEFINES += _WIN32_WINNT=0x600

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    accountdialog.cpp \
    example.pb.cc

HEADERS += \
        mainwindow.h \
    commheader.h \
    globalconst.h \
    accountdialog.h \
    urusspace.h \
    example.pb.h

FORMS +=




RC_FILE += images/icon.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/logo.ico \
    images/logo.png \
    qss/scrollbar.qss \
    proto/example.proto \
    lib/release/cares.lib

RESOURCES += \
    res.qrc


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


CONFIG(debug,debug|release){#debug

    macx:{
        LIBS    += -L"$$PWD/third_party_lib/lib/macOS" \
                -lprotobufd \
                -lgmappingd
    }
}

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

macx {
    # mac only
    ICON = nbs.icns
}

unix:!macx{
    #linux only

}

win32 {
    #windows only
    RC_ICONS = images/logo.ico
}

DISTFILES += \
    images/logo.ico \
    images/logo.png \
    qss/scrollbar.qss \
    proto/example.proto \

RESOURCES += \
    res.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/thirdparty/lib/release/ -lprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/thirdparty/lib/debug/ -lprotobuf
else:macx: LIBS += -L$$PWD/thirdparty/lib/ -lprotobuf

INCLUDEPATH += $$PWD/thirdparty
DEPENDPATH += $$PWD/thirdparty

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/thirdparty/lib/release/libprotobuf.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/thirdparty/lib/debug/libprotobuf.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/thirdparty/lib/release/protobuf.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/thirdparty/lib/debug/protobuf.lib
else:macx: PRE_TARGETDEPS += $$PWD/thirdparty/lib/libprotobuf.a

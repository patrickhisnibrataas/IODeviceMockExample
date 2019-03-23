QT += testlib
CONFIG += qt console warn_on depend_includepath testcase c++17

TEMPLATE = app

SOURCES += \
    tst_example.cpp

HEADERS += \
    mockdevice.h \
    controller.h \
    app.h

INCLUDEPATH += $$PWD/../qtmockexamples

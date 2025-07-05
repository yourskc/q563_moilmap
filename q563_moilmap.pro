#-------------------------------------------------
#
# Project created by QtCreator 2025-06-24T21:29:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = q563_moilmap
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp

win32 {
INCLUDEPATH += $$(OPENCV_SDK_DIR)/include
LIBS += -L$$PWD
LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
        -lopencv_core320        \
        -lopencv_highgui320     \
        -lopencv_imgcodecs320   \
        -lopencv_imgproc320     \
        -lopencv_videoio320
}

unix {
# message ($$CONFIG)

contains(CONFIG, cross_compile):{
message ("cross compile")
INCLUDEPATH += $$(PKG_CONFIG_SYSROOT_DIR)/usr/include/opencv4
LIBS += -L$$(PKG_CONFIG_SYSROOT_DIR)/usr/lib64/
LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_imgcodecs \
        -lopencv_videoio
}
else {
message ("non cross compile")
INCLUDEPATH += /usr/include/opencv4
# INCLUDEPATH += /usr/local/include/opencv4
# Set Qt Library location according to the actual situation
# LIBS += -L/usr/lib/x86_64-linux-gnu
# Qt 5.6.3
LIBS += -L~/Qt5.6.3/5.6.3/gcc_64/lib
LIBS += -L/usr/local/lib \
        -L/usr/lib \
        -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_imgcodecs \
        -lopencv_videoio
}
}

HEADERS  += mainwindow.h \
    moilmaploader.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc


# Copy images folder from source to build folder
copydata.commands = $(COPY_DIR) $$PWD/images $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

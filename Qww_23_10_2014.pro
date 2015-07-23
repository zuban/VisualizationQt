#-------------------------------------------------
#
# Project created by QtCreator 2014-10-23T20:34:16
#
#-------------------------------------------------

QT       += core gui
INCLUDEPATH += C:\Qwt-6.0.1\include
LIBS += C:\Qwt-6.0.1\lib\libqwtd.a
LIBS += -lcuda_dll
TARGET = Qww_23_10_2014
TEMPLATE = app
LIBS += -L"C:\QtProjects\VS projects_folder\shared_folder"
INCLUDEPATH += "C:\QtProjects\VS projects_folder\shared_folder"
#INCLUDEPATH += "C:\QtProjects\H5dist\1.8.14\include"
SOURCES += main.cpp\
        mainwindow.cpp \
    zvector.cpp \
    zgraph.cpp \
    widget.cpp \
    scrollzoomer.cpp \
    scrollbar.cpp \
    qtlegend.cpp \
    myqwtplot.cpp \
    mymarker.cpp \
    form.cpp \
    z2vector.cpp \
    spectro_plot.cpp \
    spectro_draw.cpp \
    photoclass.cpp \
    spectrwidget.cpp \
    form_spectr.cpp \
    w_wlib.cpp \
    iodata.cpp \
    zcomplex.cpp

HEADERS  += mainwindow.h \
    zvector.h \
    zgraph.h \
    widget.h \
    ui_widget.h \
    scrollzoomer.h \
    scrollbar.h \
    qtlegend.h \
    myqwtplot.h \
    mymarker.h \
    form.h \
    z2vector.h \
    spectro_plot.h \
    spectro_draw.h \
    photoclass.h \
    ui_spectrwidget.h \
    spectrwidget.h \
    form_spectr.h \
    w_wlib.h \
    iodata.h \
    colormap.h \
    coloralphamap.h \
    rasterdata.h \
    zcomplex.h

FORMS    += mainwindow.ui \
    widget.ui \
    form.ui \
    spectrwidget.ui \
    form_spectr.ui

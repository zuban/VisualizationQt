/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 14. Jul 17:47:30 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "form.h"
#include "form_spectr.h"
#include "spectrwidget.h"
#include "widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_2;
    SpectrWidget *widget_spectr;
    QSplitter *splitter;
    Widget *widget_2D;
    QTabWidget *widget_tab_control;
    QWidget *tab;
    QGridLayout *gridLayout;
    Form *widget_contr_2D;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    Form_Spectr *widget_spectr_contr;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1261, 505);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        widget_spectr = new SpectrWidget(splitter_2);
        widget_spectr->setObjectName(QString::fromUtf8("widget_spectr"));
        splitter_2->addWidget(widget_spectr);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widget_2D = new Widget(splitter);
        widget_2D->setObjectName(QString::fromUtf8("widget_2D"));
        splitter->addWidget(widget_2D);
        widget_tab_control = new QTabWidget(splitter);
        widget_tab_control->setObjectName(QString::fromUtf8("widget_tab_control"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        widget_tab_control->setPalette(palette);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_contr_2D = new Form(tab);
        widget_contr_2D->setObjectName(QString::fromUtf8("widget_contr_2D"));

        gridLayout->addWidget(widget_contr_2D, 0, 0, 1, 1);

        widget_tab_control->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_spectr_contr = new Form_Spectr(tab_2);
        widget_spectr_contr->setObjectName(QString::fromUtf8("widget_spectr_contr"));

        gridLayout_2->addWidget(widget_spectr_contr, 0, 0, 1, 1);

        widget_tab_control->addTab(tab_2, QString());
        splitter->addWidget(widget_tab_control);
        splitter_2->addWidget(splitter);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1261, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        widget_tab_control->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        widget_tab_control->setTabText(widget_tab_control->indexOf(tab), QApplication::translate("MainWindow", "2D Control", 0, QApplication::UnicodeUTF8));
        widget_tab_control->setTabText(widget_tab_control->indexOf(tab_2), QApplication::translate("MainWindow", "Spectr Control", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

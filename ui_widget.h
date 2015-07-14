/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue 14. Jul 17:47:30 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *ampl_groupBox;
    QComboBox *ampl_span_comboBox;
    QLabel *label_6;
    QComboBox *ampl_max_comboBox;
    QLabel *label_7;
    QRadioButton *ampl_autoscale_radioButton;
    QRadioButton *ampl_manual_radioButton;
    QRadioButton *ampl_up_radioButton;
    QWidget *page_2;
    QGroupBox *phase_groupBox;
    QRadioButton *phase_autoscale_radioButton;
    QRadioButton *phase_manual_radioButton;
    QRadioButton *phase_up_radioButton;
    QLabel *label_10;
    QComboBox *phase_center_comboBox;
    QLabel *label_11;
    QComboBox *phase_span_comboBox;
    QWidget *page_3;
    QGroupBox *real_groupBox;
    QComboBox *real_span_comboBox;
    QLabel *label_20;
    QComboBox *real_center_comboBox;
    QLabel *label_21;
    QRadioButton *real_autoscale_radioButton;
    QRadioButton *real_manual_radioButton;
    QRadioButton *real_up_radioButton;
    QWidget *page_4;
    QGroupBox *imag_groupBox;
    QComboBox *imag_span_comboBox;
    QLabel *label_8;
    QComboBox *imag_center_comboBox;
    QLabel *label_9;
    QRadioButton *imag_autoscale_radioButton;
    QRadioButton *imag_manual_radioButton;
    QRadioButton *imag_up_radioButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *XY_scale_pushButton;
    QPushButton *X_scale_pushButton;
    QPushButton *Y_scale_pushButton;
    QPushButton *magnifier_pushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *add_marker_pushButton;
    QPushButton *delete_marker_pushButton;
    QPushButton *reference_marker_pushButton;
    QPushButton *show_marker_pushButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QComboBox *graph_type_comboBox;
    QComboBox *graph_lin_log_type_comboBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QComboBox *graph_color_comboBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QComboBox *graph_style_comboBox;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QSpinBox *graph_wight_spinBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1354, 693);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(-1, -1, 9, -1);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 240));
        stackedWidget->setMaximumSize(QSize(100, 16777215));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        ampl_groupBox = new QGroupBox(page);
        ampl_groupBox->setObjectName(QString::fromUtf8("ampl_groupBox"));
        ampl_groupBox->setGeometry(QRect(10, 10, 81, 211));
        ampl_groupBox->setMinimumSize(QSize(60, 200));
        ampl_groupBox->setMaximumSize(QSize(200, 16777215));
        ampl_groupBox->setFlat(false);
        ampl_span_comboBox = new QComboBox(ampl_groupBox);
        ampl_span_comboBox->setObjectName(QString::fromUtf8("ampl_span_comboBox"));
        ampl_span_comboBox->setGeometry(QRect(10, 90, 71, 21));
        ampl_span_comboBox->setEditable(true);
        label_6 = new QLabel(ampl_groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 70, 46, 13));
        label_6->setFrameShape(QFrame::NoFrame);
        ampl_max_comboBox = new QComboBox(ampl_groupBox);
        ampl_max_comboBox->setObjectName(QString::fromUtf8("ampl_max_comboBox"));
        ampl_max_comboBox->setGeometry(QRect(10, 40, 71, 21));
        ampl_max_comboBox->setEditable(true);
        label_7 = new QLabel(ampl_groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 20, 61, 20));
        ampl_autoscale_radioButton = new QRadioButton(ampl_groupBox);
        ampl_autoscale_radioButton->setObjectName(QString::fromUtf8("ampl_autoscale_radioButton"));
        ampl_autoscale_radioButton->setGeometry(QRect(10, 120, 71, 17));
        ampl_autoscale_radioButton->setChecked(true);
        ampl_manual_radioButton = new QRadioButton(ampl_groupBox);
        ampl_manual_radioButton->setObjectName(QString::fromUtf8("ampl_manual_radioButton"));
        ampl_manual_radioButton->setGeometry(QRect(10, 150, 61, 17));
        ampl_up_radioButton = new QRadioButton(ampl_groupBox);
        ampl_up_radioButton->setObjectName(QString::fromUtf8("ampl_up_radioButton"));
        ampl_up_radioButton->setGeometry(QRect(10, 180, 61, 17));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        phase_groupBox = new QGroupBox(page_2);
        phase_groupBox->setObjectName(QString::fromUtf8("phase_groupBox"));
        phase_groupBox->setGeometry(QRect(10, 10, 91, 211));
        phase_groupBox->setFlat(false);
        phase_autoscale_radioButton = new QRadioButton(phase_groupBox);
        phase_autoscale_radioButton->setObjectName(QString::fromUtf8("phase_autoscale_radioButton"));
        phase_autoscale_radioButton->setGeometry(QRect(10, 120, 71, 17));
        phase_autoscale_radioButton->setChecked(true);
        phase_manual_radioButton = new QRadioButton(phase_groupBox);
        phase_manual_radioButton->setObjectName(QString::fromUtf8("phase_manual_radioButton"));
        phase_manual_radioButton->setGeometry(QRect(10, 150, 61, 17));
        phase_up_radioButton = new QRadioButton(phase_groupBox);
        phase_up_radioButton->setObjectName(QString::fromUtf8("phase_up_radioButton"));
        phase_up_radioButton->setGeometry(QRect(10, 180, 61, 17));
        label_10 = new QLabel(phase_groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 20, 61, 20));
        phase_center_comboBox = new QComboBox(phase_groupBox);
        phase_center_comboBox->setObjectName(QString::fromUtf8("phase_center_comboBox"));
        phase_center_comboBox->setGeometry(QRect(10, 40, 71, 21));
        phase_center_comboBox->setEditable(true);
        label_11 = new QLabel(phase_groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 70, 46, 13));
        label_11->setFrameShape(QFrame::NoFrame);
        phase_span_comboBox = new QComboBox(phase_groupBox);
        phase_span_comboBox->setObjectName(QString::fromUtf8("phase_span_comboBox"));
        phase_span_comboBox->setGeometry(QRect(10, 90, 71, 21));
        phase_span_comboBox->setEditable(true);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        real_groupBox = new QGroupBox(page_3);
        real_groupBox->setObjectName(QString::fromUtf8("real_groupBox"));
        real_groupBox->setGeometry(QRect(10, 10, 91, 211));
        real_groupBox->setFlat(false);
        real_span_comboBox = new QComboBox(real_groupBox);
        real_span_comboBox->setObjectName(QString::fromUtf8("real_span_comboBox"));
        real_span_comboBox->setGeometry(QRect(10, 90, 71, 21));
        real_span_comboBox->setEditable(true);
        label_20 = new QLabel(real_groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 70, 46, 13));
        label_20->setFrameShape(QFrame::NoFrame);
        real_center_comboBox = new QComboBox(real_groupBox);
        real_center_comboBox->setObjectName(QString::fromUtf8("real_center_comboBox"));
        real_center_comboBox->setGeometry(QRect(10, 40, 71, 21));
        real_center_comboBox->setEditable(true);
        label_21 = new QLabel(real_groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(30, 20, 61, 20));
        real_autoscale_radioButton = new QRadioButton(real_groupBox);
        real_autoscale_radioButton->setObjectName(QString::fromUtf8("real_autoscale_radioButton"));
        real_autoscale_radioButton->setGeometry(QRect(10, 120, 71, 17));
        real_autoscale_radioButton->setChecked(true);
        real_manual_radioButton = new QRadioButton(real_groupBox);
        real_manual_radioButton->setObjectName(QString::fromUtf8("real_manual_radioButton"));
        real_manual_radioButton->setGeometry(QRect(10, 150, 61, 17));
        real_up_radioButton = new QRadioButton(real_groupBox);
        real_up_radioButton->setObjectName(QString::fromUtf8("real_up_radioButton"));
        real_up_radioButton->setGeometry(QRect(10, 180, 61, 17));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        imag_groupBox = new QGroupBox(page_4);
        imag_groupBox->setObjectName(QString::fromUtf8("imag_groupBox"));
        imag_groupBox->setGeometry(QRect(10, 10, 91, 201));
        imag_groupBox->setFlat(false);
        imag_span_comboBox = new QComboBox(imag_groupBox);
        imag_span_comboBox->setObjectName(QString::fromUtf8("imag_span_comboBox"));
        imag_span_comboBox->setGeometry(QRect(10, 90, 71, 21));
        imag_span_comboBox->setEditable(true);
        label_8 = new QLabel(imag_groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 70, 46, 13));
        label_8->setFrameShape(QFrame::NoFrame);
        imag_center_comboBox = new QComboBox(imag_groupBox);
        imag_center_comboBox->setObjectName(QString::fromUtf8("imag_center_comboBox"));
        imag_center_comboBox->setGeometry(QRect(10, 40, 71, 21));
        imag_center_comboBox->setEditable(true);
        label_9 = new QLabel(imag_groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 20, 61, 20));
        imag_autoscale_radioButton = new QRadioButton(imag_groupBox);
        imag_autoscale_radioButton->setObjectName(QString::fromUtf8("imag_autoscale_radioButton"));
        imag_autoscale_radioButton->setGeometry(QRect(10, 120, 71, 17));
        imag_autoscale_radioButton->setChecked(true);
        imag_manual_radioButton = new QRadioButton(imag_groupBox);
        imag_manual_radioButton->setObjectName(QString::fromUtf8("imag_manual_radioButton"));
        imag_manual_radioButton->setGeometry(QRect(10, 150, 61, 17));
        imag_up_radioButton = new QRadioButton(imag_groupBox);
        imag_up_radioButton->setObjectName(QString::fromUtf8("imag_up_radioButton"));
        imag_up_radioButton->setGeometry(QRect(10, 180, 61, 17));
        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        XY_scale_pushButton = new QPushButton(Widget);
        XY_scale_pushButton->setObjectName(QString::fromUtf8("XY_scale_pushButton"));
        XY_scale_pushButton->setMinimumSize(QSize(40, 45));
        XY_scale_pushButton->setMaximumSize(QSize(70, 16777215));
        XY_scale_pushButton->setCheckable(true);

        verticalLayout->addWidget(XY_scale_pushButton);

        X_scale_pushButton = new QPushButton(Widget);
        X_scale_pushButton->setObjectName(QString::fromUtf8("X_scale_pushButton"));
        X_scale_pushButton->setMinimumSize(QSize(40, 45));
        X_scale_pushButton->setMaximumSize(QSize(70, 16777215));
        X_scale_pushButton->setCheckable(true);

        verticalLayout->addWidget(X_scale_pushButton);

        Y_scale_pushButton = new QPushButton(Widget);
        Y_scale_pushButton->setObjectName(QString::fromUtf8("Y_scale_pushButton"));
        Y_scale_pushButton->setMinimumSize(QSize(40, 45));
        Y_scale_pushButton->setMaximumSize(QSize(70, 16777215));
        Y_scale_pushButton->setCheckable(true);

        verticalLayout->addWidget(Y_scale_pushButton);

        magnifier_pushButton = new QPushButton(Widget);
        magnifier_pushButton->setObjectName(QString::fromUtf8("magnifier_pushButton"));
        magnifier_pushButton->setMinimumSize(QSize(40, 45));
        magnifier_pushButton->setMaximumSize(QSize(70, 16777215));
        magnifier_pushButton->setCheckable(true);

        verticalLayout->addWidget(magnifier_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        add_marker_pushButton = new QPushButton(Widget);
        add_marker_pushButton->setObjectName(QString::fromUtf8("add_marker_pushButton"));
        add_marker_pushButton->setMinimumSize(QSize(40, 45));

        horizontalLayout->addWidget(add_marker_pushButton);

        delete_marker_pushButton = new QPushButton(Widget);
        delete_marker_pushButton->setObjectName(QString::fromUtf8("delete_marker_pushButton"));
        delete_marker_pushButton->setMinimumSize(QSize(40, 45));

        horizontalLayout->addWidget(delete_marker_pushButton);

        reference_marker_pushButton = new QPushButton(Widget);
        reference_marker_pushButton->setObjectName(QString::fromUtf8("reference_marker_pushButton"));
        reference_marker_pushButton->setMinimumSize(QSize(40, 45));
        reference_marker_pushButton->setCheckable(true);

        horizontalLayout->addWidget(reference_marker_pushButton);

        show_marker_pushButton = new QPushButton(Widget);
        show_marker_pushButton->setObjectName(QString::fromUtf8("show_marker_pushButton"));
        show_marker_pushButton->setMinimumSize(QSize(40, 45));

        horizontalLayout->addWidget(show_marker_pushButton);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 13));

        verticalLayout_3->addWidget(label_2);

        graph_type_comboBox = new QComboBox(Widget);
        graph_type_comboBox->setObjectName(QString::fromUtf8("graph_type_comboBox"));
        graph_type_comboBox->setMinimumSize(QSize(40, 27));

        verticalLayout_3->addWidget(graph_type_comboBox);


        horizontalLayout->addLayout(verticalLayout_3);

        graph_lin_log_type_comboBox = new QComboBox(Widget);
        graph_lin_log_type_comboBox->setObjectName(QString::fromUtf8("graph_lin_log_type_comboBox"));
        graph_lin_log_type_comboBox->setMinimumSize(QSize(40, 45));

        horizontalLayout->addWidget(graph_lin_log_type_comboBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 13));

        verticalLayout_4->addWidget(label_3);

        graph_color_comboBox = new QComboBox(Widget);
        graph_color_comboBox->setObjectName(QString::fromUtf8("graph_color_comboBox"));
        graph_color_comboBox->setMinimumSize(QSize(40, 27));

        verticalLayout_4->addWidget(graph_color_comboBox);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 13));

        verticalLayout_5->addWidget(label_4);

        graph_style_comboBox = new QComboBox(Widget);
        graph_style_comboBox->setObjectName(QString::fromUtf8("graph_style_comboBox"));
        graph_style_comboBox->setMinimumSize(QSize(40, 27));

        verticalLayout_5->addWidget(graph_style_comboBox);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 13));

        verticalLayout_6->addWidget(label_5);

        graph_wight_spinBox = new QSpinBox(Widget);
        graph_wight_spinBox->setObjectName(QString::fromUtf8("graph_wight_spinBox"));
        graph_wight_spinBox->setMinimum(1);
        graph_wight_spinBox->setMaximum(25);
        graph_wight_spinBox->setSingleStep(1);

        verticalLayout_6->addWidget(graph_wight_spinBox);


        horizontalLayout->addLayout(verticalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        ampl_groupBox->setTitle(QApplication::translate("Widget", "Ampl", 0, QApplication::UnicodeUTF8));
        ampl_span_comboBox->clear();
        ampl_span_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "120", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "130", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("Widget", "Span", 0, QApplication::UnicodeUTF8));
        ampl_max_comboBox->clear();
        ampl_max_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-120", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("Widget", "Max", 0, QApplication::UnicodeUTF8));
        ampl_autoscale_radioButton->setText(QApplication::translate("Widget", "Autoscale", 0, QApplication::UnicodeUTF8));
        ampl_manual_radioButton->setText(QApplication::translate("Widget", "Manual", 0, QApplication::UnicodeUTF8));
        ampl_up_radioButton->setText(QApplication::translate("Widget", "Up", 0, QApplication::UnicodeUTF8));
        phase_groupBox->setTitle(QApplication::translate("Widget", "Phase", 0, QApplication::UnicodeUTF8));
        phase_autoscale_radioButton->setText(QApplication::translate("Widget", "Autoscale", 0, QApplication::UnicodeUTF8));
        phase_manual_radioButton->setText(QApplication::translate("Widget", "Manual", 0, QApplication::UnicodeUTF8));
        phase_up_radioButton->setText(QApplication::translate("Widget", "Up", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "Center", 0, QApplication::UnicodeUTF8));
        phase_center_comboBox->clear();
        phase_center_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "-360", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-180", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "180", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "360", 0, QApplication::UnicodeUTF8)
        );
        label_11->setText(QApplication::translate("Widget", "Span", 0, QApplication::UnicodeUTF8));
        phase_span_comboBox->clear();
        phase_span_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "180", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "360", 0, QApplication::UnicodeUTF8)
        );
        real_groupBox->setTitle(QApplication::translate("Widget", "Real", 0, QApplication::UnicodeUTF8));
        real_span_comboBox->clear();
        real_span_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "120", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "130", 0, QApplication::UnicodeUTF8)
        );
        label_20->setText(QApplication::translate("Widget", "Span", 0, QApplication::UnicodeUTF8));
        real_center_comboBox->clear();
        real_center_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-120", 0, QApplication::UnicodeUTF8)
        );
        label_21->setText(QApplication::translate("Widget", "Center", 0, QApplication::UnicodeUTF8));
        real_autoscale_radioButton->setText(QApplication::translate("Widget", "Autoscale", 0, QApplication::UnicodeUTF8));
        real_manual_radioButton->setText(QApplication::translate("Widget", "Manual", 0, QApplication::UnicodeUTF8));
        real_up_radioButton->setText(QApplication::translate("Widget", "Up", 0, QApplication::UnicodeUTF8));
        imag_groupBox->setTitle(QApplication::translate("Widget", "Imag", 0, QApplication::UnicodeUTF8));
        imag_span_comboBox->clear();
        imag_span_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "120", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "130", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("Widget", "Span", 0, QApplication::UnicodeUTF8));
        imag_center_comboBox->clear();
        imag_center_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-110", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "-120", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("Widget", "Center", 0, QApplication::UnicodeUTF8));
        imag_autoscale_radioButton->setText(QApplication::translate("Widget", "Autoscale", 0, QApplication::UnicodeUTF8));
        imag_manual_radioButton->setText(QApplication::translate("Widget", "Manual", 0, QApplication::UnicodeUTF8));
        imag_up_radioButton->setText(QApplication::translate("Widget", "Up", 0, QApplication::UnicodeUTF8));
        XY_scale_pushButton->setText(QApplication::translate("Widget", "XY Scale", 0, QApplication::UnicodeUTF8));
        X_scale_pushButton->setText(QApplication::translate("Widget", "X YScale", 0, QApplication::UnicodeUTF8));
        Y_scale_pushButton->setText(QApplication::translate("Widget", "Y Scale", 0, QApplication::UnicodeUTF8));
        magnifier_pushButton->setText(QApplication::translate("Widget", "Magnifier", 0, QApplication::UnicodeUTF8));
        add_marker_pushButton->setText(QApplication::translate("Widget", "Add Marker", 0, QApplication::UnicodeUTF8));
        delete_marker_pushButton->setText(QApplication::translate("Widget", "Delete Marker", 0, QApplication::UnicodeUTF8));
        reference_marker_pushButton->setText(QApplication::translate("Widget", "Ref Marker", 0, QApplication::UnicodeUTF8));
        show_marker_pushButton->setText(QApplication::translate("Widget", "Show Marker", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Graph type</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        graph_type_comboBox->clear();
        graph_type_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Amplitude", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Phase", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Imag", 0, QApplication::UnicodeUTF8)
        );
        graph_lin_log_type_comboBox->clear();
        graph_lin_log_type_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Log", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Lin", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Graph color</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        graph_color_comboBox->clear();
        graph_color_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkCyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkRed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "magenta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkMagenta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkGreen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkYellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkBlue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "gray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "darkGray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "lightGray", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Graph style</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        graph_style_comboBox->clear();
        graph_style_comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "SolidLine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "DashLine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "DotLine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "DashDotLine", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "DashDotDotLine", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Graph wight</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

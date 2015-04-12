/********************************************************************************
** Form generated from reading UI file 'swidget.ui'
**
** Created: Fri 31. Oct 23:22:16 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWIDGET_H
#define UI_SWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QProgressBar *progressBar;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *read_pushbutton;
    QComboBox *type_combobox;
    QComboBox *spec_type_combobox;
    QSpacerItem *horizontalSpacer;
    QPushButton *rect_pushButton;
    QPushButton *polygon_pushButton;
    QPushButton *line_pushButton;
    QComboBox *color_comboBox;
    QCheckBox *sketch_checkBox;
    QPushButton *zoom_pushButton;
    QPushButton *select_point_pushButton;
    QPushButton *cont_read_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *delete_last_pushButton;
    QPushButton *delete_sketch_pushButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpinBox *max_spinbox;
    QDoubleSpinBox *min_spinbox;
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *scale_checkBox;
    QCheckBox *flip_checkBox;
    QGridLayout *gridLayout_4;
    QLineEdit *x_y_scale_lineedit1;
    QLineEdit *x_y_scale_lineedit2;
    QLabel *x_y_scale_label;
    QPushButton *x_y_scale_pushButton;
    QLabel *label_7;
    QPushButton *ok_x_y_scale_pushButton;
    QPushButton *x_y_scale_pushButton_2;
    QGridLayout *gridLayout_5;
    QLineEdit *angle_lineedit1;
    QLineEdit *angle_lineedit2;
    QLabel *angle_label;
    QPushButton *angle_pushbutton;
    QLabel *label_8;
    QPushButton *ok_angle_pushbutton;
    QPushButton *angle_pushbutton_2;
    QGridLayout *gridLayout_6;
    QLineEdit *x_shift_lineedit1;
    QLineEdit *x_shift_lineedit2;
    QLabel *angle_label_2;
    QPushButton *x_y_shitft_pushButton;
    QLabel *label_9;
    QLineEdit *y_shift_lineedit1;
    QLineEdit *y_shift_lineedit2;
    QPushButton *ok_x_y_shift_pushButton;
    QPushButton *x_y_shitft_pushButton_2;
    QGridLayout *gridLayout_3;
    QLabel *x_shift_label;
    QLineEdit *x_shift_lineEdit;
    QLabel *y_shift_label;
    QLineEdit *y_shift_lineEdit;
    QLabel *x_scale_label;
    QLineEdit *x_scale_lineEdit;
    QLabel *y_scale_label;
    QLineEdit *y_scale_lineEdit;
    QLabel *k_label;
    QLineEdit *k_lineEdit;
    QLabel *fi_label;
    QLineEdit *fi_lineEdit;
    QSlider *fi_shift_slider;
    QLabel *fi_shift_label;
    QWidget *tab_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *photo_enable_checkBox;
    QGridLayout *gridLayout_7;
    QLineEdit *photo_x_y_scale_lineedit1;
    QLineEdit *photo_x_y_scale_lineedit2;
    QLabel *x_y_scale_label_2;
    QPushButton *photo_x_y_scale_pushButton;
    QLabel *label_10;
    QPushButton *photo_ok_x_y_scale_pushButton;
    QPushButton *photo_x_y_scale_pushButton_2;
    QGridLayout *gridLayout_8;
    QLineEdit *photo_angle_lineedit1;
    QLineEdit *photo_angle_lineedit2;
    QLabel *angle_label_3;
    QPushButton *photo_angle_pushbutton;
    QLabel *label_11;
    QPushButton *photo_ok_angle_pushbutton;
    QPushButton *photo_angle_pushbutton_2;
    QGridLayout *gridLayout_9;
    QLineEdit *photo_x_shift_lineedit1;
    QLineEdit *photo_x_shift_lineedit2;
    QLabel *angle_label_4;
    QPushButton *photo_x_y_shitft_pushButton;
    QLabel *label_12;
    QLineEdit *photo_y_shift_lineedit1;
    QLineEdit *photo_y_shift_lineedit2;
    QPushButton *photo_ok_x_y_shift_pushButton;
    QPushButton *photo_x_y_shitft_pushButton_2;
    QGridLayout *gridLayout_10;
    QLabel *x_shift_label_2;
    QLineEdit *photo_x_shift_lineEdit;
    QLabel *y_shift_label_2;
    QLineEdit *photo_y_shift_lineEdit;
    QLabel *x_scale_label_2;
    QLineEdit *photo_x_scale_lineEdit;
    QLabel *y_scale_label_2;
    QLineEdit *photo_y_scale_lineEdit;
    QLabel *k_label_2;
    QLineEdit *photo_k_lineEdit;
    QLabel *fi_label_2;
    QLineEdit *photo_fi_lineEdit;
    QLabel *fi_shift_label_2;
    QSlider *photo_fi_shift_slider;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1931, 1146);
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 1120, 1441, 23));
        progressBar->setValue(24);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1901, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        read_pushbutton = new QPushButton(layoutWidget);
        read_pushbutton->setObjectName(QString::fromUtf8("read_pushbutton"));
        read_pushbutton->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(read_pushbutton);

        type_combobox = new QComboBox(layoutWidget);
        type_combobox->setObjectName(QString::fromUtf8("type_combobox"));
        type_combobox->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(type_combobox);

        spec_type_combobox = new QComboBox(layoutWidget);
        spec_type_combobox->setObjectName(QString::fromUtf8("spec_type_combobox"));
        spec_type_combobox->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(spec_type_combobox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rect_pushButton = new QPushButton(layoutWidget);
        rect_pushButton->setObjectName(QString::fromUtf8("rect_pushButton"));
        rect_pushButton->setMinimumSize(QSize(100, 30));
        rect_pushButton->setCheckable(true);

        horizontalLayout->addWidget(rect_pushButton);

        polygon_pushButton = new QPushButton(layoutWidget);
        polygon_pushButton->setObjectName(QString::fromUtf8("polygon_pushButton"));
        polygon_pushButton->setMinimumSize(QSize(100, 30));
        polygon_pushButton->setCheckable(true);

        horizontalLayout->addWidget(polygon_pushButton);

        line_pushButton = new QPushButton(layoutWidget);
        line_pushButton->setObjectName(QString::fromUtf8("line_pushButton"));
        line_pushButton->setMinimumSize(QSize(100, 30));
        line_pushButton->setCheckable(true);

        horizontalLayout->addWidget(line_pushButton);

        color_comboBox = new QComboBox(layoutWidget);
        color_comboBox->setObjectName(QString::fromUtf8("color_comboBox"));
        color_comboBox->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(color_comboBox);

        sketch_checkBox = new QCheckBox(layoutWidget);
        sketch_checkBox->setObjectName(QString::fromUtf8("sketch_checkBox"));
        sketch_checkBox->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(sketch_checkBox);

        zoom_pushButton = new QPushButton(layoutWidget);
        zoom_pushButton->setObjectName(QString::fromUtf8("zoom_pushButton"));
        zoom_pushButton->setMinimumSize(QSize(100, 30));
        zoom_pushButton->setCheckable(true);

        horizontalLayout->addWidget(zoom_pushButton);

        select_point_pushButton = new QPushButton(layoutWidget);
        select_point_pushButton->setObjectName(QString::fromUtf8("select_point_pushButton"));
        select_point_pushButton->setMinimumSize(QSize(100, 30));
        select_point_pushButton->setCheckable(true);

        horizontalLayout->addWidget(select_point_pushButton);

        cont_read_pushButton = new QPushButton(layoutWidget);
        cont_read_pushButton->setObjectName(QString::fromUtf8("cont_read_pushButton"));
        cont_read_pushButton->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(cont_read_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        delete_last_pushButton = new QPushButton(layoutWidget);
        delete_last_pushButton->setObjectName(QString::fromUtf8("delete_last_pushButton"));
        delete_last_pushButton->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(delete_last_pushButton);

        delete_sketch_pushButton = new QPushButton(layoutWidget);
        delete_sketch_pushButton->setObjectName(QString::fromUtf8("delete_sketch_pushButton"));
        delete_sketch_pushButton->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(delete_sketch_pushButton);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1700, 60, 181, 67));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        max_spinbox = new QSpinBox(layoutWidget1);
        max_spinbox->setObjectName(QString::fromUtf8("max_spinbox"));
        max_spinbox->setMinimum(1);
        max_spinbox->setMaximum(1000);
        max_spinbox->setSingleStep(10);
        max_spinbox->setValue(1);

        gridLayout_2->addWidget(max_spinbox, 0, 1, 1, 1);

        min_spinbox = new QDoubleSpinBox(layoutWidget1);
        min_spinbox->setObjectName(QString::fromUtf8("min_spinbox"));
        min_spinbox->setMinimum(-900);
        min_spinbox->setMaximum(0);

        gridLayout_2->addWidget(min_spinbox, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(1670, 140, 251, 501));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 241, 471));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scale_checkBox = new QCheckBox(layoutWidget2);
        scale_checkBox->setObjectName(QString::fromUtf8("scale_checkBox"));
        scale_checkBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(scale_checkBox);

        flip_checkBox = new QCheckBox(layoutWidget2);
        flip_checkBox->setObjectName(QString::fromUtf8("flip_checkBox"));
        flip_checkBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(flip_checkBox);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        x_y_scale_lineedit1 = new QLineEdit(layoutWidget2);
        x_y_scale_lineedit1->setObjectName(QString::fromUtf8("x_y_scale_lineedit1"));

        gridLayout_4->addWidget(x_y_scale_lineedit1, 1, 0, 1, 2);

        x_y_scale_lineedit2 = new QLineEdit(layoutWidget2);
        x_y_scale_lineedit2->setObjectName(QString::fromUtf8("x_y_scale_lineedit2"));

        gridLayout_4->addWidget(x_y_scale_lineedit2, 1, 3, 1, 1);

        x_y_scale_label = new QLabel(layoutWidget2);
        x_y_scale_label->setObjectName(QString::fromUtf8("x_y_scale_label"));

        gridLayout_4->addWidget(x_y_scale_label, 0, 0, 1, 2);

        x_y_scale_pushButton = new QPushButton(layoutWidget2);
        x_y_scale_pushButton->setObjectName(QString::fromUtf8("x_y_scale_pushButton"));

        gridLayout_4->addWidget(x_y_scale_pushButton, 3, 0, 1, 2);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 3, 1, 1);

        ok_x_y_scale_pushButton = new QPushButton(layoutWidget2);
        ok_x_y_scale_pushButton->setObjectName(QString::fromUtf8("ok_x_y_scale_pushButton"));

        gridLayout_4->addWidget(ok_x_y_scale_pushButton, 1, 2, 1, 1);

        x_y_scale_pushButton_2 = new QPushButton(layoutWidget2);
        x_y_scale_pushButton_2->setObjectName(QString::fromUtf8("x_y_scale_pushButton_2"));

        gridLayout_4->addWidget(x_y_scale_pushButton_2, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        angle_lineedit1 = new QLineEdit(layoutWidget2);
        angle_lineedit1->setObjectName(QString::fromUtf8("angle_lineedit1"));

        gridLayout_5->addWidget(angle_lineedit1, 1, 0, 1, 2);

        angle_lineedit2 = new QLineEdit(layoutWidget2);
        angle_lineedit2->setObjectName(QString::fromUtf8("angle_lineedit2"));

        gridLayout_5->addWidget(angle_lineedit2, 1, 3, 1, 1);

        angle_label = new QLabel(layoutWidget2);
        angle_label->setObjectName(QString::fromUtf8("angle_label"));

        gridLayout_5->addWidget(angle_label, 0, 0, 1, 2);

        angle_pushbutton = new QPushButton(layoutWidget2);
        angle_pushbutton->setObjectName(QString::fromUtf8("angle_pushbutton"));

        gridLayout_5->addWidget(angle_pushbutton, 3, 0, 1, 2);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 0, 3, 1, 1);

        ok_angle_pushbutton = new QPushButton(layoutWidget2);
        ok_angle_pushbutton->setObjectName(QString::fromUtf8("ok_angle_pushbutton"));

        gridLayout_5->addWidget(ok_angle_pushbutton, 1, 2, 1, 1);

        angle_pushbutton_2 = new QPushButton(layoutWidget2);
        angle_pushbutton_2->setObjectName(QString::fromUtf8("angle_pushbutton_2"));

        gridLayout_5->addWidget(angle_pushbutton_2, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        x_shift_lineedit1 = new QLineEdit(layoutWidget2);
        x_shift_lineedit1->setObjectName(QString::fromUtf8("x_shift_lineedit1"));

        gridLayout_6->addWidget(x_shift_lineedit1, 1, 0, 1, 2);

        x_shift_lineedit2 = new QLineEdit(layoutWidget2);
        x_shift_lineedit2->setObjectName(QString::fromUtf8("x_shift_lineedit2"));

        gridLayout_6->addWidget(x_shift_lineedit2, 1, 3, 1, 1);

        angle_label_2 = new QLabel(layoutWidget2);
        angle_label_2->setObjectName(QString::fromUtf8("angle_label_2"));

        gridLayout_6->addWidget(angle_label_2, 0, 0, 1, 2);

        x_y_shitft_pushButton = new QPushButton(layoutWidget2);
        x_y_shitft_pushButton->setObjectName(QString::fromUtf8("x_y_shitft_pushButton"));

        gridLayout_6->addWidget(x_y_shitft_pushButton, 4, 0, 1, 2);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 3, 1, 1);

        y_shift_lineedit1 = new QLineEdit(layoutWidget2);
        y_shift_lineedit1->setObjectName(QString::fromUtf8("y_shift_lineedit1"));

        gridLayout_6->addWidget(y_shift_lineedit1, 2, 0, 1, 2);

        y_shift_lineedit2 = new QLineEdit(layoutWidget2);
        y_shift_lineedit2->setObjectName(QString::fromUtf8("y_shift_lineedit2"));

        gridLayout_6->addWidget(y_shift_lineedit2, 2, 3, 1, 1);

        ok_x_y_shift_pushButton = new QPushButton(layoutWidget2);
        ok_x_y_shift_pushButton->setObjectName(QString::fromUtf8("ok_x_y_shift_pushButton"));

        gridLayout_6->addWidget(ok_x_y_shift_pushButton, 1, 2, 1, 1);

        x_y_shitft_pushButton_2 = new QPushButton(layoutWidget2);
        x_y_shitft_pushButton_2->setObjectName(QString::fromUtf8("x_y_shitft_pushButton_2"));

        gridLayout_6->addWidget(x_y_shitft_pushButton_2, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        x_shift_label = new QLabel(layoutWidget2);
        x_shift_label->setObjectName(QString::fromUtf8("x_shift_label"));
        x_shift_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_shift_label, 0, 0, 1, 1);

        x_shift_lineEdit = new QLineEdit(layoutWidget2);
        x_shift_lineEdit->setObjectName(QString::fromUtf8("x_shift_lineEdit"));
        x_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_shift_lineEdit, 0, 1, 1, 1);

        y_shift_label = new QLabel(layoutWidget2);
        y_shift_label->setObjectName(QString::fromUtf8("y_shift_label"));
        y_shift_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_shift_label, 1, 0, 1, 1);

        y_shift_lineEdit = new QLineEdit(layoutWidget2);
        y_shift_lineEdit->setObjectName(QString::fromUtf8("y_shift_lineEdit"));
        y_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_shift_lineEdit, 1, 1, 1, 1);

        x_scale_label = new QLabel(layoutWidget2);
        x_scale_label->setObjectName(QString::fromUtf8("x_scale_label"));
        x_scale_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_scale_label, 2, 0, 1, 1);

        x_scale_lineEdit = new QLineEdit(layoutWidget2);
        x_scale_lineEdit->setObjectName(QString::fromUtf8("x_scale_lineEdit"));
        x_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_scale_lineEdit, 2, 1, 1, 1);

        y_scale_label = new QLabel(layoutWidget2);
        y_scale_label->setObjectName(QString::fromUtf8("y_scale_label"));
        y_scale_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_scale_label, 3, 0, 1, 1);

        y_scale_lineEdit = new QLineEdit(layoutWidget2);
        y_scale_lineEdit->setObjectName(QString::fromUtf8("y_scale_lineEdit"));
        y_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_scale_lineEdit, 3, 1, 1, 1);

        k_label = new QLabel(layoutWidget2);
        k_label->setObjectName(QString::fromUtf8("k_label"));
        k_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(k_label, 4, 0, 1, 1);

        k_lineEdit = new QLineEdit(layoutWidget2);
        k_lineEdit->setObjectName(QString::fromUtf8("k_lineEdit"));
        k_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(k_lineEdit, 4, 1, 1, 1);

        fi_label = new QLabel(layoutWidget2);
        fi_label->setObjectName(QString::fromUtf8("fi_label"));
        fi_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(fi_label, 5, 0, 1, 1);

        fi_lineEdit = new QLineEdit(layoutWidget2);
        fi_lineEdit->setObjectName(QString::fromUtf8("fi_lineEdit"));
        fi_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(fi_lineEdit, 5, 1, 1, 1);

        fi_shift_slider = new QSlider(layoutWidget2);
        fi_shift_slider->setObjectName(QString::fromUtf8("fi_shift_slider"));
        fi_shift_slider->setMaximum(360);
        fi_shift_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(fi_shift_slider, 9, 0, 1, 2);

        fi_shift_label = new QLabel(layoutWidget2);
        fi_shift_label->setObjectName(QString::fromUtf8("fi_shift_label"));
        fi_shift_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(fi_shift_label, 8, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        layoutWidget_2 = new QWidget(tab_4);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 0, 241, 471));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_2->addLayout(horizontalLayout_3);

        photo_enable_checkBox = new QCheckBox(layoutWidget_2);
        photo_enable_checkBox->setObjectName(QString::fromUtf8("photo_enable_checkBox"));

        verticalLayout_2->addWidget(photo_enable_checkBox);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        photo_x_y_scale_lineedit1 = new QLineEdit(layoutWidget_2);
        photo_x_y_scale_lineedit1->setObjectName(QString::fromUtf8("photo_x_y_scale_lineedit1"));

        gridLayout_7->addWidget(photo_x_y_scale_lineedit1, 1, 0, 1, 2);

        photo_x_y_scale_lineedit2 = new QLineEdit(layoutWidget_2);
        photo_x_y_scale_lineedit2->setObjectName(QString::fromUtf8("photo_x_y_scale_lineedit2"));

        gridLayout_7->addWidget(photo_x_y_scale_lineedit2, 1, 3, 1, 1);

        x_y_scale_label_2 = new QLabel(layoutWidget_2);
        x_y_scale_label_2->setObjectName(QString::fromUtf8("x_y_scale_label_2"));

        gridLayout_7->addWidget(x_y_scale_label_2, 0, 0, 1, 2);

        photo_x_y_scale_pushButton = new QPushButton(layoutWidget_2);
        photo_x_y_scale_pushButton->setObjectName(QString::fromUtf8("photo_x_y_scale_pushButton"));

        gridLayout_7->addWidget(photo_x_y_scale_pushButton, 3, 0, 1, 2);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_7->addWidget(label_10, 0, 3, 1, 1);

        photo_ok_x_y_scale_pushButton = new QPushButton(layoutWidget_2);
        photo_ok_x_y_scale_pushButton->setObjectName(QString::fromUtf8("photo_ok_x_y_scale_pushButton"));

        gridLayout_7->addWidget(photo_ok_x_y_scale_pushButton, 1, 2, 1, 1);

        photo_x_y_scale_pushButton_2 = new QPushButton(layoutWidget_2);
        photo_x_y_scale_pushButton_2->setObjectName(QString::fromUtf8("photo_x_y_scale_pushButton_2"));

        gridLayout_7->addWidget(photo_x_y_scale_pushButton_2, 3, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_7);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        photo_angle_lineedit1 = new QLineEdit(layoutWidget_2);
        photo_angle_lineedit1->setObjectName(QString::fromUtf8("photo_angle_lineedit1"));

        gridLayout_8->addWidget(photo_angle_lineedit1, 1, 0, 1, 2);

        photo_angle_lineedit2 = new QLineEdit(layoutWidget_2);
        photo_angle_lineedit2->setObjectName(QString::fromUtf8("photo_angle_lineedit2"));

        gridLayout_8->addWidget(photo_angle_lineedit2, 1, 3, 1, 1);

        angle_label_3 = new QLabel(layoutWidget_2);
        angle_label_3->setObjectName(QString::fromUtf8("angle_label_3"));

        gridLayout_8->addWidget(angle_label_3, 0, 0, 1, 2);

        photo_angle_pushbutton = new QPushButton(layoutWidget_2);
        photo_angle_pushbutton->setObjectName(QString::fromUtf8("photo_angle_pushbutton"));

        gridLayout_8->addWidget(photo_angle_pushbutton, 3, 0, 1, 2);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_8->addWidget(label_11, 0, 3, 1, 1);

        photo_ok_angle_pushbutton = new QPushButton(layoutWidget_2);
        photo_ok_angle_pushbutton->setObjectName(QString::fromUtf8("photo_ok_angle_pushbutton"));

        gridLayout_8->addWidget(photo_ok_angle_pushbutton, 1, 2, 1, 1);

        photo_angle_pushbutton_2 = new QPushButton(layoutWidget_2);
        photo_angle_pushbutton_2->setObjectName(QString::fromUtf8("photo_angle_pushbutton_2"));

        gridLayout_8->addWidget(photo_angle_pushbutton_2, 3, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_8);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        photo_x_shift_lineedit1 = new QLineEdit(layoutWidget_2);
        photo_x_shift_lineedit1->setObjectName(QString::fromUtf8("photo_x_shift_lineedit1"));

        gridLayout_9->addWidget(photo_x_shift_lineedit1, 1, 0, 1, 2);

        photo_x_shift_lineedit2 = new QLineEdit(layoutWidget_2);
        photo_x_shift_lineedit2->setObjectName(QString::fromUtf8("photo_x_shift_lineedit2"));

        gridLayout_9->addWidget(photo_x_shift_lineedit2, 1, 3, 1, 1);

        angle_label_4 = new QLabel(layoutWidget_2);
        angle_label_4->setObjectName(QString::fromUtf8("angle_label_4"));

        gridLayout_9->addWidget(angle_label_4, 0, 0, 1, 2);

        photo_x_y_shitft_pushButton = new QPushButton(layoutWidget_2);
        photo_x_y_shitft_pushButton->setObjectName(QString::fromUtf8("photo_x_y_shitft_pushButton"));

        gridLayout_9->addWidget(photo_x_y_shitft_pushButton, 4, 0, 1, 2);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_9->addWidget(label_12, 0, 3, 1, 1);

        photo_y_shift_lineedit1 = new QLineEdit(layoutWidget_2);
        photo_y_shift_lineedit1->setObjectName(QString::fromUtf8("photo_y_shift_lineedit1"));

        gridLayout_9->addWidget(photo_y_shift_lineedit1, 2, 0, 1, 2);

        photo_y_shift_lineedit2 = new QLineEdit(layoutWidget_2);
        photo_y_shift_lineedit2->setObjectName(QString::fromUtf8("photo_y_shift_lineedit2"));

        gridLayout_9->addWidget(photo_y_shift_lineedit2, 2, 3, 1, 1);

        photo_ok_x_y_shift_pushButton = new QPushButton(layoutWidget_2);
        photo_ok_x_y_shift_pushButton->setObjectName(QString::fromUtf8("photo_ok_x_y_shift_pushButton"));

        gridLayout_9->addWidget(photo_ok_x_y_shift_pushButton, 1, 2, 1, 1);

        photo_x_y_shitft_pushButton_2 = new QPushButton(layoutWidget_2);
        photo_x_y_shitft_pushButton_2->setObjectName(QString::fromUtf8("photo_x_y_shitft_pushButton_2"));

        gridLayout_9->addWidget(photo_x_y_shitft_pushButton_2, 4, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_9);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        x_shift_label_2 = new QLabel(layoutWidget_2);
        x_shift_label_2->setObjectName(QString::fromUtf8("x_shift_label_2"));
        x_shift_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(x_shift_label_2, 0, 0, 1, 1);

        photo_x_shift_lineEdit = new QLineEdit(layoutWidget_2);
        photo_x_shift_lineEdit->setObjectName(QString::fromUtf8("photo_x_shift_lineEdit"));
        photo_x_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_x_shift_lineEdit, 0, 1, 1, 1);

        y_shift_label_2 = new QLabel(layoutWidget_2);
        y_shift_label_2->setObjectName(QString::fromUtf8("y_shift_label_2"));
        y_shift_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(y_shift_label_2, 1, 0, 1, 1);

        photo_y_shift_lineEdit = new QLineEdit(layoutWidget_2);
        photo_y_shift_lineEdit->setObjectName(QString::fromUtf8("photo_y_shift_lineEdit"));
        photo_y_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_y_shift_lineEdit, 1, 1, 1, 1);

        x_scale_label_2 = new QLabel(layoutWidget_2);
        x_scale_label_2->setObjectName(QString::fromUtf8("x_scale_label_2"));
        x_scale_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(x_scale_label_2, 2, 0, 1, 1);

        photo_x_scale_lineEdit = new QLineEdit(layoutWidget_2);
        photo_x_scale_lineEdit->setObjectName(QString::fromUtf8("photo_x_scale_lineEdit"));
        photo_x_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_x_scale_lineEdit, 2, 1, 1, 1);

        y_scale_label_2 = new QLabel(layoutWidget_2);
        y_scale_label_2->setObjectName(QString::fromUtf8("y_scale_label_2"));
        y_scale_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(y_scale_label_2, 3, 0, 1, 1);

        photo_y_scale_lineEdit = new QLineEdit(layoutWidget_2);
        photo_y_scale_lineEdit->setObjectName(QString::fromUtf8("photo_y_scale_lineEdit"));
        photo_y_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_y_scale_lineEdit, 3, 1, 1, 1);

        k_label_2 = new QLabel(layoutWidget_2);
        k_label_2->setObjectName(QString::fromUtf8("k_label_2"));
        k_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(k_label_2, 4, 0, 1, 1);

        photo_k_lineEdit = new QLineEdit(layoutWidget_2);
        photo_k_lineEdit->setObjectName(QString::fromUtf8("photo_k_lineEdit"));
        photo_k_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_k_lineEdit, 4, 1, 1, 1);

        fi_label_2 = new QLabel(layoutWidget_2);
        fi_label_2->setObjectName(QString::fromUtf8("fi_label_2"));
        fi_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(fi_label_2, 5, 0, 1, 1);

        photo_fi_lineEdit = new QLineEdit(layoutWidget_2);
        photo_fi_lineEdit->setObjectName(QString::fromUtf8("photo_fi_lineEdit"));
        photo_fi_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_fi_lineEdit, 5, 1, 1, 1);

        fi_shift_label_2 = new QLabel(layoutWidget_2);
        fi_shift_label_2->setObjectName(QString::fromUtf8("fi_shift_label_2"));
        fi_shift_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(fi_shift_label_2, 8, 0, 1, 2);

        photo_fi_shift_slider = new QSlider(layoutWidget_2);
        photo_fi_shift_slider->setObjectName(QString::fromUtf8("photo_fi_shift_slider"));
        photo_fi_shift_slider->setMaximum(360);
        photo_fi_shift_slider->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(photo_fi_shift_slider, 9, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout_10);

        tabWidget->addTab(tab_4, QString());
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 1060, 1791, 51));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        read_pushbutton->setText(QApplication::translate("Widget", "Read", 0, QApplication::UnicodeUTF8));
        type_combobox->clear();
        type_combobox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Ampl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Phase", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Re", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Im", 0, QApplication::UnicodeUTF8)
        );
        spec_type_combobox->clear();
        spec_type_combobox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "Transparent", 0, QApplication::UnicodeUTF8)
        );
        rect_pushButton->setText(QApplication::translate("Widget", "Rect", 0, QApplication::UnicodeUTF8));
        polygon_pushButton->setText(QApplication::translate("Widget", "Polygon", 0, QApplication::UnicodeUTF8));
        line_pushButton->setText(QApplication::translate("Widget", "Line", 0, QApplication::UnicodeUTF8));
        color_comboBox->clear();
        color_comboBox->insertItems(0, QStringList()
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
        sketch_checkBox->setText(QApplication::translate("Widget", "Sketch", 0, QApplication::UnicodeUTF8));
        zoom_pushButton->setText(QApplication::translate("Widget", "Zoomer", 0, QApplication::UnicodeUTF8));
        select_point_pushButton->setText(QApplication::translate("Widget", "Select Point", 0, QApplication::UnicodeUTF8));
        cont_read_pushButton->setText(QApplication::translate("Widget", "Cont read", 0, QApplication::UnicodeUTF8));
        delete_last_pushButton->setText(QApplication::translate("Widget", "Delete item", 0, QApplication::UnicodeUTF8));
        delete_sketch_pushButton->setText(QApplication::translate("Widget", "Delete sketch", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "Spectr", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "Spectr", 0, QApplication::UnicodeUTF8));
        scale_checkBox->setText(QApplication::translate("Widget", "Scale", 0, QApplication::UnicodeUTF8));
        flip_checkBox->setText(QApplication::translate("Widget", "Flip", 0, QApplication::UnicodeUTF8));
        x_y_scale_label->setText(QApplication::translate("Widget", "Scale X Y", 0, QApplication::UnicodeUTF8));
        x_y_scale_pushButton->setText(QApplication::translate("Widget", "Select 1", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        ok_x_y_scale_pushButton->setText(QApplication::translate("Widget", "<<OK", 0, QApplication::UnicodeUTF8));
        x_y_scale_pushButton_2->setText(QApplication::translate("Widget", "Select 1", 0, QApplication::UnicodeUTF8));
        angle_label->setText(QApplication::translate("Widget", "Angle", 0, QApplication::UnicodeUTF8));
        angle_pushbutton->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        ok_angle_pushbutton->setText(QApplication::translate("Widget", "OK", 0, QApplication::UnicodeUTF8));
        angle_pushbutton_2->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        angle_label_2->setText(QApplication::translate("Widget", "X Y shift", 0, QApplication::UnicodeUTF8));
        x_y_shitft_pushButton->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        ok_x_y_shift_pushButton->setText(QApplication::translate("Widget", "OK", 0, QApplication::UnicodeUTF8));
        x_y_shitft_pushButton_2->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        x_shift_label->setText(QApplication::translate("Widget", "X  Shift", 0, QApplication::UnicodeUTF8));
        y_shift_label->setText(QApplication::translate("Widget", "Y  Shift", 0, QApplication::UnicodeUTF8));
        y_shift_lineEdit->setText(QString());
        x_scale_label->setText(QApplication::translate("Widget", "X  Scale", 0, QApplication::UnicodeUTF8));
        y_scale_label->setText(QApplication::translate("Widget", "Y  Scale", 0, QApplication::UnicodeUTF8));
        k_label->setText(QApplication::translate("Widget", "K (+1,-1)", 0, QApplication::UnicodeUTF8));
        fi_label->setText(QApplication::translate("Widget", "Fi 0", 0, QApplication::UnicodeUTF8));
        fi_shift_label->setText(QApplication::translate("Widget", "                         Fi shift", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "Sketch", 0, QApplication::UnicodeUTF8));
        photo_enable_checkBox->setText(QApplication::translate("Widget", "Enable", 0, QApplication::UnicodeUTF8));
        x_y_scale_label_2->setText(QApplication::translate("Widget", "Scale X Y", 0, QApplication::UnicodeUTF8));
        photo_x_y_scale_pushButton->setText(QApplication::translate("Widget", "Select 1", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        photo_ok_x_y_scale_pushButton->setText(QApplication::translate("Widget", "<<OK", 0, QApplication::UnicodeUTF8));
        photo_x_y_scale_pushButton_2->setText(QApplication::translate("Widget", "Select 1", 0, QApplication::UnicodeUTF8));
        angle_label_3->setText(QApplication::translate("Widget", "Angle", 0, QApplication::UnicodeUTF8));
        photo_angle_pushbutton->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        photo_ok_angle_pushbutton->setText(QApplication::translate("Widget", "OK", 0, QApplication::UnicodeUTF8));
        photo_angle_pushbutton_2->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        angle_label_4->setText(QApplication::translate("Widget", "X Y shift", 0, QApplication::UnicodeUTF8));
        photo_x_y_shitft_pushButton->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        photo_ok_x_y_shift_pushButton->setText(QApplication::translate("Widget", "OK", 0, QApplication::UnicodeUTF8));
        photo_x_y_shitft_pushButton_2->setText(QApplication::translate("Widget", "Select", 0, QApplication::UnicodeUTF8));
        x_shift_label_2->setText(QApplication::translate("Widget", "X  Shift", 0, QApplication::UnicodeUTF8));
        y_shift_label_2->setText(QApplication::translate("Widget", "Y  Shift", 0, QApplication::UnicodeUTF8));
        photo_y_shift_lineEdit->setText(QString());
        x_scale_label_2->setText(QApplication::translate("Widget", "X  Scale", 0, QApplication::UnicodeUTF8));
        y_scale_label_2->setText(QApplication::translate("Widget", "Y  Scale", 0, QApplication::UnicodeUTF8));
        k_label_2->setText(QApplication::translate("Widget", "K (+1,-1)", 0, QApplication::UnicodeUTF8));
        fi_label_2->setText(QApplication::translate("Widget", "Fi 0", 0, QApplication::UnicodeUTF8));
        fi_shift_label_2->setText(QApplication::translate("Widget", "                         Fi shift", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Widget", "Photo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWIDGET_H

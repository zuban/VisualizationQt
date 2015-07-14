/********************************************************************************
** Form generated from reading UI file 'form_spectr.ui'
**
** Created: Sun 12. Apr 16:30:12 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SPECTR_H
#define UI_FORM_SPECTR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Spectr
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *cont_read_pushButton;
    QPushButton *read_pushbutton;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
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
    QSlider *horizontalSlider_for_cuda_test;
    QWidget *tab_4;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_2;
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
    QLabel *k_label_2;
    QLineEdit *photo_k_lineEdit;
    QSlider *photo_fi_shift_slider;
    QLineEdit *photo_y_shift_lineEdit;
    QLabel *y_shift_label_2;
    QLineEdit *photo_x_scale_lineEdit;
    QLabel *x_scale_label_2;
    QLabel *y_scale_label_2;
    QLineEdit *photo_y_scale_lineEdit;
    QLabel *fi_label_2;
    QLineEdit *photo_fi_lineEdit;
    QWidget *tab;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Nk_data_label;
    QLineEdit *Nk_lineedit_data;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Nfi_data_label;
    QLineEdit *Nfi_lineedit_data;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Fstart_label;
    QLineEdit *Fstart_lineedit_data;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Fstop_data_label;
    QLineEdit *Fstop_lineedit_data;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Azstart_data_label;
    QLineEdit *Azstart_lieedit_data;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Azstop_label;
    QLineEdit *Azstop_lineedit_data;

    void setupUi(QWidget *Form_Spectr)
    {
        if (Form_Spectr->objectName().isEmpty())
            Form_Spectr->setObjectName(QString::fromUtf8("Form_Spectr"));
        Form_Spectr->resize(575, 716);
        Form_Spectr->setMinimumSize(QSize(270, 560));
        gridLayout = new QGridLayout(Form_Spectr);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cont_read_pushButton = new QPushButton(Form_Spectr);
        cont_read_pushButton->setObjectName(QString::fromUtf8("cont_read_pushButton"));
        cont_read_pushButton->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(cont_read_pushButton);

        read_pushbutton = new QPushButton(Form_Spectr);
        read_pushbutton->setObjectName(QString::fromUtf8("read_pushbutton"));
        read_pushbutton->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(read_pushbutton);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(Form_Spectr);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scale_checkBox = new QCheckBox(tab_3);
        scale_checkBox->setObjectName(QString::fromUtf8("scale_checkBox"));
        scale_checkBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(scale_checkBox);

        flip_checkBox = new QCheckBox(tab_3);
        flip_checkBox->setObjectName(QString::fromUtf8("flip_checkBox"));
        flip_checkBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(flip_checkBox);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        x_y_scale_lineedit1 = new QLineEdit(tab_3);
        x_y_scale_lineedit1->setObjectName(QString::fromUtf8("x_y_scale_lineedit1"));

        gridLayout_4->addWidget(x_y_scale_lineedit1, 1, 0, 1, 2);

        x_y_scale_lineedit2 = new QLineEdit(tab_3);
        x_y_scale_lineedit2->setObjectName(QString::fromUtf8("x_y_scale_lineedit2"));

        gridLayout_4->addWidget(x_y_scale_lineedit2, 1, 3, 1, 1);

        x_y_scale_label = new QLabel(tab_3);
        x_y_scale_label->setObjectName(QString::fromUtf8("x_y_scale_label"));

        gridLayout_4->addWidget(x_y_scale_label, 0, 0, 1, 2);

        x_y_scale_pushButton = new QPushButton(tab_3);
        x_y_scale_pushButton->setObjectName(QString::fromUtf8("x_y_scale_pushButton"));

        gridLayout_4->addWidget(x_y_scale_pushButton, 3, 0, 1, 2);

        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 3, 1, 1);

        ok_x_y_scale_pushButton = new QPushButton(tab_3);
        ok_x_y_scale_pushButton->setObjectName(QString::fromUtf8("ok_x_y_scale_pushButton"));

        gridLayout_4->addWidget(ok_x_y_scale_pushButton, 1, 2, 1, 1);

        x_y_scale_pushButton_2 = new QPushButton(tab_3);
        x_y_scale_pushButton_2->setObjectName(QString::fromUtf8("x_y_scale_pushButton_2"));

        gridLayout_4->addWidget(x_y_scale_pushButton_2, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        angle_lineedit1 = new QLineEdit(tab_3);
        angle_lineedit1->setObjectName(QString::fromUtf8("angle_lineedit1"));

        gridLayout_5->addWidget(angle_lineedit1, 1, 0, 1, 2);

        angle_lineedit2 = new QLineEdit(tab_3);
        angle_lineedit2->setObjectName(QString::fromUtf8("angle_lineedit2"));

        gridLayout_5->addWidget(angle_lineedit2, 1, 3, 1, 1);

        angle_label = new QLabel(tab_3);
        angle_label->setObjectName(QString::fromUtf8("angle_label"));

        gridLayout_5->addWidget(angle_label, 0, 0, 1, 2);

        angle_pushbutton = new QPushButton(tab_3);
        angle_pushbutton->setObjectName(QString::fromUtf8("angle_pushbutton"));

        gridLayout_5->addWidget(angle_pushbutton, 3, 0, 1, 2);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 0, 3, 1, 1);

        ok_angle_pushbutton = new QPushButton(tab_3);
        ok_angle_pushbutton->setObjectName(QString::fromUtf8("ok_angle_pushbutton"));

        gridLayout_5->addWidget(ok_angle_pushbutton, 1, 2, 1, 1);

        angle_pushbutton_2 = new QPushButton(tab_3);
        angle_pushbutton_2->setObjectName(QString::fromUtf8("angle_pushbutton_2"));

        gridLayout_5->addWidget(angle_pushbutton_2, 3, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        x_shift_lineedit1 = new QLineEdit(tab_3);
        x_shift_lineedit1->setObjectName(QString::fromUtf8("x_shift_lineedit1"));

        gridLayout_6->addWidget(x_shift_lineedit1, 1, 0, 1, 2);

        x_shift_lineedit2 = new QLineEdit(tab_3);
        x_shift_lineedit2->setObjectName(QString::fromUtf8("x_shift_lineedit2"));

        gridLayout_6->addWidget(x_shift_lineedit2, 1, 3, 1, 1);

        angle_label_2 = new QLabel(tab_3);
        angle_label_2->setObjectName(QString::fromUtf8("angle_label_2"));

        gridLayout_6->addWidget(angle_label_2, 0, 0, 1, 2);

        x_y_shitft_pushButton = new QPushButton(tab_3);
        x_y_shitft_pushButton->setObjectName(QString::fromUtf8("x_y_shitft_pushButton"));

        gridLayout_6->addWidget(x_y_shitft_pushButton, 4, 0, 1, 2);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_6->addWidget(label_9, 0, 3, 1, 1);

        y_shift_lineedit1 = new QLineEdit(tab_3);
        y_shift_lineedit1->setObjectName(QString::fromUtf8("y_shift_lineedit1"));

        gridLayout_6->addWidget(y_shift_lineedit1, 2, 0, 1, 2);

        y_shift_lineedit2 = new QLineEdit(tab_3);
        y_shift_lineedit2->setObjectName(QString::fromUtf8("y_shift_lineedit2"));

        gridLayout_6->addWidget(y_shift_lineedit2, 2, 3, 1, 1);

        ok_x_y_shift_pushButton = new QPushButton(tab_3);
        ok_x_y_shift_pushButton->setObjectName(QString::fromUtf8("ok_x_y_shift_pushButton"));

        gridLayout_6->addWidget(ok_x_y_shift_pushButton, 1, 2, 1, 1);

        x_y_shitft_pushButton_2 = new QPushButton(tab_3);
        x_y_shitft_pushButton_2->setObjectName(QString::fromUtf8("x_y_shitft_pushButton_2"));

        gridLayout_6->addWidget(x_y_shitft_pushButton_2, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        x_shift_label = new QLabel(tab_3);
        x_shift_label->setObjectName(QString::fromUtf8("x_shift_label"));
        x_shift_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_shift_label, 0, 0, 1, 1);

        x_shift_lineEdit = new QLineEdit(tab_3);
        x_shift_lineEdit->setObjectName(QString::fromUtf8("x_shift_lineEdit"));
        x_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_shift_lineEdit, 0, 1, 1, 1);

        y_shift_label = new QLabel(tab_3);
        y_shift_label->setObjectName(QString::fromUtf8("y_shift_label"));
        y_shift_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_shift_label, 1, 0, 1, 1);

        y_shift_lineEdit = new QLineEdit(tab_3);
        y_shift_lineEdit->setObjectName(QString::fromUtf8("y_shift_lineEdit"));
        y_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_shift_lineEdit, 1, 1, 1, 1);

        x_scale_label = new QLabel(tab_3);
        x_scale_label->setObjectName(QString::fromUtf8("x_scale_label"));
        x_scale_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_scale_label, 2, 0, 1, 1);

        x_scale_lineEdit = new QLineEdit(tab_3);
        x_scale_lineEdit->setObjectName(QString::fromUtf8("x_scale_lineEdit"));
        x_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(x_scale_lineEdit, 2, 1, 1, 1);

        y_scale_label = new QLabel(tab_3);
        y_scale_label->setObjectName(QString::fromUtf8("y_scale_label"));
        y_scale_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_scale_label, 3, 0, 1, 1);

        y_scale_lineEdit = new QLineEdit(tab_3);
        y_scale_lineEdit->setObjectName(QString::fromUtf8("y_scale_lineEdit"));
        y_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(y_scale_lineEdit, 3, 1, 1, 1);

        k_label = new QLabel(tab_3);
        k_label->setObjectName(QString::fromUtf8("k_label"));
        k_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(k_label, 4, 0, 1, 1);

        k_lineEdit = new QLineEdit(tab_3);
        k_lineEdit->setObjectName(QString::fromUtf8("k_lineEdit"));
        k_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(k_lineEdit, 4, 1, 1, 1);

        fi_label = new QLabel(tab_3);
        fi_label->setObjectName(QString::fromUtf8("fi_label"));
        fi_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(fi_label, 5, 0, 1, 1);

        fi_lineEdit = new QLineEdit(tab_3);
        fi_lineEdit->setObjectName(QString::fromUtf8("fi_lineEdit"));
        fi_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(fi_lineEdit, 5, 1, 1, 1);

        fi_shift_slider = new QSlider(tab_3);
        fi_shift_slider->setObjectName(QString::fromUtf8("fi_shift_slider"));
        fi_shift_slider->setMaximum(360);
        fi_shift_slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(fi_shift_slider, 9, 0, 1, 2);

        fi_shift_label = new QLabel(tab_3);
        fi_shift_label->setObjectName(QString::fromUtf8("fi_shift_label"));
        fi_shift_label->setMinimumSize(QSize(0, 15));

        gridLayout_3->addWidget(fi_shift_label, 8, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_3);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalSlider_for_cuda_test = new QSlider(tab_3);
        horizontalSlider_for_cuda_test->setObjectName(QString::fromUtf8("horizontalSlider_for_cuda_test"));
        horizontalSlider_for_cuda_test->setMaximum(360);
        horizontalSlider_for_cuda_test->setOrientation(Qt::Horizontal);
        horizontalSlider_for_cuda_test->setTickInterval(0);

        gridLayout_2->addWidget(horizontalSlider_for_cuda_test, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_11 = new QGridLayout(tab_4);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        photo_enable_checkBox = new QCheckBox(tab_4);
        photo_enable_checkBox->setObjectName(QString::fromUtf8("photo_enable_checkBox"));

        verticalLayout_2->addWidget(photo_enable_checkBox);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        photo_x_y_scale_lineedit1 = new QLineEdit(tab_4);
        photo_x_y_scale_lineedit1->setObjectName(QString::fromUtf8("photo_x_y_scale_lineedit1"));

        gridLayout_7->addWidget(photo_x_y_scale_lineedit1, 1, 0, 1, 2);

        photo_x_y_scale_lineedit2 = new QLineEdit(tab_4);
        photo_x_y_scale_lineedit2->setObjectName(QString::fromUtf8("photo_x_y_scale_lineedit2"));

        gridLayout_7->addWidget(photo_x_y_scale_lineedit2, 1, 3, 1, 1);

        x_y_scale_label_2 = new QLabel(tab_4);
        x_y_scale_label_2->setObjectName(QString::fromUtf8("x_y_scale_label_2"));

        gridLayout_7->addWidget(x_y_scale_label_2, 0, 0, 1, 2);

        photo_x_y_scale_pushButton = new QPushButton(tab_4);
        photo_x_y_scale_pushButton->setObjectName(QString::fromUtf8("photo_x_y_scale_pushButton"));

        gridLayout_7->addWidget(photo_x_y_scale_pushButton, 3, 0, 1, 2);

        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_7->addWidget(label_10, 0, 3, 1, 1);

        photo_ok_x_y_scale_pushButton = new QPushButton(tab_4);
        photo_ok_x_y_scale_pushButton->setObjectName(QString::fromUtf8("photo_ok_x_y_scale_pushButton"));

        gridLayout_7->addWidget(photo_ok_x_y_scale_pushButton, 1, 2, 1, 1);

        photo_x_y_scale_pushButton_2 = new QPushButton(tab_4);
        photo_x_y_scale_pushButton_2->setObjectName(QString::fromUtf8("photo_x_y_scale_pushButton_2"));

        gridLayout_7->addWidget(photo_x_y_scale_pushButton_2, 3, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_7);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        photo_angle_lineedit1 = new QLineEdit(tab_4);
        photo_angle_lineedit1->setObjectName(QString::fromUtf8("photo_angle_lineedit1"));

        gridLayout_8->addWidget(photo_angle_lineedit1, 1, 0, 1, 2);

        photo_angle_lineedit2 = new QLineEdit(tab_4);
        photo_angle_lineedit2->setObjectName(QString::fromUtf8("photo_angle_lineedit2"));

        gridLayout_8->addWidget(photo_angle_lineedit2, 1, 3, 1, 1);

        angle_label_3 = new QLabel(tab_4);
        angle_label_3->setObjectName(QString::fromUtf8("angle_label_3"));

        gridLayout_8->addWidget(angle_label_3, 0, 0, 1, 2);

        photo_angle_pushbutton = new QPushButton(tab_4);
        photo_angle_pushbutton->setObjectName(QString::fromUtf8("photo_angle_pushbutton"));

        gridLayout_8->addWidget(photo_angle_pushbutton, 3, 0, 1, 2);

        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_8->addWidget(label_11, 0, 3, 1, 1);

        photo_ok_angle_pushbutton = new QPushButton(tab_4);
        photo_ok_angle_pushbutton->setObjectName(QString::fromUtf8("photo_ok_angle_pushbutton"));

        gridLayout_8->addWidget(photo_ok_angle_pushbutton, 1, 2, 1, 1);

        photo_angle_pushbutton_2 = new QPushButton(tab_4);
        photo_angle_pushbutton_2->setObjectName(QString::fromUtf8("photo_angle_pushbutton_2"));

        gridLayout_8->addWidget(photo_angle_pushbutton_2, 3, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_8);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        photo_x_shift_lineedit1 = new QLineEdit(tab_4);
        photo_x_shift_lineedit1->setObjectName(QString::fromUtf8("photo_x_shift_lineedit1"));

        gridLayout_9->addWidget(photo_x_shift_lineedit1, 1, 0, 1, 2);

        photo_x_shift_lineedit2 = new QLineEdit(tab_4);
        photo_x_shift_lineedit2->setObjectName(QString::fromUtf8("photo_x_shift_lineedit2"));

        gridLayout_9->addWidget(photo_x_shift_lineedit2, 1, 3, 1, 1);

        angle_label_4 = new QLabel(tab_4);
        angle_label_4->setObjectName(QString::fromUtf8("angle_label_4"));

        gridLayout_9->addWidget(angle_label_4, 0, 0, 1, 2);

        photo_x_y_shitft_pushButton = new QPushButton(tab_4);
        photo_x_y_shitft_pushButton->setObjectName(QString::fromUtf8("photo_x_y_shitft_pushButton"));

        gridLayout_9->addWidget(photo_x_y_shitft_pushButton, 4, 0, 1, 2);

        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_9->addWidget(label_12, 0, 3, 1, 1);

        photo_y_shift_lineedit1 = new QLineEdit(tab_4);
        photo_y_shift_lineedit1->setObjectName(QString::fromUtf8("photo_y_shift_lineedit1"));

        gridLayout_9->addWidget(photo_y_shift_lineedit1, 2, 0, 1, 2);

        photo_y_shift_lineedit2 = new QLineEdit(tab_4);
        photo_y_shift_lineedit2->setObjectName(QString::fromUtf8("photo_y_shift_lineedit2"));

        gridLayout_9->addWidget(photo_y_shift_lineedit2, 2, 3, 1, 1);

        photo_ok_x_y_shift_pushButton = new QPushButton(tab_4);
        photo_ok_x_y_shift_pushButton->setObjectName(QString::fromUtf8("photo_ok_x_y_shift_pushButton"));

        gridLayout_9->addWidget(photo_ok_x_y_shift_pushButton, 1, 2, 1, 1);

        photo_x_y_shitft_pushButton_2 = new QPushButton(tab_4);
        photo_x_y_shitft_pushButton_2->setObjectName(QString::fromUtf8("photo_x_y_shitft_pushButton_2"));

        gridLayout_9->addWidget(photo_x_y_shitft_pushButton_2, 4, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_9);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        x_shift_label_2 = new QLabel(tab_4);
        x_shift_label_2->setObjectName(QString::fromUtf8("x_shift_label_2"));
        x_shift_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(x_shift_label_2, 0, 0, 1, 1);

        photo_x_shift_lineEdit = new QLineEdit(tab_4);
        photo_x_shift_lineEdit->setObjectName(QString::fromUtf8("photo_x_shift_lineEdit"));
        photo_x_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_x_shift_lineEdit, 0, 1, 1, 1);

        k_label_2 = new QLabel(tab_4);
        k_label_2->setObjectName(QString::fromUtf8("k_label_2"));
        k_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(k_label_2, 4, 0, 1, 1);

        photo_k_lineEdit = new QLineEdit(tab_4);
        photo_k_lineEdit->setObjectName(QString::fromUtf8("photo_k_lineEdit"));
        photo_k_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_k_lineEdit, 4, 1, 1, 1);

        photo_fi_shift_slider = new QSlider(tab_4);
        photo_fi_shift_slider->setObjectName(QString::fromUtf8("photo_fi_shift_slider"));
        photo_fi_shift_slider->setMaximum(360);
        photo_fi_shift_slider->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(photo_fi_shift_slider, 8, 0, 1, 2);

        photo_y_shift_lineEdit = new QLineEdit(tab_4);
        photo_y_shift_lineEdit->setObjectName(QString::fromUtf8("photo_y_shift_lineEdit"));
        photo_y_shift_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_y_shift_lineEdit, 0, 3, 1, 1);

        y_shift_label_2 = new QLabel(tab_4);
        y_shift_label_2->setObjectName(QString::fromUtf8("y_shift_label_2"));
        y_shift_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(y_shift_label_2, 0, 2, 1, 1);

        photo_x_scale_lineEdit = new QLineEdit(tab_4);
        photo_x_scale_lineEdit->setObjectName(QString::fromUtf8("photo_x_scale_lineEdit"));
        photo_x_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_x_scale_lineEdit, 2, 1, 1, 1);

        x_scale_label_2 = new QLabel(tab_4);
        x_scale_label_2->setObjectName(QString::fromUtf8("x_scale_label_2"));
        x_scale_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(x_scale_label_2, 2, 0, 1, 1);

        y_scale_label_2 = new QLabel(tab_4);
        y_scale_label_2->setObjectName(QString::fromUtf8("y_scale_label_2"));
        y_scale_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(y_scale_label_2, 2, 2, 1, 1);

        photo_y_scale_lineEdit = new QLineEdit(tab_4);
        photo_y_scale_lineEdit->setObjectName(QString::fromUtf8("photo_y_scale_lineEdit"));
        photo_y_scale_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_y_scale_lineEdit, 2, 3, 1, 1);

        fi_label_2 = new QLabel(tab_4);
        fi_label_2->setObjectName(QString::fromUtf8("fi_label_2"));
        fi_label_2->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(fi_label_2, 4, 2, 1, 1);

        photo_fi_lineEdit = new QLineEdit(tab_4);
        photo_fi_lineEdit->setObjectName(QString::fromUtf8("photo_fi_lineEdit"));
        photo_fi_lineEdit->setMinimumSize(QSize(0, 15));

        gridLayout_10->addWidget(photo_fi_lineEdit, 4, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_10);


        gridLayout_11->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_12 = new QGridLayout(tab);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Nk_data_label = new QLabel(tab);
        Nk_data_label->setObjectName(QString::fromUtf8("Nk_data_label"));
        Nk_data_label->setMinimumSize(QSize(0, 15));

        horizontalLayout_3->addWidget(Nk_data_label);

        Nk_lineedit_data = new QLineEdit(tab);
        Nk_lineedit_data->setObjectName(QString::fromUtf8("Nk_lineedit_data"));
        Nk_lineedit_data->setMinimumSize(QSize(0, 15));
        Nk_lineedit_data->setReadOnly(true);

        horizontalLayout_3->addWidget(Nk_lineedit_data);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Nfi_data_label = new QLabel(tab);
        Nfi_data_label->setObjectName(QString::fromUtf8("Nfi_data_label"));
        Nfi_data_label->setMinimumSize(QSize(0, 15));

        horizontalLayout_4->addWidget(Nfi_data_label);

        Nfi_lineedit_data = new QLineEdit(tab);
        Nfi_lineedit_data->setObjectName(QString::fromUtf8("Nfi_lineedit_data"));
        Nfi_lineedit_data->setMinimumSize(QSize(0, 15));
        Nfi_lineedit_data->setReadOnly(true);

        horizontalLayout_4->addWidget(Nfi_lineedit_data);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Fstart_label = new QLabel(tab);
        Fstart_label->setObjectName(QString::fromUtf8("Fstart_label"));
        Fstart_label->setMinimumSize(QSize(0, 15));

        horizontalLayout_5->addWidget(Fstart_label);

        Fstart_lineedit_data = new QLineEdit(tab);
        Fstart_lineedit_data->setObjectName(QString::fromUtf8("Fstart_lineedit_data"));
        Fstart_lineedit_data->setMinimumSize(QSize(0, 15));
        Fstart_lineedit_data->setReadOnly(true);

        horizontalLayout_5->addWidget(Fstart_lineedit_data);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Fstop_data_label = new QLabel(tab);
        Fstop_data_label->setObjectName(QString::fromUtf8("Fstop_data_label"));
        Fstop_data_label->setMinimumSize(QSize(0, 15));

        horizontalLayout_6->addWidget(Fstop_data_label);

        Fstop_lineedit_data = new QLineEdit(tab);
        Fstop_lineedit_data->setObjectName(QString::fromUtf8("Fstop_lineedit_data"));
        Fstop_lineedit_data->setMinimumSize(QSize(0, 15));
        Fstop_lineedit_data->setReadOnly(true);

        horizontalLayout_6->addWidget(Fstop_lineedit_data);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Azstart_data_label = new QLabel(tab);
        Azstart_data_label->setObjectName(QString::fromUtf8("Azstart_data_label"));
        Azstart_data_label->setMinimumSize(QSize(0, 15));

        horizontalLayout_7->addWidget(Azstart_data_label);

        Azstart_lieedit_data = new QLineEdit(tab);
        Azstart_lieedit_data->setObjectName(QString::fromUtf8("Azstart_lieedit_data"));
        Azstart_lieedit_data->setMinimumSize(QSize(0, 15));
        Azstart_lieedit_data->setReadOnly(true);

        horizontalLayout_7->addWidget(Azstart_lieedit_data);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        Azstop_label = new QLabel(tab);
        Azstop_label->setObjectName(QString::fromUtf8("Azstop_label"));
        Azstop_label->setMinimumSize(QSize(0, 15));

        horizontalLayout_8->addWidget(Azstop_label);

        Azstop_lineedit_data = new QLineEdit(tab);
        Azstop_lineedit_data->setObjectName(QString::fromUtf8("Azstop_lineedit_data"));
        Azstop_lineedit_data->setMinimumSize(QSize(0, 15));
        Azstop_lineedit_data->setReadOnly(true);

        horizontalLayout_8->addWidget(Azstop_lineedit_data);


        verticalLayout_4->addLayout(horizontalLayout_8);


        gridLayout_12->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Form_Spectr);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Form_Spectr);
    } // setupUi

    void retranslateUi(QWidget *Form_Spectr)
    {
        Form_Spectr->setWindowTitle(QApplication::translate("Form_Spectr", "Form", 0, QApplication::UnicodeUTF8));
        cont_read_pushButton->setText(QApplication::translate("Form_Spectr", "Cont read", 0, QApplication::UnicodeUTF8));
        read_pushbutton->setText(QApplication::translate("Form_Spectr", "Read", 0, QApplication::UnicodeUTF8));
        scale_checkBox->setText(QApplication::translate("Form_Spectr", "Scale", 0, QApplication::UnicodeUTF8));
        flip_checkBox->setText(QApplication::translate("Form_Spectr", "Flip", 0, QApplication::UnicodeUTF8));
        x_y_scale_label->setText(QApplication::translate("Form_Spectr", "Scale X Y", 0, QApplication::UnicodeUTF8));
        x_y_scale_pushButton->setText(QApplication::translate("Form_Spectr", "Select 1", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        ok_x_y_scale_pushButton->setText(QApplication::translate("Form_Spectr", "<<OK", 0, QApplication::UnicodeUTF8));
        x_y_scale_pushButton_2->setText(QApplication::translate("Form_Spectr", "Select 1", 0, QApplication::UnicodeUTF8));
        angle_label->setText(QApplication::translate("Form_Spectr", "Angle", 0, QApplication::UnicodeUTF8));
        angle_pushbutton->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        ok_angle_pushbutton->setText(QApplication::translate("Form_Spectr", "<<OK", 0, QApplication::UnicodeUTF8));
        angle_pushbutton_2->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        angle_label_2->setText(QApplication::translate("Form_Spectr", "X Y shift", 0, QApplication::UnicodeUTF8));
        x_y_shitft_pushButton->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        ok_x_y_shift_pushButton->setText(QApplication::translate("Form_Spectr", "<<OK", 0, QApplication::UnicodeUTF8));
        x_y_shitft_pushButton_2->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        x_shift_label->setText(QApplication::translate("Form_Spectr", "X  Shift", 0, QApplication::UnicodeUTF8));
        y_shift_label->setText(QApplication::translate("Form_Spectr", "Y  Shift", 0, QApplication::UnicodeUTF8));
        y_shift_lineEdit->setText(QString());
        x_scale_label->setText(QApplication::translate("Form_Spectr", "X  Scale", 0, QApplication::UnicodeUTF8));
        y_scale_label->setText(QApplication::translate("Form_Spectr", "Y  Scale", 0, QApplication::UnicodeUTF8));
        k_label->setText(QApplication::translate("Form_Spectr", "K (+1,-1)", 0, QApplication::UnicodeUTF8));
        fi_label->setText(QApplication::translate("Form_Spectr", "Fi 0", 0, QApplication::UnicodeUTF8));
        fi_shift_label->setText(QApplication::translate("Form_Spectr", "                         Fi shift", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form_Spectr", "Sketch", 0, QApplication::UnicodeUTF8));
        photo_enable_checkBox->setText(QApplication::translate("Form_Spectr", "Enable", 0, QApplication::UnicodeUTF8));
        x_y_scale_label_2->setText(QApplication::translate("Form_Spectr", "Scale X Y", 0, QApplication::UnicodeUTF8));
        photo_x_y_scale_pushButton->setText(QApplication::translate("Form_Spectr", "Select 1", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        photo_ok_x_y_scale_pushButton->setText(QApplication::translate("Form_Spectr", "<<OK", 0, QApplication::UnicodeUTF8));
        photo_x_y_scale_pushButton_2->setText(QApplication::translate("Form_Spectr", "Select 1", 0, QApplication::UnicodeUTF8));
        angle_label_3->setText(QApplication::translate("Form_Spectr", "Angle", 0, QApplication::UnicodeUTF8));
        photo_angle_pushbutton->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        photo_ok_angle_pushbutton->setText(QApplication::translate("Form_Spectr", "OK", 0, QApplication::UnicodeUTF8));
        photo_angle_pushbutton_2->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        angle_label_4->setText(QApplication::translate("Form_Spectr", "X Y shift", 0, QApplication::UnicodeUTF8));
        photo_x_y_shitft_pushButton->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        photo_ok_x_y_shift_pushButton->setText(QApplication::translate("Form_Spectr", "OK", 0, QApplication::UnicodeUTF8));
        photo_x_y_shitft_pushButton_2->setText(QApplication::translate("Form_Spectr", "Select", 0, QApplication::UnicodeUTF8));
        x_shift_label_2->setText(QApplication::translate("Form_Spectr", "X  Shift", 0, QApplication::UnicodeUTF8));
        k_label_2->setText(QApplication::translate("Form_Spectr", "K (+1,-1)", 0, QApplication::UnicodeUTF8));
        photo_y_shift_lineEdit->setText(QString());
        y_shift_label_2->setText(QApplication::translate("Form_Spectr", "Y  Shift", 0, QApplication::UnicodeUTF8));
        x_scale_label_2->setText(QApplication::translate("Form_Spectr", "X  Scale", 0, QApplication::UnicodeUTF8));
        y_scale_label_2->setText(QApplication::translate("Form_Spectr", "Y  Scale", 0, QApplication::UnicodeUTF8));
        fi_label_2->setText(QApplication::translate("Form_Spectr", "Fi 0", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Form_Spectr", "Photo", 0, QApplication::UnicodeUTF8));
        Nk_data_label->setText(QApplication::translate("Form_Spectr", "N k", 0, QApplication::UnicodeUTF8));
        Nfi_data_label->setText(QApplication::translate("Form_Spectr", "N fi", 0, QApplication::UnicodeUTF8));
        Fstart_label->setText(QApplication::translate("Form_Spectr", "F start", 0, QApplication::UnicodeUTF8));
        Fstop_data_label->setText(QApplication::translate("Form_Spectr", "F stop ", 0, QApplication::UnicodeUTF8));
        Fstop_lineedit_data->setText(QString());
        Azstart_data_label->setText(QApplication::translate("Form_Spectr", "Az start", 0, QApplication::UnicodeUTF8));
        Azstop_label->setText(QApplication::translate("Form_Spectr", "Az stop", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form_Spectr", "\320\224\320\260\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form_Spectr: public Ui_Form_Spectr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SPECTR_H

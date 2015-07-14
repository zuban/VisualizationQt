/********************************************************************************
** Form generated from reading UI file 'spectrwidget.ui'
**
** Created: Fri 10. Apr 15:39:56 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTRWIDGET_H
#define UI_SPECTRWIDGET_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpectrWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
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
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpinBox *max_spinbox;
    QDoubleSpinBox *min_spinbox;
    QLabel *label_4;
    QPushButton *delete_last_pushButton;
    QPushButton *delete_sketch_pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SpectrWidget)
    {
        if (SpectrWidget->objectName().isEmpty())
            SpectrWidget->setObjectName(QString::fromUtf8("SpectrWidget"));
        SpectrWidget->resize(1966, 1316);
        gridLayout = new QGridLayout(SpectrWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        type_combobox = new QComboBox(SpectrWidget);
        type_combobox->setObjectName(QString::fromUtf8("type_combobox"));
        type_combobox->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(type_combobox);

        spec_type_combobox = new QComboBox(SpectrWidget);
        spec_type_combobox->setObjectName(QString::fromUtf8("spec_type_combobox"));
        spec_type_combobox->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(spec_type_combobox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rect_pushButton = new QPushButton(SpectrWidget);
        rect_pushButton->setObjectName(QString::fromUtf8("rect_pushButton"));
        rect_pushButton->setMinimumSize(QSize(30, 30));
        rect_pushButton->setCheckable(true);

        horizontalLayout->addWidget(rect_pushButton);

        polygon_pushButton = new QPushButton(SpectrWidget);
        polygon_pushButton->setObjectName(QString::fromUtf8("polygon_pushButton"));
        polygon_pushButton->setMinimumSize(QSize(30, 30));
        polygon_pushButton->setCheckable(true);

        horizontalLayout->addWidget(polygon_pushButton);

        line_pushButton = new QPushButton(SpectrWidget);
        line_pushButton->setObjectName(QString::fromUtf8("line_pushButton"));
        line_pushButton->setMinimumSize(QSize(30, 30));
        line_pushButton->setCheckable(true);

        horizontalLayout->addWidget(line_pushButton);

        color_comboBox = new QComboBox(SpectrWidget);
        color_comboBox->setObjectName(QString::fromUtf8("color_comboBox"));
        color_comboBox->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(color_comboBox);

        sketch_checkBox = new QCheckBox(SpectrWidget);
        sketch_checkBox->setObjectName(QString::fromUtf8("sketch_checkBox"));
        sketch_checkBox->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(sketch_checkBox);

        zoom_pushButton = new QPushButton(SpectrWidget);
        zoom_pushButton->setObjectName(QString::fromUtf8("zoom_pushButton"));
        zoom_pushButton->setMinimumSize(QSize(30, 30));
        zoom_pushButton->setCheckable(true);

        horizontalLayout->addWidget(zoom_pushButton);

        select_point_pushButton = new QPushButton(SpectrWidget);
        select_point_pushButton->setObjectName(QString::fromUtf8("select_point_pushButton"));
        select_point_pushButton->setMinimumSize(QSize(30, 30));
        select_point_pushButton->setCheckable(true);

        horizontalLayout->addWidget(select_point_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        progressBar = new QProgressBar(SpectrWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximumSize(QSize(100, 16777215));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        lineEdit = new QLineEdit(SpectrWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(lineEdit);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(SpectrWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        max_spinbox = new QSpinBox(SpectrWidget);
        max_spinbox->setObjectName(QString::fromUtf8("max_spinbox"));
        max_spinbox->setMinimum(1);
        max_spinbox->setMaximum(1000);
        max_spinbox->setSingleStep(10);
        max_spinbox->setValue(1);

        gridLayout_2->addWidget(max_spinbox, 0, 1, 1, 1);

        min_spinbox = new QDoubleSpinBox(SpectrWidget);
        min_spinbox->setObjectName(QString::fromUtf8("min_spinbox"));
        min_spinbox->setMinimum(-900);
        min_spinbox->setMaximum(0);

        gridLayout_2->addWidget(min_spinbox, 1, 1, 1, 1);

        label_4 = new QLabel(SpectrWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        delete_last_pushButton = new QPushButton(SpectrWidget);
        delete_last_pushButton->setObjectName(QString::fromUtf8("delete_last_pushButton"));
        delete_last_pushButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(delete_last_pushButton);

        delete_sketch_pushButton = new QPushButton(SpectrWidget);
        delete_sketch_pushButton->setObjectName(QString::fromUtf8("delete_sketch_pushButton"));
        delete_sketch_pushButton->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(delete_sketch_pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SpectrWidget);

        QMetaObject::connectSlotsByName(SpectrWidget);
    } // setupUi

    void retranslateUi(QWidget *SpectrWidget)
    {
        SpectrWidget->setWindowTitle(QApplication::translate("SpectrWidget", "Form", 0, QApplication::UnicodeUTF8));
        type_combobox->clear();
        type_combobox->insertItems(0, QStringList()
         << QApplication::translate("SpectrWidget", "Ampl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "Phase", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "Re", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "Im", 0, QApplication::UnicodeUTF8)
        );
        spec_type_combobox->clear();
        spec_type_combobox->insertItems(0, QStringList()
         << QApplication::translate("SpectrWidget", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "Transparent", 0, QApplication::UnicodeUTF8)
        );
        rect_pushButton->setText(QApplication::translate("SpectrWidget", "Rect", 0, QApplication::UnicodeUTF8));
        polygon_pushButton->setText(QApplication::translate("SpectrWidget", "Polygon", 0, QApplication::UnicodeUTF8));
        line_pushButton->setText(QApplication::translate("SpectrWidget", "Line", 0, QApplication::UnicodeUTF8));
        color_comboBox->clear();
        color_comboBox->insertItems(0, QStringList()
         << QApplication::translate("SpectrWidget", "cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkCyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkRed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "magenta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkMagenta", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkGreen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "yellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkYellow", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkBlue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "gray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "darkGray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpectrWidget", "lightGray", 0, QApplication::UnicodeUTF8)
        );
        sketch_checkBox->setText(QApplication::translate("SpectrWidget", "Sketch", 0, QApplication::UnicodeUTF8));
        zoom_pushButton->setText(QApplication::translate("SpectrWidget", "Zoomer", 0, QApplication::UnicodeUTF8));
        select_point_pushButton->setText(QApplication::translate("SpectrWidget", "Select Point", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpectrWidget", "Spectr", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SpectrWidget", "Spectr", 0, QApplication::UnicodeUTF8));
        delete_last_pushButton->setText(QApplication::translate("SpectrWidget", "Delete item", 0, QApplication::UnicodeUTF8));
        delete_sketch_pushButton->setText(QApplication::translate("SpectrWidget", "Delete sketch", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpectrWidget: public Ui_SpectrWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTRWIDGET_H

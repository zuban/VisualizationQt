/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Tue 14. Jul 17:47:30 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *export_pushButton;
    QVBoxLayout *verticalLayout_2;
    QPushButton *test_cuda_pushButton;
    QLineEdit *test_row_column_lineEdit;
    QRadioButton *test_col_radioButton;
    QRadioButton *test_row_radioButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(590, 526);
        horizontalLayout_2 = new QHBoxLayout(Form);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        export_pushButton = new QPushButton(groupBox);
        export_pushButton->setObjectName(QString::fromUtf8("export_pushButton"));
        export_pushButton->setMinimumSize(QSize(60, 45));

        verticalLayout->addWidget(export_pushButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        test_cuda_pushButton = new QPushButton(groupBox);
        test_cuda_pushButton->setObjectName(QString::fromUtf8("test_cuda_pushButton"));
        test_cuda_pushButton->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(test_cuda_pushButton);

        test_row_column_lineEdit = new QLineEdit(groupBox);
        test_row_column_lineEdit->setObjectName(QString::fromUtf8("test_row_column_lineEdit"));
        test_row_column_lineEdit->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(test_row_column_lineEdit);

        test_col_radioButton = new QRadioButton(groupBox);
        test_col_radioButton->setObjectName(QString::fromUtf8("test_col_radioButton"));
        test_col_radioButton->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(test_col_radioButton);

        test_row_radioButton = new QRadioButton(groupBox);
        test_row_radioButton->setObjectName(QString::fromUtf8("test_row_radioButton"));
        test_row_radioButton->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(test_row_radioButton);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Form", "2D Graphics", 0, QApplication::UnicodeUTF8));
        export_pushButton->setText(QApplication::translate("Form", "Export", 0, QApplication::UnicodeUTF8));
        test_cuda_pushButton->setText(QApplication::translate("Form", "Update data", 0, QApplication::UnicodeUTF8));
        test_col_radioButton->setText(QApplication::translate("Form", "Columns", 0, QApplication::UnicodeUTF8));
        test_row_radioButton->setText(QApplication::translate("Form", "Rows", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

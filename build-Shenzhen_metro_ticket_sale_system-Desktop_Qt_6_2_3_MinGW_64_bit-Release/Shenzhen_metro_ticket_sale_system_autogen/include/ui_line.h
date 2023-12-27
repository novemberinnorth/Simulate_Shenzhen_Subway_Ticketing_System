/********************************************************************************
** Form generated from reading UI file 'line.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINE_H
#define UI_LINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Line
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Line)
    {
        if (Line->objectName().isEmpty())
            Line->setObjectName(QString::fromUtf8("Line"));
        Line->resize(1440, 810);
        pushButton = new QPushButton(Line);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 740, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(186, 0, 3);\n"
"border-radius:5px"));
        pushButton_2 = new QPushButton(Line);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1059, 740, 91, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(29, 139, 23);\n"
"border-radius:5px"));

        retranslateUi(Line);

        QMetaObject::connectSlotsByName(Line);
    } // setupUi

    void retranslateUi(QWidget *Line)
    {
        Line->setWindowTitle(QCoreApplication::translate("Line", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Line", "\350\277\224\345\233\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Line", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Line: public Ui_Line {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINE_H

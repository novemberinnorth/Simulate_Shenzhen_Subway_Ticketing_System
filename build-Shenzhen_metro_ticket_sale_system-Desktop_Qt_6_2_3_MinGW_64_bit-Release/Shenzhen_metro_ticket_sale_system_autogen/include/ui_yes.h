/********************************************************************************
** Form generated from reading UI file 'yes.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YES_H
#define UI_YES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yes
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *yes)
    {
        if (yes->objectName().isEmpty())
            yes->setObjectName(QString::fromUtf8("yes"));
        yes->resize(900, 600);
        textBrowser = new QTextBrowser(yes);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(250, 150, 400, 300));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgb(240, 240, 240);\n"
"border-color: rgb(240, 240, 240);"));
        pushButton = new QPushButton(yes);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 500, 200, 50));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"font: 290 16pt \"Microsoft YaHei\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(186, 0, 3);\n"
"border-radius:5px;"));
        pushButton_2 = new QPushButton(yes);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 500, 200, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"font: 290 16pt \"Microsoft YaHei\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(78, 21, 221);\n"
"border-radius:5px;"));

        retranslateUi(yes);

        QMetaObject::connectSlotsByName(yes);
    } // setupUi

    void retranslateUi(QWidget *yes)
    {
        yes->setWindowTitle(QCoreApplication::translate("yes", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("yes", "\350\277\224\345\233\236\346\224\266\351\223\266\345\217\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("yes", "\350\277\224\345\233\236\346\254\242\350\277\216\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yes: public Ui_yes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YES_H

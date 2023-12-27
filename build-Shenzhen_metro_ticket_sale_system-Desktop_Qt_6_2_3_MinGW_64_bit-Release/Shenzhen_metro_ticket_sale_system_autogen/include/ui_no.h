/********************************************************************************
** Form generated from reading UI file 'no.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NO_H
#define UI_NO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_no
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *no)
    {
        if (no->objectName().isEmpty())
            no->setObjectName(QString::fromUtf8("no"));
        no->resize(900, 600);
        textBrowser = new QTextBrowser(no);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(250, 150, 400, 300));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgb(240, 240, 240);\n"
"border-color: rgb(240, 240, 240);"));
        pushButton = new QPushButton(no);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 500, 200, 50));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"font: 290 16pt \"Microsoft YaHei\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(186, 0, 3);\n"
"border-radius:5px;"));

        retranslateUi(no);

        QMetaObject::connectSlotsByName(no);
    } // setupUi

    void retranslateUi(QWidget *no)
    {
        no->setWindowTitle(QCoreApplication::translate("no", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("no", "\350\277\224\345\233\236\346\224\266\351\223\266\345\217\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class no: public Ui_no {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NO_H

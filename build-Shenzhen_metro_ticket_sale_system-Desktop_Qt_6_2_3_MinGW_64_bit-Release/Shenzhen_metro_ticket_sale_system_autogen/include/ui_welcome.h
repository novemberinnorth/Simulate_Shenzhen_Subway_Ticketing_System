/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->resize(600, 600);
        label = new QLabel(Welcome);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -10, 601, 611));
        label->setPixmap(QPixmap(QString::fromUtf8("../welcome_background.jpg")));
        label->setScaledContents(true);
        label->setWordWrap(true);
        label_2 = new QLabel(Welcome);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 170, 371, 51));
        label_2->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"border-radius:5px;"));
        pushButton = new QPushButton(Welcome);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 280, 151, 41));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(78, 21, 221);\n"
"border-radius:5px;"));
        pushButton_2 = new QPushButton(Welcome);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 370, 151, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(184, 1, 4);\n"
"border-radius:5px;"));
        label_3 = new QLabel(Welcome);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 440, 281, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(0,0,0);\n"
"color:rgb(255,255,255);\n"
"border-radius:5px;"));
        label_4 = new QLabel(Welcome);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 490, 261, 31));
        label_4->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,0);\n"
"color:rgb(255,255,255)\n"
";\n"
"border-radius:5px;"));
        label_5 = new QLabel(Welcome);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 100, 351, 61));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Cache_-2402b251b536af3f..jpg")));
        label_5->setScaledContents(true);

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "Widget", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Welcome", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt; font-weight:700; color:#4f2ac8;\">\346\250\241\346\213\237\346\267\261\345\234\263\345\234\260\351\223\201\345\224\256\347\245\250\347\263\273\347\273\237</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Welcome", "\345\274\200\345\247\213\350\264\255\347\245\250", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Welcome", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("Welcome", "\344\275\234\350\200\205\357\274\232\350\207\252\345\212\250\345\214\226\344\272\214\347\217\255 220320221 \345\270\270\344\274\257\347\254\246", nullptr));
        label_4->setText(QCoreApplication::translate("Welcome", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">email: citcra@foxmail.com</span></p></body></html>", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H

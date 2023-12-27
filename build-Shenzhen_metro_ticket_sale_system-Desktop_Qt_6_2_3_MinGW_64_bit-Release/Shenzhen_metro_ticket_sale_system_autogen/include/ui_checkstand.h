/********************************************************************************
** Form generated from reading UI file 'checkstand.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKSTAND_H
#define UI_CHECKSTAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkstand
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *Checkstand)
    {
        if (Checkstand->objectName().isEmpty())
            Checkstand->setObjectName(QString::fromUtf8("Checkstand"));
        Checkstand->resize(900, 600);
        pushButton = new QPushButton(Checkstand);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 540, 141, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(186, 0, 3);\n"
"border-radius:5px;"));
        pushButton_2 = new QPushButton(Checkstand);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 540, 141, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";\n"
"color:rgb(255, 255, 255);\n"
"background-color:rgb(29, 139, 23);\n"
"border-radius:5px;"));
        spinBox = new QSpinBox(Checkstand);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(210, 190, 201, 41));
        textBrowser = new QTextBrowser(Checkstand);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(460, 190, 256, 192));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgb(240, 240, 240);\n"
"border-color: rgb(240, 240, 240);"));
        textBrowser_2 = new QTextBrowser(Checkstand);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(200, 70, 521, 71));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color:rgb(240, 240, 240);\n"
"border-color: rgb(240, 240, 240);"));
        label = new QLabel(Checkstand);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 190, 161, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Checkstand);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 440, 151, 40));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        doubleSpinBox = new QDoubleSpinBox(Checkstand);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(200, 430, 531, 71));

        retranslateUi(Checkstand);

        QMetaObject::connectSlotsByName(Checkstand);
    } // setupUi

    void retranslateUi(QWidget *Checkstand)
    {
        Checkstand->setWindowTitle(QCoreApplication::translate("Checkstand", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Checkstand", "\346\210\221\345\206\215\346\203\263\346\203\263", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Checkstand", "\347\253\213\345\215\263\346\224\257\344\273\230", nullptr));
        label->setText(QCoreApplication::translate("Checkstand", "\351\200\211\346\213\251\344\272\272\346\225\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Checkstand", "\350\276\223\345\205\245\351\207\221\351\242\235\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Checkstand: public Ui_Checkstand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKSTAND_H

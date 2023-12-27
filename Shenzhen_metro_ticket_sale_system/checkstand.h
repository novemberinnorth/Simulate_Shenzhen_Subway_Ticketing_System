#ifndef CHECKSTAND_H
#define CHECKSTAND_H

#include <QWidget>
#include"yes.h"
#include"no.h"

namespace Ui {
class Checkstand;
}

class Checkstand : public QWidget
{
    Q_OBJECT

public:
    explicit Checkstand(QWidget *parent = nullptr);
    ~Checkstand();
    yes w4;
    no w5;
signals:
    void return_to_line();
    void sendminus(double m);

private slots:
    void on_pushButton_clicked();
    void receiveprice(int p);

    void on_spinBox_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_pushButton_2_clicked();

    void return_from_no();
    void return_from_yes();
private:
    Ui::Checkstand *ui;
};

#endif // CHECKSTAND_H

#ifndef YES_H
#define YES_H

#include <QWidget>
namespace Ui {
class yes;
}

class yes : public QWidget
{
    Q_OBJECT

public:
    explicit yes(QWidget *parent = nullptr);
    ~yes();
    double minus;
signals:
    void return_to_checkstand();
    //void return_to_welcome();
private slots:
    void receiveminus(double m);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::yes *ui;
};

#endif // YES_H

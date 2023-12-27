#ifndef NO_H
#define NO_H

#include <QWidget>

namespace Ui {
class no;
}

class no : public QWidget
{
    Q_OBJECT

public:
    explicit no(QWidget *parent = nullptr);
    ~no();
    double minus;
signals:
    void return_to_checkstand();
private slots:
    void receiveminus(double m);
    void on_pushButton_clicked();

private:
    Ui::no *ui;
};

#endif // NO_H

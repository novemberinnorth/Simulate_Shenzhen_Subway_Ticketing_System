#ifndef WELCOME_H
#define WELCOME_H
#include <QWidget>
#include "map.h"
//#include "yes.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Welcome; }
QT_END_NAMESPACE

class Welcome : public QWidget
{
    Q_OBJECT

public:
    Welcome(QWidget *parent = nullptr);
    ~Welcome();
    void showMap();
    void return_from_map();
    //void return_from_yes();

signals:

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


public:
    Map w1;
    //yes w4;
private:
    Ui::Welcome *ui;
};
#endif // WIDGET_H

#include "no.h"
#include "ui_no.h"

no::no(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::no)
{
    ui->setupUi(this);
}

no::~no()
{
    delete ui;
}

void no::on_pushButton_clicked()
{
    emit return_to_checkstand();
}

void no::receiveminus(double m){
    minus=m;
    ui->textBrowser->setText("<h1 align=center><font face=Microsoft YaHei><font color=red><b>支付失败</b></font></h1>"
                             "<h1 align=center><font face=Microsoft YaHei><font color=black><b>仍需支付："+QString::number(minus)+"元</b></font></h1>");
}

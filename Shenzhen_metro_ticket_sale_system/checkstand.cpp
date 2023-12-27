//收银台
#include "checkstand.h"
#include "ui_checkstand.h"
int multiple=1,price=0,total=0;
double input=0;
Checkstand::Checkstand(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Checkstand)
{
    ui->setupUi(this);
    connect(&w4,SIGNAL(return_to_checkstand()),this,SLOT(return_from_yes()));
    connect(&w5,SIGNAL(return_to_checkstand()),this,SLOT(return_from_no()));
}

Checkstand::~Checkstand()
{
    delete ui;
}

void Checkstand::on_pushButton_clicked()
{
    emit return_to_line();
}

void Checkstand::receiveprice(int p){
    //qDebug().noquote()<<p;
    price=p;
    total=multiple*price;
    ui->spinBox->setMinimum(1);
    ui->spinBox->setSingleStep(1);
    ui->spinBox->setMaximum(10000);
    ui->textBrowser_2->setText("<h1 align=center><font face=Microsoft YaHei><font color=black><b>当前选择方案的金额："+QString::number(price)+"</b></font></h1>");
    ui->textBrowser->setText("<h1 align=center><font face=Microsoft YaHei><font color=black><b>总价："+QString::number(total)+"</b></font></h1>");
    ui->doubleSpinBox->setMinimum(0.0);
    ui->doubleSpinBox->setSingleStep(1);
    ui->doubleSpinBox->setMaximum(100000.0);
}

void Checkstand::on_spinBox_valueChanged(int arg1)
{
    multiple=arg1;
    total=multiple*price;
    ui->textBrowser->setText("<h1 align=center><font face=Microsoft YaHei><font color=black><b>总价："+QString::number(total)+"</b></font></h1>");
}


void Checkstand::on_doubleSpinBox_valueChanged(double arg1)
{
    input=arg1;
}


void Checkstand::on_pushButton_2_clicked()
{
    this->hide();
    double temp=input-total;
    if(temp<0){
        connect(this,SIGNAL(sendminus(double)),&w5,SLOT(receiveminus(double)));
        emit sendminus(temp*(-1));
        w5.show();
    }else{
        connect(this,SIGNAL(sendminus(double)),&w4,SLOT(receiveminus(double)));
        emit sendminus(temp);
        w4.show();
    }
}

void Checkstand::return_from_yes(){
    w4.hide();
    this->show();
}
void Checkstand::return_from_no(){
    w5.hide();
    this->show();
}

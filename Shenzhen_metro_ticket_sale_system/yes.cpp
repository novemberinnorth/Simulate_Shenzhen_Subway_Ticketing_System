#include "yes.h"
#include "ui_yes.h"

yes::yes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::yes)
{
    ui->setupUi(this);
}

yes::~yes()
{
    delete ui;
}

void yes::on_pushButton_clicked()
{
    emit return_to_checkstand();
}


void yes::on_pushButton_2_clicked()
{
    //emit return_to_welcome();
    for(auto w:QApplication::allWidgets()){
        //qDebug().noquote()<<w->windowTitle();
        if(w->windowTitle()=="Widget"&&w->isWindow()){
            this->close();
            w->show();
            break;
        }
    }
}

void yes::receiveminus(double m){
    minus=m;
    ui->textBrowser->setText("<h1 align=center><font face=Microsoft YaHei><font color=green><b>支付成功</b></font></h1>"
                             "<h1 align=center><font face=Microsoft YaHei><font color=black>找零："+QString::number(minus)+"元<b></b></font></h1>"
                             "<h1 align=center><font face=Microsoft YaHei><font color=black><b>感谢您的使用！</b></font></h1>");
}

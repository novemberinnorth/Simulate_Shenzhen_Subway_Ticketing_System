//欢迎界面
#include "welcome.h"
#include "./ui_welcome.h"

Welcome::Welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
    //w1.resize(1440,810);
    connect(&w1,&Map::return_to_welcome,this,&Welcome::return_from_map);
    QPixmap pixmap("welcome_background.jpg");
    ui->label->setPixmap(pixmap);
    //connect(&w4,&yes::return_to_welcome,this,&Welcome::return_from_yes);
}

Welcome::~Welcome()
{
    delete ui;
}


void Welcome::on_pushButton_clicked()
{
    this->hide();
    w1.show();
}


void Welcome::on_pushButton_2_clicked()
{
    this->close();
}

void Welcome::return_from_map()
{
    w1.hide();
    this->show();
}

// void Welcome::return_from_yes(){
//     w4.hide();
//     this->show();
// }

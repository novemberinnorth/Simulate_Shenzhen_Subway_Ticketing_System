//显示所有可用的线路
#include"map.h"
#include "line.h"
#include "ui_line.h"
#include<string>
#include<QAction>
#include<QDebug>
#include<QLabel>
#include<QBrush>
#include<QPainter>
#include<QPen>
#include<QPaintEvent>
#include<QPointF>
#include<QPushButton>
#include<QRadioButton>
#include<QButtonGroup>
#include<QLineEdit>
#include<QMouseEvent>
#define button_area_height 700//按钮组区域的高度
#define button_x 70//按钮左上角的横坐标
#define button_size 40//按钮的最大直径
#define line_sx 340//线路开始的横坐标
#define line_tx 1300//线路结束的横坐标
#define line_width 10//线路宽度
using namespace std;
//const int length=line_tx-line_sx;
void Line::Transfer_searcher(int l){//检索线路可换乘到的线路，若检索到目标线路则填写换乘信息并结束主函数的while循环
    //cout<<l<<endl;
    for(int i=0;i!=35;++i){
        for(int j=0;j!=3;++j){
            if(transfer_matrix[l][i][j]!=0){
                for(int k=0;k!=4;++k){
                    if((terminal_line_array[k]!=0)&&(transfer_matrix[l][i][j]==terminal_line_array[k])){
                        transfer_line_matrix[0][counttlm[0]][0]=terminal_line_array[k];//填入该终点线路
                        transfer_line_matrix[0][counttlm[0]][1]=l;//填入被查找的线路
                        transfer_station_matrix[0][counttlm[0]][0]=terminalstation;//在每一行开头填入终点站
                        transfer_station_matrix[0][counttlm[0]][1]=i;//填入最后一个换乘站
                        ++counttlm[0];//到下一行
                        found=1;
                    }
                }
            }
        }
    }
}
void Line::Transfer_restorer(int l,int r1,int r2){//检索待还原线路的上一级线路并填写信息
    for(int i=0;i!=35;++i){
        for(int j=0;j!=3;++j){
            if((transfer_matrix[l][i][j]!=0)&&(transfer_matrix[l][i][j]==temp)){
                for(int k=0;k<=r1;++k){
                    transfer_line_matrix[r1][counttlm[r1]][k]=transfer_line_matrix[r1-1][r2][k];//复制前r1+1个元素到新的一行上
                    transfer_station_matrix[r1][counttlm[r1]][k]=transfer_station_matrix[r1-1][r2][k];
                }
                transfer_line_matrix[r1][counttlm[r1]][r1+1]=l;
                transfer_station_matrix[r1][counttlm[r1]][r1+1]=i;
                ++counttlm[r1];//到下一行
            }
        }
    }
}
int Line::station_searcher(string s,int l){//给定线路上给定站点名的站点坐标
    for(int i=0;i!=35;++i){
        if(name_matrix[l][i][0]==s){
            return i;
        }
    }
    return -1;
}
void Line::Pushback(int p){//模拟入栈
    for(int i=0;i!=18;++i){
        if(transfer_line_matrix_temp[counttlmt][i]==0){
            transfer_line_matrix_temp[counttlmt][i]=p;
            break;
        }
    }
}
inline void Line::Swap(int *a,int *b){//交换
    int t=*a;
    *a=*b;
    *b=t;
}
void Line::Global_variable_reset(){//重置全局变量
    startstation=terminalstation=temp=found=countsl=countstation=0;
    sorted=counttlmt=1;
    mincs=1000;
    ss=ts="";
    for(int i=0;i!=4;++i){
        terminal_line_array[i]=0;
        sameline[i]=0;
        cs[i]=0;
    }
    for(int i=0;i!=10;++i){
        counttlm[i]=0;
        for(int j=0;j!=40;++j){
            price[j]=0;
            for(int k=0;k!=10;++k){
                transfer_line_matrix[i][j][k]=transfer_station_matrix[i][j][k]=0;
            }
        }
        for(int j=0;j!=18;++j){
            transfer_line_matrix_temp[i][j]=0;
            checklist[j]=0;
        }
    }
}
void Line::Input_station(){//将用户输入的站台名转化为矩阵坐标
    //cin>>ss>>ts;
    bool b1=1,b2=1;
    for(int i=0;i!=18;++i){
        for(int j=0;j!=35;++j){
            if(b1&&(ss==name_matrix[i][j][0])){
                startstation=j;
                transfer_line_matrix_temp[0][0]=i;
                checklist[i]=1;
                for(int k=0;k!=3;++k){
                    transfer_line_matrix_temp[0][k+1]=transfer_matrix[i][j][k];
                    checklist[transfer_matrix[i][j][k]]=1;
                }
                b1=0;
            }
            if(b2&&(ts==name_matrix[i][j][0])){
                terminalstation=j;
                terminal_line_array[0]=i;
                for(int k=0;k!=3;++k){
                    terminal_line_array[k+1]=transfer_matrix[i][j][k];
                }
                b2=0;
            }
        }
    }
}
void Line::calmain(){//核心计算代码
    Input_station();
    for(int i=0;i!=4;++i){
        for(int j=0;j!=4;++j){
            if((transfer_line_matrix_temp[0][i]!=0)&&(terminal_line_array[j]!=0)&&(transfer_line_matrix_temp[0][i]==terminal_line_array[j])){
                sameline[countsl]=terminal_line_array[j];
                ++countsl;
            }
        }
    }
    if(sameline[0]!=0){//始末站在同一条线上
        for(int i=0;i!=countsl;++i){
            for(int j=0;j!=35;++j){
                if(name_matrix[sameline[i]][j][0]==ss){//转换坐标
                    startstation=j;
                }
                if(name_matrix[sameline[i]][j][0]==ts){
                    terminalstation=j;
                }
            }
            price[i]=((terminalstation!=startstation)?(2+((terminalstation-startstation)*(((terminalstation-startstation)>=0)?1:-1))/4):0);
        }
        while(sorted){//冒泡排序
            sorted=0;
            for(int i=1;i!=countsl;++i){
                if((price[i]!=0)&&(price[i]<price[i-1])){
                    sorted=1;
                    Swap(&price[i],&price[i-1]);
                    Swap(&sameline[i],&sameline[i-1]);
                }
            }
        }
        area=button_area_height/countsl;
        diameter=(area>=button_size?button_size:area);
        for(int i=0;i!=countsl;++i){
            // //cout<<name_matrix[sameline[i]][0][0]<<":"<<ts<<" 价格："<<price[i]<<endl;
            // qDebug().noquote()<<QString::fromStdString(name_matrix[sameline[i]][0][0])
            //                    <<QString::fromStdString(":")
            //                    <<QString::fromStdString(" 价格：")
            //                    <<price[i];
            QRadioButton* button=new QRadioButton(this);
            button->setGeometry(button_x,(area*(i+0.5))-button_size/2,line_sx-button_x,diameter);
            button->setStyleSheet("QRadioButton::indicator{width:"+QString::number(diameter)+"px;height:"+QString::number(diameter)+"px;color:green}"
                                   "QRadioButton{font-weight:bold;font-size:"+QString::number(diameter/2)+"px;font-family:\"Microsoft YaHei\";"
                                   "color:black;spacing:"+QString::number(diameter)+"px;}");
            button->setText("方案"+QString::number(i+1)+"：共需"+QString::number(price[i])+"元 ");
            Line_Button->addButton(button,i);
            if(i==0){//默认选择第一个方案
                button->setChecked(true);
            }
        }
    }else{
        while(1){//填写广优展开的换乘线路直到找到目标换乘线路
            for(int i=0;i!=18;++i){
                if(transfer_line_matrix_temp[counttlmt-1][i]!=0){//找到目标换乘线路
                    Transfer_searcher(transfer_line_matrix_temp[counttlmt-1][i]);
                }
            }
            if(found){
                break;//退出while
            }
            for(int i=0;i!=18;++i){//否则，逐个展开当前transfer_line_matrix_temp这一行的换乘线路的所有可换乘线路
                if(transfer_line_matrix_temp[counttlmt-1][i]!=0){
                    for(int j=0;j!=35;++j){
                        for(int k=0;k!=3;++k){
                            if((transfer_matrix[transfer_line_matrix_temp[counttlmt-1][i]][j][k]!=0)&&(!checklist[transfer_matrix[transfer_line_matrix_temp[counttlmt-1][i]][j][k]])){//避免出现死循环
                                Pushback(transfer_matrix[transfer_line_matrix_temp[counttlmt-1][i]][j][k]);
                                checklist[transfer_matrix[transfer_line_matrix_temp[counttlmt-1][i]][j][k]]=1;
                            }
                        }
                    }
                }
            }
            ++counttlmt;//步进至transfer_line_matrix_temp的下一行
        }
        for(int i=1;i!=counttlmt;++i){//还原广优展开的中转线路和中转站
            for(int j=0;j!=counttlm[i-1];++j){
                temp=transfer_line_matrix[i-1][j][i];//取每一行末端元素为待还原线路
                for(int k=0;k!=18;++k){
                    if(transfer_line_matrix_temp[counttlmt-i-1][k]!=0){
                        Transfer_restorer(transfer_line_matrix_temp[counttlmt-i-1][k],i,j);//检索transfer_line_matrix_temp的对应行中可换乘到temp的线路
                    }
                }
            }
        }
        for(int i=0;i!=counttlm[counttlmt-1];++i){
            transfer_line_matrix[counttlmt-1][i][counttlmt+1]=transfer_line_matrix[counttlmt-1][i][counttlmt];//在transfer_line_matrix末端补上始发线路（与倒数第二条线路一致）
            transfer_station_matrix[counttlmt-1][i][counttlmt+1]=startstation;//在transfer_station_matrix末端补上始发站
            transfer_station_matrix[counttlmt-1][i][0]=station_searcher(ts,transfer_line_matrix[counttlmt-1][i][0]);
        }
        for(int i=0;i!=counttlm[counttlmt-1];++i){//计算每一种换乘线路的价格
            for(int j=1;j<=counttlmt+1;++j){
                for(int k=0;k!=35;++k){
                    if(name_matrix[transfer_line_matrix[counttlmt-1][i][j]][transfer_station_matrix[counttlmt-1][i][j]][0]==name_matrix[transfer_line_matrix[counttlmt-1][i][j-1]][k][0]){//将transfer_line_matrix[counttlmt-1][i][j]的车站坐标转为transfer_line_matrix[counttlmt-1][i][j-1]的车站坐标
                        price[i]+=(2+((k-transfer_station_matrix[counttlmt-1][i][j-1])*(((k-transfer_station_matrix[counttlmt-1][i][j-1])>=0)?1:-1))/4);
                        break;
                    }
                }
            }
        }
        while(sorted){//冒泡排序
            sorted=0;
            for(int i=1;i!=counttlm[counttlmt-1];++i){
                if((price[i]!=0)&&(price[i]<price[i-1])){//发现不是按最小到最大的顺序的价格
                    sorted=1;
                    Swap(&price[i],&price[i-1]);
                    for(int j=0;j<=counttlmt+1;++j){//交换价格对应的换乘线路和换乘站
                        Swap(&transfer_line_matrix[counttlmt-1][i][j],&transfer_line_matrix[counttlmt-1][i-1][j]);
                        Swap(&transfer_station_matrix[counttlmt-1][i][j],&transfer_station_matrix[counttlmt-1][i-1][j]);
                    }
                }
            }
        }
        area=button_area_height/counttlm[counttlmt-1];
        diameter=(area>=button_size?button_size:area);
        //int temp;
        for(int i=0;i!=counttlm[counttlmt-1];++i){
            QRadioButton* button=new QRadioButton(this);
            button->setGeometry(button_x,(area*(i+0.5))-button_size/2,line_sx-button_x,diameter);
            button->setStyleSheet("QRadioButton::indicator{width:"+QString::number(diameter)+"px;height:"+QString::number(diameter)+"px;color:green}"
                                  "QRadioButton{font-weight:bold;font-size:"+QString::number(diameter/2)+"px;font-family:\"Microsoft YaHei\";"
                                   "color:black;spacing:"+QString::number(diameter)+"px;}");
            button->setText("方案"+QString::number(i+1)+"：共需"+QString::number(price[i])+"元 ");
            Line_Button->addButton(button,i);
            if(i==0){//默认选择第一个方案
                button->setChecked(true);
            }
        }
    }
    update();
    //Global_variable_reset();
}

void Line::paintEvent(QPaintEvent *e){//画线路
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    if(sameline[0]!=0){
        for(int i=0;i!=countsl;++i){//方案数
            //qDebug().noquote()<<center.x()<<" "<<center.y()<<" "<<last_center.x()<<" "<<last_center.y();
            isForward=(station_searcher(ts,sameline[i])-station_searcher(ss,sameline[i])>0)?1:-1;
            countstation=(station_searcher(ts,sameline[i])-station_searcher(ss,sameline[i]))*isForward;
            l=length/countstation,sx=line_sx;
            center.setX(sx),center.setY(area*(i+0.3));
            pen.setWidth(10);
            pen.setColor(QColor(QString::fromStdString(line_color[sameline[i]-1])));
            painter.setPen(pen);
            brush.setColor(QColor(255,255,255));
            painter.setBrush(brush);
            painter.drawEllipse(center,diameter*0.25,diameter*0.25);
            rect.setRect(center.x()+diameter*0.25,area*i,10*(center.y()-diameter*0.25-area*i),center.y()-diameter*0.25-area*i);
            //qDebug().noquote()<<center.x()+diameter*0.25<<" "<<area*i<<" "<<10*(center.y()-diameter*0.25-area*i)<<" "<<center.y()-diameter*0.25;
            QFont font1("Microsoft YaHei",(center.y()-diameter*0.25-area*i)*0.25);
            font1.setBold(true);
            painter.setFont(font1);
            painter.drawText(rect,Qt::AlignLeft,QString::number(sameline[i])+"号线\n往 "+QString::fromStdString(direction[sameline[i]][(isForward==1?1:0)])+" 方向");
            rect.setRect(center.x()-diameter*0.25,center.y()+diameter*0.25+5,diameter*0.5,area*(i+1)-center.y()-diameter*0.25);
            QFont font("Microsoft YaHei",diameter*0.25+5);
            font.setBold(true);
            painter.setFont(font);
            painter.drawText(rect,QString::fromStdString(name_matrix[sameline[i]][station_searcher(ss,sameline[i])][0]));
            for(int j=0;j!=countstation;++j){
                last_center=center;
                sx+=l;
                center.setX(sx);
                //qDebug().noquote()<<countstation<<" "<<center.x()<<" "<<center.y()<<" "<<last_center.x()<<" "<<last_center.y();
                painter.setPen(pen);
                painter.drawLine(last_center,center);
                //painter.drawLine(center.x(),center.y(),last_center.x(),last_center.y());
                painter.setBrush(brush);
                if(j+1==countstation){
                    painter.drawEllipse(center,diameter*0.25,diameter*0.25);
                    rect.setRect(center.x()-diameter*0.25,center.y()+diameter*0.25+5,diameter*0.5,area*(i+1)-center.y()-diameter*0.25);
                    QFont font("Microsoft YaHei",diameter*0.25+5);
                    font.setBold(true);
                    painter.setFont(font);
                }else{
                    painter.drawEllipse(center,diameter*0.15,diameter*0.15);
                    rect.setRect(center.x()-diameter*0.15,center.y()+diameter*0.15+5,diameter*0.3,area*(i+1)-center.y()-diameter*0.15);
                    QFont font("Microsoft YaHei",diameter*0.15+3);
                    font.setBold(false);
                    painter.setFont(font);
                }
                painter.drawText(rect,QString::fromStdString(name_matrix[sameline[i]][(isForward==1)?(station_searcher(ss,sameline[i])+j+1):(station_searcher(ss,sameline[i])-j-1)][0]));
            }
        }
    }else{
        for(int i=0;i!=counttlm[counttlmt-1];++i){//方案数
            countstation=0,mincs=1000;
            for(int j=counttlmt;j>=0;--j){
                cs[counttlmt-j]=transfer_station_matrix[counttlmt-1][i][j]-station_searcher(name_matrix[transfer_line_matrix[counttlmt-1][i][j+1]][transfer_station_matrix[counttlmt-1][i][j+1]][0],transfer_line_matrix[counttlmt-1][i][j]);
                countstation+=((cs[counttlmt-j]>0?1:-1)*cs[counttlmt-j]);
                if(((cs[counttlmt-j]>0?1:-1)*cs[counttlmt-j])<mincs){
                    mincs=((cs[counttlmt-j]>0?1:-1)*cs[counttlmt-j]);
                }
            }
            l=(countstation!=0?length/countstation:0),sx=line_sx;
            center.setX(sx),center.setY(area*(i+0.3));
            pen.setWidth(10);
            for(int j=counttlmt;j>=0;--j){//换乘站数
                isForward=(cs[counttlmt-j]>0?1:-1);
                pen.setColor(QColor(QString::fromStdString(line_color[transfer_line_matrix[counttlmt-1][i][j]-1])));
                painter.setPen(pen);
                brush.setColor(QColor(255,255,255));
                painter.setBrush(brush);
                painter.drawEllipse(center,diameter*0.25,diameter*0.25);
                rect.setRect(center.x()+diameter*0.25,area*i,10*(center.y()-diameter*0.25-area*i),center.y()-diameter*0.25-area*i);
                //rect.setRect(center.x()+diameter*0.25,area*i,cs[counttlmt-j]*isForward*l,cs[counttlmt-j]*isForward*l/8);
                //qDebug().noquote()<<center.x()+diameter*0.25<<" "<<area*i<<" "<<10*(center.y()-diameter*0.25-area*i)<<" "<<center.y()-diameter*0.25;
                QFont font1("Microsoft YaHei",(center.y()-diameter*0.25-area*i)*0.2);
                //QFont font1("Microsoft YaHei",cs[counttlmt-j]*isForward*l/8*0.25);
                font1.setBold(true);
                painter.setFont(font1);
                painter.drawText(rect,Qt::AlignLeft,QString::number(transfer_line_matrix[counttlmt-1][i][j])+"号线\n往 "+QString::fromStdString(direction[transfer_line_matrix[counttlmt-1][i][j]][(isForward==1?1:0)])+" 方向");
                rect.setRect(center.x()-diameter*0.25,center.y()+diameter*0.25+5,diameter*0.5,area*(i+1)-center.y()-diameter*0.25);
                QFont font("Microsoft YaHei",diameter*0.25+5);
                font.setBold(true);
                painter.setFont(font);
                painter.drawText(rect,QString::fromStdString(name_matrix[transfer_line_matrix[counttlmt-1][i][j]][transfer_station_matrix[counttlmt-1][i][j]-cs[counttlmt-j]][0]));
                for(int k=transfer_station_matrix[counttlmt-1][i][j]-cs[counttlmt-j]+isForward;(isForward==1?(k<=transfer_station_matrix[counttlmt-1][i][j]):(k>=transfer_station_matrix[counttlmt-1][i][j]));(isForward==1?(++k):(--k))){
                    last_center=center;
                    sx+=l;
                    center.setX(sx);
                    //qDebug().noquote()<<countstation<<" "<<center.x()<<" "<<center.y()<<" "<<last_center.x()<<" "<<last_center.y();
                    painter.setPen(pen);
                    painter.drawLine(last_center,center);
                    //painter.drawLine(center.x(),center.y(),last_center.x(),last_center.y());
                    painter.setBrush(brush);
                    if((j==0)&&(k==transfer_station_matrix[counttlmt-1][i][j])){
                        painter.drawEllipse(center,diameter*0.25,diameter*0.25);
                        rect.setRect(center.x()-diameter*0.25,center.y()+diameter*0.25+5,diameter*0.5,area*(i+1)-center.y()-diameter*0.25);
                        QFont font("Microsoft YaHei",diameter*0.25+5);
                        font.setBold(true);
                        painter.setFont(font);
                        painter.drawText(rect,QString::fromStdString(name_matrix[transfer_line_matrix[counttlmt-1][i][j]][k][0]));
                    }else if(k!=transfer_station_matrix[counttlmt-1][i][j]){
                        painter.drawEllipse(center,diameter*0.15,diameter*0.15);
                        rect.setRect(center.x()-diameter*0.15,center.y()+diameter*0.15+5,diameter*0.3,area*(i+1)-center.y()-diameter*0.15);
                        QFont font("Microsoft YaHei",diameter*0.15+3);
                        font.setBold(false);
                        painter.setFont(font);
                        painter.drawText(rect,QString::fromStdString(name_matrix[transfer_line_matrix[counttlmt-1][i][j]][k][0]));
                    }
                }
            }
        }
    }
    // rect.adjust(0,0,200,100);
    // painter.drawText(QRect(0,0,200,100),"test");
}
Line::Line(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Line)
{
    ui->setupUi(this);
    //QPainter painter(this);
    connect(&w3,&Checkstand::return_to_line,this,&Line::return_from_checkstand);
}

Line::~Line()
{
    delete ui;
}

void Line::on_pushButton_clicked()
{
    emit return_to_map();
}

void Line::on_pushButton_2_clicked()
{
    this->hide();
    connect(this,SIGNAL(sendprice(int)),&w3,SLOT(receiveprice(int)));
    emit sendprice(price[Line_Button->checkedId()]);
    //w3.resize(900,600);
    w3.show();
}

void Line::return_from_checkstand(){
    w3.hide();
    this->show();
}

void Line::receivestation(QString& q1,QString& q2){//启动计算
    Global_variable_reset();
    ss=q1.toStdString(),ts=q2.toStdString();
    for(auto button:Line_Button->buttons()){//初始化可选线路按钮组
        Line_Button->removeButton(button);
        button->deleteLater();
    }
    //selection=1;
    calmain();
    //qDebug().noquote()<<q1<<QString::fromStdString(" ")<<q2;
}


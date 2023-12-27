//显示地图及选站界面
#include "map.h"
#include "ui_map.h"
//#include<iostream>
#include<string>
#include<QAction>
#include<QDebug>
#include<QLabel>
#include<QPushButton>
#include<QButtonGroup>
#include<QLineEdit>
#include<QMouseEvent>
#pragma execution_character_set("GBK")
//#include<QRegularExpressionValidator>
#define map_height 711//初始地图的高度
#define map_width 1151//初始地图的宽度
#define initial_x 0//初始地图左上角的坐标
#define initial_y 60
#define LINENUM 18//线路总数
#define STATIONNUM 302//站点总数
using namespace std;

Map::Map(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Map)
{
    ui->setupUi(this);
    QPixmap pixmap("shenzhen_6.png");
    ui->label_4->setPixmap(pixmap);
    ui->pushButton->setEnabled(false);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ratio=1.0,last_ratio=1.0;
    //Station_Button->setExclusive(true);
    //以下为加入站点按钮
    Station_Button->addButton(ui->Ailian,0);
    Station_Button->addButton(ui->Airport_East,1);
    Station_Button->addButton(ui->Airport_North,2);
    Station_Button->addButton(ui->Airport_Terminal_3,3);
    Station_Button->addButton(ui->Antuo_Hill,4);
    Station_Button->addButton(ui->Aobei,5);
    Station_Button->addButton(ui->Bagualing,6);
    Station_Button->addButton(ui->Baigelong,7);
    Station_Button->addButton(ui->Baishilong,8);
    Station_Button->addButton(ui->Baishizhou,9);
    Station_Button->addButton(ui->Baiwang_HKU,10);
    Station_Button->addButton(ui->Bantian,11);
    Station_Button->addButton(ui->Bantian_North,12);
    Station_Button->addButton(ui->Baoan,13);
    Station_Button->addButton(ui->Baoan_Center,14);
    Station_Button->addButton(ui->Baoan_Passenger_Transport_Terminal,15);
    Station_Button->addButton(ui->Baoan_Stadium,16);
    Station_Button->addButton(ui->Baohua,17);
    Station_Button->addButton(ui->Baolong,18);
    Station_Button->addButton(ui->Baolong_Tongle,19);
    Station_Button->addButton(ui->Baotian_1st_Road,20);
    Station_Button->addButton(ui->Beier_Road,21);
    Station_Button->addButton(ui->Bihaiwan,22);
    Station_Button->addButton(ui->Bitou,23);
    Station_Button->addButton(ui->Buji,24);
    Station_Button->addButton(ui->Buxin,25);
    Station_Button->addButton(ui->Caopu,26);
    Station_Button->addButton(ui->Chaguang,27);
    Station_Button->addButton(ui->Changhu,28);
    Station_Button->addButton(ui->Changlingpi,29);
    Station_Button->addButton(ui->Changlong,30);
    Station_Button->addButton(ui->Changzhen,31);
    Station_Button->addButton(ui->Chegongmiao,32);
    Station_Button->addButton(ui->Children_s_Palace,33);
    Station_Button->addButton(ui->Chiwan,34);
    Station_Button->addButton(ui->Chiwei,35);
    Station_Button->addButton(ui->Civic_Center,36);
    Station_Button->addButton(ui->Conversation_Exhibition_Center,37);
    Station_Button->addButton(ui->Conversation_Exhibition_City,38);
    Station_Button->addButton(ui->Cuizhu,39);
    Station_Button->addButton(ui->Dafen,40);
    Station_Button->addButton(ui->Danzhutou,41);
    Station_Button->addButton(ui->Daxin,42);
    Station_Button->addButton(ui->Dayun_Center,43);
    Station_Button->addButton(ui->Dengliang,44);
    Station_Button->addButton(ui->Donggualing,45);
    Station_Button->addButton(ui->Dongjiang_Column_Memorial_Hall,46);
    Station_Button->addButton(ui->Dongjiaotou,47);
    Station_Button->addButton(ui->Fanshen,48);
    Station_Button->addButton(ui->Fenghuangcheng,49);
    Station_Button->addButton(ui->Fuhai_West,50);
    Station_Button->addButton(ui->Fumin,51);
    Station_Button->addButton(ui->Futian,52);
    Station_Button->addButton(ui->Futian_Bonded_Area,53);
    Station_Button->addButton(ui->Futian_Checkpoint,54);
    Station_Button->addButton(ui->Fuwei,55);
    Station_Button->addButton(ui->Fuyong,56);
    Station_Button->addButton(ui->Gangtou,57);
    Station_Button->addButton(ui->Gangxia,58);
    Station_Button->addButton(ui->Gangxia_North,59);
    Station_Button->addButton(ui->Gankeng,60);
    Station_Button->addButton(ui->Gongming_Square,61);
    Station_Button->addButton(ui->Grand_Center,62);
    Station_Button->addButton(ui->Guangming,63);
    Station_Button->addButton(ui->Guangming_Street,64);
    Station_Button->addButton(ui->Guangyayuan,65);
    Station_Button->addButton(ui->Guanlan,66);
    Station_Button->addButton(ui->Guanlanhu,67);
    Station_Button->addButton(ui->Guantian,68);
    Station_Button->addButton(ui->Guiwan,69);
    Station_Button->addButton(ui->Guomao,70);
    Station_Button->addButton(ui->Gushu,71);
    Station_Button->addButton(ui->Haishan,72);
    Station_Button->addButton(ui->Haiyue,73);
    Station_Button->addButton(ui->Hanling,74);
    Station_Button->addButton(ui->Heao,75);
    Station_Button->addButton(ui->Hehua,76);
    Station_Button->addButton(ui->Henggang,77);
    Station_Button->addButton(ui->Heshuikou,78);
    Station_Button->addButton(ui->Hi_Tech_Central,79);
    Station_Button->addButton(ui->Hi_Tech_North,80);
    Station_Button->addButton(ui->Hi_Tech_Park,81);
    Station_Button->addButton(ui->Hi_Tech_South,82);
    Station_Button->addButton(ui->Honghu,83);
    Station_Button->addButton(ui->Honghuashan,84);
    Station_Button->addButton(ui->Honglang_North,85);
    Station_Button->addButton(ui->Hongling,86);
    Station_Button->addButton(ui->Hongling_North,87);
    Station_Button->addButton(ui->Hongling_South,88);
    Station_Button->addButton(ui->Hongshan,89);
    Station_Button->addButton(ui->Hongshuwan,90);
    Station_Button->addButton(ui->Hongshuwan_South,91);
    Station_Button->addButton(ui->Houhai,92);
    Station_Button->addButton(ui->Hourui,93);
    Station_Button->addButton(ui->Houting,94);
    Station_Button->addButton(ui->Huaguoshan,95);
    Station_Button->addButton(ui->Huaide,96);
    Station_Button->addButton(ui->Huanancheng,97);
    Station_Button->addButton(ui->Huangbeiling,98);
    Station_Button->addButton(ui->Huanggang_Checkpoint,99);
    Station_Button->addButton(ui->Huanggangcun,100);
    Station_Button->addButton(ui->Huanggekeng,101);
    Station_Button->addButton(ui->Huangmugang,102);
    Station_Button->addButton(ui->Huangtian,103);
    Station_Button->addButton(ui->Huaqiang_North,104);
    Station_Button->addButton(ui->Huaqiang_Road,105);
    Station_Button->addButton(ui->Huaqiang_South,106);
    Station_Button->addButton(ui->Huawei,107);
    Station_Button->addButton(ui->Huaxin,108);
    Station_Button->addButton(ui->Hubei,109);
    Station_Button->addButton(ui->Huilongpu,110);
    Station_Button->addButton(ui->Jingtian,111);
    Station_Button->addButton(ui->Jinlong,112);
    Station_Button->addButton(ui->Jixiang,113);
    Station_Button->addButton(ui->Kengzi,114);
    Station_Button->addButton(ui->Keyuan,115);
    Station_Button->addButton(ui->Laojie,116);
    Station_Button->addButton(ui->Liangmao_Hill,117);
    Station_Button->addButton(ui->Lianhua_North,118);
    Station_Button->addButton(ui->Lianhua_West,119);
    Station_Button->addButton(ui->Lianhuacun,120);
    Station_Button->addButton(ui->Liantang,121);
    Station_Button->addButton(ui->Liantang_Checkpoint,122);
    Station_Button->addButton(ui->Linhai,123);
    Station_Button->addButton(ui->Linzhi,124);
    Station_Button->addButton(ui->Litchi_Orchards,125);
    Station_Button->addButton(ui->Liuhe,126);
    Station_Button->addButton(ui->Liutang,127);
    Station_Button->addButton(ui->Liuxiandong,128);
    Station_Button->addButton(ui->Liuyue,129);
    Station_Button->addButton(ui->Liuyue_North,130);
    Station_Button->addButton(ui->Liwan,131);
    Station_Button->addButton(ui->Liyumen,132);
    Station_Button->addButton(ui->LongCheng_Square,133);
    Station_Button->addButton(ui->Longcheng_Park,134);
    Station_Button->addButton(ui->Longdong,135);
    Station_Button->addButton(ui->Longhua,136);
    Station_Button->addButton(ui->Longjing,137);
    Station_Button->addButton(ui->Longsheng,138);
    Station_Button->addButton(ui->Longyuan,139);
    Station_Button->addButton(ui->Loucun,140);
    Station_Button->addButton(ui->Ludancun,141);
    Station_Button->addButton(ui->Luohu,142);
    Station_Button->addButton(ui->Luohu_North,143);
    Station_Button->addButton(ui->Luozu,144);
    Station_Button->addButton(ui->Maan_Hill,145);
    Station_Button->addButton(ui->Maling,146);
    Station_Button->addButton(ui->Mawan,147);
    Station_Button->addButton(ui->Meicun,148);
    Station_Button->addButton(ui->Meijing,149);
    Station_Button->addButton(ui->Meilingguan,150);
    Station_Button->addButton(ui->Menghai,151);
    Station_Button->addButton(ui->Minle,152);
    Station_Button->addButton(ui->Minzhi,153);
    Station_Button->addButton(ui->Mugu,154);
    Station_Button->addButton(ui->Mumianwan,155);
    Station_Button->addButton(ui->Nanguang,156);
    Station_Button->addButton(ui->Nankeng,157);
    Station_Button->addButton(ui->Nanlian,158);
    Station_Button->addButton(ui->Nanshan,159);
    Station_Button->addButton(ui->Nanshan_Book_Mall,160);
    Station_Button->addButton(ui->Nantou_Ancient_City,161);
    Station_Button->addButton(ui->Nanyou,162);
    Station_Button->addButton(ui->Nanyou_West,163);
    Station_Button->addButton(ui->Nanyue,164);
    Station_Button->addButton(ui->Nigang,165);
    Station_Button->addButton(ui->Niuhu,166);
    Station_Button->addButton(ui->Nonglin,167);
    Station_Button->addButton(ui->OCT,168);
    Station_Button->addButton(ui->Pinghu,169);
    Station_Button->addButton(ui->Pinghuan,170);
    Station_Button->addButton(ui->Pingluan_Hill,171);
    Station_Button->addButton(ui->Pingshan,172);
    Station_Button->addButton(ui->Pingshan_Center,173);
    Station_Button->addButton(ui->Pingshan_Square,174);
    Station_Button->addButton(ui->Pingshanwei,175);
    Station_Button->addButton(ui->Pingzhou,176);
    Station_Button->addButton(ui->Qianhaiwan,177);
    Station_Button->addButton(ui->Qianwan,178);
    Station_Button->addButton(ui->Qianwan_Park,179);
    Station_Button->addButton(ui->Qiaocheng_East,180);
    Station_Button->addButton(ui->Qiaocheng_North,181);
    Station_Button->addButton(ui->Qiaotou,182);
    Station_Button->addButton(ui->Qiaotou_West,183);
    Station_Button->addButton(ui->Qiaoxiang,184);
    Station_Button->addButton(ui->Qinghu,185);
    Station_Button->addButton(ui->Qinghu_North,186);
    Station_Button->addButton(ui->Railway_Park,187);
    Station_Button->addButton(ui->Renming_South,188);
    Station_Button->addButton(ui->SIAT,189);
    Station_Button->addButton(ui->Science_Museum,190);
    Station_Button->addButton(ui->Science_Park,191);
    Station_Button->addButton(ui->Sea_World,192);
    Station_Button->addButton(ui->Shabo,193);
    Station_Button->addButton(ui->Shaibu,194);
    Station_Button->addButton(ui->Shajing,195);
    Station_Button->addButton(ui->Shangchuan,196);
    Station_Button->addButton(ui->Shangfen,197);
    Station_Button->addButton(ui->Shangjing,198);
    Station_Button->addButton(ui->Shanglilang,199);
    Station_Button->addButton(ui->Shangmeilin,200);
    Station_Button->addButton(ui->Shangsha,201);
    Station_Button->addButton(ui->Shangshuijin,202);
    Station_Button->addButton(ui->Shangtang,203);
    Station_Button->addButton(ui->Shangwu,204);
    Station_Button->addButton(ui->Shatian,205);
    Station_Button->addButton(ui->Shatoujiao,206);
    Station_Button->addButton(ui->Shawei,207);
    Station_Button->addButton(ui->Shekou_Port,208);
    Station_Button->addButton(ui->Shengping,209);
    Station_Button->addButton(ui->Shenkang,210);
    Station_Button->addButton(ui->Shenwai_Senior_Campus,211);
    Station_Button->addButton(ui->Shenwan,212);
    Station_Button->addButton(ui->Shenyun,213);
    Station_Button->addButton(ui->Shenzhen_Bay_Checkpoint,214);
    Station_Button->addButton(ui->Shenzhen_Bay_Park,215);
    Station_Button->addButton(ui->Shenzhen_North_Station,216);
    Station_Button->addButton(ui->Shenzhen_University,217);
    Station_Button->addButton(ui->Shenzhen_University_South,218);
    Station_Button->addButton(ui->Shenzhen_World,219);
    Station_Button->addButton(ui->Shenzhen_World_North,220);
    Station_Button->addButton(ui->Shenzhen_World_South,221);
    Station_Button->addButton(ui->Shigu,222);
    Station_Button->addButton(ui->Shijing,223);
    Station_Button->addButton(ui->Shixia,224);
    Station_Button->addButton(ui->Shiyaling,225);
    Station_Button->addButton(ui->Shiyan,226);
    Station_Button->addButton(ui->Shopping_Park,227);
    Station_Button->addButton(ui->Shuanglong,228);
    Station_Button->addButton(ui->Shuangyong_Street,229);
    Station_Button->addButton(ui->Shuibei,230);
    Station_Button->addButton(ui->Shuiwan,231);
    Station_Button->addButton(ui->Shutianpu,232);
    Station_Button->addButton(ui->Sihai,233);
    Station_Button->addButton(ui->Silian,234);
    Station_Button->addButton(ui->Songgang,235);
    Station_Button->addButton(ui->Songgang_Park,236);
    Station_Button->addButton(ui->Songyuanxia,237);
    Station_Button->addButton(ui->Sports_Center,238);
    Station_Button->addButton(ui->Sun_Yat_sen_University,239);
    Station_Button->addButton(ui->Sungang,240);
    Station_Button->addButton(ui->Taian,241);
    Station_Button->addButton(ui->Taiziwan,242);
    Station_Button->addButton(ui->Talent_Park,243);
    Station_Button->addButton(ui->Tangkeng,244);
    Station_Button->addButton(ui->Tanglang,245);
    Station_Button->addButton(ui->Tangwei,246);
    Station_Button->addButton(ui->Taoyuan,247);
    Station_Button->addButton(ui->Taoyuancun,248);
    Station_Button->addButton(ui->Technology_University,249);
    Station_Button->addButton(ui->Tianbei,250);
    Station_Button->addButton(ui->Tianxin,251);
    Station_Button->addButton(ui->Tongle_South,252);
    Station_Button->addButton(ui->Tongxinling,253);
    Station_Button->addButton(ui->Universiade,254);
    Station_Button->addButton(ui->University_Town,255);
    Station_Button->addButton(ui->Wanxia,256);
    Station_Button->addButton(ui->Waterlands_Resort_East,257);
    Station_Button->addButton(ui->Waterlands_Resort_South,258);
    Station_Button->addButton(ui->Wenjing,259);
    Station_Button->addButton(ui->Window_of_the_World,260);
    Station_Button->addButton(ui->Wuhe,261);
    Station_Button->addButton(ui->Wutong_Mountain_South,262);
    Station_Button->addButton(ui->Xiameilin,263);
    Station_Button->addButton(ui->Xiangmei,264);
    Station_Button->addButton(ui->Xiangmei_North,265);
    Station_Button->addButton(ui->Xiangmi,266);
    Station_Button->addButton(ui->Xiangmihu,267);
    Station_Button->addButton(ui->Xiangxicun,268);
    Station_Button->addButton(ui->Xianhulu,269);
    Station_Button->addButton(ui->Xiasha,270);
    Station_Button->addButton(ui->Xiashuijin,271);
    Station_Button->addButton(ui->Xikeng,272);
    Station_Button->addButton(ui->Xili,273);
    Station_Button->addButton(ui->Xili_High_Speed_Railway_Station,274);
    Station_Button->addButton(ui->Xili_Lake,275);
    Station_Button->addButton(ui->Xinan,276);
    Station_Button->addButton(ui->Xinan_Park,277);
    Station_Button->addButton(ui->Xingdong,278);
    Station_Button->addButton(ui->Xingwei,279);
    Station_Button->addButton(ui->Xinhe,280);
    Station_Button->addButton(ui->Xintangwei,281);
    Station_Button->addButton(ui->Xinxiu,282);
    Station_Button->addButton(ui->Xitou,283);
    Station_Button->addButton(ui->Xixiang,284);
    Station_Button->addButton(ui->Xixiang_Taoyuan,285);
    Station_Button->addButton(ui->Xuexiang,286);
    Station_Button->addButton(ui->Yabao,287);
    Station_Button->addButton(ui->Yangmei,288);
    Station_Button->addButton(ui->Yangtai_Mountain_East,289);
    Station_Button->addButton(ui->Yannan,290);
    Station_Button->addButton(ui->Yantian_Port_West,291);
    Station_Button->addButton(ui->Yantian_Road,292);
    Station_Button->addButton(ui->Yanzihu,293);
    Station_Button->addButton(ui->Yihai,294);
    Station_Button->addButton(ui->Yijing,295);
    Station_Button->addButton(ui->Yingrenshi,296);
    Station_Button->addButton(ui->Yinhu,297);
    Station_Button->addButton(ui->Yitian,298);
    Station_Button->addButton(ui->Yonghu,299);
    Station_Button->addButton(ui->Yuanfen,300);
    Station_Button->addButton(ui->Yuanling,301);
    Station_Button->addButton(ui->Yuehaimen,302);
    Station_Button->addButton(ui->Yuyuan,303);
    Station_Button->addButton(ui->Zhangbei,304);
    Station_Button->addButton(ui->Zhenmei,305);
    Station_Button->addButton(ui->Zhongshan_Park,306);
    Station_Button->addButton(ui->Zhongwu_South,307);
    Station_Button->addButton(ui->Zhucun,308);
    Station_Button->addButton(ui->Zhuguang,309);
    Station_Button->addButton(ui->Zhuzilin,310);
    Station_Button->addButton(ui->Zuopaotai_East,311);
    //以下为添加按钮的初始坐标
    for(auto button:Station_Button->buttons()){
        station_button_position[Station_Button->id(button)][0]=button->geometry().x();
        station_button_position[Station_Button->id(button)][1]=button->geometry().y();
    }
    connect(ui->actionddc,&QAction::triggered,this,&Map::help);
    connect(ui->exitmain,&QAction::triggered,this,&Map::sendslot);
    connect(&w2,&Line::return_to_map,this,&Map::return_from_line);
    connect(Station_Button,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(station_button_clicked(QAbstractButton*)));
}

Map::~Map()
{
    delete ui;
}

void Map::check(){
    if((checkss&&checkts)&&(ss!=ts)){
        ui->pushButton->setEnabled(true);
    }else{
        ui->pushButton->setEnabled(false);
    }
}

void Map::sendslot()
{
    emit mysignal();
}

void Map::on_pushButton_clicked()
{
    this->hide();
    connect(this,SIGNAL(sendstation(QString&,QString&)),&w2,SLOT(receivestation(QString&,QString&)));
    QString sendss=QString::fromStdString(ss),sendts=QString::fromStdString(ts);
    emit sendstation(sendss,sendts);
    //w2.resize(900,600);
    w2.show();
}

void Map::return_from_line()
{
    w2.hide();
    this->show();
}

void Map::on_pushButton_2_clicked()
{
    emit return_to_welcome();
}

void Map::on_Slider_valueChanged(int value)
{
    last_ratio=ratio;
    if(ratio!=1.0){//避免除以零，由于ratio=1时map_dx=map_dy=0，故没有例外情况
        map_dx/=(ratio-1),map_dy/=(ratio-1);
    }
    ratio=value/100.0;
    map_dx*=(ratio-1),map_dy*=(ratio-1);
    last_map_x=map_x,last_map_y=map_y;
    map_x=map_dx+initial_x-(map_width*ratio-map_width)/2;
    map_y=map_dy+initial_y-(map_height*ratio-map_height)/2;
    ui->label_4->setGeometry(map_dx+initial_x-(map_width*ratio-map_width)/2,map_dy+initial_y-(map_height*ratio-map_height)/2,map_width*ratio,map_height*ratio);
    ui->horizontalScrollBar->setMaximum((1-1/ratio)*map_width);
    ui->horizontalScrollBar->setPageStep(map_width/ratio);
    last_position_horizontal=(ratio-1)/(2*ratio)*map_width-1/ratio*map_dx;
    ui->horizontalScrollBar->setValue(last_position_horizontal);
    ui->verticalScrollBar->setMaximum((1-1/ratio)*map_height);
    ui->verticalScrollBar->setPageStep(map_height/ratio);
    last_position_vertical=(ratio-1)/(2*ratio)*map_height-1/ratio*map_dy;
    ui->verticalScrollBar->setValue(last_position_vertical);
    for(auto button:Station_Button->buttons()){
        station_button_position[Station_Button->id(button)][0]=(station_button_position[Station_Button->id(button)][0]-last_map_x)*ratio/last_ratio+map_x+3.3*(ratio-last_ratio);//最后一项为修正系数，下同
        station_button_position[Station_Button->id(button)][1]=(station_button_position[Station_Button->id(button)][1]-last_map_y)*ratio/last_ratio+map_y+0.75*(ratio-last_ratio);
        button->setGeometry(station_button_position[Station_Button->id(button)][0],station_button_position[Station_Button->id(button)][1],20*ratio,20*ratio);
    }
}

void Map::on_horizontalScrollBar_sliderMoved(int position)
{
    map_dx=(ratio-1)/2*map_width-ratio*position;
    last_map_x=map_x,last_map_y=map_y;
    map_x=initial_x-ratio*position;
    ui->label_4->setGeometry(map_x,map_y,map_width*ratio,map_height*ratio);
    for(auto button:Station_Button->buttons()){
        station_button_position[Station_Button->id(button)][0]+=(map_x-last_map_x);
        button->setGeometry(station_button_position[Station_Button->id(button)][0],station_button_position[Station_Button->id(button)][1],20*ratio,20*ratio);
    }
}

void Map::on_verticalScrollBar_sliderMoved(int position)
{
    map_dy=(ratio-1)/2*map_height-ratio*position;
    last_map_x=map_x,last_map_y=map_y;
    map_y=initial_y-ratio*position;
    ui->label_4->setGeometry(map_x,map_y,map_width*ratio,map_height*ratio);
    for(auto button:Station_Button->buttons()){
        station_button_position[Station_Button->id(button)][1]+=(map_y-last_map_y);
        button->setGeometry(station_button_position[Station_Button->id(button)][0],station_button_position[Station_Button->id(button)][1],20*ratio,20*ratio);
    }
}

bool Map::eventFilter(QObject *watched, QEvent *event){//利用事件过滤器监测哪个输入框被选中
    if(watched==ui->lineEdit){
        if(event->type()==QEvent::FocusIn){
            selection=0;
        }
    }
    if(watched==ui->lineEdit_2){
        if(event->type()==QEvent::FocusIn){
            selection=1;
        }
    }
    return QWidget::eventFilter(watched,event);
}

void Map::settextBrowser(int i,int j){
    ui->textBrowser->setText("<h1 align=center><font face=Microsoft YaHei><font color=black><b>"+QString::fromStdString(name_matrix[i][j][0])+"</b></font></h1>"
                             "<h3 align=center><font face=San Francisco Display><font color=black><i>"+QString::fromStdString(name_matrix[i][j][1])+"</i></font></h3>"
                             "<hr>"
                             "<h3 align=left><font face=Microsoft YaHei><font color=black><b>"+QString::fromStdString("所在线路：")+"</b></font></h3>");
    //ui->textBrowser->append("<font color="+QString::fromStdString(line_color[i-1])+">"+);
    if(i==15){
        ui->textBrowser->append("<font color="+QString::fromStdString(line_color[i-1])+">"+"16号线  </font>");
    }else if(i==16){
        ui->textBrowser->append("<font color="+QString::fromStdString(line_color[i-1])+">"+"20号线  </font>");
    }else if(i==17){
        ui->textBrowser->append("<font color="+QString::fromStdString(line_color[i-1])+">"+"6号线支线  </font>");
    }else{
        ui->textBrowser->append("<font color="+QString::fromStdString(line_color[i-1])+">"+QString::number(i)+"号线  </font>");
    }
    for(int k=0;k!=3;++k){
        if(transfer_matrix[i][j][k]!=0){
            //ui->textBrowser->append("<font color="+QString::fromStdString(line_color[transfer_matrix[i][j][k]-1])+">"+);
            if(transfer_matrix[i][j][k]==15){
                ui->textBrowser->append("<font color="+QString::fromStdString(line_color[transfer_matrix[i][j][k]-1])+">"+"16号线  </font>");
            }else if(transfer_matrix[i][j][k]==16){
                ui->textBrowser->append("<font color="+QString::fromStdString(line_color[transfer_matrix[i][j][k]-1])+">"+"20号线  </font>");
            }else if(transfer_matrix[i][j][k]==17){
                ui->textBrowser->append("<font color="+QString::fromStdString(line_color[transfer_matrix[i][j][k]-1])+">"+"6号线支线  </font>");
            }else{
                ui->textBrowser->append("<font color="+QString::fromStdString(line_color[transfer_matrix[i][j][k]-1])+">"+QString::number(transfer_matrix[i][j][k])+"号线  </font>");
            }
        }
    }
}

void Map::station_button_clicked(QAbstractButton* button){
    ui->textBrowser->clear();
    if(!selection){
        tempss=button->objectName().toStdString();
    }else{
        tempts=button->objectName().toStdString();
    }
    bool b1=1,b2=1;
    for(int i=1;i!=18;++i){
        for(int j=1;j!=35;++j){
            if(!selection&&b1&&(tempss==name_matrix[i][j][1])){
                ss=name_matrix[i][j][0];
                ui->lineEdit->setText(QString::fromStdString(ss));
                checkss=1;
                check();
                b1=0;
                settextBrowser(i,j);
            }
            if(selection&&b2&&(tempts==name_matrix[i][j][1])){
                ts=name_matrix[i][j][0];
                ui->lineEdit_2->setText(QString::fromStdString(ts));
                checkts=1;
                check();
                b2=0;
                settextBrowser(i,j);
            }
        }
    }
    // qDebug().noquote()<<QString::fromStdString(tempss)
    //          <<QString::fromStdString(" ")
    //          <<QString::fromStdString(ss)
    //          <<QString::fromStdString(" ")
    //          <<QString::fromStdString(tempts)
    //          <<QString::fromStdString(" ")
    //          <<QString::fromStdString(ts);
}

void Map::on_lineEdit_textEdited(const QString &arg1)
{
    ui->textBrowser->clear();
    checkss=0;
    for(int i=1;i!=18;++i){
        for(int j=1;j!=35;++j){
            if((!checkss)&&(arg1.toStdString()==name_matrix[i][j][0])){
                ss=name_matrix[i][j][0];
                for(auto button:Station_Button->buttons()){
                    if(button->objectName().toStdString()==name_matrix[i][j][1]){
                        button->setChecked(true);
                        break;
                    }
                }
                checkss=1;
                settextBrowser(i,j);
            }
        }
    }
    check();
}

void Map::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->textBrowser->clear();
    checkts=0;
    for(int i=1;i!=18;++i){
        for(int j=1;j!=35;++j){
            if((!checkts)&&(arg1.toStdString()==name_matrix[i][j][0])){
                ts=name_matrix[i][j][0];
                for(auto button:Station_Button->buttons()){
                    if(button->objectName().toStdString()==name_matrix[i][j][1]){
                        button->setChecked(true);
                        break;
                    }
                }
                checkts=1;
                settextBrowser(i,j);
            }
        }
    }
    check();
}

void Map::help()
{

        QMessageBox *messageRecord = new QMessageBox(this);
        messageRecord->setStyleSheet("background-color:white");
        messageRecord->setWindowTitle("帮助与说明");
        QString str = QString("<h2>帮助</h2>"
                              "<h3>选站界面</h3>"
                              "<p>您可以点击输入框来选择输入起始站或终点站，可以点击按钮来选择，或直接在输入框里输入站名<br></p>"
                              "<p>拖动滑动条来缩放地图，拖动滚动条来移动地图<br></p>"
                              "<p>在右边可以预览站点的中英文名和所在线路<br></p>"
                              "<h3>选线界面</h3>"
                              "<p>点击左列的按钮来选择您的换乘方案，价格和乘车路线位于右边<br></p>"
                              "<h3>支付界面</h3>"
                              "<p>输入人数和金额，支持直接输入、按箭头输入、鼠标滚轮输入<br></p>"
                              "<p>如想更换方案，点击“我再想想”按钮即可返回选线界面<br></p>"
                              "<h2>注意事项</h2>"
                              "<h3>1.选站界面按钮本身不会放大，且在地图放大时会偏离地图中的站点</h3>"
                              "<h3>2.“福田口岸”站点的按钮位于4号线和10号线的站点之间</h3>"
                              "<h3>3.本程序将“莲塘”作为2号线与8号线的中转站</h3>"
                              "<h3>4.本程序不支持有轨电车站点的选择</h3>"
                              "<h3>5.本程序目前只录入了2024年以前的深圳地铁站点</h3>"
                              "<h3>6.本程序的价格计算公式为：2+[同一线路上起始站与终点站间的站点数/4]（向下取整），故与实际情况有所不同</h3>"
                              "<h3>7.换乘方案过多时，可能无法看到乘车路线中的文字</h3>"
                              "<h3>8.本程序不支持拖动窗口右下角来缩放</h3>"
                              "<h2>版权说明</h2>"
                              "<h3>1.欢迎界面背景图引用深圳地铁官网的线路图<br>https://www.szmc.net/shentieyunying/yunyingfuwu/szsgdjtyyxlwlt/</h3>"
                              "<h3>2.选站界面的地图引用自https://railmapgen.github.io/?app=rmp-gallery，由本人用ps修改部分站点的中英文名</h3>"
                              "<h3>3.哈尔滨工业大学（深圳）校名校徽引用自学校官网</h3>"
                              "<h3>4.其余一切代码、图片等均为本人所有，未经允许禁止引用</h3>"
                              "<h3>源代码地址：https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System</h3>");

        QLabel *label = new QLabel(str);
        label->setWordWrap(true);
        QScrollArea *area = new QScrollArea();
        area->setMinimumSize(530, 550);
        area->setWidget(label);
        area->setWidgetResizable(true);
        area->setStyleSheet("border:0");
        area->setBackgroundRole(QPalette::Midlight);
        QGridLayout *grid = new QGridLayout();
        grid->addWidget(area);
        (dynamic_cast<QGridLayout *>(messageRecord->layout()))->addLayout(grid, 0, 0);
        QPushButton *buttonOK = messageRecord->addButton("确 认", QMessageBox::AcceptRole);
        buttonOK->setStyleSheet("QPushButton{width:65px solid; height: 22px; border-radius:4px; "
                                "background-color:qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), "
                                "stop:0.5 rgba(236, 236, 236, 255));}"
                                "QPushButton:hover{ background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,"
                                " stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));border-radius:5px;"
                                " border: 1px solid #3C80B1}"
                                "QPushButton:pressed{background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, "
                                "stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));border-radius:5px;"
                                "border: 1px solid #5F92B2;  }");
        messageRecord->exec();

}

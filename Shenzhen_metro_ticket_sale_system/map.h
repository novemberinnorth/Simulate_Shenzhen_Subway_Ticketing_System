#ifndef MAP_H
#define MAP_H
#include<QPaintEvent>
#include"line.h"
#include <QMainWindow>
#include<QAction>
#include<QDebug>
#include<QLabel>
#include<QPushButton>
#include<QButtonGroup>
#include<QMouseEvent>
#include<QMessageBox>
#include<QGridLayout>
#include<QScrollArea>
#define map_height 711//初始地图的高度
#define map_width 1151//初始地图的宽度
#define initial_x 0//初始地图左上角的坐标
#define initial_y 60
#define LINENUM 18//线路总数
#define STATIONNUM 302//站点总数
using namespace std;
//string tempss;
namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    Line w2;
    void check();
    void sendslot();
    void settextBrowser(int i,int j);
    void return_from_line();
    void zoom(int value);
    void help();
    //void initial_Station_Button();
    QButtonGroup *Station_Button=new QButtonGroup();
    double ratio=1.0,last_ratio=1.0;//地图放大倍数
    double map_x=0,map_y=60,last_map_x,last_map_y;//地图左上角的坐标
    double map_dx=0,map_dy=0;//地图左上角的坐标的变化量
    double last_position_horizontal,last_position_vertical;//记录滚动条上一次位置
    double station_button_position[STATIONNUM][2]={{0.0,0.0}};//记录所有站点按钮的位置
    bool selection=0;//选中的输入框，0为起始站，1为终点站
    bool checkss=0,checkts=0;//检测两个站点名是否被正确输入
    //string tempss;//保存用户输入的始发站和终点站
    //地铁站点名称及英文翻译
    const string name_matrix[18][35][2]={{"",""},
                                           {{"1号线","null"},
                                               {"机场东","Airport_East"},
                                               {"后瑞","Hourui"},
                                               {"固戍","Gushu"},
                                               {"西乡","Xixiang"},
                                               {"坪洲","Pingzhou"},
                                               {"宝体","Baoan_Stadium"},
                                               {"宝安中心","Baoan_Center"},
                                               {"新安","Xinan"},
                                               {"前海湾","Qianhaiwan"},
                                               {"鲤鱼门","Liyumen"},
                                               {"大新","Daxin"},
                                               {"桃园","Taoyuan"},
                                               {"深大","Shenzhen_University"},
                                               {"高新园","Hi_Tech_Park"},
                                               {"白石洲","Baishizhou"},
                                               {"世界之窗","Window_of_the_World"},
                                               {"华侨城","OCT"},
                                               {"侨城东","Qiaocheng_East"},
                                               {"竹子林","Zhuzilin"},
                                               {"车公庙","Chegongmiao"},
                                               {"香蜜湖","Xiangmihu"},
                                               {"购物公园","Shopping_Park"},
                                               {"会展中心","Conversation_Exhibition_Center"},
                                               {"岗厦","Gangxia"},
                                               {"华强路","Huaqiang_Road"},
                                               {"科学馆","Science_Museum"},
                                               {"大剧院","Grand_Center"},
                                               {"老街","Laojie"},
                                               {"国贸","Guomao"},
                                               {"罗湖","Luohu"}
                                           },
                                           {{"2号线","null"},
                                               {"赤湾","Chiwan"},
                                               {"蛇口港","Shekou_Port"},
                                               {"海上世界","Sea_World"},
                                               {"水湾","Shuiwan"},
                                               {"东角头","Dongjiaotou"},
                                               {"湾厦","Wanxia"},
                                               {"海月","Haiyue"},
                                               {"登良","Dengliang"},
                                               {"后海","Houhai"},
                                               {"科苑","Keyuan"},
                                               {"红树湾","Hongshuwan"},
                                               {"世界之窗","Window_of_the_World"},
                                               {"侨城北","Qiaocheng_North"},
                                               {"深康","Shenkang"},
                                               {"安托山","Antuo_Hill"},
                                               {"侨香","Qiaoxiang"},
                                               {"香蜜","Xiangmi"},
                                               {"香梅北","Xiangmei_North"},
                                               {"景田","Jingtian"},
                                               {"莲花西","Lianhua_West"},
                                               {"福田","Futian"},
                                               {"市民中心","Civic_Center"},
                                               {"岗厦北","Gangxia_North"},
                                               {"华强北","Huaqiang_North"},
                                               {"燕南","Yannan"},
                                               {"大剧院","Grand_Center"},
                                               {"湖贝","Hubei"},
                                               {"黄贝岭","Huangbeiling"},
                                               {"新秀","Xinxiu"},
                                               {"莲塘口岸","Liantang_Checkpoint"},
                                               {"仙湖路","Xianhulu"},
                                               {"莲塘","Liantang"}
                                           },
                                           {{"3号线","null"},
                                               {"福保","Futian_Bonded_Area"},
                                               {"益田","Yitian"},
                                               {"石厦","Shixia"},
                                               {"购物公园","Shopping_Park"},
                                               {"福田","Futian"},
                                               {"少年宫","Children_s_Palace"},
                                               {"莲花村","Lianhuacun"},
                                               {"华新","Huaxin"},
                                               {"通新岭","Tongxinling"},
                                               {"红岭","Hongling"},
                                               {"老街","Laojie"},
                                               {"晒布","Shaibu"},
                                               {"翠竹","Cuizhu"},
                                               {"田贝","Tianbei"},
                                               {"水贝","Shuibei"},
                                               {"草埔","Caopu"},
                                               {"布吉","Buji"},
                                               {"木棉湾","Mumianwan"},
                                               {"大芬","Dafen"},
                                               {"丹竹头","Danzhutou"},
                                               {"六约","Liuyue"},
                                               {"塘坑","Tangkeng"},
                                               {"横岗","Henggang"},
                                               {"永湖","Yonghu"},
                                               {"荷坳","Heao"},
                                               {"大运","Universiade"},
                                               {"爱联","Ailian"},
                                               {"吉祥","Jixiang"},
                                               {"龙城广场","LongCheng_Square"},
                                               {"南联","Nanlian"},
                                               {"双龙","Shuanglong"}
                                           },
                                           {{"4号线","null"},
                                               {"牛湖","Niuhu"},
                                               {"观澜湖","Guanlanhu"},
                                               {"松原厦","Songyuanxia"},
                                               {"观澜","Guanlan"},
                                               {"长湖","Changhu"},
                                               {"茜坑","Xikeng"},
                                               {"竹村","Zhucun"},
                                               {"清湖北","Qinghu_North"},
                                               {"清湖","Qinghu"},
                                               {"龙华","Longhua"},
                                               {"龙胜","Longsheng"},
                                               {"上塘","Shangtang"},
                                               {"红山","Hongshan"},
                                               {"深圳北站","Shenzhen_North_Station"},
                                               {"白石龙","Baishilong"},
                                               {"民乐","Minle"},
                                               {"上梅林","Shangmeilin"},
                                               {"莲花北","Lianhua_North"},
                                               {"少年宫","Children_s_Palace"},
                                               {"市民中心","Civic_Center"},
                                               {"会展中心","Conversation_Exhibition_Center"},
                                               {"福民","Fumin"},
                                               {"福田口岸","Futian_Checkpoint"}
                                           },
                                           {{"5号线","null"},
                                               {"赤湾","Chiwan"},
                                               {"荔湾","Liwan"},
                                               {"铁路公园","Railway_Park"},
                                               {"妈湾","Mawan"},
                                               {"前湾公园","Qianwan_Park"},
                                               {"前湾","Qianwan"},
                                               {"桂湾","Guiwan"},
                                               {"前海湾","Qianhaiwan"},
                                               {"临海","Linhai"},
                                               {"宝华","Baohua"},
                                               {"宝安中心","Baoan_Center"},
                                               {"翻身","Fanshen"},
                                               {"灵芝","Linzhi"},
                                               {"洪浪北","Honglang_North"},
                                               {"兴东","Xingdong"},
                                               {"留仙洞","Liuxiandong"},
                                               {"西丽","Xili"},
                                               {"大学城","University_Town"},
                                               {"塘朗","Tanglang"},
                                               {"长岭陂","Changlingpi"},
                                               {"深圳北站","Shenzhen_North_Station"},
                                               {"民治","Minzhi"},
                                               {"五和","Wuhe"},
                                               {"坂田","Bantian"},
                                               {"杨美","Yangmei"},
                                               {"上水径","Shangshuijin"},
                                               {"下水径","Xiashuijin"},
                                               {"长龙","Changlong"},
                                               {"布吉","Buji"},
                                               {"百鸽笼","Baigelong"},
                                               {"布心","Buxin"},
                                               {"太安","Taian"},
                                               {"怡景","Yijing"},
                                               {"黄贝岭","Huangbeiling"}
                                           },
                                           {{"6号线","null"},
                                               {"松岗","Songgang"},
                                               {"溪头","Xitou"},
                                               {"松岗公园","Songgang_Park"},
                                               {"薯田埔","Shutianpu"},
                                               {"合水口","Heshuikou"},
                                               {"公明广场","Gongming_Square"},
                                               {"红花山","Honghuashan"},
                                               {"楼村","Loucun"},
                                               {"科学公园","Science_Park"},
                                               {"光明","Guangming"},
                                               {"光明大街","Guangming_Street"},
                                               {"凤凰城","Fenghuangcheng"},
                                               {"长圳","Changzhen"},
                                               {"上屋","Shangwu"},
                                               {"官田","Guantian"},
                                               {"阳台山东","Yangtai_Mountain_East"},
                                               {"元芬","Yuanfen"},
                                               {"上芬","Shangfen"},
                                               {"红山","Hongshan"},
                                               {"深圳北站","Shenzhen_North_Station"},
                                               {"梅林关","Meilingguan"},
                                               {"翰岭","Hanling"},
                                               {"银湖","Yinhu"},
                                               {"八卦岭","Bagualing"},
                                               {"体育中心","Sports_Center"},
                                               {"通新岭","Tongxinling"},
                                               {"科学馆","Science_Museum"}
                                           },
                                           {{"7号线","null"},
                                               {"西丽湖","Xili_Lake"},
                                               {"西丽","Xili"},
                                               {"茶光","Chaguang"},
                                               {"珠光","Zhuguang"},
                                               {"龙井","Longjing"},
                                               {"桃源村","Taoyuancun"},
                                               {"深云","Shenyun"},
                                               {"安托山","Antuo_Hill"},
                                               {"农林","Nonglin"},
                                               {"车公庙","Chegongmiao"},
                                               {"上沙","Shangsha"},
                                               {"沙尾","Shawei"},
                                               {"石厦","Shixia"},
                                               {"皇岗村","Huanggangcun"},
                                               {"福民","Fumin"},
                                               {"皇岗口岸","Huanggang_Checkpoint"},
                                               {"赤尾","Chiwei"},
                                               {"华强南","Huaqiang_South"},
                                               {"华强北","Huaqiang_North"},
                                               {"华新","Huaxin"},
                                               {"黄木岗","Huangmugang"},
                                               {"八卦岭","Bagualing"},
                                               {"红岭北","Hongling_North"},
                                               {"笋岗","Sungang"},
                                               {"洪湖","Honghu"},
                                               {"田贝","Tianbei"},
                                               {"太安","Taian"}
                                           },
                                           {{"8号线","null"},
                                               {"莲塘","Liantang"},
                                               {"梧桐山南","Wutong_Mountain_South"},
                                               {"沙头角","Shatoujiao"},
                                               {"海山","Haishan"},
                                               {"盐田港西","Yantian_Port_West"},
                                               {"深外高中","Shenwai_Senior_Campus"},
                                               {"盐田路","Yantian_Road"}
                                           },
                                           {{"9号线","null"},
                                               {"前湾","Qianwan"},
                                               {"梦海","Menghai"},
                                               {"怡海","Yihai"},
                                               {"荔林","Litchi_Orchards"},
                                               {"南油西","Nanyou_West"},
                                               {"南油","Nanyou"},
                                               {"南山书城","Nanshan_Book_Mall"},
                                               {"深大南","Shenzhen_University_South"},
                                               {"粤海门","Yuehaimen"},
                                               {"高新南","Hi_Tech_South"},
                                               {"红树湾南","Hongshuwan_South"},
                                               {"深湾","Shenwan"},
                                               {"深圳湾公园","Shenzhen_Bay_Park"},
                                               {"下沙","Xiasha"},
                                               {"车公庙","Chegongmiao"},
                                               {"香梅","Xiangmei"},
                                               {"景田","Jingtian"},
                                               {"梅景","Meijing"},
                                               {"下梅林","Xiameilin"},
                                               {"梅村","Meicun"},
                                               {"上梅林","Shangmeilin"},
                                               {"孖岭","Maling"},
                                               {"银湖","Yinhu"},
                                               {"泥岗","Nigang"},
                                               {"红岭北","Hongling_North"},
                                               {"园岭","Yuanling"},
                                               {"红岭","Hongling"},
                                               {"红岭南","Hongling_South"},
                                               {"鹿丹村","Ludancun"},
                                               {"人民南","Renming_South"},
                                               {"向西村","Xiangxicun"},
                                               {"文锦","Wenjing"}
                                           },
                                           {{"10号线","null"},
                                               {"福田口岸","Futian_Checkpoint"},
                                               {"福民","Fumin"},
                                               {"岗厦","Gangxia"},
                                               {"岗厦北","Gangxia_North"},
                                               {"莲花村","Lianhuacun"},
                                               {"冬瓜岭","Donggualing"},
                                               {"孖岭","Maling"},
                                               {"雅宝","Yabao"},
                                               {"南坑","Nankeng"},
                                               {"光雅园","Guangyayuan"},
                                               {"五和","Wuhe"},
                                               {"坂田北","Bantian_North"},
                                               {"贝尔路","Beier_Road"},
                                               {"华为","Huawei"},
                                               {"岗头","Gangtou"},
                                               {"雪象","Xuexiang"},
                                               {"甘坑","Gankeng"},
                                               {"凉帽山","Liangmao_Hill"},
                                               {"上李朗","Shanglilang"},
                                               {"木古","Mugu"},
                                               {"华南城","Huanancheng"},
                                               {"禾花","Hehua"},
                                               {"平湖","Pinghu"},
                                               {"双拥街","Shuangyong_Street"}
                                           },
                                           {{"11号线","null"},
                                               {"碧头","Bitou"},
                                               {"松岗","Songgang"},
                                               {"后亭","Houting"},
                                               {"沙井","Shajing"},
                                               {"马安山","Maan_Hill"},
                                               {"塘尾","Tangwei"},
                                               {"桥头","Qiaotou"},
                                               {"福永","Fuyong"},
                                               {"机场北","Airport_North"},
                                               {"机场","Airport_Terminal_3"},
                                               {"碧海湾","Bihaiwan"},
                                               {"宝安","Baoan"},
                                               {"前海湾","Qianhaiwan"},
                                               {"南山","Nanshan"},
                                               {"后海","Houhai"},
                                               {"红树湾南","Hongshuwan_South"},
                                               {"车公庙","Chegongmiao"},
                                               {"福田","Futian"},
                                               {"岗厦北","Gangxia_North"}
                                           },
                                           {{"12号线","null"},
                                               {"海上田园东","Waterlands_Resort_East"},
                                               {"海上田园南","Waterlands_Resort_South"},
                                               {"国展北","Shenzhen_World_North"},
                                               {"国展","Shenzhen_World"},
                                               {"福海西","Fuhai_West"},
                                               {"桥头西","Qiaotou_West"},
                                               {"福永","Fuyong"},
                                               {"怀德","Huaide"},
                                               {"福围","Fuwei"},
                                               {"机场东","Airport_East"},
                                               {"兴围","Xingwei"},
                                               {"黄田","Huangtian"},
                                               {"钟屋南","Zhongwu_South"},
                                               {"西乡桃源","Xixiang_Taoyuan"},
                                               {"平峦山","Pingluan_Hill"},
                                               {"宝田一路","Baotian_1st_Road"},
                                               {"宝安客运站","Baoan_Passenger_Transport_Terminal"},
                                               {"流塘","Liutang"},
                                               {"上川","Shangchuan"},
                                               {"灵芝","Linzhi"},
                                               {"新安公园","Xinan_Park"},
                                               {"同乐南","Tongle_South"},
                                               {"中山公园","Zhongshan_Park"},
                                               {"南头古城","Nantou_Ancient_City"},
                                               {"桃园","Taoyuan"},
                                               {"南山","Nanshan"},
                                               {"南光","Nanguang"},
                                               {"南油","Nanyou"},
                                               {"四海","Sihai"},
                                               {"花果山","Huaguoshan"},
                                               {"海上世界","Sea_World"},
                                               {"太子湾","Taiziwan"},
                                               {"左炮台东","Zuopaotai_East"}
                                           },
                                           {{"13号线","null"},
                                               {"上屋","Shangwu"},
                                               {"石岩","Shiyan"},
                                               {"罗租","Luozu"},
                                               {"应人石","Yingrenshi"},
                                               {"百旺港大","Baiwang_HKU"},
                                               {"留仙洞","Liuxiandong"},
                                               {"石鼓","Shigu"},
                                               {"西丽高铁站","Xili_High_Speed_Railway_Station"},
                                               {"高新北","Hi_Tech_North"},
                                               {"高新中","Hi_Tech_Central"},
                                               {"深大","Shenzhen_University"},
                                               {"粤海门","Yuehaimen"},
                                               {"科苑","Keyuan"},
                                               {"后海","Houhai"},
                                               {"人才公园","Talent_Park"},
                                               {"深圳湾口岸","Shenzhen_Bay_Checkpoint"}
                                           },
                                           {{"14号线","null"},
                                               {"岗厦北","Gangxia_North"},
                                               {"黄木岗","Huangmugang"},
                                               {"罗湖北","Luohu_North"},
                                               {"布吉","Buji"},
                                               {"石芽岭","Shiyaling"},
                                               {"六约北","Liuyue_North"},
                                               {"四联","Silian"},
                                               {"坳背","Aobei"},
                                               {"大运","Universiade"},
                                               {"嶂背","Zhangbei"},
                                               {"南约","Nanyue"},
                                               {"宝龙","Baolong"},
                                               {"锦龙","Jinlong"},
                                               {"坪山围","Pingshanwei"},
                                               {"坪山广场","Pingshan_Square"},
                                               {"坪山中心","Pingshan_Center"},
                                               {"坑梓","Kengzi"},
                                               {"沙田","Shatian"}
                                           },
                                           {{"16号线","null"},
                                               {"大运","Universiade"},
                                               {"大运中心","Dayun_Center"},
                                               {"龙城公园","Longcheng_Park"},
                                               {"黄阁坑","Huanggekeng"},
                                               {"愉园","Yuyuan"},
                                               {"回龙埔","Huilongpu"},
                                               {"尚景","Shangjing"},
                                               {"盛平","Shengping"},
                                               {"龙园","Longyuan"},
                                               {"双龙","Shuanglong"},
                                               {"新塘围","Xintangwei"},
                                               {"龙东","Longdong"},
                                               {"宝龙同乐","Baolong_Tongle"},
                                               {"坪山","Pingshan"},
                                               {"新和","Xinhe"},
                                               {"六和","Liuhe"},
                                               {"坪山围","Pingshanwei"},
                                               {"坪环","Pinghuan"},
                                               {"东纵纪念馆","Dongjiang_Column_Memorial_Hall"},
                                               {"沙壆","Shabo"},
                                               {"燕子湖","Yanzihu"},
                                               {"石井","Shijing"},
                                               {"技术大学","Technology_University"},
                                               {"田心","Tianxin"}
                                           },
                                           {{"20号线","null"},
                                               {"会展城","Conversation_Exhibition_City"},
                                               {"国展北","Shenzhen_World_North"},
                                               {"国展","Shenzhen_World"},
                                               {"国展南","Shenzhen_World_South"},
                                               {"机场北","Airport_North"}
                                           },
                                           {{"6号线支线","null"},
                                               {"光明","Guangming"},
                                               {"圳美","Zhenmei"},
                                               {"中大","Sun_Yat_sen_University"},
                                               {"深理工","SIAT"}
                                           }};
    //地铁线路的颜色
    const string line_color[LINENUM]={"#00b140",
                                        "#b94700",
                                        "#00a9e0",
                                        "#da291c",
                                        "#a05eb5",
                                        "#00c7b1",
                                        "#0033a0",
                                        "#b94700",
                                        "#7b6469",
                                        "#f8779e",
                                        "#672146",
                                        "#a192b2",
                                        "#de7c00",
                                        "#f2c75c",
                                        "#1e22aa",
                                        "#88dbdf",
                                        "#168773"};
    //换乘站可换乘线路
    const int transfer_matrix[18][35][3]={{{0}},
        {{0},{12},{0},{0},{0},{0},{0},{5},{0},{5,11},{0},{0},{12},{13},{0},{0},{2},{0},{0},{0},{7,9,11},{0},{3},{4},{10},{0},{6},{2},{3},{0},{0}},//1号线
        {{0},{5},{0},{12},{0},{0},{0},{0},{0},{11,13},{13},{0},{1},{0},{0},{7},{0},{0},{0},{9},{0},{3,11},{4},{10,11,14},{7},{0},{1},{0},{5},{0},{0},{0},{8}},//2号线
        {{0},{0},{0},{7},{1},{2,11},{4},{10},{7},{6},{9},{1},{0},{0},{7},{0},{0},{5,14},{0},{0},{0},{0},{0},{0},{0},{0},{14,15},{0},{0},{0},{0},{15}},//3号线
        {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{6},{5,6},{0},{0},{9},{0},{3},{2},{1},{7,10},{10}},//4号线
        {{0},{2},{0},{0},{0},{0},{9},{0},{1,11},{0},{0},{1},{0},{12},{0},{0},{13},{7},{0},{0},{0},{4,6},{0},{10},{0},{0},{0},{0},{0},{3,14},{0},{0},{7},{0},{2}},//5号线
        {{0},{11},{0},{0},{0},{0},{0},{0},{0},{0},{17},{0},{0},{0},{13},{0},{0},{0},{0},{4},{4,5},{0},{0},{9},{7},{0},{3},{1}},//6号线
        {{0},{0},{5},{0},{0},{0},{0},{0},{2},{0},{1,9,11},{0},{0},{3},{0},{4,10},{0},{0},{0},{2},{3},{14},{6},{9},{0},{0},{3},{5}},//7号线
        {{0},{2},{0},{0},{0},{0},{0},{0}},//8号线
        {{0},{5},{0},{0},{0},{0},{12},{0},{0},{13},{0},{11},{0},{0},{0},{1,7,11},{0},{2},{0},{0},{0},{4},{10},{6},{0},{7},{0},{3},{0},{0},{0},{0},{0}},//9号线
        {{0},{4},{4,7},{1},{2,11,14},{3},{0},{9},{0},{0},{0},{5},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}},//10号线
        {{0},{0},{6},{0},{0},{0},{0},{0},{12},{16},{0},{0},{0},{1,5},{12},{2,13},{9},{1,7,9},{2,3},{2,10,14}},//11号线
        {{0},{0},{0},{16},{16},{0},{0},{11},{0},{0},{1},{0},{0},{0},{0},{0},{0},{0},{0},{0},{5},{0},{0},{0},{0},{1},{11},{0},{9},{0},{0},{2},{0},{0}},//12号线
        {{0},{6},{0},{0},{0},{0},{5},{0},{0},{0},{0},{1},{9},{2},{11},{0},{0}},//13号线
        {{0},{2,10,11},{7},{0},{3,5},{0},{0},{0},{0},{3,15},{0},{0},{0},{0},{15},{0},{0},{0},{0}},//14号线
        {{0},{3,14},{0},{0},{0},{0},{0},{0},{0},{0},{3},{0},{0},{0},{0},{0},{0},{14},{0},{0},{0},{0},{0},{0},{0}},//16号线（15）
        {{0},{0},{12},{12},{0},{11}},//20号线（16）
        {{0},{6},{0},{0},{0}},//6号线支线（17）
    };
public:
    // QString sendname(int i){
    //     if(!i){
    //         return QString::fromStdString(ss);
    //     }else{
    //         return QString::fromStdString(ts);
    //     }
    // }
signals:
    void mysignal();
    void return_to_welcome();
    void sendstation(QString&,QString&);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Slider_valueChanged(int value);

    void on_horizontalScrollBar_sliderMoved(int position);

    void on_verticalScrollBar_sliderMoved(int position);

    bool eventFilter(QObject *,QEvent *);

    void station_button_clicked(QAbstractButton*);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

private:
    Ui::Map *ui;
    string ss,ts,tempss,tempts;
};

#endif // MAP_H

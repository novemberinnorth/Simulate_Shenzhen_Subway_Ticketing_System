# Simulate_Shenzhen_Subway_Ticketing_System
### 使用c++ qt6实现图形化的模拟深圳地铁自动售票系统。  
更新：里面的价格计算仅供参考（图一乐），相同始末站不会有多种价格，可以理解成价格越贵经过站数越多；  
程序尚有未知bug，等我挑个良辰吉日再改（  
### 主要文件说明  
#### • Shenzhen_metro_ticket_sale_system  
包括两张背景图片文件和所有界面的.h, .cpp, .ui文件  
注意：所有站点的中英文名称对照表、换乘站可换乘线路矩阵及线路颜色代码位于map.h和line.h中；  
map.cpp主要基于用户交互控制ui组件（控制地图和所有按钮同轴缩放、滑动条缩放等），并绑定站点英文名称和按钮编号；  
line.cpp主要计算线路方案（尤其是不同线路的始末站时涉及的广优搜索）和基于方案绘图；  
其余文件内容相对简单，参见代码注释即可  
#### • Shenzhen_metro_ticket_sale_system_v1  
利用qt release生成的依赖文件包  
#### • Shenzhen_metro_ticket_sale_system_v1.exe  
利用Enigma Virtual Box打包好的程序，可单独下载运行，无需额外安装  

基本界面运行展示：  
<img width="452" alt="欢迎" src="https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System/assets/138506109/b51644f9-bbc8-4ec2-bc69-7fae820cc0e4">  
<img width="1083" alt="屏幕截图 2023-12-27 160926" src="https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System/assets/138506109/cefae402-4cdb-4011-94f2-cd2185ae67c4">  
<img width="1083" alt="屏幕截图 2023-12-27 160727" src="https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System/assets/138506109/adae1774-cad5-44e4-8d90-062761fa8abc">  
<img width="678" alt="屏幕截图 2023-12-27 191908" src="https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System/assets/138506109/7c4f0cff-7588-4656-a10a-2dc1b04cab6a">  
<img width="678" alt="屏幕截图 2023-12-27 192005" src="https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System/assets/138506109/cb07115a-f15e-434b-8853-bd250314c577">  
<img width="678" alt="屏幕截图 2023-12-27 191934" src="https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System/assets/138506109/65696b34-13e0-4fd7-a7dc-49b6125fef34">  

地图左上角有帮助文档，内容如下：  
<h2>帮助</h2>
<h3>选站界面</h3>
<p>您可以点击输入框来选择输入起始站或终点站，可以点击按钮来选择，或直接在输入框里输入站名<br></p>
<p>拖动滑动条来缩放地图，拖动滚动条来移动地图<br></p>
<p>在右边可以预览站点的中英文名和所在线路<br></p>
<h3>选线界面</h3>
<p>点击左列的按钮来选择您的换乘方案，价格和乘车路线位于右边<br></p>
<h3>支付界面</h3>
<p>输入人数和金额，支持直接输入、按箭头输入、鼠标滚轮输入<br></p>
<p>如想更换方案，点击“我再想想”按钮即可返回选线界面<br></p>
<h2>注意事项</h2>
<h3>1.选站界面按钮本身不会放大，且在地图放大时会偏离地图中的站点</h3>
<h3>2.“福田口岸”站点的按钮位于4号线和10号线的站点之间</h3>
<h3>3.本程序将“莲塘”作为2号线与8号线的中转站</h3>
<h3>4.本程序不支持有轨电车站点的选择</h3>
<h3>5.本程序目前只录入了2024年以前的深圳地铁站点</h3>
<h3>6.本程序的价格计算公式为：2+[同一线路上起始站与终点站间的站点数/4]（向下取整），故与实际情况有所不同</h3>
<h3>7.换乘方案过多时，可能无法看到乘车路线中的文字</h3>
<h3>8.本程序不支持拖动窗口右下角来缩放</h3>
<h2>版权说明</h2>
<h3>1.欢迎界面背景图引用深圳地铁官网的线路图<br>https://www.szmc.net/shentieyunying/yunyingfuwu/szsgdjtyyxlwlt/</h3>
<h3>2.选站界面的地图引用自https://railmapgen.github.io/?app=rmp-gallery，由本人用ps修改部分站点的中英文名</h3>
<h3>3.哈尔滨工业大学（深圳）校名校徽引用自学校官网</h3>
<h3>4.其余一切代码、图片等均为本人所有，未经允许禁止引用</h3>
<h3>源代码地址：https://github.com/novemberinnorth/Simulate_Shenzhen_Subway_Ticketing_System</h3>

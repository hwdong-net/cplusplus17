初始化
```cpp
#include <iostream>
using namespace std;
int main() {
	//1. 初始化游戏中的数据
	auto WIDTH{ 120 }, HEIGHT{ 40 }; //窗口长宽
	auto ball_x {WIDTH/2}, ball_y{HEIGHT/2}, ball_vec_x{0}, ball_vec_y{0}; //球位置及速度
	auto paddle_w{4}, paddle_h{10};   //挡板的长宽
	auto paddle1_x{0}, paddle1_y{HEIGHT/2-paddle_h/2}, paddle1_vec{3}; //挡板1位置及速度
	auto paddle2_x{ WIDTH - paddle_w }, 
               paddle2_y{ HEIGHT/2 - paddle_h/2 }, paddle2_vec{3}; //挡板2位置及速度
        auto score1{ 0 }, score2{ 0 };  //双方的得分
	return 0;
}
```
绘制场景
```cpp
int main() {
        //…

	//2. 绘制场景
	//2.1绘制背景
	//2.1.1 先绘制背景中的顶部墙	
	for (auto x = 0; x <= WIDTH; x++)
		std::cout << '=';
	std::cout << '\n';
	//2.1.2 绘制背景中的3条的竖线	
	for (auto y = 0; y <= HEIGHT; y++) {		
           for (auto x = 0; x <= WIDTH; x++)
	     if (x == 0 || x == WIDTH / 2 || x == WIDTH)
		std::cout << '|';
	     else std::cout << ' ';
		std::cout << '\n' ;
	}
	//2.1.3 绘制背景中的底部墙	
	for (auto x = 0; x <= WIDTH; x++)
	   std::cout << '=';
	std::cout << '\n';
}
```

绘制挡板和球：
```cpp
for (auto y = 0; y <= HEIGHT; y++) {		
   for (auto x = 0; x <= WIDTH; x++)
     if(x==ball_x&&y==ball_y)                            //球的位置
	std::cout << 'O';
     else if (y>= paddle1_y &&y < paddle1_y + paddle_h
		&&x>= paddle1_x && x < paddle1_x + paddle_w) {   //左挡板位置
	std::cout << 'Z';
     }
     else if (y >= paddle2_y && y < paddle2_y + paddle_h
		&& x >= paddle2_x && x < paddle2_x + paddle_w) {   //右挡板位置
	std::cout << 'Z';
     }
     else if (x == 0 || x == WIDTH  / 2 || x == WIDTH)         //竖线位置
	std::cout << '|';
     else std::cout << ' ';
	std::cout << '\n' ;
}
```

游戏是一个循环，循环每一步绘制新的画面：
```cpp
初始化游戏数据
循环（直到游戏结束）{
    处理事件（如用户输入、定时器）
    更新游戏状态（游戏中的数据）
    绘制游戏画面
}
```
清除游戏画面：
```cpp
#include <windows.h>
void gotoxy(int x, int y){
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
```
只要在每次绘制新的画面前，调用这个函数gotoxy(0,0)将光标定位在左上角就相当于清除了屏幕的内容。

隐藏光标
```cpp
void hideCursor(){
   CONSOLE_CURSOR_INFO cursor_info = {1, 0};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
```
给球一个随机的初始速度
```cpp
srand((unsigned)time(0));                 //生成随机数种子	
    ball_vec_x = rand() % 3 + 1;                //生成一个随机整数，表示x和y方向的速度大小
    ball_vec_y = rand() % 3 + 1;
    if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;  //随机改变初始的速度方向
    if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
```
srand()函数用于生成一个随机数种子，然后用rand()函数生成一个整数，通过%运算，使得代表速度的整数不至于过大。

在游戏循环中根据速度不断更新球的位置，并绘制游戏画面，就能让球动起来。
```cpp
ball_x += ball_vec_x;   //根据速度改变位置
ball_y += ball_vec_y;
```

完整代码如下：
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
   COORD coord = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
   CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main() {
   //1. 初始化游戏中的数据
   auto WIDTH{ 120 }, HEIGHT{ 40 }; //窗口长宽
   auto ball_x {WIDTH/2}, ball_y{HEIGHT/2}, ball_vec_x{0}, ball_vec_y{0};
   auto paddle_w{4}, paddle_h{10};
   auto paddle1_x{0}, paddle1_y{HEIGHT/2-paddle_h/2}, paddle1_vec{3};
   auto paddle2_x{WIDTH-paddle_w}, 
       paddle2_y{HEIGHT/2-paddle_h/2},paddle2_vec{3};	
	
   srand((unsigned)time(0));  //生成随机数种子	
   ball_vec_x = rand() % 3 + 1; //生成一个随机整数
   ball_vec_y = rand() % 3 + 1;
   if (rand() % 2 == 1) ball_vec_x = -ball_vec_x; 
   if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;

   //游戏循环
   while (true) {
      // 1. 处理事件
		
      // 2. 更新数据 
      ball_x += ball_vec_x;
      ball_y += ball_vec_y;

      gotoxy(0, 0);  //定位到(0,0)，相当于清空屏幕
      hideCursor();  //隐藏光标
	
      // 3. 绘制场景		
      //3.1绘制背景
      //3.1.1 先绘制背景中的顶部墙	
      for(auto x = 0; x <= WIDTH; x++)
	  std::cout << '=';
      std::cout << '\n';
      
      //3.1.2 绘制背景中的3条的竖线、球、挡板	
      for (auto y = 0; y <= HEIGHT; y++) {
	 for (auto x = 0; x <= WIDTH; x++) {
	     /*
				int  xdiff{ x - WIDTH/2 }, y_diff{ y - HEIGHT/2 },
					diff = xdiff * xdiff + y_diff * y_diff;
				if (abs(diff -pong_circle_r2)<2)
					std::cout << '|';
				else */
	     if (ball_x == x && ball_y == y)
		 std::cout << 'O';
	     else if (y >= paddle1_y && y < paddle1_y + paddle_h
			&& x >= paddle1_x && x < paddle1_x + paddle_w) {
		 std::cout << 'Z';
	     }
	     else if (y >= paddle2_y && y < paddle2_y + paddle_h
			&& x >= paddle2_x && x < paddle2_x + paddle_w) {
		 std::cout << 'Z';
	     }
	     else if (x == 0 || x == WIDTH / 2 || x == WIDTH)
		 std::cout << '|';
	     else std::cout << ' ';
	 }
	 std::cout << '\n';
      }

     //3.1.3 绘制背景中的底部墙	
     for (auto x = 0; x <= WIDTH; x++)
	std::cout << '=';
     std::cout << '\n';
   }
   return 0;
}
```

// 2. 碰撞检测和更新数据 
```cpp
ball_x += ball_vec_x;
ball_y += ball_vec_y;
if (ball_y < 0 || ball_y >= HEIGHT)           //和上下墙碰撞，改变垂直速度方向
   ball_vec_y = -ball_vec_y;
        
if (ball_x < paddle_w&& ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h)
{ //和左挡板碰撞，改变水平速度的方向
    ball_vec_x = -ball_vec_x;
    score1 += 1;
}
else if(ball_x >WIDTH - paddle_w && ball_y >= paddle2_y 
  && ball_y < paddle2_y + paddle_h)
 { //和右挡板碰撞，改变水平速度的方向
    ball_vec_x = -ball_vec_x;
    score2 += 1;
}
		
bool is_out{ false };              //是否跑出沟渠的bool标志
if (ball_x < 0) {score2 += 1; is_out = true;		}
else if (ball_x >WIDTH-paddle_w) {score1 += 1; is_out = true;	}
if (is_out) {                  //跑出左右沟渠，球回到中心并以新的随机速度出发
  ball_x = WIDTH / 2; ball_y = HEIGHT / 2;
  ball_vec_x = rand() % 3 + 1;
  ball_vec_y = rand() % 3 + 1;
  if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
  if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
}
```

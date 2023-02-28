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

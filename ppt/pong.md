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
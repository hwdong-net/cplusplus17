#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

#include <windows.h>
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
	auto WIDTH{ 90 }, HEIGHT{ 25 }; //窗口长宽
	auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }, ball_vec_x{ 0 }, ball_vec_y{ 0 }; //球位置及速度
	auto paddle_w{ 3 }, paddle_h{ 8 };   //挡板的长宽
	auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }, paddle1_vec{ 3 }; //挡板1位置及速度
	auto paddle2_x{ WIDTH - paddle_w },
		paddle2_y{ HEIGHT / 2 - paddle_h / 2 }, paddle2_vec{ 3 }; //挡板2位置及速度
	auto score1{ 0 }, score2{ 0 }, score1_x{ paddle_w + 8 }, score1_y{ 2 },
		score2_x{ WIDTH - 8 - paddle_w }, score2_y{ 2 };


	srand((unsigned)time(0));  //生成随机数种子	
	ball_vec_x = rand() % 5 + 1; //生成一个随机整数
	ball_vec_y = rand() % 5 + 1;
	if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
	if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;


	while (true) {
		// 1. 处理事件
		char key;
		if (_kbhit()) {                          //键盘有输入
			key = _getch();                    //得到输入的键值
			if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
				paddle1_y -= paddle1_vec;
			else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h
				< HEIGHT)
				paddle1_y += paddle1_vec;
			else if (key == 72 && paddle2_y > paddle2_vec)
				paddle2_y -= paddle2_vec;
			else if ((key == 80) && paddle2_y + paddle2_vec + paddle_h < HEIGHT)
				paddle2_y += paddle2_vec;
		}


		// 2. 更新数据 	
		std::string s1{std::to_string(score1) }, s2{ std::to_string(score2) };

		ball_x += ball_vec_x;
		ball_y += ball_vec_y;
		if (ball_y < 0 || ball_y >= HEIGHT)           //和上下墙碰撞，改变垂直速度方向
			ball_vec_y = -ball_vec_y;

		if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h)
		{ //和左挡板碰撞，改变水平速度的方向
			ball_vec_x = -ball_vec_x;
			score1 += 1;
		}
		else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y
			&& ball_y < paddle2_y + paddle_h)
		{ //和右挡板碰撞，改变水平速度的方向
			ball_vec_x = -ball_vec_x;
			score2 += 1;
		}
		bool is_out{ false };              //是否跑出沟渠的bool标志
		if (ball_x < 0) { score2 += 1; is_out = true; }
		else if (ball_x > WIDTH ) { score1 += 1; is_out = true; }
		if (is_out) {                  //跑出左右沟渠，球回到中心并以新的随机速度出发
			ball_x = WIDTH / 2; ball_y = HEIGHT / 2;
			ball_vec_x = rand() % 5 + 1;
			ball_vec_y = rand() % 5 + 1;
			if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
			if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
		}

		gotoxy(0, 0);  //定位到(0,0)，相当于清空屏幕
		hideCursor();  //隐藏光标

		//3. 绘制场景
		//3.1绘制背景
		//3.1.1 先绘制背景中的顶部墙	
		for (auto x = 0; x <= WIDTH; x++)
			std::cout << '=';
		std::cout << '\n';
		//2.1.2 绘制背景中的3条的竖线	
		for (auto y = 0; y <= HEIGHT; y++) {
			for (auto x = 0; x <= WIDTH; x++) {
				if (x == ball_x && y == ball_y)                     //球的位置
					std::cout << 'O';
				else if (y >= paddle1_y && y < paddle1_y + paddle_h
					&& x >= paddle1_x && x < paddle1_x + paddle_w) {   //左挡板位置
					std::cout << 'Z';
				}
				else if (y >= paddle2_y && y < paddle2_y + paddle_h
					&& x >= paddle2_x && x < paddle2_x + paddle_w) {   //右挡板位置
					std::cout << 'Z';
				}
				else if (y == score1_y && x == score1_x) { //左分数位置
					std::cout << s1;
					//while (x < score1_x + s1.size()) x++;
					x += s1.size();
					x--;
				}
				else if (y == score2_y && x == score2_x) {//右分数位置
					std::cout << s2;
					//while (x < score2_x + s2.size()) x++;
					x += s2.size();
					x--;
				}
				else if (x == 0 || x == WIDTH / 2 || x == WIDTH) //三条
					std::cout << '|';
				else std::cout << ' ';
			}
			std::cout << '\n';
		}
		//2.1.3 绘制背景中的底部墙	
		for (auto x = 0; x <= WIDTH; x++)
			std::cout << '=';
		std::cout << '\n';

	}

	return 0;
}

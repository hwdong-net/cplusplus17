/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   qq群：101132160
   微信公众号：hwdong编程
   C++17从入门到精通（源代码）：https://github.com/hwdong-net/cplusplus17
*/

#include <iostream>
using color = char;  //定义一个表示颜色的color类型，每种字符就是一种颜色
color* framebuffer{ nullptr };          //帧缓冲器
int framebuffer_width, framebuffer_height;
color clear_color{ ' ' };                //清屏颜色  

bool initWindow(int width, int height);  //初始化一个窗口，返回bool值表示成功还是失败
void clearWindow();               //清空窗口内容
void destoryWindow();             //销毁窗口，释放帧缓冲器占用的内存
void show();                      //显示帧缓冲区的图像
void setPixel(const int x, const int y, color c = ' ');            //设置像素的颜色
color getPixel(const int x, const int y);                       //设置像素的颜色
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

//初始化一个窗口，返回bool值表示成功还是失败
bool initWindow(int width, int height) {

	framebuffer = new color[width*height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}

//用清屏颜色clear_color清空窗口内容
void clearWindow() {
	if (!framebuffer) return;
	for (int y = 0; y < framebuffer_height; y++)
		for (int x = 0; x < framebuffer_width; x++)
			framebuffer[y*framebuffer_width + x] = clear_color;

}

//销毁窗口，释放帧缓冲器占用的内存
void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//显示帧缓冲区的图像
void show() {
	for (int y = 0; y < framebuffer_height; y++) {
		for (int x = 0; x < framebuffer_width; x++)
			std::cout << framebuffer[y*framebuffer_width + x];
		std::cout << '\n';
	}
}

void setPixel(const int x, const int y, color c) {
	framebuffer[y*framebuffer_width + x] = c;
}

color getPixel(const int x, const int y) {
	return framebuffer[y*framebuffer_width + x];
}


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>

//1. 初始化游戏中的数据
int ball_x, ball_y, ball_vec_x{0}, ball_vec_y{ 0 }; //球位置和速度
int paddle_w, paddle_h;   //挡板的长宽
int paddle1_x, paddle1_y, paddle1_vec{0}; //左挡板位置和速度
int paddle2_x, paddle2_y, paddle2_vec{0};       //右挡板位置和速度
int score1{ 0 }, score2{0}, score1_x, score1_y, score2_x, score2_y; //得分及得分的显示位置
color boundary_color{'|'}, ball_color{ 'O' }, wall_color{ '=' }, paddle_color{ 'Z' };

//初始化球的位置和速度
void random_ball(const int window_width, const int window_height) {
	ball_x = window_width / 2; ball_y = window_height / 2;
	ball_vec_x = rand() % 3 + 1;    //生成一个随机整数表示球的横向速度
	ball_vec_y = rand() % 3 + 1;    //生成一个随机整数表示球的纵向速度
	if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;  //速度可以使负数
	if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;  //速度可以使负数
}



bool init(const int window_width=100,const int window_height=40){
	if (!initWindow(window_width, window_height)) {  // 初始化窗口
		return false;
	}	
	
	ball_x = window_width / 2;
	ball_y = window_height / 2; 

	paddle_w = 4; paddle_h = 10;
	paddle1_x = 0; paddle1_y = window_height / 2 - paddle_h / 2;	
	paddle2_x = window_width - paddle_w; paddle2_y = paddle1_y;
	paddle1_vec = 3;  paddle2_vec = 3 ;

	score1 = 0; score2 = 0; 
	score1_x = paddle_w + 8;           score1_y = 2;
	score2_x = window_width - 8 - paddle_w; score2_y=2;
//	auto pong_circle_r2{ 40 };  //禁区半径的平方
	
	srand((unsigned)time(0));  //生成随机数种子
	random_ball(window_width, window_height);
	return true;
}

//绘制背景:包括上下墙壁、左右沟渠和中间分割线

void draw_background() {
	clearWindow();               //清空为背景颜色	

	int &window_width = framebuffer_width,
		&window_height = framebuffer_height;

	auto right{ window_width - 1 }, middle{ window_width / 2 };
	for (int y = 0; y < window_height; y++) {
		setPixel(0, y, boundary_color);	
		setPixel(middle, y, boundary_color);
		setPixel(right, y, boundary_color);
	}

	int bottom = window_height - 1;	
	for (int x = 0; x < window_width; x++) {
		setPixel(x,0, wall_color);
		setPixel(x,bottom,wall_color);		
	}
}

//draw_sprites()绘制场景中的精灵：球、挡板和得分。
void draw_sprites() {	
	//绘制球
	setPixel(ball_x, ball_y, ball_color);	
	//绘制左、右挡板
	for (auto y = paddle1_y; y < paddle1_y + paddle_h; y++)
		for (auto x = paddle1_x; x < paddle1_x + paddle_w; x++)
			setPixel(x,y, paddle_color);	

	for (auto y = paddle2_y; y < paddle2_y + paddle_h; y++)
		for (auto x = paddle2_x; x < paddle2_x + paddle_w; x++)
			setPixel(x,y, paddle_color);
			
	//绘制分数：分数是一个字符串
	std::string s1{ std::to_string(score1) }, s2{ std::to_string(score2) };
	for (auto i = 0; i < s1.size(); i++)
		setPixel(score1_x + i, score1_y, s1[i]);
	for (auto i = 0; i < s2.size(); i++)
		setPixel(score2_x + i, score2_y, s2[i]);		
}


void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void render_scene() {
	gotoxy(0, 0);  //定位到(0,0)，相当于清空屏幕
	hideCursor();  //隐藏光标
	draw_background();   //在画布上绘制背景
	draw_sprites();        //在画布上绘制精灵
	show();              //在屏幕上显示画布内容（场景）
}

int processInput() {	
	int &height = framebuffer_height;
	//  处理事件
	char key;
	if (_kbhit()) {
		key = _getch();
		if (key == 27) return -1;
		else if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
			paddle1_y -= paddle1_vec;
		else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h
			< height)
			paddle1_y += paddle1_vec;
		else if (key == 72 && paddle2_y > paddle2_vec)
			paddle2_y -= paddle2_vec;
		else if ((key == 80) && paddle2_y + paddle2_vec + paddle_h < height)
			paddle2_y += paddle2_vec;
	}
	return 0;
}

void update() {
	int &width = framebuffer_width;
	int &height = framebuffer_height;
	// 2. 更新数据 
	ball_x += ball_vec_x;
	ball_y += ball_vec_y;
	if (ball_y < 0 || ball_y >= height) {
		ball_vec_y = -ball_vec_y;
		ball_y += ball_vec_y;
	}
	if (ball_x < paddle_w&& ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
		ball_vec_x = -ball_vec_x;
		score1 += 1;
	}
	else if (ball_x > width - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
		ball_vec_x = -ball_vec_x;
		score2 += 1;
	}
	bool is_out{ false };
	if (ball_x < 0) { score2 += 1; is_out = true; }
	else if (ball_x >= width) { score1 += 1; is_out = true; }
	if (is_out) {
		random_ball(width,height);
	}
}


//可以编写一个简单的函数测试一下。
int Pong() {
	if (!init()) {
		std::cout << "初始化窗口失败！\n";
		return 1; 
	}
	//2.  游戏循环
	while (true) {
		if (processInput() < 0)break;
		update();
		render_scene();
	}
	return 0;
}


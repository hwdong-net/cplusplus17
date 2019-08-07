/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


//1. 初始化游戏中的数据
const int  WIDTH{ 100 }, HEIGHT{ 30 };   //窗口的长宽
auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }, ball_vec_x{ 0 }, ball_vec_y{ 0 };
auto paddle_w{ 4 }, paddle_h{ 10 };
auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }, paddle1_vec{ 3 };
auto paddle2_x{ WIDTH - paddle_w }, paddle2_y{ HEIGHT / 2 - paddle_h / 2 },
paddle2_vec{ 3 };
auto score1{ 0 }, score2{ 0 }, score1_x{ paddle_w + 8 }, score1_y{ 2 },
score2_x{ WIDTH - 8 - paddle_w }, score2_y{ 2 };

//==========画布==========
const int canvas_width{ WIDTH }, canvas_height{ HEIGHT };   //画布canvas的长宽
char canvas[canvas_height][canvas_width];   //画布内容是一个“像素是字符”的
										//矩阵（矩形区域）
#define background_color ' '  //背景颜色用空格字符' '表示
#define boundary_color '|'  //背景颜色用空格字符'|'表示
#define wall_color '='    //墙壁颜色用字符'='表示
#define ball_color 'O'    //球颜色用字符'O'表示
#define paddle_color 'Z'    //挡板颜色用字符'Z'表示

void random_ball() {
	ball_x = WIDTH / 2; ball_y = HEIGHT / 2;
	ball_vec_x = rand() % 3 + 1; //生成一个随机整数
	ball_vec_y = rand() % 3 + 1;
	if (rand() % 2 == 1) ball_vec_x = -ball_vec_x;
	if (rand() % 2 == 1) ball_vec_y = -ball_vec_y;
}

void init() {
	srand((unsigned)time(0));  //生成随机数种子	
	random_ball();
}

//---------清空画布--------
void clear_canvas() {
	for (int y = 0; y < canvas_height; y++)
		for (int x = 0; x < canvas_width; x++)
			canvas[y][x] = background_color;
}
void show() {
	for (int y = 0; y < canvas_height; y++) {
		for (int x = 0; x < canvas_width; x++)
			std::cout << canvas[y][x];
		std::cout << '\n';
	}
}
void draw_background() {
	clear_canvas();               //画布清空为背景颜色
	auto right{ canvas_width -1 }, middle{ canvas_width / 2 };
	for (auto y = 0; y < canvas_height; y++) {
		canvas[y][0] = boundary_color;		
		canvas[y][middle] = boundary_color;
		canvas[y][right] = boundary_color;
	
	}
	int bottom = canvas_height - 1;
	for (auto x = 0; x < canvas_width; x++) {
		canvas[0][x] = wall_color;
		canvas[bottom][x] = wall_color;
	}
}

void draw_sprites() {	
	//绘制球
	canvas[ball_y][ball_x] = ball_color;
	//绘制左、右挡板
	for (auto y = paddle1_y; y < paddle1_y+ paddle_h; y++) 
		for (auto x = paddle1_x; x < paddle1_x + paddle_w; x++) 
			canvas[y][x] = paddle_color;
	
	for (auto y = paddle2_y; y < paddle2_y + paddle_h; y++)
		for (auto x = paddle2_x; x < paddle2_x + paddle_w; x++)
			canvas[y][x] = paddle_color;	
	//绘制分数
	std::string s1{ std::to_string(score1) }, s2{ std::to_string(score2) };
	for (auto i = 0;i< s1.size();i++)
		canvas[score1_y][score1_x+i] = s1[i];
	for (auto i = 0; i < s2.size(); i++)
		canvas[score2_y][score2_x + i] = s2[i];
	
}

void render_scene() {
	gotoxy(0, 0);
	hideCursor();
	draw_background();
	draw_sprites();
	show();
}

int main_x() {
	render_scene();
	return 0;
}


int processInput() {
	//  处理事件
	char key;
	if (_kbhit()) {
		key = _getch();
		if (key == 27) return -1;
		else if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
			paddle1_y -= paddle1_vec;
		else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h < HEIGHT)
			paddle1_y += paddle1_vec;
		else if (key == 72 && paddle2_y > paddle2_vec)
			paddle2_y -= paddle2_vec;
		else if ((key == 80) && paddle2_y + paddle2_vec + paddle_h < HEIGHT)
			paddle2_y += paddle2_vec;
	}
	return 0;
}




void update() {
	// 2. 更新数据 
	ball_x += ball_vec_x;
	ball_y += ball_vec_y;
	
	if (ball_y < 0|| ball_y >= HEIGHT) {
		ball_vec_y = -ball_vec_y;	
		ball_y += ball_vec_y;
	}
	
	if (ball_x < paddle_w&&ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
			ball_vec_x = -ball_vec_x;
			score1 += 1;	
	}
	else if (ball_x > WIDTH - paddle_w&&ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
			ball_vec_x = -ball_vec_x;
			score2 += 1;
	}
	bool is_out{ false };
	if (ball_x < 0) { score2 += 1; is_out = true; }
	else if(ball_x>=WIDTH) { score1 += 1; is_out = true; }
	if (is_out) {		
		random_ball();
	}
}

int main() {
	//1. 初始化数据
	init();
	//2.  游戏循环
	while (true) {
		if (processInput() < 0)break;
		update();
		render_scene();
	}
	return 0;
}
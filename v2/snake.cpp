#include <iostream>
using Color = unsigned char;     //用字符表示颜色

class Window {
	int width{ 60 }, height{ 50 }; //窗口
	Color bg_color{ ' ' };     //背景颜色用空格字符表示
	Color *frame_buffer{ nullptr }; //帧缓存，彩色图像的显示器内存
public:
	Window(int w, int h, Color bgColor) //构造一个窗口对象
		:width{ w }, height{ h }, bg_color{ bgColor },
		frame_buffer{ new Color[w*h] }{	}
	~Window() {
		delete[] frame_buffer;       //删除动态内存
	}
	//绘制一个(x,y)处的像素，即给该像素一个颜色Color
	void set_pixel(int x, int y, Color color) {
		auto k = y * width + x;
		frame_buffer[k] = color;
	}

	//查询(x,y)处像素的颜色
	Color get_pixel(const int x, const int y) const {
		auto k = y * width + x;
		return frame_buffer[k];
	}

	//---------清空窗口--------
	void clear() {
		if (!frame_buffer) return;
		auto n = width * height;
		for (auto i = 0; i != n; i++)
			frame_buffer[i] = bg_color; //设置该像素为背景颜色
	}

	//--------显示窗口的内容
	void show() {
		for (auto y = 0, k = 0; y < height; y++) {
			for (auto x = 0; x < width; x++, k++)
				std::cout << frame_buffer[k];
			std::cout << '\n';
		}
	}

	int get_width() { return width; }
	int get_height() { return height; }
	Color get_bg_color() { return bg_color; }
};

class BackGround {
	Color top_boundary_color{ ' ' }, bottom_boundary_color{ '_' };
	Color left_right_boundary_color{ '|' };
public:
	void draw(Window &window) {
		auto right{ window.get_width() - 1 };
		auto bottom{ window.get_height() - 1 };
		for (auto x = 0; x < window.get_width(); x++) {
			window.set_pixel(x, 0, top_boundary_color);
			window.set_pixel(x, bottom, bottom_boundary_color);
		}

		for (auto y = 0; y < window.get_height(); y++) {
			window.set_pixel(0, y, left_right_boundary_color);
			window.set_pixel(right, y, left_right_boundary_color);
		}
	}
};

class Egg {
	int x, y;      //鸡蛋位置
	int size{ 1 };  //鸡蛋大小
	Color color;  //鸡蛋颜色
public:
	Egg(int x, int y, Color color ='G', int s = 1) :x{ x }, y{ y },
		size{ s }, color(color){}
	void draw(Window& window) {  //在canvas表示的画布上绘制鸡蛋形状
		window.set_pixel(x, y, color);
	}
	Color get_color() { return color; }
};
//表示一个位置
class Position {
	int x{ 0 }, y{ 0 };
public:
	Position(int x = 0, int y = 0) :x{ x }, y{ y }{}
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	auto get_x() { return x; }
	auto get_y() { return y; }
};
//一个蛇身像素在内存中的结点表示
class SnakeNode {
	Position pos{};                      //蛇身像素位置
	SnakeNode* next{ nullptr };            //下一个蛇身像素结点的指针
public:
	SnakeNode(const Position pos, SnakeNode* n = nullptr)
		:pos{ pos }, next{ n }{}
	Position get_pos() { return pos; }
	SnakeNode* get_next() { return next; }   //返回该结点的next值，即指向下一个结点的指针
	void set_next(SnakeNode* n) { next = n; } //修改next值
};

class Snake {
	//蛇身用2个结点指针变量分别指向链表的头结点和尾结点。
	SnakeNode *head{ nullptr }, *tail{ nullptr };
	int direction{};               //蛇前进方向
	Color body_color, head_color;
	bool is_dead{ false };                  //蛇是否死亡
	int width{ 0 }, height{ 0 };
	bool eating{ false };
public:
	//初始化窗口范围[width，height]里指定长度的一条蛇
	Snake(const int width, const int height, int length = 3,
		Color body_color = 'o', Color head_color = '@');
	
	void draw(Window& window);              //在画布canvas上绘制自己形状

	//沿给定方向前进，前进过程中需要检查是否发生了碰撞	
	void move();
	void eat(bool eating);      //吃了一个鸡蛋
	void set_direction(int d) {           //设置蛇的运动方向
		if(d== 0 && direction == 1 ||
			d == 1 && direction == 0 ||
			d == 2 && direction == 3 ||
			d == 3 && direction == 3) return;
		direction = d; 
	} 

	SnakeNode *get_head() { return head; } //返回链表的头结点
	SnakeNode *get_tail() { return tail; } //返回链表的尾结点
	Color get_body_color() { return body_color; }
	Color get_head_color() { return head_color; }
	void print() {
		std::cout << direction << "\n";
		SnakeNode *p = head->get_next();
		while (p != tail) {                          //遍历每个蛇身结点
			std::cout<<p->get_pos().get_x()<<" "<<
				p->get_pos().get_y()<<std::endl;  //在画布中设置这个蛇身像素结点的颜色
			p = p->get_next();                    //指针p向后移动，指向下一个结点
		}
		std::cout << "\n\n";
	}
};

#include <cstdlib>
#include <ctime>
inline int random_int(const int x_min, const int x_max) {
	static bool is_seeded = false;
	if (!is_seeded) {
		srand((unsigned)time(0));  //生成随机数种子
		is_seeded = true;
	}
	return rand() % (x_max - x_min) + x_min;
}


Snake::Snake(const int width, const int height, int length,
	Color body_color, Color head_color) {
	this->width = width;
	this->height = height;
	this->body_color = body_color;
	this->head_color = head_color;

	//生成随机的蛇的位置
	auto x_min{ length + 1 }, x_max{ width - x_min },
		y_min{ length + 1 }, y_max{ height - y_min };
	auto x = random_int(x_min, x_max);
	auto y = random_int(y_min, y_max);

	SnakeNode *p = new SnakeNode(Position(x, y)); //创建蛇头结点
	tail = p;                                     //该结点是链表的尾结点（最后的结点）
	head = new SnakeNode(Position(), p);         //创建整个链表的头结点
	direction = random_int(0, 4);                //生成随机的0,1,2,3	
 	for (auto i = 1; i != length; i++) {         //生成其他的蛇身结点
		if (direction == 0) y++;          //蛇头向上，蛇身向下
		else if (direction == 1) y--;     //蛇头向下
		else if (direction == 2) x++;     //蛇头向左，蛇身向右
		else x--;                         //蛇头向右
		p = new SnakeNode(Position(x, y), head->get_next());
		head->set_next(p);
	}
}

void Snake::draw(Window& window){
	SnakeNode *p = head->get_next();
	while (p != tail) {                          //遍历每个蛇身结点
		window.set_pixel(p->get_pos().get_x(),
			p->get_pos().get_y(), body_color);  //在画布中设置这个蛇身像素结点的颜色
		p = p->get_next();                    //指针p向后移动，指向下一个结点
	}
	window.set_pixel(p->get_pos().get_x(),        //在画布上绘制蛇头结点
		p->get_pos().get_y(), head_color);
}


void Snake::eat(bool eating) {	
	this->eating = eating;
}

void Snake::move() {
	auto head_pos = tail->get_pos();             //当前蛇头位置，注意：链表尾部表示蛇头
	//根据前进方向，确定新的蛇头位置，
	auto x{ head_pos.get_x() }, y{ head_pos.get_y() };
	if (direction == 0)                      //向上移动，y--
		--y;	
	else if (direction == 1)                 //向下移动，y++
		++y;	
	else if (direction == 2)                //左键-->向左移动，y--
		--x;	
	else                                //右键-->向右移动，
		++x;
	
	//创建新的蛇头，加入到链表的尾部。
	SnakeNode *p = new SnakeNode(Position( x,y));    //创建新的结点
	tail->set_next(p);      //p加到尾结点(tail)的后面，即蛇头结点的后面
	tail = p;             // p成为新的链表尾结点。即p成为了新蛇头结点
	//如果没有吃鸡蛋，则删除蛇尾结点
	if (!eating) {
		//删除代表蛇尾的链表首结点（头结点后的那个结点）
		p = head->get_next();            //p指向首结点
		head->set_next(p->get_next());    //p的next结点成为head的后一个结点
		delete p;                       //释放p结点占用的内存
	}
	//否则，正吃了一个鸡蛋，不用删除蛇尾结点。但应清空吃蛋标志
	else eating = false;  //鸡蛋已经吃完
}

#include <windows.h>
inline void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
inline void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


class GameEngine {
	Window *window{ nullptr };
	bool running{true};    //游戏是否正在运行的标志
	bool start{ false };   //游戏是否开始
	BackGround bg;
	Snake *snake{ nullptr };
	Egg *egg{ nullptr };
public:
	GameEngine(const int w = 50, const int h = 40) {
		window = new Window(w, h, ' ');
		//创建Snake对象	
		snake = new Snake(w, h, 4);		//构造一个位置随机的蛇Snake对象
		//创建随机位置的Egg对象
		auto x = random_int(2, w - 10);
		auto y = random_int(2, h - 10);
		egg = new Egg(x, y);
	}
	~GameEngine() {
		delete window; delete snake;delete egg;
	}
	//…
	void render() {
		gotoxy(0, 0);
		hideCursor();
		window->clear();
		draw_scene();
		window->show();		
	}
	void draw_scene() {
		bg.draw(*window);
		if(snake)snake->draw(*window);        //让蛇绘制自己
		if (egg)	egg->draw(*window);  //让鸡蛋绘制自己
	}
	
	void run() {	
		while (running) {
			collosion();
			processEvent();
			update();			
			render();
		}
		quit();
	}

	void processEvent() {//  处理事件
		//  处理事件
		char key;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) running = false;
			else if (key == ' ') start = !start;
			else {
				start = true;
				if (key == KEY_UP)
					snake->set_direction(0);
				else if (key == KEY_DOWN)
					snake->set_direction(1);
				else if (key == KEY_LEFT)
					snake->set_direction(2);
				else if (key == KEY_RIGHT)
					snake->set_direction(3);
			}
		}
	}
	void update() { if(start) snake->move(); }
	void collosion() {
		if (!start) return;
		auto tail = snake->get_tail();
		auto pos = tail->get_pos();//蛇头位置
		auto x{ pos.get_x() }, y{ pos.get_y() };

		if (x == 0 || y == 0 || x == window->get_width() - 1
			|| y == window->get_height() - 1) {
			running = false; //超出窗口，蛇死亡,游戏结束
			return;
		}		

		Color color = window->get_pixel(x, y);       //得到该位置的颜色
		if (color == window->get_bg_color()) return;  //未发生碰撞

	
		if (color != snake->get_head_color()) {
			if (egg&&color == egg->get_color()) {      //遇到了鸡蛋
				snake->eat(true);
				delete egg;  egg = nullptr;  //销毁鸡蛋				
				auto x = random_int(2, window->get_width() - 10);
				auto y = random_int(2, window->get_height() - 10);
				egg = new Egg(x, y);
				
			}
			else {//和墙或自身发生碰撞,游戏结束
				running = false;//和墙或自身发生碰撞,游戏结束
				return;
			}
		}		
	}
	void quit() {}

};

#if 0
int main() {
	GameEngine game;
	game.run();
}
#endif
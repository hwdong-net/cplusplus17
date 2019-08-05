#include <iostream>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


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


using Color = unsigned char;

class Canvas {
	int width{60},height{50 }; //窗口
	Color bg_color{ ' ' };
	Color *frame_buffer{ nullptr }; //帧缓存，彩色图像的显示器内存
public:
	Canvas(int w, int h, Color bgColor) 
		:width{ w }, height{ h }, bg_color{ bgColor },
		frame_buffer{ new Color[w*h] }{}
	

	//绘制一个(x,y)处的像素，即给该像素一个颜色Color
	void set_pixel(int x, int y,Color color) {
		auto k = y * width + x;
		frame_buffer[k] = color;
	}

	//查询(x,y)处像素的颜色
	Color get_pixel(const int x, const int y) const{
		auto k = y * width + x;
		return frame_buffer[k];
	}

	//---------清空画布--------
	void clear() {
		if (!frame_buffer) return;
		auto n = width * height;
		for (auto i = 0; i != n; i++)
			frame_buffer[i] = bg_color;
	}

	//--------显示画布canvas中的内容
	void show() {
		for (auto y = 0,k=0; y < height; y++) {
			for (auto x = 0; x < width; x++,k++)
				std::cout << frame_buffer[k];
			std::cout << '\n';
		}
	}

	int get_width() { return width; }
	int get_height() { return height; }
	Color get_bg_color() { return bg_color; }
};

class Egg {	
	int x, y;
	int size{ 1 };
	Color color;
public:
	Egg(int x, int y, Color color='G', int s = 1) :x{x}, y{y},
		size{s}, color(color){}
	void draw(Canvas& canvas) {
		canvas.set_pixel(x, y,color);
	}
	Color get_color() { return color; }
};

//表示一个位置
class Position {
	int x{ 0 }, y{ 0 };
public:
	Position(int x=0, int y=0) :x{ x }, y{ y }{}
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	auto get_x() { return x; }
	auto get_y() { return y; }
};
//一个蛇身像素在内存中的结点表示
class SnakeNode{
	Position pos{};
	SnakeNode* next{nullptr};
public:
	SnakeNode(const Position pos, SnakeNode* n = nullptr)
		:pos{pos}, next{ n }{}
	Position get_pos() { return pos; }
	SnakeNode* get_next() { return next; }
	void set_next(SnakeNode* n) { next = n; }
};


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Snake {
	//蛇身用2个结点指针变量分别指向链表的头结点和尾结点。
	SnakeNode *head{nullptr}, *tail{ nullptr };
	unsigned int direction{}; //蛇身方向
	Color body_color, head_color;
	bool is_dead{ false }; //蛇是否死亡
	int width{ 0 }, height{ 0 };
	bool moving{ false };
public:
	bool is_moving() { return moving; }
	//初始化窗口范围[width，height]里指定长度的一条蛇
	Snake(const int width,const int height,int length = 3,
		Color body_color = 'o', Color head_color = '@');

	//沿给定方向前进，前进过程中需要检查是否发生了碰撞
	void move(unsigned int direct);
	void update(bool to_eat=false);     //
	void draw(Canvas& canvas);	

	SnakeNode *get_head() { return head; } //返回链表的头结点
	SnakeNode *get_tail() { return tail; } //返回链表的头结点
	Color get_body_color() { return body_color; }
	Color get_head_color() { return head_color; }
	

	void print();
};

Snake::Snake(const int width, const int height, int length ,
	Color body_color, Color head_color ) {
	this->width = width;
	this->height = height;
	this->body_color = body_color;
	this->head_color = head_color;

	//生成随机的蛇的位置
	auto x_min{ length + 1 }, x_max{ width - x_min },
		y_min{ length + 1 }, y_max{ height - y_min };
	auto x = random_int(x_min, x_max);
	auto y = random_int(y_min, y_max);

	SnakeNode *p = new SnakeNode(Position(x, y));//创建蛇尾结点
	tail = p; //该结点是链表的尾结点（最后的结点）
	head = new SnakeNode(Position(), p); //创建整个链表的头结点
	auto d = random_int(0, 4);//生成随机的0,1,2,3	
	for (auto i = 1; i != length; i++) {
		if (d == 0) x++;
		else if (d == 1) x--;
		else if (d == 2) y++;
		else y--;
		p = new SnakeNode(Position(x, y), head->get_next());
		head->set_next(p);
	}
	if (d == 0) direction = KEY_LEFT; 
	else if (d == 1) direction = KEY_RIGHT;
	else if (d == 2) direction = KEY_UP;
	else  direction = KEY_DOWN; 
}



void Snake::draw(Canvas& canvas) {
	SnakeNode *p = head->get_next();	
	while (p!=tail) {
		canvas.set_pixel(p->get_pos().get_x(),
			p->get_pos().get_y(), body_color);
		p = p->get_next(); //指针p向后移动
	}
	canvas.set_pixel(p->get_pos().get_x(),
		p->get_pos().get_y(), head_color);
}



void Snake::move(unsigned int direct) {
	//让蛇沿着上下左右方向运动，用字母表示不同方向
	//注意：链表尾部表示蛇头
	auto head_pos = tail->get_pos();
	auto x{head_pos.get_x()}, y{ head_pos.get_y()};	

	

	if (direct == KEY_UP) {//向上移动，y--
		if (y == 1)			return; //到达顶部了不能移动
		if(this->direction== KEY_DOWN) return;
		--y;
	}
	else if (direct == KEY_DOWN) {//向上移动，y++
		if (y == height-1)			return; //到达底部了不能移动
		if (this->direction == KEY_UP) return;
		++y;
	}
	else if (direct == KEY_LEFT) {//左键-->向左移动，y--
		if (x == 1)			return; //到达最左边不能移动
		if (this->direction == KEY_RIGHT) return;
		--x;
	}
	else if (direct == KEY_RIGHT) {//右键-->向右移动，y++
		if (x == width-1)			return; //到达最右边不能移动
		if (this->direction == KEY_LEFT) return;
		++x;
	}
	else return;
	this->direction = direct;

	//检查是否发生碰撞？


	//创建新的蛇头，加入到链表的尾部。
	SnakeNode *p = new SnakeNode(Position( x,y));//创建蛇尾结点
	tail->set_next(p);
	tail = p; //新蛇头结点p称为新的链表尾结点

	moving = true;//表示正在移动
}
void Snake::update(bool to_eat) {
	//如果没有吃鸡蛋，则删除蛇尾结点
	if (!to_eat) {
		//删除代表蛇尾的链表首结点（头结点后的那个结点）
		SnakeNode *p = head->get_next(); //p指向首结点
		head->set_next(p->get_next()); //p的next结点称为head的后一个结点
		delete p; //释放p结点暂用内存
	}
	//否则，正吃了一个鸡蛋，不用删除蛇尾结点。
	moving = false;
}

void Snake::print() {
	auto p = head->get_next();
	while (p) {
		auto pos = p->get_pos();
		std::cout << pos.get_x() << ',' << pos.get_y() << '\t';
		p = p->get_next();
	}
	std::cout << std::endl;
	int a = 0;
	std::cin >> a;
}

class BackGround {
	Color top_boundary_color{' '}, bottom_boundary_color{ '_' };
	Color left_right_boundary_color{ '|' };
public:
	void draw(Canvas &canvas) {
		auto right{ canvas.get_width() - 1 };
		auto bottom{ canvas.get_height() - 1 };
		for (auto x = 0; x < canvas.get_width(); x++) {
			canvas.set_pixel(x,0, top_boundary_color);
			canvas.set_pixel(x, bottom, bottom_boundary_color);
		}

		for (auto y = 0; y < canvas.get_height(); y++) {
			canvas.set_pixel(0, y, left_right_boundary_color);
			canvas.set_pixel(right, y,  left_right_boundary_color);
		}		
	}
};

class GameEngine {
	Canvas *canvas{nullptr};
	Snake *snake{ nullptr };
	Egg *egg{ nullptr };
	BackGround bg;
	bool running{ true };	
public:
	GameEngine(const int w=80,const int h=30) {
		canvas = new Canvas(w, h, ' ');
		canvas->clear();
		//创建Snake对象		
		snake = new Snake(w,h,4);
		//创建Egg对象
		auto x = random_int(2, w-2);
		auto y = random_int(2, h-2);
		egg = new Egg(x,y);
	}
	void run() {
		while (running) {
			processEvent();
			update();
			collosion();
			render();
		}
		quit();
	}

	void processEvent() {
		//  处理事件
		char key;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) running=false;
			snake->move(key);
		}
	}
	void update() {}	
	void collosion() {
		if (!snake->is_moving()) return;
		auto tail = snake->get_tail();
		auto pos = tail->get_pos();//蛇头位置
		auto x{ pos.get_x() }, y{ pos.get_y() };

		//是否撞墙了？
		bool is_snake_dsead{ false };
		if(x==0||y==0||x== canvas->get_width()-1||y==canvas->get_height()-1)
			is_snake_dsead = true;
		if (is_snake_dsead) {
			running = false;//游戏结束
			return;
		}

		Color color= canvas->get_pixel(x, y);//得到该位置的颜色
		if (color == canvas->get_bg_color()) return;

		bool to_eat{ false };
		if (egg&&color == egg->get_color())
			to_eat = true;
		else if(color != snake->get_head_color()) //和墙或自身发生碰撞
			is_snake_dsead = true;
		if (is_snake_dsead) {
			running = false;//游戏结束
			return;
		}
		snake->update(to_eat);//
		if (to_eat) {
			delete egg;  egg = nullptr;
			auto x = random_int(2, canvas->get_width() - 2);
			auto y = random_int(2, canvas->get_height() - 2);
			egg = new Egg(x, y);
		}
	}
	void render() {
		if (!running) return;
		gotoxy(0, 0);
		hideCursor();
		canvas->clear();
		draw_scene();
		canvas->show();
	}
	void draw_scene() {	
		bg.draw(*canvas);
		snake->draw(*canvas);
		if(egg)	egg->draw(*canvas);
	}
	void quit(){}
};


int main() {
	GameEngine game;
	game.run();
}
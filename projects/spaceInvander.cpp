/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#if 1
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
	int width{ 60 }, height{ 50 }; //窗口
	Color bg_color{ ' ' };
	Color *frame_buffer{ nullptr }; //帧缓存，彩色图像的显示器内存
public:
	Canvas(int w, int h, Color bgColor)
		:width{ w }, height{ h }, bg_color{ bgColor },
		frame_buffer{ new Color[w*h] }{}


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

	//---------清空画布--------
	void clear() {
		if (!frame_buffer) return;
		auto n = width * height;
		for (auto i = 0; i != n; i++)
			frame_buffer[i] = bg_color;
	}

	//--------显示画布canvas中的内容
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

//表示2维坐标点或向量
using T = int;
class Vector2 {
	T x{ 0 }, y{ 0 };
public:
	Vector2(T x = 0, T y = 0) :x{ x }, y{ y }{}
	T& operator[](int i) {
		if (i == 0) return x;
		else if (i == 1) return y;
		else throw "下标非法";
	}
	T operator[](const int i) const {
		if (i == 0) return x;
		else if (i == 1) return y;
		else throw "下标非法";
	}
};

//包围矩形
class Rect{	
public:
	Vector2 pos, size;
	Rect(Vector2 p, Vector2 s) :pos{ p }, size{ s }{}
	Rect(const T x,const T y, const T w, const T h )
		:pos{x,y}, size{w,h}{}	
	
	bool collide(const Rect &other) {
		return (
			(pos[0]+ size[0]> other.pos[0]) &&
			(other.pos[0] + other.size[0] > pos[0]) &&
			(pos[1]+ size[1] > other.pos[1] ) &&
			(other.pos[1] + other.size[1] > pos[1]) 
			);
	}
};

const Color bullet_color = '|';
const Color player_color = '*';
const Color enemy_color = '+';
const Color background_color = ' ';



//精灵
class Sprite {
protected:	
	Canvas *canvas{ nullptr };
	Vector2 pos, vel,size_;//位置、速度、大小
	Color color;  //颜色
	int lives{1};//生命值
	Rect rect;
public:
	Sprite(Canvas *canvas,const Color c, const Vector2 p,
		const Vector2 v=Vector2{0,0},const  Vector2 s = Vector2{ 1,1 },
		const int lives=1)
		:canvas{ canvas },pos {	p}, vel{ v }, size_{ s }, 
		color{ c }, lives(lives), rect{ Vector2(pos[0]-s[0]/2,pos[1]-s[1]/2),s }
	{
		
	}
	virtual void update() {
		pos[0] += vel[0]; pos[1] += vel[1];
		rect.pos[0] = pos[0] - rect.size[0] / 2;
		rect.pos[1] = pos[1] - rect.size[1] / 2;
	    if(is_out())lives = 0;
		

	}
	virtual void draw() {}
	virtual bool is_dead() { return lives <= 0; }
	virtual Rect get_rect() { return rect; }
	virtual bool collide(const Rect &other) { return rect.collide(other); }
protected:
	bool is_out() {
		return  (rect.pos[0] <= 0 || rect.pos[1] <= 0
			|| rect.pos[0] + rect.size[0] >= canvas->get_width()
			|| rect.pos[1] + rect.size[1] >= canvas->get_height());
			
	}
	
};


class BackGround {
	Color top_boundary_color{ ' ' }, bottom_boundary_color{ '_' };
	Color boundary_color{ '#' };
public:
	void draw(Canvas &canvas) {
		auto right{ canvas.get_width() - 1 };
		auto bottom{ canvas.get_height() - 1 };
		for (auto x = 0; x < canvas.get_width(); x++) {
			canvas.set_pixel(x, 0, top_boundary_color);
			canvas.set_pixel(x, bottom, bottom_boundary_color);
		}

		for (auto y = 0; y < canvas.get_height(); y++) {
			canvas.set_pixel(0, y, boundary_color);
			canvas.set_pixel(right, y, boundary_color);
		}
	}
};

using ElemType = Sprite*;
//using ElemType = int;
class Vector{
	ElemType *data{ nullptr };
	int  capacity{ 0 }, n{ 0 };
public:
	Vector(const int cap=5) :capacity{ cap }, data{ new ElemType[cap] }
	{}
	bool insert(const int i, const ElemType &e) {
		if (i < 0 || i >= n) return false;
		if (n == capacity&&!add_capacity()) 
				return false;		
		for (auto j = n; j > i; j--)
			data[j] = data[j - 1];
		data[i] = e;
		return true;
	}
	bool erase(const int i) {
		if (i < 0 || i >= n) return false;
		for (auto j = i; j <n-1 ; j++)
			data[j] = data[j+1];
		n--;
		return false;
	}
	bool push_back(const ElemType &e) {
		if (n == capacity && !add_capacity())
			return false;
		data[n++] = e;	
		return true;
	}
	bool pop_back(const ElemType e) {
		if (n == 0) return false;
		n--; return true;
	}

	ElemType get(const int i)const {
		if(i>=0&&i<n)
			return data[i];
		throw "下标非法！\n";
	}
	ElemType get(const int i,const ElemType &e)const {
		if (i >= 0 && i < n)
			return data[i] = e;	
	}

	ElemType& operator[](int i) {
		if (i >= 0 && i < n) return data[i];		
		else throw "下标非法";
	}
	ElemType operator[](const int i) const {
		if (i >= 0 && i < n) return data[i];
		else throw "下标非法";
	}

	bool add_capacity(){
		ElemType *temp = new ElemType[2 * capacity];
		if (!temp) return false;
		for (auto i = 0; i < n; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp; capacity *= 2;
		return true;
	}

	int size() const{ return n; }
};


//游戏引擎类
#include<string>

class GameEngine {
protected:
	Canvas *canvas{ nullptr };
	Vector sprites;
	bool running{ true };
	BackGround *bg{ new BackGround() };
	int score{ 0 };
public:
	GameEngine(const int w = 80, const int h = 30) {
		canvas = new Canvas(w, h, ' ');
		canvas->clear();	
	}
	
	virtual void run() {
		while (running) {
			processEvent();
			update();
			collosion();
			render();
		}
		quit();
	}

	virtual void processEvent() {
		//  处理事件
		char key;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) running = false;			
		}
	}
	virtual void update() {
		for(auto i = 0 ; i<sprites.size();i++)
			sprites[i]->update();
	}
	virtual void collosion() {
		
	}
	virtual void render() {
		if (!running) return;
		gotoxy(0, 0);
		hideCursor();
		canvas->clear();
		draw_scene();
		canvas->show();
	}
	virtual void draw_scene() {
		bg->draw(*canvas);
		for (auto i = 0; i < sprites.size(); i++)
			sprites[i]->draw();	

		std::string s{ std::to_string(score) };
		auto x = canvas->get_width() - s.size() - 2;
		auto y = 1;
		for (auto i = 0; i < s.size(); i++,x++)
			canvas->set_pixel(x,y,s[i]);


	}
	virtual void quit() {}
};


class Bullet :public Sprite {	
public:
	Bullet(Canvas *canvas, const Color c, const Vector2 p,
		const Vector2 v = Vector2{ 0,0 }) :Sprite(canvas,c,p,v)	
	{		
	}
	void draw() {
		auto x{ pos[0] }, y{ pos[1] };		
		canvas->set_pixel(x, y, bullet_color);
	}
	virtual void hitted() {
		lives--;
	}
};

class Flighter:public Sprite {
protected:
	Bullet *bullet{nullptr};
public:
	Flighter(Canvas *canvas, const Color c, const Vector2 p,
		const Vector2 v = Vector2{ 0,0 }, const  Vector2 s = Vector2{ 1,1 },
		const int lives = 1) :Sprite(canvas, c, p, v, s, lives) {
	}

	virtual Bullet * shot(const Vector2 &vel) {
		auto x = pos[0];
		auto y = pos[1] - rect.size[1] / 2;
		bullet = new Bullet(canvas, bullet_color, Vector2{ x,y }, vel);
		return bullet;	
	}
	void move(Vector2 vel) {
		pos[0] += vel[0];
		pos[1] += vel[1];
	}

	virtual void hitted() {
		lives--;
		//play sound
	}
};

class Player :public Flighter{	
public:	
	Player(Canvas *canvas, const Color c, const Vector2 p,
		const Vector2 v = Vector2{ 0,0 }, const  Vector2 s = Vector2{ 3,3 },
		const int lives = 1) :Flighter(canvas, c, p, v, s, lives) {
	}
	
	
	virtual void draw() {
		auto x{pos[0]}, y {pos[1]};
		canvas->set_pixel(x, y-1, player_color);
		canvas->set_pixel(x-1, y, player_color);
		canvas->set_pixel(x, y, player_color);
		canvas->set_pixel(x+1, y, player_color);
		canvas->set_pixel(x-1, y+1, player_color);
		canvas->set_pixel(x+1, y+1, player_color);
	}

	void move(Vector2 vel) {
		auto x = pos[0] + vel[0];
		auto y = pos[1] + vel[1];
		if (x >= rect.size[0] / 2 && x < canvas->get_width() - rect.size[0] / 2 - 1)
			pos[0] = x;
		if (y >= rect.size[1] / 2 && y < canvas->get_height() - rect.size[1] / 2 - 1)
			pos[1] = y;
	}
};

#include <chrono>
using namespace std::chrono;

class Enemy :public Flighter {
protected:	
	int bullet_num{ 0 };//假如每次连续发射5法子弹
	high_resolution_clock::time_point shot_start{ high_resolution_clock::now() };
	high_resolution_clock::time_point shot_last{ shot_start };
	high_resolution_clock::time_point move_start{shot_start};
public:
	Enemy(Canvas *canvas, const Color c, const Vector2 p,
		const Vector2 v = Vector2{ 0,0 }, const  Vector2 s = Vector2{ 3,3 },
		const int lives = 1) :Flighter(canvas, c, p, v, s, lives) {
	}
	virtual void draw() {
		auto x{ pos[0] }, y{ pos[1] };
		canvas->set_pixel(x-2, y - 1, enemy_color);
		canvas->set_pixel(x , y - 1, enemy_color);
		canvas->set_pixel(x + 2, y - 1, enemy_color);
		canvas->set_pixel(x - 1, y , enemy_color);
		canvas->set_pixel(x+1, y , enemy_color);		
		canvas->set_pixel(x , y+1, enemy_color);
	}

	virtual void update() {
		//随机发射子弹		
		auto now = std::chrono::high_resolution_clock::now();
		auto dur = now - shot_start; //持续时间
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		if (ms > 3000) {
			bullet_num = 3;
			shot_start = now;
		}
		if (bullet_num > 0) {
			auto dur2 = now - shot_last;
			auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(dur2).count();
			if (ms2 > 100) {
				shot_last = now;
				shot(Vector2{ 0,1 }); //必须将这个子弹在引擎类的update()中加入
				bullet_num--;
			}
		}		
		
		auto dur_move = now - move_start; //持续时间
		auto ms_move = std::chrono::duration_cast<std::chrono::milliseconds>(dur_move).count();
		if (ms_move > 300) {
			auto a = ms_move % 6;
			if (a > 0) {
				if (a == 1) move(Vector2(-1, 0));
				else if (a == 2) move(Vector2(1, 0));
				else if (a > 2)move(Vector2(0, 1));
				move_start = now;
			}
		}

		Flighter::update();
	}
	Bullet *get_bullet(){//返回bullet指针，并将bullet设置为空指针
		Bullet *p = bullet;
		bullet = 0;
		return p;		
	}
};


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class SpaceInvander :public GameEngine {
protected:
	Player *player{nullptr};
	Vector enemies;
	Vector bullets, enemy_bullets;
	high_resolution_clock::time_point create_enemy_start
		= std::chrono::high_resolution_clock::now();
	
public:
	SpaceInvander(const int w = 80, const int h = 30) : GameEngine(w,h){
		auto player_w{3 }, player_h{ 3 };
		player = new Player(canvas, player_color, 
			Vector2{ canvas->get_width()/2,canvas->get_height()- player_h-1  }
			, Vector2{ 0,0 }, Vector2{ player_w,player_h });
		sprites.push_back(player);

#if 0
		//生成随机的敌机的位置
		int x_off = 10,y_off = 5;
		auto x_min{ x_off }, x_max{ canvas->get_width() - x_off },
			y_min{ 1 }, y_max{ y_off };
		auto x = random_int(x_min, x_max);
		auto y = random_int(y_min, y_max);
		Enemy *enemy = new Enemy(canvas, enemy_color, Vector2{ x,y });
		sprites.push_back(enemy);
		enemies.push_back(enemy);
#else
		//create_enemies();
#endif
		

	}
	void processEvent() {
		char key;
        if (_kbhit()) {
			key = _getch();
			if (key == 27) running = false;
			if (key == ' ') {
				//生成子弹的位置正好在战机的上方
				Bullet *bullet = player->shot(Vector2(0,-1));
				bullets.push_back(bullet);
				sprites.push_back(bullet);
			}
			else if (key == 'a' || key == 'A'||key== KEY_LEFT) {
				player->move(Vector2(-1, 0));//战机左移			

			}
			else if (key == 'd' || key == 'D' || key == KEY_RIGHT) {
				player->move(Vector2(1, 0)); //战机右移

			}
			else if (key == 'w' || key == 'W' || key == KEY_UP) {
				player->move(Vector2(0,-1));
			}
			else if (key == 's' || key == 'S' || key == KEY_DOWN) {
				player->move(Vector2(0,1));
			}
		}
	}

	void update() {
		for (auto i = 0; i < enemies.size(); i++) {
			auto enemy = enemies[i];
			Bullet *bullet = static_cast<Enemy*>(enemy)->get_bullet();
			if (bullet) {
				enemy_bullets.push_back(bullet);
				sprites.push_back(bullet);
			}
		}

		auto now = std::chrono::high_resolution_clock::now();
		auto dur = now - create_enemy_start; //持续时间
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		if (ms > 6000) {
			create_enemy_start = now;
			create_enemies();
		}			
		GameEngine::update();
	}

	void collosion() {
		//检测是否碰撞
		//检测敌机是否被子弹击中或和我战机碰撞
		for (auto i = 0; i < enemies.size(); i++) {
			auto enemy = enemies[i];
			if (player&&player->collide(enemy->get_rect())) {
				player->hitted();
				static_cast<Enemy*>(enemy)->hitted();
			}
			for (auto j = 0; j < bullets.size(); j++) {
				auto bullet = bullets[j];
				if (enemy->collide(bullet->get_rect())) {
					static_cast<Enemy*>(enemy)->hitted();
					static_cast<Bullet*>(bullet)->hitted();
					score++;
				}
			}
		}
		//检测我战机是否被子弹击中
		if (player) {
			for (auto j = 0; j < enemy_bullets.size(); j++) {
				auto bullet = enemy_bullets[j];
				if (player->collide(bullet->get_rect())) {
					player->hitted();
					static_cast<Bullet*>(bullet)->hitted();
				}
			}
		}	

		Vector deads;
		for (auto i = 0; i < sprites.size(); ) {
			
			if (sprites[i]->is_dead()) {
				delete sprites[i];
				deads.push_back(sprites[i]);
				sprites.erase(i);			
			}
			else i++;
		}
		//在enemies和bullets中寻找已经删除的 Sprite指针
		for (auto i = 0; i < deads.size();i++ ) {
			Sprite* p = deads[i];
			auto deleted{ false };
			for (auto i = 0; i < enemies.size(); i++)
				if (enemies[i] == p) {
					enemies.erase(i); 
					deleted = true;			break;
				}
			if (deleted) continue;
			for (auto i = 0; i < bullets.size(); i++)
				if (bullets[i] == p) {
					bullets.erase(i);
					break;
				}
			if (deleted) continue;
			for (auto i = 0; i < enemy_bullets.size(); i++)
				if (enemy_bullets[i] == p) {
					enemy_bullets.erase(i);
					break;
				}
		}
	}

	void create_enemies() {
		//开始生成敌机
		
		//生成随机的敌机的位置
		int x_off = 10, y_off = 5;
		auto x_min{ x_off }, x_max{ canvas->get_width() - x_off },
			y_min{ 2}, y_max{ y_off };
		auto x = random_int(x_min, x_max);
		auto y = random_int(y_min, y_max);
		Enemy *enemy = new Enemy(canvas, enemy_color, Vector2{ x,y });
		sprites.push_back(enemy);
		enemies.push_back(enemy);

		//再生成一个敌机
		x = random_int(5, x - x_off);
		y = random_int(y_min, y_max);
		enemy = new Enemy(canvas, enemy_color, Vector2{ x,y });
		sprites.push_back(enemy);
		enemies.push_back(enemy);

		//生成第3个敌机
		x = random_int(x + x_off, canvas->get_width() - 5);
		y = random_int(y_min, y_max);
		enemy = new Enemy(canvas, enemy_color, Vector2{ x,y });
		sprites.push_back(enemy);
		enemies.push_back(enemy);
	}
};

int main() {
	try {
		SpaceInvander game;
		game.run();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

#endif 

#if 0
#include <string>
class Book {
public:
	std::string name, author, publisher;
	double price;
};
using ElemType = Book;

//using ElemType = char;
class Vector {
	ElemType *data{ nullptr };
	int  capacity{ 0 }, n{ 0 };
public:
	Vector(const int cap = 5)   //创建容量是cap的一个线性表
		:capacity{ cap }, data{ new ElemType[cap] }	{}
	bool insert(const int i, const ElemType &e); //在i处插入元素
	bool erase(const int i);            //删除i元素
	bool push_back(const ElemType &e); //表的最后添加一个元素
	bool pop_back();  //删除表的最后元素

	bool get(const int i, ElemType &e)const; //读取i元素
	bool set(const int i, const ElemType e);//修改i元素	
	int size() const { return n; }  //查询表长
private:
	bool add_capacity();             //扩充容量
};

bool Vector::add_capacity() {
	ElemType *temp = new ElemType[2 * capacity];//分配更大空间
	if (!temp) return false;      
	for (auto i = 0; i < n; i++) {     //将原空间data数据拷贝到新空间temp
		temp[i] = data[i];
	}
	delete[] data;                //双方原来空间内存
	data = temp;     //data指向新的空间temp
	capacity *= 2;      //修改容量
	return true;
}

bool Vector::insert(const int i, const ElemType &e) {
	if (i < 0 || i >= n) return false; //插入位置合法吗？
	if (n == capacity && !add_capacity()) //已满，增加容量
		return false;
	for (auto j = n; j > i; j--)  //将n-1到i的元素都向后移动一个位置
		data[j] = data[j - 1];
	data[i] = e; 
	n++; //初学者忘记修改表长
	return true;
}

bool Vector::erase(const int i) {
	if (i < 0 || i >= n) return false; //位置i合法吗？
	 //i+1到n-1元素依次向前移动一个位置
	for (auto j = i; j < n - 1; j++) 
		data[j] = data[j + 1];
	n--;   //不要忘了：表长变量减去1。
	return false;
}

bool Vector::push_back(const ElemType &e) {
	if (n == capacity && !add_capacity()) //空间满就扩容
		return false;
	data[n++] = e; //e放入下标n位置，然后n++
	return true;
}
bool Vector::pop_back() {
	if (n == 0) return false; //空表
	n--;   //n减去1就相当于删除了表尾元素
	return true;
}

//读取i元素
bool Vector::get(const int i, ElemType &e)const{
	if (i >= 0 && i < n) {
		e = data[i]; return true;
	}
	return false;
}
//修改i元素
bool Vector::set(const int i, const ElemType e){
	if (i >= 0 && i < n) {
		data[i]=e; return true;
	}
	return false;
}

#include <iostream>
void input(ElemType &e) {
	std::cout << "请输入图书的信息：书名 作者 出版社 价格:\n";
	std::cin >> e.name >> e.author >> e.publisher >> e.price;
}
void print(const ElemType &e) {
	std::cout << e.name << e.author << e.publisher << e.price << '\n';
}
void print(const Vector &v) {
	ElemType e;
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, e);
		print(e);//输出该图书信息
	}
	std::cout << std::endl;
}

void help() {
	std::cout << "请输入命令:i(插入)、e(删除)、a(追加)、b(删除最后元素)、\n";
	std::cout << "s(修删除某序号元素)、g(查询某序号元素)、p(打印)\n";
}
int main() {
	Vector books;
	ElemType e;
	char cmd;
	help();
	while (std::cin >> cmd) {
		if (cmd == 27)break;
		else if (cmd == 'I' || cmd == 'i') {//插入一本图书
			std::cout << "请输入插入的位置（从0开始）：";
			int i; std::cin >> i;
			input(e);
			books.insert(i, e);
		}
		else if (cmd == 'e' || cmd == 'E') {//删除一本图书
			std::cout << "请输入删除的位置（从0开始）：";
			int i; std::cin >> i;			
			books.erase(i);
		}
		else if (cmd == 'a' || cmd == 'A') {//在最后插入一本图书
			input(e);
			books.push_back(e);
		}
		else if (cmd == 'b' || cmd == 'B') {//删除最后一本图书
			input(e);
			books.pop_back();
		}		
		else if (cmd == 's' || cmd == 'S') {//修改某序号的图书
			std::cout << "请输入要修改的图书的位置（从0开始）：";
			int i; std::cin >> i;
			input(e);
			books.set(i, e);
		}
		else if (cmd == 'g' || cmd == 'G') {//查询某序号的图书
			std::cout << "请输入要查询的图书的位置（从0开始）：";
			int i; std::cin >> i;
			books.get(i, e);
			print(e);
		}
		else if (cmd == 'p' || cmd == 'P') {//显示所有图书
			print(books);
		}
		help();
		
	}

}


#if 0
#include <iostream>
void print(const Vector &v) {
	ElemType e;
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, e);
		std::cout << e << '\t';
	}
	std::cout << std::endl;
}
int main() {
	Vector v(2);
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	print(v);
	v.insert(1, 'd');
	print(v);
	ElemType e;
	v.get(1, e);
	std::cout << e << '\n';
	v.set(1, 'f');
	print(v);
	v.erase(2);
	print(v);
	v.pop_back();
	print(v);
}
#endif
#endif 

#if 0
using ElemType = char; //假设数据元素的类型是ElemType
class List {	
	struct LNode { //struct定义的类的成员默认是公开的
		ElemType data;
		LNode *next{nullptr}; //next是指向下一个元素结点的指针变量
	};
	LNode *head;
public:
	//初始化一个不含任何数据只有头结点的空的链表
	List() :head{ new LNode{} } {}
	
	bool insert(const int i, const ElemType &e); //在i处插入元素
	bool erase(const int i);            //删除i元素

	bool push_back(const ElemType &e); //表的最后添加一个元素
	bool pop_back();  //删除表的最后元素

	bool push_front(const ElemType &e); //插入元素成为第一个元素（首结点）
	bool pop_front();  //删除首结点

	bool get(const int i, ElemType &e)const; //读取i元素
	bool set(const int i, const ElemType e);//修改i元素	
	int size() const;  //查询表长
private:
	LNode *locate(const int i )const;
};


bool List::push_front(const ElemType &e) {
	LNode *p = new LNode;
	if (!p) return false; //分配内存失败!
	p->data = e;
	p->next = head->next;//p的next指针指向原来的首结点
	head->next = p; //head的next指向p指向的新结点，即新结点成为首结点。
}

bool List::pop_front() {
	if (!head->next) return false; //空表
	LNode *p = head->next; //p指向要删除的首结点
	head->next = p->next;//head的next指向p的后一个结点，即跳过首结点
	delete p;//删除原来的首结点
	return true;
}
int List::size()const {
	LNode *p{head}; auto i{ 0 };//p指向头结点，计数器i尾0
	p = p->next;  //p指向首结点，
	while (p) { //p不是空指针，表示遇到一个结点
		i++;  //计数器增加1
		p = p->next; //p指向下一个结点
	}
	return i;
}
List::LNode * List::locate(const int i)const{
	if (i < 0) return nullptr;//插入位置不合法
	LNode *p{ head }; auto j{ 0 };//p指向头结点，计数器i尾0
	while (p&&j < i ) {
		p = p->next;  //p指向下一个结点
		j++;
	}
	return p;
}



bool List::erase(const int i) {     //删除i元素
	LNode *p = locate(i-1);//定位i-1号结点	
	if (p) {//p指向的第i-1号结点存在
		LNode *q = p->next;//q保存要删除的结点地址
		p->next = q->next;//使p的next指针跳过q结点
		delete q; // 删除q指向的那个结点
		return true;
	}
	return false; //i超出了表长
}

bool List::insert(const int i, const ElemType &e) {
	LNode *p = locate(i - 1);//定位i-1号结点	
	if (p) {//p指向的第i-1号结点存在
		LNode *q = new LNode;//q指向分配的新结点内存块
		if (!q) return false;
		q->data = e;
		q->next = p->next; //将p的后继结点挂到q的后面
		p->next = q;//将q指向的结点挂到p的后面
		return true;
	}
	return false;
}

bool List::get(const int i, ElemType &e)const {
	LNode *p = locate(i );//定位i号结点	
	if (p) {
		e = p->data; return true;
	}
	return false;

}
bool List::set(const int i, const ElemType e) {
	LNode *p = locate(i);//定位i号结点	
	if (p) {
		p->data = e; return true;
	}
	return false;
}


#include <iostream>
void print(const List &v) {
	ElemType e;
	for (auto i = 1; i <= v.size(); i++) {
		v.get(i, e);
		std::cout << e << '\t';
	}
	std::cout << std::endl;
}

int main() {
	List v;
	v.push_front('a');
	v.push_front('b');
	v.push_front('c');
	print(v);
	v.insert(1, 'd');
	print(v);
	ElemType e;
	v.get(1, e);
	std::cout << e << '\n';
	v.set(1, 'f');
	print(v);
	v.erase(2);
	print(v);
	v.pop_front();
	print(v);
}
#endif 




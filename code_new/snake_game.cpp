#ifdef  version_0
#include "ChGL.hpp"


class Snake;
class Egg;
class BackGround {
    color top_color{ '*' }, bottom_color{ '*' }, side_color{ '|' };
public:
    void draw(ChGL& window) {
        auto w = window.getWidth();
        auto h = window.getHeight();
        int right = w - 1;
        int bottom = h - 1;
        for (int x = 0; x < w; x++) {
            window.setPixel(x, 0, top_color);
            window.setPixel(x, bottom, bottom_color);
        }
        auto mid_x = (w - 1) / 2;
        for (int y = 1; y < bottom; y++) {
            window.setPixel(0, y, side_color);
            window.setPixel(mid_x, y, side_color);
            window.setPixel(right, y, side_color);
        }
    }
};

class GameEngine {
    ChGL* window{ nullptr };
    BackGround bg;         // 游戏画布
    Snake* snake{ nullptr }; // 蛇
    Egg* egg{ nullptr };     // 鸡蛋
    bool running{ true };
    //bool start{false};
    InputHandler input;
public:
    GameEngine(int w = 50, int h = 20);
    ~GameEngine() {
        if (window) delete window;
    }
    void run() {
        while (running) {
            processEvent();
            update();
            collision();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
private:
    void processEvent();
    void update();
    void collision();
    void drawScene();
    void render() {
        if (!running or !window) return;
        window->clear();
        drawScene();
        window->show();
    }
};
GameEngine::GameEngine( int w,  int h) {
    window = new ChGL(w, h);
};
void GameEngine::processEvent() {}
void GameEngine::update() {}
void GameEngine::collision() {}
void GameEngine::drawScene() {
    bg.draw(*window);
}

#include <chrono>
#include <random>
class Random {
    std::mt19937 rng;
public:
    Random() : rng(std::random_device{}()) {}
    int get(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
};
int main() {
    GameEngine game;
    game.run();
}
#endif



#ifdef version_egg_snake
#include "ChGL.hpp"


class Snake;
class Egg;
class BackGround {
    Color top_color{ '*' }, bottom_color{ '*' }, side_color{ '|' };
public:
    void draw(ChGL& window) {
        auto w = window.getWidth();
        auto h = window.getHeight();
        int right = w - 1;
        int bottom = h - 1;
        for (int x = 0; x < w; x++) {
            window.setPixel(x, 0, top_color);
            window.setPixel(x, bottom, bottom_color);
        }
        auto mid_x = (w - 1) / 2;
        for (int y = 1; y < bottom; y++) {
            window.setPixel(0, y, side_color);
            window.setPixel(mid_x, y, side_color);
            window.setPixel(right, y, side_color);
        }
    }
};

class GameEngine {
    ChGL* window{ nullptr };
    BackGround bg;         // 游戏画布
    Snake* snake{ nullptr }; // 蛇
    Egg* egg{ nullptr };     // 鸡蛋
    bool running{ true };
    //bool start{false};
    InputHandler input;
public:
    GameEngine(int w = 50, int h = 20);
    ~GameEngine() {
        if (window) delete window;
    }
    void run() {
        while (running) {
            processEvent();
            update();
            collision();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
private:
    void processEvent();
    void update();
    void collision();
    void drawScene();
    void render() {
        if (!running or !window) return;
        window->clear();
        drawScene();
        window->show();
    }
};

void GameEngine::processEvent() {}
void GameEngine::update() {}
void GameEngine::collision() {}


#include <chrono>
#include <random>
class Random {
    std::mt19937 rng;
public:
    Random() : rng(std::random_device{}()) {}
    int get(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
};


class Egg {
    int x, y;
    int size{ 1 };
    Color color{ 'G' };
    Random rand;
public:
    Egg(int w, int h, Color color = 'G', int s = 1)
        :size{ s }, color(color) {
        x = rand.get(2, w - 2);
        y = rand.get(2, h - 2);
    }
    void draw(ChGL& window) {
        window.setPixel(x, y, color);
    }
    Color getColor() const { return color; }
    int getX() const { return x; }
    int getY() const { return y; }
};

//表示一个位置
class Position {
    int x{ 0 }, y{ 0 };
public:
    Position(int x = 0, int y = 0) :x{ x }, y{ y } {}
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
        :pos{ pos }, next{ n } {
    }
    Position get_pos() { return pos; }
    SnakeNode* get_next() { return next; }   //返回该结点的next值，即指向下一个结点的指针
    void set_next(SnakeNode* n) { next = n; } //修改next值
};

class Snake {
    //蛇身用2个结点指针变量分别指向链表的头结点和尾结点。
    SnakeNode* head{ nullptr }, * tail{ nullptr };
    int direction{ 0 }; // 0:上, 1:下, 2:左, 3:右
    Color body_color{ 'o' }, head_color{ '@' };
    bool is_dead{ false };
    int width{ 0 }, height{ 0 };
    bool eating{ false };
    Random rand; // 随机数生成器    
public:
    //初始化窗口范围[width，height]里指定长度的一条蛇
    Snake(int width, int height, int length = 3,
        Color body_color = 'o', Color head_color = '@');

    void draw(ChGL& window);              //在画布window上绘制自己形状

    //沿direction方向前进，前进过程中需要检查是否发生了碰撞
    void move();
    void eat(bool eating);                  //吃了一个鸡蛋
    void set_direction(int d) {           //设置蛇的运动方向
        direction = d;
    }
    SnakeNode* get_head() { return head; } //返回链表的头结点
    SnakeNode* get_tail() { return tail; } //返回链表的尾结点
    Color get_body_color() { return body_color; }
    Color get_head_color() { return head_color; }
};

Snake::Snake(int width, int height, int length, Color body_color, Color head_color)
    :width{ width},height{ height }, body_color{ body_color }, head_color{ head_color } {
    int x_min = length + 1, x_max = width - x_min;
    int y_min = length + 1, y_max = height - y_min;
    //生成随机的蛇的位置
    int x = rand.get(x_min, x_max);
    int y = rand.get(y_min, y_max);

    tail = new SnakeNode(Position(x, y));
    head = new SnakeNode(Position(), tail);
    direction = rand.get(0, 3);
    for (int i = 1; i < length; i++) {
        if (direction == 0) y--;
        else if (direction == 1) y++;
        else if (direction == 2) x--;
        else x++;
        SnakeNode* p = new SnakeNode(Position(x, y), head->get_next());
        head->set_next(p);
    }
}

void Snake::draw(ChGL& window) {
    SnakeNode* p = head->get_next();
    while (p != tail) {                          //遍历每个蛇身结点
        window.setPixel(p->get_pos().get_x(),
            p->get_pos().get_y(), body_color);  //在画布中设置这个蛇身像素结点的颜色
        p = p->get_next();                    //指针p向后移动，指向下一个结点
    }
    window.setPixel(p->get_pos().get_x(),        //在画布上绘制蛇头结点
        p->get_pos().get_y(), head_color);
}

void Snake::eat(bool eating) {
    this->eating = eating;
}

void Snake::move() {
    if (is_dead) return;
    Position head_pos = tail->get_pos(); //当前蛇头位置，注意：链表尾部表示蛇头
    int x = head_pos.get_x(), y = head_pos.get_y();
    if (direction == 0) y--;       //向上移动，y--
    else if (direction == 1) y++;  //向下移动，y++
    else if (direction == 2) x--;   //左键-->向左移动,x--
    else x++;                       //右键-->向右移动，
    if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1) {
        is_dead = true;
        return;
    }
    //创建新的蛇头，加入到链表的尾部。
    SnakeNode* p = new SnakeNode(Position(x, y));//创建新的结点
    tail->set_next(p); //p加到尾结点(tail)的后面，即蛇头结点的后面
    tail = p; // p成为新的链表尾结点。即p成为了新蛇头结点
    if (!eating) {//如果没有吃鸡蛋，则删除蛇尾结点
        p = head->get_next();
        head->set_next(p->get_next());
        delete p;
    }
    else {
        //否则，正吃了一个鸡蛋，不用删除蛇尾结点。但应清空吃蛋标志
        eating = false;
    }
}

GameEngine::GameEngine(int w, int h) {
    window = new ChGL(w, h);
    snake = new Snake(w, h, 4);
    egg = new Egg(w, h);
}

void GameEngine::drawScene() {
    bg.draw(*window);
    if (snake) snake->draw(*window);
    if (egg) egg->draw(*window);
}


int main() {
    GameEngine game;
    game.run();
}
#endif



#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "ChGL.hpp" // 包含之前的ChGL.hpp

// 方向键定义（跨平台）
#ifdef _WIN32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#else
#define KEY_UP 'A' // Linux下用小写w/a/s/d模拟方向键
#define KEY_DOWN 'B'
#define KEY_LEFT 'D'
#define KEY_RIGHT 'C'
#endif

// 随机数生成
class Random {
    std::mt19937 rng;
public:
    Random() : rng(std::random_device{}()) {}
    int get(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }
};

// 位置类
class Position {
    int x{0}, y{0};
public:
    Position(int x = 0, int y = 0) : x{x}, y{y} {}
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() const { return x; }
    int getY() const { return y; }
};

// 蛇身节点类
class SnakeNode {
    Position pos;
    SnakeNode* next{nullptr};
public:
    SnakeNode(const Position& pos, SnakeNode* n = nullptr) : pos{pos}, next{n} {}
    Position getPos() const { return pos; }
    SnakeNode* getNext() const { return next; }
    void setNext(SnakeNode* n) { next = n; }
};

// 蛇类
class Snake {
    SnakeNode *head{nullptr}, *tail{nullptr}; // 头节点（蛇尾），尾节点（蛇头）
    int direction{0}; // 0:上, 1:下, 2:左, 3:右
    color body_color{'o'}, head_color{'@'};
    bool is_dead{false};
    int width{0}, height{0};
    bool eating{false};
    Random rand;

public:
    Snake(int width, int height, int length = 3, color body = 'o', color head = '@')
        : width{width}, height{height}, body_color{body}, head_color{head} {
        // 随机生成蛇尾位置
        int x_min = length + 1, x_max = width - x_min;
        int y_min = length + 1, y_max = height - y_min;
        int x = rand.get(x_min, x_max);
        int y = rand.get(y_min, y_max);

        // 创建蛇尾节点
        tail = new SnakeNode(Position(x, y));
        head = new SnakeNode(Position(), tail);
        direction = rand.get(0, 3);

        // 创建蛇身
        for (int i = 1; i < length; i++) {
            if (direction == 0) y--;
            else if (direction == 1) y++;
            else if (direction == 2) x--;
            else x++;
            SnakeNode* p = new SnakeNode(Position(x, y), head->getNext());
            head->setNext(p);
        }
    }

    ~Snake() {
        SnakeNode* p = head;
        while (p) {
            SnakeNode* next = p->getNext();
            delete p;
            p = next;
        }
    }

    void draw(ChGL& window) {
        SnakeNode* p = head->getNext();
        while (p != tail) {
            window.setPixel(p->getPos().getX(), p->getPos().getY(), body_color);
            p = p->getNext();
        }
        window.setPixel(p->getPos().getX(), p->getPos().getY(), head_color);
    }

    void move() {
        if (is_dead) return;
        Position head_pos = tail->getPos();
        int x = head_pos.getX(), y = head_pos.getY();

        // 计算新蛇头位置
        if (direction == 0) y--;
        else if (direction == 1) y++;
        else if (direction == 2) x--;
        else x++;

        // 验证新位置
        if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1) {
            is_dead = true;
            return;
        }

        // 创建新蛇头
        SnakeNode* p = new SnakeNode(Position(x, y));
        tail->setNext(p);
        tail = p;

        // 未吃蛋则删除蛇尾
        if (!eating) {
            p = head->getNext();
            head->setNext(p->getNext());
            delete p;
        } else {
            eating = false;
        }
    }

    void eat(bool e) { eating = e; }

    void setDirection(int d) {
        // 禁止反向移动
        if ((d == 0 && direction == 1) || (d == 1 && direction == 0) ||
            (d == 2 && direction == 3) || (d == 3 && direction == 2))
            return;
        direction = d;
    }

    SnakeNode* getHead() const { return head; }
    SnakeNode* getTail() const { return tail; }
    color getBodyColor() const { return body_color; }
    color getHeadColor() const { return head_color; }
    bool isDead() const { return is_dead; }
};

// 鸡蛋类
class Egg {
    int x, y;
    int size{1};
    color color{'G'};
    Random rand;

public:
    Egg(int w, int h) {
        x = rand.get(2, w - 2);
        y = rand.get(2, h - 2);
    }

    void draw(ChGL& window) {
        window.setPixel(x, y, color);
    }

    color getColor() const { return color; }
    int getX() const { return x; }
    int getY() const { return y; }
};

// 背景类
class BackGround {
    color top_color{' '}, bottom_color{'_'}, side_color{'|'};

public:
    void draw(ChGL& window) {
        int right = window.getWidth() - 1;
        int bottom = window.getHeight() - 1;
        for (int x = 0; x < window.getWidth(); x++) {
            window.setPixel(x, 0, top_color);
            window.setPixel(x, bottom, bottom_color);
        }
        for (int y = 0; y < window.getHeight(); y++) {
            window.setPixel(0, y, side_color);
            window.setPixel(right, y, side_color);
        }
    }
};

// 游戏引擎类
class GameEngine {
    ChGL* window{nullptr};
    BackGround bg;
    Snake* snake{nullptr};
    Egg* egg{nullptr};
    bool running{true};
    bool start{false};
    InputHandler input;

public:
    GameEngine(int w = 60, h = 50) {
        window = new ChGL();
        if (!window->init(w, h)) {
            throw std::runtime_error("Failed to initialize ChGL window");
        }
        window->setClearColor(' ');
        snake = new Snake(w, h, 4);
        egg = new Egg(w, h);
    }

    ~GameEngine() {
        delete window;
        delete snake;
        delete egg;
    }

    void run() {
        while (running) {
            processEvent();
            update();
            collision();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        quit();
    }

private:
    void processEvent() {
        if (input.kbhit()) {
            char key = input.getch();
            if (key == 27) running = false; // ESC退出
            else if (key == ' ') start = !start;
            else {
                start = true;
                if (key == KEY_UP) snake->setDirection(0);
                else if (key == KEY_DOWN) snake->setDirection(1);
                else if (key == KEY_LEFT) snake->setDirection(2);
                else if (key == KEY_RIGHT) snake->setDirection(3);
            }
        }
    }

    void update() {
        if (start && !snake->isDead()) snake->move();
    }

    void collision() {
        if (!start || snake->isDead()) return;
        auto tail = snake->getTail();
        auto pos = tail->getPos();
        int x = pos.getX(), y = pos.getY();

        color pixel = window->getPixel(x, y);
        if (pixel == window->getClearColor()) return;

        if (pixel != snake->getHeadColor()) {
            if (egg && pixel == egg->getColor()) {
                snake->eat(true);
                delete egg;
                egg = new Egg(window->getWidth(), window->getHeight());
            } else {
                running = false; // 撞墙或自身
            }
        }
    }

    void render() {
        if (!running) return;
        window->clear();
        drawScene();
        window->show();
    }

    void drawScene() {
        bg.draw(*window);
        if (snake) snake->draw(*window);
        if (egg) egg->draw(*window);
    }

    void quit() {
        window->destroy();
    }
};

int main() {
    try {
        GameEngine game;
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

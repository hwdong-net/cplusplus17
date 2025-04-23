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

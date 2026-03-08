#include <iostream>
#include <chrono>
#include <random>
#include <conio.h>   // Windows 平台需包含 _kbhit、_getch
#include <windows.h> // 用于光标控制等

// -------------------- 辅助类 --------------------
class Vector2 {
public:
    int x, y;
    Vector2(int x = 0, int y = 0) : x(x), y(y) {}
    Vector2 operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
    Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
};

class Rect {
public:
    Vector2 pos;   // 左上角
    Vector2 size;  // 宽高
    Rect(Vector2 p = {0,0}, Vector2 s = {0,0}) : pos(p), size(s) {}
    bool collide(const Rect& other) const {
        return (pos.x < other.pos.x + other.size.x) &&
               (pos.x + size.x > other.pos.x) &&
               (pos.y < other.pos.y + other.size.y) &&
               (pos.y + size.y > other.pos.y);
    }
};

// 颜色用整数表示（简化，实际未使用彩色）
class Color {
public:
    static constexpr int White = 7;
    static constexpr int Green = 10;
    static constexpr int Red = 12;
};

// 窗口类（简化，仅提供像素操作和光标控制）
class Window {
    int width_, height_;
public:
    Window(int w, int h, char) : width_(w), height_(h) {}
    int get_width() const { return width_; }
    int get_height() const { return height_; }
    void clear() { system("cls"); }
    void set_pixel(int x, int y, int) { gotoxy(x, y); std::cout << '*'; }
    void show() {}
};

// 光标移动函数（Windows）
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 随机数生成
int random_int(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// -------------------- 自定义 Vector --------------------
class Sprite;  // 前向声明
using ElemType = Sprite*;

class Vector {
    ElemType* data_;
    int capacity_;
    int size_;
    void expand() {
        int newCap = capacity_ == 0 ? 1 : capacity_ * 2;
        ElemType* newData = new ElemType[newCap];
        for (int i = 0; i < size_; ++i) newData[i] = data_[i];
        delete[] data_;
        data_ = newData;
        capacity_ = newCap;
    }
public:
    Vector(int cap = 5) : data_(new ElemType[cap]), capacity_(cap), size_(0) {}
    ~Vector() { delete[] data_; }  // 只释放数组，不释放元素
    bool push_back(const ElemType& e) {
        if (size_ == capacity_) expand();
        data_[size_++] = e;
        return true;
    }
    bool erase(int index) {
        if (index < 0 || index >= size_) return false;
        for (int i = index; i < size_ - 1; ++i) data_[i] = data_[i + 1];
        --size_;
        return true;
    }
    ElemType& operator[](int i) { return data_[i]; }
    const ElemType operator[](int i) const { return data_[i]; }
    int size() const { return size_; }
    bool empty() const { return size_ == 0; }
};

// -------------------- 精灵基类 --------------------
class Sprite {
protected:
    Window* window_;
    Vector2 pos_;
    Vector2 vel_;
    Vector2 size_;
    int color_;
    int lives_;
    Rect rect_;
public:
    Sprite(Window* w, int c, Vector2 p, Vector2 v = {0,0}, Vector2 s = {1,1}, int lives = 1)
        : window_(w), pos_(p), vel_(v), size_(s), color_(c), lives_(lives),
          rect_({p.x - s.x/2, p.y - s.y/2}, s) {}
    virtual ~Sprite() = default;
    virtual void update() {
        pos_ += vel_;
        rect_.pos.x = pos_.x - rect_.size.x / 2;
        rect_.pos.y = pos_.y - rect_.size.y / 2;
    }
    virtual void draw() = 0;
    bool is_dead() const { return lives_ <= 0; }
    virtual void hit() { --lives_; }
    Rect get_rect() const { return rect_; }
    bool collide(const Rect& other) const { return rect_.collide(other); }
};

// -------------------- 子弹类 --------------------
class Bullet : public Sprite {
public:
    Bullet(Window* w, int c, Vector2 p, Vector2 v) : Sprite(w, c, p, v) {}
    void draw() override {
        window_->set_pixel(pos_.x, pos_.y, color_);
    }
};

// -------------------- 战机基类 --------------------
class Fighter : public Sprite {
protected:
    Bullet* bullet_{nullptr};  // 刚射出的子弹，用于传递
public:
    Fighter(Window* w, int c, Vector2 p, Vector2 v = {0,0}, Vector2 s = {1,1}, int lives = 1)
        : Sprite(w, c, p, v, s, lives) {}
    virtual Bullet* shoot(Vector2 vel) {
        Vector2 bulletPos(pos_.x, pos_.y - size_.y/2);
        bullet_ = new Bullet(window_, Color::White, bulletPos, vel);
        return bullet_;
    }
    Bullet* get_bullet() {
        Bullet* p = bullet_;
        bullet_ = nullptr;
        return p;
    }
};

// -------------------- 玩家战机 --------------------
class Player : public Fighter {
public:
    Player(Window* w, int c, Vector2 p) : Fighter(w, c, p, {0,0}, {3,3}, 1) {}
    void move(Vector2 delta) {
        int x = pos_.x + delta.x;
        int y = pos_.y + delta.y;
        if (x >= size_.x/2 && x < window_->get_width() - size_.x/2 - 1) pos_.x = x;
        if (y >= size_.y/2 && y < window_->get_height() - size_.y/2 - 1) pos_.y = y;
    }
    void draw() override {
        int x = pos_.x, y = pos_.y;
        window_->set_pixel(x, y-1, color_);
        window_->set_pixel(x-1, y, color_);
        window_->set_pixel(x, y, color_);
        window_->set_pixel(x+1, y, color_);
        window_->set_pixel(x-1, y+1, color_);
        window_->set_pixel(x+1, y+1, color_);
    }
};

// -------------------- 敌机 --------------------
class Enemy : public Fighter {
public:
    Enemy(Window* w, int c, Vector2 p) : Fighter(w, c, p, {0,1}, {3,3}, 1) {}
    void draw() override {
        int x = pos_.x, y = pos_.y;
        window_->set_pixel(x-2, y-1, color_);
        window_->set_pixel(x, y-1, color_);
        window_->set_pixel(x+2, y-1, color_);
        window_->set_pixel(x-1, y, color_);
        window_->set_pixel(x+1, y, color_);
        window_->set_pixel(x, y+1, color_);
    }
};

// -------------------- 游戏引擎基类 --------------------
class BackGround {
public:
    void draw(Window& w) const { /* 可绘制简单背景，留空 */ }
};

class GameEngine {
protected:
    Window* window_;
    Vector sprites_;      // 所有精灵的唯一拥有者
    bool running_;
    BackGround* bg_;
public:
    GameEngine(int w = 80, int h = 30)
        : window_(new Window(w, h, ' ')), running_(true), bg_(new BackGround()) {}
    virtual ~GameEngine() {
        for (int i = 0; i < sprites_.size(); ++i) delete sprites_[i];
        delete window_;
        delete bg_;
    }
    virtual void run() {
        while (running_) {
            processEvent();
            update();
            collision();
            render();
        }
        quit();
    }
    virtual void processEvent() {
        char key;
        if (_kbhit()) {
            key = _getch();
            if (key == 27) running_ = false;  // ESC
        }
    }
    virtual void update() {
        for (int i = 0; i < sprites_.size(); ++i) sprites_[i]->update();
    }
    virtual void collision() {}  // 派生类实现
    virtual void render() {
        gotoxy(0, 0);
        hideCursor();
        window_->clear();
        drawScene();
        window_->show();
    }
    virtual void drawScene() {
        bg_->draw(*window_);
        for (int i = 0; i < sprites_.size(); ++i) sprites_[i]->draw();
    }
    virtual void quit() {}
};

// -------------------- 雷电战机游戏类 --------------------
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class SpaceInvader : public GameEngine {
    Player* player_;
    Vector enemies_;       // 敌机指针（不拥有）
    Vector bullets_;       // 我方子弹指针
    Vector enemyBullets_;  // 敌方子弹指针
public:
    SpaceInvader(int w = 80, int h = 30) : GameEngine(w, h), player_(nullptr) {
        player_ = new Player(window_, Color::Green, {w/2, h-4});
        sprites_.push_back(player_);

        int x = random_int(10, w-10);
        int y = random_int(1, 5);
        Enemy* e = new Enemy(window_, Color::Red, {x, y});
        sprites_.push_back(e);
        enemies_.push_back(e);
    }

    void processEvent() override {
        char key;
        if (_kbhit()) {
            key = _getch();
            if (key == 27) running_ = false;
            else if (key == ' ') {
                Bullet* b = player_->shoot({0, -1});
                sprites_.push_back(b);
                bullets_.push_back(b);
            }
            else if (key == 'a' || key == 'A' || key == KEY_LEFT) player_->move({-1,0});
            else if (key == 'd' || key == 'D' || key == KEY_RIGHT) player_->move({1,0});
            else if (key == 'w' || key == 'W' || key == KEY_UP) player_->move({0,-1});
            else if (key == 's' || key == 'S' || key == KEY_DOWN) player_->move({0,1});
        }
    }

    void update() override {
        GameEngine::update();
        for (int i = 0; i < enemies_.size(); ++i) {
            Enemy* e = static_cast<Enemy*>(enemies_[i]);
            Bullet* b = e->get_bullet();
            if (b) {
                sprites_.push_back(b);
                enemyBullets_.push_back(b);
            }
        }
    }

    void collision() override {
        Vector deadSprites;

        // 敌机与玩家、我方子弹碰撞
        for (int i = 0; i < enemies_.size(); ++i) {
            Enemy* e = static_cast<Enemy*>(enemies_[i]);
            if (!e) continue;

            if (player_ && !player_->is_dead() && player_->collide(e->get_rect())) {
                player_->hit();
                e->hit();
            }

            for (int j = 0; j < bullets_.size(); ++j) {
                Bullet* b = static_cast<Bullet*>(bullets_[j]);
                if (b && e->collide(b->get_rect())) {
                    e->hit();
                    b->hit();
                }
            }
        }

        // 玩家与敌方子弹碰撞
        if (player_ && !player_->is_dead()) {
            for (int j = 0; j < enemyBullets_.size(); ++j) {
                Bullet* b = static_cast<Bullet*>(enemyBullets_[j]);
                if (b && player_->collide(b->get_rect())) {
                    player_->hit();
                    b->hit();
                }
            }
        }

        // 收集死亡精灵
        for (int i = 0; i < sprites_.size(); ) {
            if (sprites_[i]->is_dead()) {
                deadSprites.push_back(sprites_[i]);
                sprites_.erase(i);
            } else {
                ++i;
            }
        }

        // 从辅助容器中移除死亡指针
        for (int i = 0; i < deadSprites.size(); ++i) {
            Sprite* dead = deadSprites[i];
            for (int j = 0; j < enemies_.size(); ++j) {
                if (enemies_[j] == dead) { enemies_.erase(j); break; }
            }
            for (int j = 0; j < bullets_.size(); ++j) {
                if (bullets_[j] == dead) { bullets_.erase(j); break; }
            }
            for (int j = 0; j < enemyBullets_.size(); ++j) {
                if (enemyBullets_[j] == dead) { enemyBullets_.erase(j); break; }
            }
        }

        // 释放死亡精灵内存
        for (int i = 0; i < deadSprites.size(); ++i) delete deadSprites[i];

        if (player_ && player_->is_dead()) running_ = false;
    }
};

// 增加敌机的智能行为
#include <chrono>

void Enemy::update() {
    static auto lastShotTime = std::chrono::high_resolution_clock::now();
    static auto lastMoveTime = lastShotTime;
    auto now = std::chrono::high_resolution_clock::now();

    auto shotDur = now - lastShotTime;
    auto shotMs = std::chrono::duration_cast<std::chrono::milliseconds>(shotDur).count();
    if (shotMs > 2000) {
        shoot({0, 1});
        lastShotTime = now;
    }

    auto moveDur = now - lastMoveTime;
    auto moveMs = std::chrono::duration_cast<std::chrono::milliseconds>(moveDur).count();
    if (moveMs > 300) {
        int r = random_int(0, 5);
        if (r == 1) pos_.x -= 1;
        else if (r == 2) pos_.x += 1;
        else if (r == 3) pos_.y += 1;
        lastMoveTime = now;
    }

    Fighter::update();
}

// 主函数
int main() {
    SpaceInvader game;
    game.run();
    return 0;
}
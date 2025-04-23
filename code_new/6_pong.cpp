#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#define _WIN32
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
void hide_cursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // 隐藏光标
    SetConsoleCursorInfo(console, &cursorInfo);
}
void show_cursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = TRUE;  // 显示光标
    SetConsoleCursorInfo(console, &cursorInfo);
}
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// 检测是否有按键输入（类似 _kbhit()）
int _kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// 读取单个按键（类似 _getch()）
char _getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif


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

bool initWindow(int width, int height) {
    framebuffer = new color[width * height];
    if (!framebuffer) return false;
    framebuffer_width = width;
    framebuffer_height = height;
    clearWindow();
    return true;
}

//用清屏颜色clear_color清空窗口内容
void clearWindow() {
    for (int y = 0; y < framebuffer_height; y++)
        for (int x = 0; x < framebuffer_width; x++)
            framebuffer[y * framebuffer_width + x] = clear_color;

}

//销毁窗口，释放帧缓冲器占用的内存
void destoryWindow() {
    delete[] framebuffer;
    framebuffer = nullptr;
}

//显示帧缓冲区的图像
#ifdef WIN32
#include <windows.h>
void show() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;

    for (int y = 0; y < framebuffer_height; y++) {
        WriteConsoleOutputCharacterA(
            hConsole,
            &framebuffer[y * framebuffer_width],  // 每行的起始位置
            framebuffer_width,
            { 0, (SHORT)y }, // 设置光标到当前行
            &written
        );
    }    
}
#else
#include <unistd.h>
void show() {
    // 清屏并移动光标到左上角
    write(STDOUT_FILENO, "\033[H\033[J", 6);

    for (int y = 0; y < framebuffer_height; y++) {
        write(STDOUT_FILENO, &framebuffer[y * framebuffer_width], framebuffer_width);  // 写入一行字符
        write(STDOUT_FILENO, "\n", 1);  // 手动换行
    }
}
#endif

void setPixel(const int x, const int y, color c) {
    framebuffer[y * framebuffer_width + x] = c;
}
color getPixel(const int x, const int y) {
    return framebuffer[y * framebuffer_width + x];
}

//1. 初始化游戏中的数据
int ball_x, ball_y, ball_vec_x{ 0 }, ball_vec_y{ 0 }; // 球的位置和速度
int paddle_w{ 3 }, paddle_h{ 10 };                           // 挡板的宽度和高度
int paddle1_x, paddle1_y, paddle1_vec{ 0 };         // 左挡板位置和速度
int paddle2_x, paddle2_y, paddle2_vec{ 0 };         // 右挡板位置和速度
int score1{ 0 }, score2{ 0 }, score1_x, score1_y, score2_x, score2_y; // 得分及其显示位置

void random_ball(const int window_width, const int window_height);

bool init(const int window_width = 80, const int window_height = 30) {
    if (!initWindow(window_width, window_height)) {  // 初始化窗口
        return false;
    }
    ball_x = window_width / 2;
    ball_y = window_height / 2;

    paddle1_x = 0; paddle1_y = window_height / 2 - paddle_h / 2;
    paddle2_x = window_width - paddle_w; paddle2_y = paddle1_y;
    paddle1_vec = 3;  paddle2_vec = 3;

    score1 = 0; score2 = 0;
    score1_x = paddle_w + 8;           score1_y = 2;
    score2_x = window_width - 8 - paddle_w; score2_y = 2;
    //    auto pong_circle_r2{ 40 };  //禁区半径的平方

    srand((unsigned)time(0));  //生成随机数种子
    random_ball(window_width, window_height);
    return true;
}
//初始化球的位置和速度
#define RANDOM_DIRECTION() ((rand() % 3 + 1) * (rand() % 2 ? 1 : -1))
void random_ball(const int window_width, const int window_height) {
    ball_x = window_width / 2; ball_y = window_height / 2;
    ball_vec_x = RANDOM_DIRECTION();
    ball_vec_y = RANDOM_DIRECTION();
}

//背景包括上下墙壁、左右沟渠和中间分割线，可以用一个函数绘制到画布上：
color boundary_color = '|';
color wall_color = '=';
void draw_background() {
    clearWindow();               //清空为背景颜色    
    int& window_width = framebuffer_width, & window_height = framebuffer_height;
    auto right{ window_width - 1 }, middle{ window_width / 2 };
    for (int y = 0; y < window_height; y++) {
        setPixel(0, y, boundary_color);
        setPixel(middle, y, boundary_color);
        setPixel(right, y, boundary_color);
    }
    int bottom = window_height - 1;
    for (int x = 0; x < window_width; x++) {
        setPixel(x, 0, wall_color);
        setPixel(x, bottom, wall_color);
    }
}

//draw_sprites()绘制场景中的精灵：球、挡板和得分。

color ball_color = 'O';
color paddle_color = 'z';
void draw_sprites() {
    //绘制球
    setPixel(ball_x, ball_y, ball_color);
    //绘制左、右挡板
    for (auto y = paddle1_y; y < paddle1_y + paddle_h; y++)
        for (auto x = paddle1_x; x < paddle1_x + paddle_w; x++)
            setPixel(x, y, paddle_color);

    for (auto y = paddle2_y; y < paddle2_y + paddle_h; y++)
        for (auto x = paddle2_x; x < paddle2_x + paddle_w; x++)
            setPixel(x, y, paddle_color);

    //绘制分数：分数是一个字符串
    std::string s1{ std::to_string(score1) }, s2{ std::to_string(score2) };
    for (auto i = 0; i < s1.size(); i++)
        setPixel(score1_x + i, score1_y, s1[i]);
    for (auto i = 0; i < s2.size(); i++)
        setPixel(score2_x + i, score2_y, s2[i]);
}


#ifdef _WIN32 
void hideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void cls() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
    hideCursor();  // 隐藏光标
}
#else
void cls() {
    std::cout << "\033[H";  // 将光标移动到 (0,0)
    std::cout << "\033[?25l";  // 隐藏光标  
}
#endif

void render_scene() {
    cls();
    draw_background();   //在画布上绘制背景
    draw_sprites();        //在画布上绘制精灵
    show();              //在屏幕上显示画布内容（场景）
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // 控制更新速度
}

//可将事件处理功能封装在一个函数里：
int processInput() {
    auto WIDTH = framebuffer_width;
    auto HEIGHT = framebuffer_height;
    //  处理事件
    char key;
    if (_kbhit()) {
        key = _getch();
        if (key == 27) return -1; //ESC
        else if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
            paddle1_y -= paddle1_vec;
        else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h
            < HEIGHT)
            paddle1_y += paddle1_vec;
        else if (key == 72 && paddle2_y > paddle2_vec)
            paddle2_y -= paddle2_vec;
        else if ((key == 80) && paddle2_y + paddle2_vec + paddle_h < HEIGHT)
            paddle2_y += paddle2_vec;
    }
    return 0;
}

//更新球的位置，检测球与墙壁、挡板是否发生碰撞。
void update() {
    auto WIDTH = framebuffer_width;
    auto HEIGHT = framebuffer_height;
    // 2. 更新数据 
    ball_x += ball_vec_x;
    ball_y += ball_vec_y;
    if (ball_y < 0 || ball_y >= HEIGHT) {
        ball_vec_y = -ball_vec_y;
        ball_y += ball_vec_y;
    }
    if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
        ball_vec_x = -ball_vec_x;
        score1 += 1;
    }
    else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
        ball_vec_x = -ball_vec_x;
        score2 += 1;
    }
    bool is_out{ false };
    if (ball_x < 0) { score2 += 1; is_out = true; }
    else if (ball_x >= WIDTH) { score1 += 1; is_out = true; }
    if (is_out) {
        random_ball(WIDTH, HEIGHT);
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

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

#define RANDOM_DIRECTION() ((rand() % 3 + 1) * (rand() % 2 ? 1 : -1))

int main() {
    // 1. 初始化游戏中的数据
    auto WIDTH{ 120 }, HEIGHT{ 40 }; // 窗口长宽
    auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }, ball_vec_x{ 0 }, ball_vec_y{ 0 }; // 球的位置及速度
    auto paddle_w{ 3 }, paddle_h{ 10 }; // 挡板的长宽
    auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }, paddle1_vec{ 3 }; // 左挡板位置
    auto paddle2_x{ WIDTH - paddle_w }, paddle2_y{ HEIGHT / 2 - paddle_h / 2 }, paddle2_vec{ 3 }; // 右挡板位置
    auto score1{ 0 }, score2{ 0 }, score1_x{ paddle_w + 8 }, score1_y{ 2 },
        score2_x{ WIDTH - 8 - paddle_w }, score2_y{ 2 };

    srand((unsigned)time(0));  // 生成随机数种子   
    ball_vec_x = RANDOM_DIRECTION();
    ball_vec_y = RANDOM_DIRECTION();

    // 游戏循环
    while (true) {
        // 1. 处理事件
        char key;
        if (_kbhit()) { // 键盘有输入 (注意: _kbhit() 是 Windows 平台相关的函数)
            key = _getch(); // 得到输入的键值 (注意: _getch() 是 Windows 平台相关的函数)

            // 处理左挡板 (Paddle 1) 的移动
            if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec) {
                paddle1_y -= paddle1_vec;
            }
            else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h < HEIGHT) {
                paddle1_y += paddle1_vec;
            }

            // 处理右挡板 (Paddle 2) 的移动
            else if (key == 72 && paddle2_y > paddle2_vec) { // 72 是向上箭头键的 ASCII 码
                paddle2_y -= paddle2_vec;
            }
            else if (key == 80 && paddle2_y + paddle2_vec + paddle_h < HEIGHT) { // 80 是向下箭头键的 ASCII 码
                paddle2_y += paddle2_vec;
            }
        }

        // 2. 更新数据
        ball_x += ball_vec_x;
        ball_y += ball_vec_y;

        if (ball_y < 0 || ball_y >= HEIGHT) { // 和上下墙碰撞，改变垂直速度方向
            ball_vec_y = -ball_vec_y;
        }

        if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
            // 和左挡板碰撞，改变水平速度的方向
            ball_vec_x = -ball_vec_x;
            score1 += 1;
        }
        else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
            // 和右挡板碰撞，改变水平速度的方向
            ball_vec_x = -ball_vec_x;
            score2 += 1;
        }

        // 跑出左右沟渠，球回到中心并以新的随机速度出发
        if (ball_x < 0 || ball_x > WIDTH) {
            if (ball_x < 0) score2++;
            else score1++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            
            ball_vec_x = RANDOM_DIRECTION();
            ball_vec_y = RANDOM_DIRECTION();
        }

        std::string s1{ std::to_string(score1) }, s2{ std::to_string(score2) };

#ifdef _WIN32  
        // 定位到 (0,0)，，相当于清空屏幕
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
        hide_cursor();  // 隐藏光标
#else
        std::cout << "\033[H";  // 将光标移动到 (0,0)
        std::cout << "\033[?25l";  // 隐藏光标    
#endif

        // 3. 绘制新画面
        // 绘制顶部墙
        for (auto x = 0; x < WIDTH; x++)
            std::cout << '=';
        std::cout << '\n';

        // 绘制球、挡板和背景
        for (auto y = 1, HEIGHT_1 = HEIGHT - 1; y < HEIGHT_1; y++) {
            for (auto x = 0; x < WIDTH; x++) {
                if (x == ball_x && y == ball_y)
                    std::cout << 'O';
                else if (y >= paddle1_y && y < paddle1_y + paddle_h
                    && x >= paddle1_x && x < paddle1_x + paddle_w)
                    std::cout << 'Z';
                else if (y >= paddle2_y && y < paddle2_y + paddle_h
                    && x >= paddle2_x && x < paddle2_x + paddle_w)
                    std::cout << 'Z';
                else if (y == score1_y && x == score1_x) { // 左分数位置
                    std::cout << s1;
                    x += s1.size();
                    x--;
                }
                else if (y == score2_y && x == score2_x) { // 右分数位置
                    std::cout << s2;
                    x += s2.size();
                    x--;
                }
                else if (x == 0 || x == WIDTH / 2 || x == WIDTH - 1)
                    std::cout << '|';
                else std::cout << ' ';
            }
            std::cout << '\n';
        }

        // 绘制底部墙
        for (auto x = 0; x < WIDTH; x++)
            std::cout << '=';
        std::cout << '\n';

        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // 控制更新速度
    }
}

#if 0
/*
      ========提高程序效率的方法：=========
      可以用C++的`string`类缓存窗口画面里的内容：
      // 创建一个字符数组来缓存整个画面
      std::string framebuffer(HEIGHT * (WIDTH + 1), ' '); // 包括换行符
      将所有要输出的窗口画面里的字符一行一行地依次放入这个字符串中。如：
      framebuffer[frame_idx] = 'A'; //将字符'A'放入字符串下标frame_idx对应的字符位置
      将字符'A'放入字符串`framebuffer`的下标`frame_idx`对应的字符位置，下标从0开始计算。
      改写后的`main()`代码如下：
  */
int main() {
    // 1. 初始化游戏中的数据
    auto WIDTH{ 120 }, HEIGHT{ 40 }; // 窗口长宽
    auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }, ball_vec_x{ 0 }, ball_vec_y{ 0 }; // 球的位置及速度
    auto paddle_w{ 3 }, paddle_h{ 10 }; // 挡板的长宽
    auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }, paddle1_vec{ 3 }; // 左挡板位置
    auto paddle2_x{ WIDTH - paddle_w }, paddle2_y{ HEIGHT / 2 - paddle_h / 2 }, paddle2_vec{ 3 }; // 右挡板位置
    auto score1{ 0 }, score2{ 0 }, score1_x{ paddle_w + 8 }, score1_y{ 2 },
        score2_x{ WIDTH - 8 - paddle_w }, score2_y{ 2 };

    srand((unsigned)time(0));  // 生成随机数种子   

    ball_vec_x = RANDOM_DIRECTION();
    ball_vec_y = RANDOM_DIRECTION();

    // 创建一个字符数组来缓存整个画面
    std::string framebuffer(HEIGHT * (WIDTH + 1), ' '); // 包括换行符

    // 游戏循环
    while (true) {
        // 1. 处理事件
        char key;
        if (_kbhit()) { // 键盘有输入 (注意: _kbhit() 是 Windows 平台相关的函数)
            key = _getch(); // 得到输入的键值 (注意: _getch() 是 Windows 平台相关的函数)

            // 处理左挡板 (Paddle 1) 的移动
            if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec) {
                paddle1_y -= paddle1_vec;
            }
            else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h < HEIGHT) {
                paddle1_y += paddle1_vec;
            }

            // 处理右挡板 (Paddle 2) 的移动
            else if (key == 72 && paddle2_y > paddle2_vec) { // 72 是向上箭头键的 ASCII 码
                paddle2_y -= paddle2_vec;
            }
            else if (key == 80 && paddle2_y + paddle2_vec + paddle_h < HEIGHT) { // 80 是向下箭头键的 ASCII 码
                paddle2_y += paddle2_vec;
            }
        }

        // 2. 更新数据
        ball_x += ball_vec_x;
        ball_y += ball_vec_y;

        if (ball_y < 0 || ball_y >= HEIGHT) { // 和上下墙碰撞，改变垂直速度方向
            ball_vec_y = -ball_vec_y;
        }

        if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
            // 和左挡板碰撞，改变水平速度的方向
            ball_vec_x = -ball_vec_x;
            score1 += 1;
        }
        else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
            // 和右挡板碰撞，改变水平速度的方向
            ball_vec_x = -ball_vec_x;
            score2 += 1;
        }

        // 跑出左右沟渠，球回到中心并以新的随机速度出发
        if (ball_x < 0 || ball_x > WIDTH) {
            if (ball_x < 0) score2++;
            else score1++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vec_x = rand() % 3 + 1;
            ball_vec_y = rand() % 3 + 1;

            if (rand() % 2 == 1) {
                ball_vec_x = -ball_vec_x;
            }
            if (rand() % 2 == 1) {
                ball_vec_y = -ball_vec_y;
            }
        }

#ifdef _WIN32  
        // 定位到 (0,0)，相当于清空屏幕
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
        hide_cursor();  // 隐藏光标
#else
        std::cout << "\033[H";  // 将光标移动到 (0,0)
        std::cout << "\033[?25l";  // 隐藏光标    
#endif

        // 3. 绘制新画面到 framebuffer
        int frame_idx = 0;
        std::string s1 = std::to_string(score1);  // 左侧分数
        std::string s2 = std::to_string(score2);  // 右侧分数
        

        // 绘制顶部墙
        for (auto x = 0; x < WIDTH; x++) {
            framebuffer[frame_idx++] = '=';
        }
        framebuffer[frame_idx++] = '\n';

        // 绘制球、挡板和背景
        for (auto y = 1, HEIGHT_1 = HEIGHT - 1; y < HEIGHT_1; y++) {
            for (auto x = 0; x < WIDTH; x++) {
                if (x == ball_x && y == ball_y)
                    framebuffer[frame_idx++] = 'O';
                else if (y >= paddle1_y && y < paddle1_y + paddle_h
                    && x >= paddle1_x && x < paddle1_x + paddle_w)
                    framebuffer[frame_idx++] = 'Z';
                else if (y >= paddle2_y && y < paddle2_y + paddle_h
                    && x >= paddle2_x && x < paddle2_x + paddle_w)
                    framebuffer[frame_idx++] = 'Z';
                else if (y == score1_y && x == score1_x) {  // 左分数位置
                    framebuffer[frame_idx++] = s1[0];
                    x += s1.size() - 1;
                }
                else if (y == score2_y && x == score2_x) {  // 右分数位置
                    framebuffer[frame_idx++] = s2[0];
                    x += s2.size() - 1;
                }
                else if (x == 0 || x == WIDTH / 2 || x == WIDTH-1)
                    framebuffer[frame_idx++] = '|';
                else framebuffer[frame_idx++] = ' ';
            }
            framebuffer[frame_idx++] = '\n';
        }

        // 绘制底部墙
        for (auto x = 0; x < WIDTH; x++) {
            framebuffer[frame_idx++] = '=';
        }
        framebuffer[frame_idx++] = '\n';

        // 输出整个屏幕内容
        std::cout << framebuffer;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // 控制更新速度
    }
}
#endif

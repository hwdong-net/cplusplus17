#include <iostream>
#include <random>      // 现代C++随机数库
#include <thread>
#include <chrono>
#include <string>

#define _WIN32   // 根据实际情况注释或取消注释

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
void hide_cursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(console, &cursorInfo);
}
void show_cursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(console, &cursorInfo);
}
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

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

void hide_cursor() {
    std::cout << "\033[?25l";
}
void show_cursor() {
    std::cout << "\033[?25h";
}
#endif

int main() {
    // 1. 初始化游戏中的数据
    const auto WIDTH{ 120 }, HEIGHT{ 40 }; // 窗口长宽
    auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }; // 球的位置
    auto ball_vec_x{ 0 }, ball_vec_y{ 0 }; // 球的速度
    const auto paddle_w{ 3 }, paddle_h{ 10 }; // 挡板的长宽
    auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }; // 左挡板位置
    auto paddle2_x{ WIDTH - paddle_w }, paddle2_y{ HEIGHT / 2 - paddle_h / 2 }; // 右挡板位置
    const auto paddle_vec{ 3 }; // 挡板移动速度
    auto score1{ 0 }, score2{ 0 };  // 双方的得分

    // 使用现代C++随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> velDist(1, 3);   // 速度大小 1~3
    std::uniform_int_distribution<int> dirDist(0, 1);   // 方向

    ball_vec_x = velDist(gen) * (dirDist(gen) ? 1 : -1);
    ball_vec_y = velDist(gen) * (dirDist(gen) ? 1 : -1);

    hide_cursor();          // 隐藏光标
    // 游戏循环
    while (true) {
        // 1. 处理事件
        char key;
        if (_kbhit()) {
            key = _getch();

            if ((key == 'w' || key == 'W') && paddle1_y > paddle_vec) {
                paddle1_y -= paddle_vec;
            }
            else if ((key == 's' || key == 'S') && paddle1_y + paddle_vec + paddle_h < HEIGHT) {
                paddle1_y += paddle_vec;
            }
            else if (key == 72 && paddle2_y > paddle_vec) { // 上箭头
                paddle2_y -= paddle_vec;
            }
            else if (key == 80 && paddle2_y + paddle_vec + paddle_h < HEIGHT) { // 下箭头
                paddle2_y += paddle_vec;
            }
            // 按 q 退出游戏
            else if (key == 'q' || key == 'Q') {
                break;
            }
        }

        // 2. 更新数据
        ball_x += ball_vec_x;
        ball_y += ball_vec_y;

        // 上下边界反弹
        if (ball_y < 0 || ball_y >= HEIGHT) {
            ball_vec_y = -ball_vec_y;
        }

        // 与左右挡板碰撞（只反弹，不加分）
        if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) {
            ball_vec_x = -ball_vec_x;
        }
        else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
            ball_vec_x = -ball_vec_x;
        }

        // 超出左右边界：对方得分，重置球
        if (ball_x < 0) {
            score2++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vec_x = velDist(gen) * (dirDist(gen) ? 1 : -1);
            ball_vec_y = velDist(gen) * (dirDist(gen) ? 1 : -1);
        }
        else if (ball_x > WIDTH) {
            score1++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vec_x = velDist(gen) * (dirDist(gen) ? 1 : -1);
            ball_vec_y = velDist(gen) * (dirDist(gen) ? 1 : -1);
        }

        // 准备分数字符串
        std::string s1 = std::to_string(score1);
        std::string s2 = std::to_string(score2);

#ifdef _WIN32  
        // 定位到 (0,0)，相当于清空屏幕
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
#else
        std::cout << "\033[H";  // 将光标移动到 (0,0)        
#endif

        // 3. 绘制新画面
        // 绘制顶部墙
        for (auto x = 0; x < WIDTH; x++)
            std::cout << '=';
        std::cout << '\n';

        // 绘制球、挡板和背景
        for (auto y = 0; y < HEIGHT; y++) {
            for (auto x = 0; x < WIDTH; x++) {
                if (x == ball_x && y == ball_y)
                    std::cout << 'O';
                else if (y >= paddle1_y && y < paddle1_y + paddle_h && x >= paddle1_x && x < paddle1_x + paddle_w)
                    std::cout << 'Z';
                else if (y >= paddle2_y && y < paddle2_y + paddle_h && x >= paddle2_x && x < paddle2_x + paddle_w)
                    std::cout << 'Z';
                else if (y == 2 && x == paddle_w + 8) { // 左分数位置
                    std::cout << s1;
                    x += s1.size() - 1;
                }
                else if (y == 2 && x == WIDTH - 8 - paddle_w) { // 右分数位置
                    std::cout << s2;
                    x += s2.size() - 1;
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
    show_cursor();          // 恢复光标
}
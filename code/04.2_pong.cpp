#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

#define RANDOM_DIRECTION() ((rand() % 5 + 1) * (rand() % 2 ? 1 : -1))

void gotoxy(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main() {
    // 1. 初始化游戏中的数据
    auto WIDTH{ 90 }, HEIGHT{ 25 };
    auto ball_x{ WIDTH / 2 }, ball_y{ HEIGHT / 2 }, ball_vec_x{ RANDOM_DIRECTION() }, ball_vec_y{ RANDOM_DIRECTION() };
    auto paddle_w{ 3 }, paddle_h{ 8 };
    auto paddle1_x{ 0 }, paddle1_y{ HEIGHT / 2 - paddle_h / 2 }, paddle1_vec{ 3 };
    auto paddle2_x{ WIDTH - paddle_w }, paddle2_y{ HEIGHT / 2 - paddle_h / 2 }, paddle2_vec{ 3 };
    auto score1{ 0 }, score2{ 0 };
    auto score1_x{ paddle_w + 8 }, score1_y{ 2 };
    auto score2_x{ WIDTH - 8 - paddle_w }, score2_y{ 2 };

    srand((unsigned)time(0)); // 只执行一次，初始化随机数种子

    while (true) {
        // 1. 处理输入
        if (_kbhit()) {
            char key = _getch();
            if ((key == 'w' || key == 'W') && paddle1_y > paddle1_vec)
                paddle1_y -= paddle1_vec;
            else if ((key == 's' || key == 'S') && paddle1_y + paddle1_vec + paddle_h < HEIGHT)
                paddle1_y += paddle1_vec;
            else if (key == 72 && paddle2_y > paddle2_vec) // 上箭头
                paddle2_y -= paddle2_vec;
            else if (key == 80 && paddle2_y + paddle2_vec + paddle_h < HEIGHT) // 下箭头
                paddle2_y += paddle2_vec;
        }

        // 2. 更新数据
        ball_x += ball_vec_x;
        ball_y += ball_vec_y;

        if (ball_y < 0 || ball_y >= HEIGHT) ball_vec_y = -ball_vec_y;

        if (ball_x < paddle_w && ball_y >= paddle1_y && ball_y < paddle1_y + paddle_h) { 
            ball_vec_x = -ball_vec_x;
            score1 += 1;
        } else if (ball_x > WIDTH - paddle_w && ball_y >= paddle2_y && ball_y < paddle2_y + paddle_h) {
            ball_vec_x = -ball_vec_x;
            score2 += 1;
        }

        if (ball_x < 0 || ball_x > WIDTH) {
            if (ball_x < 0) score2++;
            else score1++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vec_x = RANDOM_DIRECTION();
            ball_vec_y = RANDOM_DIRECTION();
        }

        gotoxy(0, 0);
        hideCursor();

        // 3. 绘制场景
        string screen;
        screen.reserve((WIDTH + 2) * (HEIGHT + 2));

        // 绘制顶部边界
        screen.append(WIDTH + 1, '=');
        screen += '\n';

        // 绘制主体
        for (int y = 0; y <= HEIGHT; y++) {
            for (int x = 0; x <= WIDTH; x++) {
                if (x == ball_x && y == ball_y) screen += 'O';
                else if (y >= paddle1_y && y < paddle1_y + paddle_h && x < paddle_w) screen += 'Z';
                else if (y >= paddle2_y && y < paddle2_y + paddle_h && x >= WIDTH - paddle_w) screen += 'Z';
                else if (y == score1_y && x == score1_x) screen += to_string(score1);
                else if (y == score2_y && x == score2_x) screen += to_string(score2);
                else if (x == 0 || x == WIDTH / 2 || x == WIDTH) screen += '|';
                else screen += ' ';
            }
            screen += '\n';
        }

        // 底部边界
        screen.append(WIDTH + 1, '=');
        screen += '\n';

        cout << screen;
    }

    return 0;
}

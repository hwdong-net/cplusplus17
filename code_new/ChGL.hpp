#ifndef ChGL_HPP
#define ChGL_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

// 定义颜色类型（字符表示）
using color = char;

// 光标控制类
class CursorController {
public:
    void showCursor() {
#ifdef _WIN32
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(console, &cursorInfo);
        cursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(console, &cursorInfo);
#else
        write(STDOUT_FILENO, "\033[?25h", 6); // 显示光标
#endif
    }

    void hideCursor() {
#ifdef _WIN32
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(console, &cursorInfo);
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(console, &cursorInfo);
#else
        write(STDOUT_FILENO, "\033[?25l", 6); // 隐藏光标
#endif
    }
};

// 输入处理类（独立模块）
class InputHandler {
public:
    bool kbhit() {
#ifdef _WIN32
        return _kbhit();
#else
        struct termios oldt, newt;
        int ch, oldf;
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
            return true;
        }
        return false;
#endif
    }

    char getch() {
#ifdef _WIN32
        return _getch();
#else
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
#endif
    }
};

// 核心图形库类
class ChGL {
private:
    color* framebuffer;          // 帧缓冲区
    int width;                   // 窗口宽度
    int height;                  // 窗口高度
    color clear_color;           // 清屏颜色
    CursorController cursor;     // 光标控制器

    // 私有方法：跨平台显示帧缓冲区
    void displayFrame() {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD written;
        for (int y = 0; y < height; y++) {
            WriteConsoleOutputCharacterA(
                hConsole,
                &framebuffer[y * width],
                width,
                { 0, (SHORT)y },
                &written
            );
        }
#else
        write(STDOUT_FILENO, "\033[H\033[J", 6); // 清屏并移动光标
        for (int y = 0; y < height; y++) {
            write(STDOUT_FILENO, &framebuffer[y * width], width);
            write(STDOUT_FILENO, "\n", 1);
        }
#endif
    }

public:
    ChGL() : framebuffer(nullptr), width(0), height(0), clear_color(' ') {
        cursor.hideCursor(); // 初始化时隐藏光标
    }

    ~ChGL() {
        destroy();
    }

    // 初始化窗口
    bool init(int w, int h) {
        if (framebuffer) return false; // 防止重复初始化
        width = w;
        height = h;
        framebuffer = new color[w * h];
        if (!framebuffer) return false;
        clear();
        return true;
    }

    // 清空窗口
    void clear() {
        for (int y = 0; y < height; y++)
            for (int x = 0; x < width; x++)
                framebuffer[y * width + x] = clear_color;
    }

    // 销毁窗口
    void destroy() {
        if (framebuffer) {
            delete[] framebuffer;
            framebuffer = nullptr;
        }
        width = 0;
        height = 0;
        cursor.showCursor(); // 销毁时恢复光标
    }

    // 显示帧缓冲区
    void show() {
        displayFrame();
    }

    // 设置像素
    void setPixel(int x, int y, color c = ' ') {
        if (x >= 0 && x < width && y >= 0 && y < height)
            framebuffer[y * width + x] = c;
    }

    // 获取像素
    color getPixel(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height)
            return framebuffer[y * width + x];
        return clear_color;
    }

    // 设置/获取清屏颜色
    void setClearColor(color c) {
        clear_color = c;
    }

    color getClearColor() const {
        return clear_color;
    }

    // 获取窗口尺寸
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#endif

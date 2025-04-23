#include "ChGL.hpp"
#include <thread>
#include <chrono>

int main() {
    ChGL win(40, 20);
    InputHandler input;

    int x = 20, y = 10; // 角色初始位置
    win.setClearColor(' '); // 设置清屏颜色为空格

    while (true) {
        // 处理输入
        if (input.kbhit()) {
            char key = input.getch();
            if (key == 'q') break; // 按 'q' 退出
            if (key == 'w' && y > 0) y--; // 上
            if (key == 's' && y < win.getHeight() - 1) y++; // 下
            if (key == 'a' && x > 0) x--; // 左
            if (key == 'd' && x < win.getWidth() - 1) x++; // 右
        }

        // 更新画面
        win.clear();
        win.setPixel(x, y, '@'); // 绘制角色
        win.show();

        // 控制帧率
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

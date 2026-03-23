#include <iostream>
#include <random>

int main() {
    // 现代 C++ 随机数生成
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int target = dist(gen);

    int guess = 0;
    int attempts = 0;

    std::cout << "欢迎来到猜数字游戏！我已经选择了一个 1 到 100 之间的数字，请你来猜。\n";

    while (true) {
        std::cout << "请输入你的猜测（1-100）：";
        std::cin >> guess;

        // 处理非数字输入
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "输入无效，请输入一个整数！\n";
            continue;
        }

        // 范围验证
        if (guess < 1 || guess > 100) {
            std::cout << "请输入一个 1 到 100 之间的数字！\n";
            continue;
        }

        attempts++;

        if (guess < target) {
            std::cout << "太小了！\n";
        }
        else if (guess > target) {
            std::cout << "太大了！\n";
        }
        else {
            std::cout << "恭喜你，猜对了！总共猜了 " << attempts << " 次。\n";
            break;
        }
    }

    return 0;
}
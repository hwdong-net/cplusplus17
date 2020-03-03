#if 0
/*
 这是第一个程序
 this is a first c++ program 
 //hello world  
*/

#include <iostream> //输入输出流 头文件
int main() {
    std::cout << "hello world"; //输出一个字符串
	return 0;
}
#endif

#if 0
#include <iostream> //输入输出流 头文件
#define PI 3.1415
int main() {
    std::cout << PI * 2.5 * 2.5<<std::endl;
    std::cout <<2* PI * 2.5<< std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> //输入输出流 头文件
#define PI 3.1415
int main() {
    int i = 3;
    char ch = 'A';
    double d = 3.14;
    bool ok = true;
    std::cout << i << std::endl;
    std::cout << ch << std::endl;
    std::cout << d << std::endl;
    std::cout << ok << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> //输入输出流 头文件
int main() {
    int x, y = 4;
    x = 3;
    z  = 2 * (3 + 4)
    std::cout << z << std::endl;
}
#endif

#if 0
#include <iostream> //输入输出流 头文件
#define PI 3.14159
int main() {
    double radius;
    std::cout << "请输入圆的半径：";
    std::cin >> radius;
    std::cout << "圆的面积是：" << PI * radius * radius 
        << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> //输入输出流 头文件
#include <iomanip>
int main() {
    
    std::cout << "int"<<'\t'<< "double" << '\t' << "bool\n";
    std::cout << "int" << std::setw(10) << "double" 
        << std::setw(10) << "bool";
    
    return 0;
}
#endif

#if 0
#include <iostream> //输入输出流 头文件

void hello() {
    std::cout << "hello\t";
    std::cout << "wang\n";
}

void add_34() {
    std::cout << "3+4=:" << 3 + 4 << std::endl;
}

double circle_area(double radius) {//形式参数
    return 3.14159 * radius * radius;
}

int main() {
    hello();
    add_34();
    hello(); //代码复用
    std::cout<<circle_area(2.5)<<std::endl;//实际参数
    std::cout << circle_area(3.5) << std::endl;
    std::cout << circle_area(7.5) << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream>
namespace A {
    int a;
    double f() { return 3.14; }
    int g(int i) { return 2 * i; }
}

namespace B {
    double a;
    int f() { return 0; }
    char g;
}

using  A::a;
using  A::f;
int main() {
    int i = 2;
    a = B::f();
    B::a = f();
}
#endif

#if 0
#include <iostream>
int main() {
    double radius;
    std::cout << "请输入圆的半径：";
    std::cin >> radius;
    if (radius <= 0)
        std::cout << "圆半径不能小于0 ";
    else 
        std::cout << "圆的面积是： "<<3.14*radius*radius;
}
#endif

#if 1
#include <iostream>
int main() {
    int i=1, sum = 0;
    while (i <= 100) {
        sum = sum + i;
        i = i + 1;
    }
    std::cout << "1到100的整数之和是：" << sum << std::endl;
}
#endif
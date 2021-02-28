//-----------第1讲：C++介绍-----------------
#if 0
int main() 
{
}
#endif


#if 0
// 程序注释：双斜杠//表示单行注释
int main()
{
}
#endif

#if 0
//C++程序都执行叫做main()的函数
int main() //函数签名
{
}
#endif

#if 0
// 多行注释： /*开头，*/j结尾
/* C++程序都执行叫做main()的函数
 程序注释：双斜杠//表示单行注释
 //多行注释里可以嵌套单行注释，但不能嵌套多行注释
*/
int main() //函数签名
{
}
#endif

#if 0
//语句都以; 结尾。
int main() 
{
    return 0; //return返回0给调用者即操作系统，表示没有错误              
}
#endif



#if 0 //#开头的是预处理指令
int main()
{
                 
}
#endif

#if 0
//预处理指令#include 包含头文件iostream
#include <iostream>  //iostream是标准输入输出头文件
int main()
{
}
#endif

#if 0
//预处理指令#include 包含头文件iostream
#include <iostream>  //iostream是标准输入输出头文件
int main()
{
    std::cout << "hello world!"; //输出一个字符串
                                 //cout是标准名字空间std的名字，
                                 //cout代表标准输出流对象
                                 //"hello world!"：双引号包围的字符串
                                 // << 是输出运算符
    return 0;
}
#endif

#if 0
#include <iostream>
using std::cout;
int main() {
    cout << "        *" << '\n';
    cout << "      *   *" << '\n';
    cout << "    *   *   *" << '\n';
    cout << "  *   *   *   *" << '\n';
    return 0;
}
#endif


#if 0
// 计算圆的面积和周长
#include <iostream> 
int main() {
    std::cout << 3.14 * 2.5 * 2.5 << std::endl;
    std::cout << 2 * 3.14 * 2.5 << std::endl;
    return 0;
}
#endif

#if 0
// 修改圆周率PI的精度
#include <iostream> 
int main() {
    std::cout << 3.1415926 * 2.5 * 2.5 << std::endl;
    std::cout << 2 * 3.14 * 2.5 << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> 
#define PI 3.1415  //宏定义
                   //用#define定义宏
int main() {
    std::cout << PI * 2.5 * 2.5 << std::endl;
    std::cout << 2 * PI * 2.5 << std::endl;
    return 0;
}
#endif


#if 0
//变量就是一块内存，每个变量都有确定的类型。
//类型决定了对变量能进行什么运算、变量占内存大小、变量值范围
#include <iostream> 
int main() {
    int i = 3;                    //整型变量i初始化为文字量3
    char ch = 'A';                //字符型
    double d = 3.14;              //浮点数类型
    bool ok = true;               //布尔类型
    std::cout << i << std::endl;
    std::cout << ch << std::endl;
    std::cout << d << std::endl;
    std::cout << ok << std::endl;
    return 0;
}
#endif

#if 0
//用运算符对数据(变量 / 常量）进行运算，构成了表达式
//一个量也是一个表达式

#include <iostream> 
int main() {
    int x, y = 4;          //同类型变量的定义用逗号隔开
    x = 3;                 //赋值运算符
    z = 2 * (3 + 4)        //算术运算符
    std::cout << z << std::endl;
}
#endif

#if 0
#include <iostream> 
#define PI 3.14159
int main() {
    double radius;
    std::cout << "请输入圆的半径：";   //输出运算符<<
    std::cin >> radius;               //输入运算符>>,
                                      //cin标准输入流对象
    std::cout << "圆的面积是：" << PI * radius * radius 
        << std::endl;
    return 0;
}
#endif

#if 0
//格式化输出
#include <iostream> //输入输出流 头文件
#include <iomanip>  //setw()函数需要的头文件
                    //setw()设置输出宽度
int main() {
    
    std::cout << "int"<<'\t'<< "double" << '\t' << "bool\n";
    std::cout << "int" << std::setw(10) << "double" 
        << std::setw(10) << "bool";
    
    return 0;
}
#endif

#if 0
/*  函数签名格式：
返回类型  函数名(参数列表)      */
int       main(  )
{
    
}
#endif

#if 0
/*  函数定义格式：
返回类型  函数名(参数列表)
{
    多个语句组成的语句块
}
*/
int       main    () 
{
    int i = 3, j = 4;
    i = i + j;
    return 0;
}
#endif


#if 0
//程序中可以有任意多的函数，
//通过函数名调用执行函数体中的语句
#include <iostream> 
void hello() {
    std::cout << "hello\t";
    std::cout << "wang\n";
}

void add_34() {
    std::cout << "3+4=:" << 3 + 4 << std::endl;
}

//函数的形参列表可以定义多个形参
double circle_area(double radius) {//形式参数
    return 3.14159 * radius * radius;
}

int main() {
    hello();      //调用hello()函数
    add_34();    //调用add_34()函数
    hello();     //代码复用
    std::cout<<circle_area(2.5)<<std::endl;  //提供“实际参数”调用函数
    std::cout << circle_area(3.5) << std::endl;
    std::cout << circle_area(7.5) << std::endl;
    return 0;
}
#endif

#if 0
//名字空间：防止名字冲突
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
//名字限定:               
//  名字空间名::名字 
#include <iostream>
int main() {
    double radius;
    std::cout << "请输入圆的半径：";  //m
    std::cin >> radius;
    std::cout << "圆的面积是： " << 3.14 * radius * radius;
}
#endif

#if 0
//using声明：  
//using 名字空间名::名字;
#include <iostream>
using std::cout;
#include <iostream>
int main() {
    double radius;
    cout << "请输入圆的半径：";  //m
    std::cin >> radius;
    cout << "圆的面积是： " << 3.14 * radius * radius;
}
#endif

#if 0
//u引入整个名字空间 ：     
//using namespace A;
#include <iostream>
using namespace std;
#include <iostream>
int main() {
    double radius;
    cout << "请输入圆的半径：";  //m
    cin >> radius;
    cout << "圆的面积是： " << 3.14 * radius * radius;
}
#endif


#if 0
//if条件语句
#include <iostream>
int main() {
    double radius;
    std::cout << "请输入圆的半径：";  //m
    std::cin >> radius;
    if (radius > 0)
        std::cout << "圆的面积是： " << 3.14 * radius * radius;
}
#endif

#if 0
//if条件语句 
#include <iostream>
int main() {
    double radius;
    std::cout << "请输入圆的半径：";  //m
    std::cin >> radius;
    if (radius <= 0)
        std::cout << "圆半径不能小于0 ";
    else
        std::cout << "圆的面积是： " << 3.14 * radius * radius;
}
#endif


#if 0
//while循环语句
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

#if 1
//for循环语句
#include <iostream>
int main() {
    int sum = 0;
    for (int i = 0; i <= 100; i++){
        sum = sum + i;
    }
    std::cout << "1到100的整数之和是：" << sum << std::endl;
}
#endif

// ----------练习--------
#if 0
//找出程序中的错误
#include <iostream>
using namespace std
void main() {
    int FTemp = 0
        int CTemp = 0;
    cout >> "Enter a Farenheit temperature: ";
    cin << FTemp;   CTemp = FTemp - 32 / (9 / 5);
    cout >> "\n <<FTemp >> " in Farenheit = "  >> CTemp >> in Celsius\n";
    return 0;
}
#endif

#if 0
/* 目标：写一个程序计算体积： cube(立方体), sphere(球), cone(圆锥).
**Cube Volume = side^3
**Sphere Volume = (4/3) * pi * radius^3
**Cone Volume = pi * radius^2 * (height/3)
**Write the values to the console.
*/

#include<iostream>
int main() {
    float cubeSide = 5.4;    //Dimension of the cube    
    float sphereRadius = 2.33;   //Dimension of sphere 
    float coneRadius = 7.65;   //Dimensions of cone    
    float coneHeight = 14;
    float volCube, volSphere, volCone = 0;
    return 0;
}
#endif

#if 0
从键盘输入3个实数，然后按从小到大的程序输出
#endif

#if 0
从键盘输入一系列整数，求它们的最大值并输出
#endif


#if 0
/*假设行数从键盘输入，打印输出如下的金字塔。
             *
           *   *
         *   *   *
       *   *   *   * 
*/
#endif



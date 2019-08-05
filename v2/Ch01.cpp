#if 0
/*
   第一个程序
   hello world
   cout是代表屏幕的输出流对象，它的名字cout属于标准名字空间std
*/
#include <iostream>  //输入输出头文件

int main() {
	std::cout << "hello world!";
	std::cout << std::endl;
	std::cout << 3 + 4 << std::endl;
	return 0;
}
#endif

#if 0
/*
  绘制一个飞行器形状
*/
#include <iostream>  

int main() {
	std::cout << "      *\n";
	std::cout << "    *   *\n";
	std::cout << "    *   *\n";
}
#endif 


#if 0
#include <iostream>
int main() {
	double radius = 3.6;
	double area = 3.1415926*radius*radius;
	std::cout << "半径是"<<radius<<"圆的面积是："
		<<area << std::endl;
	radius = 9.8; //修改radius变量的值为9.8
	area = 3.1415926*radius*radius;
//	std::cout << "半径是" << radius << "圆的面积是："
//		<< area << std::endl;
}
#endif

#if 0
//输入运算符>>
//cin是一个代表键盘的输入流对象，也是属于标准名字空间std
#include <iostream>
int main() {
	double radius;
	std::cin >> radius;
	double area = 3.1415926*radius*radius;
	std::cout << "半径是" << radius << "圆的面积是："
		<< area << std::endl;
}
#endif 

#if 0
//函数：命名的程序块
#include <iostream>
void f() {
	std::cout << "你好！" << std::endl;
	std::cout << "hello world！" << std::endl;
}
int main() {
	f();
	return 0;
}
#endif

#if 0
#include <iostream>
#define PI 3.1425926 
int main() {
	double radius = 3.6;
	double area = PI *radius*radius;
	std::cout << "半径是" << radius << "圆的面积是："
		<< area << std::endl;
	radius = 9.8; //修改radius变量的值为9.8
	area = PI *radius*radius;
	std::cout << "半径是" << radius << "圆的面积是："
			<< area << std::endl;
}
#endif

#if 0
#include <iostream>  
int main() {
#if 0
	std::cout << "hello world!";
#else
	std::cout << "你好!";
#endif
	return 0;
}
#endif

#if 0
#define DEBUG
#ifdef  DEBUG
#include <iostream>  
int main() {
	std::cout << "hello world!";
	return 0;
}
#endif

#ifdef Windows
...
#endif
#ifdef Linux
...
#endif

#ifndef F_342345_.h
#define F_342345_.h
#include <iostream>
void f() {
	std::cout << "你好！" << std::endl;
	std::cout << "hello world！" << std::endl;
}
#endif
#endif

#if 0
#include <iostream>
int main() {
	{
		std::cout << "你好！" << std::endl;
		std::cout << "hello world！" << std::endl;
	}
	{
		std::cout << 3 + 4 << std::endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	if (score >= 60)
		std::cout << "你及格了！\n";
	else
		std::cout << "你不及格！\n";
	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	while (score >= 0) 
	{
		if (score >= 60)
			std::cout << "你及格了！\n";
		else
			std::cout << "你不及格！\n";
		std::cin >> score;
	}
	return 0;
}
#endif 

#if 0
#include <iostream>
#include <string>       //包含string类型的头文件
int main() {
	std::string s;      //string也是属于标准名字空间std的名字
	std::cin >> s;
	std::cout << "hello," << s << std::endl;
	return 0;
}
#endif 

#if 0

#include <iostream>       // std::cout
#include <string>         // std::string
int main() {
	std::string s("hello world");
	std::string s2 = s.substr(0, 6);
	std::cout << s2 << "  " << s2.size() << std::endl;
	std::cout << s + s2 << std::endl;
}
#endif


#if 0
#include <iostream>
using namespace std;
// 十进制转换为二进制 
void decToBinary(int n){
	// array to store binary number 
	int binaryNum[1000];

	// counter for binary array 
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array 
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}
int main()
{
	int n = 17;
	decToBinary(n);
	return 0;
}
#endif 

#if 0

#if 0
/*
随机数：srand()、rand()
*/
#include <iostream>
#include <cstdlib>
#include <ctime> 

int main() {
	srand((unsigned)time(0));   //生成随机数种子	
	int M = 4, m = 1;
	char ch;
	do {
		std::cout << (rand() % (M - m) + m) << '\n';
	} while (std::cin >> ch);
}
#else
#include <random>
#include <iostream>
int main(){
	std::random_device rd;  // 将用于为随机数引擎获得种子
	std::mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
	std::uniform_int_distribution<> dis(1, 6);

	for (int n = 0; n < 10; ++n)
		// 用 dis 变换 gen 所生成的随机 unsigned int 到 [1, 6] 中的 int
		std::cout << dis(gen) << ' ';
	std::cout << '\n';
}
#endif
#endif 


#if 0
/*
请编写一个学生成绩统计分析程序，要求
1)能输入、查询、修改、删除学生成绩记录，
2)能统计不同分数段的人数、百分比、分距(最高最低分的差)

一个学生成绩记录包括：班级、姓名、学号、平时成绩、实验成绩、期末成绩、总评成绩
其中总评成绩 = c1*平时成绩+c2*实验成绩+c3*期末成绩。c1、c2、c3从键盘输入。
程序应该具有：输入新纪录、显示所有学生记录、查询、删除、修改等功能。

用一个结构类型表示一个学生记录，如：
typedef struct{
    char class[20],name[10];
	in id;
	double score_gen,score_exp,score_test,score;
}Student;

查找时，需要对字符串进行比较，应包含C语言的字符串处理函数的头文件
<cstring>
建议用动态内存分配存储学生成绩数据，当然也可以用静态数组。
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>

using namespace std;
void help() {
	cout << "请输入命令：\n" ;
	cout << "插入学生成绩记录：I(i)\n";
	cout << "显示所有学生成绩：S(s)\n";
	cout << "查询学生成绩记录：Q(q)\n";
	cout << "删除某个学生成绩：D(d)\n";
	cout << "修改某个学生成绩：M(m)\n";
	cout << "显示帮助命令：H(h)\n";
	cout << "退出程序：Esc键或按CTRL+Z(Windows)或CTRL+D(Unix)\n";
}
int main() {
	cout << "===========欢迎使用《学生成绩分析程序》===================";
	help();
	char cmd;
	while (cin >> cmd) {
		if (cmd == 'H' || cmd == 'h') {
			help(); continue;
		}
	}
}
#endif 

#if 0
#include <iostream>
int main() {
	std::cout << R"d(
          ,-~-. _.---._ ,-~-.
         / .- ,'       `. -. \
         \ ` /`        ' \ ' /
          `-/   'a___a`   \-'
            |   ,'(_)`.   |
            \  ( ._|_. )  /
             \  `.___,'  /
            .-`._     _,'-.
          ,'  ,' `---' `.  `.
         /   /     :     \   \
       ,'   /      :      \   `.
     ,'     |      :      |     `.
    |     ,'|      :      |`.     |
    `.__,' .-\     :     /-. `.__,'
          /   `.   :   ,'   \
   .""-.,'      `._:_,'      `.,-"".
  / ,-. `         ) (         ' ,-. \
 ( (   `.       ,'   `.       ,'   ) )
  \ \    \   _,'       `._   /    / /
   `.`._,'  /             \  `._,','
     `.__.-'               `-.__,'

)d";
			

}
#endif 
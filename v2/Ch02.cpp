/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   qq群：101132160
   微信公众号：hwdong编程
   C++17从入门到精通（源代码）：https://github.com/hwdong-net/cplusplus17
*/

#if 0
#include <iostream>
using namespace std;
int main() {
	int i = 3;
	char ch = 'A';
	double radius = 2.56;
	bool ok = false;

	cout << "int整型占用内存： "<<sizeof(int)<<"字节"<<endl;
	cout << "i占用内存： "<<sizeof(i)<<"字节" <<endl;
    cout << "ch占用内存： "<< sizeof(ch)<<"字节" <<endl;
	cout << "radius占用内存： "<<sizeof(radius)<<"字节" <<endl;
	cout << "ok占用内存： "<<sizeof(ok)<<"字节"<<endl;
}

#endif


#if 0
#include <iostream>
using namespace std;
int main() {
	cout << typeid(18u).name() << '\n'
		<< typeid(022L).name() << '\n'
		<< typeid(18LL).name() << '\n'
		<< typeid(0x12UL).name() << '\n'
		<< typeid(18ULL).name() << '\n';
}

#endif 

#if 0

#if 0
/* 用反斜杠开始的转义字符序列表示某种字符，如：
  \n表示换行符、\t表示制表符、\0表示空字符(结束符)、…
*/
#include<iostream>
int main() {
	std::cout << "\\hello\tworld\n";
	
	std::cout << "\\hello\tworld\n";
}
#endif
#if 0
/*所有的ASCII字符都可以用反斜杠\和其8位ASCII表示。
\0(空字符)       \7  (响铃)      \12 (换行符)    \40(空格)
\115 (‘M’)          \x4d (‘M’)

\后的值不能超过256，因此，一般不超过3位十进制数。如\1234表示的是字符\123和’4’
但\402则非法！
*/
#include<iostream>
int main() {
	std::cout << "\0hello";
	std::cout << "\7he\12ll\123o\115\t\x4d\n";
	std::cout << "\1234\n";	
	std::cout << "\40\402\n";	
}
#endif

#if 0
#include<iostream>
int main() {
    unsigned short a = '\\';
	unsigned short b = '\r';
	unsigned short c = '\x2e';
	std::cout << a << '\t' << b << '\t' << c << '\n';
	std::cout << '\\' << '\t' << '\r' << '\t' << '\x2e' << '\n';
	std::cout << "hello\rworld";
}
#endif
#if 1
/*
以R开头，避免转义字符序列。
	R "delimiter( raw_characters )delimiter"
delimiter是除圆括号()、反斜杠和空格字符之外的字符序列。
*/
#include<iostream>
int main() {	
	std::cout << R"d2f(\\hello\rwor\0ld)d2f";
}
#endif
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	bool b{ true };
	std::cout << b << '\t';
	std::cout << std::boolalpha << b << std::endl;
#if 0
	cout << std::hex << 18 << '\t' << 25 << '\n';
	cout << std::oct << 18 << '\t' << 25 << '\n';
	cout << std::dec << 18 << '\t' << 25 << '\n';
#endif

#if 0
	std::cout << std::fixed << 0.01 << '\n'
		<< std::scientific << 0.01 << '\n'
		<< std::hexfloat << 0.01 << '\n'
		<< std::defaultfloat << 0.01 << '\n';
#endif

}
#endif 

#if 0
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout << std::setprecision(2) << 3.1415926 << '\n';
	cout << std::setw(10) << 3.1415926 << '\n';
	cout << std::setw(10) << std::setfill('-') << 3.1415926 << '\n';
}


#endif 
#if 0
#include <iostream>
using namespace std;
int main() {
	bool b = 42;  //int型值42转换为bool值true,再对b初始化，b的值就是true	
	int i = b; // b的值true转换为int型值1，再初始化int变量i。
	std::cout << boolalpha << b << '\t' << i << std::endl;
	i = 3.14; //double型值3.14转换为int型值3，再对变量i赋值，i的值就是3
	std::cout << i << std::endl;
	unsigned char c = -1; //unsigned char的取值范围是[0,255]
			  // -1关于[0,255]的余数为  (-1+256) % 256 = 255
	signed char c2 = 256; //256超出char的取值范围[-127,128]，结果不可知
	std::cout << (unsigned short)c << std::endl;
	std::cout << (short)c2 << std::endl;
	return 0;
}
#endif

#if 0
//类型别名使代码具有跨平台性，只需用条件编译开关。
#define USING_COMPILER_A
#if defined USING_COMPILER_A
using Int32 = __int32;
using Int64 = __int64;
#elif defined USING_COMPILER_B
using Int32 = int;
using Int64 = long long;
#endif

#endif 

#if 0
#include <iostream>
#include <string>

int main() {
	typedef std::basic_string<char> string;
	std::basic_string<char> s("hello");
	std::string   s2("world");
	std::cout<<s<<"\n" << s2 << "\n";
}


#endif 

#if 0
#if 1
enum class Color { red, green, blue };
enum class Color2 { red, green, blue,yellow };
int main() {
	Color c = Color::green;
	Color2 c2 = Color2::red;
	c2 = c;
}
#else
enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
#include <iostream>
int main() {
	Day d{ Day::Tuesday };	
}
#endif

#endif 

#if 0
#include <iostream>
int g_var;
int main() {
	int var{ 2 };
	{
		std::cout << g_var << '\t' << var << '\n';
		int var{ 0 };
		var = 5;
		std::cout << g_var << '\t' << var << '\n';
	}
	std::cout << g_var << '\t' << var << '\n';
}

#endif 

#if 0
#include <iostream>
#include <string>
using namespace std;
enum class Color { red, green, blue };
int main() {
	string str;
	Color color;
	cin >> str;
	if (str == "red") color = Color::red;
	//...
}


}
#endif

#if 0
int main() {
	int month{ 8 }, day{ 6 };
	//int month{08},day{ 06 };
}
#endif


#if 0
#include <iostream>
int main() {
	int a = 0;
	decltype((a)) b = a;
	b++;
	std::cout << a <<'\t' << b;
}
#endif

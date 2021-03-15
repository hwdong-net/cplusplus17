/*=============变量的定义===================
-------- 为什么需要变量？-----------
// 避免数据硬编码
// 提高代码可读性
// 保存中间结果 ，f(x) = 5x^3-2x^2+4x+6 = 0
// 避免重复计算
*/

#if 0
// 1. 变量定义格式：
// 数据类型  变量名 [初始化式]
// 可以同时定义多个同类型的变量，它们之间用逗号隔开
#include <iostream>
using namespace std;
int main() {
	int adfs3_,b=3;
	std::cout << adfs3_ << " " << b<<endl;
	return 0;
}
#endif 

#if 0
// 2. 变量的初始化： =, (),{}
#include <iostream>
int main() {
	int a;
	int b{};
	int c{ 2 };
	int d = 2 ;
	int e(2);
	std::cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
	return 0;
}
#endif 

#if 0
// 3. 列表初始化{}:不允许导致“信息损失” 的初始化
#include <iostream>
int main() {
	int a;
	int b{};
	int c{ 2.6 };
	int d = 2.6;
	int e(2.6);
	std::cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
	return 0;
}
#endif

#if 0
// 4. auto
// 定义有初始化的变量时，可以用auto推断其数据类型。

#include <iostream>
int  main() {
	auto b = true; //bool
	auto ch{ 'x' }; //char
	auto i = 123;  //int
	auto j = 123L;  //long
	auto d{ 1.2 };  //double
	auto z = d + i;

	std::cout << b << " " << ch << " " << i << " " << j << " "
		<< d << " " << z << '\n';
	return 0;
}
#endif


#if 0
// 5. typeid
// typeid运算符查询得到一个数据类型或变量的类型信息
#include <iostream>
int  main() {
	auto b = true;
	auto ch{ 'x' };
	auto i = 123;
	auto j = 123L;
	auto d{ 1.2 };
	auto z = d + i;

	std::cout << b << " " << ch << " " << i << " " << j << " "
		<< d << " " << z << '\n';

	std::cout << typeid(b).name() << " " << typeid(ch).name() << " "
		<< typeid(int).name() << " " << typeid(j).name() << " "
		<< typeid(d).name() << " " << typeid(z).name() << '\n';
	return 0;
}
#endif

#if 0
// 6. decltype
// 用decltype(exp)得到一个表达式的值的类型，并用这个类型来定义一个变量。
 
#include <iostream>
int  main() {
	decltype(3 + 4.5) c{ 2.4 };
	std::cout << typeid(c).name() << '\n';

	return 0;
}
#endif


#if 0
// 7.赋值运算符=
// 可以用赋值运算符修改该变量的值（该变量内存的值）。
// 初始化=  vs     赋值 =
#include <iostream>
using namespace std;
int main() {
	int a = 2;
	a = 5;
	std::cout << a << std::endl;
}
#endif



#if 0
// 8. const 
// 用const关键字修饰一个变量（对象），用来表示变量的不可修改性。
// 因此，const对象必须初始化

#include <iostream>
int  main() {
	const int i=3;   //未初始化
	//const int j;   //未初始化
	//i = 6;  //错！
	std::cout << i << '\n';
	return 0;
}
#endif


/*==============内在类型===============
C++语言本身已经定义了基本类型（如int、char、double）
和复合类型（数组、指针、引用），这些数据类型称为内在类型。
*/

#if 0
// 1 类型决定了能对变量进行什么样的运算
#include <iostream>
using namespace std;
int main() {
	int x = 3.5, y(4);	
//	double x = 3.5, y(4);
	std::cout << x % y; //% 6%5
}
#endif

#if 0
// 2.类型决定了变量占据内存的大小
#include <iostream>
int main() {
	int i = 3;
	char ch = 'A';
	double radius = 2.56;
	bool ok = false;

	std::cout << "int整型占用内存： " << sizeof(int) << "字节" << std::endl;
	std::cout << "i占用内存： " << sizeof(i) << "字节" << std::endl;
	std::cout << "ch占用内存： " << sizeof(ch) << "字节" << std::endl;
	std::cout << "radius占用内存： " << sizeof(radius) << "字节" << std::endl;
	std::cout << "ok占用内存： " << sizeof(ok) << "字节" << std::endl;
}
#endif


#if 0
// 3.类型决定了值的范围
// 看书上
//  numeric_limits，头文件limits
//numeric_limits类模板提供了一种标准化的方式来查询算术类型的各种属性
#include <limits>
#include <iostream>

int main(){
	std::cout << "type\tlowest()\tmin()\t\tmax()\n\n"
		<< "bool\t"
		<< std::numeric_limits<bool>::lowest() << "\t\t"
		<< std::numeric_limits<bool>::min() << "\t\t"
		<< std::numeric_limits<bool>::max() << '\n'
		<< "uchar\t"
		<< +std::numeric_limits<unsigned char>::lowest() << "\t\t"
		<< +std::numeric_limits<unsigned char>::min() << "\t\t"
		<< +std::numeric_limits<unsigned char>::max() << '\n'
		<< "int\t"
		<< std::numeric_limits<int>::lowest() << '\t'
		<< std::numeric_limits<int>::min() << '\t'
		<< std::numeric_limits<int>::max() << '\n'
		<< "float\t"
		<< std::numeric_limits<float>::lowest() << '\t'
		<< std::numeric_limits<float>::min() << '\t'
		<< std::numeric_limits<float>::max() << '\n'
		<< "double\t"
		<< std::numeric_limits<double>::lowest() << '\t'
		<< std::numeric_limits<double>::min() << '\t'
		<< std::numeric_limits<double>::max() << '\n';
}
#endif

/*==============文字量===============
直接写出值的常量如2、3.14、‘X’、“hello world”等都称为文字量
每个文字量也是有对应的数据类型
*/

#if 0
/*  1. 整型文字量
可以表示为十进制、八进制、十六进制、二进制等不同形式。
以0开头的是八进制，以0x或0X开头的是十六进制，以0b或0B开头的是二进制。
*/
#include <iostream>
using namespace std;
int main() {
	cout << typeid(18).name() << ' '
		<< typeid(022).name() << ' '
		<< typeid(0x12).name() << ' '
		<< typeid(0b100010010).name() << '\n';
}
#endif


#if 0
/*  2. 整型文字量的后缀表示
* 为了表示除int外的其他整型，可以在文字量后面
添加表示不同整型的后缀，字母u或U表示是unsigned整型，
而字母l或L表示long整型，ll或LL表示long long整型。
*/
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
  //3.浮点型文字量
/*必须包含小数点，可用后缀f或F表示float、
用l或L表示long double浮点类型。
*/
#include <iostream>
using namespace std;
int main() {
	cout << 2E3 << '\t' << 0.2e-3 << '\t'
		<< -0.1E-3L << '\t' << .3E2f << '\n';
}
#endif


#if 0
// 4. 字符（串）文字量
// 如果要表示不同类型的字符类型，可以用前缀，
// u8前缀实际是用于表示UTF-8字符串的。
#include <iostream>
using namespace std;
int main() {
	cout << typeid(L'A').name() << '\n'
		<< typeid(u'A').name() << '\n'
		<< typeid(U'A').name() << '\n'
		<< typeid(u8'A').name() << '\n';
	cout << u8"你好，liping" << '\n';
	cout << sizeof(L'A') << " " << sizeof(u'A') << " "
		<< sizeof(U'A') << " " << sizeof(u8'A') << "\n";
}
#endif


#if 0
// 5. 转义字符序列
/*用反斜杠\开始的转义字符序列表示某种字符，
如\n表示换行符、\t表示制表符、\0表示空字符(结束符)、…。
所有的ASCII字符都可以用反斜杠\和其8位ASCII表示。

R "delimiter( raw_characters )delimiter"
*/

#include <iostream>
using namespace std;
int main() {
	cout << "hello\tworld" << '\n'
		
		<< "hello\0world" << '\n'
		<< '\115' << '\n'
	    << '\7' << '\n';  //听到声音吗？
	cout << R"dfdsf( \n\0\t\7 )dfdsf" << '\n';
}
#endif


/*
* ========流操纵符==========
可以用流操纵符控制数据的输出格式
iomanip和ios
*/
#if 0
#include <iostream>
using namespace std;
int main() {
	bool b{ true };
	std::cout << b << '\t';
	std::cout << boolalpha << b << std::endl;
}
#endif


#if 0
// std::dec，std::oct，std::hex
//后续的整数都以十进制、八进制、十六进制形式输出。
#include <iostream>
using namespace std;
int main() {
	std::cout << std::hex << 18 << '\t' << 25 << '\n';
	std::cout << std::oct << 18 << '\t' << 25 << '\n';
	std::cout << std::dec << 18 << '\t' << 25 << '\n';
	return 0;
}
#endif


#if 0
/*如下操纵符改变浮点数的输出格式
std::fixed：以固定精度形式输出
std::scientific：以科学计数法形式输出
std::hexfloat：以十六进制浮点形式输出
std::defaultfloat：以默认形式输出
*/
#include <iostream>
using namespace std;
int main() {
	std::cout << std::fixed << 100.01234567 <<"\t"<< 0.01234567 << '\n'
		<< std::scientific << 100.01 << "\t" << 0.01 << '\n'
		<< std::hexfloat << 100.01 << "\t" << 0.01 << '\n'
		<< std::defaultfloat << 100.01 << "\t" << 0.01 << '\n';
}
#endif

#if 0
/*
iomanip的操纵符往往需要传递一个参数，如setw(5)操纵符表示输出量占据的宽度是5。
std::setw(n)：改变输出域的宽度
std:: setprecision(n)：改变浮点数的精度
std:: setfill(ch)：改变填空字符，当setw的输出域宽度大于输出值的宽度时，
    默认的填空字符是空格，可以用setfill(ch)改变这个填空字符。
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {	
	std::cout << std::setprecision(2) << 3.1415926 << '\n';
	std::cout << std::setw(10) << 3.1415926 << '\n';
	std::cout << std::setw(10) << std::setfill('-') << 3.1415926 << '\n';
}
#endif


/*
* ============类型转换=====================
* 将一种类型的值转化成另外一种类型的值
*/

#if 0
/* 1. 隐式类型转换
用运算符对不同类型的数据进行运算时或定义变量的初始化值类型和变量类型不一致时，
C++编译器会将自动它们转换为同一种类型，称为隐式类型转换。
*/
#include <iostream>
using namespace std;
int main() {
	int i = 3.14;    //在对int型变量i初始化时，会将
				   // double型值3.14转换为int型值3，再对i初始化
	cout << i << endl;
	int  j = i * 2.5;  //i先转换为和 2.5同类型的double值 3.0，2个
	            // double值相乘的结果再转换为int类型值，对变量j初始化
	cout << typeid(i * 2.5).name()<< endl;
	cout << j << endl;
}
#endif

#if 0
/* 1. 强制类型转换
有时需要强制将一种类型值转换为另一种类型值。
1)旧时强制类型转换：  （T） var
double c = 2/(double)5;
2) static_cast<T>
double d = 2/ static_cast<double>5;

*/
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
/*
 混合int和unsigned类型时，
会用取模法(余数法)将负整数隐式转换为unsigned类型的值。
*/
#include <limits>
#include <iostream>
using namespace std;
int main() {	
	cout << std::numeric_limits<unsigned>::min() << "\t\t"
		<< std::numeric_limits<unsigned>::max() << '\n';

	unsigned u = 0;
	u = u - 1;              //如果unsigned是32位整数: [0, 4294967295]
							//-1转换为： (-1+4294967296) % 4294967296
	std::cout << u << std::endl << std::endl;

	int i = -42;
	cout << i + i << endl;   //输出 -84
	cout << u + i << endl;   //如果是32位整数，则输出4294967264
						     //-42转换为： (-42+4294967296)%4294967296
	                         //            = 4294967254
}
#endif


#if 1
/*
 ---------类型别名：给一个类型起一个新名字------
 */
#include <iostream>
 using FLOAT = double;//typedef double FLOAT

 int main(){
	 FLOAT radius{2.5}; //相当于double radius{2.5};
	 std::cout << typeid(radius).name() << std::endl;
	 return 0;
 }

 /*
#define USING_COMPILER_B
#if defined USING_COMPILER_A
using Int32 = __int32;
using Int64 =  __int64;
#elif defined USING_COMPILER_B
using Int32 = int;
using Int64 = long long;
#endif
 */

#endif
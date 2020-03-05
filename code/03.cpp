//=============3. 运算符与表达式===============
//运算符对数据进行数学或逻辑操作的特殊符号，
//如运算符 + 、 * 、 || 分别表示加、乘、逻辑或。
//运算符对数据进行运算就构成了表达式。如
/*
  2+3/5
  3.14*2.5*2.5
*/

// -----------3.1 运算符------------
//按功能的不同，可分为：算术、比较、逻辑、位运算、赋值等
//算术：+、-、*、/、%（求余数）、++（自增）、--（自减）
//比较：==、!=、>、<、>=、<=
//逻辑：&&（逻辑与）、||（逻辑或）、 ！（逻辑非）
//位运算：&（与）、|（或）、^(异或)、~（补）、<<（左移）、>>（右移）
//赋值：=、+=、*=、|=、...

// 按运算数个数，可分为：一元、二元、三元
#if 0
#include <iostream>
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int min = a < b ? (a < c ? a : c) : (b < c ? b : c);
	std::cout << a << "," << b << "," << c << "这3个数的最小值是："
		<< min << std::endl;
}
#endif

//----------溢出问题--------------
#if 0
#include <iostream>
int main() {
	short value = 32767;
	std::cout << value << std::endl;
	value = value + 1;    // value超出short类型的值的范围，结果不可预期！
	std::cout << value << std::endl;
}
#endif

//----------整数和浮点数混合运算--------------
#if 0
#include <iostream>
int main() {
	auto val3 = 21.0 / 6;  //隐含类型转换

	std::cout << "21.0/6 = :" << 21.0 / 6 << std::endl;
	int a = 3, b = 4;
	std::cout << "int/int=:" << a / b << std::endl;
	std::cout << "double/int=:" << static_cast<double>(a) / b << std::endl;
	std::cout << "int/double=:" << a / static_cast<double>(b) << std::endl;
	std::cout << "double/double=:" << static_cast<double>(a) / static_cast<double>(b) << std::endl;
}
#endif

//----------求余数运算 %--------------
#if 0
#include <iostream>
int main() {
	int ival = 10;
	double dval = 3.14;
	auto val = ival % 4;
//	auto val2 = dval % 4;  //错：%不能用于实数
	std::cout << "val:" << val << std::endl;

	std::cout << "21 % 6:" << 21 % 6 << std::endl; //结果是3  
	std::cout << "21 % 7:" << 21 % 7 << std::endl;  //结果是0 
	std::cout << "-21 % (-8):" << -21 % (-8) << std::endl; //结果是-5  
	std::cout << "21 % (-5):" << 21 % (-8) << std::endl; //结果是5
}
#endif

//-----------自增++和自减------------------
#if 0
#include <iostream>
int main() {
	int a = 3, b = 3;
	std::cout << "a++的值" << a++ << ", a的值是" << a << std::endl;
	std::cout << "++b的值" << ++b << ", b的值是" << b << std::endl;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int x = 1;
	int a = ++x;         //x先增加1为2，表达式++x为更新后的x值2,a的值为2
	int b = x++;         //表达式x++的值为x的值2,即b = 2,然后x自增1为3
	int c = ++ ++x;      //c和x的都是5
	int d = x + ++x;      //因为x和++x是+的2个运算数，但x和++x哪个先计算值是不确定的，
						// 结果可能是5+6，也可能是6+6
//	int e = x++ ++;      //出现编译错误:需要左值
	cout << a << endl << b << endl << c << endl << d << endl;
	return 0;
}

#endif

//-------cmath-------
#if 0
#include <cmath>
#include <iostream>
int main() {
	double d = 3.5;
	std::cout << sqrt(3.5) << std::endl;// 输出3.5的平方根

	double base = 3.5, exp = 6.4;;
	std::cout << base << "^" << exp << "等于" << pow(base, exp);
	return 0;
}
#endif


#if 0
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double x = 20.5, result;
	result = log10(x);
	cout << "log10(x) = " << result << endl;

	x = -2.5;
	result = log10(x);
	cout << "log10(x) = " << result << endl;

	return 0;
}
#endif

#if 0
#include <cmath>
#include <iostream>
int main() {
	float angle_deg{ 60.0f };      //角度
	const float pi{ 3.14159265f };
	const float pi_degrees{ 180.0f };
	float tangent{ std::tan(pi * angle_deg / pi_degrees) };
	float angle(std::atan(tangent));
	float angle_deg2{ angle * pi_degrees / pi };
	std::cout << angle << '\t' << angle_deg2 << '\t' << angle_deg << '\n';
}
#endif

//------位运算--------
/*
      a = 0 0 1 0 0 1 0 1
	  b = 0 0 0 1 0 1 1 0
*/
#if 0
//~x 的结果是: -(x+1)
#include <iostream>
#include <bitset>
#include <iomanip>
int main() {
	char a{ 37 }, b{ 22 };
	std::cout << std::left;
	std::cout << std::setw(5) << "a:" << std::setw(5)<< +a << std::bitset<8>(a) << '\n'
		<< std::setw(5) << "b:" << std::setw(5) << +b << std::bitset<8>(b) << '\n';

	std::cout << std::setw(5) << "a&b" << std::setw(5) << (a & b)  << std::bitset<8>(a & b) << '\n';
	std::cout << std::setw(5) << "a|b" << std::setw(5) << (a | b)  << std::bitset<8>(a | b) << '\n';
	std::cout << std::setw(5) << "a^b" << std::setw(5) << (a ^ b) << std::bitset<8>(a ^ b) << '\n';

	std::cout << std::setw(5) << "~a" << std::setw(5) << (~a)  << std::bitset<8>(~a) << '\n';
	std::cout << std::setw(5) << "a<<2" << std::setw(5) << (a << 2)  << std::bitset<8>(a<<2) << '\n';
	std::cout << std::setw(5) << "a>>2" << std::setw(5) << (a >> 2)  << std::bitset<8>(a>>2) << '\n';

	a = -37;
	std::cout << std::setw(5) << "a:" << std::setw(5) << +a << std::bitset<8>(a) << '\n';
	std::cout << std::setw(5) << "~a" << std::setw(5) << (~a) << std::bitset<8>(~a) << '\n';
	std::cout << std::setw(5) << "a<<2" << std::setw(5) << (a << 2) << std::bitset<8>(a << 2) << '\n';
	std::cout << std::setw(5) << "a>>2" << std::setw(5) << (a >> 2) << std::bitset<8>(a >> 2) << '\n';
}
#endif


//----------赋值运算符-----------
#if 0
#include <iostream>
int main() {
	//右结合性
	int a{}, b{ 3 }, c{ 4 };
	a = b = c = 2;
	std::cout << a << '\t' << b << '\t' << c << '\n';
	//左运算数必须是左值
	3 = a; //错
	a+b == 5;
	//不能修改const对象
	const int d = 5;
	d = 1; //
}
#endif

#if 0
#include <iostream>
#include <bitset>
#include <iomanip>
int main() {
	int a(3), b{ 4 },c;
	a *= b;
	std::cout << a << std::endl;
	a = 3;
	std::cout << std::left;
	std::cout << std::setw(5) << "a:" << std::setw(5) << +a << std::bitset<8>(a) << '\n'
		<< std::setw(5) << "b:" << std::setw(5) << +b << std::bitset<8>(b) << '\n';
	a |= b;
	std::cout << std::setw(5) << "a:" << std::setw(5) << +a << std::bitset<8>(a) << '\n';
	
}
#endif

//-----------关系运算符-------------
#if 0
//关系运算符(如<)优先于赋值运算符=
#include <iostream>
using namespace std;
int main() {
	int a = 4, b = 5;
	bool b1 = a < b;    // bool b1 = (a<b) 
	bool b2 = a == b;   // bool b2 = (a==b) 
	//boolalpha使得后面的bool变量输出"true"或"false"而不是1或0
	cout << boolalpha << b1 << '\t' << b2 << endl;
}
#endif

#if 0
//浮点数不能用==判断2个数是否相等
#include <iostream>
#include<iomanip>
using namespace std;
int main() {
	double d1(100 - 99.99);
	double d2(10 - 9.99);
	bool b = d1 == d2; // bool b = (d1==d2)
	cout << boolalpha << b << endl;

	cout << setprecision(17); //浮点数输出格式修改为精度17位
	cout << d1 << endl;
	cout << d2 << endl;
}
#endif

#if 0
//用绝对误差或相对误差判断2个浮点数是否相等
#include <iostream>
#include<cmath>    // 绝对值函数fabs函数在cmath头文件中
#include<iomanip>
using namespace std;
int main() {
	double d1(100 - 99.99);
	double d2(10 - 9.99);
	bool b = fabs(d1 - d2) < 1e-10;   // 误差是否足够小？
	cout << boolalpha << b << endl;
	cout << setprecision(17);
	cout << d1 << endl;
	cout << d2 << endl;
}
#endif

//----------逻辑运算------
#if 0
#include <iostream>
int main() {
	int a = 4, b = 0;
	std::cout << std::boolalpha;
	std::cout << (a || b) << std::endl
		<< (a && b) << std::endl
		<< (!a && b) << std::endl;

	std::cout << '\n';
	std::cout << (a or b) << std::endl
		<< (a and b) << std::endl
		<< (not a and b) << std::endl;
}
#endif

//-----------逗号运算符-----------
//1)
//   exp1, exp2
//  依次计算exp1 和exp2的值，整个表达式的值是exp2的值。
//2) 注意：逗号运算符优先级低于赋值运算符
#if 0
#include <iostream>
int main() {
	auto a{ 4 }, b{ 3 };
	//auto c = a, b;  //错：逗号运算符号优先级低于=
	auto d = (a, b);
	std::cout << d << std::endl;
}

#endif
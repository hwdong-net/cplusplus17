//1. 为什么需要变量？
//1.1 避免数据硬编码
//1.2 提高代码可读性
// 1.3 保存中间结果 ，f(x) = 5x^3-2x^2+4x+6 = 0
// 1.4 避免重复计算

#if 0
#include <iostream>
#define PI 3.1415926
int  main() {	
	std::cout << PI * 2.5 * 2.5 << std::endl; //
	std::cout << 2 * PI * 2.5 << std::endl;
	return 0;
}
#endif 

#if 0
#include <iostream>
#define PI 3.1415926
int  main() {
	double radious;
	std::cin >> radious;
	std::cout << PI * radious * radious <<std::endl;
	std::cout << 2* PI * radious << std::endl;
	return 0;
}
#endif

#if 0
//ax^2+bx+c = 0
#include <iostream>
int  main() {	
	double a = 1, b = 8, c = 1.5;
	std::cin >> a>>b>>c;
	double d = sqrt(b * b - 4 * a * c);
	double a2 = 2 * a;
	std::cout << "x1:" << (-b + d) / a2 << std::endl;
	std::cout << "x2:" << (-b - d) / a2 << std::endl;
	return 0;
}
#endif


#if 0
#include <iostream>
int  main() {
	int a;
	int b{};
	int c{ 2 };
	int d = 3;
	int e(5);
	std::cout << a << " " << b << " " << c << " " << d << " "
		<< e << '\n';
	return 0;
}
#endif

#if 0
#include <iostream>
int  main() {
	double d;
	double d1{};
	double d2{ 3.5 };
	double d3 = 3.5;
	double d4(3.5);
	
	int i1{};
	int i2{ 3.5 };
	int i3 = 3.5;
	int i4(3.5);

	
	std::cout << d << " " << d1 << " " << d2 << " " << d3 << " "
		<< d4 << '\n';

	std::cout << i << " " << i1 << " " << i2 << " " << i3 << " "
		<< i4 << '\n';
	return 0;
}
#endif

#if 0
// auto 
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
	return 0;
}
#endif

#if 0
// auto 
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
		<< typeid(i).name() << " " << typeid(j).name() << " "
		<< typeid(d).name() << " " << typeid(z).name() << '\n';
	return 0;
}
#endif

#if 0
// decltype 
#include <iostream>
int  main() {
	decltype(3 + 4.5) c{ 2.4 };
	std::cout << typeid(c).name() << '\n';

	return 0;
}
#endif

#if 0
// const 
#include <iostream>
int  main() {
	const int c;
	std::cout << c << '\n';

	return 0;
}
#endif

#if 0
#include <iostream>
int  main() {
	auto i{ 3 };
	auto ch{ 'A' };
	auto d{ 3.14 };
	auto ok{true };
	std::cout << sizeof(i) <<" " << sizeof(int) << std::endl;
	std::cout << sizeof(ch) << " " << sizeof(char) << std::endl;
	std::cout << sizeof(d) << " " << sizeof(double) << std::endl;
	std::cout << sizeof(ok) << " " << sizeof(bool) << std::endl;
	return 0;
}
#endif

#if 0
#include <iostream>
int  main() {
	double a{ 3.14 };
	int b = 2;
	std::cout <<a%b <<std::endl;	
	return 0;
}
#endif


#if 0
#include<iostream> 
#include<limits.h> // for int,char macros 
#include<float.h> // for float,double macros 
using namespace std;
int main(){
	// Displaying ranges with the help of macros 
	cout << "char ranges from : " << CHAR_MIN << " to " << CHAR_MAX;
	cout << "\n\nshort char ranges from : " << SCHAR_MIN << " to " << SCHAR_MAX;
	cout << "\n\nunsigned char ranges from : " << 0 << " to " << UCHAR_MAX;

	cout << "\n\n\nshort int ranges from : " << SHRT_MIN << " to " << SHRT_MAX;
	cout << "\n\nunsigned short int ranges from : " << 0 << " to " << USHRT_MAX;
	cout << "\n\nint ranges from : " << INT_MIN << " to " << INT_MAX;
	cout << "\n\nunsigned int ranges from : " << 0 << " to " << UINT_MAX;
	cout << "\n\nlong int ranges from : " << LONG_MIN << " to " << LONG_MAX;
	cout << "\n\nunsigned long int ranges from : " << 0 << " to " << ULONG_MAX;
	cout << "\n\nlong long int ranges from : " << LLONG_MIN << " to " << LLONG_MAX;
	cout << "\n\nunsigned long long int ranges from : " << 0 << " to " << ULLONG_MAX;

	cout << "\n\n\nfloat ranges from : " << FLT_MIN << " to " << FLT_MAX;
	cout << "\n\nnegative float ranges from : " << -FLT_MIN << " to " << -FLT_MAX;
	cout << "\n\ndouble ranges from : " << DBL_MIN << " to " << DBL_MAX;
	cout << "\n\nnegative double ranges from : " << -DBL_MIN << " to " << +DBL_MAX;

	return 0;
}

#endif




#if 0
#include <iostream>
int  main() {
	std::cout << 18u << '\t' << 022L << '\t' << 0x12UL << '\t'
		<< 0x12LL << '\t' << 18ULL << '\n';
	std::cout << typeid(18u).name() << '\t' 
		<< typeid(022L).name() << '\t' 
		<< typeid(0x12UL).name() << '\t'
		<< typeid(0x12LL).name() << '\t' 
		<< typeid(18ULL).name() <<  '\n';

	std::cout << '\115' << " " << '\12' << " " << '\x4d' << " "
		<< '\?' << " " << '\40' << '!' << '\n';
	std::cout << '\7';

	std::cout << R"sdsd(\\hello\rworld\0\t\n)sdsd";
	return 0;
}
#endif

#if 0
#include <iostream>
int  main() {
	bool b = 3.14;
	int k = b;
	k = 3.14;
	double d = k;
	unsigned char c = -1;
	signed char c2 = 256;

	std::cout << b << " " << k << " " << d << " \n";
	std::cout << c << " " << c2 << " \n";
	std::cout << (int)c << " " << (int)c2 << " \n";
	return 0;
}
#endif

#if 0
#include <iostream>
int  main() {
	double d = 2 / 5;
	double d2 = 2 / (double)5;
	std::cout << d << " " << d2 << " \n";

	unsigned char c = -1;
	signed char c2 = 256;
	std::cout << static_cast<unsigned> (c) << " " 
		<< static_cast<signed>(c2) << " \n";
	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	unsigned u = 0;
	u = u - 1;                 //如果unsigned是32位整数: [0, 4294967295]
							//-1转换为： (-1+4294967296) % 4294967296
	std::cout << u << std::endl;
	int i = -42;
	std::cout << i + i << std::endl;   //输出 -84
	std::cout << u + i << std::endl;   //如果是32位整数，则输出4294967264
						   //-42转换为： (-42+4294967296)%4294967296 = 4294967254
	return 0;
}

#endif

#if 0
#include <iostream>
enum class Day {
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

int main() {
	Day d{ Day::Monday };
	
	return 0;
}

#endif

#if 0
enum class Color { red, green, blue };
enum class Color2 { red, green, blue, yellow };
int main() {
	Color c = Color::green;
	Color2 c2 = Color2::red;
	c2 = c;
}

class X { //类

};
#endif

#if 0
#include <string>
#include<iostream>
using namespace std;
int main() {
	string s1("hello"), s2 = "world", s3;
	cout << s1 << '\t' << s2 << '\t' << s3 << '\n';
	
	s3 = s1 + s2;

	cout << s3 << '\t' << s3.size() << '\n';
}

#endif

#if 0
#include <vector>
#include<iostream>
using namespace std;
int main() {
	vector<int> iv;
	iv.push_back(1233);
	iv.push_back(3544);
	iv.push_back(6754674);

	
	for (int i = 0; i != iv.size(); i++)
		std::cout << iv[i]<<'\t';
	std::cout << '\n';

	vector<char> cv(5);
	cv[2] = 'A';
	for (int i = 0; i != cv.size(); i++)
		std::cout << cv[i] << '\t';
	std::cout << '\n';

}

#endif
 
#if 0
#include<iostream>
#include <string>
using namespace std;

struct Person { //类 类型
	string name;
	int age;
};
int main() {
	Person john;
	john.name = "john";//成员访问运算符
	john.age = 30;

	std::cout << john.name <<'\t'<< john.age<< '\n';

}

#endif

#if 1
#include<iostream>
using namespace std;
int  g_var;

int main() {
	int var{ 2 };
	{
		std::cout << g_var << '\t' << var << std::endl;
		int var{ 0 };
		var = 5;
		std::cout << g_var << '\t' << var << std::endl;
	}
	std::cout << g_var << '\t' << var << std::endl;
}

#endif
#if 0
#include <iostream>
int main() {
	std::cout << "hello world";
	std::cout << std::endl;
	std::cout << "教小白精通编程";
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	cout << "hello\n\nworld";
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
int main() {
	auto b = true;  // true是布尔类型的一个值
	auto ch{ 'x' };    // 单引号表示的字符’x’对变量ch初始化
	auto i = 123;   //123是int整型的值
	auto d{ 1.2 };   // 1.2表示的是double浮点型的值
	auto z = d + i;   //从表达式d+i的值推断z的数据类型
	cout << typeid(b).name() << '\t';
	cout << typeid(ch).name() << '\t';
	cout << typeid(i).name() << '\t';
	cout << typeid(d).name() << '\t';
	cout << typeid(z).name() << endl;
}

#endif
#if 0
#include <iostream>
#include <string>
int main() {
	std::string s = "hello", s2 = "world";
	std::cout << s * s2;
	std::cout<<3*s ;
}
/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   qq群：101132160
   微信公众号：hwdong编程
   C++17从入门到精通（源代码）：https://github.com/hwdong-net/cplusplus17
*/

#if 1
#include <iostream>
#include <bitset>
int main_1() {
	std::cout <<"十进制：" << std::dec << 0b101101011101100111100101 <<'\n'
		<< "十六进制：" <<std::hex<< 0b101101011101100111100101 <<'\n'
		<< "八进制：" << std::oct << 0b101101011101100111100101 << '\n';

	
	std::cout << "十进制：" << std::bitset<sizeof(unsigned int) * 8>(7654321) << std::endl;
	return 0;
}
#endif
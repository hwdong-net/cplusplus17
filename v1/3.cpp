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
#include <bitset>
#include <iomanip>
int main() {
	char a{ 37 }, b{ 22 };
	std::cout << std::setw(5) << "a:" << std::bitset<8>(a) << '\n'
		<< std::setw(5) << "b:" << std::bitset<8>(b) << '\n';
	std::cout << std::setw(5) << "~b:" << std::bitset<8>(~b)
		<< '\t' << ~b << '\n';
	std::cout << std::setw(5) << "a^b:" << std::bitset<8>(a^b)
		<< '\t' << (a^b) << '\n';
}
#endif


#if 0
#include <iostream>
#include <bitset>
#include <iomanip>
int main() {
	char a{ 37 }, b{ 22 };
	std::cout <<std::setw(5)<<"a:"<< std::bitset<8>(a) << '\n'
		<< std::setw(5) << "b:"<< std::bitset<8>(b) << '\n';
	std::cout << std::setw(5) << "~b:" << std::bitset<8>(~b)
		<< '\t' << ~b << '\n';
	std::cout << std::setw(5) << "a^b:" << std::bitset<8>(a^b) 
		<< '\t' << (a^b) << '\n';
}
#endif
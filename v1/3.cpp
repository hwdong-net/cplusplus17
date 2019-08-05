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
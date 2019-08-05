#include <iostream>
#include <string>
using namespace std;
int main() {
	const string myString = "Hello,my weibo name is hw-dong";
	
	if (const auto it = myString.find("Hello"); it != std::string::npos)
		std::cout << it << " Hello\n";

	if (const auto it = myString.find("hw-dong"); it != std::string::npos)
		std::cout << it << " hw-dong\n";
}
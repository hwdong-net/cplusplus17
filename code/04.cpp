#if 0
#include <iostream>
using namespace std;
int main() {
	double score;
	std::cin >> score;
	if (score < 60)
		std::cout << "不及格！" << std::endl;
	else
		std::cout << "及格了！" << std::endl;
		return 0;
}
#endif 


#if 0
#include <iostream>
using namespace std;
int main() {
	double score;
	std::cin >> score;
	if (score < 60)
		std::cout << "不及格！" << std::endl;
	else if (score < 70)
		std::cout << "及格！" << std::endl;
	else if (score < 80)
		std::cout << "中等！" << std::endl;
	else if (score < 90)
		std::cout << "良好！" << std::endl;
	else
		std::cout << "优秀！" << std::endl

	return 0;
}
#endif 

#if  0
<iostream>
int main() {
    double score;
	std::cin >> score;
	if (score >= 60) {
		if (score >= 90)
			std::cout << "优秀！" << std::endl;
	}
	else
		std::cout << "不及格！" << std::endl;
	return 0;
}
#endif 


#if 0
#include <iostream>

int main() {
	int a = -100;
	if (a < 0) {
		std::cout << "a的绝对值是";
		std::cout << -a;
	}
	else {
		std::cout << "a的绝对值是";
		std::cout << a;
	}
	return 0;
}
#endif 

#if 0
#include <iostream>

int main() {
	int x;
	std::cin >> x;
	switch (x) {
	case 0:
	case 1:
		std::cout << "x是 0 或1\n";
		break;   //break关键字用于跳出switch       
	case 2:
		std::cout << "x 是 2\n";
		break;   //break关键字用于跳出switch    
	default:
		std::cout << "x 不是 0，1， 2\n";
		//break;   //break关键字用于跳出switch          
	}

	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	unsigned vowelCnt = 0, nonVowelCnt = 0;
	char ch;
	while (std::cin >> ch) {
		switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowelCnt++;
			break;          //跳出switch循环
		default:
			nonVowelCnt++;
			break;          //跳出switch循环
		}
	}
	std::cout << vowelCnt << std::endl;
	std::cout << nonVowelCnt << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
int main() {
	unsigned v;
	std::cin >> v;
	switch (v) {
	case 1: {
		int x = 0;
		std::cout << x << '\n';
	
		  break;
	}
        //  'x' 的作用域在此结束
	default: std::cout << "default\n"; // 无错误
		break;
	}
	return 0;
}
#endif 


#if 0
// 计算n的阶乘
// n的阶乘 n! = 1*2*3...*n
#include <iostream>
using namespace std;
int main() {
	int n, i{ 1 }, factorial{ 1 };
	cout << "请输入一个正整数: ";
	cin >> n;

	while (i <= n) {       //只要i小于等于n，就一直执行while循环体
		factorial *= i;       //factorial = factorial * i;
		++i;
	}

	cout << n << "的阶乘是：= " << factorial;
	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	while (std::cin >> score) {
		sum += score;
		num++;
	}
	std::cout << "平均成绩是：" << sum / num << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	while (std::cin >> score) {
		if (score < 0)
			break;
		sum += score;
		num++;
	}
	std::cout << "平均成绩是：" << sum / num << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	std::cin >> score;
	do {
		if (score < 0)
			break;
		sum += score;
		num++;
	} while (std::cin >> score);

	std::cout << "平均成绩是：" << sum / num << std::endl;

	return 0;
}
#endif 


#if 0
#include <iostream>
using namespace std;
int main() {
	auto score{ 0. }, sum{ 0. };
	auto num{ 0 };
	
	while (std::cin >> score) {
		if (score < 0)
			continue;
		sum += score;
		num++;
	}

	std::cout << "平均成绩是：" << sum / num << std::endl;

	return 0;
}
#endif 


#if 0
#include <iostream>
using namespace std;
int main() {
	auto s{ 0 };
	for (auto i{ 1 }; i <= 100; i++)
		s += i;
	std::cout << "1到100之间的整数之和是：" << s << std::endl;

	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main() {
	double score, sum{ 0 };
	auto num{ 0 };
	for (; std::cin >> score; ) {
		if (score < 0)
			break;  //跳出while循环
		sum += score;
		num++;
	}
	std::cout << "平均成绩是：" << sum / num << std::endl;
	return 0;
}
#endif 



#if 0
#include <iostream>
using namespace std;
int main() {
	double score, sum{ 0 };
	auto num{ 0 };
	for (; std::cin >> score && score >= 0; ) {
		sum += score;
		num++;
	}

	std::cout << "平均成绩是：" << sum / num << std::endl;
	return 0;
}
#endif 

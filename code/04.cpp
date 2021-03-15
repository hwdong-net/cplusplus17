/*
* ==============if条件语句===============
* 如果条件满足就执行相应的程序块
*/

#if 0
/*
    if(exp)
	   程序块
*/
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	if (score < 60)
		std::cout << "不及格！" << std::endl;	
	return 0;
}
#endif 



#if 0
/*
	if(exp)
	   程序块
	else
	   程序块2
*/

#include <iostream>
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

/*
	if(exp)
	   程序块
	else if(exp2)
	   程序块2
	else if(exp3)
	   程序块3
	   ...
	else
	   程序块_else
*/

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
//使用if嵌套语句，需要注意if - else的匹配是从内到外的
// 输入70，会怎么样？
//为了表示正确的程序设计意图，可以借助于{}来控制if和else的匹配。
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	if (score >= 60) 
		if (score >= 90)
			std::cout << "优秀！" << std::endl;	
	else
		std::cout << "不及格！" << std::endl;
	return 0;
}
#endif 


#if 0
//if或else块里有多条语句时，也要用花括号{}括起来
#if 1
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	if (score < 60)   //多个语句的程序块需要用{ }包围
		std::cout << "不及格！";
		std::cout <<"继续努力"<<std::endl;
	
	return 0;
}
#else
#include <iostream>
int main() {
	int a = -100;
	if (a < 0) 
		std::cout << "a的绝对值是";
		std::cout << -a;

	else 
		std::cout << "a的绝对值是";
		std::cout << a;
	
	return 0;
}
#endif
#endif 


/*
* ==============switch条件语句===============
* switch根据表达式的值跳转到相应的case去执行
* 格式：
*  switch(可无损转换为整型的表达式){
    case (整型或枚举型)常量表达式1:
        程序块1
    case (整型或枚举型)常量表达式2:
        程序块2
    //...
    default:
        默认程序块
* 
*/

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

/*
关于switch有几个语法点：
	case 的标签必须是整型常量表达式
	不同case的标签值不能相同
	case子句里定义变量，必须加花括号，否则假如执行其他case会出现“作用域里的该变量定义未初始化”
	default标签可以省略
	break关键字定义的break语句用于跳出整个switch语句。
*/

#if 0 
int main() {
	int x, y;
	switch (x) {
	case 3.14:                //错：case 标签必须是整型常量表达式 
		//... do something
		break;
	case y:                  　//错：case 标签必须是整型常量表达式
		//... do something
		break;
	}
}

#endif 

#if 0 
int main() {
	int x;
	//...
	//下面的有2个case的标签值都是1，不能相同！
	switch (x) {
	case 1:
		//...
		break;
	case 1:
		//...
		break;
	case 2:
		//...
		break;
}
#endif


#if 0 
int main() {
	switch (v) {
	case 1: int x = 0; // 初始化
		std::cout << x << '\n';
		break;
	default:             // 编译错误：因为default标签，可能导致 'x' 未初始化
		std::cout << "default\n";
		break;
	}
}
#endif

#if 0
#include <iostream>
int main() {
	unsigned v;
	std::cin >> v;
	switch (v) {
	case 1: 
		int x = 0;             //case中局部变量可能未初始化
		std::cout << x << '\n';
		break;			
	default: 
		std::cout << "default\n"; 
		break;
	}
	return 0;
}
#endif 


#if 0
/* C++17: if/switch语句中可以有初始化语句
if (初始化语句; 表达式)
switch (初始化语句; 表达式)
*/

#if 0
//有2个好处，一个是代码更加简洁，另外，var只属于if语句，从而不会污染周围环境。
int main(){
	auto var = doSomething();
	if (condition(var)) {
		//if块
	}		
	else {
		//else块
	}		
}
#else
int main() {
	if (auto var = doSomething; condition(var)) {

	}//if块		
	else {
	}//else块

}
#endif 

#if 1
#include <iostream>
#include <String>
using std::string;
int main() {
	const string s = "Hello,my youtube channel  is hwdong";
	const auto it = s.find("Hello");
	if (it != std::string::npos)
		std::cout << it << " Hello\n";

	const auto it2 = s.find("hwdong");
	if (it2 != std::string::npos)
		std::cout << it2 << " hw-dong\n";

}
#else
#include <iostream>
#include <String>
using std::string;
int main() {
	const string s = "Hello,my youtube channel  is hwdong";	
	if (const auto it = s.find("Hello"); it != std::string::npos)
		std::cout << it << " Hello\n";

	if (const auto it = s.find("hwdong"); it != std::string::npos)
		std::cout << it << " hw-dong\n";
}
#endif 

#endif 

 
/*
* =============whilie循环语句====================
* 条件满足就一直执行
* 
*/

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
//程序从键盘输入一组成绩，最后输出平均分
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
//break：跳出循环
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
//continue
// 用于直接中断循环体里的后续语句执行，回到循环开头重新执行循环。

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
/*--------do-while-------------
do
	程序块
while(表达式);

//注意：while（表达式）后面必须有分号；。
*/

#include <iostream>
using namespace std;
int main() {
	double score, average{ 0 };
	auto num{ 0 };
	std::cin >> score;          //注意：先输入得到一个分数
	do {
		if (score < 0)
			break;          //跳出while循环
		average += score;
		num++;
	} while (std::cin >> score);
	std::cout << "平均成绩是：" << average / num << std::endl;
}
#endif 



/*
* ============for循环语句======================
* for(初始化表达式; 条件表达式; 后处理表达式)
    程序块

*/
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
/* for语句和while语句是等价的：
初始化表达式;
while(表达式){
    程序块
    后处理表达式;
}
*/
//求平均分的程序可以写成等价的for语句形式：
#if 1
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
#else
#include <iostream>
using namespace std;
int main() {
	double score, sum{ 0 };
	auto num{ 0 };
	for (; std::cin >> score && score >= 0; ) {
		average += score;
		num++;
	}
	std::cout << "平均成绩是：" << sum / num << std::endl;
	return 0;
}
#endif
#endif 


#if 0 
//输出1到100之间所有被3整除的整数
#include <iostream>
using namespace std;
int main() {
	for (auto i{ 1 }; i <= 100; i++)
		if (i % 3 != 0)
			continue; //停止后续语句执行，回到循环的条件表达式"i<=100"
	std::cout << i << std::endl;
	return 0;
}
#endif




/*
*  ===========go 跳转语句============、

goto 标签名;
//...
标签名: 

或

标签名:
//...
goto 标签名;

*/

#if 0
#include <iostream>
using namespace std;
int main() {
	std::cout << "平均成绩是：" << average / num << std::endl;
	double score, average{ 0 };
	auto num{ 0 };
	for (; std::cin >> score; ) {
		if (score < 0)
			goto label;         //跳到标签label处执行 
		average += score;
		num++;
	}
label:
	std::cout << "平均成绩是：" << average / num << std::endl;
	return 0;
}
#endif 






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
#include <string>
int main() {
	int a;  std::string s;
#if 0
	std::cin >> a >> s;
	std::cout << a << '\t' << s;
#else
	std::cin >> std::noskipws >> a >> s;
	std::cout << a << '\t' << s;
#endif
	if (!std::cin)
		std::cout << "输入流处于错误状态!";
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main()
{
	char c;
	cout << "请输入:" << endl;
	while (cin.get(c))
		cout <<c;
	return 0;
}
#endif 

#if 0
#include <iostream>
#include <fstream>
int main() {
	std::ofstream outfile("test.txt");
	char ch;
	std::cout << "输入一些文本，直到遇到特殊字符#\n";
	do {
		ch = std::cin.get();
		outfile.put(ch);
	} while (ch != '#');

	return 0;
}

#endif 

#if 0
#include <iostream>
#include <sstream>
int main() {
	std::istringstream is("My name is hwdong");
	char str[10];
	while (is.get(str, 10, ' ')) {  //分隔符是空格字符
		is.get(); //跳过分隔符
		std::cout << str << '\n';
	}
}
#endif

#if 0
#include <iostream>     
#include <fstream>      
int main() {
	char str[256];
	std::cout << "输入存在的文件名: ";
	std::cin.get(str, 256);

	std::ifstream is(str); //创建输入文件流对象is
	char c;
	while (is.get(c))
		std::cout << c;

	is.close();  //关闭打开的文件
}

#endif

#if 0
#include <iostream>
#include <sstream>

int main() {
	std::istringstream is("hwdong|hw-dong|hw.dong");
	char str[10];

	while (is.getline(str, 8, '|'))
		std::cout << str << '\n';

}
#endif

#if 0
#include <iostream>     
#include <fstream>      
int main() {
	std::ifstream is("test.txt");
	char buf[1024];
	while (is.getline(buf, 1024))
		std::cout << buf << '\n';
}
#endif

#if 0
#include <iostream>     
#include <fstream>      
int main() {
	//binary表示以二进制方式打开文件
	std::ifstream is("test.txt", std::ifstream::binary);
	std::ofstream os("test2.txt", std::ofstream::binary);
	char buf[10];
	while (is.read(buf, 10)) {
		os.write(buf, is.gcount());
	}
	os.write(buf, is.gcount());
	os.close(); //关闭文件

	char buf2[4096];
	std::ifstream is2("test2.txt", std::ifstream::binary);
	is2.read(buf2, 4096);
	int num = is2.gcount();
	buf2[num] = '\0';
	std::cout << buf2;
}
#endif

#if 0
#include <iostream>     
#include <string>      
int main() {
	char c = std::cin.peek();
	if (c >= '0'&&c <= '9') {//如果cin中的第一个字符是数字，则读入一个整数
		int num; std::cin >> num;
		std::cout << "你输入了一个整数：" << num << std::endl;
	}
	else {   //否则，读入一行字符串
		std::string str;  getline(std::cin, str);
		std::cout << "你输入了一个字符串：" << str << std::endl;
	}
}
#endif 

#if 0
#include <iostream> 
int main() {
	std::cout << "hi" << std::endl; // 输出hi和换行符，然后刷新缓冲区
	std::cout << "hi" << std::flush; //输出hi，然后刷新缓冲区
	std::cout << "hi" << std::ends<<"world"; // 输出hi和空字符，然后刷新缓冲区

}
#endif 

#if 0
#include <iostream>
#include <fstream>
#include <iterator> 
#include <string>
int main() {
	std::ifstream iF("test.txt");
	std::istream_iterator<std::string> it(iF);  // 从iF读取数据
	std::istream_iterator<std::string> eof;    // 尾迭代器	
	while (it != eof)
		std::cout << *it++ << '\t';
}

#endif 


#if 0
#include <vector>
#include <algorithm>
#include <iostream>

struct Sum{
	Sum() : sum{ 0 } { }
	void operator()(int n) { sum += n; }
	int sum;
};

int main(){
	std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };

	auto print = [](const int& n) { std::cout << " " << n; };

	std::cout << "用print输出所有数:";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << '\n';

	// 对每个数执行lambda表达式，即每个数增加1
	std::for_each(nums.begin(), nums.end(), [](int &n) { n++; });

	// 对每个数执行函数调用Sum::operator()
	Sum s = std::for_each(nums.begin(), nums.end(), Sum());

	std::cout << "after: ";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << '\n';
	std::cout << "sum: " << s.sum << '\n';
}

#endif 

#if 0
// merge algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::merge, std::sort
#include <vector>       // std::vector

int main() {
	int first[] = { 5,10,15,20,25 };
	int second[] = { 50,40,30,20,10 };
	std::vector<int> v(10);

//	std::sort(first, first + 5);
//	std::sort(second, second + 5);
	std::merge(first, first + 5, second, second + 5, v.begin());

	std::cout << "The resulting vector contains:";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
#endif 

#if 0

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v{ 5, 23, 22, 9, 8 };

	std::cout << "initially, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::make_heap(v.begin(), v.end());  //调整序列[v.begin(): v.end())为一个堆
//	std::make_heap(v.begin(), v.end(), [](double a, double b) {return b<a; });
#if 0
	std::cout << "after make_heap, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	v.push_back(56);                    //将56追加到向量v后面

	std::cout << "before push_heap: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::push_heap(v.begin(), v.end()); //将最后一个元素即v.end()-1的元素插入到堆中

	std::cout << "after push_heap: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::pop_heap(v.begin(), v.end()); //将堆顶元素弹出，即第一个元素和最后一个元素交换
	auto largest = v.back();
	v.pop_back();                      //将v的最后一个元素删除
	std::cout << "largest element: " << largest << '\n';

	std::cout << "after removing the largest element, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';
#endif
	std::sort_heap(v.begin(), v.end());

	std::cout << "sorted:\t";
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

#endif 

#if 0
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>



int main()
{
	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto &i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5, 5, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto &i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}

#endif 

#if 0
//输入CTRL+Z结束

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
	vector<int> vec;
	istream_iterator<int> is(cin);//绑定标准输入装置
	istream_iterator<int> eof;//定义输入结束位置
	copy(is, eof, back_inserter(vec));
	sort(vec.begin(), vec.end());

	ostream_iterator<int> os(cout, ", ");//绑定标准输出装置
	copy(vec.begin(), vec.end(), os);
}
#endif

#if 0


/************************************************************************/
//功能：从标志输入读取所有的输入文字，排序，将不重复的文件打印到屏幕                                                             
/************************************************************************/
#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main(){
	vector<string> strVector;
	//istream_iterator 是输入流迭代器
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(strVector));
	sort(strVector.begin(), strVector.end());

	//类unique算法，消除毗邻的相同元素值，ostream_iterator 输出流迭代器
	unique_copy(strVector.begin(), strVector.end(), ostream_iterator<string>(cout, "\n"));
}


#endif

#if 0
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

template<typename C>
void print(const C& c) {
	for (auto e : c) 	std::cout << e << " ";
	std::cout << '\n';
}
int main() {
	std::array<int, 5> s = { 5, -7, 4, -2, 8 };
	//逆序排序
	std::reverse(s.begin(), s.end()); //将s逆置为：8, -2, 4, -7, 5
	print(s);
	// 使用默认的运算符operator<
	std::sort(s.begin(), s.end());  //默认元素的大小排序
	print(s);
	// 使用标准库的比较函数对象
	std::sort(s.begin(), s.end(), std::greater<int>());  //用策略std::greater排序
	print(s);
	// 使用定制的函数对象
	struct {
		bool operator()(int a, int b) const
		{
			return a < b;
		}
	} customLess;
	std::sort(s.begin(), s.end(), customLess);  //用策略customLess排序
	print(s);
	// 用lambda表达式比较
	std::sort(s.begin(), s.end(), [](int a, int b) {return a > b;	}); //用Lambda策略排序
	print(s);
}

#endif 
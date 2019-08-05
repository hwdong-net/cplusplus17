#if 0
#include <iostream>
#include <sstream>
int main() {
	std::cout << " 0.01的定点格式(fixed): " << std::fixed << 0.01 << '\n'
		<< "0.01的科学计数法(scientific): " << std::scientific << 0.01 << '\n'
		<< "0.01的十六进制(hexfloat): " << std::hexfloat << 0.01 << '\n'
		<< "0.01的默认格式(default): " << std::defaultfloat << 0.01 << '\n';
	double f;
	std::istringstream("0x1P-1022") >> std::hexfloat >> f;
	std::cout << "将0x1P-1022解析为十六进制的结果是： " << f << '\n';
}
#endif

#if 0
#include <iostream>
#include <iomanip>
int main() {
	std::cout << "Left fill:\n" << std::left << std::setfill('*')
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << std::hex << std::showbase << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";
	std::cout << std::setfill('#');
	std::cout << "Internal fill:\n" << std::internal
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";

	std::cout << "Right fill:\n" << std::right
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << '\n';
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
#include <string>      
int main() {
	char c= std::cin.peek();
	if (c >= '0'&&c <= '9') {
		int num;std::cin >> num;
		std::cout << "你输入了一个整数：" << num << std::endl;
	}
	else {
		std::string str;  getline(std::cin, str);
		std::cout << "你输入了一个字符串：" << str << std::endl;
	}
}
#endif
#if 0
#include <iostream>     
#include <string>      
int main() {
	char c = std::cin.get(); 
	std::cin.putback(c); //将字符c再放回去
	if (c >= '0'&&c <= '9') {
		int num; std::cin >> num;
		std::cout << "你输入了一个整数：" << num << std::endl;
	}
	else {
		std::string str;  getline(std::cin, str);
		std::cout << "你输入了一个字符串：" << str << std::endl;
	}
}
#endif

#include <iostream>
#include <vector>
void print(const std::vector<int> &vec) {
	for (auto e : vec)
		std::cout << e << '\t';
	std::cout << std::endl;
}

#if 0
int main() {
	std::vector<int> vec{ 1,2,3,4 };
	int *p = vec.data(); // data()返回存储实际数据元素的内存块的地址(指针)
	while (p != vec.data() + vec.size()) {  //通过指针遍历
		*p *= 2;
		p++;
	}
	print(vec);                       //输出结果：2       4       6       8
	vec.clear();           //清空
	vec.reserve(5);       //容量变为5；
	std::cout << "大小：" << vec.size() << '\t'
		<< "容量：" << vec.capacity() << '\n'; //输出： 大小：0 容量：5
}
#endif



#if 0

#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream
#include <string>       // std::string
int   main() {
	// 构造字符串输出流对象
	std::ostringstream sout;

	// 写数据到字符串输出流对象
	sout << "zhang" << "," << 80.5;
	//获取内容
	std::cout << sout.str() << std::endl;
	//设置内容
	sout.str("hello world");
	//获取内容
	std::cout << sout.str() << std::endl;
}


#endif 


#include <iostream>
#include <vector>  //包含vector类模板的头文件

#if 0
int main() {
	std::vector<int> vec; //空的vector对象
	std::vector<int> vec2(3); //10个元素，每个元素的初始值为0
	std::vector<int> vec3{ 3 }; //初始化列表，只有一个元素10
	std::vector<int> vec4{ 1,3,5,7,9 }; //初始化列表，包含5个元素
	std::vector<int> vec5(vec4); //拷贝构造函数

	vec = vec5; //赋值运算符	

	vec.pop_back();  //删除最后的元素，即9
	vec.push_back(2);   //push_back将2加到最后面
	vec.push_back(4);
	vec[0] = 100;  //通过下标运算符访问某个元素
	vec.at(1) = 200;  //类似于下标运算符[]，at()方法通过下标访问某个元素
					  //at()会检查下标是否超出范围，而[]不检查
	for (auto i{ 0 }; i < vec.size(); i++)  //size()函数返回vec的大小（元素个数）
		std::cout << vec[i] << '\t';
	std::cout << std::endl;
}
#endif

#if 0
void print(const std::vector<int> &vec) {
	for (auto e : vec)
		std::cout << e << '\t';
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec(3);
	for (auto& e : vec)	  //e是引用vec的元素，才能修改它	
		e = 1;
	vec.push_back(10);
	print(vec);
}
#endif 



#if 0
int main() {
	std::vector<int> vec{ 1,2,3,4,5,6 };
	std::cout << *(vec.begin()) << '\t'; //vec.begin()返回指向vec开头的迭代器
									  //迭代器类似于指针，可以用*得到它指向的元素
									  //输出结果：1
	
	std::cout << *(vec.begin()+2) << '\t'; //对迭代器加上一个整数，使得迭代器偏移
	std::cout << *(vec.end() - 2) << '\t';
	auto p = vec.begin();
	p++;                    //迭代器可以自增或自减
	std::cout << *p << '\n';
	print(vec);
	vec.insert(vec.begin() + 1,100); //在迭代器指示位置插入一个新元素100
	vec.erase(vec.end() - 1);
	print(vec);	
}

#endif

#if 0
int main() {
	std::vector<int> vec;
	vec.emplace_back(1);
	vec.emplace(vec.begin() + 1, 2);
	print(vec);
}
#endif

#if 0
int main() {
	std::vector<int> vec{1,2,3,4};
	int *p = vec.data(); // data()返回存储实际数据元素的内存块的地址(指针)
	while (p != vec.data() + vec.size()) {  //通过指针遍历
		*p *= 2;
		p++;
	}
	print(vec);                       //输出结果：2       4       6       8
	
	vec.clear();           //清空
	vec.reserve(5);       //容量变为5；
	std::cout << "大小：" << vec.size() << '\t'
		<< "容量：" << vec.capacity() << '\n'; //输出： 大小：0 容量：5


	print(vec);                      //输出结果：10      14      18

} 

#endif

#if 0
#include <array>
int main() {
	std::array<int, 5> arr;
	std::array<int, 4> arr2{1,3,7};
	arr[4] = 3;
	arr2.at(3) = 13;
	for(auto e:arr)
		std::cout << e << '\t';
	std::cout << std::endl;
	std::cout << arr2.back() << std::endl;

//	arr = arr2; //arr和arr2属于完全不同类型：std::array<int, 5>和std::array<int, 4> 
	            //不能相互赋值！
}
#endif 

#if 0
#include <deque>  //双向队列(double-ended queue)
int main() {
	std::deque<int> deq{ 1,3 };
	deq.push_back(5);
	deq.push_front(-3);
	deq.push_front(-5);
	deq[1] = 10;
	deq[4] = 40;
	for (auto e : deq)
		std::cout << e << '\t';
	std::cout << std::endl;

	deq.pop_front();
	for (auto e : deq)
		std::cout << e << '\t';
	std::cout << std::endl;
}
#endif


#if 0

/* list因为是链表，数据元素是单独存放的，所有数据元素不是存储在一块连续存储空间
   因此，不同于数组，不能用下标运算符[]去访问其中的元素，只能用迭代器去访问它的元素
*/

#include <list>  //单向链表list类模板的的头文件

int main() {
	std::list<int> l; //空的list
	std::list<int> l2{2,3,5}; //列表初始化
	std::list<int> l3(1);
//	l3[1] = 3;     //错：不能用下标运算符

	l = l3;
	l.push_front(-3);
	l.push_back(3);
	l.insert(l.begin(), -5);  	//begin()和end()返回第一个元素和最后元素的后一个位置的迭代器
	                         //迭代器类似于指针，可以用*得到它指向的元素
	for (auto it = l.begin(); it != l.end(); it++)
		std::cout << *it << '\t';
	std::cout << std::endl;

	
	
	for (auto it = l.begin(); it != l.end(); it++)
		*it *= 3;
	for (auto it = l.begin(); it != l.end(); it++)
		std::cout << *it << '\t';
	std::cout << std::endl;

	auto it = l.end();
	it--; it--;
	l.insert(it, 100);
	l.pop_back();
	for (auto it = l.begin(); it != l.end(); it++)
		std::cout << *it << '\t';
	std::cout << std::endl;
	return 0;	
}

#endif

#if 0
#include <iostream>
#include <stack>
#include <queue>
int main()
{
	std::stack<int> stack;
	for (int i{}; i < 10; ++i)
		stack.push(i);
	std::cout << "不断从栈顶pop()出栈元素，直到栈为空\n";
	while (!stack.empty())
	{
		std::cout << stack.top() << ' '; //top()获取栈顶元素
		stack.pop(); // pop()方法不返回任何值!
	}
	std::cout << std::endl;
	std::queue<int> queue;
	for (int i{}; i < 10; ++i)
		queue.push(i);
	std::cout << "不断从队头pop()出队元素，直到队列为空\n ";
	while (!queue.empty())
	{
		std::cout << queue.front() << ' '; //front()获取队头元素
		queue.pop(); // pop() 方法不返回任何值!
	}
	std::cout << std::endl;
}

#endif 

#include <iostream>
#include <set>

void print(const std::set<int>& S) {
	for (int e : S)
		std::cout << e << '\t';
	std::cout << std::endl;
}
#if 0
int main() {
	std::set<int> s;
	s.insert(1);//插入
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	s.erase(2); //删除
	print(s);
	s.clear();
	s.insert(2);
	print(s);

	if (s.find(2) != s.end())
		std::cout << "2 在集合s中\n";
	std::cout << s.count(2) << '\t' << s.count(1) << '\n';
}
#endif 

#if 0
int main() {
	std::set<int> s;
	s.insert(3);//插入
	s.insert(1);
	s.insert(2);
	print(s);
	std::set<int> s2;
	s2.insert(2);//插入
	s2.insert(3);
	s2.insert(1);
	print(s2);
}
#endif 
#if 0
int main() {
	std::set<int> s;
	s.insert(3);//插入
	s.insert(1);
	s.insert(2);
	print(s);
	std::set<int,std::greater<>> s2;
	s2.insert(2);//插入
	s2.insert(3);
	s2.insert(1);
	for (int e : s2)
		std::cout << e << '\t';
	std::cout << std::endl;
}
#endif 

#if 0
#include <map>
#include <iostream>
#include <string>
int main()
{
	std::map<std::string, unsigned long long> phone_book;
	phone_book["Li Ping"] = 13101966886;
	phone_book["Zhang Wei"] = 15301966686;
	phone_book["Wang qiang"] = 13101966886;
	phone_book["Pan Xiao"] = 12401966888;
	std::cout << "Li Ping的电话号码是：" << phone_book["Li Ping"] << std::endl;
	for (const auto&[name, phone] : phone_book)
		std::cout << name << " 的号码： " << phone << std::endl;

	if (phone_book.find("Zhang Wei") != phone_book.end())
		std::cout << "Zhang Wei的号码是："<<phone_book ["Zhang Wei"]<<'\n';
	std::cout<< phone_book.count("Zhang Wei")<<'\t'<< phone_book.count("ZhangWei")<< '\n';
}

#endif 

#if 0

#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec{ 1,2,3,4,5 };
	std::vector<int>::iterator it;
	std::vector<int>::const_iterator cit;
	for (it = vec.begin(); it != vec.end(); it++)
		*it *= 2; //可以通过*it修改它指向的元素的值

	for (cit = vec.cbegin(); cit != vec.cend(); cit++)
		std::cout << *cit << '\t'; //只能查询不能修改cit指向的元素
	std::cout << '\n';

	std::vector<int>::const_reverse_iterator crit; //const_reverse_iterator逆向迭代器
	for (crit = vec.crbegin(); crit != vec.crend(); crit++) //crbegin()指向最后一个元素
		std::cout << *crit << '\t';
	std::cout << '\n';

}

#endif
#if 0
#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec{ 1,2,3 };
	for (auto it = vec.begin(); it != vec.end(); it++)
		*it *= 2;
	for (auto cit = vec.cbegin(); cit != vec.cend(); cit++)
		std::cout << *cit << '\t';
	std::cout << std::endl; //输出：2       4       6
}
#endif 
#if 0
#include <iostream>
#include <vector>
#include <string>
using std::string;
int main() {
	std::vector<string> vec{ "hello","world","c++","python" };
	std::vector<string>::iterator it = vec.begin() + 2;
	std::cout << it->size() << '\n';  //输出：3
}
#endif 

#if 0 
#include <iostream>
#include <vector>
int main() {
	std::vector<int> v{ 1,2,3 };
	std::vector<int> vec{ 4,5,6 };
	int arr[]{ 7,8};
	v.insert(v.end(), vec.begin(), vec.end());
	v.insert(v.end(), arr, arr+std::size(arr)); //范围可以是一个指针指向的范围
	                   //std::size()可以查询一个内在数组的大小
	print(v);  //输出：1       2       3       4       5       6       7       8	
	v.erase(v.begin() + 1, v.end() - 2);
	print(v);  //输出: 1       7       8
}
#endif

#if 0
#include <iostream>
int main() {
	int arr[]{ 1,2,3,4};
	for (auto it = std::begin(arr); it != std::end(arr); it++)
		std::cout << *it << '\t';
}
#endif 

#if 0
#include <fstream>
int main() {
	std::ofstream outFile("test.txt");
	outFile<<3.14<<"\t"<<"hello"<<"\n";
}

#if 0
1) 创建输入输出流对象
2）连接输入输出设备
3）执行输出输出（包括高层的格式化输出输出或底层的非格式化输出输出）
4）断开输入输出设备
5）释放输入输出流对象
#endif

#if 0
template <class charT, class traits = char_traits<charT> >
class basic_istream;

template <class charT, class traits = char_traits<charT> >
class basic_ostream;

typedef basic_ios<char>           ios;
typedef basic_ios<wchar_t>        wios;
typedef basic_istream<char>       istream;
typedef basic_istream<wchar_t>    wistream;
typedef basic_ostream<char>       ostream;
typedef basic_ostream<wchar_t>    wostream;
typedef basic_iostream<char>      iostream;
typedef basic_iostream<wchar_t>   wiostream;
typedef basic_streambuf<char>     streambuf;
typedef basic_streambuf<wchar_t>  wstreambuf;
#endif
#endif 

#if 0
#include <iostream>
#include <sstream>

int main(){
	std::cout << "数值 0.01的定点格式(fixed): " << std::fixed << 0.01 << '\n'
		<< "数值 0.01的科学计数法(scientific): " << std::scientific << 0.01 << '\n'
		<< "数值 0.01的十六进制(hexfloat): " << std::hexfloat << 0.01 << '\n'
		<< "数值 0.01的默认格式(default): " << std::defaultfloat << 0.01 << '\n';
	double f;
	std::istringstream("0x1P-1022") >> std::hexfloat >> f;
	std::cout << "将0x1P-1022解析为十六进制的结果是： " << f << '\n';
}
#endif 

#if 0


#include <iostream>
#include <iomanip>
int main(){	
	std::cout << "Left fill:\n" << std::left << std::setfill('*')
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << std::hex << std::showbase << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";
	std::cout << std::setfill('#');
	std::cout << "Internal fill:\n" << std::internal
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << "\n\n";
	
	std::cout << "Right fill:\n" << std::right
		<< std::setw(12) << -1.23 << '\n'
		<< std::setw(12) << 42 << '\n'
		<< std::setw(12) << std::put_money(123, true) << '\n';
}
#endif 

#if 0
basic_ostream& put(char_type c);

ostream& operator<< (float val)
ostream& operator<< (streambuf* sb);
ostream& operator<< (ios_base& (*pf)(ios_base&));

ostream& put(char c);


int get();
istream& get(char& c);
int get(); istream&
c - string(2)
istream& get(char* s, streamsize n);
istream& get(char* s, streamsize n, char delim);
stream buffer(3)
istream& get(streambuf& sb);
istream& get(streambuf& sb, char delim);

istream& getline(char* s, streamsize n);
istream& getline(char* s, streamsize n, char delim);
#endif 

#if 0
#include <iostream>
#include <fstream>

int main() {
	std::ofstream outfile("test.txt");
	char ch;
	std::cout << "输入一些文本，直到遇到某个特殊字符如#:\n";
	do {
		ch = std::cin.get();
		outfile.put(ch);
	} while (ch != '#');

	return 0;
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
/*
问题：分隔符仍然留在输入流中。
解决方法：用get()跳过这个分隔符即可
*/
#include <iostream>     
#include <fstream>
int main() {
	char str[256],str2[256];
	std::cout << "输入包含2个#的字符串: ";
	std::cin.get(str, 256,'#');
	std::cin.get();
	std::cin.get(str2, 256, '#');
	std::cout<<str<<'\n';
	std::cout << str2 << '\n';	
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
// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

int main() {
	std::ifstream is("test.txt", std::ifstream::binary);
	if (!is) return -1;

	// 确定文件的长度
	is.seekg(0, is.end);     //定位到文件尾
	int length = is.tellg(); //查询长度
	is.seekg(0, is.beg);     //重新定位到文件开头

	// 分配内存
	char * buffer = new char[length];

	// 读取数据块:
	is.read(buffer, length);

	is.close();

	// 用write输出到cout
	std::cout.write(buffer, length);
	delete[] buffer;

}
#endif 

#if 0
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

int main() {
	std::ifstream is("tesy.txt");
	std::cout << is.failbit << "\t" << is.goodbit << "\n";
	std::cout <<std::boolalpha<< is.fail() << "\t" << is.good()<< "\n";

	std::cout << std::cout.failbit << "\t" << std::cout.goodbit << "\n";
	std::cout << std::boolalpha << std::cout.fail() << "\t" << std::cout.good() << "\n";	
	std::cout << is.rdstate()<<"\t"	 << std::cout.rdstate()<<'\n';

#if 0
	std::string word;
	while(std::cin>>word)
		//...
#endif


	std::cout << "hi" << std::endl; // 输出hi和换行符，然后刷新缓冲区
	std::cout << "hi" << std::flush; //输出hi，然后刷新缓冲区
	std::cout << "hi" << std::ends; // 输出hi和空字符，然后刷新缓冲区
}
#endif 

#if 0
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
int main() {
	std::ofstream os;
	os.open("test3.txt");
	os << "hello world! in test3\n";
	os.close();
	os.open("test4.txt"); //再打开另外一个文件
	os << "hello world! in test4\n";
}
#endif 

#if 0
#include <fstream>
//.......
std::ifstream iF;
iF.open(filename, mode); //以mode模式打开文件
//......
iF.close();

// OR combine declaration and open()
std::ifstream iF(filename, mode);//以mode模式打开文件
#endif 

#if 0
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
int main() {
	std::ifstream iF;
	iF.open("test3.txt", std::ofstream::in); //或std::ios_base::in
	std::string str;
	while (iF >> str)std::cout << str ;

	std::cout << std::endl;
	std::ifstream iF2("test4.txt", std::ios_base::binary); //再打开另外一个文件
	char buf[10];
	while (iF2.read(buf, 10)) {
		std::cout.write(buf, iF2.gcount());
	}
	std::cout.write(buf, iF2.gcount());
}
#endif 

#if 0
typedef basic_istringstream<char> istringstream;
typedef basic_ostringstream<char> ostringstream;
typedef basic_stringstream<char> stringstream;

explicit istringstream(ios::openmode mode = ios::in);  // 默认空的string
explicit istringstream(const string & buf,
	ios::openmode mode = ios::in);  // 有一个初始化的string
#endif 

#if 0
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
int main() {
	std::string stringvalues = "123 3.14 hello";
	std::istringstream iss(stringvalues);
	int i; double f; std::string s;
	iss >> i >> f >> s;
    std::cout << i << '\t' << f << '\t' << s << '\n';
}
#endif 
#if 0
explicit ostringstream(ios::openmode mode = ios::out);  // 默认空的string
explicit ostringstream(const string & buf,
	ios::openmode mode = ios::out);  // 有一个初始化的string

string str() const;           // 得到流对象存储的string值
void str(const string & str); // 设置流对象的string值
#endif 
#if 0
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
int   main() {
	// 构造字符串输出流对象
	std::ostringstream sout;

	// 写数据到字符串输出流对象
	sout << "zhang" << std::endl;
	sout << "wang" << std::endl;
	sout << "li" << std::endl;

	//获取内容
	std::cout << sout.str() << std::endl;
	//设置内容
	sout.str("hello world") ;
	//获取内容
	std::cout << sout.str() << std::endl;
}
#endif 

#if 0 
#include <string>
#include <iostream>
int main() {
	std::string::iterator it;
	std::string str = "hello world";
	for (it = str.begin(); it < str.end(); it++)
		std::cout << *it;
	std::cout << std::endl;
}
#endif 

#if 0 

// 在迭代器pos位置前插入一个值val
iterator insert(iterator pos, const value_type & val);  

// 在迭代器pos位置前插入n个值val
void     insert(iterator pos, size_type n, const value_type & val);  


// 在迭代器pos位置前插入[first, last)范围里的值
template <class InputIterator>
void     insert(iterator pos, InputIterator first, InputIterator last)

// 删除迭代器pos位置的元素
iterator erase(iterator pos);  

// 删除迭代器[first, last)范围里的元素
iterator erase(iterator first, iterator last);  

//填充：将旧内容删除，赋值为n个val值
void assign(size_type n, const value_type & val);  

//用范围 [first, last)里的值赋值
template <class InputIterator>
void assign(InputIterator first, InputIterator last);  

//用初始化列表中的元素赋值
void assign(initializer_list<value_type> il);
#endif 

#if 0
#include <iostream>
#include <vector>
int main(){
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign(7, 100);             // 用7个100赋值

	std::vector<int>::iterator it;
	it = first.begin() + 1;

	// 用[it, first.end() - 1）里即first的5个中间元素赋值
	second.assign(it, first.end() - 1); 

	int myints[] = { 1776,7,4 };
	third.assign(myints, myints + 3);   // 用数组范围[myints, myints + 3）里的元素赋值

	std::cout << "first的大小: " << int(first.size()) << '\n';
	std::cout << "second的大小: " << int(second.size()) << '\n';
	std::cout << "third的大小: " << int(third.size()) << '\n';
	return 0;
}
#endif

#if 0
template < class charT,
	class traits = char_traits<charT>,    // basic_string::traits_type
	class Alloc = allocator<charT> >     // basic_string::allocator_type
	class basic_string;

typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;
typedef basic_string<char16_t> u16string;  // C++11
typedef basic_string<char32_t> u32string;  // C++11

using std::string = std::basic_string<char>;
using std::wstring = std::basic_string<wchar_t>;
using std::u16string = std::basic_string<char16_t>; //c++11
using std::u32string = std::basic_string<char32_t>; //c++11

using std::string_view = std::basic_string_view<char>;
using std::wstring_view = std::basic_string_view<wchar_t>;
using std::u16string_view = std::basic_string_view<char16_t>;
using std::u32string_view = std::basic_string_view<char32_t>;
#endif

#if 0
#include <string>
#include <iostream>
#include <string_view>

// 需要重载new运算符来看看到底有没有分配内存
void* operator new(std::size_t n){
	std::cout << "new " << n << " bytes\n";
	return malloc(n);
}

int main(){
	// 原始的字符串，分配一次内存
	std::string str{ "This is a cat" };

	// 求子串时，又会分配内存，并执行拷贝操作
	auto subStr = str.substr(str.find("cat"));
	std::cout << subStr << "\n";

	// 求子串，没有内存分配
	std::string_view strView{ str };
	auto subView = strView.substr(str.find("cat"));
	std::cout << subView << "\n";
}
#endif

#if 0
#include <iostream>
#include <string>   // C++ string class
using namespace std;
int main() {
	string s1, s2("hello"), s3 = "world";
	string s4(s3);    //拷贝构造函数
	string s5 = {'c','+','+'},s6{"python"}; //初始化列表	 
	string s7(8, 'a'); //8个字符'a'构成的字符串
}
#endif 

#if 0
//作为成员函数重载运算符
//第一个操作数必须是string类对象
=      // 赋值
[]     // 下标访问（不检查下标是否合法）
+=     // 在原字符串后面加上另一个字符串

//非成员函数的友元 
//第一个操作数不必是string类对象
+                      // 拼接2个字符串（其中一个可以是C风格串或文字量）
                       // 返回拼接后的新的string对象
==, !=, <, <=, >, >=   // 关系（比较）运算符
                       // 其中一个操作数可以C风格串或文字量                     
>>                     // 流输入运算符
<<                     // 流输出运算符 

#endif 

#if 0
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t

int main(){
	std::string str("it is a cat,that is a dog ");
	std::size_t found = str.find_first_of("is");
	while (found != std::string::npos)	{
		str[found] = '*';
		found = str.find_first_of("is", found + 1);
	}
	std::cout << str << '\n';
}
#endif

#if 0
#include <iostream>
#include <string>
#include <cctype>
int main(){
	std::string str("hello  world");
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) 
		*it = toupper(*it);

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		std::cout << *it;
	std::cout << '\n';
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>

int main(){
	std::string name;

	std::cout << "请输入你的名字: ";
	std::getline(std::cin, name);
	std::cout << "Hello, " << name << "!\n";
	return 0;
}
#endif
#if 0
#include <iostream>     // std::cout
#include <algorithm>    // std::copy
#include <list>       // std::list
int main() {
	int arr[] = { 1,2,3 };
	std::list<int> l{ -1,-2,-3,-4 };
	std::copy(arr, arr + 3, l.begin());
	std::cout << "l contains:";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}
#if 0
int arr[] = { 1,2,3,4,5 };
std::list<int> l{ -1,-2,-3,-4 };
std::copy(arr, arr + 5, l.begin());

template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
#endif


#endif

#if 0
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
int main() {
	std::vector<int> v{ 1,2,3,4,5 };
	std::list<int> l{ -1,-2,-3 };
	std::copy(v.begin(), v.end(),
		std::insert_iterator<std::list<int>>(l, l.begin()));
	for (int n : l)
		std::cout << n << ' ';
	std::cout << '\n';
}
#endif

#if 0
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main(){
	std::vector<int> v{ 1,2,3,4,5 };
	std::list<int> l{ -1,-2,-3 };
//	std::copy(v.begin(), v.end(),
//		std::insert_iterator<std::list<int>>(l,l.begin()));

	std::copy(v.begin(), v.end(), std::inserter(l, l.begin()));
//	std::copy(v.begin(), v.end(), 
//		std::insert_iterator<std::list<int>>(l, std::next(l.begin())));
	//可以用std::inserter简化插入迭代器的使用。
	for (int n : l)
		std::cout << n << ' ';
	std::cout << '\n';
}

#endif

#if 0
std::inserter(c, p)           //c是容器对象，p是指向c的迭代器
std::front_inser t_iterator(c) //c是容器对象，
std::back_inser t_iterator（c） //c是容器对象，

#endif

#if 0
#include <iostream>
#include <iterator>

int main() {
	std::istream_iterator<int> it(std::cin); // 从cin读取数据
	std::istream_iterator<int> eof; // 尾迭代器	
		while (it != eof)
			std::cout<<*it++;
}
#endif

#if 0
#include <string>
#include <fstream>
#include <iterator>
int main() {
	std::ifstream iF("test.txt");
	std::istream_iterator<std::string> it(iF); // 从iF读取数据
	std::istream_iterator<std::string> eof; // 尾迭代器	
	while (it != eof)
		std::cout << *it++<<'\t';
}
#endif
#if 0
#include <iostream>
#include <iterator>

int main() {
	int arr[] = { 1,3,5 };
	std::ostream_iterator<int> out_iter(std::cout, "-*");
	for (auto e : arr)
		*out_iter++ = e; // 给输出流迭代器赋值就是将
	                  //该元素输出到其关键的输出流对象中
	
}

#endif

#if 0

/*
bool Vector::add_capacity() {
	ElemType *temp = new ElemType[2 * capacity];//分配更大空间
	if (!temp) return false;
	for (auto i = 0; i < n; i++) {     //将原空间data数据拷贝到新空间temp
		temp[i] = data[i];
	}
	delete[] data;                //双方原来空间内存
	data = temp;     //data指向新的空间temp
	capacity *= 2;      //修改容量
	return true;


}
*/
#include <memory>
#include <iostream>
class X {
	int a{ 0 };
public:
	X() = default;
	int get() { return a; }
	void set(const int a) { this->a = a; }
	X(const X& x) :a{ x.a } { 
		std::cout << "拷贝数据:" << a << "\n"; }
	X(const X&& x) :a{ x.a } {
		std::cout << "移动数据:" << a << "\n";
	}
};
int main(){
	int n{5};
	X *arr = new X[n];
	for (auto i{ 0 }; i != n; i++)
		arr[i].set(2 * i + 1);

	auto n2{ 10 };
	X *tmp = new X[n2];
	//auto last = std::uninitialized_copy(arr, arr+n, tmp);
	auto last = std::uninitialized_copy(std::make_move_iterator(arr), 
		std::make_move_iterator(arr + n), tmp);
	delete[] arr; 
	arr = tmp; 
	for (auto i{ 0 }; i != n; i++)
		std::cout << arr[i].get()<<" ";
}


#endif 

#if 0
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

void Print(const vector<int>& v) {
	for (auto e:v)		cout << e << '\t';
	cout << endl;
}
int main() {
	vector<int> v{1,2,3};
	insert_iterator<vector<int>> p{ v,v.begin() + 1 }; 
	back_insert_iterator<vector<int>> bp{v}; 
	

	*p++ = 20; //*p=20然后p++
	*p = 10;
	Print(v);
	*bp = 30;   Print(v);
	
	//错：vector没有push_front()
	//front_insert_iterator<vector<int>> fp{ v };
	//*fp = 40;   Print(v);
}
#endif

#if 0
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
void square_all(vector<int>& v) { // 对v的每个元素执行平方运算
	for_each(v.begin(), v.end(), [](int& x) {x *= x; });
}

template< class InputIt, class UnaryPredicate >
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
	return std::find_if_not(first, last, p) == last;
}
template< class InputIt, class UnaryPredicate >
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
	return std::find_if(first, last, p) != last;
}
template< class InputIt, class UnaryPredicate >
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
	return std::find_if(first, last, p) == last;
}


#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

int main(){
	std::vector<int> v(10, 2);
	std::partial_sum(v.cbegin(), v.cend(), v.begin());
	std::cout << "Among the numbers: ";
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; })) {
		std::cout << "All numbers are even\n";
	}
	if (std::none_of(v.cbegin(), v.cend(), std::bind(std::modulus<int>(),
		std::placeholders::_1, 2))) {
		std::cout << "None of them are odd\n";
	}
	struct DivisibleBy
	{
		const int d;
		DivisibleBy(int n) : d(n) {}
		bool operator()(int n) const { return n % d == 0; }
	};

	if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7))) {
		std::cout << "At least one number is divisible by 7\n";
	}
}


int main_() {
	vector<int> vec{ 1,2,3 };
	square_all(vec);
	for (auto e : vec)
		std::cout <<e<< '\t';

	vector<int> div{ 4，5 };
	scale(vec,div);
}
#endif

#if 0
#include <algorithm>
#include <iostream>
#include <vector>

int main(){
	std::vector<int> v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };

	std::cout<< std::count(v.begin(), v.end(), 3)<< '\t';
	std::cout << std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
}
#endif

#if 0

#include<string>
#include <array>
void f(const std::string& s){
	auto p_space = find(s.begin(), s.end(), ' ');
	auto p_whitespace = find_if(s.begin(), s.end(), isspace);
	// ...
}

int main(){
	std::vector<int> v{ 1,3,7,4 };
	std::vector<int> t{ 0,2,3,4,5 };

	auto p = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());
	std::cout <<"第一个位于" << std::distance(v.begin(), p) <<"的元素"
		<<*p<< "在t中找到了匹配元素\n";
	auto q = std::find_first_of(p + 1, v.end(), t.begin(), t.end());
	std::cout << "第一个位于" << std::distance(v.begin(), q) << "的元素" 
		<< *q << "在t中找到了匹配元素\n";
}


#endif
#if 0
#include <string>
#include <iostream>>
std::tuple<std::string,double, char> get_student() {
	std::string name; double score; char level;
	std::cin >> name >> score >> level;
	return std::make_tuple(name,score, level);
}

int main() {
	std::string name; double score; char level;
	std::tie(name, score, level) = get_student();	
	std::cout << name << '\t'<<score << '\t' << level << '\n';
	auto s = get_student();
	std::cout << std::get<0>(s) << '\t' << std::get<1>(s) 
		<< '\t' << std::get<2>(s) << '\n';
}
#endif

#if 0
#include <string>
#include <iostream>>
int main() {
	std::pair<std::string, double> name_score("张伟",89.5);
	name_score.second = 90.5;	
	std::cout << name_score.first << '\t' << name_score.second << '\n';
	auto p = std::make_pair("赵四", 70.5);
	std::cout << p.first << '\t' << p.second << '\n';
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>

std::string mirror_ends(const std::string& in){
	return std::string(in.begin(),
		std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main(){
	std::cout << mirror_ends("abXYZba") << '\n'
		<< mirror_ends("abca") << '\n'
		<< mirror_ends("aba") << '\n';
}
#endif 



#if 0
#include <iostream>
#include <algorithm>
#include <iterator>
template <class Container, class Size, class T>
bool consecutive_values(const Container& c, Size count, const T& v){
	return std::search_n(std::begin(c), std::end(c), count, v) != std::end(c);
}
int main(){
	const char sequence[] = "1001010100010101001010101";
	std::cout << std::boolalpha;
	std::cout << "有4个连续的0: "
		<< consecutive_values(sequence, 4, '0') << '\n';
	std::cout << "有3个连续的0: "
		<< consecutive_values(sequence, 3, '0') << '\n';
}
#endif 


#if 0
template<class In, class Out, class Op>
Out transform(In first, In last, Out res, Op op){
	while (first != last)
		∗res++ = op(∗first++);
	return res;
}
void toupper(string& s) //
{
	transform(s.begin(), s.end(), s.begin(), toupper);
}

void f(list<int>&ld, int n, ostream& os)
{
	copy_if(ld.begin(), ld.end(),
		ostream_iterator<int>(os),
		[](int x) { return x > n); });
}

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

int main() {
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = std::accumulate(v.begin(), v.end(), 0);
	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

	std::string s = std::accumulate(std::next(v.begin()), v.end(),
		std::to_string(v[0]), // start with first element
		[](std::string a, int b) {
		return a + '-' + std::to_string(b);
	});

	std::cout << "和: " << sum << '\n'
		<< "积: " << product << '\n'
		<< "-分割的字符串: " << s << '\n';
}


#endif 

#if 0
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

template<typename C>
void print(const C& c) {
	for(auto e:c)
		std::cout << e << " ";
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

#if 0
#include <string>
#include <iostream>
#include <algorithm>
int main() {
	std::string s = "abbcccde";
	auto p = std::unique(s.begin(), s.end());
	std::cout << s <<'\t'<< p-s.begin() << '\t' 
		<<s.substr(0, p - s.begin())<< '\n';
}
#endif

#if 0
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include <functional>  //bind
#include <random> //伪随机数模块
using namespace std;
//生成随机整数的类
class Rand_int{
public:
	Rand_int(int lo, int hi) : p{ lo,hi } { } // store the parameters
	int operator()() const { return r(); }
private:
	uniform_int_distribution<>::param_type p;
	function<int()> r{ bind(uniform_int_distribution<>{p}, default_random_engine{}) };
};
//生成随机实数的类
class Rand_double{
public:
	Rand_double(double low, double high)
		:r(bind(uniform_real_distribution<>(low, high), default_random_engine())) { }
	double operator()() { return r(); }
private:
	function<double()> r;
};

int v1[3];
std::array<int,3> v2;
std::vector<double> v3;

template<typename C>
void Print(const C& c) {
	for (auto &e : c)
		std::cout << e << '\t';
	std::cout << '\n';
}
void main(){
	std::fill(std::begin(v1), std::end(v1), 9); // v1的所有元素值设置为9
	generate(begin(v2), end(v2), Rand_int(1,100)); // 传递一个头等函数对象Rand_int
	                                       //v2元素值设置为随机整数
	// 输出5个[-100, 100]随机的浮点数
	generate_n(ostream_iterator<double>{cout,","}, 5, Rand_double(-100, 100)); 
	fill_n(back_inserter(v3), 5, 3.1); // 将5个3.1插入到v的后面
	std::cout << std::endl;
	Print(v1);
	Print(v2);
	Print(v3);
}

#endif
#if 0
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
#if 0
	string s = "abbcccde";
	auto p = unique(s.begin(), s.end());
	cout << s << ' ' << p-s.begin() << '\n';
#else
	string s = "abbcccde";
	string s2;
	auto q =  unique_copy(s.begin(), s.end(), std::back_inserter(s2),
		[](char c1, char c2) { return c1 == c2; });
	cout << s2  << '\n';
#endif
}
#endif

#if 0
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <cctype>
int main(){
	std::string str = "Text with some   spaces";
	std::cout << "before: " << str << "\n";

	std::cout << "after:  ";
	std::remove_copy(str.begin(), str.end(),
		std::ostream_iterator<char>(std::cout), ' ');
	std::cout << '\n';

	std::string str1 = "Text with some   spaces";
	str1.erase(std::remove(str1.begin(), str1.end(), ' '),
		str1.end());
	std::cout << "remove:  " << str1 << '\n';

	std::string str2 = "Text with some   spaces";
	str2.erase(std::remove_if(str2.begin(),
		str2.end(),
		[](unsigned char x) {return std::isspace(x); }),
		str2.end());
	std::cout << "remove_if:  " << str2 << '\n';
}
#endif

#if 0
#include <algorithm>
#include <string>
#include <array>
#include <iostream>
#include <functional>
int main() {
	std::string s = "hello world";
	std::replace(s.begin(), s.end(), 'o', 'X'); // 所有的'o'替换为'X'
	std::cout << s;

	std::array<int, 10> s{ 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };	
	std::replace_if(s.begin(), s.end(),
		std::bind(std::less<int>(), std::placeholders::_1, 5), 55);
}
#endif


#if 0
template<typename C，Val v>
auto find_last(C& c，Val v) −> decltype(c.begin())
{
	for (auto p = c.rbegin(); p != c.rend(); ++p) //逆向搜索
		if (∗p == v) return −−p.base();
	return c.end(); // 用c.end()表示"未找到"
}


template<typename C>
auto find_last(C& c, Val v) − > decltype(c.begin())
{
	for (auto p = c.end(); p != c.begin(); ) // 前向搜索search backward from end
		if (∗−−p == v) return p;
	return c.end(); // 用c.end()表示"未找到"
}
#endif 

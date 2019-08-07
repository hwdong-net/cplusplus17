/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#if 0
#include <iostream>
struct Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
int main() {
	Date day;	
	day.year = 2018;// 通过成员访问运算符.访问类对象day的成员year
	day.month = 6;
	day.day = 1;
	std::cout << day.year << '-' << day.month << '-' << day.day << '\n';
}
#endif 

#if 0
#include <iostream>
struct Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
};

void print(Date *date) {//date是Date*指针类型，不是一个Date对象
	 // 间接访问运算符->访问date指向的Date对象的成员year，month和day
	std::cout << date->year << "-" << date->month << "-" << date->day << '\n';
}

int main() {
	Date day;
	day.year = 2018;// 通过成员访问运算符.访问类对象day的成员year
	day.month = 6;
	day.day = 1;
	print(&day); //将day的地址作为指针传给print函数
}

int main() {
	Date day;
	print(&day); //将day的地址作为指针传给print函数
	day.year = 2018;// 通过成员访问运算符.访问类对象day的成员year
	day.month = 6;
	day.year = 1;
	print(&day); //将day的地址作为指针传给print函数
}

#endif

#if 0
#include <iostream>
class Date {
public:
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
void print(Date *date) {	
	std::cout << date->year << "-" << date->month << "-" << date->day << '\n';
}
int main() {
	Date day;
	day.year = 2018;// 通过成员访问运算符.访问类对象day的成员year
	day.month = 6;
	day.day = 1;
	print(&day);
}
#endif 

#if 0
#include <iostream>
class Date {
public:          //public之后的成员都是公开的
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() {
		//print函数知道year、month、day是那个对象的成员   
		std::cout << year << "-" << month << "-" << day << '\n';
	}
};
int main() {
	Date day;
	day.year = 2018;
	day.month = 6;
	day.day = 1;
	day.print();  //必须通过类对象day调用类Date的函数成员print()
}
#endif 


#if 0

#include <iostream>
class Date {
public:          //public之后的成员都是公开的
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() {   //注意：不能写成: void print(Date *this){ 
		//通过指针变量this访问其指向对象的year、month、day成员
		std::cout << this->year << "-" << this->month << "-" << this->day << '\n';
	}
};
int main() {
	Date day, day1;
	day.print();
	day1.print();
}

#endif 

#if 0
#include <iostream>
class Date {
public:          //public之后的成员都是公开的
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& setDay(int d) {
		day = d;
		return *this; //返回this指针指向的对象的引用
	}
	Date& setYear(int y) {
		year = y;
		return *this; //返回this指针指向的对象的引用
	}
};
int main() {
	Date day;
	day.year = 2018;
	day.month = 6;
	day.day = 1;
	day.print();
	day.setYear(2019).setDay(20); //day.setYear(2019)的返回是day自身，
								  //因此对它可以继续调用setDay(20)
}
#endif 

#if 0
#include <iostream>
class Date {
public:          //public之后的成员都是公开的
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& setDay(int d) {
		day = d;
		return *this; //返回this指针指向的对象的引用
	}
	Date* setYear(int y) {
		year = y;
		return this;  //返回this指针
	}
};
int main() {
	Date day,day2;
	day.year = 2018;
	day.month = 6;
	day.day = 1;
	day.print();
	day.setYear(2019)->setDay(20); //day.setYear(2019)的返回是day的指针，
                                //通过这个指针可以间接调用setDay(20)
	day2.print();
}

#endif 

#if 0
#include <iostream>
class X {
	int a, b, c;
	double d;
};
int main() {	
	X x;
	std::cout << sizeof(int) << '\t' << sizeof(double) << '\n';
	std::cout << sizeof(x) << '\t' << sizeof(X) << '\n';
}

#endif 
//构造函数

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() {} //构造函数名与类名相同，没有返回类型
	          //默认构造函数没有任何参数和函数体代码
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1;
	day.print();
	day1.print();
}

#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() { std::cout << "构造Date对象：" << std::endl; print(); }
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day;	//定义类对象时自动调用匹配的构造函数
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "构造Date对象：" << '\t'; 
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018,8,18),	//定义类对象时自动调用匹配的构造函数
	     day2{ 2019,6,1 };
	Date day;    //错：没有合适的默认构造函数可用
	Date day(2010, 1, 2, 3);  //错：没有重载函数接受 4 个参数
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() = default;
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "构造Date对象：" << '\t';
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018, 8, 18),	//定义类对象时自动调用匹配的构造函数
		day2{ 2019,6,1 };
	Date day;    //Ok,调用默认构造函数
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date() = default;
	Date(int y = 2000, int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day,day1(2011),day2{ 2019,6},
		day3{ 2019,13,8 };
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(Date &d) :year(d.year),month(d.month),day(d.day){}

	Date(int y = 2000, int m = 1, int d = 1) :year(y),month(m),day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date &operator=(const Date& date) {
		std::cout << "赋值运算符\n";
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this; //返回被赋值对象的而自身的引用
	}
};

int main() {
	Date day(2018, 1, 1);
	Date day2, day3;
	day3 = day2 = day; //先执行day2 = day，结果是day2，再执行day3 = day2
					 //day2 = day实际是day2.operator=(day)
}
#endif 

#if 0
int main() {

	Date day{ 2018,1,1 },day2{day}
	day.print();
	day2.print();


	Date day{ 2018,1,1 }, day3;
	day3 = day;
	day.print();
	day3.print();
}
#endif


#if 0
#include <iostream>
class A {	
public:
	A(int x) { std::cout << "用" << x << "构造对象"; }
};
void f(A a) {}
int main() {
	f(2); // 1隐含通过构造函数A(int)转换成A类型对象，再对a1初始化
}

#endif 

#if 0
#include <iostream>
class Circle{
	double radius{0.};
public:
	explicit   Circle(double r):radius(r) {}
	auto area() { return 3.1415*radius*radius; }
	auto isAreaLargerThan(Circle c) { return area() > c.area(); }
};
int main() {
	Circle c(2), c2(5);
	std::cout << "a和c2的面积是：" << c.area() << '\t' << c2.area() << '\n';
	if (c2.isAreaLargerThan(c))
		std::cout << "c2的面积比c大\n";
	else 
		std::cout << "c2的面积比c小\n";
	if (c2.isAreaLargerThan(50))
		std::cout << "c2的面积比50大\n";
	else 
		std::cout << "c2的面积比50小c\n";
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1):year(y), month(m), day(d) {
	}
	Date(int *p) :Date(p[0], p[1], p[2]) { //委托Date(int y=2000,int m=1,int d=1)构造函数    
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
#endif 

#if 0
class A {
public:
	A(int) {/*...*/ }
	A(double) = delete;
	A& operator=(const A& o) = delete;
	A(const A& o) = delete;
};
int main() {
	A a(1);
	A a1(3.14);  //错： A(double)被禁止了
	A a2(a);     //错：A(const A& o) 被禁止了
	a2 = a1;     //错：A& operator=(const A& o) 被禁止了
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1);
	void print();
};
Date::Date(int y, int m, int d) :year(y), month(m), day(d) {}
void Date::print() { std::cout << year << "-" << month << "-" << day << '\n'; }
#endif


#if 0
#include <iostream>
class Date {	
public:
	Date(int y = 2000, int m = 1, int d = 1):year(y), month(m), day(d) {
	}
	Date(int *p) :Date(p[0], p[1], p[2]) { //委托Date(int y=2000,int m=1,int d=1)构造函数    
	}
	//get函数：访问类对象的数据
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

	//set函数：修改类对象的数据
	void setYear(int y) { if (y > 0) year = y; }
	void setMonth(int m) { if (m > 0) month = m; }
	void setDay(int d) { if (d > 0) day = d; }
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
private:
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
int main() {
	Date day;
	day.setYear(2018);
	std::cout << day.getMonth() << '\n';
}


#endif 

#if 0
int main() {
	int i;
	const int ci = 1;
	ci = 3; //错：不能修改const对象(变量)
	const int *p = &i; //p是指向const int即“常对象”的指针变量
	*p = 3;  //错：不能修改p指向的常对象(const对象)
	const int &r = i;  //p是const int“常对象”的引用
	r = 3;   //错：不能修改r引用的常对象(const对象)
}
#endif

#if 0
class X {
public:
	int ival{ 0 };
};
int main() {
	const X x;
	std::cout << x.ival << std::endl; //OK
	x.ival = 10;  //错：const对象x（的成员）不能被修改
	
	X y;
	y.ival = 10;  // y不是const对象，当然可以修改它（的成员）
	const X *p = &y;
	p->ival = 20;  //错：不能通过p去修改它指向的const X即“常对象”，
	               // 即使初始化p的y是可以修改的
	const X &r = y;  //const X的引用变量r绑定到y
	r.ival = 20;   //错：不能通过引用变量r修改它引用的const X即“常对象”，
	              //即使初始化r的y是可以修改的
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date(int y = 2000, int m = 1, int d = 1):year(y), month(m), day(d) {
	}
	Date(int *p) :Date(p[0], p[1], p[2]) { //委托Date(int y=2000,int m=1,int d=1)构造函数    
	}
	//get函数：访问类对象的数据
	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }

	//set函数：修改类对象的数据
	void setYear(int y)const  { if (y > 0) year = y; }
	void setMonth(int m) { if (m > 0) month = m; }
	void setDay(int d) { if (d > 0) day = d; }
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	const Date day;
	day.setYear(2008);    //错：不能去修改const对象day
	std::cout << day.getYear() << std::endl;  //Ok!    
}
#endif 

#if 0
#include <iostream>
class Date {
	int _year{ 2000 }, _month{ 1 }, _day{ 1 };
public:
	int& year() { return _year; }
	int& month() { return _month; }
	int& day() { return _day; }
};
int main() {
	Date day;
	day.year() = 2008;    //OK
	std::cout << day.year() << std::endl; //OK
	const Date day2;
	day2.year() = 2008;  //编译错误。是合理的，因为不能const对象嘛
	std::cout << day2.year() << std::endl; //编译错误。不合理，为什么不能查询const对象信息？    
}
#endif 

#if 0
#include <iostream>
class Date {
	int _year{ 2000 }, _month{ 1 }, _day{ 1 };
public:
	int& year() { return _year; }
	int& month() { return _month; }
	int& day() { return _day; }
	const int& year() const { return _year; }
	const int& month() const { return _month; }
	const int& day() const { return _day; }
};
int main() {
	Date day;
	day.year() = 2008;    //OK
	std::cout << day.year() << std::endl; //OK
	const Date day2;
	//day2.year() = 2008;  //编译错误。是合理的，因为不能修改const对象
	std::cout << day2.year() << std::endl; //OK,没有编译错误。    
}
#endif 

#if 0
class X {
	mutable int count{ 0 };
	int ival{ 0 };
public:
	int val()const {
		count++; //mutable成员总是可以被修改
		return ival;
	}
};

#endif 

#if 0
#include <iostream>
class X {
	int x{ 0 };
public:
	void set_x(int i) { x = i; }
	void print() { std::cout << x; }
};
int main() {
	X x;
	x.print(); std::cout << '\n';
	X arr[3];
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
	for (auto i = 0; i != 3; i++) arr[i].set_x(2 * i + 1);
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
}
#endif

#if 0
class X {
	int x{ 0 };
public:
	X(int i) :x(i) {}
};
int main() {
	X arr[3];
}
#endif 

#if 0
#include <iostream>
class IntArray {
	int *data{ nullptr };//指针变量指向动态分配的int数组
	int size{0}; //data指向的数组的大小
public:
	IntArray(int s) :size(s) {
		data = new int[s];
		if (data)  size = s; 
		std::cout << "构造了一个大小是" << s << "的IntArray对象\n";
	}
	~IntArray() { 
		std::cout << "析构函数\n";
		if (data) delete[] data;
	}
	void put(int i,int x) { 
		if (i >= 0 && i < size) data[i] = x; }
	int get(int i) { 
		if (i >= 0 && i < size) return data[i];
		else return 0;
	}
};

int main(){
	std::cout << "请输入人数：";
	int s; std::cin >> s;
	IntArray arr(s);
	std::cout << "请输入年龄：";
	for (auto i = 0; i < s; i++) {
		int age;
		std::cin >> age;
		arr.put(i, age);
	}
	std::cout << '\n';
	std::cout << "输入的年龄是：\n";
	for (auto i = 0; i < s; i++) 
		std::cout << arr.get(i)<<'\t';
	std::cout << '\n';

}
#endif

#if 0
#include <iostream>
class X
{
public:
	static inline int count{};   //X对象的个数
public:
	int get_count() { return count; };
	X() { count++; }   //创建了一个新的X对象,count增加1
	~X() { count--; }  //销毁了一个新的X对象,count减少1
};
//int X::count = 0; //或 int X::count {};

int main() {
	X x,x2;
	X arr[3];	
	std::cout << x.count<< '\t' << arr[1].count << '\t' << X::count << '\n';
}
#endif
#if 0
class Circle {
public:
	static inline const double PI{ 3.1415926 };
	Circle(double r) :radius(r) {}
	auto area() { return PI * radius*radius; }
private:
	double radius{ 0. };
};

#endif

#if 0
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:
	const static Date default_date;
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
const Date Date::default_date{ 2010,1,1 };
#endif

#if 0
#include <iostream>
class Date {	
	int year{ default_date.year }, month{ default_date.month }, 
		day{ default_date.day };
public:
	static Date default_date;
	static void set_default(const Date &d) {
		default_date.year = d.year;
		default_date.month = d.month;
		default_date.day = d.day;
	}
	Date(int y = default_date.year, int m = default_date.month, 
		int d = default_date.day) :year(y), month(m), day(d) {
	}	
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
Date Date::default_date{2010,1,1};
int main() {
	Date arr[3];
	Date d(2018,6,8);
	d.set_default(d); //或Date::set_default(d)
	Date arr2[5];
}


#endif 

#if 0
#include <iostream>
class X{
public:
	static inline int count{};   //X对象的个数
public:
	static int get_count() { return count; };
	X() { count++; }   //创建了一个新的X对象,count增加1
	~X() { count--; }  //销毁了一个新的X对象,count减少1
};

int main() {
	X x, x2;
	X arr[3];
	std::cout << x.get_count() << '\t' << arr[1].get_count() << '\t'
		<< X::get_count() << '\n';
}
#endif 


//习题
#if 0

#include <iostream>
using namespace std;

class 	Point{
	int x{ 0 }, y{ 0 };
public:
	Point(){
		cout << "Constructor Called"<<endl;
	}	
	Point(int X, int Y = 20){
		//?
		cout << "Constructor Called" <<x<<","<<y<< endl;
	}	
	~Point(){
		cout << endl << "Destructor Called" << x << "," << y << endl;
	}
	void set_x(const int x) {?}
	void print()	{
		cout << x << "," << y << endl;		
	}
};

int main(){
	Point p1 = Point(10);
	cout << "p1 Value Are : ";
	p1.print();
	Point p2 = Point(30, 40);
	cout << "p2 Value Are : ";
	p2.print();
	p1.set_x(2);
	p1.print();
	return 0;
}


//https://www.includehelp.com/cpp-programs/cpp-class-program-to-read-time-in-seconds-and-convert-in-time-format-hh-mm-ss-using-class.aspx
#include <iostream>
using namespace std;

class Time{
private:
	int hours,minutes,seconds;
public:
	Time(int h, int m, int s);
	Time(const char *str); //str是字符串格式的时间“02：08：15”
	void getTime(void);
	void putTime(void);
	void addTime(Time T1, Time T2);
	int seconds();//将时间转换为秒
};
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){
		std::cout << "拷贝构造函数\n"; print(); }
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();
}
#endif

#if 0

#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	//委托Date(int y=2000,int m=1,int d=1)构造函数  
	Date(int *p) :Date(p[0], p[1], p[2]) {	}
//	Date(int *p) :Date(p[0], p[1], p[2]), day{ 20 } {	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	int date[]{ 2018,9,6 };
	Date d(date); d.print();
}
#endif

#if 0
#include <iostream>
class X {
private:
	inline static int count{0};   //X对象的个数
public:
	int get_count() { return count; };
	X() { count++; }   //创建了一个新的X对象,count增加1
	~X() { count--; }  //销毁了一个新的X对象,count减少1
};

int main() {
	X x, x2;
	X arr[3];
	std::cout << x.get_count() << '\n';
}

#endif

#if 0
#include <iostream>
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:	
	static  const  Date default_date;
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
const Date Date::default_date{ 2010,1,1 };
int main() {
	Date day;
	day.print();
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>   //strlen()
class String {
	char *data{ nullptr };
	int size_{0};
public:
	String() = default;
	String(const char *s) {
		auto len = strlen(s);
		data = new char[len + 1];
		if (!data) return;
		strcpy(data, s);//拷贝字符串内容从s到data指向的空间
		size_ = len;
	}
	~String() { delete[] data; }
	auto size() { return size_; }
};
int main() {
	String s("hello world");
//	String s2(s); //调用拷贝构造函数，将s拷贝到新对象s2中。
	String  s3;
	s3 = s;
	std::cout << s.size();
	//std::cout << s.find(“helo”);
}

#endif

#if 0
using ElemType = char;
class Vector {
	ElemType *data{ nullptr };
	auto  capacity{0}, n{0};
public:
	Vector(const int cap = 5)   //创建容量是cap的一个线性表
		:capacity{ cap }, data{ new ElemType[cap] }	{}
	bool insert(const int i, const ElemType &e); //在i处插入元素
	bool erase(const int i);            //删除i元素
	bool push_back(const ElemType &e); //表的最后添加一个元素
	bool pop_back();  //删除表的最后元素

	bool get(const int i, ElemType &e)const; //读取i元素
	bool set(const int i, const ElemType e);//修改i元素
	int size() const { return n; }  //查询表长
private:
	bool add_capacity();             //扩充容量
};

bool Vector::insert(const int i, const ElemType &e) { //在i处插入元素
	return true;
}
bool Vector::erase(const int i) {            //删除i元素
	return true;
}
bool Vector::push_back(const ElemType &e) { //表的最后添加一个元素
	return true;
}
bool Vector::pop_back() {  //删除表的最后元素
	return true;
}

bool Vector::get(const int i, ElemType &e)const { //读取i元素
	return true;
}
bool Vector::set(const int i, const ElemType e) {//修改i元素
	return true;
}
bool Vector::add_capacity(){            //扩充容量
	return true;
}
#endif

#if 0
#include <iostream>
#if 0
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	Point operator-()const {
		return Point(-this->y, -this->x);
	}
	void print() { std::cout << x << "," << y; }
	//...
};
#else
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}	
	friend Point operator-(const Point &p);
	void print() { std::cout << x << "," << y; }
	//...
};
Point operator-(const Point &p) {
	return Point(-p.y, -p.x);
}

#endif 

int main() {
	Point p(3, 4);
	(-p).print();
}

#endif


class X {
public:
	inline void f();
};
void X::f() {
	/*...*/
}
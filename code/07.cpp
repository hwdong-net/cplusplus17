/*传统的过程式编程：
变量 (对象)就是一些存储数据的内存块，而过程 (函数)对这些数据进行处理。
*/

/*
 面向对象设计与编程：程序是由不同种类的许多对象相互协作完成的。
 对象之间通过发送/接收消息来协作完成各种任务。
 由这些对象构成的程序也称为“对象式系统”.
*/

//------------用class或struct关键字定义一个类----
//定义的类就是一个数据类型。

#if 0
#include <string>
using std::string;
struct student {
	string name;
	double score;
};

//C++中变量也称为对象，对象是类（类型）的具体实例
//如: student stu
//通过成员访问运算符.访问类对象的成员
//如：stu.score

int main() {
	student stu; //定义一个类的实例-对象
	stu.name = "LiPing"; //成员访问运算符.访问类对象的成员
	stu.score = 78.5;

	//和内在类型一样，可以定义类类型的数组，存储一组类对象。
	student students[3];
	students[0].name ="LiPing";
	students[0].score = 60.5;
}
#endif

#if 0
//T是类类型，则T* 是T指针类型
#include <string>
using std::string;
struct student {
	string name;
	double score;
};
int main() {
	student stu;	
	student* p = &stu;

	(*p).name = "LiPing";   //*p就是p指向的变量stu
	p->score = 78;                //p指向的类对象的成员score
	student students[3];
	p = students + 2;         //指向第3个student对象
	p->name = "Wang Wei";	
}
#endif

#if 0
//T是类类型，则T* 是T指针类型
//T* 指针指向动态分配的一个或多个对象
//如同int *是指向int类型变量的指针类型
//同样可以用间接访问运算符 ->或解引用运算符*访问指针指向的变量

#include <string>
using std::string;
struct student {
	string name;
	double score;
};
int main() {
	student* p = new student;
	p->name = "Wang";
	delete p;                     //不需要的内存块要及时释放
	p = new student[3];   //p指向动态分配的3个student的内存块的起始地址
	p[1].score = 67;
	(*(p + 1)).score = 67;
	p->score = 78;
	delete[] p;
}
#endif

#if 0
//---类的成员函数----
// 属于类作用域的函数，可以访问处理类（对象）的数据
#include <iostream>
#include <string>
using std::string;
using std::cout;
struct student {
	string name;
	double score;
	void print() { cout << name << " " << score << '\n'; }
};
int main() {
	student stu;
	stu.name = "LiPing"; //成员访问运算符.访问类对象的成员	
	stu.score = 78.5;
	stu.print();
}
#endif 

#if 0
//可以在类体外 定义成员函数
#include <iostream>
#include <string>
using std::string;
using std::cout;
struct student {
	string name;
	double score;
	void print();
};

void student::print() { 
	cout << name << " " << score << '\n';
}
int main() {
	student stu;
	stu.name = "LiPing"; //成员访问运算符.访问类对象的成员	
	stu.print();
}
#endif 


# if 0
//----------this 指针-----
//类的（非静态）成员函数都有一个this隐含参数，
//它指向调用这个函数的那个对象
#include <iostream>
#include <string>
using std::string;
using std::cout;
struct student {
	string name;
	double score;
	void print() { cout << name << " "<< score << '\n'; }
};
//void print(student *this){/*...*/}
int main() {
	student stu, stu2;
	stu.name = "Li"; stu.score = 67.8;
	stu2.name = "Wang"; stu2.score = 77.5;
	stu.print(); //  print(&stu)
	stu2.print();
}
#endif 

#if 0
#include <iostream>
#include <string>
using std::string;
using std::cout;

struct student {
	string name;
	double score;
	void print() {
		cout << this->name << "\t" << this->score<<std::endl;
	}
};

int main() { 
	student stu, stu2;
	stu.name = "Li"; stu.score = 78.6;
	stu2.name = "Wang"; stu2.score = 98.2;
	student* p = &stu;
	p->print();
	(*p).print();
	p = &stu2;
	p->print();
	(*p).print();
	
}
#endif 

#if 0
//----------类对象的大小------------
//一个类对象占据的内存存放的是其数据成员，
//因此类对象的大小基本上等于或略大于所有数据成员占据内存之和。
//为什么略大于所有数据成员之和呢？这是因为数据在内存里是要对齐存放的

#include <iostream>
class X {
	int a, b, c;
	double d;
};
int main() {
	X x;
	std::cout << sizeof(3) << '\t' << sizeof(double) << '\n';
	std::cout << sizeof(x) << '\t' << sizeof(X) << '\n';
}
#endif


//==============构造函数==============
//创建类对象时，会自动调用类的某个构造函数
//没有定义构造函数，则编译器会自动生成一个
//参数列表和函数体都为空的默认构造函数。 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	void print() {
		std::cout << year << "-" << month << "-" << day << '\n'; 
	}
};
int main() {
	Date day, day1;  //day和day1都用默认构造函数
	day.print();
	day1.print();
}
#endif

#if 0
//---------（默认）构造函数-------------
//构造函数：函数名和类名相同，没有返回类型
//默认构造函数：不带参数、或参数都有默认值
#include <iostream>
class Date{
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() { 
		std::cout << "构造Date对象：" << std::endl; 
		print(); 
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day;   //定义类对象时自动调用匹配的构造函数
}
#endif 

#if 0
//---------构造函数-------------
//如果定义了构造函数，则编译器就不会再生成默认构造函数
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
	//Date day(2018, 8, 18),	       //定义类对象时自动调用匹配的构造函数
	//	day2{ 2019,6,1 };

	//Date day;    //错：没有合适的默认构造函数可用
	Date day(2010, 1,3);  //错：没有重载函数接受 4 个参数
}
#endif 



#if 0
//---------（默认）构造函数-------------
//和普通函数一样，类的成员函数（包括构造函数）的参数
//也可以有默认值,并遵守默认参数一律靠右的规则.
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1(2011), day2{ 2019,6 },
		day3{ 2019,13,8 };
	day2.print();
}

#endif 

#if 0
//---------default定义默认构造函数-------------
//可以通过default关键字来通知编译器生成默认构造函数
//不能定义多个默认构造函数，重定义！
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() = default;//Date() {}
	Date(int y , int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day;
}

#endif 

#if 0
//可以定义多个构造函数
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	//Date() {}
	Date() = default;
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "构造Date对象：" << '\t';
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018, 8, 18),	       //定义类对象时自动调用匹配的构造函数
		day2;
}
#endif

#if 0
//-------初始化成员列表-----------
// 在函数体外初始化类对象的成员，
//仍然按照数据成员在Date中定义的次序即year、month、day的次序依次初始化。
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
//	Date(int y = 2000, int m = 1, int d = 1) 
//	:year{ y }, month(m), day(d){		}	
	Date(int y = 2000, int m = 1, int d = 1) 
		: day(d), month(m), year{ y }{
		//year = y; month = m; day = d;
		std::cout << "创建一个date对象\n";
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 };	
	day.print();
	//Date day2{ day };
	//day2.print();
}
#endif 

#if 1
//为什么要初始化成员列表？
//因为有些成员（如non-static const、引用变量、无默认构造函数类对象）
//无法在构造函数体里初始化

#if 0
#include <iostream>
class X {
	const int a;
public:
	X(int x):a(x) {
		
	}  //Initializer list must be used
	int get() { return a; }
};

int main() {
	X x(10);
	std::cout << x.get();
	return 0;
}
#endif 

#if 0
using namespace std;
class X {
	const int &r;
public:
	X(int &b) :r(b) {//Initializer list must be used
		//r = b;
	}  
	int get() { return r; }
};

int main() {
	int i = 20;
	X x(i);
	cout << x.get() << endl;
	i = 30;
	cout << x.get() << endl;
	return 0;
}
#endif 

#if 0
#include <iostream>
using namespace std;

class A {
	int i;
public:
	A(int);
};

A::A(int arg) {
	i = arg;
	cout << "A's Constructor called: Value of i: " << i << endl;
}

// Class B contains object of A
class B {
	A a;
public:
	B(int);
};

B::B(int x) :a(x) {  //Initializer list must be used
	
	cout << "B's Constructor called";
}

int main() {
	B obj(10);
	return 0;
}
#endif 
#endif 



#if 0
//-------拷贝构造函数----------
//用已存在的同类对象对该类对象初始化。
//如果没有定义拷贝构造函数，编译器会自动生成一个默认拷贝构造函数。
#include <iostream>
using std::cout;
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
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
//可以定义自己的拷贝构造函数
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	//	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){
		std::cout << "拷贝构造函数\n";
	}
	Date(int y = 2000, int m = 1, int d = 1) : day(d), month(m), year{ y }{	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();	
}
#endif 

#if 0
//--------拷贝构造函数的参数必须是引用---------
#if 0
class X {	
public:
	X() = default;
	X(X s) {}
};
int main() {
	X x;
	X y(x); //
}  
#else
class X {
public:
	X() = default;
	X( const X &x) {}
	//X& operator=(const X& object) { return *this; }
};
int main() {
	const X a;
	X b;
	X y(a),y2(b);
}
#endif

#endif 


#if 0
//---------默认）赋值运算符operator=---------------
//默认情况下，可以将一个类对象赋值给另外一个类对象
//调用的是：（默认）赋值运算符operator=

#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 }, day3;
	day3 = day; // day3.operator=(day)
	day.print();
	day3.print();

}
#endif 

#if 0
//---------赋值运算符operator=---------------
// 赋值运算符函数的参数和拷贝构造函数一样的，是const引用类型
//但返回的是被赋值对象自身，即 *this
//如：
class X {
	X& operator=(const X& object) {
		//...
		return *this;
  }
};
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& operator=(const Date& date) {
		std::cout << "赋值运算符\n";
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this; //返回被赋值对象自身的引用
	}
};
//a=b=c

#if 0
//---------赋值运算符operator=-右结合性--------------
int main() {
	Date day{ 2018,1,1 }, day3;
	day3 = day; // day3.operator=(day)
	day.print();
	day3.print();
}
#else
int main() {
	Date day(2018, 1, 1);
	Date day2(2020,4,8), day3;
	day3 = day2 = day; //先执行day2 = day，结果是day2，再执行day3 = day2
					 //day2 = day实际是day2.operator=(day)
	//day3.operator=(day2.operator=(day))
	day.print();
	day2.print();
	day3.print();
}
#endif
#endif 


#if 0
//--------隐式类型转换------------
//---带有1个参数的构造函数，定义了隐式类型转换----
#include <iostream>
class A {
public:
	A(int x) { std::cout << "用" << x << "构造对象"; }
};

#if 0
int  main() {
	A a(1), b{ 2 }, c = 3;  //创建A类的3个对象a,b,c
	a = 4;    //即：a= A(4);将4赋值给A类对象，
	          //先将4转化为A类对象A(4)，再赋值给
}
#else
void f(A a) {}
int main() {
	f(2); //即：f(A(2)): 隐含通过构造函数A(int)
	          //转换成A类型对象，再对a初始化
}
#endif

#endif 

#if 0
//然而，对于有的类，这种隐含类型转换会带来一些问题。
#include <iostream>
class Circle {
	double radius{ 0. };
public:
	 Circle(double r) :radius(r) {}
	auto area() { return 3.1415 * radius * radius; }
	auto isAreaLargerThan(Circle c) { return area() > c.area(); }
};

int main() {
	Circle c(2), c2(5);
	std::cout << "c和c2的面积是：" << c.area() << '\t' << c2.area() << '\n';
	if (c2.isAreaLargerThan(c))
		std::cout << "c2的面积比c大\n";
	else
		std::cout << "c2的面积比c小\n";
	if (c2.isAreaLargerThan(50))
		std::cout << "c2的面积比50大\n";
	else
		std::cout << "c2的面积比50小\n";
}

#endif 


#if 0
//--------explicit---------------
//用explicit说明构造函数禁止隐含类型转换
#include <iostream>
class Circle {
	double radius{ 0. };
public:
	explicit Circle(double r) :radius(r) {}
	auto area() { return 3.1415 * radius * radius; }
	auto isAreaLargerThan(Circle c) { return area() > c.area(); }
};

int main() {
	Circle c(2), c2(5);
	std::cout << "c和c2的面积是：" << c.area() << '\t' << c2.area() << '\n';
	if (c2.isAreaLargerThan(c))
		std::cout << "c2的面积比c大\n";
	else
		std::cout << "c2的面积比c小\n";
	if (c2.isAreaLargerThan(50))
		std::cout << "c2的面积比50大\n";
	else
		std::cout << "c2的面积比50小\n";
}
#endif 

#if 0
//-----------委托构造函数-------------
//委托构造函数:一个构造函数在初始化列表种调用其他的构造函数.
//可以避免重复的代码
//委托构造函数只能在初始化成员列表里而不能在函数体里调用被委托构造函数。
//成员变量不能在委托构造函数的初始化列表里初始化，但可以在函数体里初始化成员变量。
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
		std::cout << "默认构造函数！\n";
	}
	//委托Date(int y=2000,int m=1,int d=1)构造函数  
	Date(int* p) :Date(p[0], p[1], p[2]) {	
		std::cout << "委托构造函数！\n";
	}
	//Date(int* p) :Date(p[0], p[1], p[2]), day{ 20 } {	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	int date[]{ 2018,9,6 };
	Date d(date); d.print();
}
#endif

#if 0
//-------delete----------
//可能希望禁止某个构造函数或赋值运算符，
//比如禁止编译器生成默认的拷贝构造函数或赋值运算符，
//可以通过delete关键字显式地进行说明
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
//输入输出流对象也是禁止被拷贝的，
//因为代表输入的键盘和输出的屏幕只有一个，如果允许拷贝，就混乱了。
#endif



#if 0
//-------类对象的数组----------
//一个没有构造函数或者定义了默认构造函数的类，才可以定义这种类的对象的数组。
#include <iostream>
class X {	
public:
	void set_x(int i) { x = i; }
	void print() { std::cout << x; }
private:
	int x{ 0 };
};

int main() {
	X x;
	x.print(); std::cout << '\n';
	X arr[3];              //X类对象的数组
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
	for (auto i = 0; i != 3; i++) 
		arr[i].set_x(2 * i + 1);
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
}
#endif 

#if 0
//-------类对象的数组----------
//有默认构造函数的类，才可以定义类对象的数组
class X {
	int x{ 0 };
public:	
};
int main() {
	X arr[3];    //X有编译器生成的默认构造函数，可定义X类型的数组！
	X* p = new X[3];
}
#endif 

#if 0
//-------类对象的数组----------
//没有默认构造函数的类，则不能定义类对象的数组
class X {
int x{ 0 };
public:
	X(int i) :x(i) {}
};
int main() {
	X arr[3];    //X没有默认构造函数，因此不能定义X类型的数组！
}
#endif 

#if 0
//-------访问控制--------------
//private、public关键字说明类的成员是否可以被外界访问
#include <iostream>
class X {
	int x;
public:
	void set_x(int i) { x = i; }
	int get_x() { return x; }
};

int main() {
	X x;
	x.x = 5;
	x.set_x(5);
	std::cout << x.get_x();
}

#endif

#if 0
//-------访问控制--------------
//private,public,protected
#include <iostream>
class Date {
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	Date(int* p) :Date(p[0], p[1], p[2]) { //委托Date(int y=2000,int m=1,int d=1)构造函数    
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
	day.month = 4;
	day.setYear(2018);
	std::cout << day.getMonth() << '\n';
}
#endif

#if 0
//------const对象:不可修改的对象---------
int main() {
	int i;
	const int ci = 1;
	ci = 3;             //错：不能修改const对象(变量)
	const int* p = &i;    //p是指向const int即“常对象”的指针变量
	*p = 3;            //错：不能修改p指向的常对象(const对象)
	const int& r = i;     //r是const int“常对象”的引用
	r = 3;              //错：不能修改r引用的常对象(const对象)
}
#endif

#if  0
//------const对象:不可修改的对象---------
#include <iostream>
class Date {
	int year, month, day;
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	void setYear(const int year) { this->year = year; }
	int getYear() { return year; }
};
int main() {
	const Date day;
	day.setYear(2008);            //错：不能去修改const对象day
	std::cout << day.getYear();      //错：getYear虽然不会修改day			
									 //但编译器怎么知道它会不会修改day的数据呢？
}
#endif

#if  0
//--------const成员函数:不能修改数据成员的函数---------
#include <iostream>
class Date {
	int year, month, day;
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	void setYear(const int year) { this->year = year; }
	int getYear()const { return year; }
};
int main() {
	const Date day;
//	day.setYear(2008);            //错：不能去修改const对象day
	std::cout << day.getYear();      //错：getYear虽然不会修改day			
									 //但编译器怎么知道它会不会修改day的数据呢？
}
#endif 

#if  0
//-----------重载const-----------
//const函数中的const关键字是函数签名的一部分，
// 也就是说可以用于重载解析过程中区分同名函数的。
class X {
	void f() {/*...*/ }
	void f()const {/*...*/ }
};

//不能通过const对象或const对象的指针或引用调用这个非const函数
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
	day.year() = 2008;                 //OK
	std::cout << day.year() << std::endl;   //OK
	const Date day2;
	day2.year() = 2008;                //编译错误。是合理的，因为不能修改const对象嘛
	std::cout << day2.year() << std::endl;  //编译错误。不合理，为什么不能查询const对象信息？    
}

#endif

#if 0
//解决方法是重载const，即定义一个重载的const函数。
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
	day.year() = 2008;    //没问题，调用的是非const函数：int& year()
	std::cout << day.year() << std::endl; //OK
	const Date day2;
	//day2.year() = 2008;  //编译错误。是合理的，因为不能修改const对象
	std::cout << day2.year() << std::endl; //OK,没有编译错误。    
}

#endif 

#if 0
//mutable
//用mutable成员总是可以被修改的，即使是const函数
#include <iostream>
class X {
	mutable int count{ 0 }; //count是mutable函数
	int ival{ 0 };
public:
	int val()const {
		count++;       //mutable成员总是可以被修改
		return ival;
	}
	int get_count()const { return count; }
};

int main() {
	X x;
	std::cout << x.val() << '\n';
	std::cout <<x.get_count();
}
#endif

#if 0
//当一个类对象被销毁时，会调用一个称为析构函数（destructor）的特殊成员函数。
class X {
public:
	~X() {  }  //或：~X()=default
};
#endif


#if 0
//当一个类对象被销毁时，会调用一个称为析构函数（destructor）的特殊成员函数。
#include <iostream>
class X{
public:
	X(){ std::cout << "构造函数会申请资源\n"; }
	//~X()=default
	~X() {
		std::cout << "析构函数用于销毁/释放对象占用的资源\n";
	}
}; 

int main() {
	X x;
}

#endif


#if 0
//IntArray类表示一个固定大小的数据元素是int的动态数组。
#include <iostream>
class IntArray {
	int* data{ nullptr };      //指针变量指向动态分配的内存块
	int size{ 0 };            //data指向的动态数组的大小
public:
	IntArray(int s) :size(s) {
		data = new int[s];    //分配一块动态内存，地址保存在data中
		if (data)  size = s;
		std::cout << "构造了一个大小是" << s << "的IntArray对象\n";
	}
	~IntArray() {
		std::cout << "析构函数\n";
		if (data) delete[] data;  //释放data指向的动态内存
	}
	void put(int i, int x) {
		if (i >= 0 && i < size) data[i] = x;
	}
	int get(int i) {
		if (i >= 0 && i < size) return data[i];
		else return 0;
	}
};

int main() {
	std::cout << "请输入人数：";
	int s; std::cin >> s;

	IntArray arr(s);      //创建IntArray对象，会为s.data成员分配一块动态内存

	std::cout << "请输入年龄：";
	for (auto i = 0; i < s; i++) {
		int age;
		std::cin >> age;
		arr.put(i, age);
	}
	std::cout << "输入的年龄是：\n";
	for (auto i = 0; i < s; i++)
		std::cout << arr.get(i) << '\t';
	std::cout << '\n';       //这句结束后，将销毁arr，因此IntArray的
//析构函数释放arr.data指向的动态内存
}
#endif 

#if  0
//static关键字修饰的成员称为静态成员。
//静态成员属于整个类而不是某个对象。静态成员变量是类所有对象共享的。

# if 0
class X {
private:
	static int count;   //count是类X的静态成员变量，表示类X的对象的个数
public:
	static int get_count() { return count; };
	X() { count++; }   //创建了一个新的X对象,count增加1
	~X() { count--; }  //销毁了一个新的X对象,count减少1
};
int X::count = 0;       //或 int X::count{0};

#else 
//类X定义中的静态成员变量count仅仅是声明还不是定义，因此，在类定义中不能对它初始化。
class X {
private:
	static  int count{0};   //count是类X的静态成员变量，表示类X的对象的个数
public:
	static int get_count() { return count; };
	X() { count++; }   //创建了一个新的X对象,count增加1
	~X() { count--; }  //销毁了一个新的X对象,count减少1
};
#endif
//静态成员变量必须在类体外定义，因为它不属于某个对象


#include <iostream>
int main() {
	//X x,y;
	std::cout<<X::get_count();
	//std::cout << X::count;
}
#endif

#if  0
//在C++17中通过关键字inline修饰一个静态变量，使得静态成员的声明与定义统一起来，
class X {
private:
	 static inline int count{ 0 };   //count是类X的静态成员变量，表示类X的对象的个数
public:
	int get_count() { return count; };
	X() { count++; }   //创建了一个新的X对象,count增加1
	~X() { count--; }  //销毁了一个新的X对象,count减少1
};
int main() {
	X x;
}
#endif 

#if 0
//静态const成员变量
class Circle {
public:
	static inline const double PI{ 3.1415926 };
	//static void init() { radius = 0; }
	Circle(double r) :radius(r) {}
	auto area() { return PI * this->radius * radius; }
private:
	double radius{ 0. };
};

#include <iostream>
int  main() {
	Circle c(2.5);
	std::cout <<sizeof(c)<<" "<< c.area() << " " <<c.PI<<" "<<Circle::PI;
}

#endif

#if 0
//静态成员函数(static member function)
//关联整个类的成员函数，不能访问非静态成员
class X {
public:
	static inline int count{};   //count是类X的静态成员变量，表示类X的对象的个数
public:
	static int get_count() { return count; };    //静态成员函数
	X() { count++; }         //创建了一个新的X对象,count增加1
	~X() { count--; }         //销毁了一个新的X对象,count减少1
};
//和静态成员变量不同的是，静态成员函数的定义可以完全定义在类体内，当然也可以定义在类体外。
//静态成员函数和静态成员变量都是属于整个类，通过类名就可以调用静态成员函数，
//而普通成员函数必须通过类对象才能调用。
#include <iostream>
int main() {
	X x, x2;
	X arr[3];
	std::cout << x.get_count() << '\t' << arr[1].get_count() << '\t'
		<< X::get_count() << '\n';
}

#endif

#if 0
//类自身类型的静态成员变量
#include <iostream>
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
//必须在类体外定义它：
const Date Date::default_date{ 2010,1,1 };

int main() {
	Date arr[3];
	Date d(2018, 6, 8);
	Date arr2[5];

}
#endif

#if  0
//也可以将它定义成非const类型的静态成员，以便可以修改它
#include <iostream>
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:
	static Date default_date;
	static void set_default(const Date& d) {
		default_date.year = d.year;
		default_date.month = d.month;
		default_date.day = d.day;
	}
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
//然后在类体外，定义它：
Date Date::default_date{ 2010,1,1 };
//现在就可以修改这个静态成员变量了：
int main() {
	Date arr[3];
	Date d(2018, 6, 8);
	d.set_default(d);     //  或Date::set_default(d)
	Date arr2[5];
}
#endif

#if 0
//在类中用关键字friend声明某个外部函数或外部类是这个类的友元，
//则这个外部函数或外部类是可以直接访问这个类的private成员。
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
	friend void print(const Date& day); //外部函数print是Date类的友元
};
void print(const Date& day) { //print可以访问Date对象day的私有成员
	 std::cout << day.year << "-" << day.month << "-" << day.day << '\n';    
}
void print2(const Date& day) {//print2不能访问Date对象day的私有成员
	 std::cout << day.year<< "-" << day.month << "-" << day.day << '\n';    
}

#endif

#if 0
//和普通函数如果声明为内联（inline）函数可以提高程序效率一样，
//类的成员函数也可以是内联（inline）成员函数，
//如果一个类的成员函数就是在类体内实现的，这个函数自动就成为了内联成员函数，
//如果一个类的成员函数在体外实现的，则必须在类体内函数的声明前加关键字inline，
// 而类体外函数声明前不能加inline。
class X {
public:
	inline void f();
};
void X::f() {
	/*...*/
}
//在类体内声明了f()是内联成员函数，类体外函数声明前不能再有关键字inline。
#endif

#if 0
#define  _CRT_SECURE_NO_WARNINGS
//重定义拷贝构造函数和赋值运算符
//防止共用资源导致的问题“多次销毁。释放同一个资源”

#include <iostream>
#include <cstring>   //strlen()
class String {
	char* data{ nullptr };
	int size_{ 0 };
public:
	String() = default;
	String(const char* s) {
		auto len = strlen(s);
		data = new char[len + 1];  //分配一块存储字符的动态内存块
		if (!data) return;
		strcpy(data, s);         //拷贝字符串内容从s到data指向的空间
		size_ = len;
	}
	~String() {
		delete[] data;
	}
	auto size() { return size_; }
};

int main() {
	String s("hello world");
	String s2(s);    //调用拷贝构造函数，将s拷贝到新对象s2中

	String  s3;
	s3 = s;
}

#endif

#if 0
//解决的办法是重新定义拷贝构造函数和赋值运算符。
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>   //strlen()

#include <iostream>
#include <cstring>   //strlen()
class String {
	char* data{ nullptr };
	int size_{ 0 };
public:
	String() = default;
	String(const char* s) {
		auto len = strlen(s);
		data = new char[len + 1];  //分配一块存储字符的动态内存块
		if (!data) return;
		strcpy(data, s);         //拷贝字符串内容从s到data指向的空间
		size_ = len;
	}
	auto size() { return size_; }

	String(const String& s);
	String& operator=(const String& s);
};


String::String(const String& s) {
	std::cout << "拷贝构造函数:\n";  //仅仅用于输出是否进入该函数
	if (s.data == 0)return;
	if (this != &s) {
		data = new char[s.size_ + 1]; //申请一块自己专用的内存卡
		if (!data) return;
		size_ = s.size_;
		strcpy(data, s.data); //拷贝字符串内容
	}
}

String& String::operator=(const String& s) {
	if (this != &s) {
		std::cout << "赋值运算符:\n";  //仅仅用于输出是否进入该函数
		if (s.data == 0) return *this;
		data = new char[s.size_ + 1]; //申请一块自己专用的内存卡
		if (!data) return *this; 
		size_ = s.size_;
		strcpy(data, s.data); //拷贝字符串内容
	}
	return *this;
}

int main() {
	String s("hello world");
	String s2(s);    //调用拷贝构造函数，将s拷贝到新对象s2中

	String  s3;
	s3 = s;
}
#endif
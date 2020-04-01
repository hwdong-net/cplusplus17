
#if 0
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

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1;  //day和day1都用默认构造函数构成
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
	Date day;   //定义类对象时自动调用匹配的构造函数
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
	//Date day(2018, 8, 18),	       //定义类对象时自动调用匹配的构造函数
	//	day2{ 2019,6,1 };

	Date day;    //错：没有合适的默认构造函数可用
	Date day(2010, 1, 2, 3);  //错：没有重载函数接受 4 个参数

}

#endif 

#if 0
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
		day3{ 2019,13,8 };}

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

#endif 

#if 0
//初始化成员列表
//仍然按照数据成员在Date中定义的次序即year、month、day的次序依次初始化。
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
//	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}	
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
//拷贝构造函数
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	//	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){}
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
//拷贝构造函数的参数必须是引用
#if 0
class X {	
public:
	X() = default;
	X(X x) {}
};
int main() {
	X x;
	X y(x);
}
#else
class X {
public:
	X() = default;
	X(const X &x) {}
	X& operator=(const X& object);
};
int main() {
	X x;
	X y(x);
}
#endif

#endif 

#if 1
//拷贝构造函数
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){}
	Date(int y = 2000, int m = 1, int d = 1) : day(d), month(m), year{ y }{	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& operator=(const Date& date) {
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
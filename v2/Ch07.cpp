/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/


#if 0
#include <iostream>

class Point2 {
	int x,y;
	static inline const  Point2 O;// {0, 0};
public:
	Point2(const int x = O.x,const int y=O.y):x(x),y(y) {};
};

const Point2 Point2::O{0,0};
#endif 

#if 0
#include<iostream>
using namespace std;

class X {
	static int x;
	int *ptr;
	int y;
};

int main() {
	X t;
	cout << sizeof(t) << " ";
	cout << sizeof(X *);
}
#endif

#if 0
#include <iostream>

class A {
public:
	A(int x) { std::cout << "A:" << x << "构造对象\n"; }
};
int main() {
	A a(1), b{ 2 }, c = 3;
	return 0;
}
#endif

#if 1
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	//委托Date(int y=2000,int m=1,int d=1)构造函数  
	Date(int *p) :Date(p[0], p[1], p[2]) {	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	int date[]{ 2018,9,6 };
	Date d(date); d.print();
}


#endif 
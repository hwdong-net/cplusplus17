#if 0
#include <iostream>
using std::cout;
class Sprite {	
	double pos[2]{}, vel[2]{1.,1.};//位置pos和速度vel
public:
	Sprite(double *p=0,double *v=0) {
		if (p) { pos[0] = p[0]; pos[1] = p[1]; }
		if (v) { vel[0] = v[0]; vel[1] = v[1]; }
	}
	void update() { pos[0] += vel[0]; pos[1] += vel[1];	}
	void draw() {cout << "在("<< pos[0] << ',' << pos[1] << ")位置绘制精灵\n";
	}
};
class Ball :public Sprite {
	double radius{2.};
};

int main() {
	Ball ball;	
	ball.update();
	ball.draw();
}
#endif 

# if 0
#include <iostream>
using std::cout;
class Sprite {
protected:
	double pos[2]{}, vel[2]{ 1.,1. };//位置pos和速度vel
public:
	Sprite(double *p = 0, double *v = 0) {
		if (p) { pos[0] = p[0]; pos[1] = p[1]; }
		if (v) { vel[0] = v[0]; vel[1] = v[1]; }
	}
	void update() { pos[0] += vel[0]; pos[1] += vel[1]; }
	void draw() {
		cout << "在(" << pos[0] << ',' << pos[1] << ")位置绘制精灵\n";
	}
};
class Ball :public Sprite {
	double radius{ 2. };
public:
	void draw() {
		Sprite::draw(); // 调用基类Sprite的draw()方法
		cout << "绘制半径" << radius << "，圆心在("
			<< pos[0] << ',' << pos[1] << ")的圆\n";
	}
};
int main() {
	Ball ball;
	ball.update();
	ball.draw();
}
#endif

#if 0
#include <iostream>
using std::cout;
class Base {
protected:
	int value{0};
public:
	Base(int v=0) :value(v) {}	
	void print() { cout << value << '\n'; }
};
class Derived :public Base {
	double value{ 1.5};
public:	
	void print(bool base = false) { 
		if(base)
			cout << Base::value << '\t' << value << '\n';
		else 
			cout<< value << '\n';
	}
};

int main() {
	Base b;
	Derived d;
	b.print();
	d.print(true);
}
#endif 

#if 0
class B {
	//...
};
class D :B {
	//...
};
class D :private B {
	//...
};
#endif 

#if 0
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
	
public:
	B()  { cout << "B类拷贝构造函数\n"; }		
};
class D :public B {
	double d{ 2.5 };
public:
	D()  { cout << "D类拷贝构造函数\n"; }		
};
int main() {
	D d,d2(d);
}
#endif 


#if 0
#include <iostream>
#include <string>
using std::cout;
using std::string;
class B {
	int b{ 0 };
	string name{};
public:	
	B(const B& b):b(b.b),name(b.name) { cout << "B类拷贝构造函数\n"; }
	B(int b,string n):b(b),name(n) { cout << "B类构造函数\n"; }
	B() { cout << "B类默认构造函数\n"; }
//	~B() { cout << "B类析构函数\n"; }
	
};
class D :public B {
	double d{ 2.5 };
public:
//	D(const D& d) :d(d.d),B(d) { cout << "D类拷贝构造函数\n"; }
	D(const D& d){ cout << "D类拷贝构造函数\n"; }
	D(double d,int b,string n):B(b,n),d(d) { cout << "D类构造函数\n"; }
//	~D() { cout << "D类析构函数\n"; }
};
int main() {
	D d(3.0,2,"helo");
	std::cout << '\n';
	D d2(d);
	std::cout << '\n';
}
#endif


#if 0
#include <iostream>
class B {
	int b{0};
public:
	B(int b=0) :b(b) {}
	void print() { std::cout <<"B:"<< b; }
};
class D:public B {
	double d{ 2.5 };
public:
	D(double d=0) :d(d) {}
	void print() {
		std::cout << "D:";  
		B::print(); std::cout << d ; 
	}
};

#if 0
int main() {
	B b{ 1 };
	D d{3.14};
	b.print();  std::cout << '\n';
	d.print();  std::cout << '\n';
	b = d;
	b.print();  std::cout << '\n';
}

#else
int main() {	
	B b{ 1 };
	D d{ 3.14 };
	B *p = &b;
	p->print(); std::cout << '\n';
	p = &d;
	p->print(); std::cout << '\n';
	D *q = p; //错：基类指针不能自动隐含转换为派生类指针类型
	
	D *q = static_cast<D*>(p); //强制将B*转换为D*
	q = static_cast<D*>(&b);  //强制将B*转换为D*
}
#endif

#endif

#if 0

#if 0
#include <iostream>
using std::cout;
class B {
public:
	B() { cout << "B类默认构造函数\n"; }
	B(const B& b) { cout << "B类拷贝构造函数\n"; }
};
class D :public B {
public:
	D() { cout << "D类默认构造函数\n"; }
	D(const D& d) { cout << "D类拷贝构造函数\n"; }
};
int main() {
	D d, d2(d);
}
#else
#include <iostream>
using std::cout;
class B {
public:
	B() { cout << "B类默认构造函数\n"; }
	B(const B& b) { cout << "B类拷贝构造函数\n"; }
};
class D :public B {
public:
	D() { cout << "D类默认构造函数\n"; }
	D(const D& d) :B{d} { cout << "D类拷贝构造函数\n"; }
};
int main() {
	D d, d2(d);
}
#endif
#endif

#if 0
#include <iostream>
#include <string>
using std::cout;
using std::string;
class B {
	int b{ 0 };
	string name{};
public:
	B(const B& b) :b(b.b), name(b.name) { cout << "B类拷贝构造函数\n"; }
	B(int b, string n) :b(b), name(n) { cout << "B类构造函数\n"; }
};
class D :public B {
	double d{ 2.5 };
public:
	D(const D& d) :d(d.d), B(d) { cout << "D类拷贝构造函数\n"; }
	D(double d, int b, string n) :B(b, n), d(d) { cout << "D类构造函数\n"; }

};
int main() {
	D d(3.0, 2, "helo");
	std::cout << '\n';
	D d2(d);
	std::cout << '\n';
}
#endif 

#if 0
#include <iostream>
class Shape {
public:
	void draw() { std::cout << "绘制一般形状\n"; }
};
class Color {
	int color{ 0 };
public:
	int get_color() { return color; }
};
class Circle :public Shape, public Color {
public:
	void draw() { std::cout << "绘制三角形\n"; }
};

int main() {
	Circle c;
	std::cout << c.get_color() << '\n';
	c.draw();
	c.Shape::draw();
}

#endif 

#if 0
#include <iostream>
class Shape {	
public:
	void draw() { std::cout << "绘制形状\n"; }
};
class Color {
	int color{0};
public:	
	Color(int c) :color(c) {}
	int get_color() { return color; }
};
class Circle:public Shape,public Color {
public:	
	Circle(int color) :Color(color) {}
	void draw() { std::cout << "绘制三角形\n"; }
};

int main() {
	Circle c;
	std::cout << c.get_color() << '\n';
	c.draw();
	c.Shape::draw();
}
#endif 

#if 0
#include <iostream>
class USBDevice{
private:
	long m_id;
public:
	USBDevice(long id): m_id(id){}

	long getID() { return m_id; }};

class NetworkDevice{
private:
	long m_id;
public:
	NetworkDevice(long id): m_id(id){}
	long getID() { return m_id; }
};

class WirelessAdapter : public USBDevice, public NetworkDevice{
public:
	WirelessAdapter(long usbId, long networkId)
		: USBDevice(usbId), NetworkDevice(networkId)	{	}
};


int main(){
	WirelessAdapter c54G(5442, 181742);
	std::cout << c54G.getID(); // 调用哪一个getID()？
	return 0;
}

#endif

#if 0

#if 0
#include <iostream>
#include <string>
using namespace std;

class Person { //人
protected:
	string name{ "noname" };
};

class PartyMember :  public Person { //党员
protected:
	string party{ "RP" };
};
class Teacher :  public Person { //教师
protected:
	string title{ "RP" }; //职称
	string profession{ "CS" };// 专业
};

class TeacherPM :public Teacher, PartyMember {  //教师党员
};

int main() {
	Person p;
	PartyMember pm;
	Teacher t;
	TeacherPM tpm;
	string s{ "hello" };
	cout << sizeof(p) << '\n';
	cout << sizeof(p) << '\t' << sizeof(pm) << '\t' << sizeof(t) << '\t'
		<< sizeof(tpm) << '\n';
	return 0;
}

#else 

#include <iostream>
#include <string>
using namespace std;

class Person { //人
protected:
	string name{"noname"};
};

class PartyMember: virtual public Person{ //党员
protected:
	string party{ "RP" };
};
class Teacher : virtual public Person{ //教师
protected:
	string title{ "RP" }; //职称
	string profession{ "CS" };// 专业
};

class TeacherPM :public Teacher,PartyMember{  //教师党员
};

int main() {	
	Person p;
	PartyMember pm;
	Teacher t;
	TeacherPM tpm;
	string s{"hello"};
	cout << sizeof(p) << '\n';
	cout << sizeof(p) << '\t' << sizeof(pm) << '\t' << sizeof(t) << '\t'
		<< sizeof(tpm) << '\n';
	return 0;	
}
#endif 
#endif 

#if 0
class A{
	int i;
};
class B:virtual public A {
	int j;
}; 
class C :virtual public A {
	int k;
};
class D :public B,C {

};

int main() {
	A a; B b; C c; D d;
	cout << sizeof(a) << '\t' << sizeof(b) << '\t' << sizeof(c) << '\t'
		<< sizeof(d) << '\n';
}

#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\n'; }
};
class Student:public Person { //学生	
public:
	double score{ 0 };
	Student(string n,double s) :Person(n) ,score(s){}
	void print() { Person::print(); cout<<score << '\n'; }	
};

#if 0
int main() {
	Person p{ "Li Ping" };
	Student s{ "Zhang wei",60 };	
	p = s; //派生类对象可以赋值给基类对象，但产生了切割
	cout << p.score; //错：p时Person对象，没有score属性
	s = p;
}
#endif 
int main() {
	Person p{ "Li Ping" },*pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;       //派生类对象s的地址(指针)赋值给基类指针变量
	Person &r = s; //基类引用变量可以引用派生类对象
	pp->print();
	r.print();
	cout << '\n';
	Student *ps = static_cast<Student*>(pp); //将Person*强制转化为Student*
	ps->print();
	ps = static_cast<Student*>(&p);    //将Person*强制转化为Student*
	ps->print();
}
#endif 

#if 0
#include <iostream>
#include <string>
using namespace std;

class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print() { cout << name << '\n'; }
};
class Student :public Person { //学生	
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};
class Teacher :public Person { //学生	
public:
	string title{"讲师"}; //职称
	Teacher(string n, string t):Person(n), title(t) {}
	void print() { Person::print(); cout << title << '\n'; }
};

class Staff :public Person { //学生	
public:
	string positon{ "讲师" }; //职务
	Staff(string n, string p) :Person(n), positon(p) {}
	void print() { Person::print(); cout << positon << '\n'; }
};

/*
class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print();
};
void Person::print() { cout << name << '\n'; }
*/

int main() {
	Person p{ "Li Ping" }, *pp = &p; //pp指向了Person对象
	Student s{ "Zhang wei",60 };
	Teacher t{ "王强","教授" };
	pp->print();   //调用的是Person的print()
	cout << '\n';
	pp = &s;       //pp指向了Student对象
	pp->print();  //调用的是Student的print()
	cout << '\n';
	pp = &t;        //pp指向了Teacher对象
	pp->print();	   //调用的是Teacher的print()
	cout << '\n';

	Person &r = s; //基类引用变量可以引用派生类对象
	r.print();
}



#endif 

#if 0
#include <iostream>
class B {
public:
	virtual B& f() { return *this; }
	virtual int g() { std::cout << "g\n"; return 0; }
};
class D:public B {
public:
	D& f() { return *this; }
	int g( ) { std::cout << "g\n";  }
};

#endif 

#if 0
#include <iostream>
class B {
public:
	virtual B& f() { return *this; }
	virtual void  g(int) { std::cout << "g in B\n"; }
};
class D :public B {
public:
	D& f() { return *this; }
	void g() { std::cout << "g in D\n"; }
};

int main() {
	D d;
	B *p = &d;
	p->f();
	d.g();
	p->g(0);
}
#endif 

#if 0
class X {
public:
	virtual void  print() { }
	
};
class Y final :public X {
public:
	virtual void  print() override { }
};
#endif 

#if 0
#include <iostream>
#include <string>
using namespace std;
class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print() { cout << name << '\t'; }
	virtual ~Person() { cout<<"Person的析构函数\n";	}
};
class Student :public Person { //学生	
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
	~Student() { cout <<"Student的析构函数\n"; }
};
class Teacher :public Person { //学生	
public:
	string title{ "讲师" }; //职称
	Teacher(string n, string t) :Person(n), title(t) {}
	void print() { Person::print(); cout << title << '\n'; }
	~Teacher() { cout << "Teacher的析构函数\n"; }
};

class Staff :public Person { //学生	
public:
	string positon{ "秘书" }; //职务
	Staff(string n, string p) :Person(n), positon(p) {}
	void print() { Person::print(); cout << positon << '\n'; }
};

int main() {
	Person* arr[5];
	int n = 0;
	arr[0] = new Teacher("Li Ping","讲师");
	arr[1] = new Teacher("张伟", "教授");
	arr[2] = new Student("王 浩", 70.5);
	n = 3;
	for (auto i = 0; i != n; i++)
		arr[i]->print();
	for (auto i = 0; i != n; i++) delete arr[i];	
}
#endif 
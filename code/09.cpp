#if 0
//Dog（狗）是一种特殊的Animal（动物）
//一个Dog具有Animal的所有属性，但还有Dog特有的属性，比如狗喜欢刨骨头或啃骨头。
//独立类：代码重复

class Animal
{
	//...
	void run() {/*...*/}
};
class Dog
{
	//...
	void run() {/*...*/ }
	void eat_bone() {/*...*/ }
};
#endif

#if 0
//Dog类继承Animal类，Animail类称为基类，Dog类称为派生类
class Animal
{
	//...
	void run() {/*...*/ }
};
class Dog:public Animal
{
	//...
	//void run() {/*...*/ }
	void eat_bone() {/*...*/ }
};
#endif

#if 0
//派生类的定义:
class 派生类名 : public 基类名
{
	//派生类成员(数据成员和成员函数)
};
#endif


#if 0
//Sprite：表示游戏中所有的精灵的共性
#include <iostream>
using std::cout;
class Sprite {
	double pos[2]{}, vel[2]{ 1.,1. };    //位置pos和速度vel
public:
	Sprite(double* p = 0, double* v = 0) {
		if (p) { pos[0] = p[0]; pos[1] = p[1]; }
		if (v) { vel[0] = v[0]; vel[1] = v[1]; }
	}
	void update() { pos[0] += vel[0]; pos[1] += vel[1]; }  //根据速度更新位置
	void draw() {
		cout << "在(" << pos[0] << ',' << pos[1] << ")位置绘制精灵\n";
	}
};

//Ball(球)是一个特殊的精灵
class Ball : public Sprite {
	double radius{ 1. };
public:
#if 0
	Ball(double x, double y, double vx, double vy, double r)
	{
		pos[0] = x;
	}
#endif
};

//Paddle(球拍)是一个特殊的精灵
class Paddle : public Sprite {
	double width,height;
public:
	Paddle(double w, double h) :width(w), height(h) {}	
};

int main() {
	Ball ball;
	ball.update();
	ball.draw();
	Paddle paddle1(2,5), paddle2(2,5);
	paddle1.update(); paddle2.update();
	paddle1.draw(); paddle2.draw();
}
#endif

#if 0
class Ball : public Sprite {
	double radius{ 1. };
public:
	void draw() {		
		cout << "绘制半径" << radius << "，圆心在("
			<< pos[0] << ',' << pos[1] << ")的圆\n";
	}
};
#endif

#if 0
#include <iostream>
using std::cout;
class Sprite {
protected://保护成员
	double pos[2]{}, vel[2]{ 1.,1. };    //位置pos和速度vel
public:
	Sprite(double* p = 0, double* v = 0) {
		if (p) { pos[0] = p[0]; pos[1] = p[1]; }
		if (v) { vel[0] = v[0]; vel[1] = v[1]; }
	}
	void update() { pos[0] += vel[0]; pos[1] += vel[1]; }  //根据速度更新位置
	void draw() {
		cout << "在(" << pos[0] << ',' << pos[1] << ")位置绘制精灵\n";
	}
};

class Ball : public Sprite {
	double radius{ 1. };
public:
	void draw() {
		cout << "绘制半径" << radius << "，圆心在("
			<< pos[0] << ',' << pos[1] << ")的圆\n";
	}
};
// 派生类访问基类的hide成员，用基类作用域
class Paddle : public Sprite {
	double width, height;
public:
	Paddle(double w, double h) :width(w), height(h) {}
	void draw() {
		Sprite::draw();
		cout << "绘制宽高为" << width << ',' << height << "的球拍\n";
	}
};
int main() {
	Ball ball;
	ball.update();
	ball.draw();
	Paddle paddle1(2, 5), paddle2(2, 5);
	paddle1.update(); paddle2.update();
	paddle1.draw(); paddle2.draw();
}

#endif

#if 0
//------------继承方式--------------
//一个类通过private、protected、public关键字修饰成员，控制成员对外界的可见性。
//关键字private、protected、public也可以用于定义派生类从基类的继承方式，即控制基类成员在派生类的可见性。
class B {
};
class D1 : public B{
	//...
};
class D2 : protected B {
	//...
};
class D3 : private B {
	//...
};

//用 class定义一个派生类时，如果没有指明派生方式，则默认是 private继承方式。
class D :  B    //等价于class D : private B 
{
	//...
};

//基类成员在派生类中的访问可见性
#endif

#if 0
//派生类对象也是一种特殊的基类对象
//Dog是一个Animal
//可以将一个派生类对象当成一个基类对象使用
#include <iostream>
class B {
	int b{ 0 };
public:
	B(int b = 0) :b(b) {}
	void print() { std::cout << "B:" << b; }
};
class D :public B {
	double d{ 2.5 };
public:
	D(double d = 0) :d(d) {}
	void print() {
		std::cout << "D:";
		B::print(); std::cout << '\t' << d;
	}
};

int main() {
	B b{ 1 };
	D d{ 3.14 };
	b.print();  std::cout << '\n';
	d.print();  std::cout << '\n';
	b = d;
	b.print();  std::cout << '\n';
}
#endif


#if 0
//基类指针和派生类指针
//避免“对象被切割”的更好的方法是用基类指针指向派生类对象，或者说将派生类指针赋值给基类指针变量。
#include <iostream>
class B {
	int b{ 0 };
public:
	B(int b = 0) :b(b) {}
	void print() { std::cout << "B:" << b; }
};
class D :public B {
	double d{ 2.5 };
public:
	D(double d = 0) :d(d) {}
	void print() {
		std::cout << "D:";
		B::print(); std::cout << '\t' << d;
	}
};

#if 1
int main() {
	B b{ 1 };
	D d{ 3.14 };
	B* p = &b;            //基类指针p指向基类对象b
	p->print(); std::cout << '\n';
	p = &d;               //基类指针p指向派生类对象d
	p->print(); std::cout << '\n';
}
#endif

#if 0
//基类指针强制类型转换为派生类指针
int main() {
	B b{ 1 };
	D d{ 3.14 };
	B* p = &b;            //基类指针p指向基类对象b
	p->print(); std::cout << '\n';
	p = &d;               //基类指针p指向派生类对象d
	((D*)p)->print(); std::cout << '\n';
	(static_cast<D*>(p))->print(); std::cout << '\n';	
}
#endif
#endif 

#if 0
//----------派生类的构造函数---------
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
public:
	B() { cout << "B类构造函数\n"; }
};
class D :public B {
	double d{ 2.5 };
public:
	D() { cout << "D类构造函数\n"; }
};
int main() {
	D d;
}
//先调用基类构造函数构造派生类对象的基类部分
//再调用派生类构造函数，初始化派生类部分
#endif

#if 0
//--------派生类的析构函数----------
//在销毁一个对象时，却是反其道而行，
//即先执行派生类自己的析构函数，然后是其上层的基类的析构函数，直到最上层基类的析构函数。
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
public:
	B() { cout << "B类构造函数\n"; }
	~B() { cout << "B类析构函数\n"; }

};
class D :public B {
	double d{ 2.5 };
public:
	D() { cout << "D类构造函数\n"; }
	~D() { cout << "D类析构函数\n"; }
};
int main() {
	D d;
}
#endif 

#if 0
//---------在派生类的初始化成员列表里调用基类的其他构造函数-----------
//派生类的构造函数调用的是基类默认的构造函数，
//也可以在派生类的初始化成员列表里调用基类的其他构造函数。
#include <iostream>
using std::cout;
class B {
	int b{ 0 };
public:
	B() { cout << "B类默认构造函数\n"; }
	B(int b) :b(b) { cout << "B类构造函数\n"; }
	~B() { cout << "B类析构函数\n"; }
};
class D :public B {
	double d{ 2.5 };
public:
	D() :B(2) { cout << "D类默认构造函数\n"; }  //在初始化成员列表里调用基类构造函数
	~D() { cout << "D类析构函数\n"; }
};
int main() {
	D d;
}


#endif 

#if 0
//------ 调用基类构造函数必须提供相应的参数----------
//必须在初始化成员列表中显式调用基类构造函数并提供必须的参数。
//因此，基类构造函数需要的参数通常应该在派生类的构造函数的形参列表中出现。
#include <iostream>
#include <string>
using std::cout;
using std::string;
class B {
	int b{ 0 };
	string name{};
public:
	B(int b, string n) :b(b), name(n) {
		cout << "B类构造函数\n"; }
	~B() { cout << "B类析构函数\n"; }

};
class D :public B {
	double d{ 2.5 };
public:
	D():B(2,"hello") { cout << "D类默认构造函数\n"; }
	D(double d, int i, string s) :B(i, s), d(d) {}
	~D() { cout << "D类析构函数\n"; }
};
int main() {
	D d;
}

// D(double d,int b,string n):B(b,n),d(d) {
//     cout << "D类构造函数\n"; }
// D():B(2,"name"),d(d) { cout << "D类默认构造函数\n"; }
#endif

#if  0
//------注意：派生类的拷贝构造函数调用基类的默认构造函数而不是拷贝构造函数--
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
#endif

#if 0
//解决办法是在派生类拷贝构造函数的初始化成员列表里调用基类的拷贝构造函数。
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
	D(const D& d) :B{ d }  //在初始化成员列表里调用基类的拷贝构造函数
	{
		cout << "D类拷贝构造函数\n";
	}
};
int main() {
	D d, d2(d);
}

#else

//下面的代码假设B和D都有一些成员变量。
//派生类的拷贝构造函数的初始化成员列表中同样调用了基类的拷贝构造函数。
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
#endif 

#if 0
//-------多继承-------
//从多个直接基类定义一个派生类，或者说一个类可以继承多个基类，
//这种继承方式称为多继承（Multiple Inheritance）。

class A {
	/*...*/
};
class B {
	/*...*/
};
class C {
	/*...*/
};
class D : public A, protected B, private C {
	//…D类的成员
};
//D分别以public、protected、private等不同继承方式继承了基类A、B、C的属性。


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
	void draw() { std::cout << "绘制圆\n"; }
};

int main() {
	Circle c;
	std::cout << c.get_color() << '\n';
	c.draw();
}

#endif 

#if 0
//--------多继承的二义性问题-----------
//如果一个派生类的不同基类包含了同名的数据成员或同样签名的函数成员，
//当通过该派生类对象访问这个成员时，可能会产生二义性问题。
#include <iostream>
class USBDevice {
private:
	long m_id;
public:
	USBDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
};

class NetworkDevice {
private:
	long m_id;
public:
	NetworkDevice(long id) : m_id(id) {}
	long getID() { return m_id; }
};

class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
	WirelessAdapter(long usbId, long networkId)
		: USBDevice(usbId), NetworkDevice(networkId) {	}
};
int main() {
	WirelessAdapter  wa(5442, 181742);
	std::cout << wa.getID(); // 调用哪一个getID()？
	return 0;
}

//如何解决？
#endif

#if 0
//------------虚基类----------

#include <iostream>
#include <string>
using namespace std;
class Person { //人
protected:
	string name{ "noname" };
};

#if 0
//多继承时可能一个派生类对象中有多份间接基类对象
class PartyMember : public Person { //党员
protected:
	string party{ "RP" };
};

class Teacher : public Person { //教师
protected:
	string title{ "TA" }; //职称
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
	cout << sizeof(p) << '\t' << sizeof(pm) << '\t' << sizeof(t) << '\t'
		<< sizeof(tpm) << '\n';
	return 0;
}

#else
//为了避免这种间接基类对象在派生类中出现多个副本。
// 可以在定义派生类时，声明继承的基类为虚基类
class PartyMember : virtual public Person { //党员
protected:
	string party{ "RP" };
};
class Teacher : virtual public Person { //教师
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
	cout << sizeof(p) << '\t' << sizeof(pm) << '\t' << sizeof(t) << '\t'
		<< sizeof(tpm) << '\n';
	return 0;
}

#endif
#endif


#if 0
//-------派生类对象也是基本对象-----
// 但派生类对象赋值给基类对象，会产生“切割问题”
#include <string>
#include <iostream>
using namespace std;

class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\t'; }
};
class Student :public Person { //学生
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};
int main() {
	Person p{ "Li Ping" };
	Student s{ "Zhang wei",60 };
	p = s;            //派生类对象可以赋值给基类对象，但产生了切割
	cout << p.score;    //错：p是Person对象，没有score属性
	s = p;            //错：不能将Person对象赋值给Student对象
}

#endif

#if  0
//---------指针的向上类型转换-----------
//派生类指针可以隐含转化为基类指针
#include <string>
#include <iostream>
using namespace std;

class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\t'; }
};
class Student :public Person { //学生
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};


#if 0
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;          //派生类对象s的地址(指针)赋值给基类指针变量
	Person& r = s;     //基类引用变量可以引用派生类对象
	pp->print();
	r.print();
}

#else

//但通过它们调用的print()函数仍然是基类而不是派生类的print()函数。
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;          //派生类对象s的地址(指针)赋值给基类指针变量
	Person& r = s;     //基类引用变量可以引用派生类对象
	pp->print();
	r.print();

	Student* ps = static_cast<Student*>(pp);     //将Person*强制转化为Student*
	ps->print();
	ps = static_cast<Student*>(&p);             //将Person*强制转化为Student*
	ps->print();
}
#endif

#endif 

#if 0
//---------static_cast<>只能用于相关类型的强制类型转换-------------
//static_cast<>只能用于相关类型，如具有继承和派生关系的指针（或引用）类型之间的强制类型转换，
//2个不同类型指针（或引用）如D* 和X* 之间是不能用static_cast<>强制类型转换的，
#include <iostream>
struct B {
	int m = 0;
	void print() const { std::cout << "Hi, this is B!\n"; }
};
struct D : B {
	void print() const { std::cout << "Hi, this is D!\n"; }
};
class X {};
int main() {
	int n = static_cast<int>(3.14);     //基本类型之间的static_cast
	D d;
	B& br = d;      // 向上类型转换：派生类引用可以自动隐含转换为基类引用
				 //也可以用static_cast<>： B& br = static_cast<B&>d;
	br.print();
	D& dr = static_cast<D&>(br);    // 向下类型转换(downcast)
	dr.print();

	D* dp = new D;
	B* bp = dp;       // 向上类型转换：派生类指针可以自动隐含转换为基类指针
				   // 也可以用static_cast<>： B*bp = static_cast<B*>d;
	D* dp2 = static_cast<D*>(bp); // this works
	X* xp = static_cast<X*>(dp);    // 编译错误：无法从“D *”转换为“X *”

	void* p = dp; //任何指针都可以转化为void*
	D* dp3 = static_cast<D*>(p);  //将void*强制转化为D*。
	return 0;
}

#endif 


//==============9.4 多态(Polymorphism)==================


#if 0
#include <string>
#include <iostream>
using namespace std;
class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	void print() { cout << name << '\n'; }
};
class Student :public Person { //学生
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
};

//-----------派生类对象也是基类对象----------------
#if 0
int main() {
	Person p{ "Li Ping" };
	Student s{ "Zhang wei",60 };
	p = s;            //派生类对象可以赋值给基类对象，但产生了切割
	cout << p.score;    //错：p是Person对象，没有score属性
	s = p;            //错：不能将Persion对象赋值给Student对象
}
#endif 

//-------- 基类指针（引用）和向下类型转换------
#if 0
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;        //派生类对象s的地址(指针)赋值给基类指针变量
	Person& r = s;  //基类引用变量可以引用派生类对象
	pp->print();
	r.print();
}
#endif

#if 0
int main() {
	Person p{ "Li Ping" }, * pp = &p;
	Student s{ "Zhang wei",60 };
	pp = &s;        //派生类对象s的地址(指针)赋值给基类指针变量
	Person& r = s;  //基类引用变量可以引用派生类对象
	pp->print();
	r.print();
	Student* ps = static_cast<Student*>(pp);     //将Person*强制转化为Student*
	ps->print();
	ps = static_cast<Student*>(&p);             //将Person*强制转化为Student*
	ps->print();
}
#endif 

#endif 


//-----------虚函数和多态----------------

#if 0
#include <string>
#include <iostream>
using namespace std;

//将前面的Person的print()函数定义为虚函数：
class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print() { cout << name << '\t'; }
	virtual ~Person() { cout << "Person的析构函数\n"; }
};

//只要在基类中用关键字virtual声明了虚函数，
// 派生类中这个虚函数前可加可不加virtual关键字，这个函数都是虚函数。
class Teacher :public Person { //学生	
public:
	string title{ "讲师" }; //职称
	Teacher(string n, string t) :Person(n), title(t) {}
	void print() { Person::print(); cout << title << '\n'; }
	virtual ~Teacher() { cout << "Teacher的析构函数\n"; }
	
};

class Student :public Person { //学生
public:
	double score{ 0 };
	Student(string n, double s) :Person(n), score(s) {}
	void print() { Person::print(); cout << score << '\n'; }
	virtual  ~Student() { cout << "Student的析构函数\n"; }
};

#if  1
int main() {
	Person p{ "Li Ping" }, *pp = &p; //pp指向了Person对象
	Student s{ "Zhang wei",60 };
	Teacher t{ "王强","教授" };
	pp->print();         //调用的是Person的print()
	cout << '\n';
	pp = &s;           //pp指向了Student对象
	pp->print();        //调用的是Student的print()
	cout << '\n';
	pp = &t;          //pp指向了Teacher对象
	pp->print();	   //调用的是Teacher的print()
	cout << '\n';
	Person& r = s; //基类引用变量可以引用派生类对象
	r.print();
}

#endif

#if 0
int main() {
	Person* arr[5];
	int n = 0;
	arr[0] = new Teacher("Li Ping", "讲师");
	arr[1] = new Teacher("张伟", "教授");
	arr[2] = new Student("王 浩", 70.5);
	n = 3;
	for (auto i = 0; i != n; i++)
		arr[i]->print();
	
	for (auto i = 0; i != n; i++) 
		delete arr[i];

}
#endif

#endif 

#if 0
//--------dynamic_cast----
// dynamic_cast<>主要用于具有多态性的层次继承结构的类之间的指针（或引用）的向上、向下和侧向转换。
//它是在程序运行期间根据指针（或引用）指向（或引用）的对象的实际类型确定
// 是否能安全地进行指针（或引用）类型的转换。其格式是：
/*
	dynamic_cast<Type*>(p)
	dynamic_cast<Type&>(r)
*/
//即在运行时，将指针p（或引用r）转换为类型Type* （或Type& ）。
//如果不能进行类型转换，对于指针，返回空指针，对于引用，则抛出一个异常（错误）。


//dynamic_cast<>主要用于将一个基类指针（或引用）转换为一个派生类的指针（或引用），即向下类型转换（downcasting）。
//向上类型转换（upcasting）可以使用也可以不使用dynamic_cast。
#if 1
#include <iostream>
using std::cout;
struct Base {
	virtual ~Base() {}
};

struct Derived : Base {
	virtual void name() {}
};
int main() {
	Base* b1 = new Base;
	if (Derived * d = dynamic_cast<Derived*>(b1)) {
		std::cout << "downcast from b1 to d successful\n";
		d->name(); // safe to call
	}

	Base* b2 = new Derived;
	if (Derived * d = dynamic_cast<Derived*>(b2)) {
		std::cout << "downcast from b2 to d successful\n";
		d->name(); // safe to call
	}

	delete b1;
	delete b2;
}

#else
#include <iostream> 
struct V {
	virtual void f() {};       //必须是多态的才能使用运行时检查的dynamic_cast
};
struct A : virtual V {};
struct B : virtual V {
	B(V* v, A* a) {
		// 构造过程中的类型转换(看下面D的构造函数的调用)
		dynamic_cast<B*>(v);   // 没问题： v的类型是 V*, 而V是B的基类，v可以转化为B*类型
		dynamic_cast<B*>(a);   // 不可预知：undefined behavior: a的类型是A*，
		                       // 但A不是B的基类
	}
};
struct D : A, B {
	D() : B(static_cast<A*>(this), this) { }
};
int main() {
	D d;
	A& ra = d; // 向上类型转换：派生类引用转化为基类引用。可以使用也可以不使用dynamic_cast
	D& rd = dynamic_cast<D&>(ra); // 向下类型转换：基类引用转化为派生类引用
	B& rb = dynamic_cast<B&>(ra); // 侧向类型转换：从A&转换为B&
	A a;
	D& rda = dynamic_cast<D&>(a); //运行时错误：因为实际对象a不是D类型
	B& rba = dynamic_cast<B&>(a); //运行时错误：因为实际对象a不是B类型
}

#endif

#endif 


#if 0
//--------类体外定义虚函数-------------
/*
* 和inline内联成员函数一样，
类体外定义的虚函数不能有关键字virtual，
且必须在类体里的函数声明前添加关键字virtual。
*/
#include <string>
#include <iostream>
using namespace std;
class Person { //人
protected:
	string name{ "noname" };
public:
	Person(string n) :name(n) {}
	virtual void print();       //类体里的函数声明前的virtual关键字
};
//类体外的函数定义前不能有virtual关键字
void Person::print() { cout << name << '\n'; }  

#endif 


#if 0
//----------- 虚函数的签名和返回类型------------
/*
* 函数的签名是指函数名、形参列表和函数的修饰符如const。
派生类和基类的虚函数的签名必须相同。
此外，派生类的虚函数的返回类型要么相同要么是该类的指针或引用类型。
*/
#if 0
#include <iostream>
class B {
public:
	virtual B& f() { return *this; }
	virtual int g() { std::cout << "g\n"; return 0; }
};
class D :public B {
public:
	D& f() { return *this; }
	double g() { std::cout << "g\n"; return 0.; }
};
#endif

#if 1
//假如D里的g()和B里的g()的函数签名不同，它们就不是同一个虚函数了
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
	B* p = &d;
	p->f();
	d.g();
	p->g(); //基类指针p调用派生类的g()是错误的，因为该函数不是虚函数
}

#endif

#endif 

#if 0
//-------override---------
// 在派生类的虚函数签名后添加override关键字，说明这是一个从基类继承下来的虚函数，
// 编译器会检查基类是否有这个虚函数，如果没有就会报告错误。
//
class X {
public:
	virtual void  print() { }
};
class Y :public X {
public:
	virtual void  Print() override
	{}
};

#endif 


#if 1
//--------final ----------
/*
* 虚函数签名后添加final关键字。表示虚函数的继承到此为止，
* 其派生类不能再定义或继承该虚函数了。
*/

class Y :public X {
public:
	//final 表示Y类的派生类不能再有print()虚函数。
	virtual void print() override final 
	{ }
};

//类名后用关键字final将一个类定义为final类（最终类），
// 即不能再从这个类定义任何派生类。
//final 表示不能从Y类定义派生类，或者说任何类不能将Y作为基类。
class Y final :public X {
public:
	virtual void  print() override { }
};

#endif 


#if 1
//---------虚析构函数-----------
//析构函数应该定义为虚函数

#endif 
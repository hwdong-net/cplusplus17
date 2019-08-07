/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include <iostream>

#if 0
int do_task(){
	// ...
	if (正常处理了某些工作)
		return result;  //返回结果
	else
		throw Some_error{}; //抛出错误
}

void taskmaster()
{
	try {
		auto result = do_task();
		// 使用返回的结果 result
	}
	catch (Some_error) {
		//  do_task发生了某种异常: 处理这个异常
	}
}


try {
	f();
}
catch (const std::overflow_error& e) {
	// 如果f()抛出(throw)的是std::overflow_error对象（相同类型）
}
catch (const std::runtime_error& e) {
	//如果f()抛出(throw)的是std::underflow_error (基类规则)
}
catch (const std::exception& e) {
	//如果f()抛出(throw)的是std::logic_error (基类规则)
}
catch (...) {
	// 不管 f()抛出的是声明类型的异常
}

#endif 

#if 0
#include <iostream>
#include <string>

class MyError{
};

void g() {
	auto i{0};
	std::cin >> i;
	if (i == 0) 
		throw std::string("I am zero");
	else if (i < 0) 
		throw MyError();
	else if (i ==1)
		throw std::exception();
}

void f() {
	auto j{ 3 };
	j++;
	try {
		g();
	}
	catch (std::string &e) {
		std::cout << e << '\n';
	}
	catch (MyError ) {
		std::cout << "MyError" << '\n';
	}
	catch (...) {
		std::cout << "任何类型的异常" << '\n';
	}
}

int main() {
	f();
}
#endif

#if 0
#include <iostream>
#include <string>

class MyError {
};

void g3() {
	auto i{ 0 };
	std::cin >> i;
	try {
		auto d{ 0. };
		if (i == 0)
			throw "I am zero";
		else if (i < 0)
			throw MyError();
		else if (i == 1)
			throw std::exception();
		else if (i == 3)
			throw i;
		std::cout << i * i << '\n';
	}
	catch (int &e) {
		std::cout << e++ << '\t'<<e<<'\n';
	}
	std::cout<<i<<'\n';
}

void g2() {
	auto j{ 3 };
	j++;
	try {
		g3();
	}
	catch(MyError e) {
		std::cout<<"MyError"<< '\n';
	}
	j *= 3;
	std::cout << j << '\n';
}

void g1() {
	//...
	try {

	}
	catch (const char *s) {
		std::cout << s << '\n';
		throw std::string(s);
	}
	//...
}
void main() {
	//...
	try {

	}
	catch (std::string s) {
		std::cout << s << '\n';
	}
	//...
}

#endif

#if 0
#include <mutex>
#include <iostream>
#include <string> 
#include <fstream>
#include <stdexcept>

#if 0
void write_to_file(const std::string & message) {
	// 用于保护文件访问的互斥锁（跨线程共享）mutex
	static std::mutex mutex;

	// 在访问文件之前锁定互斥锁mutex
	std::lock_guard<std::mutex> lock(mutex);

	// 试图打开文件
	std::ofstream file("example.txt");
	if (!file.is_open())
		throw std::runtime_error("unable to open file");
	
	file << message << std::endl; // 像文件中写信息

	//无论是否发生异常，文件将在离开范围时被关闭，
	//互斥锁mutex将被解锁（lock的析构函数）	
}
#endif

// 用于保护文件访问的互斥锁（跨线程共享）mutex
static std::mutex mutex;
void write_to_file(const std::string & message) {

	mutex.lock();

	// 试图打开文件
	std::ofstream file("example.txt");
	if (!file.is_open())
		throw std::runtime_error("unable to open file");

	file << message << std::endl; // 像文件中写信息

	//无论是否发生异常，文件将在离开范围时被关闭，
	mutex.unlock(); //异常发生时，无法到达这一句，因此，mutex无法解锁
}

#endif 

#if 0
auto get_scores(){
	auto p = new double[100];
	if (!p) throw "没有足够的内存";
	for (auto i = 0; i != 100; i++) {
		auto score{0.};
		std::cin >> score;
		if (score < 0) throw "输入了一个负的分数！";
		else p[i] = score;
	}
	return p;
	
}

void fun() {	
	try {
		auto scores = get_scores();
		delete[] scores; // 可能不会到达这一句，引起内存泄漏 memory leak!
	}
	catch (const char *e) {
		std::cout << e << "\n";
	}
}

int main() {
	fun();
	//...
}
#endif 

#if 0
//禁止拷贝和赋值:防止资源被共享
class NonCopyable{
	NonCopyable(NonCopyable const &) = delete; // private copy constructor
	NonCopyable & operator= (NonCopyable const &) = delete; // private assignment operator
public:
	NonCopyable(){}
};

template <class T>
class WrapPtr{ // : NonCopyable{
	//禁止拷贝和赋值:防止资源被共享
	WrapPtr(WrapPtr const &) = delete; // private copy constructor
	WrapPtr & operator= (WrapPtr const &) = delete; // private assignment operator
public:

	WrapPtr(T * p = 0) : ptr_(p) {}
	~WrapPtr() throw() { std::cout << "释放指针"; delete ptr_; }
	// Array subscript operator
	T& operator[](size_t index) noexcept { return ptr_[index]; }
	const T& operator[](size_t index) const noexcept { return ptr_[index]; }
	T *get_data()const noexcept { return ptr_; }
private:
	T *ptr_;
};

auto get_scores() {
	auto p = new double[100];
	if (!p) throw "没有足够的内存";

	WrapPtr wp(p);
	for (auto i = 0; i != 100; i++) {
		auto score{ 0. };
		std::cin >> score;
		if (score < 0) throw "输入了一个负的分数！";
		else wp[i] = score;
	}
	return wp.get_data();

}

void fun() {
	try {
		auto scores = get_scores();	
	}
	catch (const char *e) {
		std::cout << e << "\n";
	}
}

int main() {
	fun();
	//...
}
#endif

#if 0
int main() {
	auto *p{ new int }, *q{ new int[3] };//p、q指向动态分配内存
	auto i{ 3 };
	p = &i;   //p也可以指向一个自动变量
	delete q; //错：只释放了q指向的3个int的第1个int内存。
	q = 0;
	delete p; //错：p指向的不是动态内存
	
	p = new int;
	q = p;
	delete p; p = 0;
	auto j{ *q };

}
#endif 


# if 0
#include <memory>
#include <iostream>

void f() {
# if 0
	std::unique_ptr<double> p{ new double{0.} };
	*p = 3.14;
	std::cout <<*p << '\t';
	double *rp = p.get();
	*rp = 3.1415;
	std::cout << *(p.get()) << '\n';
	
	std::cout << p.get() << '\t';
	p.reset(new double);
	std::cout << p.get() << '\n';
	
	p.reset();
	std::cout << p.get() << '\n';

	p.reset(new double);
	double* rawp = p.release();	
	*rawp = 3.0;
	std::cout << p.get() << '\n';

#endif

#if 0
	std::unique_ptr<char[]> p(new char[5]);
	p[0] = 'A'; p[1] = 'B'; p[2] = 'C';
	for (auto i = 0; i != 3; i++)
		std::cout << p[i];
	std::cout << std::endl;
#endif 

#if 0
	auto q = std::make_unique<double>(3.14);
	std::cout << *q << '\n';
	auto p = std::make_unique<double[]>(3); //分配3个double元素的动态空间
	p[0] = 'A'; p[1] = 'B'; p[2] = 'C';
	for (auto i = 0; i != 3; i++)
		std::cout << p[i];
	std::cout << std::endl;
	
#endif 

#if 0
	auto p = std::make_unique<double>(3.14);
	auto q{ p }; //错：不能拷贝构造
	std::unique_ptr<double> r{};
	r = p;    //错：不能赋值
#endif 
}
#endif 



#if 0
std::unique_ptr<int> get_unique() {
	auto ptr = std::unique_ptr<int>{ new int{2} }; 
	return ptr; // ptr被move（移动）到临时的返回结果中
}


void f() {
	//...
	auto uptr = get_unique(); // get_unique()的返回值被move(移动)到uptr中
	//...
}
#endif 

#if 0
std::unique_ptr<int> get_unique() {
	auto ptr = std::unique_ptr<int>{ new int{2} };
	return ptr; // ptr被move（移动）到临时的返回结果中
}



void fun(std::unique_ptr<int> p)
{
	// ...
}

int main()
{
	std::unique_ptr<int> p = get_unique();
	fun(p); // 错：左值不能隐含地调用move构造函数
	fun(std::move(p)); // 可以！用std::move()将左值转换为右值引用
	return 0;
}
#endif 

#if 0

#include <iostream>
#include <memory>
#include <string>
int main() {
	auto ptr = std::make_shared<std::string>("hello");
	*ptr = "world";
	std::cout << *ptr << '\t' << ptr.use_count()<< '\n';
	auto ptr2 = ptr;  //引用计数变为2
	*ptr2 = "hello world";
	std::cout << *ptr << '\t' << ptr.use_count() << '\n';
	ptr2.reset(new std::string{"wang"}); //释放原来的raw指针，指向新的string对象
	std::cout << *ptr << '\t' << ptr.use_count() << '\n';
	ptr.reset();
	std::cout << ptr.use_count() << '\n';
}

#endif 


#if 0
#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
	std::cout << "use_count == " << gw.use_count() << ": ";
	if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
		std::cout << *spt << "\n";
	}
	else {
		std::cout << "gw is expired\n";
	}
}

int main(){
	{
		auto sp = std::make_shared<int>(42);
		gw = sp;

		observe();
	}

	observe();
}
#endif 

#if 0
(a)std::range_error r("error");
throw r;
(b)std::exception *p = &r;
throw *p;

void f(int *b, int *e){
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	// 假如这里出现了异常
}


(a) class exceptionType { };
catch (exceptionType *pet) {}
(b) catch (...) {}
(c) typedef int EXCPTYPE;
catch (EXCPTYPE) {}

a) catch
b) handlers
c) throw
d) none of the mentioned

a. catch (.., )
b. catch (-- - )
c. catch (…)
d. catch (void x)

a.Try
b. catch
c.Finally
d.None of these
#endif 

#if 0
#include <iostream>
using namespace std;

int main(){
	try	{
		throw 'a';
	}
	catch (int param)	{
		cout << "int exceptionn";
	}
	catch (...)	{
		cout << "default exceptionn";
	}
	cout << "After Exception";
	return 0;
}
#endif 

#if 0

#include <iostream>
using namespace std;

class X {
public:
	X() { cout << "Constructor of X " << endl; }
	~X() { cout << "Destructor of X " << endl; }
};

int main() {
	try {
		X  t1;		throw 10;
	}
	catch (int i) {
		cout << "捕获 " << i << endl;
	}
}
#endif 

#if 0

void f2() {
	double d;
	try {
		auto i{ 0};		std::cin >> i;
		if (i < 0) throw - 1;
		else	if (i ==0) throw "zero";
		else throw 3.14;
	}
	catch (float) { std::cout << "float异常\n"; }
}
void f() {	
	try { f2(); }
	catch (int) { std::cout << "int异常\n"; }
}
int main() {
	try {
		f();
	}
	catch (double &err) {
		std::cout << "异常:" << err << "\n";
	}
}
#endif 

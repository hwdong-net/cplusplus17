/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   qq群：101132160
   微信公众号：hwdong编程
   C++17从入门到精通（源代码）：https://github.com/hwdong-net/cplusplus17
*/

#include <iostream>
# if 0 
#include <iostream>

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

#if 0
int* Max(int * a, int* b) {
	return a > b ? a : b;
}
#endif 

template <>
int * Max<int *>(int* a, int* b) {
	return *a > *b ? a : b;
}

#if 0
int * Max(int* a, int* b) {
	return *a > *b ? a : b;
}
#endif 

int main() {
	int x = 10, y = 20;
	int *p = &x, *q = &y;
    std::cout << *Max(p, q) << '\n';
}
#endif 

#if 0
#include <iostream>
using std::cout;

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

int* Max(int * a, int* b) {
	cout << "hehe\n";
	return *a > *b ? a : b;
}

template <typename T>
T Max(T arr[], int n) {
	T ret{ arr[0] };
	for (int i=1;i!=n;i++)
		if (arr[i]>ret ) ret = arr[i];
	return ret;
}

template <typename T>
T* Max(T* a, T* b) {
	return *a > *b ? a : b;
}

int main() {
	int x{ 10 }, y{ 20 };
	cout << Max(x, y) << '\n';
	cout << *Max(&x, &y) << '\n';
	double ds[]{ 3.1,0.2,4.6,7.8 };
	cout << Max(ds, std::size(ds))<<'\n';
}
#endif

#include <iostream>
using std::cout;
#if 0
template <typename T1,typename T2>
auto add(T1 a, T2 b)decltype(a + b) {
	return a +b;
}
#endif 

#if 0
template <typename T1, typename T2>
decltype(auto) add(T1 a, T2 b) {
	return a + b;
}
#endif 

#if 0
template <typename T, int lower, int upper>
T average(const T arr[])
{
	T ret{ arr[lower] };
	for (auto i = lower + 1; i <= upper; i++)
		ret += arr[i];
	return ret;
}

int main() {
	int arr[]{ 1,2,3,4,5 };
	std::cout<<average<int, 0, 4>(arr)<<'\t';
	std::cout << average<int, 1, 3>(arr) << '\t';
	double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
	std::cout << average<double, 1, 3>(arr2) << '\t';
}
#endif

#if 0
template <int lower, int upper, typename T>
T average(const T arr[])
{
	T ret{ arr[lower] };
	for (auto i = lower + 1; i <= upper; i++)
		ret += arr[i];
	return ret;
}

int main() {
	int arr[]{ 1,2,3,4,5 };
	std::cout << average<0,4>(arr) << '\t';
	std::cout << average<1,3>(arr) << '\t';
	double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
	std::cout << average<1, 3>(arr2) << '\t';	
}
#endif 

#if 0
template <typename T=int,int e=2>
T power(const T x) {
	T ret{ x};
	for (auto i = 1; i < e; i++)
		ret *= x;
	return ret;
}

int main() {
	std::cout << power(3)<<'\t';
	std::cout << power(3.5) << '\t';	
	std::cout << power<double,3>(3.5) << '\t';
}
#endif

template <typename T>
class Vector{
private:
	T* data{nullptr}; // T*类型指针指向数据元素类型是T的动态数组
	size_t capacity{0}; //动态空间的大小
	size_t size_{0}; // 实际的数据元素个数
public:
	explicit Vector(size_t cap=5);
	~Vector();

	T& operator[](size_t index); // 下标运算符
	const T& operator[](size_t index) const; // 下标运算符-const

	Vector(const Vector<T>& array); // 拷贝构造函数
	Vector& operator=(const Vector<T>& rhs); // 赋值运算符

	bool push_back(const T &e);
	
	size_t size() const { return size_; } // 返回实际数据元素的个数
};

template <typename T> 
Vector<T>::Vector(size_t cap) :data{ new T[cap] }, size_{ 0 }, capacity{ cap }
{
	//if (data) { capacity = cap; }
}

template <typename T>
Vector<T>::~Vector() {
	delete[] data;
}
#if 0
template <typename T>
T& Vector<T>::operator[](size_t index) // 下标运算符
{
	if (index >= size_) throw "下标非法";
	return data[index];
}
#endif

template <typename T>
const T& Vector<T>::operator[](size_t index) const // 下标运算符-const
{
	if (index >= size_) throw "下标非法";
	return data[index];
}

#if 0
template <typename T>
T& Vector<T>::operator[](size_t index) // 下标运算符
{
	return const_cast<T&> (static_cast<const Vector<T>&>(*this)[index]);
}
#endif 

#if 0
#include <utility>
template <typename T>
T& Vector<T>::operator[](size_t index) // 下标运算符
{
	return const_cast<T&> (std::as_const(*this)[index]);
}

template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector{ vec.capacity }
{
	size_ = vec.size_;
	for (size_t i{}; i < size_; ++i)  //拷贝每个数据元素
		data[i] = vec.data[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (&rhs != this) // 当右操作数不等于自己时，才赋值
	{ 
		Vector<T> ret{ rhs };
		std::swap(data, ret.data);		

		size_ = ret.size_;
		capacity = ret.capacity;
	}
	return *this; // 返回自身的引用
}

template <typename T>
bool Vector<T>::push_back(const T&e)
{
	if (capacity == size_) // 空间已满
	{
		T* temp= new T[2*capacity]; //分配和右操作数同样大小的空间
		if (!temp) return false;  //失败
		capacity*=2;
		//将数据从旧空间拷贝这个新空间
		for (size_t i{}; i < size_; ++i)
			temp[i] = data[i];
			    
		delete[] data; // 释放本来的内存
		data = temp;		
	}
	//将新数据e加到已有数据元素的最后面
	data[size_] = e; size_++;
	return true;
}

#endif 

#if 0
template <>
class Vector<const char*>
{
	// 处理特定类型 const char*的类Vector...
};



template<typename T,int s=10>
class X {
	//...
};

template<int s>
class X<const char*,s> {
	//...
};

template<typename T, int s>
class X<T*, s> {
	//...
};


int main() {
	Vector<int> a;
	for (auto i = 0; i <= 6; i++)
		a.push_back(2 * i + 1);
	a[3] = 30;
	for (auto i = 0; i != a.size(); i++)
		std::cout << a[i] << '\t';
	std::cout << '\n';

	Vector<int> b;
	b = a;
	for (auto i = 0; i != a.size(); i++)
		std::cout << b[i] << '\t';

//	Vector x{1.,2.,3.5 ,4.2, 5.5 };
	//std::vector x{ 1.,2.,3.5 ,4.2, 5.5 };

	Vector<const char *> vec;

	X<const char *, 3> x;

	return 0;
}
#endif 

#if 0
template<typename T>
class X{
	int a{ 0 };
	//...
	friend void f();
	friend class A;
};

void f() {
	X<char> x;
	X<double> y;
	std::cout<< x.a << '\t' << y.a << '\n';
}

int main() {
	f();
}
#endif 

#if 0

template<typename T>
class Y{
	int a{0};		
	//...
	friend auto g(const Y<T>& e);
};

template<typename T>
auto g(const Y<T>& e) {
	std::cout << e.a << '\n';
}

int main() {
	Y<char> y;
	Y<double> y2;
	
	g<char>(y);
//	g<double>(y2);
	return 0;
}
#endif


#if 0
#include <iostream>
class Point {
	int x, y;
public:
	Point(int x0, int y0) :x{ x0 }, y{ y0 }{}
	Point(std::initializer_list<int> list) {
		auto it = list.begin();//begin()返回一个指示list第一个元素位置的迭代器
		x = *it++; //先将it指向的元素值*it赋值给x,然后it++，使得it指向下一个元素
		y = *it++;
	}
	void print() {
		std::cout << x << "," << y;
	}
};

int main() {
	Point p{ 2,5 }; //OK，参数个数正好匹配
	Point q{ 2,5,3 }; //错：编译器没有3个参数的构造函数
}
#endif

#if 0
template <template<class> class X, class A>
void f(const X<A> &value) {
	/*...*/
}

#endif 

#if 0
template <typename... T>
void f(T... args) {/*...*/}

#if 0
template <typename... Args>
void print(Args&...args) {
	for (auto arg : args)
		std::cout << arg;	
}
#endif 

template <typename T>
void print(T t) {
	std::cout << t << '\t';
}

template <typename T,typename... Rest>
void print(T t,Rest...rest) {
	std::cout << t << "\t";
	print(rest...);
}
int main() {
	print("Li") ;
	print(2,"Li");
	print(2, "Li",80.5);
}
//https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/
//https://www.cnblogs.com/qicosmos/p/4325949.html
#endif 
#include <iostream>

#if 0
int main() {
	int var;
	var = 3;

	
}
#endif 

#if 0
int foo() { return 3; }

int main() {
	foo() = 3;
	return 0;
}
#endif 

#if 0
#include <vector>
int g_var = 2;

int& foo(){
	return g_var;
}

int main(){
	foo() = 10;
	std::vector<int> vec(3);
	vec[1] = 3; 

	const int a = 10;//a是一个左值
	a = 2; //但a不能被赋值（修改）
	return 0;
}
#endif 

#if 0
int main() {
#if 1
	double a{}, b{ 1 }, c{ -2 };
	double *x = &(a + b); //a+b不是左值
	double *y = &a;   //a是左值
	double *z = &(std::abs(a*b)); //std::abs(a*b)不是左值
	double *u = &25; // 常量25不是左值
#endif
	int a = 1, b = 2;
	int c = a + b;

	int arr[] = { 1, 2 };
	int* p = &arr[0];
	*(p + 1) = 10;   // OK: p + 1是右值, 但 *(p + 1)是一个左值

	int var{ 5 };
	int&& rtemp{ var + 3 }; // 右值引用rvalue reference
	std::cout << rtemp << std::endl; //输出表达式rtemp的值
	int& rcount{ var }; // 左值引用lvalue reference
}
#endif 


#if 0

class X {
	//...
public:
	X() = default;
	X(const X&) { std::cout << "拷贝构造函数！\n"; }
	X& operator=(const X&) {
		std::cout << "赋值拷贝函数:\n";
		return *this; 
	}
	//X(const X&&) { std::cout << "移动构造函数！\n"; }
};
X fun() {
	X t;
	//...
	return t;
}
int main() {
	X x;
	x = fun();
}

#endif 

#include <utility>
using std::cout;
template <typename T>
class Vector {
private:
	T* data{ nullptr }; // T*类型指针指向数据元素类型是T的动态数组
	size_t capacity{ 0 }; //动态空间的大小
	size_t size_{ 0 }; // 实际的数据元素个数
public:
	explicit Vector(size_t cap = 5);
	~Vector();

	T& operator[](size_t index); // 下标运算符
	const T& operator[](size_t index) const; // 下标运算符-const

	Vector(const Vector<T>& array); // 拷贝构造函数
	Vector<T>& operator=(const Vector<T>& rhs); // 赋值运算符

	bool push_back(const T &e);
	size_t size() const { return size_; } // 返回实际数据元素的个数

#if 1

	Vector(Vector&& moved);
	Vector<T>& operator=(Vector<T>&& rhs);
#endif
};

template <typename T>
Vector<T>::Vector(size_t cap) :data{ new T[cap] }, size_{ 0 }, capacity{ cap }
{
//	cout << "构造函数：分配了" << capacity << "元素的空间\n";
	//if (data) { capacity = cap; }
}

template <typename T>
Vector<T>::~Vector() {
	delete[] data;
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const // 下标运算符-const
{
	if (index >= size_) throw "下标非法";
	return data[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index) // 下标运算符
{
	return const_cast<T&> (std::as_const(*this)[index]);
}

template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector{ vec.capacity }
{ 
	cout << "拷贝构造函数：拷贝了" << vec.size_ << "元素\n";
    size_ = vec.size_;
	for (size_t i{}; i < size_; ++i)  //拷贝每个数据元素
		data[i] = vec.data[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (&rhs != this) // 当右操作数不等于自己时，才赋值
	{
		cout << "赋值运算符\n";
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
		T* temp = new T[2 * capacity]; //分配和右操作数同样大小的空间
		if (!temp) return false;  //失败
		capacity *= 2;
		//将数据从旧空间拷贝这个新空间
		for (size_t i{}; i < size_; ++i)
			temp[i] = data[i];

		delete[] data; // 释放本来的内存
		data = temp;
	}
	//将新数据e加到已有数据元素的最后面
	data[size_] = e; 
	size_++;
	return true;
}

Vector<int> f() {
	Vector<int> v(20);
	for (auto i = 0; i < 1000; i++)
		v.push_back(2 * i + 1);

	return v;
}

#if 1
// Move constructor
template <typename T>
Vector<T>::Vector(Vector<T>&& vec)
	: size_{ vec.size_ }, data{ vec.data }
{
	cout << "移动构造函数：移动了 " << vec.size_ << "元素\n";
	vec.data = nullptr; // Otherwise destructor of moved would delete[] elements!
}

// Move assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
	cout << "移动赋值运算符：移动了 " << rhs.size_ << "元素\n";
	if (this != &rhs) // prevent trouble with self-assignments
	{
		delete[] data; // delete[] all existing elements
		data = rhs.data; // copy the elements pointer and the size
		size_ = rhs.size_;
		rhs.data = nullptr; // make sure rhs does not delete[] elements
	}
	return *this; // return lhs
}
#endif 

#if 0

int main() {
#if 0
	Vector<int> v1(20);
	Vector<int> v2;
	for (auto i = 0; i < 1000; i++)
		v1.push_back(2 * i + 1);
	cout << "左值的赋值...\n";
	v2 = v1;
#else
	Vector<int> v2;
	cout << "右值的赋值...\n";
	v2 = f();
#endif
}

#endif 

#if 1 
int main(){
	Vector< std::string> str_vec;
	Vector< std::string> string_vec;
	for (auto i = 0; i < 10000; i++)
		string_vec.push_back("mljsdklfjsjfsyuqwhl");
	//str_vec = string_vec;
	str_vec = std::move(string_vec);
#if 0
	template<class _Ty>
	_NODISCARD constexpr remove_reference_t<_Ty>&&
		move(_Ty&& _Arg) _NOEXCEPT
	{	// forward _Arg as movable
		return (static_cast<remove_reference_t<_Ty>&&>(_Arg));
	}
#endif
	std::cout << "........\n";
	//将string_vec转化为右值，右值引用ref引用这个右值
	Vector< std::string> &&ref{std::move(string_vec)};
//	Vector< std::string> str_vec2 = ref; //ref是一个左值，因此，
	                              //这是普通的赋值运算而不是移动赋值
	Vector< std::string> str_vec2 = std::move(ref);//


	return 0;
}
#endif
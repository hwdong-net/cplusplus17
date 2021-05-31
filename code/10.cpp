#include <iostream>
using namespace std;


//==============函数模板====================

#if 0
//--------求2个元素的最大值，不同类型需单独编写函数------
int Max(int a, int b) {
    return a > b ? a : b;
}

double Max(double a, double b) {
    return a > b ? a : b;
}
int main() {
    cout << Max(3, 5) << endl;         
    cout << Max(3.5, 4.5) << endl;  
    cout << Max(6, 4) << endl;
}


#endif



#if 0
//--------求2个元素的最大值，只要编写一个模板函数------
template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}
int main() {
    cout << Max<int>(3, 5) << endl;          //模板类型参数T为int
    cout << Max<double>(3.5, 4.5) << endl;  //模板类型参数T为double
    cout << Max<int>(6, 4) << endl;
}

#endif

#if 0
//---------模板参数推断----------
//根据调用函数模板传递的实际函数参数（注：不是模板参数）自动推断出模板参数的类型。
//不需要显式指定模板类型参数

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    cout << Max(3, 5) << endl;     //根据实际参数3,5是int类型，
//推断出需要实例化Max<int>函数
    cout << Max(3.5, 4.5) << endl;  //根据实际参数3.5, 4.5是double类型，
//推断出需要实例化Max<double>函数
    cout << Max(6, 4) << endl;     //调用前面已经实例化的Max<int>函数
}



#endif

//---------10.1.3 模板专门化----------
#if 0

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

#if 0
//针对int*类型对模板参数专门化
template <>
int* Max<int*>(int* a, int* b) {
    return  *a > *b ? a : b;
}
#endif

/*
* int* Max(int * a, int* b) {
	return a > b ? a : b;
}
*/
int main() {
    int x = 10, y = 20;
    int* p = &x, * q = &y;
    std::cout << *Max(p, q) << '\n';
}
#endif

//--------函数模板和重载--------------
//可以定义和函数模板名同名的函数或模板，

#if 0
template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}
int* Max(int* a, int* b) {
    return *a > *b ? a : b;
}

template <typename T>
T Max(T arr[], int n) {
    T ret{ arr[0] };
    for (int i = 1; i != n; i++)
        if (arr[i] > ret) ret = arr[i];
    return ret;
}

template <typename T>
T* Max(T* a, T* b) {
    return *a > *b ? a : b;
}

//和普通的函数重载一样，编译器会根据模板参数或函数参数确定最匹配的实例化函数。
//当普通函数和针对指针类型的模板都能精确匹配*Max(&x, &y)时，普通函数优先。
//即int* Max(int * a, int* b)优先于template <typename T>T* Max(T* a, T* b)。
int main() {
    int x{ 10 }, y{ 20 };
    cout << Max(x, y) << '\n';      // template <typename T>T Max(T a, T b)
    cout << *Max(&x, &y) << '\n';  // int* Max(int * a, int* b)
    double ds[]{ 3.1,0.2,4.6,7.8 };
    cout << Max(ds, std::size(ds)) << '\n';  // template <typename T> T Max(T arr[], int n)
}

#endif

//-----------10.1.5 模板的返回类型推断------------
#if 0
/*  返回类型是什么？
template <typename T1, typename T2>
? add(T1 a, T2 b) {
    return a + b;
}
*/

//尾返回类型(trailing return type)语法，
//即在函数签名后用->decltype(exp)来推断模板函数的返回类型，
//函数签名前用auto关键字：
#if 1
template <typename T1, typename T2>
auto add(T1 a, T2 b)->decltype(a + b) {
    return a + b;
}

#else
//用decltype(auto)来推断函数的返回类型：
template <typename T1, typename T2>
decltype(auto) add(T1 a, T2 b) {
    return a + b;
}
#endif

int main() {
    auto ret = add(3, 4.5);
    cout << typeid(ret).name() << endl;
    cout << add(3, 4.5)<<endl;
}
#endif

//----------10.1.6 非类型模板参数----------
//模板参数里还可以有非类型模板参数，
//模式实例化时传递给非类型模板参数的是普通的值而不是数据类型
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
    std::cout << average<int, 0, 4>(arr) << '\n';
    std::cout << average<int, 1, 3>(arr) << '\n';
    double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
    std::cout << average<double, 1, 3>(arr2) << '\n';

#if 0
    //非类型模板参数要传递常数值而不是变量
    int i = 1, j = 3;
    std::cout << average<double, i,j>(arr2) << '\n'; 
#endif
}

#endif

//可以将函数模板的类型模板参数放在最后，其类型由输入的函数的实参自动推断。
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
    std::cout << average<0, 4>(arr) << '\t';
    std::cout << average<1, 3>(arr) << '\t';
    double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
    std::cout << average<1, 3>(arr2) << '\t';
}

#endif 

//C++17中还允许用auto说明非类型模板参数，
//从而根据模板实例自动推断非类型模板参数的类型。
#if 0
template <auto value> void f() { }
int main() {
    f<10>();
}
#endif

//--------在C++17中可以用auto声明非类型模板参数，使得模板定义更加简单：-----
#if 0
#if 0
//下面的constexpr常量模板及其实例化代码：
template <typename T, T value> constexpr T TConstant = value;
constexpr auto const MySuperConst = TConstant<int, 100>;
#else
//用auto声明非类型模板参数
template <auto value> constexpr auto TConstant = value;
constexpr auto const MySuperConst = TConstant<100>;
#endif 

#endif 

//---------10.1.7 模板模板参数--------------
//模板参数本身也可以是一个模板，这种模板参数称为模板模板参数。
//实例化模板时，传递的不是一个数据类型或者具体值而是另外的一个模板，
#if 0
template <template<class> class X, class A>
void f(const X<A>& value) {
    /*...*/
}
#endif

//------------10.1.8 模板参数的默认值-------
//定义函数模板时，可以给类型模板参数、非类型模板参数、模板模板参数设置默认值。
// 
#if 0
//下面代码给类型模板参数T、非类型模板参数e都设置了一个默认值：

template <typename T = int, int e = 2>
T power(const T x) {
    T ret{ x };
    for (auto i = 1; i < e; i++)
        ret *= x;
    return ret;
}

int main() {
    std::cout << power(3) << '\t';
    std::cout << power(3.5) << '\t';
    std::cout << power<double, 3>(3.5) << '\t';
}
#endif 

#if 0
//和函数的默认参数必须在非默认参数后面不同，
//默认模板参数可以在非默认模板参数的前面，
template <typename T = int, int e>
T power(const T x) {
    T ret{ x };
    for (auto i = 1; i < e; i++)
        ret *= x;
    return ret;
}
//再看一个例子：
template <typename T = int, int e = 2>
T fun() {
    T  ret{ 0 };
    for (auto i = 1; i < e; i++)
        ret += 3.14;
    return ret;
}

int main() {
    std::cout << fun() << '\t';
    std::cout << fun<double>() << '\t';
    //std::cout << fun<3>() << '\t';  //错：3实例化T
    std::cout << fun<double, 3>() << '\t';
}
#endif 

//-------------10.1.9可变模版参数----------------
/*
* std::initializer_list可定义可变数目的形参，
但传递给形参的可变数目的所有实参类型都必须相同，
而通过定义可变模板参数的模板，
可以给可变模板参数对应的形参传递不同类型不同数目的实参。
*/

#if 0
template <typename... Args>
void fun(Args... args) {/*...*/ }
//用Range for如下访问传递给args的每个实参是错误的：
template <typename... Args>
void print(Args...args) {
    for (auto arg : args)
        std::cout << arg;
}
#endif 

#if 0
//该函数模板写成递归函数模板形式
/*
* 递归形式的函数模板将可变参数拆成2部分，
第一个形参是一个普通的单个值的参数，
而第二个是一个可变模板参数。其中的rest...表示逗号隔开的可变参数。
*/

#if 0
template <typename T>
void print(T t) {                       //基情形：只有一个函数形参
    std::cout << t << '\t';
}
template <typename T, typename... Rest>
void print(T t, Rest...rest) {              //递归情形：有多个函数形参
    std::cout << t << "\t";	print(rest...);
}

int main() {
    print("Li");           //调用的是print(T t)
    print(2, "Li");          //调用的是print(T t, Rest...rest)
    print(2, "Li", 80.5);      //调用的是print(T t, Rest...rest)
}
#endif


#if 1
//下面的sum函数模板用于对一组可变模板参数求和。
#include <iostream>
auto sum() { return 0; }

template<typename T1, typename... T>
auto sum(T1 s, T... ts) { return s + sum(ts...); }

int main() {
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
}
#endif 

#endif


#if 0
//-----折叠表达式------------
/*
* 折叠表达式（Fold expressions）是一种新的用运算符解包可变参数的方法。
即用一个运算符（如op）对打包的可变参数（pack）处理，其常见格式如下：
( pack op ... )             //(1)
( ... op pack )             //(2)
( pack op ... op init )       //(3)
( init op ... op pack )       //(4)
版本(1)是右折叠，即展开成：(a1 op (a2 op (a3 ... (aN-1 op aN))))形式，
版本(2)是左折叠，展开成：((((a1 op a2) op a3) ... ) op aN)形式。
版本(3)、(4)类似于(1)和(2)，只不过多了一个初始值。
*/

#if 0
template <typename... T>
auto sum(T... s) {
    return (... + s);
}
int main() {
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
}
#endif

#if 0
//用基于逗号运算符,的折叠表达式可将前面的print函数模板写成如下形式。
template<typename ...Args>
void print(Args ...args) {
    ((std::cout << args << '\t'), ...) << "\n";
}
int main() {
    print("Li");           
    print(2, "Li");         
    print(2, "Li", 80.5);    
}
#endif

//当然函数体中的代码也可以用一个Lambda函数做更多的工作。
#if 1
template<typename ... Args>
void print(Args ... args) {
    ([](const auto& x) { std::cout << x << "\t"; }(args), ...);
    std::cout << "\n";
}
int main() {
    print("Li");
    print(2, "Li");
    print(2, "Li", 80.5);
}
#endif

#endif 

//--------10.1.10 constexpr if-----------
/*
* constexpr使得表达式可以在编译期间计算，从而避免了运行期间的计算开销。
如果和if结合，使得可以在编译时根据常量表达式条件而丢弃if语句的分支。
if constexpr (cond)
   语句1; // 如果 cond是false，则丢弃该语句
else
   语句2; // 如果 cond是true，则丢弃该语句
*/

#if 0
//fibonacci(斐波那契) 数列的C++模板实现。
template<int  n>
constexpr int fibonacci() { return fibonacci<n - 1>() + fibonacci<n - 2>(); }
template<>
constexpr int fibonacci<1>() { return 1; }
template<>
constexpr int fibonacci<0>() { return 0; }

int main() {
    cout << fibonacci<6>()<< endl;
}

#endif

#if 0
//在C++17中，如果用constexpr if实现则只需要写一个类似普通递归函数的模板。
template<int n>
constexpr int fibonacci() {
    if constexpr (n >= 2)
        return fibonacci<n - 1>() + fibonacci<n - 2>();
    else
        return n;
}

int main() {
    cout << fibonacci<6>() << endl;
}

#endif

//=========10.2 类模板=============

#if 0
//-----C++标准库的vector类模板是一个模板化的顺序表-------
#include <iostream>
#include <vector>   //vector类模板的头文件
using namespace std;
int main() {
    vector<int> ivec;            //编译器会自动生成数据元素是
//int类型的vector（向量或数组）类
    vector<double> dvec;        //编译器会自动生成数据元素是
//double类型的vector（向量或数组）类
    vector<int> ivec2 = { 3,5,7,4,6 };   //用统一初始化{ }对ivec2初始化.
//ivec2的类型是vector<int>
    ivec = ivec2;        // ivec和ivec2是同类型vector<int>的变量（对象），可以相互赋值
 //   dvec = ivec2;        // 错：dvec和ivec2是不同类型的对象，不能相互赋值。

    for (auto e : ivec2)            //range for可遍历向量ivec2的每个元素
        cout << e << '\n';
    cout << endl;

    ivec.push_back(10);   //在ivec向量类的最后加入一个整数10
    ivec.push_back(9);    //在ivec向量类的最后加入一个整数9
    ivec.push_back(8);    //在ivec向量类的最后加入一个整数8
    for (auto e : ivec)   cout << e << '\n';
    cout << endl;

    for (int i = 0; i != 5; i++)
        dvec.push_back(2*i + 1);
    for (int i = 0; i != dvec.size(); i++)   //dvec.size()返回实际元素的个数
        cout << dvec[i] << '\n';
    cout << endl;
}

#endif

#if 0
#include <string>
using std::string;
class student {
    string name_;
    double score_;
public:
    student(string n, double s) :name_(n), score_(s) {}
    string name() { return name_; }
    double score() { return score_; }
    void set_name(string n) { name_ = n; }
    void set_score(double s) { score_ = s; }
};
//同样可以直接在程序中实例化一个数据元素类型是student的vector。
#include <iostream>
using namespace std;
int main() {
    vector<student> students;       //从vector实例化一个类：vector<student>
    student stu;
    cout << "输入学生信息：name, score\n";
    while (cin >> stu.name) {
        if (cin >> score && score >= 0)
            students.push_back(stu);
        else break;
        cout << "输入学生信息：name, score\n";
    }
    cout << "输出所有学生的信息\n";
    for (auto e : students)
        cout << e.name() << '\t' << e.score() << endl;

    return 0;
}
#if 0
int main() {
    student students[100];  //100个student的静态数组空间
    int num_student = 0;   //实际学生个数
    return 0;
}
#endif 
#endif

//-------10.2.2 类模板Vector-------------
#if 0
template <typename T>            //类型模板参数T用于泛化数据元素的类型
class Vector {
private:
    T* data{ nullptr };             // T*类型指针指向数据元素类型是T的动态内存块（动态数组）
    size_t capacity{ 0 };            //动态空间的大小
    size_t n{ 0 };                  // 实际的数据元素个数
public:
    explicit Vector<T>(int cap = 5);
    ~Vector<T>();

    T& operator[](size_t index);                    // 下标运算符
    const T& operator[](size_t index) const;          // const版本的下标运算符

    Vector<T>(const Vector<T>& array);           // 拷贝构造函数
    Vector<T>& operator=(const Vector<T>& rhs);   // 赋值运算符

    bool push_back(const T& e);
    size_t size() const { return n; } // 返回实际数据元素的个数
};

//1.	构造函数模板Constructor Templates
template <typename T>             //类体外定义成员函数模板，必须包含模板头
Vector<T>::Vector(size_t cap) :data{ new T[cap] }, n{ 0 }
{
    if (data) { capacity = cap; }
}
//2.	析构函数模板Destructor Templates
template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

//3.	拷贝构造函数模板
template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector{ vec.capacity } {
    if (!data)  return;
    n = vec.n;
       for (size_t i{}; i < n; ++i)  //拷贝每个数据元素
            data[i] = vec.data[i];
}
//4.	下标运算符[]模板
template <typename T>
T& Vector<T>::operator[](size_t index) { // 下标运算符
    if (index >= n) throw "下标非法";
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const { // 下标运算符-const
    if (index >= n) throw "下标非法";
    return data[index];
}


#if 0 
//const和non-const的下标运算符函数模板具有一样的代码，
// 实际编程中应尽量避免这种代码重复，
//那么non - const版本的下标运算符怎么调用const版本的下标运算符函数呢？
//能不能直接写成如下形式？：
template <typename T>
T & Vector<T>::operator[](size_t index) // 下标运算符
{
    return (*this)[index];
}
/*
* 因为这个是non-const版本的，因此this是non-const指针，
//*this是non-const的引用，通过这个引用调用的下标运算符函数仍然是这个函数本身，
//因此，就产生了无限死循环！
*/
//正确的做法：强制类型转换
//return const_cast<T&> ( static_cast<const Vector<T>&>(*this)[index] );
//const_cast<>去掉对象的const性,即const_cast<>将const对象转换为non-const对象。

C++17提供了一个辅助函数std::as_const可以将一个non - const对象
//强制转换为一个const对象。
//可以用它替代static_cast<>，使代码更加简洁一些：
return const_cast<T&> (std::as_const(*this)[index]);

//std::as_const函数在头文件<utility>中，

#include <utility>
template <typename T>
T& Vector<T>::operator[](size_t index) {// 下标运算符
    return const_cast<T&> (std::as_const(*this)[index]);
}

#endif 

//5.	赋值运算符模板The Assignment Operator Template
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // 当右操作数不等于自己时，才赋值
    {
        T* temp = new T[rhs.capacity];   //申请和右操作数同样大小的空间
        if (temp) {
            delete[] data;             // 释放原来的内存空间
            data = temp;
            // 拷贝右操作数的内容
            n = rhs.n;
            capacity = rhs.capacity;
            for (size_t i{}; i < n; ++i)
                data[i] = rhs.data[i];
        }
    }
    return *this; // 返回自身的引用
}

/*
* 赋值运算符函数内部是和拷贝构造函数基本同样的代码，
//按照 “不重复做（DRY）”的原则，应该避免重复代码。
是否可以在其中调用拷贝构造函数呢？
*/

#if 0
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // 当右操作数不等于自己时，才赋值
    {
        Vector<T> ret(rhs)； //拷贝构造函数构造一个临时对象ret
            delete[] data;        // 释放本来的内存
        data = ret.data;      //data指向临时对象的data内存
        n = ret.n;
        capacity = ret.capacity;
    }
    return *this; // 返回自身的引用
}

#endif 

#if 0
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // 当右操作数不等于自己时，才赋值
    {
        Vector<T> ret{ rhs };
        //交换ret.data和data指针
        T* temp = ret.data;   //
        ret.data = data;
        data = temp;

        n = ret.n;
        capacity = ret.capacity;
    }
    return *this; // 返回自身的引用
}

#endif

#if 0
//交换2个data指针变量的值可以使用标准库的函数std::swap()
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (&rhs != this) // 当右操作数不等于自己时，才赋值
    {
        Vector<T> ret{ rhs };
        std::swap(data, ret.data);
        std::swap(n, ret.n);
        std::swap(capacity, ret.capacity);
    }
    return *this; // 返回自身的引用
}

#endif

//6.	push_back()

template <typename T>
bool Vector<T>::push_back(const T& e)
{
    if (capacity == n) // 空间已满
    {
        T* temp = new T[2 * capacity];   //分配2倍的内存空间
        if (!temp) return false;        //失败
        capacity *= 2;                //设置空间容量
        //将数据从旧空间拷贝这个新空间
        for (size_t i{}; i < n; ++i)
            temp[i] = data[i];

        delete[] data; // 释放本来的内存
        data = temp;
    }
    //将新数据e加到已有数据元素（下标0,1,…,size_-1）的最后面
    data[n] = e;   n++;
    return true;
}

//7.	测试Vector类模板
int main() {
    Vector<int> a;  // Vector<int>是Vector类模板的实例化类，其中的数据元素类型是int
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
    return 0;
}

#endif 

//--------10.2.4 类模板的模板参数推断------------
/*
* C++17中类模板和函数模板一样可以自动推断模板参数类型。
在C++17中，下面代码是可以从初始化列表中
推断出模板Vector<T>的模板参数T的类型的。

 Vector x{ 2., 4.3, 8.  };
但
  Vector y{ 2, 4.3, 8. };
则无法推断模板参数的类型，因为2是int，而其他的值是double。

*/

#if 0
//std::tuple是一个可以容纳不同类似数值的模板类。
int main() {
    std::tuple t(1, 2, 3);              // 自动推断3个值的类型都是int
    std::tuple<int, int, int> t2(1, 2, 3); //指定3个值的类型都是int
    std::tuple t3(1, 2., 3.f); // 自动推断3个值的类型都是int、double、float

    //可以用get<i>函数模板获得一个tuple对象的某个下标是i的元素。
    std::cout << typeid(std::get<0>(t3)).name() << "\n";
    std::cout << typeid(std::get<1>(t3)).name() << "\n";
    std::cout << typeid(std::get<2>(t3)).name() << "\n";

}
#endif

//--------10.2.5类模板的专门化---------
#if  0
//和函数模板的专门化一样，也可以定义类模板的专门化。
//这种所有模板参数都指定专门类型的类模板专门化称为完全专门化
template <>
class Vector<const char*>
{
    // 处理特定类型 const char*的类Vector...
};

//部分专门化，即只专门化部分模板参数，这样的部分专门化仍然是一个类模板。
template<typename T, int s = 10>
class X {
    //...
};

//可以对其中的一个模板参数如类型模板参数指定其专门化为const char*，
//得到下面的专门化类模板：
template<int s>
class X<const char*, s> {
    //…
};

//注意：类模板中的模板参数s也必须出现在专门类模板名后的<>里，但不需要说明其类型。
//下面的专门化将类型模板参数专门化为T*指针类型。
template<typename T, int s>
class X<T*, s> {
    //…
};

#endif

//---------10.2.6类模板的友元-------------------
/*
* 和普通类的友元一样，可以用关键字friend在
类模板里指定外部函数、类、或其他模板为该类模板的友元。
*/

#if 0
template<typename T>
class X {
    int a{ 0 };
    //...
    friend void fun();
    friend class A;
};

void fun() {
    X<int> x;
    X<double> y;
    std::cout << x.a << '\t' << y.a << '\n';
}

#endif 

#if 0
/*
* 作为友元的函数模板g和类模板Y是同一个模板头，
因此，g的实例如g<int>只能是同类型模板参数（int）的类模板Y的实例Y<int>的友元，
不是其他类型模板参数（如double）的Y实例（如Y<double>）的友元。
*/

template<typename T>
class Point {
public:
    T x, y;
    Point(const T x, const T y) :x(x), y(y) {}
    //...
    friend Point<T>* g(Point<T>& e);
};
template<typename T>
Point<T>* g(Point<T>& e) {
    Point<T>* p = new Point<T>(e);
    return p;
}
int main() {
    Point<int> e(3, 4);
    auto p = g<int>(e);
    std::cout << p->x << "\t" << p->y << '\n';
    Point<double> x(3, 4);
    auto q = g<int>(x);  //错：g<int>不是Point<double>的友元
    std::cout << q->x << "\t" << q->y << '\n';
}

#endif 

//---------10.2.7 类模板std::initializer_list< >--------------
/*
* 当用{}初始化列表去初始化其他变量或作为赋值运算符的右操作数时，
编译器会自动创建一个std::initializer_list<>实例化类的对象。例如：
   auto il = { 10, 20, 30 };

*/

#if 1
//Point类中定义了std::initializer_list<int>作为参数的构造函数，
//则就可以接受任意多个值的括号参数化列表对象。

class Point {
    int x, y;
public:
    Point(int x0, int y0) :x{ x0 }, y{ y0 }{}
    Point(std::initializer_list<int> list) {
        auto it = list.begin();    //begin()返回一个指示list
//第一个元素位置的迭代器
        x = *it++;             //先将it指向的元素值*it赋值给x,
//然后it++，使得it指向下一个元素
        y = *it++;
    }
    void print() {
        std::cout << x << "," << y;
    }
};

//下面是Vector的带std::initializer_list<>参数的构造函数：
Vector(std::initializer_list<T> l) {
    data = new T[l.size()];
    if (!data) return;
    capacity = l.size(); n = l.size();
    auto i{ 0 };
    for (auto it = l.begin(); it != l.end(); it++, i++)
        data[i] = *it;
}

//执行下列程序：
int main() {
    Vector<Vector<int>> matrix{ {1,2,3,4},{5,6,7,8} };
    for (auto i = 0; i < matrix.size(); i++) {
        for (auto j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}


#endif 
//========为什么需要函数？==========.include <iostream>
using namespace std;
//---------最大公约数--
#if 0
int main() {
    int m{ 72 }, n{ 27 };
    cout << m << "和" << n;
    while (n != 0) {
        auto r = m % n;
        m = n; n = r;
    }
    cout << " 的最大公约数为"
        << m << endl;

    m = 36, n = 24;
    cout << m << "和" << n;
    while (n != 0) {
        auto r = m % n;
        m = n; n = r;
    }
    cout << " 的最大公约数为"
        << m << endl;
}
#endif

//------函数的定义、函数的形式参数----
//------函数的调用、实际参数----------

# if 0
#include <iostream>

//GCD是函数名，圆括号内的是参数化的2个整数m,n，称为“形式参数”
//函数名前面的void关键字，说明这个函数不返回值
void GCD(int m, int n) {   
    while (n != 0) {
        int r = m % n;
        m = n; n = r;
    }
    std::cout << m << "和" << n << "的最大公约数是： " << m << std::endl;
}

int main() {
    int x = 72, y = 27;
    GCD(x, y); //调用函数名叫GCD的代码，将x,y的值传递给
             //被调用函数GCD的2个形参数m,n    
    x = 36; y = 24;
    GCD(x, y);
}
#endif

//---------return返回（结果）---------------
# if 0
#include <iostream>
int GCD(int m, int n) {
    //int m = 72,n = 27;
    while (n != 0) {
        int r = m % n;
        m = n; n = r;
    }
    return m; //返回int类型的结果（值）m    
}

int main() {
    int x = 72, y = 27;
    int gcd = GCD(x, y); //用函数GCD的返回结果初始化int类型变量gcd
    std::cout << x << "和" << x << "的最大公约数是： " << gcd << std::endl;

    x = 36; y = 24;
    gcd = GCD(x, y);
    std::cout << x << "和" << y << "的最大公约数是： " << gcd << std::endl;
}
#endif


#if 0
//函数的每个形参用逗号隔开，必须说明每个形参的类型
//形参不能同名（也不能与局部变量同名）：重定义
void f();
void f1(void);

//void f2(int v1, v2);
void f3(int v) {
    int v;
}
#endif

//---------return：返回结果----------------
//一个函数可以有多个return语句，函数遇到return就执行结束
#if 0
#include <iostream>
auto g() {
    int i; std::cin >> i;
    if (i > 0) return 1;        //函数结束，返回1
    else if (i < 0) return -1;   //函数结束，返回-1
    else return 0;              //函数结束，返回0
}
int main() {
    auto ret = g();
    std::cout<<typeid(ret).name();
    return 0;
}
#endif

//多个return值的类型必须相同或能转化为同一个类型
#if 0
#include <iostream>
auto g2() {
    int i; std::cin >> i;
    if (i > 0) return 3.14;        
    else if (i < 0) return -1;   
    else return 0;              
}
int main() {
    g2();
    return 0;
}
#endif

//不能返回非静态局部变量的引用或指针
#if 0
int* fp() {
    int var;
    //...
    return &var;
}
int& fr() {
    int var;
    //...
    return var;
}

#include <iostream>
int main() {
    int *p = fp();
    *p = 45;
    std::cout << *p << std::endl;

    int& q = fr();
    q = 45;
    std::cout << q << std::endl;
}
#endif


//静态局部变量和非静态局部变量
#if 0
#if 1
int main() {
    while (true) {
        auto i{ 0 }; //i是一个非静态局部变量
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#else

#include <iostream>
int main() {
    while (true) {
        static auto i{ 0 }; //i是一个静态局部变量
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#endif
#endif 

#if 0
#include <iostream>
void  f() {
    static auto i{ 0 };   //i是静态局部变量
    int j{ 0 };          //j是非静态局部变量
    i++;  j++;
    std::cout << i << '\t' << j << '\n';
}

int main() {
    f();
    f();
}
#endif 

#if 0
#if 0
#include <iostream>
int main() {
    while (true) {
        auto i{ 0 }; //i是一个非静态局部变量
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#endif
#include <iostream>
int main() {
    while (true) {
        static auto i{ 0 }; //i是一个静态局部变量
        if (i++ < 6) std::cout << i << '\t';
        else break;
    }
}
#endif

#if 0
//1. 值形参，引用形参
#include <iostream>
void f(int var, int& ref) {
    var++;
    ref++;
    std::cout << var << '\t' << ref << std::endl;
}
int main() {
    auto x = 1, y = 1;
    f(x, y);
    std::cout << x << '\t' << y << std::endl;
}
#endif

#if 0
//2.默认形参
int pow(int x, int n = 2) {
    auto ret{ 1 };
    for (auto i{ 0 }; i < n; i++)
        ret *= x;
    return ret;
}


void f(int a, int b = 2, int c = 4) {

}

int main() {
    f();
    cout << pow(3) << '\t'
        << pow(3, 4) << endl;
}
#endif


//3.数组形参
#if 0
//函数的形参写成数组的样子,实际是一个指针变量
void printArr(int a[], int n) { //int *
    //for(auto e:a)
    //	cout << e << '\t';

    for (auto i{ 0 }; i < n; i++)
        cout << a[i] << '\t';
    cout << endl;
}

int main() {
    int arr[]{ 1,2,3,4,5 };
    printArr(arr, 5);
}
#endif

//----不能用range for访问指针指向的数组----
#if 0
#include <iostream>
void PrintArr(int arr[], int n) {  
    for (auto e:arr)
        std::cout << e << '\t';
}
int main() {
    int a[]{ 7,2,4,19 };
    PrintArr(a, 4);
}

#endif

//引用参数可引用一个数组
//此时可以用range for访问这个数组
#if 0
#include <iostream>
//arr引用的是int[4]类型的数组，
//即引用的是有4个int元素的数组
void SquareArr(int(&arr)[4]) {   
    for (auto& e : arr)  //arr既然是一个真正数组，就可以用Range for循环
        e *= e;
}
int main() {
    int a[]{ 7,2,4,19 };
    SquareArr(a);
    for (auto e : a)
        std::cout << e << '\t';
}
#endif

#if 0
#include <iostream>
void h(int arr[][4], int n) {
    //p指向一个int[4]数组的指针,即指向一行对应的那个数组
    //p++就指向下一个int[4]数组
    for (auto p = arr; p != arr + n; p++) {
        for (auto e : *p)  //*p就是数组int[4]，所以可以用Range for
            std::cout << e << '\t';
        std::cout << '\n';
    }
}
int main() {
    int a[][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    h(a, 3); //必须传递a的大小
}

#endif


//-------const与形参----------
/*
void f(const int x, const int y);
void g(const int *p, const int n);
void h(int *const q, const int n);
void k(const int &r);
*/
//不能将一个const对象的指针(或引用)
// 传给一个非const的指针（引用）形参，
// const int *不能传给int*
//但反过来是可以的

#if 0
void f(int *x) {
}
void g(int& x) {
}
int main() {
    const int i{3};
 //   f(&i);
    g(i);
}
#endif

//-------可变数目的形参---------
//C语言 ...
//C++: 用C++标准库的std::initializer_list<T>类型
// 定义函数的形参
#if 0
#include <iostream>
//scores是std::initializer_list<double>类型的变量
double average(std::initializer_list<double> scores) {
    auto n{ 0 };
    double all{ 0 };
    for (auto score : scores) {
        all += score; n++;
    }
    if (n > 0)	return all /= n;
    return 0;
}

int main() {
    std::cout << average({  }) << '\n';
    std::cout << average({ 60. }) << '\n';
    std::cout << average({ 50.,80 }) << '\n';
    std::cout << average({ 90,50.,80 }) << '\n';
}
#endif

//=============递归函数===============
#if 0
#include <iostream>
int fact(int n) {
    if (n == 1)  // 如果n等于1，就直接返回值1
        return 1;
    return n * fact(n - 1);	//fact(n)等于n和fact(n-1)的乘积
}
int main() {
    std::cout << fact(4) << '\n';     //输出： 24
}
/*
递归是一个嵌套的过程，如fact(4)的递归计算过程如下：
fact(4)
 4 * fact(3)
 4 * (3 * fact(2))
 4 * (3 * (2 * fact(1)))
 4 * (3 * (2 * 1 ))
 4 * (3 * 2)
 4 * 6
 24
*/
#endif

#if 0
//斐波那契数列
#include <iostream>
int fib(int n) {
    if (n < 2)                  //基情形
        return 1;
    else                       //递归情形
        return fib(n - 1) + fib(n - 2);
}
int main() {
    for (int i{ 1 }; i != 8; i++)
        std::cout << fib(i) << '\t';
}

#endif



#if 0
#include <iostream>
int gcd(int m, int n) {
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}
int main() {
    std::cout << gcd(72, 27) << '\t' << gcd(24, 36) << '\t';
}
#endif

#if 0
auto binarySearch(int a[], const int L, const int H, int value) {
    if (L > H)           //空序列
        return -1;
    auto Middle = (L + H) / 2;
    if (a[Middle] == value) // 1）中间元素直接比较
        return Middle;
    else 	if (value < a[Middle])
        return binarySearch(a, L, Middle - 1, value);    // 2) 左区间查找
    else
        return binarySearch(a, Middle + 1, H, value);  // 3) 左区间查找
}

#include <iostream>
int main() {
    int arr[]{ 5, 7, 12, 25, 34, 37, 43, 46, 58, 80, 82, 105 };
    std::cout << binarySearch(arr, 0, 11, 25) << '\t';
    std::cout << binarySearch(arr, 0, 11, 13) << '\n';
}
#endif


#if 0
#include <iostream>
// 一个盘子：直接移动
void moveDisk(int i, const char x, const char y) {
    std::cout << "moving disk" << i << " from " << x << " to " << y << '\n';
}

// 参数：盘数, 起始柱, 中转柱, 目标柱
void move(int n, const char a, const char b, const char c) {
    if (n < 1) return;
    move(n - 1, a, c, b);  // n - 1个盘子从A柱借助于C柱移到B柱
    moveDisk(n, a, c);
    move(n - 1, b, a, c);   // n - 1个盘子从B柱借助于A柱移到C柱
}
int main() {
    move(3, 'A', 'B', 'C');
}

#endif

#if 0
using T = int;   //T是数据元素的类型
int partition(T arr[], const int start, const int end) {
    auto pivotvalue{ arr[start] };
    auto L = start + 1, R = end;

    auto done{ false };
    while (!done) {
        while (L <= R and arr[L] <= pivotvalue) L = L + 1;
        while (arr[R] >= pivotvalue and R >= L) R = R - 1;
        if (R < L)	done = true;
        else {	//交换L,R的值
            auto temp{ arr[L] };
            arr[L] = arr[R];
            arr[R] = temp;
        }
    }
    //交换R和start的值，将基准元素移到基准位置R
    auto temp{ arr[R] };
    arr[R] = arr[start];
    arr[start] = temp;
    return R;
}



// qsort是对[start, end]区间的元素进行快速排序过程
void qsort(T arr[], const int start, const int  end) {
    if (start >= end) return;
    // partition将[start, end]之间的序列一次划分为2部分，返回pivot是基准的位置
    auto pivot = partition(arr, start, end); //先对原序列一次划分
    qsort(arr, start, pivot - 1);    //对[start, pivot - 1]之间的序列调用qsort快速排序过程，
    qsort(arr, pivot + 1, end);     //对[pivot + 1, end]之间的序列调用qsort快速排序过程，	
}

void quickSort(T arr[], const int n) { //对n个元素的数组arr的快速排序
    qsort(arr, 0, n - 1); //调用对一个区间快速排序过程qsort
}

#include <iostream>
int main() {
    int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
    quickSort(a, 8);
    for (auto i{ 0 }; i != 8; i++)
        std::cout << a[i] << '\t';
    std::cout << '\n';
}

#endif



//=======函数重载与重载解析===========
/*C++同一作用域总可定义多个同名不同签名的函数，
称之为函数重载。

函数名及其形参列表构成了函数的签名，
即只要函数的签名不同，就是不同的函数。
*/

#if 0
int f() {/*...*/ }
int f(int) {/*...*/ }
int f(int, int) {/*...*/ }
double f(double) {/*...*/ }
#endif

#if 0
//同一作用域中的多个相同签名的函数，称之为重定义。
int f(int) {/*...*/ }
double f(int) {/*...*/ }
#endif

#if 0
//形参不同和形参是否const无关
void f(int) {}
void f(const int) {}

void g(int*) {}      //int对象的指针
void g(int* const) {}    //int对象的常指针
int main() {
    int i{ 0 };
    f(i);
    g(&i);
}

//因此：如果函数不修改形参，应将形参声明为const对象。
#endif

#if 0
//但下面的2个同名函数f()（或g()）的形参是不同的：
void f(int&) {}        //int对象的引用
void f(const int&) {}    //const int对应的引用

void g(int*);         //int对象的指针
void g(const int*);    //const int 对象的指针，指针不是const
int main() {
    int i{ 0 };
    f(i);
    g(&i);
}
#endif

#if 0
//当有多个同名函数时，编译器根据实参来选择一个最合适的函数。
//这个选择最佳重载函数的过程称为重载解析。

void f()
void f(int)
void f(int, int)
void f(double, double = 3.14)

int main() {
    f(5.6);
    f(3, 5.6);
}
#endif


#if 0
/*
* 在重载解析时，实参对形参的初始化和普通变量的初始化是一样的。
如，可以用const或non-const对象的指针或引用去初始化const对象
的指针或引用，
反过来，不能用const对象的指针或引用去初始化
non-const指针或引用。
*/

//复习：变量的初始化

#if 0
int main() {
    const int ci = 3; //const对象可以用non-const对象初始化
    int i = ci;       //non-const对象可以用const对象初始化
    const int j = i;  //const对象可以用non-const对象初始化
    const int& cri = i; // const对象的引用可用const或non-const值初始化，包括文字量
    const int& cr3 = 3; // const对象的引用可用const或non-const值初始化，包括文字量
    const int& crj = j; // const对象的引用可用const或non-const值初始化，包括文字量
    int& r = ci;        //non-const对象的引用（普通引用）不能用const对象初始化
    int& r = 3;        //non-const对象的引用（普通引用）不能用const对象初始化，包括文字量

    const int* cp = &i; // ok: const对象的指针可用const或non-const的指针(地址)初始化
    const int* cpj = &j; // ok: const对象的指针可用const或non-const的指针(地址)初始化
    const int* cp3 = &3; //错：文字量没有地址
    int* p = &i;       //普通指针（non-const对象的指针）可用non-const的指针(地址)初始化
    int* p2 = cp;   // error: 普通指针不能用const对象的指针初始化：p2和cp类型不匹配
    int* pj = &j;   // error: 普通指针不能用const对象的指针初始化：pj和&j类型不匹配
}
#else


//对于函数，涉及const的指针或引用的形参的初始化也是一样的，如：
void fun(int*) {/*...*/ }
void fun(int&) {/*...*/ }
void g(const int&) {/*...*/ }

int main() {
    int i = 0;
    const int ci = i;
    unsigned  ui = 0;
    fun(&i); // 调用fun(int *)
    fun(&ci); // 错: 不能将const int的指针转化为int *
    fun(i); // 调用fun(int &)
    fun(ci); // 错: 不能将普通引用int &绑定到一个const对象ci
    fun(18); // 错: 不能将普通引用int &绑定到一个文字量
    fun(ui); // 错: 类型不匹配，ui是unsigned
    g(37);   // OK: cosnt int的引用可以用文字量初始化
}
#endif

#endif 



#if 0
//inline 函数
inline int add(const int x, const int y) {
    return x + y;
}
int main() {
    add(3, 4);
}
#endif


// const表示一个对象不会改变,定义时必须初始化

#if 1
int main() {
    const int c1 = 3; 
   // const int c2; //错
   // c1 = 4; //错

    int i;
    cin >> i;
    const int c3 = i; //可以用non-const等初始化
    int arr[c1]; 
    int arr3[c3]; 
}
#endif

//constexpr关键字可以用来修饰一个变量或函数，
//用于定义一个常量表达式。

#if 0
//constexpr定义变量时，表示这是一个常量表达式，
//其值编译时确定
int  main() {
    constexpr auto pi{ 3.14 };
 //   constexpr int I; //错
    int i{ 3 };
    constexpr int ci = i;
}
#endif 

#if 0
//constexpr函数可以返回常量表达式
//但是否是常量表达式取决于函数参数
constexpr auto size1(int x) {
    int i{ 9 };	return i;
}

int main() {
    const auto b{ 4 };          //编译时常量，因为4是常量表达式
    const auto e{ size1(b) };    //编译时常量，因b是常量表达式，所以size1(b)是常量表达式

    auto a{ 3 };
    const auto d{ size1(a) };     //运行时常量，因a是变量，所以size1(a)不是常量表达式

    int arr[e];
    int brr[d];
}
#endif

#if 0
const auto size() {	      //返回一个const对象，不是常量表达式
    int i{ 9 };	return i;
}
constexpr auto size1(int x) {   //constexpr函数可以返回常量表达式
    int i{ 9 };	return i;
}
auto a{ 3 };
const auto b{ 4 };          //编译时常量，因为4是常量表达式
const auto c{ size() };       //运行时常量，因为size()函数值运行时才能确定
const auto d{ size1(a) };     //运行时常量，因a是变量，所以size1(a)不是常量表达式
const auto e{ size1(b) };    //编译时常量，因b是常量表达式，所以size1(b)是常量表达式
char arr[a], arr1[b], arr2[c], arr3[d], arr4[e];  //数组大小必须是常量表达式
#endif 



#if 1
using color = char; //不同字符模拟像素颜色

color* framebuffer{ nullptr };          //帧缓冲器
int framebuffer_width, framebuffer_height;

color clear_color{ ' ' };                //清屏颜色  

//API函数
bool initWindow(int width, int height);  //初始化一个窗口，返回bool值表示成功还是失败
void clearWindow();               //清空窗口内容
void destoryWindow();             //销毁窗口，释放帧缓冲器占用的内存
void show();                      //显示帧缓冲区的图像
void setPixel(const int x, const int y, color c = ' ');            //设置像素的颜色
color getPixel(const int x, const int y);                       //设置像素的颜色
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

void setPixel(const int x, const int y, color c) {
    framebuffer[y * framebuffer_width + x] = c;
}
color getPixel(const int x, const int y) {
    return framebuffer[y * framebuffer_width + x];
}

#include <iostream>

//初始化一个窗口，返回bool值表示成功还是失败
bool initWindow(int width, int height) {
    framebuffer = new color[width * height];
    if (!framebuffer) return false;
    framebuffer_width = width;
    framebuffer_height = height;
    clearWindow();
    return true;
}

//用清屏颜色clear_color清空窗口内容
void clearWindow() {
    auto framebuffer_size = framebuffer_width*framebuffer_height
    for (auto k = 0; k!= framebuffer_size; k++)
            framebuffer[k] = clear_color;
}

//销毁窗口，释放帧缓冲器占用的内存
void destoryWindow() {
    delete[] framebuffer;
    framebuffer = nullptr;
}

//显示帧缓冲区的图像
void show() {
    for (int y = 0; y < framebuffer_height; y++) {
        for (int x = 0; x < framebuffer_width; x++)
            std::cout << framebuffer[y * framebuffer_width + x];
        std::cout << '\n';
    }
}

#if 0
int main() {
    if (!initWindow(25, 15)) {
        return 1;
    }
    set_clear_color('-');
    clearWindow();
    int x{ 10 }, y{ 10 };
    setPixel(x, y, '*');
    setPixel(x - 1, y + 1, '*'); setPixel(x, y + 1, ' '); setPixel(x + 1, y + 1, '*');
    setPixel(x - 2, y + 2, '*'); setPixel(x - 1, y + 2, ' '); setPixel(x, y + 2, '*'); setPixel(x + 1, y + 2, ' '); setPixel(x + 2, y + 2, '*');
    show();
}
#endif

#if 0
#include <cmath>
const float PI{3.1415926};
void draw_sin_curve (int width,int height,int degree_step=5){
    
	for (int degree = 0 ; degree <= 360 ; degree = degree + degree_step ){		
		auto x = floor( degree/360.*width) +1; //+1是为了防止x=0
		auto y = floor( (sin(degree*PI/180)+1) * height/2)+1;	 //+1是为了防止y=0	
		setPixel(x,y,'*');
	}
}
int main(){	
    int width=50,height =40;
	if(!initWindow(width,height)){		
		return 1;
	}
	draw_sin_curve(width,height-2);
	show();	
}
#endif


#if 0
inline void min_max(double s[], const int n, double& min, double& max) {
    if (n <= 0) return;
    min = s[0]; max = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] < min) min = s[i];
        if (s[i] > max) max = s[i];
    }
}

inline void plot(double x[], double y[], const int n, const int win_w, const int win_h,
    const int offset = 2, const bool upset = true) {
    auto plot_w{ win_w - 2 * offset }, plot_h{ win_h - 2 * offset };
    //求x[],y[]数组中的最大值、最小值
    double x_min, x_max, y_min, y_max, x_dist, y_dist;
    min_max(x, n, x_min, x_max);
    min_max(y, n, y_min, y_max);
    x_dist = x_max - x_min;
    y_dist = y_max - y_min;
    auto scale_x = new double[n], scale_y = new double[n];
    if (!scale_x || !scale_y) return;
    //放缩到绘图plot窗口中
    for (int i = 0; i < n; i++) {
        scale_x[i] = plot_w * (x[i] - x_min) / x_dist;
        scale_y[i] = plot_h * (y[i] - y_min) / y_dist;
    }
    //绘制点集
    if (upset)
        for (int i = 0; i < n; i++)
            setPixel(scale_x[i] + offset, win_h - (scale_y[i] + offset), '*');
    else
        for (int i = 0; i < n; i++)
            setPixel(scale_x[i] + offset, scale_y[i] + offset, '*');
    delete[] scale_x;
    delete[] scale_y;
    show();
}

int main() {
    const int w = 100, h = 40;
    if (!initWindow(w, h)) {
        return 1;
    }
    double x[] = { 2014, 1600, 2400, 1416, 3000, 3670, 4500 };//房屋面积
    double y[] = { 400, 330, 369, 232, 540, 620, 800 };//房屋价格
    plot(x, y, 7, w, h);
    return 0;
}

#endif 

#endif



/*
----优化屏幕刷新（屏幕绘制）函数----
*/

#include <iostream>

using color = char;  // 定义表示颜色的类型，每种字符对应一种颜色
color* framebuffer{ nullptr };  // 帧缓冲器指针
int framebuffer_width, framebuffer_height, framebuffer_size;
color clear_color{ ' ' };         // 清屏颜色

// 初始化窗口，分配存储 width * height 个字符的内存，并用清屏颜色填充
bool initWindow(int width, int height) {
    framebuffer_size = (width + 1) * height;
    framebuffer = new color[framebuffer_size]; // 预留换行符
    if (!framebuffer) return false;
    framebuffer_width = width;
    framebuffer_height = height;

    for (int y = 0; y < framebuffer_height; y++) {
        framebuffer[y * (framebuffer_width + 1) + framebuffer_width] = '\n';
    }
    return true;
}

// 清空窗口：将帧缓冲器中每个像素设置为清屏颜色
void clearWindow() {
    for (auto y = 0; y != framebuffer_height; y++)
        for (auto x = 0; x != framebuffer_width; x++)
            framebuffer[y * (framebuffer_width + 1) + x] = clear_color;
}

// 销毁窗口，释放帧缓冲器占用的内存，并将指针置空
void destroyWindow() {
    delete[] framebuffer;
    framebuffer = nullptr;
}

// 根据坐标 (x, y) 设置对应像素的颜色
void setPixel(const int x, const int y, color c) {
    framebuffer[y * (framebuffer_width + 1) + x] = c;
}

// 根据坐标 (x, y) 获取对应像素的颜色
color getPixel(const int x, const int y) {
    return framebuffer[y * (framebuffer_width + 1) + x];
}

// 设置和获取清屏颜色
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

void show() {
    fwrite(framebuffer, 1, (framebuffer_width + 1) * framebuffer_height, stdout);
    fflush(stdout);
}

// 测试代码
int main() {
    if (!initWindow(25, 15)) {
        return 1;
    }
    set_clear_color('-');
    clearWindow();

    int x{ 10 }, y{ 10 };

    setPixel(x, y, '*');

    setPixel(x - 1, y + 1, '*'); setPixel(x, y + 1, ' ');
    setPixel(x + 1, y + 1, '*');

    setPixel(x - 2, y + 2, '*'); setPixel(x - 1, y + 2, ' ');
    setPixel(x, y + 2, '*'); setPixel(x + 1, y + 2, ' ');
    setPixel(x + 2, y + 2, '*');
    show();
}


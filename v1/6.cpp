#if 0
int Pow(int x, int e = 2) {
	auto ret{1};
	for (auto i = 0; i < e; i++)
		ret *= x;
	return ret;
}

#include <iostream>
int main() {
	std::cout << Pow(3) << '\t' << Pow(3, 4) <<'\n';
}
#endif

#if 0
#include <iostream>
void PrintArr(int arr[],int n) {
	for (auto i = 0;i<n;i++)
		std::cout << arr[i] << '\t';
}
int main() {
	int a[]{ 7,2,4,19 };
	PrintArr(a, 4);
}
#endif

# if 0
void PrintArr(int arr[], int n) {
	for (auto e :arr)
		std::cout << e << '\t';
}
#endif

#if 0
#include <iostream>
void PrintArr(int arr[], int n) {
	for (auto p=arr;p!=arr+n;p++)
		std::cout << *p << '\t';
}

void PrintArr(int arr[], int n);
void PrintArr(int arr[2], int n);
void PrintArr(int arr[10], int n);
void PrintArr(int *arr, int n);
#endif

#if 0
#include <iostream>
void SquareArr(int(&arr)[4]) {
	for (auto &e : arr)
		e *= e;
}
int main() {
	int a[]{ 7,2,4,19 };
	SquareArr(a);
	for (auto e : a)
		std::cout << e << '\t';
}
#endif

/*
void f(int arr[][4], int n); //等价于void f(int (*arr)[4], int n);
void g(int arr[][4][5], int n); //等价于void g(int (*brr)[4][5], int n);
*/

#if 0
#include <iostream>
void f(int arr[][4], int n) {
	//p指向以为数组int [4],即指向一行对应的那个数组
	for (auto p = arr; p != arr + n; p++) {
		for (auto e : *p)  //*p就是数组int[4]
			std::cout << e << '\t';
		std::cout <<'\n';
	}
}
int main() {
	int a[][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	f(a,3); //必须传递a的大小
}

#endif
#if 0
void f(const int x, const int y);
void g(const int *p, const int n);
void h(int *const q, const int n);
void f2(const int *const s, const int n);
#endif

#if 0
#include <iostream>
int fact(int n) {
	if (n == 1)  // 如果n等于1，就直接返回值1
		return 1;
	return n * fact(n - 1);	
}
int main() {
	std::cout << fact(4) << '\n';     //输出： 24
}
#endif

#if 0
#include <iostream>
int fib(int n) {
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main() {
	for (int i{1};i!=8;i++)
		std::cout << fib(i) << '\t';
}
#endif 
#if 0
#include <iostream>
int gcd(int m, int n) {
	if (n == 0)
		return m;
	else
		return gcd(n, m%n);
}
int main() {
  std::cout << gcd(72,27) << '\t' << gcd(24, 36) << '\t';
}
#endif

#if 0

#include <iostream>
auto binarySearch(int a[], const int L,const int H, int value) {
	if (L>H)           //空序列
		return -1;
	auto Middle = (L+H) / 2;
    if (a[Middle] == value) // 1）中间元素直接比较
		return Middle;
	else 	if (value < a[Middle])
		return binarySearch(a, L, Middle - 1, value);    // 2) 左区间查找
	else
		return binarySearch(a, Middle + 1, H, value);  // 3) 左区间查找
} 

int main() {
	int arr[]{ 5, 7, 12, 25, 34, 37, 43, 46, 58, 80, 82, 105 };
	std::cout<<binarySearch(arr, 0, 11,25)<<'\t';
	std::cout << binarySearch(arr, 0, 11, 13) << '\n';
}
#endif
# if 0
#include <iostream>
// 一个盘子：直接移动
void moveDisk(int i, const char x, const char y) {
	std::cout << "moving disk" << i << " from " << x << " to " << y<<'\n';
}

// 盘数, 起始柱, 中转柱, 目标柱
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

#include <iostream>

#if 0

void  partition(int a[], const int  start, const int  end) {
	auto pivotvalue = a[start];
	auto L{start + 1}, R{ end };

	auto done = false;
	while (not done) {
	}

	while L <= R and alist[L] <= pivotvalue :
		L = L + 1

		while alist[R] >= pivotvalue and R >= L :
			R = R - 1

			if R < L :
				done = True
			else :
				alist[L], alist[R] = alist[R], alist[L]
				#temp = alist[L]
				#alist[L] = alist[R]
				#alist[R] = temp

				alist[R], alist[start] = alist[start], alist[R]
				#temp = alist[start]
				#alist[start] = alist[R]
				#alist[R] = temp

				return R
}

}
void qsort(int arr[], const int start, const int  end) {
	if(start >= end) return;
	auto pivot = partition(arr, start, end)  //将[start, end]之间的序列一次划分为2部分，
		                                //  pivot是基准的位置
	qsort(arr, start, pivot - 1)    // 对[start, pivot - 1]之间的序列调用qsort快速过程，
	qsort(arr, pivot + 1, end)      // 对[pivot + 1, end]之间的序列调用qsort快速过程，
}

#endif

#if 0
int f() {/*...*/}
int f(int) {/*...*/ }
int f(int,int) {/*...*/ }
double f(double) {/*...*/ }


int f(int) {/*...*/ }
double f(int) {/*...*/ }
int f(int )
int f(const int )

int g(int*)         //int对象的指针
int g(int *const)  //int对象的常指针

int f(int&)   //int对象的引用
int f(const int&) //const int对应的引用

int g(int*)   //int对象的而指针
int g(const int *) //const int 对象的指针，指针不是const 

void f()
void f(int)
void f(int,int)
void f(double,double=3.14)

f(5.6)
#endif 

#if 0
void ff(int) { std::cout << "f(int)"; }
void ff(short) { std::cout << "f(short)"; }

int main() {
	ff('c'); //char提升为int,因此调用的是ff(int)
}

inline int add(const int x, const int y) {
	return x + y;
}
int main() {
	add(3, 4);
}
#endif

#if 0
auto f(const int a) {  /*…*/ }


const auto size() {
	int i{ 9 };
	return i;
}

const auto size() {
	int i{ 9 };
	return i;
}
constexpr auto size1(int x) {
	int i{ 9 };
	return i;
}

#endif 
#if 0
int main() {
#if 0
	const auto PI{3.14};
	PI = 3.1415926;//错:不能修改const对象
	const int ci; //错：const对象必须初始化

	auto a{2};
	const auto ca = a;  //ok：可以是一个变量
	const auto j = 42;  //ok：可以是一个文字量
	const auto k = get_size(); //ok:可以时一个运行时的值
#endif

#if 0
	auto a{3};
	const auto b{ 4 }; // //编译时常量，因为4是常量表达式
	const auto c{ size() }; //运行时常量，因为size()函数值运行时才能确定
	const auto d{ size1(a) }; //运行时常量，因a时变量，所以size1(a)不是常量表达式
	const auto e{ size1(b) }; //编译时常量，因b是常量表达式，所以size1(b)是常量表达式
	char arr[a], arr1[b], arr2[c], arr3[d], arr4[e];
#endif 

	auto a{ 3 };
	const auto b{ 4 }; //编译时常量，但不一定是常量表达式
	constexpr auto c{ 5 };//常量表达式，也是编译时常量
	constexpr auto d{ c+1 };//c是常量表达式，因此c+1也是，因此d也是常量表达式
	constexpr auto e{size()}; //错：size()函数返回的不是编译时常量
	constexpr auto f{ size1(a) }; //错：size1(a)不是常量表达式，因为a不是编译时常量
	constexpr auto g{ size1(b) };  //OK：size1(b)是常量表达式，因为b是编译时常量

}
#endif


#if 0
int main() {
	const int ci = 3; //const对象可以用non-const对象初始化
	int i = ci;       //non-const对象可以用const对象初始化
	const int j = i;  //const对象可以用non-const对象初始化
	const int &cri = i; // const对象的引用可用const或non-const值初始化，包括文字量
	const int &cr3 = 3; // const对象的引用可用const或non-const值初始化，包括文字量
	const int &crj = j; // const对象的引用可用const或non-const值初始化，包括文字量
	int &r = ci;        //non-const对象的引用（普通引用）不能用const对象初始化
	int &r = 3;        //non-const对象的引用（普通引用）不能用const对象初始化，包括文字量

	const int *cp = &i; // ok: const对象的指针可用const或non-const的指针(地址)初始化
	const int *cpj = &j; // ok: const对象的指针可用const或non-const的指针(地址)初始化
	const int *cp3 = &3; //错：文字量没有地址
	int* p = &i;       //普通指针（non-const对象的指针）可用non-const的指针(地址)初始化
	int *p2 = cp;   // error: 普通指针不能用const对象的指针初始化：p2和cp类型不匹配
	int *pj = &j;   // error: 普通指针不能用const对象的指针初始化：p2和cp类型不匹配
}

#endif 
#if 0

int f() {
	int i = 42;
	const int *cp = &i; // ok: const对象的指针可用const或non-const的指针(地址)初始化
	const int &r = i; // ok: const对象的引用可用const或non-const值初始化
	const int &r2 = 42; // ok: const对象的引用可用const或non-const值初始化，包括文字量
	int* p2 = &i;

	int *p3 = p;
	int *p = cp; // error: 普通指针不能用const对象的指针初始化：p和cp类型不匹配
	
	int &r3 = r; // error: 普通引用不能用const对象的引用初始化： r3和r类型不匹配
	int &r4 = 42; // error: 普通引用不能用常量初始化
}


#endif

#if 0
void fun(int *) {/*...*/ }
void fun(int &) {/*...*/ }
void g(const int &) {/*...*/ }

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

#if 0
#include <iostream>
double average(std::initializer_list<double> scores){
	auto n{ 0 };
	double all{ 0 };
	for (auto score : scores) {
		all += score; n++;
	}
	if(n>0)	return all /= n;
	return 0;
}
int main() {
	std::cout << average({  }) << '\n';
	std::cout << average({60.}) << '\n';
	std::cout << average({ 50.,80 }) << '\n';
	std::cout << average({ 90,50.,80 }) << '\n';
}
#endif 

#if 0
#include <iostream>
int main(){
	while (true) {
		static auto i{ 0 }; //i是一个静态局部变量
		if (i++ < 6) std::cout << i << '\t';
		else break;
	}
}

#endif 

#if 0
#include <iostream>
void  f() {
	static auto i{ 0 };
	int j{ 0 };
	i++;  j++;
	std::cout << i << '\t' << j << '\n'; 
}

int main() {
	f();
	f();
}

#endif 

#if 0 

using T = int;
int partition(T arr[], const int start, const int end){
	auto pivotvalue{ arr[start] };
	auto L = start + 1, R = end;

	auto done{ false };
	while (!done) {
		while (L <= R and arr[L] <= pivotvalue)
			L = L + 1;
		while (arr[R] >= pivotvalue and R >= L)
			R = R - 1;
		if (R < L)
			done = true;
		else {
			//交换L,R的值
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

// 对[start, end]区间的元素进行快速排序
void qsort(T arr[], const int start, const int  end) {
	if (start >= end) return;
	//partition将[start, end]之间的序列一次划分为2部分，返回pivot是基准的位置
	auto pivot = partition(arr, start, end);
	qsort(arr, start, pivot - 1);    //对[start, pivot - 1]之间的序列调用qsort快速过程，
	qsort(arr, pivot + 1, end);     //对[pivot + 1, end]之间的序列调用qsort快速过程，	
}

void quickSort(T arr[], const int n) {
	qsort(arr, 0, n - 1);
}


int main() {
	int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
	quickSort(a, 8);
	for (auto i{ 0 }; i != 8; i++)
		std::cout << a[i] << '\t';
	std::cout << '\n';
}
#endif 


#if 0
bool  go_maze(int maze[][6], const int x, const int  y,const int n = 6) {
	//该位置是否终点（2）、墙（1）、已经走过（3）
	if (maze[x][y] == 2) {
		std::cout << "到达终点：" << x << "," << y << '\n';
		return true;
	}
	else if (maze[x][y] == 1) {
		//std::cout << "墙：" << x << "," << y<<'\n';
		return false;
	}
	else if (maze[x][y] >= 3) {
		//std::cout << "已经访问过：" << x << "," << y << '\n';
		return false;
	}
	//从该位置向4邻探索
	std::cout << "访问：" << x << "," << y << '\n';
	maze[x][y] = 3;          // 标记该位置已经访问过
	// 向4邻探索
	if ((x < n - 1 and go_maze(maze,x + 1, y))
		or (y > 0 and go_maze(maze, x, y - 1))
		or (x > 0 and go_maze(maze, x - 1, y))
		or (y < n - 1 and go_maze(maze, x, y + 1)))
		return true;

	maze[x][y] = 4;     //此路也不通
	return false;	
}

void print(int maze[][6], const int n = 6) {
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < n; j++) {
			std::cout << maze[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

int main() {
	int maze[][6] = { {0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0 },
		{0, 1, 1, 0, 0, 1},
		{0, 1, 0, 0, 1, 0 },
		{0, 1, 0, 0, 0, 2} };

	go_maze(maze, 0, 0);
	print(maze);
}
#endif
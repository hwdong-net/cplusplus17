/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include <iostream>
#if 0
double average(const double *arr,const int n) {
	auto ave = arr[0];
	for (auto i = 1; i != n; i++) ave += arr[i];
	ave /= n;
	return ave;
}

using AVE_PTR = double(*)(const double *, const int);
typedef double(*AVE_PTR)(const double *, const int);

int main() {
#if 0
	double(*pf)(const double *, const int) = average;
	double(*pf2)(const double *, const int) = &average;
	std::cout << average <<'\t'<< &average << '\n';
	std::cout << *pf << '\t' << *pf2 << '\n';
#endif
	auto pf = average;
	AVE_PTR pf = average;

	double a[]{ 1,2,3,4,5 };
	std::cout << pf(a, 5) << '\t' << average(a, 5) << '\n';
}
#endif

#if 0
template<typename T>
T find_optimal(const T *arr,const int n, bool (*compare)(const T&,const T&) ) {
	T opt{ arr[0] };
	for (auto i = 0; i != n; i++)
		if (compare(arr[i], opt))  //arr[i]比opt更好
			opt = arr[i];
	return opt;
}

template<typename T>
bool less(const T& a, const T& b) { return a < b; }

template<typename T>
bool greate(const T& a, const T& b) { return a >= b; }

template<typename T>
bool lessAbs(const T& a, const T& b) { return std::abs(a) < std::abs(b); } //绝对值小优先

template<typename T>
using COMPARE_PTR = bool (*)(const T&, const T&);

int main() {
	double a[]{ 9,-3,2,-7 };
	COMPARE_PTR<double> pf = less;  //auto pf = less<double>;
	std::cout << find_optimal(a, 4, pf) << '\t';

	pf = greate;
	std::cout << find_optimal(a, 4, pf) << '\t';

	pf = lessAbs;
	std::cout << find_optimal(a, 4, pf) << '\t';
}

#endif 

#if 0
class LessThan {
public:	
	bool operator() (double a, double b) const{ return a < b; }
};

int main() {
	double x{ 3 }, y{ 4 };
	LessThan le;
	//if (le(x, y)) std::cout << "x<y\n";
	if (le.operator()(x, y)) std::cout << "x<y\n";
}
#endif 

#if 0
template<typename T,typename CompareT>
T find_optimal(const T *arr, const int n, CompareT compare){
	T opt{ arr[0] };
	for (auto i = 0; i != n; i++)
		if (compare(arr[i], opt))  //arr[i]比opt更好
			opt = arr[i];
	return opt;
}

template<typename T>
class LessThan {
public:
	bool operator() (T a, T b) const { return a < b; }
};

template<typename T>
class Nearest {
	T x;
public:
	Nearest(T x) :x{ x } {}
	bool operator() (T a, T b) const {
		return std::abs(a - x) < std::abs(b - x); }
};

#include<functional>

template<typename T>
bool greate(const T& a, const T& b) { return a >= b; }
bool lessAbs(const double& a, const double& b) { return std::abs(a) < std::abs(b); }
int main() {
	double a[]{ 9,-3,2,-7 };
#if 0
	std::cout << find_optimal(a, 4, LessThan<double>()) << '\t';	
	std::cout << find_optimal(a, 4, greate<double>) << '\t';
	std::cout << find_optimal(a, 4, lessAbs) << '\t';
#else 
	for (auto &e : a)
		std::cout << e << '\t';
	std::cout << '\n';

	std::cout << "输入一个数值：\n";
	double x;  std::cin >> x;
	std::cout << find_optimal(a, 4, Nearest(x)) << '\t';

//	std::cout << find_optimal(a, 4, std::less<>{}) << '\t';
#endif 
//	std::cout << find_optimal(a, 4, std::greater<>{}) << '\t';
}

#endif

#if 0
int main() {
	double x{ 3 }, y{ 4 };
	auto less =  [](double x, double y)->double { return x < y; };
	//auto less{ [](double x, double y) { return x < y; } };
	std::cout << less(x, y) << '\n';
}
#endif




#if 0
template<typename T, typename CompareT>
T find_optimal(const T *arr, const int n, CompareT compare) {
	T opt{ arr[0] };
	for (auto i = 1; i != n; i++)
		if (compare(arr[i], opt))  //arr[i]比opt更好
			opt = arr[i];
	return opt;
}

int main() {
	double a[]{ 9,-3,2,-7 };
//	std::cout << find_optimal(a, 4, [](double x, double y) { return x < y; }) << '\t';	

	std::cout << "\n输入一个数值：\n";
	double v;  std::cin >> v;
	std::cout << find_optimal(a, 4, [v](double x, double y) {
		return std::abs(x-v) < std::abs(y-v); }) << '\t';
}
#endif

#if 0
int main() {
	double a[]{ 7,1,5,9 };
	
	std::cout << "\n输入一个数值：\n";
	double v;  std::cin >> v;
	std::cout << find_optimal(a, 4, [=](double x, double y) {
		return std::abs(x - v) < std::abs(y - v); }) << '\t';
}
#endif

#if 0
int main() {
	double a[]{ 7,1,5,9 };
	
	int count = 0;
	std::cout << "输入一个数值：\n";
	double v;  std::cin >> v;
	std::cout << find_optimal(a, 4, [&](double x, double y) {
		a[count] -= v;
		count++;  //比较的次数累加
		return std::abs(x - v) < std::abs(y - v); 
	});
	std::cout << "\t比较的次数：" << count << '\n';
	std::cout << "修改了的a值：" ;
	for (auto e : a)
		std::cout << e << '\t';	
}
#endif 

#if 0
class X {
	double value{ 0. };
public:
	X(double x) :value{ x } {}
	double find_nearest(const double arr[], const int n) {
		//...
		return find_optimal(arr, n, [this](double a, double b) {
			return std::abs(a - this->value) < std::abs(b - this->value); });
	}
};

int main() {
	double a[]{ 7,1,5,9 };
	std::cout << "输入一个数值：\n";
	double v;  std::cin >> v;
	X x(v);
	std::cout << x.find_nearest(a, 4) << '\n';
}
#endif

#if 0
https://blog.feabhas.com/2014/03/demystifying-c-lambdas/

[](X &elem) {elem.op(); }

class _complieGeneratedName_ {
public:
	void operator() { X &elem }const {
		elem.op();
	}
};

[value](X &elem) {elem.op(); }

class _complieGeneratedName_ {
	double value{};
public:
	void operator() { X &elem }const {
		elem.op();
	}
};
#endif 


#include <functional>
int less(const int& a, const int& b) { return a < b?a:b; }

template<typename T>
int greate(const T& a, const T& b) { return a > b ? a : b;}

class  Less{
public:
	int operator()(const int& a, const int& b) { return a < b ? a : b; }
};

#if 0
int main() {
	int a{ 3 }, b{ 8 };
	std::function< int(int x, int y)> compare;
	compare = less;
	std::cout << compare(a, b) << '\t';
	compare = Less();
	std::cout << compare(a, b) << '\t';
	compare = greate<int>;
	std::cout << compare(a, b) << '\t';
	int v{ 3 };
	compare = [v](int a, int b) { auto x{std::abs(a - v)}, y{ std::abs(b - v)};
	                              return x<y?a:b; };
	std::cout << compare(a, b) << '\n';
}
#endif 

#if 0
int main() {
	int a{ 3 }, b{ 8 };
	int v{ 4 };
	std::function< int(int x, int y)> cmp_arr[]{
		less,Less(),greate<int>,
		[v](int a, int b) { 
		         auto x{std::abs(a - v)}, y{ std::abs(b - v)};
					return x < y ? a : b; }
	};

	for(auto i = 0 ;i!=size(cmp_arr);i++)
		std::cout << cmp_arr[i](a, b) << '\t';	
}
#endif 

#if 0
template<typename Iterator, typename CompareT>
Iterator find_optimal(Iterator begin, Iterator end, CompareT compare) {
	if (begin == end) return end;
	Iterator optimum = begin;
	for (Iterator iter = ++begin; iter != end; ++iter)
	{
		if (compare(*iter, *optimum))
		{
			optimum = iter;
		}
	}
	return optimum;	
}

#include <iostream>
int main() {
	std::vector<int> arr{ 3,11,51,25,7,39,68 };
	
	std::cout << "输入一个数值：\n";
	double v;  std::cin >> v;
	std::cout << *find_optimal(arr.begin(),arr.end(), [=](double x, double y) {
		return std::abs(x - v) < std::abs(y - v); }) << '\t';	
	
	std::cout << *find_optimal(arr.begin()+2, arr.end()-2, [=](double x, double y) {
		return std::abs(x - v) < std::abs(y - v); }) << '\t';

	int arr2[]{ 19,3,24,42,53,26 };
	std::cout << *find_optimal(std::begin(arr2) + 1, std::end(arr2) - 1, [=](double x, double y) {
		return std::abs(x - v) < std::abs(y - v); }) << '\t';
}
#endif 

#if 0

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
	int arr[]{ 19,3,24,42,53,26 };	
	auto [min_it,max_it] = std::minmax_element(std::begin(arr), std::end(arr));
	std::cout << "最小值、最大值分别为: " <<*min_it<< '\t' << *max_it << '\n';;
	
	double v;  std::cin >> v;
	auto[near_it, far_it] = std::minmax_element(std::begin(arr), std::end(arr),
		[v](const auto &x, const auto &y) {return std::abs(x - v) < std::abs(y - v); });
	
	std::cout << "最小值、最大值分别为: " << *near_it << '\t' << *far_it << '\n';
}
#endif

#if 1
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>  //accumulate所在头文件

template<typename T>
void printVec(std::vector<T> &vec) {
	for (auto a : vec) {
		std::cout << a << " ";
	}
	std::cout << '\n';
}

#if 0
int main() {
	std::vector<int> arr{ 19,3,24,42,53,26 };
	printVec(arr);
	std::reverse(arr.begin(), arr.end());
	printVec(arr);
	std::accumulate(arr.begin(), arr.end(),5, std::multiplies<int>());//累积乘法
	printVec(arr);
	std::sort(arr.begin(), arr.end());
	printVec(arr);
	std::sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {return a > b; });
	printVec(arr);
}
#endif 


#if 0
find(first,last,value)
find_if(first,last, p)
find_if_not(first, last, p)
find_first_of(first,last,forward_first,forward_last,p)
#endif 

#if 0
int main() {
	std::vector<int> v{ 3,53,1,19,24,42,3,26 };
	std::cout << "3出现的次数：" << std::count(v.begin(), v.end(), 3) << '\n';
    auto it = std::find(v.begin(), v.end(), 3);
	if (it != v.end()) std::cout << *it << '\t';
	auto x{ 6 };
	//第一个大于x的元素
	it = std::find_if(v.begin(), v.end(), [x](const auto &a) {return a > x; });
	if (it != v.end()) std::cout << *it << '\t';
	//第一个不大于x的元素
	it = std::find_if_not(v.begin(), v.end(), [x](const auto &a) {return a > x; });
	if (it != v.end()) std::cout << *it << '\t';
}
#endif 


#if 0
int main() {
	std::vector<int> v{ 0, 2, 3, 25, 5 };
	std::vector<int> t{ 3, 19, 10, 2 };
	auto result = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());
	if (result != v.end()) { std::cout << *result << '\t'; }

	result = std::find_first_of(v.begin(), v.end(), t.begin(), t.end(),
		[](const auto &a, const auto &b) {return a > b; });
	if (result != v.end()) { std::cout << *result << '\n'; }
}
#endif 

#if 0
int main() {
	std::vector<int> v{10, 20, 30, 30, 20, 10, 10, 20};
	std::sort(v.begin(), v.end());
	printVec(v);
	if (binary_search(v.begin(), v.end(), 20))
		std::cout << "存在等于20的元素\n";
	auto low = std::lower_bound(v.begin(), v.end(), 20);           
	auto up = std::upper_bound(v.begin(), v.end(), 20);
	std::cout << *low<< '\t' << *up << '\t';

}
#endif 


#endif

#if 0
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a)IntP p0(ix);
(b)IntP p1(pi);
(c)IntP p2(pi2);
(d)IntP p3(&ix);
(e)IntP p4(new int(2048));
(f)IntP p5(p2.get());
#endif
#if 0
#include <functional>
double square(double x) { return x * x; }

int main() {
	//auto f = std::bind(square, 3.5);
	std::function<double ()> f= std::bind(square, 3.5);
	std::cout<<f();
}

#endif

#if 0
#include <functional>
#include <iostream>

using namespace std::placeholders;

int area(double pi, double r){
	return pi * r*r;
}

int main(){
	auto f = bind(area, 3.14, _1);
	std::cout << "3.14 *2.5*2.5 " <<  " = " << f(2.5)<<'\n';	
	return 0;
}
#endif
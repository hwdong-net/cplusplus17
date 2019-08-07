/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include <iostream>
using std::cout;
#if 0
int main() {
//	const int i = 3; //const表示变量i是不可被修改的
//	i = 4; //错：试图修改const对象
	const int j; //错：i没有初始化
}
#endif 

#if 0
int main() {
	int a[]{ 12,46,25,43,58,7,37,5,80,34,105,82 };
	auto x{ 0 };
	bool found{ false };
	std::cin >> x;
	for (auto e : a)
		if (e == x) {
			found = true;
			break;
		}
	if (found)
		std::cout << "在数组a中找到了：" << x<<'\n';
	else 
		std::cout << "在数组a中未找到：" << x<<'\n';
}
#endif

#if 0
int main() {
	int a[]{ 5,7,12,25,34,37,43,46,58,80,82,105 };
	auto x{ 0 };	
	std::cin >> x;

	auto L{ 0 }, H{ 9 }; 
	while (L <= H) {                  // 区间[L，H]存在
		auto Middle{ (L + H) / 2 };    // Middle指向区间的中点
		if (a[Middle] == x)         // 等于Middle指向的元素，找到了！		
			break;
		else if (x < a[Middle])
			H = Middle - 1;       // 在左区间查找
		else
			L = Middle + 1;       // 在右区间查找
	}
	
     if(L<=H)
		 std::cout << "在数组a中找到了：" << x << '\n';
	 else
		 std::cout << "在数组a中未找到：" << x << '\n';
}
#endif

#if 0
#include <iostream>
int main() {
	int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
	for (auto i = 7; i > 0; i--) {
		//对[0,i]之间的序列进行“一趟冒泡”
		for (auto j = 0; j < i; j++)
			if (a[j] > a[j + 1]) {//交换它们
				auto t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
		//输出序列
		for (auto e : a)
			std::cout << e << '\t';
		std::cout << '\n';
	}
}
#endif

#if 0
#include <iostream>
int main() {
	int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
	for (auto r = a+7; r>a; r--) {
		//对[0,i]之间的序列进行“一趟冒泡”
		for (auto p = a; p < r; p++)
			if (*p > *(p + 1)) {//交换它们
				auto t = *p; *p = *(p+1); *(p+1) = t;
			}
		//输出序列
		for (auto e : a)
			std::cout << e << '\t';
		std::cout << '\n';
	}
}
#endif

#if 0

#include <iostream>
int main() {
	auto n{ 4 };
	//	auto INFINITY =  std::numeric_limits<double>::max();
	double D[][4]{ {0, 2, 6, 4},
				{INFINITY, 0, 3, INFINITY},
				{7, INFINITY, 0, 1 },
				{5, INFINITY, 12, 0} };

	unsigned int P[][4]{ {0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0} };
	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++)
			P[u][v] = u;
	//打印D和P矩阵
	for (auto& row : D) { //row是引用ia的每个元素，因此row是一个int[4]的数组
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << '\n';
	for (auto& row : P) { //row是引用ia的每个元素，因此row是一个int[4]的数组
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << std::endl;

	//Floyd算法
	for (auto w = 0; w < n; w++)
		for (auto u = 0; u < n; u++)
			for (auto v = 0; v < n; v++)
				if (w != u and w != v and D[u][w] + D[w][v] < D[u][v]) {
					D[u][v] = D[u][w] + D[w][v];
					P[u][v] = P[w][v];
					//打印D和P矩阵
					for (auto& row : D) { //row是引用ia的每个元素，因此row是一个int[4]的数组
						for (auto col : row)
							cout << col << '\t';
						cout << '\n';
					}
					cout << '\n';
					for (auto& row : P) { //row是引用ia的每个元素，因此row是一个int[4]的数组
						for (auto col : row)
							cout << col << '\t';
						cout << '\n';
					}
					cout << std::endl;					
				}
		
	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++) {
			if (u == v) continue;
			cout << u << "到" << v << "的逆向路径是:";
			cout << v << ',';
			auto w{ P[u][v] };
			for (auto w{ P[u][v] }; w != u;) {
				cout << w << ',';
				w = P[u][w];				
			}
			cout << u << std::endl;
		}

}

#endif

#if defined USING_COMPILER_A
using Int32 = __int32;
using Int64 =  __int64;
#elif defined USING_COMPILER_B
using Int32 = int;
using Int64 = long long;
#endif

#if 0
using StrPtr = std::shared_ptr<std::string>;

enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

#include <iostream>
int main() {
	Day d{Day::Tuesday };
	std::cout << static_cast<int>(d) << '\t';
}

//enum class Day { Monday=3, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
//enum class Day { Monday = 3, Tuesday=6, Wednesday= Monday+5, Thursday, Friday, Saturday, Sunday };
#endif

#if 0
int g_var;

int main() {
	int var{2};	
	{
		std::cout << g_var << '\t' << var << '\n';
		int var{ 0 };
		var = 5;
		std::cout << g_var << '\t' << var << '\n';
	}
	std::cout << g_var << '\t' << var << '\n';
}
#endif 

#if 0
enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
#include <iostream>
int main() {
	Day d{ Day::Tuesday };
	std::cout << (int)d << '\t';
	std::cout << static_cast<int>(d) << '\t';
}
#endif 

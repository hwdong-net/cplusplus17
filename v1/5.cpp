/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#if 0
#include <iostream>
int main() {
	int i{0};
	int *const p = &i;
	const int *q = &i;
	int const *s = &i;
	*p = 2;  //p不能被修改，但它指向的int类型变量是可以被修改的
	std::cout << *p << '\t' << *q << '\t' << *s << '\n';
	int j{ 3 };
	q = &j;
	s = &j;
	std::cout << *p << '\t' << *q << '\t' << *s << '\n';
	p = &j;
	*q = 4;
	*s = 4;
}
#endif

#if 0
int main() {
	int a{ 3 }, b{ 4 };
	{
		int c{ 5 };
	}
	a = 2;
}
#endif 

#if 0
#include <iostream>
int main() {
	double *p{}; //初始化指针变量p为空指针，等价于double *p{nullptr}
	p = new double; //p存储new分配内存的地址
	double *q{};
	q = new double[3]; //q存储new分配内存的地址
	
	*p = 3.14; //*p就是p指向的那个double变量
	*q = 3.15; //*q就是q指向的那个double变量
	*(q + 1) = 3.16; //*(q+1）就是q+1指向的那个double变量
	*(q + 2) = 3.17; //*(q+2）就是q+2指向的那个double变量
	*(q + 3) = 3.17; //*(q+3）就是q+3指向的那个double变量
	                  //但q+3指向的内存不属于分配的内存块，无法访问，因此出错！
	*(p + 1) = 2.5; //错：p+1的内存不属于程序
	*(q - 1) = 2.5; //错：q-1的内存不属于程序
	for (auto i = 0; i < 3; i++)
		q[i] += 2;
	for (auto i = 0; i < 3; i++)
		std::cout << q[i] << '\t';
	delete p;
	delete[] q;
}
#endif
#if 0
#include <iostream>
int main() {
	double scores[100][4]; //最多可以存储100个学生成绩
	int n = 0; //学生人数
	int cols; //每个学生的成绩个数
	std::cin >> n>> cols;
	//double *scores = new double[n][cols];

//	double (*p)[4] = new double[4]; //分配一个double[4]的空间.

//	double (*scores)[4] = new double[n][4];
	auto scores = new double[n][4];
}
#endif

#if 0
#include <iostream>
int main() {	
	int n = 0; //学生人数
	int cols; //每个学生的成绩个数
	std::cout << "输入学生人数\n";
	std::cin >> n ;
	auto scores{ new double[n][4]};
	std::cout << "输入学生的平时、实验、期末、总评成绩\n";
	for (auto i = 0; i != n; i++) {
		std::cin >> scores[i][0] >> scores[i][1]
			>> scores[i][2] >> scores[i][3];
	}
	for (auto i = 0; i != n; i++) {
		std::cout << scores[i][0] <<'\t'<< scores[i][1]	<< '\t' 
			<< scores[i][2] << '\t' << scores[i][3] << '\n';
	}
}
#endif

#if 0
//const对象的引用：reference to const
int main() {
	int i = 42;
	const int ci = 1024; //ci是const int对象，即不能修改的int，也称为常量
	const int &r1 = ci;   // r1是const对象的引用						
	const int &r2 = i;    // 绑定const int&到一个普通的int对象	
	const int &r3 = 42;   // 绑定const int&文字量
	const int &r4 = r1 * 2; // 绑定const int&到表达式 

	r1 = 42; // 错: const对象的引用 不能用于修改 
	r4 = 42;

	int &r5 = ci; // 错: 普通变量的引用不能引用const对象
	int &r6 = i * 2; // error: 普通变量的引用不能引用表达式
	int &r7 = 6; //不能引用文字量

	double dval = 3.14;
	const int &r8 = dval; //dval是double类型，而r8是const int类型的引用。

	const int temp = dval;
	const int &r8 = temp;

	int j = 4;
	int &r9 = j;
	const int &r10 = j;
	r9 = 0; //也就是j = 0
	r10 = 0; //不可以，因为r10是const int的引用。
}


#endif 

#if 0
//指针和const
int main() {
	char *const cp; // 指向char的const指针
	char const* pc; // 指向const char的指针
	const char* pc2; //指向const char的指针
	const char* const pc3; //指向const char的const指针


	int a = 0;
	const int b = a;
	const int *pa = &a;
	*pa = 4;  //错：指向const对象
	pa = &b;  //指针可以修改
	int *const pa2 = &a;
	pa2 = &b;  //错：const指针不能被修改
	int* pb = &b; //错：普通指针不能指向const对象，
				  //否则，不就可通过*pb修改const对象了？
	const int *pb2 = &b;
	pb2 = &a;
	const int *const pb3 = &b;
	const int *const pb4 = &a;
	pb4 = pb3; //错：pb4不能被修改
	*pb4 = 9; //错：pb4指向的const对象，不能修改



	char s[] = "Gorm";
	const char* pc = s; // 指向const char的指针
	pc[3] = 'g'; // 错 : 指向const char的指针
	pc = p; // OK
	char *const cp = s; // 指向char的const指针
	cp[3] = 'a'; // OK
	cp = p; // 错 : cp 是const指针
	const char *const cpc = s; // //指向const char的const指针
	cpc[3] = 'a'; // 错: cpc指向const char
	cpc = p;     // 错 : cpc 是const指针
}
#endif 

#if 0
int f() {
	int i{0};
	int *const p1 = &i;
	const int ci = 42;
	const int *p2 = &ci;
	const int *const p3 = p2;
	const int &r = ci;

	int *p = p3;
	p2 = p3;
	p2 = &i;
	int &r1 = ci;
	const int &r2 = i;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ia[3][4];
	auto cnt{ 0 };
	for (auto &row : ia)  //对ia的每个元素（每行）
		for (auto &col : row) {  //对row的每个元素（每列）
			col = cnt;     cnt++; //可以合并为一句： col = cnt++;
		}
	//输出   
	for (auto &row : ia) {
		for (auto &col : row)
			cout << col << '\t';
		cout << '\n';
	}

	for (auto& row : ia) 
		for (auto col : row) //错：row是一个指针，
				 //而对于指针是无法使用Range for的
			cout << col << '\t';
	

}

#endif

#if 0
#include <iostream>
using namespace std;
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
				}
	//打印D和P矩阵
	for (auto& row : D) {
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << '\n';
	for (auto& row : P) {
		for (auto col : row)
			cout << col << '\t';
		cout << '\n';
	}
	cout << std::endl;	
}
#endif
#if 0

int main() {
	int& ref4{ 10 };  //错： 不能引用文字量
	double dval{ 3.14 };
	int& ref5{ dval };  //错：引用变量类型和被引用变量类型不一致
}
#endif

#if 0

int main() {
	double* s;
	double& r;
}
#endif

#if 0
int main() {
	int zero{ 0 }, * p1;
	//int* p2{ zero };
	int* p{ 0 };
	int* p3{ 3 };

}
#endif

#if 0
#include <iostream>
int main() {
	int i;
	int* p{ &i }, * q{ 0 };
	bool b{ p };  // int*非空指针p转化为bool型值true,
				  // 然后对b初始化，因此，b的值是true
	std::cout << std::boolalpha << b << std::endl; //boolalpha操作符控制bool量的显示形式
	b = q;       // int *空指针q转化为bool型值false,
				  // 然后赋值给b，因此，b的值是false;
	std::cout << std::boolalpha << b << std::endl;
}
#endif

#if 0
#include <iostream>
int main() {
	int* pi;
	void* pv = pi; // ok: int*到 void*的隐式类型转换
	//*pv;    //错 :不能解引用 void*
//	++pv;   //错: 不能增量或偏移 void* (指向对象的内存大小未知)
	int* pi2 = static_cast<int*>(pv); // void* 强制类型转换到int*
	double* pd1 = pv;   // 错:不能将void*初始化或赋值给非void*指针变量
	double* pd2 = pi; // 错：指针类型不一致
	double* pd3 = static_cast<double*>(pv); // 不安全
}
#endif

#if 0
#include <iostream>
int main() {
	int i = 3;
	int* pi = &i;
	std::cout << i << "\t" << *pi << std::endl;
	void* pv = pi; // ok: int*到 void*的隐式类型转换
	//*pv=4;    //错 :不能解引用 void*
//	++pv;   //错: 不能增量或偏移 void* (指向对象的内存大小未知)
	int* pi2 = static_cast<int*>(pv); // void* 强制类型转换到int*
	*pi2 = 4;
	std::cout << i << "\t" << *pi << "\t" << *pi2 << std::endl;

	//double* pd1 = pv;   // 错:不能将void*初始化或赋值给非void*指针变量
	//double* pd2 = pi; // 错：指针类型不一致
	double* pd3 = static_cast<double*>(pv); // 不安全
	*pd3 = 3.14;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ival{ 1024 };
	int* pi{ &ival };  //pi 存储ival的地址
	int** ppi{ &pi }; // ppi存储pi的地址。 pi的类型是int *，
				   // 所以&pi的类型 (int *) *，即 int **，int **就是(int *)*
				   // ppi ---> pi -->ival  
	cout << "ival的值是： " << ival << endl;
	cout << "ival的值是： " << *pi << endl;    // *pi就是ival
	cout << "ival的值是：" << **ppi << endl;  // **ppi即 *(*ppi)，而*ppi就是pi，
 // 因此，**ppi就是 *(pi)即ival

	cout << "\nival的地址是：" << &ival << endl;
	cout << "ival的地址是：" << pi << endl;   //pi保存的是ival的地址
	cout << "ival的地址是：" << *ppi << endl; //*ppi就是pi

	cout << "\npi的地址是：" << &pi << endl;
	cout << "pi的地址是：" << ppi << endl;   //pi保存的是ival的地址  
}

#endif

#if 0
int main() {
	auto i{ 0 }, j{ 1 };
	int* p;            //指针变量不一定要初始化
	int& r{ i };
	int &r1;     //错：引用变量r1没有初始化！
	p = &i;          //p指向i
	p = &j;        //p指向j
	auto * &rp{ p };    // rp引用p
//	int*& rp2;       //错：引用变量rp2没有初始化
//	int&* q;         //错： 不能定义指向引用的的指针，
					// 因为引用变量没有独立内存(即没有地址)
	int&* q2 = &r;  //错：原因同上. 另外，取地址运算符&不能作用于引用变量r！ 
}
#endif

#if 0
int main() {
	int  s = 20;
	int arr[20];
}
#endif

#if 0
#include <iostream>
int main() {
	int  s = 20;
	int arr[20];

	int v5[4]{ 1,2,3 }; //列表中的个数少于数组大小，剩余的数组元素的值取默认值，
//对于内在类型，默认值通常是0，即等价于int v5[4] = {1,2,3,0}
	std::cout << v5[0] << '\t' << v5[1] << '\t' << v5[2] 
		<< '\t' << v5[3] << std::endl;

	char a1[]{ 'C','+','+' }; //a1是3个char字符的数组
	char a2[]{ 'C','+','+','\0' }; //a2是4个char字符的数组，最后一个字符是结束字符
	char a3[]{ "C++" }; //用字符串文字量对字符数组a3初始化，
	//因为文字量字符串有一个隐含的结束字符 '\0'
	//因此a3实际是4个字符，即相当于char a3[] = {'C','+','+','\0'};
//	char a4[5]{ "Hello" }; //错：空间不够！因为文字量字符串"Hello"实际有6个字符。
	char a5[6]{ "Hello" }; //OK：空间正好
	char a6[9]{ "Hello" }; //OK：空间足够。问：a6的第7，8字符是什么呢?

}
#endif

#if 0
#include <iostream>
int main() {
	int ar[3]; //3个int元素的数组
	int arr[10]; //10个int元素的数组, int[10]
	int* ptrs[10]; //10个int*元素的数组
	int(*parr)[10]; //parr是一个指针，指向的是int[10]的数组，
	//即指向的是10个int元素的数组，
	//或者说它存储的是int[10]数组的地址
	parr = &arr; //将 int[10]类型数组arr的地址赋值给 parr
	   //  int(*)[10]
	parr = &ar; //错：类型不一致！ ar的类型是 int[3]而不是int[10]。

	int(&ref_arr)[10] = arr; //ref_arr是一个引用变量，引用的是10个int元素的数组，
                    // 而arr正好是10个int的数组
	int(&ref_arr2)[10] = ar; //错：ref_arr是一个引用变量，
	               //引用的是10个int元素的数组，
	                  // 而ar是3个int的数组。类型不一致！

}
#endif

#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char s[] = { 'C','+','+' }; //字符数组，但不是C风格字符串
	char s2[] = { 'C','+','+','\0' }; //带结束字符'\0'的字符数组是C风格字符串
	cout << strlen(s) << '\t' << strlen(s2) << endl;
}
#endif

#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char s[] = "A string example"; //用字符串文字量初始化字符数组，结果包含了结束字符
	char s2[] = "A hello world";
	int ret = strcmp(s,s2); //返回负数表示s<s2，返回0表示s==s2，返回正数,表示s>s2
	if (ret < 0)
		cout << "s<s2" << endl;
	else if (ret == 0)
		cout << "s==s2" << endl;
	else
		cout << "s>s2" << endl;
}
#endif

#if 0
/* strchr 例子 */
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char str[] = "This is a sample string";
	const char* pch;
	std::cout << "字符s在字符串" << str << "出现的位置\n";
	pch = strchr(str, 's');
	while (pch != 0) {
		std::cout << "s出现在" << pch - str + 1 << '\n';
		pch = strchr(pch + 1, 's');
	}
	return 0;
}


#endif

#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int v[]{ 10,20,30,40 };
	int* p1{ &(v[0]) }; //p1存储的是第一个元素v[0]的地址
		int* p2{ v };     //数组名就是数组的第一个元素的地址,等价于 int *p2{&(v[0])};
	int* p3{ v + 4 };   //v是第一个元素的指针，向后偏移4个int元素空间，
					//因此v+4指向的是最后一个元素v[3]再偏移一个int空间的地址
	std::cout << *(p1 + 2) << endl; // *(p1+2)等价于*(v+2),该语句输出第3个元素
}

#endif

#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int v[] = { 1,2,3,4 };
	int* p = v;
	p[2] = 20 + *(v + 3);
	int b = *(p + 2), c = v[2], d = *(v + 2);
	std::cout << b << '\t' << c << '\t' << d << '\t' << *p << '\n';

	p++;   //p从v向后偏移1个int占据的空间(4个字节)，即p指向v[1]
	p++;   //p指向v[2]

	std::cout << b << '\t' << c << '\t' << d << '\t' << *p << '\n';
	
	p -= 2;  //p向前偏移2个int占据的空间，即地址减去了8个字节,
		  //p指向了第一个元素
	std::cout << *p << std::endl;
	p--;    //语法不错，但其指向的地址已经不属于数组v了。
	std::cout << *p << std::endl;  //语法不错，但*p访问了一个不属于自己的内存块，
						   //运行程序时会崩溃！
#if 1
	int ival = 1024;
	p = &ival;// p指向ival
	std::cout << *p << std::endl;     //*p就是ival
	std::cout << *(p + 1) << std::endl; //语法没错，但p-1指针指向的内存不属于程序，
						  // *(p+1)访问这个不属于自己的内存，运行时程序会崩溃！
	std::cout << p << '\t' << p + 1 << std::endl;

#endif
}

#endif

#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int a[6]{ 1,2,3,4,5,6 };
	std::cout << a << '\t' << a + 1 << std::endl;

	double b[6]{ 1,2,3,4,5,6 };
	std::cout << b << '\t' << b + 1 << std::endl;
	double* q = (double*)a;
	std::cout << q << '\t' << q + 1 << std::endl;
	std::cout << *q << '\t' << *(q + 1) << std::endl;

}

#endif

#if 0
int Strlen(const char* s) {
	const char* p = s;      //p和s都指向char*类型指针s指向的字符串的第一个字符
	while (*p != '\0') p++;   //p++将指针p指向下一个字符的位置，*p得到其指向的字符
	return p - s;
}

#include <iostream>
using namespace std;
int main() {
	char s[] = { 'C','+','+' }; //字符数组，但不是C风格字符串
	char s2[] = { 'C','+','+','\0' }; //带结束字符'\0'的字符数组是C风格字符串
	cout << Strlen(s) << '\t' << Strlen(s2) << endl;
}

#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int v[] = { 1,2,3,4 };
	for (int i = 0; i != 4; i++)
		v[i] = 2 * v[i] + 1;
	

	int* p = v;

	for (int i = 0; i != 4; i++)
		cout << *(p + i) << '\t';  // *(p+i)就是p[i]
	cout << endl;

	for (int i = 0; i != 4; i++)
		cout << p[i] << '\t';  // p[i]就是*(p+i)
	cout << endl;

	p = v;
	for (; p != v + 4; p++)
		cout << *p << '\t';
	cout << endl;

	int* q = v + 4;
	for (; p != q; p++)
		cout << *p << '\t';
	cout << endl;
}

#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int v1[10], v2[10];
	int a = &(v1[5]) - &(v1[3]);  //两个指针相隔2个整数，因此a = 2
	int b = &(v1[5]) - &(v2[3]);  //不指向同一个数组的2个指针相减，
							 // 结果不可预知，因为这2个数组在内存的相对
							 //位置不知道，可能相隔很远，也可能相邻
	cout << a << '\t' << b << '\t' << endl;
	int* p = v1 + 11;
	a = p - &(v1[3]);        //a的值应该为8
	std::cout << a << endl;
}

#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int arr[10],a;
	int* p, * q;
	p = arr;  q = arr + 10;
	a = q - p; //值为10
	a = p - q; //值为-10

	int i = 1;
	while (p < q) {
		*p = i++;		
		p++; //p指向下一个int元素的位置
	}
	p = arr;
	while (p < q) {
		std::cout << *p << '\t';
		p++; //p指向下一个int元素的位置
	}
}

#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int arr[]{ 1,2,3,4,5,6,7,8,9 };
	//begin(arr)返回arr的起始地址，相当于 arr或 &(arr[0])
	//end(arr)返回arr的结束地址（即最后一个元素的后一个地址），相当于 arr+9或 &(arr[9])
	auto b = begin(arr), e = end(arr);
	while (b != e) {
		cout << *b << '\t';   //通过解引用运算符*，即*b得到b指向的int对象
		b++;
	}
	cout << endl;
}

#endif


#if 0
#include <iostream>
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//访问arr的每个元素，变量e引用该元素
	for (auto& e : arr) //对arr的每个元素e，可以通过引用变量 e直接修改数组的元素
		e = 2 * e + 1;

	//访问arr的每个元素，用该元素初始化变量e
	for (auto  e : arr)  //e是arr元素的赋值（拷贝），无法通过e修改arr的元素
		std::cout << e << '\t';
	std::cout << std::endl;
}

#endif

#if 0
#include <iostream>
int main() {
	int is[] = { 1,2,3,4 };
	for (auto e : is)
		std::cout << e << '\t';
	std::cout << std::endl;

#if 0
	int* p = is;        //p是指针数组is的指针变量
	for (auto e : p)    //错：不能将range for用于指针p！
		std::cout << e << '\t';
	std::cout << std::endl;
#endif

}

#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ia[3][4]; // = {0,1,2,3,4,5,6,7,8,9,10,11};
	for (int i = 0; i != 3; i++)
		for (int j = 0; j != 4; j++)
			ia[i][j] = i * 4 + j;

	//演示如何用引用访问数组
	int(&row)[4] = ia[0]; //row引用ia的第1行
	for (int j = 0; j!= 4; j++)
		cout << row[j] << '\t';

	cout << std::endl;
	//演示如何用指针遍历数组
	int(*p)[4]; //指针变量p指向的是一个int[4]数组，
	p = ia;//ia即数组ia的第一个元素的地址，即 &(ia[0])，因此，p存储的是 ia[0]的地址
	for (; p != ia + 3; p++) { //p指向的是int[4]数组, *p就是它指向的int[4]数组
		int* q = *p; //q指向*p这个数组的第一个元素
		           // *p :ia[0]  int[4]
		for (; q != (*p) + 4; q++)
			cout << *q << '\t';
		cout << '\n'; //输出换行        
	}
}


#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ia[3][4]; // = {0,1,2,3,4,5,6,7,8,9,10,11};
	for (int i = 0; i != 3; i++)
		for (int j = 0; j != 4; j++)
			ia[i][j] = i * 4 + j;

	//演示如何用引用访问数组
	int(&row)[4] = ia[0]; //row引用ia的第1行
	for (int j = 0; j != 4; j++)
		cout << row[j] << '\t';

	cout << std::endl;
	//演示如何用指针遍历数组
	for (auto p = begin(ia); p != end(ia); p++) {
		for (auto q = begin(*p); q != end(*p); q++)
			cout << *q << '\t';
		cout << '\n'; //输出换行 
	}
}

#endif


#if 0
#include <iostream>

using namespace std;
int main() {
	int ia[3][4];
	auto cnt{ 0 };
	for (auto& row : ia)               //对ia的每个元素（每行）的引用row
		for (auto& col : row) {        //对row的每个元素（每列）的引用col
			col = cnt;     cnt++;    //可以合并为一句： col = cnt++;
		}
	//输出   
	for (auto& row : ia) {
		for (auto& col : row)
			cout << col << '\t';
		cout << '\n';
	}
}

#endif

#if 0
int main() {
	double* p{ nullptr }; //初始化指针变量p为空指针
	p = new double; //p存储new分配内存的地址
	if (!p) return 1;   //申请内存失败
	double* q{ nullptr };
	q = new double[3]; //q存储new分配内存的地址
	if (!q) return 1;   //申请内存失败

//可以用解引用运算符*访问p或q指向的内存
	*p = 3.14;        //*p就是p指向的那个double变量
	*q = 3.15;        //*q就是q指向的那个double变量
	*(q + 1) = 3.16;    //*(q+1)就是q+1指向的那个double变量
	*(q + 2) = 3.17;    //*(q+2)就是q+2指向的那个double变量
	*(q + 3) = 3.17;    //*(q+3)就是q+3指向的那个double变量
					 //但q+3指向的内存不属于分配的内存块，无法访问，因此出错！

	*(p + 1) = 2.5; //错：p+1的内存不属于程序
	*(q - 1) = 2.5; //错：q-1的内存不属于程序
}


#endif

#if 0
#include <iostream>
int main() {
	//double scores[100][4]; //最多可以存储100个学生成绩
	int n = 0; //学生人数
	int cols; //每个学生的成绩个数
	std::cin >> n >> cols;
	//double* scores = new double[n][cols];
	//double* scores = new double[n][4]; //double[4] new T [n] new double[4][n]
	double (*scores)[4] = new double[n][4];

}


#endif

#if 0
#include <iostream>

int main() {
	int n = 0; //学生人数
	int cols; //每个学生的成绩个数
	std::cout << "输入学生人数\n";
	std::cin >> n;
	auto scores{ new double[n][4] };
	std::cout << "输入学生的平时、实验、期末、总评成绩\n";
	for (auto i = 0; i != n; i++) {
		std::cin >> scores[i][0] >> scores[i][1]
			>> scores[i][2] >> scores[i][3];
	}
	for (auto i = 0; i != n; i++) {
		std::cout << scores[i][0] << '\t' << scores[i][1] << '\t'
			<< scores[i][2] << '\t' << scores[i][3] << '\n';
	}
}
#endif

#if 0
#include <iostream>

int main() {
	int i{ 3 }, j{ 4 };
	int* const p = &i;
	int const*  q = &i;
	const int*  s = &i;
	*p = 30;
	//p = &j;
	//*q = 40;
	//*s = 40;
	q = &j;
	s = &j;	   	
}

#endif

#if 1
#include <iostream>

int main() {
	int i = 42;
	const int ci = 1024; //ci是const int对象，即不能修改的int，也称为常量
	const int& r1 = ci;   //用const int初始化const int的引用变量r1					
	const int& r2 = i;    // 用non-const的int变量i初始化const int的引用变量r2	
	const int& r3 = 42;   // 用文字量42初始化const int的引用变量r3
	const int& r4 = r1 * 2; // 用文字量r1 * 2初始化const int的引用变量r4


	//int& r5 = ci; // 错: 普通变量的引用不能引用const对象
	//int& r6 = i * 2; // error: 普通变量的引用不能引用表达式
	//int& r7 = 6; //不能引用文字量
	int& r9 = i;

	//r1 = 42;  // 错: const对象的引用 不能用于修改 
	//r4 = 42;
	//r2 = 30;

	//const int& r2 = i;
	//const int temp = i;
	//const int& r2 = temp;
}



#endif


















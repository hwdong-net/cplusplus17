//=========5. 复合类型=============
/*
* ==========5.1 引用===========
* 引用（Reference）就是一个变量(对象)的别名。如：
    T& ref{var};      //定义了引用变量ref，它是变量var的别名（引用）

  引用变量有什么用？
    函数的参数、renge for等
*/

#include <iostream>
using namespace std;
#if 0
int main() {
	int val{0};  //
	int& ref{ val }; // int& ref= val ;

	//对引用变量的操作就是对它引用的那个对象的操作。
	ref = 3; //即： val = 3;
	cout << ref << ' ' << val << endl;
	val += 1; //ref+=1
	cout << ref << ' ' << val << endl;
}
#endif 

#if 0
//下面哪些是引用变量？
int main() {
	int i{ 1024 }, i2{ 2048 }; 
	int &r{ i }, r2{ i2 };   //r引用i，r2是普通int变量，不是引用
	int i3{24} ,&ri{i3};  //i3不是引用，ri引用i3
	int &r3{i3},&r4{i2}; //r3引用i3,r4引用i2
}
#endif 

#if 0
int main() {
	int val;
	int& ref{ val }; // int& ref= val ;
	int& ref2;     //错：int 类型的引用变量ref2没有初始化
	int& ref4{ 10 };  //错： 不能引用文字量
	double dval{ 3.14 };
	int& ref5{ dval };  //错：引用变量类型和被引用变量类型不一致
}
#endif

/*======5.2. 指针=========
* 对于一个类型T，T* 是T指针类型。
即T* 类型的变量可以保存T类型变量的地址。
*/

#if 0
int main() {
	int i{3};
	int* p = &i; //&是 取地址运算符  int *
	              //p的类型是int * ,它初始化为int类型变量i的地址（指针）
	cout << i << "\t"  << &i << "\t" << p << endl;
}
#endif

#if 0
//T* 和T是完全不同的两个类型，相互之间不能初始化或赋值
int main() {
	char c;
	char* p;
	char* q{ c };   //不能用char类型的值初始化char*类型的变量
	p = c;        //也不能将char类型的值赋值给char*类型的变量
	char ch{ p };  //char类型变量也不能用char*类型值初始化
	ch = p;      //也不能用char*类型值赋值给char变量
}
#endif

#if 0
//解引用运算符* 作用于指针变量p，得到它指向的那个变量。
int main() {
	int i{ 3 };
	int* p{ &i}; //p存储的是i的地址，即p指向i。

	cout << i << "\t" << *p << endl;
	*p = 10; // *p就是c,因此，相当于i=10;即变量i的内存块存储的内容是10
	cout << i << "\t" << *p << endl;
	int i2{ *p }; //相当于 int i2 {i}。即i2的初始值就是i的值，即10
}
#endif


#if 0
/*指针变量也占据一块独立的内存。
因此，定义指针变量时，不一定要初始化。
而引用变量仅仅是其他变量的别名，
引用变量本身不占据单独的一块内存，
引用变量定义时则必须初始化。
*/
int main() {
	double* s;
	double& r;
}
#endif

#if 0
//给指针变量初始化和赋值时，类型须相同或能隐含转换。
int main() {
	double d;
	double* pd;
	pd = &d;   //OK:  pd的类型是double *, &d的类型是double*。类型完全相同
	double* pd2 = pd;
	int* pi = pd;  //错：pi的类型是int *，而pd的类型是double* 。类型不一致
	pi = &d;   //错：pi的类型是int *，而&d的类型是double* 。类型不一致
}
#endif

#if 0
#include <iostream>
int main() {
	int i;
	int* p{ &i }, *q{ 0 };
	bool b{ true };// p };  // int*非空指针p转化为bool型值true,
				  // 然后对b初始化，因此，b的值是true
	std::cout << std::boolalpha << b << std::endl; //boolalpha操作符控制bool量的显示形式
	b = q;       // int *空指针q转化为bool型值false,
				  // 然后赋值给b，因此，b的值是false;
	std::cout << std::boolalpha << b << std::endl;
}
#endif

#if 0
/*
* 注意：*和&的多个含义
   定义变量时，*和&分别表示定义指针变量和引用变量
   作为运算符时，*和&则分别表示解引用和取地址运算符
*/
int main() {
	int i{ 56 };
	int& r{ i }; //r引用i，即r是变量i的别名，r和i是同一块内存的不同名字
	int* p;    //p的类型是int*，可存储int型变量的地址
	p = &i; //&i得到int型变量i的地址，赋值给变量p。两者类型都是int *
	*p = 3;  // *p得到p指向的那个变量，即i。因此这句命令相当于: i = 3;
	int& r2{ *p }; // int型引用变量r2引用的变量是*p，即i
}
#endif 


#if 0
//空指针：不指向任何变量(对象)的指针(变量)。
//初始化一个空指针的方法有：
int main() {
	int* p2{ 0 }; //用0初始化一个空指针变量
	int* p1{ nullptr }; // 从C++11开始，用nullptr表示空指针。 推荐使用！
	int* p3{ NULL };  //NULL通常是一个为0的宏常量。C++11开始禁止这样使用！

	//C++11 从nullptr表示空指针
	int* pi{ nullptr };
	double* pd{ nullptr };
	int ival{ nullptr };   //错：ival不是一个指针变量
}
#endif


#if 0
//不能用整数给指针赋值，即使这个整数为0, 因为类型不同。
int main() {
	int zero{ 0 }, * p1;
	int* p{ 0 }; //可以用0对指针初始化或赋值
	p = 0; //
	int* p2{ zero }; //错：不能用整数给指针赋值
	int* p3{ 3 };
}
#endif


#if 0
/*
* void* 无类型指针
1）void* 变量可以存储任何内存地址(任何类型对象的地址)。
2）void* 变量之间可以比较大小，可以相互赋值。
3）void* 变量不能*解引用、不能对指针进行偏移、
       不能隐式类型转换到非void指针类型，
	   但可以通过强制类型转换static_cast将它转换到特定的指针类型。
*/

#include <iostream>
int main() {
	int* pi;
	void* pv = pi; // ok: int*到 void*的隐式类型转换
	*pv;    //错 :不能解引用 void*
	++pv;   //错: 不能增量或偏移 void* (指向对象的内存大小未知)
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
//指针的指针
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
//5.2.5 指针的引用
int main() {
	int i{ 42 };
	int* p;
	int*& r{ p };  //r引用p，即r是p的别名
	r = &i; //将i的地址赋值给r，也就是p，因此p指针变量里保存的就是i的地址
	*r = 0; //相当于*p = 0，p指针变量的值是0，即p成为一个空指针。
	int&* q; //错！ 因为：从右向左看，q是一个指针变量，存储的是int &变量的地址，
		// 也就是说q试图存储一个引用变量的地址，而引用变量是没有独立的内存块的，
		// 即引用变量没有地址！
}
#endif

#if 0
//5.2.6 引用和指针的比较
/*
1）	共同点：都是间接指向或引用其他对象
2） 不同点: 引用(变量) 仅仅是其他变量的别名，无独立内存，
   同一个引用变量不能修改去引用不同的变量。
   指针变量存储其他变量的地址，有独立内存，在不同时刻可指向不同对象。
*/
int main() {
	auto i{ 0 }, j{ 1 };
	int* p;            //指针变量不一定要初始化
	int& r{ i }, & r1;     //错：引用变量r1没有初始化！
	p = &i;          //p指向i
	p = &j;          //p指向j
#if 1
	auto * &rp{ p };    // rp引用p
	int*& rp2;       //错：引用变量rp2没有初始化
	int&* q;         //错： 不能定义指向引用的的指针，
					// 因为引用变量没有独立内存(即没有地址)
#endif 
	int&* q2 = &r;  //错：原因同上. 另外，取地址运算符&不能作用于引用变量r！ 
}
#endif





/*=========数组=============
* 对于一个类型T，T[size] 是“size个T类型元素的数组”类型。
 T[size]类型的变量var定义为T var[size]而不是T[size] var。即：
     T var[size]; //var 是 T[size]类型的变量即 “size个T类型元素的数组”
*/

#if 0
//定义数组
int main() {
	float v[3];   //v是3个float元素的一个数组
	char* a[32]; //a是32个char *元素的一个数组，每个元素的类型是char*
}
#endif

#if 0
//可以用下标运算符operator[]访问数组的元素，下标从0开始
//超出范围的访问时非法的
#include <iostream>
int main() {
	float v[3];    //数组v的3个元素分别是：v[0],v[1],v[2]
	char* a[32];  //数组a的32个元素分别是：a[0],a[1],...a[31]
	v[1] = 10;   //v的第二个元素的值修改为10
	std::cout << v[0] << '\t'<<v[1] << '\t' << v[2] << std::endl;   //输出v的3个元素
	std::cout << v[3];       //错：下标超出范围
	std::cout << v[-1];     //错：下标超出范围
	a[1] = 0;          //a的第2个元素成为空指针
	a[2] = 'a';         //错：不能将char类型的值赋值给char *类型的元素
	auto b = v[2];      //用v[2]对变量b进行初始化，因此b是float类型的变量
}
#endif


#if 0
//数组的大小必须是“常量表达式”，即编译时值确定的表达式。
int main() {
	int s = 20;
	int arr[s];      //错：s不是常量表达式（编译时常量）。
	int arr2[20];   //Ok: 文字量20是编译时常量
}
#endif

#if 0
//和普通变量一样，在定义数组变量时，也可以对它初始化，
//即用花括号{ 和 }括起来的列表初始化对其每个元素进行初始化。
int main() {
	int v1[]{ 1,2,3 };       //v1是3个int类型元素的数组
	char v2[]{ 'a','b','c','\0' };  //是4个char元素的数组，最后一个转义字符'\0'称为
						  //结束字符，其8位二进制都是0
	char v3[2]{ 'a','b','\0' };   //错： 列表中的元素个数不能超出其大小
	char v4[4]{ 'a','b','\0' };   //OK，4个元素的数组
	int v5[4]{ 1,2,3 };      //列表中的个数少于数组大小，剩余的数组元素的值取默认值，
						  //对于内在类型，默认值通常是0，即等价于int v5[4] = {1,2,3,0}
	cout << v5[0] << '\t' << v5[1] << '\t' << v5[2] << '\t' << v5[3] << endl;
}
#endif

#if 0
//注意：不能用一个数组去初始化或赋值给另一个数组。
int main() {
	int a[] = { 1,2,3 };
	int a2[] = a;    //错：不能用一个数组去初始化另一个数组
	a2 = a;        //错：不能用一个数组去赋值给另一个数组
}
#endif

#if 0
//复杂的数组声明
//“自内向外、自右向左”的阅读
int main() {
	int ar[3];     //3个int元素的数组
	int arr[10];    //10个int元素的数组
	int* ptrs[10];    //10个int*元素的数组
	int(*parr)[10];  //parr是一个指针，指向的是int[10]的数组，
				   //即指向的是10个int元素的数组，
				   //或者说它存储的是int[10]数组的地址
	parr = &arr;   //将 int[10]类型数组arr的地址赋值给 parr
	parr = &ar;   //错：类型不一致！ ar的类型是 int[3]而不是int[10]。
}
#endif



#if 0
//字符数组可以用一个字符串文字量进行初始化。
int main() {
	char a1[]{ 'C','+','+' };     //a1是3个char字符的数组
	char a2[]{ 'C','+','+','\0' };  //a2是4个char字符的数组，最后一个字符是结束字符
	char a3[]{ "C++" };      //用字符串文字量对字符数组a3初始化，
					   //因为文字量字符串有一个隐含的结束字符 '\0'
					   //因此a3实际是4个字符，即相当于char a3[] = {'C','+','+','\0'}; 
	char a4[5]{ "Hello" };  //错：空间不够！因为文字量字符串"Hello"实际有6个字符。
	char a5[6]{ "Hello" };  //OK：空间正好
	char a6[9]{ "Hello" };  //OK：空间足够。问：a6的第7，8字符是什么呢?
}
#endif

#if 0
//带结束字符'\0'的字符数组是C语言的字符串，称为C风格字符串。
//<cstring>文件中的C字符串函数库
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
/*
//关于C风格字符串的更多函数和更详细信息，可以参考文档：
http://www.cplusplus.com/reference/cstring/
*/
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char s[] = "A string example"; //用字符串文字量初始化字符数组，结果包含了结束字符
	char s2[] = "A hello world";
	int ret = strcmp(s.s2); //返回负数表示s<s2，返回0表示s==s2，返回正数,表示s>s2
	if (ret < 0)
		cout << "s<s2" << endl;
	else if (ret == 0)
		cout << "s==s2" << endl;
	else
		cout << "s>s2" << endl;
}
#endif


#if 0
/*
//实现字符串处理函数
*/
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

/*===========指针访问数组=============
* 可以用指针指向数据元素，
* 数组名是指向数组第一个元素的指针（地址）。

*/
#if 0
int main() {
	int v[]{ 1,2,3,4 };
	int* p1{ &(v[0]) }； //p1存储的是第一个元素v[0]的地址
		int* p2{ v };     //数组名就是数组的第一个元素的地址,等价于 int *p2{&(v[0])};
	int* p3{ v + 4 };   //v是第一个元素的指针，向后偏移4个int元素空间，
					//因此v+4指向的是最后一个元素v[3]再偏移一个int空间的地址
	std::cout << *(p1 + 2) << endl; // *(p1+2)等价于*(v+2),该语句输出第3个元素

}
#endif

#if 0
/* 下列访问数组元素的式子都是等价的：
  v[j] == *(&(v[0]) + j) == *(v + j) == *(j + v) == j[v]  
  如：
  3["hello"] == "hello"[3];
  2[v] == v[2];
*/
int main() {
	int v[]{ 1,2,3 };
	cout << 3["hello"] << '\t' << "hello"[3] << endl;
	cout << 2[v] << '\t' << v[2] << endl;
	return 0;
}
#endif



#if 0
/*
* 对于一个指针变量p和一个整数n，
可以用 p+n、p-n 、p+=n 、p-=n等算术运算对指针进行偏移，
也可以用自增（p++或 ++p）、自减（p--或--p）进行偏移。例如：
*/
int main() {
	int v[] = { 1,2,3,4 };
	int* p = v;
	p[2] = 20 + *(v + 3);
	int b = *(p + 2), c = v[2], d = *(v + 2);
	p++;   //p从v向后偏移1个int占据的空间(4个字节)，即p指向v[1]
	p++;   //p指向v[2]
	std::cout << b << '\t' << c << '\t' << c << '\t' << *p << '\n';
	p -= 2;  //p向前偏移2个int占据的空间，即地址减去了8个字节,
		  //p指向了第一个元素
	std::cout << *p << std::endl;
	p--;    //语法不错，但其指向的地址已经不属于数组v了。
	std::cout << *p << std::endl;  //语法不错，但*p访问了一个不属于自己的内存块，
						   //运行程序时会崩溃！
	int ival = 1024；
		p = &ival；// p指向ival
		std::cout << *p << std::endl;     //*p就是ival
	std::cout << *(p + 1) << std::endl; //语法没错，但p-1指针指向的内存不属于程序，
						  // *(p+1)访问这个不属于自己的内存，运行时程序会崩溃！
}
#endif

#if 0
//用指针实现Strlen
int Strlen(const char* s) {
	const char* p = s;      //p和s都指向char*类型指针s指向的字符串的第一个字符
	while (*p != ’\0’) p++;   //p++将指针p指向下一个字符的位置，*p得到其指向的字符
	return p - s;
}

int main() {
	
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int v[] = { 1,2,3,4 };
	for (int i = 0; i != 4; i++)
		v[i] = 2 * v[i] + 1;
	cout << endl;

	for (int i = 0; i != 4; i++)
		cout << *(p + i) << '\t';  // *(p+i)就是p[i]
	cout << endl;

	for (int i = 0; i != 4; i++)
		cout << p[i] << '\t';  // p[i]就是*(p+i)
	cout << endl;

	int* p = v;
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
/*
* 2个指针不能相加，但指向同一个数组的指针可以相减：表示两者之间的元素个数。
*/
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
//不指向同一个数组的同类型指针可以比较或相减，但没意义。
int main() {
	int i = 0, sz = 42;
	int* p = &i, * q = &sz;
	int a = p - q;    //不指向同一个数组的同类型指针相减，没有意义！
		if (p < q) {    //错：这里比较没有意义！
			 //...
        }

}
#endif

#if 0
//下列代码通过比较指向同一个数组元素的2个指针，控制循环过程：
int main() {
	int arr[10];
	p = arr;  q = arr + 10;
	a = q - p; //值为10
	a = p - q; //值为-10
	while (p < q) {
		std::cout << *p << endl;
		p++; p指向下一个int元素的位置
	}
}
#endif


#if 0
//C++标准库提供的begin()和end()函数得到
//这个数组的起始地址和结束地址(最后1个元素的后一个地址)。
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
//其中b、e的类型都是int*。
#endif



//===========Range for=============
/*对数组这种多个同类型元素构成的序列对象，可以用Range for遍历其中的元素
* // 假如arr是T类型的数组
    for(T &变量名: arr)   // 变量名表示是arr每个元素的引用
或
    for(T 变量名: arr)   // 变量名表示是arr每个元素的复制
*/

#if 0
#include <iostream>
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//访问arr的每个元素，变量e引用该元素
	for (int& e : arr) //对arr的每个元素e，可以通过引用变量 e直接修改数组的元素
		e = 2 * e + 1;

	//访问arr的每个元素，用该元素初始化变量e
	for (int e : arr)  //e是arr元素的赋值（拷贝），无法通过e修改arr的元素
		std::cout << e << '\t';
	std::cout << std::endl;
}
#endif

#if 0
//可以将range for的变量类型用auto来自动推断，即：
#include <iostream>
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//访问arr的每个元素，变量e引用该元素
	for (auto& e : arr) //对arr的每个元素e,因为要修改arr的每个元素，
					 //所以e必须定义为是引用变量
		e = 2 * e + 1;
	//访问arr的每个元素，用该元素初始化变量e
	for (auto e : arr)    //对arr的每个元素e,我们不修改arr的元素，
					   //所以e可以定义成非引用变量
		std::cout << e << '\t';
	std::cout << std::endl;
}

#endif

#if 0
//注意：Range for不能用于指针。例如：
#include <iostream>
int main() {
	int is[] = { 1,2,3,4 };
	for (auto e : is)
		std::cout << e << '\t';
	std::cout << std::endl;

	int* p = is;        //p是指针数组is的指针变量
	for (auto e : p)    //错：不能将range for用于指针p！
		std::cout << e << '\t';
	std::cout << std::endl;
}
#endif


/*
* =========多维数组=========
*/
#if 0
#include <iostream>
int main() {
	int  s = 20;
	int arr[20];
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
int main() {
	int a[]{1,2,3,4};
	int (&r)[4] = a;
	int (*p)[4] = &a;
	int* q = a;
	cout << p << '\t' << q << '\t'<<endl;
	cout << (*p)[0] << '\t' << (*p)[1] << '\t' << endl;
	for (auto s = *p; s != *p + 4; s++)
		std::cout << *s << '\t';
	cout << endl;
	cout << typeid(q).name()<<endl;
	cout << typeid(p).name() << endl;
	cout << typeid(&a).name() << endl;
	cout << typeid(a).name() << endl;
	cout << typeid(&(a[0])).name() << endl;
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

#if 0
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


#if 0
#include <iostream>

int  main() {
	int a[]{ 12,46,25,43,7,92,5,29,80,105 };
	auto x{ 0 };	
	std::cin >> x;
	/*
	int* p = a,*q = a+10;
	for (; p!=q;p++) {
		if (*p == x) {
			break;
		}
	}
	*/
	//迭代器
	auto p = std::begin(a), q = std::end(a);
	for (; p != q; p++) {
		if (*p == x) {
			break;
		}
	}
	if(p<q)
		std::cout <<"在下标" << p-a << "找到了元素" << x << std::endl;
	else 
		std::cout << "未找到元素" << x << std::endl;
}
#endif

#if 0
#include <iostream>
int  main() {
	int a[]{ 5,7,12,25,34,37,43,46,58,80,82,105 };
	auto x{ 0 };
	std::cin >> x;
	auto L{ 0 }, H{ std::end(a) - std::begin(a) - 1 };
	while (L <= H) {
		auto M{ (L + H) / 2 };
		if (a[M] == x)
			break;
		else if (a[M] > x)
			H = M - 1;
		else L = M + 1;
	}
	if(L<H)
		std::cout << "在下标" << (L + H) / 2 << "找到了元素" << x << std::endl;
	else 
		std::cout << "未找到元素" << x << std::endl;	
}
#endif

#if 0
#include <iostream>
int  main() {
	int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
	auto n = std::end(a) - std::begin(a);

	for (auto i = n-1; i > 0; i--) { //i从7到1，共7趟冒泡
		//对每个i，对[0,i]之间的序列进行“一趟冒泡”
		for (auto j = 0; j < i; j++)   //下标j遍历序列[0,i-1]
			if (a[j] > a[j + 1]) {   //如果是逆序，就交换它们
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
using namespace std;
int main() {
	auto n{ 4 };
	//auto INFTY = std::numeric_limits<double>::max();
	auto INFTY = 1e12; // INFTY假设表示一个无穷大的数值
 // 初始化距离矩阵D
	double D[][4]{ {0, 2, 6, 4},
				   {INFTY, 0, 3, INFTY},
				   {7, INFTY, 0, 1 },
				   {5, INFTY, 12, 0} };
	// 初始化路径矩阵P
	unsigned int P[][4]{ {0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0} };
	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++)
			P[u][v] = u; //直达路径uv的终点的前一个顶点是u，终点是v

	//打印D和P矩阵
	cout << "初始的距离和路径矩阵：\n";
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
	for (auto w = 0; w < n; w++) //对每个顶点w，都绕道一次，更新D和P
		for (auto u = 0; u < n; u++)
			for (auto v = 0; v < n; v++)
				//绕道w使D[u][v]变得更短吗？
				if (w != u and w != v and D[u][w] + D[w][v] < D[u][v]) {
					D[u][v] = D[u][w] + D[w][v];
					P[u][v] = P[w][v];
				}

	//打印D和P矩阵
	cout << "最终的距离和路径矩阵：\n";
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

	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++) {
			if (u == v) continue;
			cout << u << "到" << v << "的逆向路径是:";
			cout << v << ','; //终点
			//auto w{ P[u][v] };
			for (auto w{ P[u][v] }; w != u;) {
				cout << w << ',';
				w = P[u][w];
			}
			cout << u << std::endl;
		}

}

#endif



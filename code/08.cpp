/*===========运算符===========
    再复杂的计算都归结为对基本类型的运算
	人们熟悉运算符
    运算符比函数更直观
	add(x, multiply( y, z))
	x+y*z
*/



#if 0
//------运算符函数----------
//每个运算符实际就是一个函数，称为运算符函数，
// 运算符函数的完整名称是operator关键字加上运算符构造的。
//如加法运算符 + 的函数是operator +
//s1 + s2      实际是      s1.operator+(s2)

#include <string>
#include <iostream>
int main() {
	std::string s1{ "hello" }, s2{ "world" }, s3;
	s3 = s1 + s2;    //s3.operator=(operator+(s1,s2)); 
	std::cout << s3;  //operator<<(std::cout, s3);
}
#endif

#if 0
//-------运算符重载-------
//对用户定义类型，重新定义运算符函数，称为运算符重载。
#include <string>
#include <iostream>
std::string operator+(const std::string& s1, const std::string& s2) {
	std::string s;
	/*  */
	return s;
}
std::ostream& operator<<(std::ostream& out, const std::string& s) {
	/* ... */
	return out;
}

#endif

#if 0
//--------运算符重载的2种方式---------------
//成员函数：将运算符函数定义为类的成员函数。
//外部函数：将运算符函数定义为外部函数（全局函数）。
//大多数运算符可以采用上述任意一种重载方式。但某些特殊运算符，只能采用其中一种方式重载。
//例如：赋值运算符只能作为类的成员函数重载。
#include <iostream>
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	Point operator+(const Point& other) {
		return  Point(x + other.x, y + other.y);
		//return  Point(this->x + other.x, this->y + other.y);
	}

	friend void print(const Point & p);
};
void print(const Point& p) {
	std::cout << p.x << "," << p.y;
}
//然后就可以使用运算符 + ，对2个Point类对象进行加法运算：
int main() {
	Point P{ 2,3 }, Q{ 4,5 };
	print(P + Q);//P.operator+(Q)
}

#endif

#if 0
// operator+也可以作为外部（全局）函数实现
#include <iostream>
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	friend Point operator+(const Point&  P, const Point& Q);
	friend void print(const Point & p);
};
Point operator+(const Point& P, const Point& Q) {
	return  Point(P.x + Q.x, P.y + Q.y);
}

void print(const Point& p) {
	std::cout << p.x << "," << p.y;
}
//然后就可以使用运算符 + ，对2个Point类对象进行加法运算：
int main() {
	Point P{ 2,3 }, Q{ 4,5 };
	print(P + Q);//operator+(P,Q)
}
#endif

#if 0
//---------运算符函数: 参数个数----------
/*
二元运算符
	作为成员函数，有且只有一个参数：   a.operator@(b)
	作为外部函数，有且只有2个参数：operator@(a,b)
一元运算符
	作为成员函数，参数列表为空：   a.operator++()
	作为外部函数，有且只有1个参数：operator-(a)
*/
#if 0
#include <iostream>
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	Point operator-()const {
		return Point(-this->y, -this->x);
	}
	void print() { std::cout << x << "," << y; }
	//...
};

int main() {
	Point P(3, 4);
	Point Q = -P;
	Q.print();
}
#else
#include <iostream>
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	friend Point operator-(const Point& p);
	void print() { std::cout << x << "," << y; }
	//...
};
Point operator-(const Point& p) {
	return Point(-p.y, -p.x);
}
int main() {
	Point P(3, 4);
	Point Q = -P;
	Q.print();
}
#endif
#endif

#if 0
//--------- 成员函数重载和外部函数重载的区别----------------
//作为成员函数重载的运算符的第一个操作数必须是这个类的对象，不能是其他可转化为这个类类型的变量。
//而作为外部函数重载的运算符的第一个操作数可以是能转化为这个类类型的变量。
#if 0
class Point {
	double x{}, y{};
public:	
	Point(double x=0, double y=0) :x{ x }, y{ y }{}
	friend Point operator+(Point P, const Point& other);
	//…
};
Point operator+(Point P, const Point& other) {
	return  Point(P.x + other.x, P.y + other.y);
}
#else
class Point {
	double x{}, y{};
public:
	Point(double x = 0, double y = 0) :x{ x }, y{ y }{}
	Point operator+(const Point& other) {
		return  Point(x + other.x, y + other.y);
	}
	//…
};

#endif
int main() {
	Point P(3, 4),Q(-2,6);
	P + 2;
	2 + P;
	P + Q;
}
#endif


#if 0
//-----------赋值运算符=------------
/*
对于Point对象，可以直接用赋值运算符 = ：
P = Q;
对于Point类，编译器生成的默认赋值运算符operator = ()如下：
*/
class Point {
	double x, y;
public:
	Point& operator=(const Point& other) {
		if (this != &other) {
			x = other.x; y = other.y;
		}
		return *this;
	}
}

//1)只能以成员函数的形式重载赋值运算符operator=()，并且重载的函数最后必须返回自引用（*this）。
//2)对于占用资源的类，默认的赋值运算符函数会导致“共享同一资源”问题。如string、vector。
//应该重新定义赋值运算符函数！
#endif

#if 0
//------下标运算符[]-----
//下标运算符通常定义2个版本，
//一个是返回可以被修改的引用，即可以作为赋值运算符的左操作数，
//另外一种是const成员函数，返回的是一个值，可用作赋值运算符的右操作数。
#include <iostream>
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	double& operator[](int i) {        //返回对象的引用
		if (i == 0) return x;
		else if (i == 1) return y;
		else throw "下标非法";
	}
	double operator[](const int i) const { //返回值的const函数
		if (i == 0) return x;
		else if (i == 1) return y;
		else throw "下标非法";
	}
	friend void print(const Point & p);
	//...
};

void print(const Point & p) {
	std::cout << p.x << "," << p.y;
}
int main() {
	Point P{ 2,3 };
	P[0] = 4;       //P[0]调用的是引用版本，
	P[1] = P[0];    //P[1]调用的是引用版本，P[0]调用的是const版本
	print(P);
}
#endif

#if 0
//-------输入输出运算符<<和>>--------
//其中的输出流参数out必须是引用
#include <iostream>
class Point {
	double x, y;
	//…
public:
	Point(double x=0, double y=0) :x{ x }, y{ y }{}
	friend std::ostream& operator<<(std::ostream& out, const Point& p);
	//…
};

std::ostream& operator<<(std::ostream& out, const Point& p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}


int main() {
	Point P;
	std::cout << P;
}

#endif

#if 0
//----------比较运算符-----------
// 作为成员函数实现
#include <iostream>
class Point {
	double x, y;
	//…
public:
	Point(double x = 0, double y = 0) :x{ x }, y{ y }{}
	bool operator<(const Point& other);
	bool operator==(const Point& other);	
	//…
};

bool Point::operator<(const Point& other) {
	if (x == other.x) return y < other.y;
	return x < other.x;
}
bool Point::operator==(const Point & other) {
	return x == other.x && y == other.y;
}
//然后就可以对2个Point对象通用 < 或 == 进行比较：
int main() {
	Point P{ 2,3 }, Q(3, 2);
	if (P < Q || P == Q) std::cout << "P<=Q";
	else std::cout << "P>Q";
}

#endif

#if 0
//----------比较运算符-----------
// 作为外部函数实现
#include <iostream>
class Point {
	double x, y;
	//…
public:
	friend bool operator<(const Point P, const Point& Q);
	friend bool operator==(const Point P, const Point& Q);
	bool operator<=(const Point& other) {
		return *this < other || *this == other;	}

	//…
};

bool operator<(const Point P, const Point& Q) {
	if (P.x == Q.x)return P.y < Q.y;
	return P.x < Q.x;
}
bool operator==(const Point P, const Point & Q) {
	return P.x == Q.x && P.y == Q.y;
}

//然后就可以对2个Point对象通用 < 或 == 进行比较：
int main() {
	Point P{ 2,3 }, Q(3, 2);
	if (P < Q || P == Q) std::cout << "P<=Q";
	else std::cout << "P>Q";
}

#endif

#if 0
#include <utility>
using namespace std::rel_ops;
class Point {
	double x{}, y{};
public:
	Point(double x = 0, double y = 0) :x{ x }, y{ y }{}
	friend bool operator<(const Point P, const Point& Q);
	friend bool operator==(const Point P, const Point& Q);
};
bool operator<(const Point P, const Point& Q) {
	if (P.x == Q.x)return P.y < Q.y;
	return P.x < Q.x;
}
bool operator==(const Point P, const Point & Q) {
	return P.x == Q.x && P.y == Q.y;
}

#include <iostream>
int main() {
	Point P{ 2,3 }, Q(3, 2);
	if (P > Q) std::cout << "P>Q";      //  >运算符
	if (P != Q) std::cout << "P!=Q";      // !=运算符
}
#endif

#if 0
//---------函数调用运算符()------------
//对一个类型，可以定义函数调用运算符: operator()
//调用运算符operator()函数，其包含一个参数n，该函数根据这个参数n计算x^n+y^n。
#include <cmath>
class Point {
	double x{}, y{};
public:
	Point(double x = 0, double y = 0) :x{ x }, y{ y }{}
	double operator()(int n = 2) {
		if (n <= 1) return std::abs(x) + std::abs(y);
		double xn(x), yn(y);
		for (auto i = 1; i != n; i++) { xn *= x; yn *= y; }
		return xn + yn;
	}
	//…
};
#include <iostream>
int main() {
	Point P{ 2,3 };
	std::cout<<P(2)<<'\t'<<P(3)<<'\n';  //P(2)和P(3)调用了函数调用运算符operator()
}

#endif

#if 0
//------类型转换运算符----------
/*
带一个参数的构造函数实际上定义了一个从参数类型到类类型的隐式类型转换。
	 class X{
		public:
			 X(int a) {...}
	 };
反过来，也可以定义一个类型转换运算符用于将类类型隐式转换为其他的类型。
类型转换运算符同样必须作为成员函数实现，其格式是：
		 operator type () const
类型转换函数也没有返回类型
*/

class Point {
	double x{}, y{};
public:
	operator double() const {
		return x * x + y * y;
	}
	Point(double x, double y) :x{ x }, y{ y }{}
};
#include <iostream>
int main() {
	Point P(3, 4);
	double d = P;  //对象P隐式转化为double类型的值，再对d初始化
	std::cout << d << '\n';
}
#endif

#if 0
//------隐含类型转换引起的歧义-------------
//一个参数的构造函数和类型转换运算符定义的隐式类型转换有时会引歧义
class A {
	int a;
public:
	A(int){}         //一个参数的构造函数定义了int类型到A类的自动类型转换
	operator int() { return a; }   //类型转换运算符可以将A类型对象自动转换为int类型
	friend A operator+(const A& a1, const A& a2); //2个A类型的对象相加
};
A operator+(const A& a1, const A& a2) {
	A ret(0);
	//...
	return ret;
}

#if 0
int main() {
	A a{ 1 };
	int i = 1, z;
	z = a + i; //错：到底是 A+A还是int+int
}
#else
//强制类型转换消除歧义性
int main() {
	A a{ 1 };
	int i = 1, z;
	//z = static_cast<int>(a) + i;  //或z = (int)a + i;
	z = a + static_cast<A>(i);  //或z = a + A(i);
}
#endif
#endif

#if 0
//-------自增和自减运算符-----------
//自增运算符++和自减运算符--都是一元运算符，且必须作为类的成员函数实现
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	//前缀自增运算符必须返回这个对象自身的引用
	Point& operator++();         
	 //后缀自增运算符必须带一个int参数，且不能返回对象自身的引用
	const Point operator++(int);  
	//…
};

Point& Point::operator++() { //前缀++
	++x; ++y;
	return *this;
}
const Point Point::operator++(int) {  //后缀++
	Point P(*this);  //暂时保存原来的对象值
	++(*this);     //对象自身自增
	return P;     //返回的原来的对象值，一个临时变量
}

//因为前缀自增返回的是对象自身，所以对它可以继续用++运算，
//而后缀++返回的是一个临时值，不能连续使用后缀++。如：
int main() {
	Point P{ 2,3 };
	++ ++P;       //OK：因为++P返回的就是P自己，可以继续对它再用++运算
	(++P)++;     //OK:理由同上
//	P++ ++;      //错：因为P++返回的不是自身引用，不能继续对P++再用++运算
//	++(P++);     //错：理由同上
}

#endif

/*
可以重载的运算符有：
+    −   ∗   /   %   ˆ   &   |   ˜   !
+=   −=  ∗=  /=  %=  ˆ=  &=  |=  <<= >>=
>    <   >=  <=  ==  !=  <<  >>
&&   ||  ++  --  ->  ->*  ,   *   T
[]  ()  new new[] delete delete[]
注意：
	这里的T表示的是类型转换运算符。
	有的运算符可能有2种含义，比如&可以作为位运算符也可以作为取地址符、-可以作为减法运算符也可以作为负号运算符。
	有的运算符只能作为成员函数重载，如：=、[]、()、T(类型转换运算符)。
	也有的运算符只能作为外部函数重载，如：new、new[]、delete、delete[]。
	也有一些运算符不能被重载，如：
	:: 作用域运算符
	. 成员访问运算符
	.* 成员选择运算符
	?:条件运算符
	sizeof 查询对象的大小
	typeid查询对象的类型
*/

#if 1
//-------实战：实现一个矩阵类Matrix---------------
#if 0
class Matrix {
	double* data{ nullptr };
	int m{}, n{}; //行数和列数
public:
	Matrix(const int m = 0, const int n = 0);
	explicit Matrix(const int m) :Matrix(m, m) {}   //为防止将一个int值隐含自动转换为Matrix类型
//，这里用explicit
	double operator() (const int i, const int j)const;
	double& operator()(const int i, const int j);
};

Matrix::Matrix(const int m, const int n) :m(m), n(n) {
	if (m <= 0 || n <= 0) return;
	data = new double[m * n];
	if (!data) { this->m = this->n = 0; return; }
}
double Matrix::operator() (const int i, const int j)const {
	int k = i * n + j;
	return data[k];
}
double& Matrix::operator() (const int i, const int j) {
	int k = i * n + j;
	return data[k];
}

#include <iostream>
int main() {
	Matrix A(3, 4);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			A(i, j) = i * 4 + j;     //A(i,j)调用的是引用版本的operator()

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << A(i, j) << "  ";  //A(i,j)调用的是const版本的operator()
		std::cout << std::endl;
	}
}
#else
//Matrix还应该能够复制、赋值，进行+、-、*包括+=、-*、*=等运算。
//下面的代码将+=、-*、*=运算符作为成员函数实现，而+、-、*运算符作为友元函数实现：

class Matrix {
	double* data{ nullptr };
	int m{ 0 }, n{ 0 }; //行数和列数
public:
	Matrix(const int m = 0, const int n = 0);
	explicit Matrix(const int m) :Matrix(m, m) {}  //为防止将一个int值隐含自动转换为Matrix类型，
//这里用explicit
	double operator() (const int i, const int j)const;
	double& operator()(const int i, const int j);

	Matrix(const Matrix& M);                  //拷贝构造函数
	Matrix& operator=(const Matrix& M);       //赋值运算符函数

	Matrix& operator+=(const Matrix& M);
	Matrix& operator-=(const Matrix& M);
	Matrix& operator*=(const Matrix& M);

	friend Matrix operator+(const Matrix& A, const Matrix& B);
	friend Matrix operator-(const Matrix& A, const Matrix& B);
	friend Matrix operator*(const Matrix& A, const Matrix& B);

	int rows()const { return m; }
	int cols() const { return n; }
};

Matrix::Matrix(const int m, const int n) :m(m), n(n) {
	if (m <= 0 || n <= 0) return;
	data = new double[m * n];
	if (!data) { this->m = this->n = 0; return; }
}
double Matrix::operator() (const int i, const int j)const {
	int k = i * n + j;
	return data[k];
}
double& Matrix::operator() (const int i, const int j) {
	int k = i * n + j;
	return data[k];
}

Matrix::Matrix(const Matrix& M) {
	int num = M.m * M.n;
	data = new double[num];                  //申请一块内存
	if (data) {
		m = M.m; n = M.n;
		for (auto i = 0; i != num; i++)
			data[i] = M.data[i];
	}
}
Matrix& Matrix::operator=(const Matrix & M) {
	int num = M.m * M.n;
	double* temp = new double[num];         //申请一块新内存
	if (temp) {                              //数据赋值（拷贝）
		delete[] data;                     //释放原来的内存
		data = temp;                      //data指向新内存块
		m = M.m; n = M.n;
		for (auto i = 0; i != num; i++)
			data[i] = M.data[i];
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix & M) {
	if (m != M.m || n != M.n) return *this;
	int num = m * n;
	for (auto i = 0; i != num; i++)data[i] += M.data[i];
	return *this;
}
Matrix & Matrix::operator-=(const Matrix & M) {
	if (m != M.m || n != M.n) return *this;
	int num = m * n;
	for (auto i = 0; i != num; i++)data[i] -= M.data[i];
	return *this;
}
Matrix & Matrix::operator*=(const Matrix & M) {
	//...补充你的代码
	return *this;
}

Matrix operator+(const Matrix & A, const Matrix & B) {
	Matrix C(A);	C += B;	return C;
}
Matrix operator-(const Matrix & A, const Matrix & B) {
	Matrix C(A);	C -= B;	return C;
}
Matrix operator*(const Matrix & A, const Matrix & B) {
	Matrix C(A);	C *= B;	return C;
}

//编写一段简单代码测试一下刚添加的函数是否正确。
#include <iostream>
int main() {
	Matrix A(3, 4), B(3, 4);

	for (int i = 0; i < A.rows(); i++)
		for (int j = 0; j < A.cols(); j++) {
			A(i, j) = i * A.cols() + j;
			B(i, j) = i * A.cols() + j;
		}

	for (int i = 0; i < A.rows(); i++) {
		for (int j = 0; j < A.cols(); j++)
			std::cout << A(i, j) << "  ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	Matrix C;
	C = A + B;
	for (int i = 0; i < C.rows(); i++) {
		for (int j = 0; j < C.cols(); j++)
			std::cout << C(i, j) << "  ";
		std::cout << std::endl;
	}
}

#endif

#endif


#if 0
using ElemType = char;   //假设数据元素类型ElemType是char类型
class Vector {
	ElemType* data{ nullptr };   //空间起始地址
	int  capacity{ 0 }, n{ 0 };   //空间容量和实际元素个数，初始化为0
public:
	Vector(const int cap = 5)   //创建容量是cap的一个线性表
		:capacity{ cap }, data{ new ElemType[cap] }	{}
	bool insert(const int i, const ElemType& e); //在i处插入元素
	bool erase(const int i);            //删除i元素
	bool push_back(const ElemType& e); //表的最后添加一个元素
	bool pop_back();  //删除表的最后元素
	//bool insert_front(const ElemType e);
	//bool pop_front();
	//bool find(const ElemType e);

	bool get(const int i, ElemType& e)const; //读取i元素
	bool set(const int i, const ElemType e);//修改i元素
	int size() const { return n; }  //查询表长
private:
	bool add_capacity();             //扩充容量
};

bool Vector::add_capacity() {
	ElemType* temp = new ElemType[2 * capacity];   //分配2倍大小的更大空间
	if (!temp) return false;                         //申请内存失败
	for (auto i = 0; i < n; i++) {                     //将原空间data数据拷贝到新空间temp
		temp[i] = data[i];
	}
	delete[] data;                               //释放原来空间内存
	data = temp;                                //data指向新的空间temp
	capacity *= 2;                              //修改容量
	return true;
}

//(a0,a1,..., e,  ai,...   an-1)
bool Vector::insert(const int i, const ElemType& e) {
	if (i < 0 || i > n) return false;          //插入位置合法吗？
	if (n == capacity && !add_capacity())   //已满，增加容量
		return false;
	for (auto j = n; j > i; j--)             //将n-1到i的元素都向后移动一个位置
		data[j] = data[j - 1];           //j-1移到j位置上
	data[i] = e;
	n++;                            //不要忘记修改表长
	return true;
}

bool Vector::erase(const int i) {
	if (i < 0 || i >= n) return false;    //位置i合法吗？
	 //i+1到n-1元素依次向前移动一个位置
	for (auto j = i; j < n - 1; j++)
		data[j] = data[j + 1];       //j+1移到j位置上
	n--;                         // 不要忘了：表长变量减去1。
	return false;
}

bool Vector::push_back(const ElemType& e) {
	if (n == capacity && !add_capacity())    //空间满就扩容
		return false;
	data[n] = e;
	n++;
	//data[n++] = e;                      //e放入下标n位置，然后n++
	return true;
}
bool Vector::pop_back() {
	if (n == 0) return false;          //空表
	n--;                         //n减去1就相当于删除了表尾元素
	return true;
}

bool Vector::get(const int i, ElemType& e)const {
	if (i >= 0 && i < n) {  //下标是否合法？
		e = data[i]; return true;
	}
	return false;
}
//修改i元素的值
bool Vector::set(const int i, const ElemType e) {
	if (i >= 0 && i < n) {  //下标是否合法？
		data[i] = e; return true;
	}
	return false;
}

#include <iostream>
void print(const Vector& v) {   //输出线性表中的所有元素
	ElemType ele;
	//遍历每一个下标i:0,1,…,size()-1
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, ele);   //通过e返回下标i处的元素值 
		std::cout << ele << '\t';
	}
	std::cout << std::endl;
}

int main() {
	Vector v(2);           //创建容量是2的空线性表
	v.push_back('a');     //线性表最后添加一个元素’a’
	v.push_back('b');     //线性表最后添加一个元素’b’
	v.push_back('c');
	v.insert(1, 'd');    //下标1处插入一个元素’d’
	print(v);
	ElemType e;
	v.get(1, e);         //查询下标1处的元素值
	std::cout << e << '\n';
	v.set(1, 'f');       //修改下标1处的元素值为’f’
	print(v);
	v.erase(2);          //删除下标2处的元素
	print(v);
	v.pop_back();       //删除最后一个元素
	print(v);
}
#endif


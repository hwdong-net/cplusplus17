#include <string>
#include <iostream>

#if 0
int main() {
	std::string s1{ "hello" }, s2{ "world" }, s3;
	s3 = s1 + s2; //用+、=对strign对象进行运算符
	std::cout << s3; //用<<将s3输出到cout中
}
#endif

#if 0
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	Point operator+(const Point &other) {
		return  Point(this->x + other.x, this->y + other.y);
	}

	friend void print(const Point &p);
};
#endif

#if 0
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	
	//...
	friend Point operator~(const Point &p);
	friend void print(const Point &p);
};
Point operator~(const Point &p){
	return Point(-p.y, -p.x);
}
#endif

#if 0
class Point {
	double x{}, y{};
public:
	Point(double x) :x{ x }, y{ 0 } {}
	Point(double x, double y) :x{ x }, y{ y }{}

	Point operator+(const Point &other) {
		return  Point(this->x + other.x, this->y + other.y);
	}
	friend void print(const Point &p);
};

int main() {
	Point P{ 3,4 }, Q{ 2,3};
	P + 2;	
	2 + P;
	P + Q;

}
#endif 

#if 0
class MyString {
private:
	char *data{ nullptr };
	int n{ 0 };
public:
	MyString(const char *str = "", int n = 0) :n(n) {		
		if (!n) data = nullptr;
		else
			data = new char[n];

		for (auto i = 0; i != n; ++i)
			data[i] = str[i];
	}

	~MyString() {
		std::cout << "deleting " << data << '\n'; 
		delete[] data;
	}
};

void f(){
	MyString s1{ "hello" }, s2{ "world" };
	s1 = s2;
}

int main() {	
	f();
}

#endif 

#if 0
class MyString{
private:
	char *data{ nullptr};
	int n{0};
public:
	MyString(const char *str = "", int n = 0) :n(n){
		if (!n) data = nullptr;
		else
			data = new char[n];

		for (auto i = 0; i !=n; ++i)
			data[i] = str[i];
	}
	
	MyString& operator=(const MyString &str);	
	
};
MyString& MyString::operator=(const MyString &str) {
	if (!str.n) { delete[] data; data = nullptr; n = 0; }
	char *temp = new char[str.n];
	if (temp) {
		if (data) delete[] data;
		data = temp;
		n = str.n;
		for (auto i = 0; i != str.n; ++i)
			data[i] = str.data[i];
	}	
	return *this;
}
#endif



#if 0
#include <iostream>
#include <utility>
using namespace std::rel_ops;

class Point {
	double x{}, y{};
public:
	double operator()(int n=2) {
		if (n <= 1) return std::abs(x) + std::abs(y);
		double xn(x), yn(y);
		for (auto i = 1;i != n; i++) { xn *= x; yn *= y; }
		return xn + yn;
	}
	Point(double x, double y) :x{ x }, y{ y }{}
	double& operator[](int i) {
		if (i == 0) return x;
		else if (i == 1) return y;
		else throw "下标非法";
	}
	double operator[](const int i) const{
		if (i == 0) return x;
		else if (i == 1) return y;
		else throw "下标非法";
	}
	Point & operator=(const Point & other) {
		if (this != &other) {
			x = other.x; y = other.y;
		}
		return *this;
	}

#if 0
	bool operator<(const Point &other);
	bool operator==(const Point &other);
	bool operator<=(const Point &other);
#else
	friend bool operator<(const Point P, const Point &Q);
	friend bool operator==(const Point P, const Point &Q);
#endif

	friend std::ostream& operator<<(std::ostream &out, const Point &p);
	friend Point operator+(Point P, const Point &other);
	friend void print(const Point &p);
};

#if 0
bool Point::operator<(const Point &other) {
	if (x == other.x)return y < other.y;
	return x < other.x;
}
bool Point::operator==(const Point &other) {
	return x == other.x && y==other.y;
}


bool Point::operator<=(const Point &other) {
	return *this<other||*this==other;
}
#else
bool operator<(const Point P, const Point &Q) {
	if (P.x == Q.x)return P.y < Q.y;
	return P.x < Q.x;
}
bool operator==(const Point P, const Point &Q) {
	return P.x == Q.x && P.y == Q.y;
}
#endif


std::ostream& operator<<(std::ostream &out, const Point &p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}
Point operator+(Point P, const Point &other) {
	return  Point(P.x + other.x, P.y + other.y);
}
void print(const Point &p) {
	std::cout << p.x << "," << p.y;
}
int main() {
	Point P{ 2,3 },Q(3,2);
	if (P > Q) std::cout << "P>Q";
	if(P!=Q) std::cout << "P!=Q";

	std::cout<<P(2)<<'\t'<<P(3)<<'\n';
}

#endif

#if 0
class Point {
	double x{}, y{};
public:
	operator double() const{
		return x * x + y * y;
	}
	Point(double x, double y) :x{ x }, y{ y }{}
};

int main() {
	Point P(3, 4);
	double d = P;
	std::cout << d << '\n';
}
#endif 


#if 0

class A {
	//…
public:
	A(int);
	operator int();
	friend A operator+(const A& a1, const A& a2);
};
A operator+(const A& a1, const A& a2) {
	A ret{1.};
	//...
	return ret;
}
A::operator int(){
	//...
	return 0;
}

int main() {
	A a{1};
	int i = 1, z;
	z = a + i; //错：到底是 A+A还是int+int
	z = (int)a + i;
	z = a + A(i);
}
#endif


#if 0
class Matrix {
	double *data{nullptr};
	int m{}, n{}; //行数和列数
public:	
	Matrix(const int m=0, const int n=0);
	explicit Matrix(const int m) :Matrix(m, m) {} //为防止将一个int值隐含自动转换为Matrix类型，这里用explicit
	double operator() (const int i, const int j)const;
	double& operator()(const int i, const int j);

	Matrix(const Matrix& M);
	Matrix& operator=(const Matrix& M);

	Matrix & operator+=(const Matrix &M);
	Matrix & operator-=(const Matrix &M);
	Matrix & operator*=(const Matrix &M);

	friend Matrix operator+(const Matrix &A, const Matrix &B);
	friend Matrix operator-(const Matrix &A, const Matrix &B);
	friend Matrix operator*(const Matrix &A, const Matrix &B);
	int rows()const { return m; }
	int cols()const { return n; }
};

Matrix::Matrix(const int m, const int n) :m(m),n(n){
	if (m == 0 || n == 0) return;
	data = new double[m*n];
	if (!data) {	this->m = this->n = 0; return;	}
}
double Matrix::operator() (const int i, const int j)const {
	int k = i * n + j;
	return data[k];
}
double& Matrix::operator() (const int i, const int j) {
	int k = i * n + j;
	return data[k];
}

Matrix::Matrix(const Matrix& M):Matrix(M.m,M.n) {
	if (data) {
		int num = m * n;
		for (auto i = 0; i != num; i++)data[i] = M.data[i];
	}
}
Matrix& Matrix::operator=(const Matrix& M) {
	delete[] data;
	m = M.m; n = M.n;
	int num = m * n;
	data = new double[num];
	for (auto i = 0; i != num; i++)data[i] = M.data[i];
	return *this;
}

Matrix & Matrix::operator+=(const Matrix &M) {
	if (m != M.m || n != M.n) return *this;
	int num = m * n;
	for (auto i = 0; i != num; i++)data[i] += M.data[i];
	return *this;

}
Matrix & Matrix::operator-=(const Matrix &M) {
	if (m != M.m || n != M.n) return *this;
	int num = m * n;
	for (auto i = 0; i != num; i++)data[i] -= M.data[i];
	return *this;
}
Matrix & Matrix::operator*=(const Matrix &M) {
	//...补充你的代码
	return *this;
}

Matrix operator+(const Matrix &A, const Matrix &B) {
	Matrix C(A);
	C += B;	
	return C;
}
Matrix operator-(const Matrix &A, const Matrix &B) {
	Matrix C(A);
	C -= B;
	return C;
}
Matrix operator*(const Matrix &A, const Matrix &B) {
	Matrix C(A);
	C *= B;
	return C;
}

int main() {
	Matrix A(3, 4),B(3,4);
	
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
	C = A+ B;
	for (int i = 0; i < C.rows(); i++) {
		for (int j = 0; j < C.cols(); j++)
			std::cout << C(i, j) << "  ";
		std::cout << std::endl;
	}
	
}

#endif
#if 0
class Point {
	double x{}, y{};
public:	
	Point(double x, double y) :x{ x }, y{ y }{}

	Point& operator++(); //前缀自增运算符必须返回这个对象自身的引用
	const Point operator++(int); //后缀自增运算符必须带一个int参数，且不能返回对象自身的引用
	friend void print(const Point &p);
};

Point& Point::operator++() {
	++x; ++y;
	return *this;
}
const Point Point::operator++(int) {
	Point P(*this);
	++(*this); //对象自身自增
	return P;//返回的时一个临时对象
}
int main() {
	Point P{ 2,3 };
	++ ++P;  //OK：因为++P返回的就是P自己，可以继续对它再用++运算
	(++P)++; //OK:理由同上
	P++ ++; //错：因为P++返回的不是自身引用，不能继续对P++再用++运算
	++(P++); //错：理由同上
}
#endif

#if 0
+    ?   ?   /   %   ?   &   |   ?   !
+=   ?=  ?=  /=  %=  ?=  &=  |=  <<= >>=
>    <   >=  <=  ==  !=  <<  >>
&&   ||  ++  --  ->  ->*  ,   *  T
[]  ()  new new[] delete delete[]

!= < > +=
? = ? = /= %= ? = &= |=
<< >> >>= <<= == != <=
>= && || ++?? ? > ?,
? > []() new new[] delete delete[]
#endif 
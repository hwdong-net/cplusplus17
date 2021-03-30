## const

### const对象

可以用**const**关键字定义一个变量，说明这个变量的值是不变的，告诉编译器程序员不能在代码中修改这个const（变量）对象的值。
既然const对象是不能被修改的，因此定义const变量（对象）时，就必须对它初始化。如：
```cpp
int main(){
  cosnt int i=3;
  i=4; //错：const对象不能被修改
  const double r; //错：定义时未初始化
}
```
const对象用于表示一个常量值，如表示圆周率PI，既然是编译期确定的常量值，也可以用来作为数组的大小。如：
```cpp
const double PI = 3.1415926;
int main(){
  cosnt int Size=10;
  double scores[Size];
}
```
当然，const对象可以用非const对象或表达式初始化，也可以用const对象对非const变量初始化或赋值：
```
int main(){
  int a{2},b;
  cosnt int i=a*2;
  b = a;
}
```


#### const和指针

下面代码定义了3个指针变量p、q、s：
```cpp
int main(){
  int i{0};
	int *const p = &i;
	const int *q = &i;
	int const *s = &i;
	std::cout << *p << '\t' << *q << '\t' << *s << '\t';
}
```
根据理解变量的从右向左规则，紧挨着p的是一个const，说明p首先是一个const变量（对象），
即p 的值是不可以修改的，再往左看，是`int*`说明p变量存储的是`int*`的值，即int 变量的地址，
即p是不可被修改的`int *`指针变量，或者说p是一个`int*`的const对象。

q和s紧挨着的是`*`，说明它们首先是一个指针变量，再往左看是const int和int const，
说明q和s指向的变量是const int和int const。const int和int const这2个类型是一样的，
因此，q和s的类型是一样的，是指向const int变量的指针变量，即它们指向的变量是不能被修改的（const int），
但它们本身是可以被修改的。

因此，下列代码是没有任何错误的：

```cpp

  *p = 2;  //p不能被修改，但它指向的int类型变量是可以被修改的
  std::cout << *p << '\t' << *q << '\t' << *s << '\n';
  int j{ 3 };
  q = &j;   //修改q指向另一个int变量j
  s = &j;   //修改s指向另一个int变量j
  std::cout << *p << '\t' << *q << '\t' << *s << '\n';	
```
而下面代码是错误的：
```cpp
 p = &j;   //错：p是不能被修改的
  *q = 4;   //错：q指向的是const int对象，const对象是不能被修改的
  *s = 4;   //错：s指向的是const int对象，const对象是不能被修改的
```

下面的指针p4是const对象（即p4不能被修改），且它指向的也被认为是const对象（即也不能修改其执行的对象，即`*P4`）。：
```cpp
const int* const p4; //指向const char的const指针
```

#### const对象的引用
可以定义一个const对象的引用，如：
```cpp
 int main(){
    int i = 42;
    const int ci = 1024; //ci是const int对象，即不能修改的int，也称为常量
    const int &r1 = ci;   //用const int初始化const int的引用变量r1
    const int &r2 = i;    // 用non-const的int变量i初始化const int的引用变量r2
    const int &r3 = 42;   // 用文字量42初始化const int的引用变量r3
    const int &r4 = r1 * 2; // 用文字量r1 * 2初始化const int的引用变量r4
 }
```
r,r1,r2,r3都是const int对象的引用变量。因此不能对它们引用的对象进行修改。
它们可以用const对象、非const对象、文字量或表达式初始化，
实际上对于用非const对象的初始化的const对象的引用，它们引用的是临时的const对象。

```cpp
  double dval = 3.14;
  const int &r8 = dval; //dval是double类型，而r8是const int类型的引用。
```
实际上，““const int &r8 = dval;”替换为如下形式：
```cpp
const int temp = dval;
const int &r8 = temp;
```
因为引用变量是不可以修改的，因此"int& const r"和"int& r"都表示的引用变量是不可以修改的，因此const在这里是多余的。但它们执行的那个变量是可以修改的：
```cpp
#include <iostream>
using namespace std;

int main() {
	int i{ 1 };
	int& const r = i;
	r = 3;
	cout << r << endl;
}
```
因为引用变量本身一旦一定就不可修改，因此“int &const r=i”和"int &r = i"是同一个意思。
```cpp
int main() {
	int i{ 0 };
	int& const r = i;//int&   r1 = i;
	r = 4; //即i =4;
	cout << i << " " << r << endl;
}
```
非const对象的引用不能引用const对象，如：
```cpp
int main() {
	int i{ 0 };
	const int ci{ 4 };
	int&  const r1 = i;//int&   r1 = i;
	int& const r2 = ci;//非const对象的引用不能引用const对象
	int&  r3 = ci;//非const对象的引用不能引用const对象
	r1 = 4;
	cout << i << " " << r1 << endl;
}
```

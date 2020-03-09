1.	下面哪些是不合法的变量标识符？为什么？
```
@ohd       *zara    a2bc   move_name   a_123
myname50   _temp   j     a23b9      retVal    51_name
```
2. 编译下面的程序，看看有什么编译错误。
```cpp
#include <iostream>
#include <string>
int main() {
	std::string s = "hello", s2 = "world";
	std::cout << s * s2;
	std::cout<<3*s ;
}
```

3.	指出下面文字量的数据类型并说明每组文字量的值的区别。
```
(A) 'a', L'a', "a", L"a"，u'a', U'a'
(B) 10, 10u, 10L, 10uL, 012, 0xC,0xAuLL
(C) 3.14, 3.14f, 3.14L, .314e-2L
(D) 10, 10u, 10., 10e-2
```
4. 下列程序的输出是什么？
```cpp
1）int main(){
  int a = -1,b = -1;
    unsigned c = 1;
    cout <<a*b <<endl << a*c << endl;
  }
  
2）int main(){
unsigned u=42,u2=10;
cout<<u-u2<<endl;
cout<<u2-u<<endl;
int i=10, i2=42;
cout<<i-i2<<endl;
cout<<i2-i<<endl;
cout<<i-u<<endl;
cout<<u-i<<endl;
}

3)
 int main(){
for(unsigned int i = 10; i>=0;i--)
  cout <<i << endl;
}
```

5. 下列关于auto的用法哪里有错误？为什么？
```cpp
	auto x;
	auto y{};
	auto z{ 0 };
	auto u = z;
	auto v(u);
```

6. 修改下列代码的语法错误，运行修改后的程序，体会变量的不同初始化方式。
```cpp
#include <iostream>
int main() {
	double d;
	double d1{ 3.5 };
	double d2 = { 3.5 };
	double d3 = 3.5;
	double d4(3.5);
	int i;
	int i1{ 3.5 };
	int i2 = { 3.5 };
	int i3 = 3.5;
	int i4(3.5);

	std::cout << d << '\t' << d1 << '\t'
		<< d2 << '\t' << d3 << '\t' << d4 << '\n';

	std::cout << i << '\t' << i1 << '\t'
		<< i2 << '\t' << i3 << '\t' << i4 << '\n';
	
	auto a = 3.5;
	auto a1 { 3.5 };
	auto a2 = i2 + d2 / 2;
	std::cout << a << '\t' << a1 << '\t' << a2 << '\n';
}
```


7.补充完善下面的程序，根据输入字符串的值设置相应的Color类型变量color的值。
```cpp
#include <iostream>
#include <string>
using namespace std;
enum class Color { red, green, blue };
int main() {
	string str;
	Color color;
	cin >> str;
	if (str == "red") color = Color::red;
	//...
}
```
8. 下面两组变量的定义有什么区别？有没有错误？为什么？
```cpp
1）int month{ 8 }, day{ 6 };
2）int month{08},day{ 06 };
```


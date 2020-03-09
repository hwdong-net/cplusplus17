1.	输入一个正整数，要求输出数字是逆序的正整数。如输入2357，应输出7532。
2. 下列运算的结果是什么？
```cpp
unsigned long ul1 = 3, ul2 = 7;
(A) ul1 & ul2      (B) ul1 | ul2     (C) ul1 && ul2    (D) ul1 || ul2
```
3. 下列运算的结果是什么？

```cpp
(A) (true&&true)||false
(B) (false&&true)||true
(C) (false&&true)||true||true
(D) (5>6||4>3)&&(7>8)
(E) |(7>4||3>4)
```

4. 下列语句的输出是什么？
```cpp
std::cout << (2, 3.4 , 5.5);
```

5. 下列程序的输出是什么？
```cpp
#include <iostream> 
int main() { 
   int a = 0; 
   int b; 
   a = (a == (a == 1)); 
   std::cout<<a; 
   return 0; 
} 
(A) 0     (B) 1    (C) 很大的负数   (D) -1
```
6. 下列程序的输出是什么？
```cpp
# include <iostream> 
int main() { 
    int x = 10; 
    int y = 20; 
    x += y += 10; 
std::cout<< x<<<" "<<y;
} 
(A) 40 20      (B) 40 30     (C) 30 30      (D) 30 40
```

7. 下面程序的输出是？
```cpp
#include <iostream> 
int main() { 
   int x = 10; 
   int y = (x++, x++, x++); 
   std::cout<< x<<<" "<<y; 
} 
(A) 13 12          (B) 13 13        (C) 10 10      (D) 依赖于编译器
```

8. 下列代码片段的输出是什么？为什么？
```cpp
	auto x{ 6 }, y{ 8 };
	auto c{ false }, d{ true };
	std::cout << (c ? ++x, y++ : --x, y--) << '\n';
	std::cout << (true ? ++x, ++y : --x, --y) << '\n';
	std::cout << c ? ++x, ++y : --x, --y << '\n';
```






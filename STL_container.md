## C++ STL Containers （容器模板）
[An Overview of C++ STL Containers](https://embeddedartistry.com/blog/2017/08/02/an-overview-of-c-stl-containers/)
[C++'s Built-In Data Structures](https://www.codecademy.com/learn/c-plus-plus-for-programmers/modules/cpp-built-in-data-structures/cheatsheet)
[https://en.cppreference.com/w/cpp/container](https://en.cppreference.com/w/cpp/container)
[https://cplusplus.com/reference/stl/](https://cplusplus.com/reference/stl/)

### arrays(数组)

C++ 中的数组用于存储相同类型的值的集合。数组的大小在声明时指定，之后不能更改。可以用下标运算符访问数组的元素。
```cpp
#include <iostream>

using namespace std;

int main()
{
  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  
  std::cout << vowels[2];	// Outputs: i
 
  char game[3][3] = {
    {'x', 'o', 'o'} , 
    {'o', 'x', 'x'} , 
    {'o', 'o', 'x'}  
  };
  
   std::cout << game[0][2];	// Outputs: o
  
  return 0;
}
```
除了静态数组，还可以用动态内存分配运算符new分配动态的数组空间。如：
```cpp
int * array = new int[5]; 
for(int i = 0 ; i<5;i++)
   array[i]  = 2*i+1;
delete[] array;
```

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
### vector (向量)

vector是C++的模板类，可以通过指定数据元素的类型实例化一个具体的vector实例类，如vector<int> 是数据元素类型是int的一个vector类。
vector<>类的对象和数组一样，可以通过下标访问其元素，但vector<>类对象大的空间可以自动动态增长而不用担心空间不足的问题。
```cpp
  std::vector <int> ints = {1,2,3,4,5};
  ints.push_back(11);
  ints.push_back(13);
  for(int i = 0 ; i<ints.size();i++)
         cout<<ints[i];
```
vector<>的常用操作有：
  . push_back(): add element to the end of the vector.
  . pop_back(): remove element from the end of the vector.
  . size(): return the size of the vector.
  . empty(): return whether the vector is empty.
  

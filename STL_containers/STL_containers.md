## C++ STL Containers （容器模板）
[An Overview of C++ STL Containers](https://embeddedartistry.com/blog/2017/08/02/an-overview-of-c-stl-containers/)
[C++'s Built-In Data Structures](https://www.codecademy.com/learn/c-plus-plus-for-programmers/modules/cpp-built-in-data-structures/cheatsheet)
[https://en.cppreference.com/w/cpp/container](https://en.cppreference.com/w/cpp/container)
[https://cplusplus.com/reference/stl/](https://cplusplus.com/reference/stl/)

C++内在的数组提供了存储同类型多个元素的一种数据结构。

### arrays(数组)

C++ 中的数组用于存储相同类型的值的集合。数组的大小在声明时指定，之后不能更改。
```cpp
int x[256];              //声明时指定大小
const char str[] = 'This is a string";  // 通过初始化指明大小
char vowels[ ] = {'a', 'e', 'i', 'o', 'u'};
```
除了静态数组，还可以用动态内存分配运算符new分配动态的数组空间。如：
```cpp
int * arr = static_cast<int*>(malloc(256 * sizeof(int)));
char *srr = new char[10];
```
可以用下标运算符访问数组的元素。
```cpp
int t = x[28];
arr[0] = t;
```

下标访问的本质是对指针进行偏移：
```cpp
cout<<x[3]<< *(x+3)<<endl;
```
通过指针访问内在数组的特点：

- When arrays are passed into functions, they decay into a simple pointer
 - Built-in arrays and pointers provide no bounds checking. The [] operator will allow you to write to any offset you want.
- You must keep track of array size separately
    - sizeof() only returns the correct size for statically allocated arrays when used in the same context you allocated them in
    - Do you keep track of size in bytes or elements? Will you remember the correct interpretation throughout your entire call chain?
- You must supply the size as an argument to functions which require array input
- You must remember whether your array is statically or dynamically allocated
- You must remember to free your dynamically allocated arrays

除了内在的静态数组和动态数组外，C++的容器库（containers library）实现了程序员经常需要使用的通用数据结构。容器是存储元素集合（即其他对象）的对象。这些容器中的每一个都管理其元素的存储空间，并通过迭代器和/或成员函数提供对每个元素的访问。C++的容器库包含一些模板和算法。

C++ 容器库将容器分为四种类型：

- 序列容器：array（静态连续数组），vector（动态连续数组）,forward_list(单链表),list（双向链表）,deque（双端队列）
- 序列容器适配器：stack(堆栈),queue(队列), priority_queue（优先队列）
- 关联容器 : 关联容器提供排序的数据结构，使用键提供快速查找（O(log n) 时间）。
  -  Keys are unique
       - set is a collection of unique keys, sorted by keys
       - map is a collection of key-value pairs, sorted by keys
       - set and map are typically implemented using red-black trees
  - Multiple entries for the same key are permitted
       - multiset is a collection of keys, sorted by keys
       - multimap is a collection of key-value pairs, sorted by keys
- 无序关联容器:无序关联容器提供可以使用散列访问的未排序数据结构。最坏情况下的访问时间为 O(n)，但对于大多数操作而言，访问时间比线性时间快得多。
   - Keys are unique
      - unordered set is a collection of keys, hashed by keys
      - unordered_map is a collection of key-value pairs, hashed by keys
   - Multiple entires for the same key are permitted
      - unordered_multiset is a collection of keys, hashed by keys
      - unordered_multimap is a collection of key-value pairs, hashed by keys


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
  - push_back(): 在最后添加一个元素
  - pop_back(): 删除最后一个元素
  - size(): 返回实际元素个数
  - empty(): 判断是否空？
  - erase(it) : 删除某个位置it的元素
  - insert(it,e): 位置it处插入一个元素
  
### stack 和 queue
  堆栈是stack一个Last-In-First-Out context (LIFO)的类模板，元素只能在栈顶插入(push())或删除(pop())。
  
  队列queue是一个First-In-First-Out context (FIFO)的类模板，元素只能在队尾插入(push())或删除队头元素(pop())。
  
  ```cpp
  int main()
{
  std::stack<int> tower;
  
  tower.push(3);
  tower.push(2);
  tower.push(1);
  
  while(!tower.empty()) {
    std::cout << tower.top() << " ";
    tower.pop();
  }
  // Outputs: 1 2 3
  
  std::queue<int> Q;

  Q.push(10);
  Q.push(9);
  Q.push(8);
  
  while(!Q.empty()) {
    std::cout << Q.front() << " ";
    Q.pop();
  }
  // Outputs: 10 9 8

  return 0;
}
```
  
### set
  在 C++ 中，集合（set）是包含唯一元素集合的数据结构。集合set的元素由它们自己的值或键索引。集合不能包含重复元素。一旦将元素添加到集合中，就无法修改该元素。
  C++的集合类型主要有unordered_set （无序集合） 和 set（有序集合）。前者用哈希表数据结构实现，后者用红黑树实现。
  
  主要操作如下：
  - insert(): add an element to the set.
  - erase(): removes an element from the set.
  - count(): check whether an element exists in the set.
  - size(): return the size of the set.
  
  ```cpp
  int main()
{
  std::unordered_set<int> primes({2, 3, 5, 7});
  
  primes.insert(11);
  primes.insert(13);
  primes.insert(11);  // Duplicates are not inserted
  
  primes.erase(2);
  primes.erase(13);
  
  // Outputs: primes does not contain 2.
  if(primes.count(2))
    std::cout << "primes contains 2.\n";
  else
    std::cout << "primes does not contain 2.\n";
  
  // Outputs: Size of primes: 4
  std::cout << "Size of primes: " << primes.size() << "\n";
  
  return 0;
}
  ```

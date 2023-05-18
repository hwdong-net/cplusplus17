### std: :accumulate

```cpp
template< class InputIt, class T >
T accumulate( InputIt first, InputIt last, T init );

template< class InputIt, class T, class BinaryOperation >
constexpr T accumulate( InputIt first, InputIt last, T init,
                        BinaryOperation op );
```
Computes the sum of the given value **init** and the elements in the range **[first,last)** .
The meaning of the **sum** can be defined by op.   

std::accumulate performs fold operation using op operation (function) on range [first, last) starting with init as accumulator value.

Effectively it's equivalent of:
```cpp
T acc = init;
for (auto it = first; first != last; ++it)
    acc = op(acc, *it);
return acc;
```

For example, do simple sum over a vector:

```
std::vector<int> v { 2, 3, 4 };
auto sum = std::accumulate(v.begin(), v.end(), 1);
std::cout << sum << std::endl; 
```
output:
```
10
```

If each digit in the vector is regarded as a certain digit of a integer, we can convert digits to number.

First define class digit2number as an operator:
```cpp
class digit2number {
public:
    int operator()(int acc, int d) const { return acc * 10 + d; }
};
```
then,accumulate using operator of digit2number:
```cpp
const int ds[3] = {1, 2, 3};
int n = std::accumulate(ds, ds + 3, 0, digit2number());
std::cout << n << std::endl;
```
output:
```
123
```
Lambda express is more simple then defining a class digit2number:
```cpp
const std::vector<int> ds = {1, 2, 3};
int n = std::accumulate(ds.begin(), ds.end(),
                        0,
                        [](int acc, int d) { return acc * 10 + d; });
std::cout << n << std::endl;
```






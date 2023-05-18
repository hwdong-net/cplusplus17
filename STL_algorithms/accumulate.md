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

**[Leetcode 2011. Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)**

There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

Example 1:
```
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
```
Example 2:
```
Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
```
Example 3:
```
Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
```

**c++ Solution**:
```cpp
// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        return accumulate(cbegin(operations), cend(operations), 0,
                          [](const auto& total, const auto& x) {
                              return total + ((x[1] == '+') ? 1 : -1);
                          });
    }
};
```




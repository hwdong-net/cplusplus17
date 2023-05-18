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

std::accumulate performs fold operation using f function on range [first, last) starting with init as accumulator value.




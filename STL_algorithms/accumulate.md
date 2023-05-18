### std: :accumulate

```cpp
template< class InputIt, class T >
T accumulate( InputIt first, InputIt last, T init );

template< class InputIt, class T, class BinaryOperation >
constexpr T accumulate( InputIt first, InputIt last, T init,
                        BinaryOperation op );
```
Computes the sum of the given value **init** and the elements in the range **[first,last)** .
The sum 



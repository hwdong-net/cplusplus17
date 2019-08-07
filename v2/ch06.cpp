/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include <iostream>
//scores是std::initializer_list<double>类型的变量
double average(std::initializer_list<double> scores) {
	auto n{ 0 };
	double all{ 0 };
	for (auto score : scores) {
		all += score; n++;
	}
	if (n > 0)	return all /= n;
	return 0;
}


#if 0

int main() {
	std::cout << average({  }) << '\n';
	std::cout << average({ 60. }) << '\n';
	std::cout << average({ 50.,80 }) << '\n';
	std::cout << average({ 90,50.,80 }) << '\n';
}
#endif 

#if 0
#include <iostream>
auto binarySearch(int a[], const int L, const int H, int value) {
	if (L > H)           //空序列
		return -1;
	auto Middle = (L + H) / 2;
	if (a[Middle] == value) // 1）中间元素直接比较
		return Middle;
	else 	if (value < a[Middle])
		return binarySearch(a, L, Middle - 1, value);    // 2) 左区间查找
	else
		return binarySearch(a, Middle + 1, H, value);  // 3) 左区间查找
}
int main() {
	int arr[]{ 5, 7, 12, 25, 34, 37, 43, 46, 58, 80, 82, 105 };
	std::cout << binarySearch(arr, 0, 11, 25) << '\t';
	std::cout << binarySearch(arr, 0, 11, 13) << '\n';
}
#endif 

#if 0
#include <iostream>
// 一个盘子：直接移动
void moveDisk(int i, const char x, const char y) {
	std::cout << "moving disk" << i << " from " << x << " to " << y << '\n';
}

// 参数：盘数, 起始柱, 中转柱, 目标柱
void move(int n, const char a, const char b, const char c) {
	if (n < 1) return;
	move(n - 1, a, c, b);  // n - 1个盘子从A柱借助于C柱移到B柱
	moveDisk(n, a, c);
	move(n - 1, b, a, c);   // n - 1个盘子从B柱借助于A柱移到C柱
}
int main() {
	move(3, 'A', 'B', 'C');
}

#endif

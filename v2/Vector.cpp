/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include "Vector.h"
#include <iostream>

#if 0
int main() {
	Vector<int> a;  // Vector<int>是Vector类模板的实例化类，其中的数据元素类型是int
	for (auto i = 0; i <= 6; i++)
		a.push_back(2 * i + 1);
	a[3] = 30;
	for (auto i = 0; i != a.size(); i++)
		std::cout << a[i] << '\t';
	std::cout << '\n';

	Vector<int> b;
	b = a;
	for (auto i = 0; i != a.size(); i++)
		std::cout << b[i] << '\t';
	return 0;
}
#endif

#if 0
int main() {
	Vector<Vector<int>> matrix{ {1,2,3,4},{5,6,7,8} };
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

#endif
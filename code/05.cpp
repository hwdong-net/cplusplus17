#if 0

int main() {
	int& ref4{ 10 };  //错： 不能引用文字量
	double dval{ 3.14 };
	int& ref5{ dval };  //错：引用变量类型和被引用变量类型不一致
}
#endif

#if 0

int main() {
	double* s;
	double& r;
}
#endif

#if 0
int main() {
	int zero{ 0 }, * p1;
	//int* p2{ zero };
	int* p{ 0 };
	int* p3{ 3 };

}
#endif

#if 0
#include <iostream>
int main() {
	int i;
	int* p{ &i }, * q{ 0 };
	bool b{ p };  // int*非空指针p转化为bool型值true,
				  // 然后对b初始化，因此，b的值是true
	std::cout << std::boolalpha << b << std::endl; //boolalpha操作符控制bool量的显示形式
	b = q;       // int *空指针q转化为bool型值false,
				  // 然后赋值给b，因此，b的值是false;
	std::cout << std::boolalpha << b << std::endl;
}
#endif

#if 0
#include <iostream>
int main() {
	int* pi;
	void* pv = pi; // ok: int*到 void*的隐式类型转换
	//*pv;    //错 :不能解引用 void*
//	++pv;   //错: 不能增量或偏移 void* (指向对象的内存大小未知)
	int* pi2 = static_cast<int*>(pv); // void* 强制类型转换到int*
	double* pd1 = pv;   // 错:不能将void*初始化或赋值给非void*指针变量
	double* pd2 = pi; // 错：指针类型不一致
	double* pd3 = static_cast<double*>(pv); // 不安全
}
#endif

#if 0
#include <iostream>
int main() {
	int i = 3;
	int* pi = &i;
	std::cout << i << "\t" << *pi << std::endl;
	void* pv = pi; // ok: int*到 void*的隐式类型转换
	//*pv=4;    //错 :不能解引用 void*
//	++pv;   //错: 不能增量或偏移 void* (指向对象的内存大小未知)
	int* pi2 = static_cast<int*>(pv); // void* 强制类型转换到int*
	*pi2 = 4;
	std::cout << i << "\t" << *pi << "\t" << *pi2 << std::endl;

	//double* pd1 = pv;   // 错:不能将void*初始化或赋值给非void*指针变量
	//double* pd2 = pi; // 错：指针类型不一致
	double* pd3 = static_cast<double*>(pv); // 不安全
	*pd3 = 3.14;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	int ival{ 1024 };
	int* pi{ &ival };  //pi 存储ival的地址
	int** ppi{ &pi }; // ppi存储pi的地址。 pi的类型是int *，
				   // 所以&pi的类型 (int *) *，即 int **，int **就是(int *)*
				   // ppi ---> pi -->ival  
	cout << "ival的值是： " << ival << endl;
	cout << "ival的值是： " << *pi << endl;    // *pi就是ival
	cout << "ival的值是：" << **ppi << endl;  // **ppi即 *(*ppi)，而*ppi就是pi，
 // 因此，**ppi就是 *(pi)即ival

	cout << "\nival的地址是：" << &ival << endl;
	cout << "ival的地址是：" << pi << endl;   //pi保存的是ival的地址
	cout << "ival的地址是：" << *ppi << endl; //*ppi就是pi

	cout << "\npi的地址是：" << &pi << endl;
	cout << "pi的地址是：" << ppi << endl;   //pi保存的是ival的地址  
}

#endif

#if 1
int main() {
	auto i{ 0 }, j{ 1 };
	int* p;            //指针变量不一定要初始化
	int& r{ i };
	int &r1;     //错：引用变量r1没有初始化！
	p = &i;          //p指向i
	p = &j;        //p指向j
	auto * &rp{ p };    // rp引用p
//	int*& rp2;       //错：引用变量rp2没有初始化
//	int&* q;         //错： 不能定义指向引用的的指针，
					// 因为引用变量没有独立内存(即没有地址)
	int&* q2 = &r;  //错：原因同上. 另外，取地址运算符&不能作用于引用变量r！ 
}
#endif
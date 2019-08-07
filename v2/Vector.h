/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#pragma once
//#include <initializer_list>
#include <iostream>
template<typename T>
class Vector {
	T *data{ nullptr };
	int  capacity{ 0 }, n{ 0 };
public:
	explicit Vector(const int cap = 5)
		:capacity{ cap }, data{ new T[cap] }, n{ 0 }
	{}
	Vector(std::initializer_list<T>	l) {
		data = new T[l.size()];
		if (!data) return;
		capacity = l.size(); n = l.size();
		auto i{ 0 };
		for (auto it = l.begin(); it != l.end(); it++, i++)
			data[i] = *it;
	}
	~Vector() { delete[] data; data = nullptr; }
	int size() const { return n; }
	void clear() { n = 0; }
	bool push_back(const T &e) {
		if (n == capacity && !add_capacity())
			return false;
		data[n] = e;
		n++;
		return true;
	}
	bool add_capacity() {
		T *temp = new T[2 * capacity];
		if (!temp) return false;
		for (auto i = 0; i < n; i++) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp; capacity *= 2;
		return true;
	}
	T& operator[](const int i) {
		if (i >= 0 && i < n) return data[i];
		else throw "下标非法";
		//	return const_cast<T&> (static_cast<const Vector<T>&>(*this)[i]);
	}
	T operator[](const int i) const {

		if (i >= 0 && i < n) return data[i];
		else throw "下标非法";
	}

	Vector(const Vector<T>& array); // 拷贝构造函数
	Vector& operator=(const Vector<T>& rhs); // 赋值运算符


	bool insert(const int i, const T &e) {
		if (i < 0 || i >= n) return false;
		if (n == capacity && !add_capacity())
			return false;
		for (auto j = n; j > i; j--)
			data[j] = data[j - 1];
		data[i] = e;
		return true;
	}
	bool erase(const int i) {
		if (i < 0 || i >= n) return false;
		for (auto j = i; j < n - 1; j++)
			data[j] = data[j + 1];
		n--;
		return false;
	}

	bool pop_back(const T e) {
		if (n == 0) return false;
		n--; return true;
	}
};
template <typename T>
Vector<T>::Vector(const Vector& vec)// : Vector{ vec.capacity }
{
	data = new T[vec.capacity];
	if (!data) return;
	n = vec.n; capacity = vec.capacity;
	for (size_t i{ 0 }; i < n; ++i)  //拷贝每个数据元素
		data[i] = vec.data[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (&rhs != this) // 当右操作数不等于自己时，才赋值
	{
#if 0
		delete[] data;
		data = new T[rhs.capacity];
		if (!data) { n = 0; return *this; }
		n = rhs.n;
		capacity = rhs.capacity;
		for (size_t i{}; i < n; ++i)  //拷贝每个数据元素
			data[i] = rhs.data[i];
#else
		Vector<T> ret{ rhs };
		std::swap(data, ret.data);
		std::swap(n, ret.n);
		std::swap(capacity, ret.capacity);
		//n = ret.n;
		//capacity = ret.capacity;==
#endif
	}
	return *this; // 返回自身的引用
}


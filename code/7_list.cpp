#include <iostream>
#if 0
class IntArray {
	int* data{ nullptr };      //指针变量指向动态分配的内存块
	int size{ 0 };            //data指向的动态数组的大小
public:
	IntArray(int s) :size(s) {
		data = new int[s];    //分配一块动态内存，地址保存在data中
		if (data)  size = s;
		std::cout << "构造了一个大小是" << s << "的IntArray对象\n";
	}
	~IntArray() {
		std::cout << "析构函数\n";
		if (data) delete[] data;  //释放data指向的动态内存
	}
	void put(int i, int x) {
		if (i >= 0 && i < size) data[i] = x;
	}
	int get(int i) {
		if (i >= 0 && i < size) return data[i];
		else return 0;
	}
};

#include <vector>
int main(){
	//int ages[5];//静态数组
	
	std::vector<int> ages;
	ages.push_back(3);
	ages.push_back(45);
	ages.size();
}
#endif
/*
struct student {
	string name;
	double score;
};
using ElemType = student;   //假设数据元素类型ElemType是char类型
*/
using ElemType = char;   //假设数据元素类型ElemType是char类型
class Vector{
	ElemType* data{ nullptr };   //空间起始地址
	int  capacity{ 0 }, n{ 0 };   //空间容量和实际元素个数，初始化为0
public:
	Vector(const int cap = 5)   //创建容量是cap的一个线性表
		:capacity{ cap }, data{ new ElemType[cap] }	{}
	bool insert(const int i, const ElemType& e); //在i处插入元素
	bool erase(const int i);            //删除i元素
	bool push_back(const ElemType& e); //表的最后添加一个元素
	bool pop_back();  //删除表的最后元素
	//bool insert_front(const ElemType e);
	//bool pop_front();
	//bool find(const ElemType e);

	bool get(const int i, ElemType& e)const; //读取i元素
	bool set(const int i, const ElemType e);//修改i元素
	int size() const { return n; }  //查询表长
private:
	bool add_capacity();             //扩充容量
};

bool Vector::add_capacity() {
	ElemType* temp = new ElemType[2 * capacity];   //分配2倍大小的更大空间
	if (!temp) return false;                         //申请内存失败
	for (auto i = 0; i < n; i++) {                     //将原空间data数据拷贝到新空间temp
		temp[i] = data[i];
	}
	delete[] data;                               //释放原来空间内存
	data = temp;                                //data指向新的空间temp
	capacity *= 2;                              //修改容量
	return true;
}

//(a0,a1,..., e,  ai,...   an-1)
bool Vector::insert(const int i, const ElemType& e) {
	if (i < 0 || i > n) return false;          //插入位置合法吗？
	if (n == capacity && !add_capacity())   //已满，增加容量
		return false;
	for (auto j = n; j > i; j--)             //将n-1到i的元素都向后移动一个位置
		data[j] = data[j - 1];           //j-1移到j位置上
	data[i] = e;
	n++;                            //不要忘记修改表长
	return true;
}

bool Vector::erase(const int i) {
	if (i < 0 || i >= n) return false;    //位置i合法吗？
	 //i+1到n-1元素依次向前移动一个位置
	for (auto j = i; j < n - 1; j++)
		data[j] = data[j + 1];       //j+1移到j位置上
	n--;                         // 不要忘了：表长变量减去1。
	return false;
}

bool Vector::push_back(const ElemType& e) {
	if (n == capacity && !add_capacity())    //空间满就扩容
		return false;
	data[n] = e;
	n++;
	//data[n++] = e;                      //e放入下标n位置，然后n++
	return true;
}
bool Vector::pop_back() {
	if (n == 0) return false;          //空表
	n--;                         //n减去1就相当于删除了表尾元素
	return true;
}

bool Vector::get(const int i, ElemType& e)const {
	if (i >= 0 && i < n) {  //下标是否合法？
		e = data[i]; return true;
	}
	return false;
}
//修改i元素的值
bool Vector::set(const int i, const ElemType e) {
	if (i >= 0 && i < n) {  //下标是否合法？
		data[i] = e; return true;
	}
	return false;
}

#include <iostream>
void print(const Vector& v) {   //输出线性表中的所有元素
	ElemType ele;
	//遍历每一个下标i:0,1,…,size()-1
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, ele);   //通过e返回下标i处的元素值 
		std::cout << ele << '\t';
	}
	std::cout << std::endl;
}

int main() {
	Vector v(2);           //创建容量是2的空线性表
	v.push_back('a');     //线性表最后添加一个元素’a’
	v.push_back('b');     //线性表最后添加一个元素’b’
	v.push_back('c');
	v.insert(1, 'd');    //下标1处插入一个元素’d’
	print(v);
	ElemType e;
	v.get(1, e);         //查询下标1处的元素值
	std::cout << e << '\n';
	v.set(1, 'f');       //修改下标1处的元素值为’f’
	print(v);
	v.erase(2);          //删除下标2处的元素
	print(v);
	v.pop_back();       //删除最后一个元素
	print(v);
}


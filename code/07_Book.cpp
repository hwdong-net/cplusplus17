#include <string>
class Book {
public:
	std::string name, author, publisher;
	double price;
};

using ElemType = Book; //ElemType定义为Book类型
class Vector {
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


//----------图书管理------------------
#include <iostream>
//输入一个数据元素的辅助函数
void input(ElemType& e) {
	std::cout << "请输入图书的信息：书名 作者 出版社 价格:\n";
	std::cin >> e.name >> e.author >> e.publisher >> e.price;
}
//打印一本图书信息
void print(const ElemType& e) {
	std::cout << e.name << e.author << e.publisher << e.price << '\n';
}
//打印Vector对象v中的所有图书信息
void print(const Vector& v) {
	ElemType e;
	for (auto i = 0; i != v.size(); i++) {
		v.get(i, e);
		print(e);//输出该图书信息
	}
	std::cout << std::endl;
}
//帮助提示函数
void help() {
	std::cout << "请输入命令:i(插入)、e(删除)、a(追加)、b(删除最后元素)、\n";
	std::cout << "s(修删除某序号元素)、g(查询某序号元素)、p(打印)\n";
}
int main() {
	Vector books;
	ElemType e;
	char cmd;
	help();
	while (std::cin >> cmd) {
		if (cmd == 27)break;
		else if (cmd == 'I' || cmd == 'i') {//插入一本图书
			std::cout << "请输入插入的位置（从0开始）：";
			int i; std::cin >> i;
			input(e);
			books.insert(i, e);
		}
		else if (cmd == 'e' || cmd == 'E') {//删除一本图书
			std::cout << "请输入删除的位置（从0开始）：";
			int i; std::cin >> i;
			books.erase(i);
		}
		else if (cmd == 'a' || cmd == 'A') {//在最后插入一本图书
			input(e);
			books.push_back(e);
		}
		else if (cmd == 'b' || cmd == 'B') {//删除最后一本图书
			input(e);
			books.pop_back();
		}
		else if (cmd == 's' || cmd == 'S') {//修改某序号的图书
			std::cout << "请输入要修改的图书的位置（从0开始）：";
			int i; std::cin >> i;
			input(e);
			books.set(i, e);
		}
		else if (cmd == 'g' || cmd == 'G') {//查询某序号的图书
			std::cout << "请输入要查询的图书的位置（从0开始）：";
			int i; std::cin >> i;
			books.get(i, e);
			print(e);
		}
		else if (cmd == 'p' || cmd == 'P') {//显示所有图书
			print(books);
		}
		help();

	}
}

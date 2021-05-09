#if 0
using ElemType = char;      //假设数据元素的类型是ElemType
struct LNode {             //struct定义的类的成员默认是公开的
	ElemType data;
	LNode* next{ nullptr };  //next是指向下一个元素结点的指针变量
};
#endif

using ElemType = char;      //假设数据元素的类型是ElemType
class List {
	struct LNode {    //struct定义的类的成员默认是公开的
		ElemType data;
		LNode* next{ nullptr }; //next是指向下一个元素结点的指针变量
	};
	LNode* head;         //指向头结点的指针变量
public:
	//初始化一个不含任何数据只有头结点的空的链表
	List() :head{ new LNode{} } {}

	bool insert(const int i, const ElemType& e); //在i处插入元素
	bool erase(const int i);            //删除i元素
	LNode* locate(const int i)const;

	bool push_back(const ElemType& e); //表的最后添加一个元素
	bool pop_back();  //删除表的最后元素

	bool push_front(const ElemType& e); //插入元素成为第一个元素（首结点）
	bool pop_front();  //删除首结点

	bool get(const int i, ElemType& e)const; //读取i元素
	bool set(const int i, const ElemType e);//修改i元素	
	int size() const;  //查询表长
};

bool List::push_front(const ElemType& e) {
	LNode* p = new LNode;     //创建一个新的结点
	if (!p) return false;          //分配内存失败!
	p->data = e;               //将新数据放入p指向的新结点的data成员中
	p->next = head->next;       //p的next指针指向原来的首结点
	head->next = p;            //head的next指向p指向的新结点，即新结点成为首结点。
}

bool List::pop_front() {
	if (!head->next) return false;   //空表
	LNode* p = head->next;      //p指向要删除的首结点
	head->next = p->next;        //head的next指向p的后一个结点，即跳过首结点
	delete p;                   //删除原来的首结点
	return true;
}
int List::size()const {
	LNode* p{ head }; auto i{ 0 };  //p指向头结点，计数器i为0
	p = p->next;               //p指向首结点，
	while (p) {                 //p不是空指针，表示遇到一个结点
		i++;                  //计数器增加1
		p = p->next;           //p指向下一个结点
	}
	return i;
}
List::LNode* List::locate(const int i)const {
	if (i < 0) return nullptr;//插入位置不合法
	LNode* p{ head }; auto j{ 0 };//p指向头结点，计数器i尾0
	while (p && j < i) {
		p = p->next;  //p指向下一个结点
		j++;
	}
	return p;
}

bool List::erase(const int i) {     //删除i元素
	LNode* p = locate(i - 1);          //定位i-1号结点	
	if (p) {                        //如果p指向的第i-1号结点存在
		LNode* q = p->next;       //q保存要删除的结点地址
		p->next = q->next;         //使p的next指针跳过q结点
		delete q;                 // 删除q指向的那个结点
		return true;
	}
	return false;                   //i超出了表长
}

bool List::insert(const int i, const ElemType& e) {
	LNode* p = locate(i - 1);             //定位i-1号结点	
	if (p) {                          //p指向的第i-1号结点存在
		LNode* q = new LNode;       //q指向分配的新结点内存块
		if (!q) return false;
		q->data = e;
		q->next = p->next;            //将p的后继结点挂到q的后面
		p->next = q;                 //将q指向的结点挂到p的后面
		return true;
	}
	return false;
}
bool List::get(const int i, ElemType& e)const {
	LNode* p = locate(i);//定位i号结点	
	if (p) {
		e = p->data; return true;
	}
	return false;
}
bool List::set(const int i, const ElemType e) {
	LNode* p = locate(i);//定位i号结点	
	if (p) {
		p->data = e; return true;
	}
	return false;
}

#include <iostream>
void print(const List& v) {
	ElemType e;
	for (auto i = 1; i <= v.size(); i++) {
		v.get(i, e);
		std::cout << e << '\t';
	}
	std::cout << std::endl;
}

int main() {
	List v;
	v.push_front('a');
	v.push_front('b');
	v.push_front('c');
	print(v);
	v.insert(1, 'd');
	print(v);
	ElemType e;
	v.get(1, e);
	std::cout << e << '\n';
	v.set(1, 'f');
	print(v);
	v.erase(2);
	print(v);
	v.pop_front();
	print(v);
}

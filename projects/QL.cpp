/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

//QL
#include <iostream>
#include <string>


template<typename T>
class Vector {
	T *data{ nullptr };
	int  capacity{ 0 }, n{ 0 };
public:
	explicit Vector(const int cap = 5) 
		:capacity{ cap }, data{ new T[cap] },n{0}
	{}
	Vector(std::initializer_list<T>	l) {
		data = new T[l.size()];
		if (!data) return;	
		capacity = l.size(); n = l.size();
		auto i{ 0 };
		for (auto it = l.begin(); it != l.end(); it++,i++)
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
	for (size_t i{0}; i < n; ++i)  //拷贝每个数据元素
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
		if(!data){ n = 0; return *this; }
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


template<typename T>
class Qst {
public:
	std::string action_name;  //动作名
	T Q_value;   //Q(s,a）的值
	int next_state;  //转移到的状态
	T reward;  //直接回报
	Qst(std::string a = " ", const int ns = 0, T r = 0, T qvalue = 0) :
		action_name{ a }, reward{ r }, next_state{ ns }, Q_value{ qvalue } {}
};

using State_QT_Table = Vector < Qst<double>>; //一个状态的QT表
using QT_Table = Vector<State_QT_Table>;  //所有状态的QT表

#if 0
void print(State_QT_Table &s_QT_table) {
	for (auto j = 0; j != s_QT_table.size(); j++)
		std::cout << s_QT_table[j].action_name << '\t'
		<< s_QT_table[j].next_state << '\t'
		<< s_QT_table[j].reward << '\t' << s_QT_table[j].Q_value << '\n';
}
#endif




#include <random>

template<typename T>
T random_real(const T lower_bound=0.,const T upper_bound=1.) {	
	std::uniform_real_distribution<T> unif(lower_bound, upper_bound);
	static std::default_random_engine re;
	return unif(re);
}
int random_int(const int lower_bound = 1, const int upper_bound = 52) {
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(lower_bound, upper_bound);	
	return dis(gen);
}

template<typename T>
class QLearning {
	using State_QT_Table = Vector < Qst<T>>; //一个状态的QT表
	using QT_Table = Vector<State_QT_Table>;  //所有状态的QT表
	QT_Table QT_table;
public:
	QLearning();
	QLearning(const Vector<Vector<int>> &maze);
	
	void Q_Learning(const int MAX_EPISODES = 15,
		const T EPSILON = 0.2, const T ALPHA = 0.1, const T GAMMA = 0.9);

	int random_start_state(); //随机选择出发状态
	//选择一个动作
	int choose_action(const int state, T EPSILON=0.1);
	//从当前状态state和动作action，获得环境的反馈：
	//（下一个状态next_state、直接奖励reward，next_state是否终止状态)
	bool get_env_feedback(const int state, const int action,
		int &next_state,T &reward);
	T max_Qvalue(const int s,int& action); //状态下的最大Qvalue及对应的action
	
	bool is_terminal(const int state);
	void print(); //打印QT_table
	void print_Q();//只打印Q表
	Vector<int> shortest_path(const int state);
};
template<typename T>
QLearning<T>::QLearning(){
	State_QT_Table s_QT_table;
	s_QT_table.push_back({ "s", 5, -1 });
	s_QT_table.push_back({ "e",1,0 });
	QT_table.push_back(s_QT_table);

	s_QT_table.clear();
	s_QT_table.push_back({ "w", 0, 0 });
	s_QT_table.push_back({ "e",2,0 });
	QT_table.push_back(s_QT_table);
	s_QT_table.clear();
	s_QT_table.push_back({ "s", 6, 1 });
	s_QT_table.push_back({ "w",1,0 });
	s_QT_table.push_back({ "e",3,0 });
	QT_table.push_back(s_QT_table);
	s_QT_table.clear();
	s_QT_table.push_back({ "w", 2, 0 });
	s_QT_table.push_back({ "e",4,0 });
	QT_table.push_back(s_QT_table);
	s_QT_table.clear();
	s_QT_table.push_back({ "w", 3, 0 });
	s_QT_table.push_back({ "s",7,-1 });
	QT_table.push_back(s_QT_table);
	s_QT_table.clear();
	QT_table.push_back(s_QT_table);//状态5是终止状态
	QT_table.push_back(s_QT_table);//状态6是终止状态
	QT_table.push_back(s_QT_table);//状态7是终止状态

//	terminal_states.push_back(5);
//	terminal_states.push_back(6);
//	terminal_states.push_back(7);
}

template<typename T>
void QLearning<T>::Q_Learning(const int MAX_EPISODES,
	const T EPSILON , const T ALPHA , const T GAMMA)
{
	//   循环的回合数
	for (auto episode = 0; episode != MAX_EPISODES; episode++)
	{
		auto step_counter{ 0 };
		auto s = random_start_state(); //选择随机出发状态
		std::cout<<"step: "<<episode<<" start State: "<<s<<'\n';
	//	s = 4;
		auto is_terminated{ false };
		print_Q();

		//update_env(S, episode, step_counter)
		while (!is_terminated) { //循环直到一局游戏结束
			auto action = choose_action(s, EPSILON); // 根据状态选择动作
			int s_next;
			T R;
			is_terminated = get_env_feedback(s, action, s_next,R); // 获取环境的反馈
			auto  q_predict = QT_table[s][action].Q_value;
			auto q_target = R; //如果s_next是结束状态，
			if (!is_terminated) { // 如果s_next不是结束状态，就更新q_target值
				T max_qvalue;
				auto  max_action{ 0 };
				max_qvalue = max_Qvalue(s_next, max_action);
				q_target = R + GAMMA * max_qvalue;				
			}
			QT_table[s][action].Q_value += ALPHA * (q_target - q_predict);  //更新Q值
			s = s_next;  //进入下一状态
		//	print_Q();				
		}
	}
	return;
}


template<typename T>
T QLearning<T>::max_Qvalue(const int s,int& action) {
	auto s_QT_table = QT_table[s];
	T max = s_QT_table[0].Q_value;
	action = 0 ;
	for (auto i = 1; i != s_QT_table.size(); i++) {
		if (s_QT_table[i].Q_value > max) {
			max = s_QT_table[i].Q_value;
			action = i;
		}
	}
	return max;
}
template<typename T>
int QLearning<T>::choose_action(const int state, T EPSILON) {	
	T rnd{ random_real(0.,1.)};
	if (rnd < EPSILON) 
		return  random_int(0, QT_table[state].size()-1) ;
	else {	
		auto  action{ 0 };
		max_Qvalue(state, action);		
		return action;
	}	
}

template<typename T>
int QLearning<T>::random_start_state() {
	int s{0};
	do{
		s = random_int(0, QT_table.size() - 1);
	} while (is_terminal(s));
	return s;
}
template<typename T>
bool QLearning<T>::get_env_feedback(const int state, const int action
	,int &next_state, T &reward) {
	next_state = QT_table[state][action].next_state;
	reward = QT_table[state][action].reward;

	return is_terminal(next_state);	
}

template<typename T>
bool  QLearning<T>::is_terminal(const int state) {
	return QT_table[state].size() == 0;
#if 0
	for (auto i = 0; i < terminal_states.size(); i++)
		if (terminal_states[i] == state)
			return true;
	return false;
#endif;
}

#include <iomanip>      // std::setw
template<typename T>
void QLearning<T>::print_Q() {
	for (auto i = 0; i != QT_table.size(); i++) {
		if (QT_table[i].size() == 0)continue;
		std::cout << "state " << std::setw(3) << i << ":" << std::setw(3);
		for (auto j = 0; j != QT_table[i].size(); j++)
			std::cout <<"("<< QT_table[i][j].action_name<<","
			<<QT_table[i][j].Q_value<<")\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template<typename T>
void QLearning<T>::print() {
	for (auto i = 0; i != QT_table.size(); i++) {
		if (QT_table[i].size() == 0)continue;
		std::cout << "state " << std::setw(3) << i << ":"<<std::setw(3);
		for (auto j = 0; j != QT_table[i].size(); j++)
			std::cout <<"("<< QT_table[i][j].action_name <<","
			<< QT_table[i][j].next_state <<","
			<< QT_table[i][j].reward << "," << QT_table[i][j].Q_value << ")\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template<typename T>
Vector<int> QLearning<T>::shortest_path(const int state)
{	
	Vector<int> path;
	auto s{ state };
	while (!is_terminal(s)) {
		path.push_back(s);
		auto  action{ 0 };
		max_Qvalue(s, action);		
		s = QT_table[s][action].next_state;			
	}
	path.push_back(s);
	return path;
}

template<typename T>
QLearning<T>::QLearning(const Vector<Vector<int>> &maze) {
	const auto m{ maze.size() }, n{ maze[0].size() };
	int s{ 0 };	
	for (auto i = 0; i < m; i++) {
		for (auto j = 0; j < n; j++, s++) {			
			State_QT_Table s_QT_table;//s状态的QT表
			if (maze[i][j]!=0){ //std::abs(reward) > 1e-10) { //终止状态
				QT_table.push_back(s_QT_table); continue;
			}
			if (i >= 1) {
				auto s_next = s - n;			
				s_QT_table.push_back({ "U", s_next, static_cast<T>(maze[i-1][j]) });
			}
			if (i < m - 1) {
				auto s_next = s + n;				
				s_QT_table.push_back({ "D", s_next,  static_cast<T>(maze[i+1][j]) });
			}
			if (j >= 1) {
				auto s_next = s - 1;				
				s_QT_table.push_back({ "L", s_next, static_cast<T>(maze[i][j-1]) });
			}
			if (j < n - 1) {
				auto s_next = s + 1;				
				s_QT_table.push_back({ "R", s_next, static_cast<T>(maze[i][j+1]) });
			}			
			QT_table.push_back(s_QT_table);
		}

	}
}

int main() {
#if 0
	for (auto i =0; i < 10 ; i++){
		std::cout<<random_int(0,3)<<std::endl;;
	}
	return 0;
#endif;

#if 0
	QLearning<double> ql;
	ql.print();
	ql.Q_Learning();
#else	
	Vector<Vector<int>> maze{ {0, 0, 0, 0},	
	                          {0,-1, 0, 0},
                              {0,-1,-1, 0},
                              {0, 0, 0, 1} };

	for (auto i = 0; i < maze.size(); i++) {		
		for (auto j = 0; j < maze[i].size(); j++) {
			std::cout << maze[i][j] << "  ";
		}
		std::cout << std::endl;	
	}
	QLearning<double> ql(maze);
//	ql.print();
	ql.Q_Learning(100);
#endif

	

	//输出从一个状态s出发到达终止状态的最佳路径
	auto s{ 0 };
	auto path = ql.shortest_path(s);
	std::cout << "shortest_path from " <<s<< std::endl;
	for (auto i = 0; i != path.size(); i++)
		std::cout << path[i] << '\t';
	std::cout << std::endl;

	return 0;
}

#if 0
int main() {
	Vector<Vector<int>> matrix{ {1,2,3,4},{5,6,7,8} };

	for (auto i = 0; i < matrix.size(); i++) {
		//std::cout << maze[i].size();
		for (auto j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}
#endif 

#if 0


 q_Table
def build_Q_table(state_actions = None) :
	Q = {}
	if state_actions == None :
		Q = [{'s':0, 'e' : 0}, { 'w':0,'e' : 0 }, { 'w':0,'s' : 0,'e' : 0 }, { 'w':0,'e' : 0 }, { 'w':0,'s' : 0 }]
	else :
		for actions in state_actions :
for action in actions :
action.append(0)
return Q


初始化游戏环境：状态转移及奖励、终止状态
def build_T_table(transit_table = None, terminal_states = None) :
	if transit_table == None :
		transit_table = { 
		(0,'s') : (5,-1),(0,'e') : (1,0),
		(1,'w') : (0,0),(1,'e') : (2,0),
		(2,'s') : (6,1),(2,'w') : (1,0),(2,'e') : (3,0),
		(3,'w') : (2,0),(3,'e') : (4,0),
		(4,'w') : (3,0),(4,'s') : (7,-1) }
		if terminal_states == None :
			terminal_states = { 5,6,7 }
			return transit_table, terminal_states


#endif 
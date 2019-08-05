#include <iostream>
#include "plot.h"

using namespace std;
//#define SIMULATE
//#define HOUSE_DATA

#ifdef  SIMULATE
const int M{ 10 };
const int m{ 5 }, n{2};   //m是样本数目，n是theta参数个数
#else
const int M{ 47 };
const int m{ 47 }, n{3};   //m是样本数目，n是theta参数个数
#endif 
double house_data[][3]{
2104,3,399900,
1600,3,329900,
2400,3,369000,
1416,2,232000,
3000,4,539900,
1985,4,299900,
1534,3,314900,
1427,3,198999,
1380,3,212000,
1494,3,242500,
1940,4,239999,
2000,3,347000,
1890,3,329999,
4478,5,699900,
1268,3,259900,
2300,4,449900,
1320,2,299900,
1236,3,199900,
2609,4,499998,
3031,4,599000,
1767,3,252900,
1888,2,255000,
1604,3,242900,
1962,4,259900,
3890,3,573900,
1100,3,249900,
1458,3,464500,
2526,3,469000,
2200,3,475000,
2637,3,299900,
1839,2,349900,
1000,1,169900,
2040,4,314900,
3137,3,579900,
1811,4,285900,
1437,3,249900,
1239,3,229900,
2132,4,345000,
4215,4,549000,
2162,4,287000,
1664,2,368500,
2238,3,329900,
2567,4,314000,
1200,3,299000,
852,2,179900,
1852,4,299900,
1203,3,239500 };


double X[][1]{
	9.16481174938805,3.9617176989763605,1.9118988617843014,4.770872353143195,
	8.96268633959237,4.347497877496233,0.7837488406009996,9.003451281535993,
	9.219537986787007,0.14895852444561486 };
double Y[]{ 19.3296234987761, 8.923435397952721, 4.823797723568603, 10.54174470628639,
18.92537267918474, 9.694995754992465, 2.567497681201999, 19.006902563071986,
19.439075973574013, 1.2979170488912297
};

//一个样本的h(x)
inline auto h_theta_x(const double x[], const double theta[], const int n) {
	auto h{ 0. };
	for (int i = 0; i < n; i++)
		h += x[i] * theta[i];
	return h;
}

auto cost_function(double g[], const double X[][n], const double *Y, const double theta[], const int m)
{
	//	h_theta_x(h, X, theta, m, n);
	double f{ 0. };
	for (auto j = 0; j != n; j++) g[j] = 0.;
	for (int i = 0; i < m; i++) {
		auto h = h_theta_x(X[i], theta, n);
		auto h_y{ h - Y[i] };
		//	auto h_y{ h[i] - Y[i] };
		f += (h_y * h_y);     //累加误差
		//累加梯度
		for (int j = 0; j < n; j++)
			g[j] += (h_y * X[i][j]);
	}
	f /= (2 * m); //平均误差
	for (int j = 0; j < n; j++) //平均梯度
		g[j] /= m;
	return f;
}

auto gradient_descent(double X[][n], double *Y, double theta[],
	double alpha, const int iterations, const int m, double *cost_history)
{
	for (auto iter = 0; iter != iterations; iter++) {
		double g[n]{};
		auto f = cost_function(g, X, Y, theta, m);
		cost_history[iter] = f;	
		for (auto j = 0; j < n; j++) //更新theta
			theta[j] -= alpha * g[j];
	}
}


#ifdef SIMULATE

#if 0
int main() {
	//准备训练数据，为数据特征增加一列1
	double train_X[m][n]{}, train_Y[m]{};		
	for (int i = 0; i < m; i++) {
		train_X[i][0] = 1;
		train_X[i][1] = X[i][0];
		train_Y[i] = Y[i];
	}	
	double theta[n]{ }; //未知参数
	auto alpha(0.0001);
	auto iterations{ 1000 };
	double cost_history[1000];
	gradient_descent(train_X, train_Y, theta, alpha, iterations, m, cost_history);

	for (int j = 0; j != n; j++)
		cout << theta[j] << '\t';
	cout << '\n';

	for (int j = 0; j!=1000; j++)
		if(j % 99 == 1)
			cout <<j<<'\t'<< cost_history[j] << '\n';
	cout << '\n';

	//绘制代价曲线
	const int w = 80, h = 30;
	if (!initWindow(w, h)) {
		return 1;
	}	
	double *x = new double[iterations];
	for (int i = 0; i < iterations; i++) x[i] = i;	
	int n = 1000;
	plot(x, cost_history, n, w, h);
	delete[] x;
	return 0;
}
#else
// 用数值梯度检查分析梯度的计算是否正确
//代价函数
auto J(double X[][n], double *Y, double theta[], const int m) {
	double f{ 0. };
	for (int i = 0; i < m; i++) {
		auto h = h_theta_x(X[i], theta, n);
		auto h_y{ h - Y[i] };
		f += h_y * h_y;     //累加误差		
	}
	f /= (2 * m); //平均误差
	return f;
}
//数值梯度
auto computeNumericalGradient(double *grad_approx, double X[][n], double *Y, const double theta[],
	const int m, double epsilon = 1e-7)
{
	for (auto j = 0; j < n; j++) {
		double theta_plus[n]{};
		double theta_minus[n]{};
		for (int k = 0; k != n; k++) {
			theta_plus[k] = theta[k];
			theta_minus[k] = theta[k];
		}
		theta_plus[j] = theta[j] + epsilon;
		auto J_plus = J(X, Y, theta_plus, m);
		theta_minus[j] = theta[j] - epsilon;
		auto J_minus = J(X, Y, theta_minus, m);
		grad_approx[j] = (J_plus - J_minus) / (2 * epsilon);
	}
}

int main() {
	//准备训练数据，为数据特征增加一列1
	double train_X[m][n]{}, train_Y[m]{};
	for (int i = 0; i < m; i++) {
		train_X[i][0] = 1;
		train_X[i][1] = X[i][0];
		train_Y[i] = Y[i];
	}
	double theta[n]{0.5,1.1}; //未知参数

	double g[n]{}, g_[n]{}; //g是分析梯度，g_是数值梯度
	cost_function(g, train_X, train_Y, theta, m);
	computeNumericalGradient(g_, train_X, train_Y, theta, m);
	
	for (int j = 0; j != n; j++)
		cout << g[j] << '\t' << g_[j] << '\n';
	return 0;
}
#endif  

#endif //SIMULATE



#ifdef HOUSE_DATA

#include <iostream>
#include <cstdlib>
#include <ctime>
auto batch_data(double train_X[][n], double train_Y[], double X[][n], double Y[],
	const int M, const int m) 
{
	for (auto i = 0; i != m; i++) {
		int s = rand() % M;
		for (unsigned int j = 0; j != n; j++) {
			train_X[i][j] = X[s][j];
		}
		train_Y[i] = Y[s];
	}
}

auto batch_gradient_descent(double train_X[][n], double train_Y[], 
	double X[][n], double *Y, double theta[],
	double alpha, const int batch_iterations, const int iterations,
	const int M, const int m, double *cost_history)
{
	
	for (auto iter = 0; iter != batch_iterations; iter++) {
		batch_data(train_X, train_Y, X, Y, M, m);
		double * cost_history_ = cost_history + iter * iterations;
		gradient_descent(train_X, train_Y, theta, alpha, iterations, m, cost_history_);
	}
}


#if 0
int main_2() {
	//准备训练数据，为数据特征增加一列1
	double train_X[m][n]{}, train_Y[m]{}, X0[M][n]{};
	for (int i = 0; i < m; i++) {
		X0[i][0] = 1;
		X0[i][1] = X[i][0];
		//train_Y[i] = Y[i];
	}
	double theta[n]{ }; //未知参数
	auto alpha(0.0001);
	auto batch_iterations(4);
	auto iterations{ 500 };
	double cost_history[500*4];
	srand(static_cast <unsigned int> (time(0)));
	batch_gradient_descent(train_X, train_Y,X0,Y, theta, alpha, batch_iterations, iterations,
		M,m, cost_history);

	for (int j = 0; j != n; j++)
		cout << theta[j] << '\t';
	cout << '\n';

	for (int j = 0; j != 500 * 4; j++)
		if (j % 99 == 1)
			cout << j << '\t' << cost_history[j] << '\n';
	cout << '\n';
	return 0;
}
#else 


auto get_data(double X[][n], double *Y, double XY[][n], const int m) {
	for (auto i = 0; i != m; i++) {
		X[i][0] = 1;
		for (auto j = 0; j != n - 1; j++) {
			X[i][j + 1] = XY[i][j];
		}
		Y[i] = XY[i][n - 1];
	}
}


void print_data(double X[][n], const int m) {
	for (auto i = 0; i < m; i++) {
		for (auto j = 0; j != n; j++)
			std::cout << X[i][j] << '\t';
		std::cout << '\n';
	}
}

auto mean(double X[][n], const int m, const unsigned int col) {
	double mean_value{ 0 };
	for (auto i = 0; i != m; i++)
		mean_value += X[i][col];
	return 	mean_value /= m;
}

auto standard_deviation(double X[][n],  const int m,
	const unsigned int col,	const double mean_value)
{
	double sd{ 0 };
	for (auto i = 0; i != m; i++) {
		auto diff{ (X[i][col] - mean_value) };
		sd += diff * diff;
	}
	return sqrt(sd / m);
}

auto Normalization(double X[][n], const int m, const unsigned int col, 
	double &mean_value, double& sd) 
{
	mean_value =  mean(X, m,col) ;
	sd = standard_deviation(X, m,col,  mean_value);
	for (auto i = 0; i != m; i++) {	
		X[i][col] = (X[i][col] - mean_value) / sd;		
	}
}

double means[n], sds[n];
auto Normalization(double X[][n], const int m, double means[], double sds[],
	const unsigned int start_col=1) 
{
	print_data(X, 5);

	for (unsigned int col = start_col; col != n; col++)
		Normalization(X, m, col, means[col], sds[col]);
	print_data(X, 5);
}



int main() {
	//准备训练数据，为数据特征增加一列1
	double train_X[m][n]{}, train_Y[m]{}, X0[M][n]{},Y0[M];
	get_data(X0, Y0, house_data, M);
	
	Normalization(X0, M, means, sds);
	double theta[n]{ }; //未知参数
	auto alpha(0.01);
	auto batch_iterations(2);
	auto iterations{ 500 };
	double cost_history[500];
#if 1
	gradient_descent(X0, Y0, theta, alpha, iterations,	M,cost_history);
#else
	srand(static_cast <unsigned int> (time(0)));
	batch_gradient_descent(train_X, train_Y, X0, Y0, theta, alpha, batch_iterations, iterations,
		M, m, cost_history);
#endif

	for (int j = 0; j != n; j++)
		cout << theta[j] << '\t';
	cout << '\n';

	for (int j = 0; j != 500; j++)
		if (j % 39 == 1)
			cout << j << '\t' << cost_history[j] << '\n';
	cout << '\n';

	double x[3]{1.,1650,3};
	double pred = x[0] * theta[0] + (x[1] - means[1]) / sds[1] * theta[1]
		+(x[2] - means[2]) / sds[2] * theta[2];	
    std:cout << pred << endl;



	//绘制代价曲线
	const int w = 80, h = 30;
	if (!initWindow(w, h)) {
		return 1;
	}


	double *t = new double[iterations];
	for (int i = 0; i < iterations; i++) t[i] = i;
	int n = iterations;
	plot(t, cost_history, n, w, h);
	delete[] t;

	return 0;
}

#endif 


#if 0
auto Normalization(double Y[], const int m, double &mean_y, double &sd) {
	mean_y = 0;
	for (auto i = 0; i != m; i++)
		mean_y += Y[i];
	mean_y /= m;
	sd = 0;
	for (auto i = 0; i != m; i++) {
		sd+= (Y[i]- mean_y)*(Y[i]- mean_y);
	}
	sd /= m;
	for (auto i = 0; i != m; i++)
		Y[i] = (Y[i] - mean_y) / sd;
}









auto DEBUG{ true };
auto print_NUM{ 50 };


auto gradient_descent(double X[][n], double *Y, double theta[],
	double alpha, const int iterations, const int m,double *cost_history)
{
//	for (auto j = 0; j != n; j++)		cout << g[j] << '\t';
	for (auto iter = 0; iter != iterations; iter++) {
		double g[n]{};
		auto f = cost(g, X, Y, theta, m);
		cost_history[iter] = f;
		if (DEBUG&&iter%print_NUM == 1)
		{
			double grad_approx[n]{};
			std::cout << iter << "cost:" << f << '\t';
			computeNumericalGradient(grad_approx, X, Y, theta, m);
			auto diff{ 0. };
			for (auto j = 0; j != n; j++) {
				auto delta{ grad_approx[j] - g[j] };
				diff += delta * delta; // (grad_approx[j] - g[j])*(grad_approx[j] - g[j]);
			}
			diff /= n;
			std::cout << "check gradient diff :" << diff << '\n';
		}

		for (auto j = 0; j < n; j++) //更新theta
			theta[j] -= alpha * g[j];

	}
}


auto h_theta_x(double h[], double X[][n], double theta[], const int m)
{
	auto cost{ 0. };
	for (int i = 0; i < m; i++)
		h[i] = h_theta_x(X[i], theta, n);
}

void print_data(double X[], const int m) {
	for (auto i = 0; i < m; i++)
		std::cout << X[i] << '\t';
	std::cout << '\n';
}


int main() {
	double train_X[m][n]{},train_Y[m]{};
	double means[n]{}, sds[n]{}, mean_y{}, sd_y{};
	double theta[n]{0.5,1.5};
	auto alpha(0.0001);
	auto iterations{ 300 };
	double cost_history[300];
//	get_data(train_X, train_Y,house_data,m);
//	Normalization(train_X, m, means, sds);
	for (int i = 0; i < m; i++) {
		train_X[i][0] = 1;
		train_X[i][1] = X[i][0];
		train_Y[i] = Y[i];
	}
	print_data(train_X, 5);
	print_data(train_Y, 5);

	double g[n]{  }, grad_approx[n]{};
	
	auto c = cost(g,train_X, train_Y, theta, m);
	auto f = J(train_X, train_Y, theta, m);
	computeNumericalGradient(grad_approx, train_X, train_Y, theta, m);

	gradient_descent(train_X, train_Y, theta, alpha, iterations, m,cost_history);
	//return 0;

}

#endif 
#endif
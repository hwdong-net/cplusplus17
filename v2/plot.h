#pragma once
#include "ChGL.h"
inline void min_max(double s[], const int n, double &min, double &max) {
	if (n <= 0) return;
	min = s[0]; max = s[0];
	for (int i = 1; i < n; i++) {
		if (s[i] < min) min = s[i];
		if (s[i] > max) max = s[i];
	}
}

inline void plot(double x[], double y[], const int n, const int win_w, const int win_h, const int offset = 2, const bool upset = true) {
	auto plot_w{ win_w - 2 * offset }, plot_h{ win_h - 2 * offset };
	//求x[],y[]数组中的最大值、最小值
	double x_min, x_max, y_min, y_max, x_dist, y_dist;
	min_max(x, n, x_min, x_max);
	min_max(y, n, y_min, y_max);
	x_dist = x_max - x_min;
	y_dist = y_max - y_min;
	auto scale_x = new double[n], scale_y = new double[n];
	if (!scale_x || !scale_y) return;
	for (int i = 0; i < n; i++) {
		scale_x[i] = (x[i] - x_min) / x_dist;
		scale_y[i] = (y[i] - y_min) / y_dist;
		scale_x[i] *= plot_w;  //放缩到绘图plot窗口中
		scale_y[i] *= plot_h;
	}

	//绘制
	if (upset) {
		for (int i = 0; i < n; i++) {
			setPixel(scale_x[i] + offset, win_h - (scale_y[i] + offset), '*');
		}
	}
	else
		for (int i = 0; i < n; i++) {
			setPixel(scale_x[i] + offset, scale_y[i] + offset, '*');
		}
	delete[] scale_x;
	delete[] scale_y;
	show();
}
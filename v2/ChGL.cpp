#include <iostream>

using color = char;  //定义一个表示颜色的color类型，每种字符就是一种颜色
color* framebuffer{ nullptr };          //帧缓冲器
int framebuffer_width, framebuffer_height;
color clear_color{ ' ' };                //清屏颜色  

#if 1
#include "ChGL.h"
#else 
bool initWindow(int width, int height);  //初始化一个窗口，返回bool值表示成功还是失败
void clearWindow();               //清空窗口内容
void destoryWindow();             //销毁窗口，释放帧缓冲器占用的内存
void show();                      //显示帧缓冲区的图像
void setPixel(const int x, const int y, color c = ' ');            //设置像素的颜色
color getPixel(const int x, const int y);                       //设置像素的颜色
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }


bool initWindow(int width, int height) {

	framebuffer = new color[width*height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}




//销毁窗口，释放帧缓冲器占用的内存
void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//显示帧缓冲区的图像
void show() {
	for (int y = 0; y < framebuffer_height; y++) {
		for (int x = 0; x < framebuffer_width; x++)
			std::cout << framebuffer[y*framebuffer_width + x];
		std::cout << '\n';
	}
}

void setPixel(const int x, const int y, color c) {
	framebuffer[y*framebuffer_width + x] = c;
}

color getPixel(const int x, const int y) {
	return framebuffer[y*framebuffer_width + x];
}
#endif
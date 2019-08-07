/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   qq群：101132160
   微信公众号：hwdong编程
   C++17从入门到精通（源代码）：https://github.com/hwdong-net/cplusplus17
*/

#pragma once
using color = char;  //定义一个表示颜色的color类型，每种字符就是一种颜色
extern color* framebuffer;          //帧缓冲器
extern int framebuffer_width, framebuffer_height;
extern color clear_color;                //清屏颜色

//用清屏颜色clear_color清空窗口内容
inline void clearWindow() {
	if (!framebuffer) return;
	for (int y = 0; y < framebuffer_height; y++)
		for (int x = 0; x < framebuffer_width; x++)
			framebuffer[y*framebuffer_width + x] = clear_color;

}
//初始化一个窗口，返回bool值表示成功还是失败
inline bool initWindow(int width, int height) {

	framebuffer = new color[width*height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}


//销毁窗口，释放帧缓冲器占用的内存
inline void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//显示帧缓冲区的图像
inline void show() {
	for (int y = 0; y < framebuffer_height; y++) {
		for (int x = 0; x < framebuffer_width; x++)
			std::cout << framebuffer[y*framebuffer_width + x];
		std::cout << '\n';
	}
}

//设置像素的颜色
inline void setPixel(const int x, const int y, color c) {
	framebuffer[y*framebuffer_width + x] = c;
}
//得到像素的颜色
inline color getPixel(const int x, const int y) {
	return framebuffer[y*framebuffer_width + x];
}

inline void set_clear_color(color c) { clear_color = c; }
inline color get_clear_color() { return clear_color; }
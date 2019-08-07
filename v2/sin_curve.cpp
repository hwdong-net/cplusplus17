/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   微信公众号：hwdong编程
*/

#include <iostream>
#if 1
#include "ChGL.h"
#else
using color = char;  //定义一个表示颜色的color类型，每种字符就是一种颜色
color* framebuffer{nullptr};          //帧缓冲器
int framebuffer_width,framebuffer_height;
color clear_color{' '};                //清屏颜色  
          
bool initWindow(int width,int height);  //初始化一个窗口，返回bool值表示成功还是失败
void clearWindow();               //清空窗口内容
void destoryWindow();             //销毁窗口，释放帧缓冲器占用的内存
void show();                      //显示帧缓冲区的图像
void setPixel(const int x,const int y,color c=' ');            //设置像素的颜色
color getPixel(const int x,const int y);                       //设置像素的颜色
void set_clear_color(color c) { clear_color = c; }
color get_clear_color(){ return clear_color; }

//初始化一个窗口，返回bool值表示成功还是失败
bool initWindow(int width,int height){	
   
   framebuffer = new color[width*height];
   if(!framebuffer) return false;
   framebuffer_width = width;
   framebuffer_height = height;
   clearWindow();
   return true;
}

//用清屏颜色clear_color清空窗口内容
void clearWindow(){
   for(int y = 0; y< framebuffer_height;y++)
      for(int x = 0; x< framebuffer_width;x++)
	        framebuffer[y*framebuffer_width+x] = clear_color;     
   
}

//销毁窗口，释放帧缓冲器占用的内存
void destoryWindow(){
	delete[] framebuffer;
	framebuffer = nullptr;
}

//显示帧缓冲区的图像
void show(){
   for(int y = 0; y< framebuffer_height;y++){
     for(int x = 0; x< framebuffer_width;x++)
	         std::cout<<framebuffer[y*framebuffer_width+x];
     std::cout<<'\n'; 
  }
}

void setPixel(const int x,const int y,color c){
	framebuffer[y*framebuffer_width+x] = c;
}

color getPixel(const int x,const int y){
	return framebuffer[y*framebuffer_width+x];
}
#endif

#include <cmath>
#define SINEHEIGHT  12
#define DEGREESTEP  10

void draw_sin_curve(const int i){

	for (int degree = 0,j=0 ; degree < 361 ; degree = degree + DEGREESTEP,j++ )
	{		
		auto x = floor( ( degree / DEGREESTEP ) + 0.5 ) +1;
		auto y = floor(   sin(degree * 3.141 / 180 )  * ( SINEHEIGHT / 2 )  + 0.5 )
	    	+ SINEHEIGHT / 2 +1;
		if(j==i)
	    	setPixel(x,y,'O');
		else setPixel(x,y,'*');
	}

	auto x = 1;
	auto y = SINEHEIGHT / 2+1 ;
	setPixel(x,y,'*');
}



#include <windows.h>
inline void gotoxy(short int x, short int y){
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
inline void hideCursor(){
   CONSOLE_CURSOR_INFO cursor_info = {1, 0};
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

#if 0
int main(){	
	if(!initWindow(40,20)){		
		return 1;
	}
	for(auto k{0};k<100;k++){

	  for (int degree = 0 ,i=0; degree < 361 ; degree = degree + DEGREESTEP,i++ ){	  	  
	  	  hideCursor();
	  	  gotoxy(0,0);
	      draw_sin_curve(i);
	      show();	
      }
      break;

	}
}

#endif 
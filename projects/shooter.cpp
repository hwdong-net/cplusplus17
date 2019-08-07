/* ----------hwdong的教学资源---------------
   教学博客：https://hwdong.net
   youtube频道： hwdong
   twitter： hwdong
   B站和微博：hw-dong
   qq群：101132160
   微信公众号：hwdong编程
   C++17从入门到精通（源代码）：https://github.com/hwdong-net/cplusplus17
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


//====辅助函数=========

//------光标定位-------

void gotoxy(int x, int y){
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//------隐藏光标-------

void hideCursor(){
 CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


//---------常用的颜色-------

#define background_color ' '

#define boundary_color '+'
//---颜色------

#define enemy_color '@'

#define shooter_color '*'

#define bullet_color '|'

//------敌人位置------
int  enemy_x,enemy_y;

//------战机位置------
int shooter_x,shooter_y;

//------子弹位置------

int  bullet_x = -1,bullet_y = -1;

//==========画布==========

 const int canvas_width = 50,canvas_height=20; //画布canvas的长宽

 char canvas[canvas_height][canvas_width];     //画布内容是一个“像素是字符”的矩阵（矩形区域）


//---------清空画布--------

void clear_canvas(){
     for(int y = 0; y<canvas_height;y++)
		  for(int x = 0; x<canvas_width;x++)
              canvas[y][x] = background_color;
     int right  =canvas_width-1;
     for(int y = 0; y<canvas_height;y++){
        canvas[y][0] = boundary_color;
        canvas[y][right] = boundary_color;
     }
     int bottom  =canvas_height-1;
     for(int x = 0; x<canvas_width;x++){
        canvas[0][x] = boundary_color;
        canvas[bottom][x] = boundary_color;
     }
}



void setup(){
     hideCursor();
     enemy_x = canvas_width/2;
	 enemy_y = 2;

	 shooter_x = canvas_width/2;
	 shooter_y  = canvas_height-3;

}

//--------处理输入--------
void processInput(){
  char key;
  if(kbhit()){
	key = getch();
	if(key==' '){
	   //生成子弹的位置正好在战机的上方

	   bullet_x = shooter_x;
	   bullet_y = shooter_y-3;
	}
	else if(key=='a'||key=='A'){
             if(shooter_x>0)  shooter_x--;  //战机左移

	}
	else if(key=='d'||key=='D'){
             if(shooter_x<canvas_width-1)      shooter_x++;   //战机右移
	}
	else if(key=='w'||key=='W'){
              if(shooter_y>0)            shooter_y--;
	}
	else if(key=='s'||key=='S'){
              if(shooter_y<canvas_height-1)	       shooter_y++;
	}
   }

}

//--------更新数据--------

void update(){
  //存在子弹时，每次重新绘制画面前，子弹位置向上移动一个位置
 // if(bullet_y>1) bullet_y--;
}

void renderScene(){
    clear_canvas();

    if(enemy_x>=0&&enemy_x<canvas_width &&enemy_y>=0&&enemy_y<canvas_height)
		canvas[enemy_y][enemy_x] =  enemy_color;

    canvas[shooter_y-1][shooter_x] = shooter_color;
	canvas[shooter_y][shooter_x-1] = shooter_color;
	canvas[shooter_y][shooter_x] = shooter_color;
	canvas[shooter_y][shooter_x+1] = shooter_color;
	canvas[shooter_y+1][shooter_x-1] = shooter_color;
	canvas[shooter_y+1][shooter_x+1] = shooter_color;

	if(bullet_x>=0&&bullet_x<canvas_width&&bullet_y>=0
       &&bullet_y<canvas_height)
		canvas[bullet_y][bullet_x] =  bullet_color;

}


void show(){
  gotoxy(0,0);
  for(int y = 0; y< canvas_height;y++){
     for(int x = 0; x< canvas_width;x++)
	    std::cout<<canvas[y][x];
     std::cout<<'\n';
  }
}


int main(){
	setup();

	while(1){
		processInput();
		update();
		renderScene();
	 	show();
	}


  return 0;
}

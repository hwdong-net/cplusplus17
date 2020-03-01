 **注**：作业只限定于“面向对象程序设计”的3个班级的同学，请全国其他网友不要提交作业，

## 第一章作业

1. 编写程序输出下面的图案

   1) 
   ```

   ​               1
   ​           2      3
   ​      4       5      6
   ```

   2) 

   ```
   |\---/|
   | o_o |
    \_^_/
   ```

   更多参考[https://www.asciiart.eu/animals/cats](https://www.asciiart.eu/animals/cats)

2. 将十进制整数765431转换为十六进制，在十六进制形式下，如何将该数的二进制的第17位设置为1？写出对应的二进制形式。（手动转换，不需要编程）

3. 找出下面程序代码中的错误

   ```cpp
   #include <iostream>
   using namespace std
   void main () {   
      int FTemp = 0   
      int CTemp = 0;   
      cout >> "Enter a Farenheit temperature: ";   
      cin << FTemp;   CTemp = FTemp - 32 / (9/5);   
      cout >> "\n <<FTemp >> " in Farenheit = "  >> CTemp >> in Celsius\n";   
      return 0; 
   }
   ```

4. 写一个程序计算 cube(立方体), sphere(球)和cone(圆锥)的体积，并输出。

   各种立体的计算公式：

   ```
   Cube Volume = side^3
   Sphere Volume = (4/3) * pi * radius^3
   Cone Volume = pi * radius^2 * (height/3)
   ```

   代码框架：

   ```cpp
   #include<iostream>
   int main(){       
       float cubeSide = 5.4;    //Dimension of the cube    
       float sphereRadius = 2.33;   //Dimension of sphere 
       float coneRadius = 7.65;   //Dimensions of cone    
       float coneHeight = 14;        
       float volCube, volSphere, volCone = 0;        
       return 0;
   }
   ```

5. 从键盘输入3个实数，然后按从小到大的程序输出。

6. 从键盘输入一系列整数，求它们的最大值并输出。

   ```cpp
   #include <iostream>
   int main(){
       ? a;   //接受输入的整数变量
       ? max = -1000000;   //最大值，初始化为很小的值
       while(?::cin>>a){
           if(?)
               max = ?;
       }
       std::cout<<"最大的整数是："<<?<<'\n';
       return 0;
   }
   ```

   

7. 假设行数从键盘输入，打印输出如下的金字塔。

   1）输出字符*组成的金字塔

   ```
            *
          *   *
        *   *   *
      *   *   *   *
   ```

   参考代码框架：

   ```cpp
   #include <iostream>
   int main(){
       int rows;
       std::cout<<"请输入行数：";
       std::cin>>rows;
       for(int i = 1; i<=rows; i++){
           //输出一定数量的空白
           for(int space =1 ; space< ?;space++)
               std::cout<<" ";
           //输出2*i-1个字符'*'
           for(int k = 0; k< ?;k++)
               ?
           std::cout<<std::endl;//换行
       }
       return 0;
   }
   ```

   2） 改写上面的程序，输出下面的金字塔：

   ```
             1
          2  3  2
       3  4  5  4  3
    4  5  6  7  6  5  4
   ```

8. 写一个程序，从键盘输入一个正整数，判断它是否是质数。

   

   

   

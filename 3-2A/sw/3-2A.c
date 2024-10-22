#include<reg51.h>
#include<intrins.h>
sbit s1=P0^0;
void delay(unsigned int i)
 {
 unsigned int k;
 for(k=0;k<i;k++);
 }
void main(   )		   //主函数
{  unsigned  char   i;     //定义字符型变量i
   P1=0xff ;                   //P1口LED灯全灭
   while(1) 
   {  s1=1;                     //读引脚数据前先设置为1
      if(s1==0)                //检测到按键按下 
   {  delay(1200);          //延时10ms 去抖动
       if(s1==0)                //再次检测到按键按下    
      {   P1=0xFE;  
           for(i=0;i<8;i++)          //循环8次
            { delay(50000);           // 延时
               P1=_crol_(P1,1); }	 // P1左移1位	        
      } }
else P1=0x00;                //点亮发光二极管
  } 
}
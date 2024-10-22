#include <reg51.h>	             //包含头文件reg51.h 
#include <intrins.h>
sbit   s1=P0^0;                       //定义位变量
unsigned char key=0;
void delay(unsigned int i)     //定义延时函数 
{  unsigned  int  k;
   for(k=0; k<i;k++) ;     }
   void main(  )	         //主函数
{  unsigned  char   i;      //定义字变量i，记录按下次数、
   P1=0xff ;                     //P1=1111  1111B ,  LED灯全灭
   while(1)   
   {  s1=1;
      if(s1==0) 
     {  delay(1200);            //延时10ms 去抖动
         if (s1==0)                //再次检测到按键按下 
         key++;                    //记录按键次数
         key=key%5;          //处理按键次数
if(key==1)    {P1=0;}  //第一种情况，全亮
if(key==2)    {P1=0xFF;} //第二种情况，全灭  
if(key==3) {
             while(1){
			          P1=0;delay(50000);P1=0xFF;delay(50000);if(s1==1) {break;}      } 
			 } //第三种情况，闪烁
if(key==4) {P1=0xFE;  				   //第四种情况，流水灯
            for(i=0;i<8;i++)            //循环8次
            { delay(50000);           //延时
               P1=_crol_(P1,1); }	  //P1左移1位	        
            P1=0xff;}					  //流水灯结束所有灯熄灭
if(key==0)                //第五种情况
       {int m;
	   P1=0xFE;
	   for(m=0;m<7;m++){
	   delay(50000);
	   P1=P1<<1;}  
		}      
 while(!s1)  ;      //等待按键释放
 delay(1200);     //延时去抖动  
   }  }}

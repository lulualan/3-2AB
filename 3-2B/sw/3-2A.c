#include <reg51.h>	             //����ͷ�ļ�reg51.h 
#include <intrins.h>
sbit   s1=P0^0;                       //����λ����
unsigned char key=0;
void delay(unsigned int i)     //������ʱ���� 
{  unsigned  int  k;
   for(k=0; k<i;k++) ;     }
   void main(  )	         //������
{  unsigned  char   i;      //�����ֱ���i����¼���´�����
   P1=0xff ;                     //P1=1111  1111B ,  LED��ȫ��
   while(1)   
   {  s1=1;
      if(s1==0) 
     {  delay(1200);            //��ʱ10ms ȥ����
         if (s1==0)                //�ٴμ�⵽�������� 
         key++;                    //��¼��������
         key=key%5;          //����������
if(key==1)    {P1=0;}  //��һ�������ȫ��
if(key==2)    {P1=0xFF;} //�ڶ��������ȫ��  
if(key==3) {
             while(1){
			          P1=0;delay(50000);P1=0xFF;delay(50000);if(s1==1) {break;}      } 
			 } //�������������˸
if(key==4) {P1=0xFE;  				   //�������������ˮ��
            for(i=0;i<8;i++)            //ѭ��8��
            { delay(50000);           //��ʱ
               P1=_crol_(P1,1); }	  //P1����1λ	        
            P1=0xff;}					  //��ˮ�ƽ������е�Ϩ��
if(key==0)                //���������
       {int m;
	   P1=0xFE;
	   for(m=0;m<7;m++){
	   delay(50000);
	   P1=P1<<1;}  
		}      
 while(!s1)  ;      //�ȴ������ͷ�
 delay(1200);     //��ʱȥ����  
   }  }}

#include<reg51.h>
#include<intrins.h>
sbit s1=P0^0;
void delay(unsigned int i)
 {
 unsigned int k;
 for(k=0;k<i;k++);
 }
void main(   )		   //������
{  unsigned  char   i;     //�����ַ��ͱ���i
   P1=0xff ;                   //P1��LED��ȫ��
   while(1) 
   {  s1=1;                     //����������ǰ������Ϊ1
      if(s1==0)                //��⵽�������� 
   {  delay(1200);          //��ʱ10ms ȥ����
       if(s1==0)                //�ٴμ�⵽��������    
      {   P1=0xFE;  
           for(i=0;i<8;i++)          //ѭ��8��
            { delay(50000);           // ��ʱ
               P1=_crol_(P1,1); }	 // P1����1λ	        
      } }
else P1=0x00;                //�������������
  } 
}
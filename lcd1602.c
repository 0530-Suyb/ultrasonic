#include "lcd1602.h"
#include "delay.h"
#include<string.h>

void LcdWriteCom(u8 com)	  
{
	LCD1602_E = 0;     
	LCD1602_RS = 0;	   
	LCD1602_RW = 0;	   
	
	LCD = com;     
  delay_nms(1);
	
	LCD1602_E = 1;	          
	delay_nms(5);	  
	LCD1602_E = 0;
}

void LcdWriteData(u8 dat)			
{
	LCD1602_E = 0;	
	LCD1602_RS = 1;	
	LCD1602_RW = 0;	

	LCD = dat; 
	delay_nms(1);

	LCD1602_E = 1;   
	delay_nms(5);   
	LCD1602_E = 0;
}

void LcdInit()						  
{
 	LcdWriteCom(0x38);  //����ʾ
	LcdWriteCom(0x0c);  //����ʾ����ʾ���
	LcdWriteCom(0x06);  //дһ��ָ���1
	LcdWriteCom(0x01);  //����
	LcdWriteCom(0x80);  //��������ָ�����
}

void LcdString(u8 *str, u8 x, u8 y)
{
	LcdWriteCom(0x80 + (x - 1) + 0x40 * (y - 1));
	while(*str != '\0')
		LcdWriteData(*str++);
}




/* ��ʾ�ַ����Զ����� V1.0.0*/
// ����һЩ����
//void LcdString(u8* str)
//{
//	u8 i, len = strlen(str);
//	u8 n = len > 16 ? len : 16;
//	for(i = 0; i < n; i++)
//	  LcdWriteData(str[i]);
//	//����ַ�������16����ʾ�ڶ���
//	if(len > 16)
//	{
//		n = len > 32 ? 32 : len;
//		LcdWriteCom(0xC0);//�ڶ�����ʾ����
//		for(i=16; i < n; i++)
//		{
//			led0=0;
//		  LcdWriteData(str[i]);
//		}
//	}
//}
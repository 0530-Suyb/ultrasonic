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
 	LcdWriteCom(0x38);  //开显示
	LcdWriteCom(0x0c);  //开显示不显示光标
	LcdWriteCom(0x06);  //写一个指针加1
	LcdWriteCom(0x01);  //清屏
	LcdWriteCom(0x80);  //设置数据指针起点
}

void LcdString(u8 *str, u8 x, u8 y)
{
	LcdWriteCom(0x80 + (x - 1) + 0x40 * (y - 1));
	while(*str != '\0')
		LcdWriteData(*str++);
}




/* 显示字符，自动换行 V1.0.0*/
// 存在一些问题
//void LcdString(u8* str)
//{
//	u8 i, len = strlen(str);
//	u8 n = len > 16 ? len : 16;
//	for(i = 0; i < n; i++)
//	  LcdWriteData(str[i]);
//	//如果字符数大于16，显示第二行
//	if(len > 16)
//	{
//		n = len > 32 ? 32 : len;
//		LcdWriteCom(0xC0);//第二行显示命令
//		for(i=16; i < n; i++)
//		{
//			led0=0;
//		  LcdWriteData(str[i]);
//		}
//	}
//}
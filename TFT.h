#ifndef _TFT_H_
#define _TFT_H_

#include<reg52.h>
#include<absacc.h>
#include<intrins.h>
#include<string.h>
#include "DataType.h"



//定义常用颜色
#define RED  		0xf800
#define GREEN		0x07e0
#define BLUE 		0x001f
#define WHITE		0xffff
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   
#define GRAY1   0x8410     
#define GRAY2   0x4208   

sbit bl        =P2^4;
sbit scl       =P2^5;
sbit sda       =P2^3;
sbit rs        =P2^2;
sbit cs        =P2^0;
sbit reset     =P2^1;

u8 code Zk_ASCII8X16[];

void TFT_Init();
void delay(u16 time);
void  SPI_WriteData(u8 Data);
void  Lcd_WriteIndex(u8 Data);
void  Lcd_WriteData(u8 Data);
void  Lcd_WriteData_16(u16 Data);
void Reset(void);
void lcd_initial(void);
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
void LCD_Clear(u16 Color);		
	
void  Contrast_Adjust();

void Display_Desc();
void Output_Pixel(u16 x,u16 y);
void Display_ASCII8X16(u16 x0,u16 y0,u8 *s);	

#endif
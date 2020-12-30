#ifndef _LCD1602_H_
#define _LCD1602_H_

#include<reg52.h>
#include "DataType.h"

#define LCD P0

sbit LCD1602_E = P2^7; //使能
sbit LCD1602_RW = P2^5;//读写
sbit LCD1602_RS = P2^6;//命令数据

void LcdWriteCom(u8 com);
void LcdWriteData(u8 dat);
void LcdInit();	

void LcdString(u8 *str, u8 x, u8 y); //指定位置显示字符串，左上角为（1，1）

#endif
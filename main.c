#include<reg52.h>
//#include "lcd1602.h"
#include "SG90.h"
#include "HC_SR04.h"
#include "Timer.h"
#include "DataType.h"
#include "delay.h"
#include "TFT.h"
#include<stdio.h>
#include<math.h>

sbit Key = P1^0;

void uart_Init()
{
	SCON = 0x50;
	PCON = 0x80;
	TMOD = 0x21;
	TH1 = 0xf4;
	TL1 = 0xf4;
	TR1 = 1;
	EA = 1;
}

void uart_send(char c)
{
	SBUF = c;
	while(!TI);
	TI = 0;
}

void uart_string(char* str)
{
	while(*str)
	{
		uart_send(*str);
		str++;
	}
}

u16 calc(u16 *dist, const int len)
{
	char i, j=0, str[20];
	int min[2];
	int xdata dif[10];  //10 = len(11) - 1
	u16 x1, x2, x;
	
	min[0] = 1000;
	min[1] = 1000;

	//计算差值
	for(i = 0; i < len - 1; i++)
		dif[i] = dist[i + 1] - dist[i];
	//获取极小值点
	for(i = 0; i < len - 2; i++)
	{
		if(dif[i] <= 0 && dif[i + 1] > 0)
		{
			if(j < 2)
			    min[j++] = i+1;
			else
			{
			    if(dist[i+1] < dist[min[0]] && dist[min[0]] > dist[min[1]]) min[0] = i+1;
	    	    else if(dist[i+1] < dist[min[1]]) min[1] = i+1;
			}
		}
	}
	if(dif[0] > 0)
	{
		if(dist[0] < dist[min[0]] && dist[min[0]] > dist[min[1]]) min[0] = 0;
		if(dist[0] < dist[min[1]]) min[1] = 0;
	}
	if(dif[len-2] < 0)  
	{
		if(dist[len-1] < dist[min[0]] && dist[min[0]] > dist[min[1]]) min[0] = len-1;
		if(dist[len-1] < dist[min[1]]) min[1] = len-1;
	}
	
	//计算两物体间距
	x1 = dist[min[0]];
	x2 = dist[min[1]];
	
//	sprintf(str, "%d\r\n", min[0]);
//	uart_string(str);
//	sprintf(str, "%d\r\n", min[1]);
//	uart_string(str);
//	sprintf(str, "x1 = %d mm\r\n", x1);
//	uart_string(str);
//	sprintf(str, "x2 = %d mm\r\n", x2);
//	uart_string(str);
	
	
	x = sqrt(x1*x1+x2*x2-2*x1*x2*cos(3.141592 * 9*(min[0]-min[1]) / 180));
//	sprintf(str, "dist = %d mm\r\n", x);
//	uart_string(str);
	
	return x;
}

void main()
{
	u16 xdata dist[22], distance;
	char i = 0, angle = -45;
	char xdata str[20];
	Timer_Init();
	
	TFT_Init();
	
	Display_ASCII8X16(10,10,"distance:");
	
	//距离测试
//	while(1)
//	{
//		dist[0] = measure();
//		sprintf(str, "%d mm\r\n", dist[0]);
//		uart_Init();
//		uart_string(str);
//	}

		for(i = 0; i < 11; i++)
		{
			SGTurn(angle);
			angle += 9;
			dist[2*i] = measure();
			dist[2*i + 1] = measure();
		}
		
		for(i = 0; i < 11; i++)
		{
			dist[i] =  (dist[2*i] + dist[2*i+1])/2;
			if(dist[i] >= 1000)
				dist[i] = 1000;
			if(dist[i] <= 200)
				dist[i] = 200;
		}
		
		
//		uart_Init();
//		for(i = 0; i < 11; i++)
//		{
//			sprintf(str, "%d ", dist[i]);
//			uart_string(str);
//		}
//		uart_string("\r\n");
		distance = calc(dist, 11);
		
		if(distance > 1200) distance = 1200;
		if(distance < 100) distance = 100;
		
//		sprintf(str, "dist:%d mm  ", distance);
//		uart_string(str);
//		
//		uart_string("\r\n");
		
		Display_ASCII8X16(10,42, str);
		while(1);
}
	

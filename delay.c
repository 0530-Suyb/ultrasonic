#include "delay.h"

void delay_nms(u16 n)  //ms级延时
{
	u16 i;
	while(n--)
	{
		for(i = 0; i < 164; i++);
	}
}

void delay_10us(u16 i)  //us级延时，延时13.5*i us
{
	while(i--);	
}

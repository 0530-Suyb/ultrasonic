#include<reg52.h>

extern int cnt200;
//默认工作方式1，定时1ms，定时器需手动取消注释开启工作

void Timer_Init()
{
	TMOD = 0x11;
	TH0 = 0xff;
	TL0 = 0x9c;
	//ET1 = 1;
	ET0 = 1;
	EA = 1;
	//TR1 = 1;
	//TR0 = 1;
}

void Timer0_Task() interrupt 1
{
	TH0 = 0xff;
	TL0 = 0x9c;
	cnt200++;
}


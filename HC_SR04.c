#include "HC_SR04.h"
#include "delay.h"

void SR04_Init()
{
	Echo = 0;
	Trig = 0;
}

void ClrTimer()
{
	TMOD = 0x11;
	TR1 = 0;
	TH1 = 0;
	TL1 = 0;
}

void sendStart()
{
	Trig = 1;
	delay_10us(2);
	Trig = 0;
}

u16 measure()
{
	u16 distance;
	u32 time;
	
	SR04_Init();
	ClrTimer();
	sendStart();
	while(!Echo);
	TR1 = 1;
	while(Echo); //接收到回传信号，Echo被置低电平
	TR1 = 0;
	
	time = TH1 * 256 + TL1;
	distance = (int)(0.17 * time);
	return distance;
}
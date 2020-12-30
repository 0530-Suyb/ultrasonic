#include "SG90.h"

int cnt200 = 0; //plus 1 is pass 100us, every period is 20ms

void SGTurn(char turn) //turn=0,不动；turn=-90，逆时针90度；turn=90顺时针90度
{
	u8 high = 15 + turn / 9, PWMFreq = 15;
	TR0 = 1;
	while(PWMFreq)
	{
		if(cnt200 == high)
			SG = 0;
		if(cnt200 == 200)
		{
		  SG = 1;
			cnt200 = 0;
			PWMFreq--;
		}
	}
	TR0 = 0;
}
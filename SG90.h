#ifndef _SG90_H_
#define _SG90_H_

#include<reg52.h>
#include "DataType.h"

sbit SG = P1^7;

void SGTurn(char turn); //turn=0,������turn=-90����ʱ��90�ȣ�turn=90˳ʱ��90��

#endif
#ifndef _SG90_H_
#define _SG90_H_

#include<reg52.h>
#include "DataType.h"

sbit SG = P1^7;

void SGTurn(char turn); //turn=0,不动；turn=-90，逆时针90度；turn=90顺时针90度

#endif
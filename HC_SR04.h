#ifndef _HC_SR04_H_
#define _HC_SR04_H_

#include<reg52.h>
#include<intrins.h>
#include "DataType.h"

sbit Trig = P1^5;
sbit Echo = P1^6;

u16 measure();

#endif
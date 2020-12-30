#ifndef _DATATYPE_H_
#define _DATATYPE_H_

#include<reg52.h>

#define LED P2

typedef unsigned long u32;
typedef unsigned int u16;
typedef unsigned char u8;

sbit led0 = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
sbit led4 = P2^4;
sbit led5 = P2^5;
sbit led6 = P2^6;
sbit led7 = P2^7;

#endif
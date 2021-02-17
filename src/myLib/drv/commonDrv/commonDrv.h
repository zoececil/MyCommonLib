#ifndef __COMMONDRV_H
#define __COMMONDRV_H
#include "all_config.h"
#include "../nativeInterface.h"
#include "stdio.h"


/***********延时基本(全)***************/
void myDelayUS(u32 nus);
void myDelayMS(u16 nms);
void myDelayInit(u8 SYSCLK);
/***********重定向(待完善)***************/
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

#endif
#endif
/**************其他(待完善)***************/

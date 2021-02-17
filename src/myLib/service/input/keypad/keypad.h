#include "all_config.h"
#ifdef service_input_keypad
#ifndef __KEYPAD_H
#define __KEYPAD_H
#include "keypad_drv.h"
#include "keypadsrc.h"


extern unsigned char i,j,k,x,y,sum;

typedef void (*callback)(unsigned char x,unsigned char y);
callback cfunction;

typedef enum
{
    Pull_Up,
    Pull_Down,
}keypad_select_mode;



void keypad_init(keypad_select_mode mode,unsigned char len_size,unsigned char wid_size);
unsigned char keypad_scan(void);
void repeat(callback function,unsigned char x,unsigned char y);
void sum_event(unsigned char sum);


#endif
#endif

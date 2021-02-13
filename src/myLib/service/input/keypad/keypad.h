/*
 * keypad.h
 *
 *  Created on: Feb 5, 2021
 *      Author: zoe
 */

#ifndef MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_
#define MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_

#include "myLib/drv/commonDrv/commonDrv.h"
#include "keypad_drv.h"
#include "keypadsrc.h"
#ifdef service_input_keypad

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

#endif /* MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_ */

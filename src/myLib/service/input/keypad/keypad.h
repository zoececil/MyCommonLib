/*
 * keypad.h
 *
 *  Created on: Feb 5, 2021
 *      Author: 16708
 */

#ifndef MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_
#define MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_
#include "myLib/drv/commonDrv/commonDrv.h"
#ifdef service_input_keypad
void initKeypad(void (*callback)(unsigned char x,unsigned char y));
void scanKeypad();

#endif

#endif /* MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_ */

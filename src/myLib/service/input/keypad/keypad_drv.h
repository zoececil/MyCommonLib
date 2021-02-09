/*
 * keypad_drv.h
 *
 *  Created on: Feb 5, 2021
 *      Author: 16708
 */

#ifndef MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_DRV_H_
#define MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_DRV_H_
#include "myLib/drv/commonDrv/commonDrv.h"
#ifdef service_input_keypad

typedef enum
{
  PIN_RESET = 0u,
  PIN_SET
} PinState;

PinState flag;
void setOut(char target, PinState state);
void writeRow(char index,PinState state);
PinState readCol(char index);

#endif
#endif /* MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_DRV_H_ */

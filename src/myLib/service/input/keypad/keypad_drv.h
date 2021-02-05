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

void writeRow(char index,char state);
void writeCol(char index,char state);

#endif
#endif /* MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_DRV_H_ */

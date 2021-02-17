#include "all_config.h"
#ifdef service_input_keypad

#ifndef __KEYPADDRV_H
#define __KEYPADDRV_H
#include "myLib/drv/commonDrv/commonDrv.h"

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
#endif 

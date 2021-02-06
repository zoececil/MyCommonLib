/*
 * keypad.h
 *
 *  Created on: Feb 5, 2021
 *      Author: 16708zoe
 */

#ifndef MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_
#define MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_
#include "myLib/drv/commonDrv/commonDrv.h"
#include "keypad_drv.h"
#ifdef service_input_keypad
extern unsigned char i,j,k,x,y,sum;
#define s_stateMode  PIN_SET    //����ʱ����ΪPIN_SET������ʱΪPIN_RESET
#define f_stateMode  PIN_RESET  //����ʱ����ΪPIN_RESET������ʱΪPIN_SET

typedef void (*callback)(unsigned char x,unsigned char y);

void repeat(callback function,unsigned char x,unsigned char y);
void sum_event(unsigned char sum);
void function1(unsigned char x,unsigned char y);
void function2(unsigned char x,unsigned char y);
void function3(unsigned char x,unsigned char y);
//funCtionxΪ����ʵ�ֶ�Ӧ�������ܵ�Ӧ�ò�ص�����,�û���������ģ��˿��ݲ�������

unsigned char scanKeypad(void);

#endif

#endif /* MYCOMMONLIB_SRC_MYLIB_SERVICE_INPUT_KEYPAD_KEYPAD_H_ */

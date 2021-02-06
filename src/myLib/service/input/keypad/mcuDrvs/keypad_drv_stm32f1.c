/*
 * keypad_stm32f1_hal.c
 *
 *  Created on: Feb 5, 2021
 *      Author: 16708
 */
#include "../keypad_drv.h"

#ifdef service_input_keypad
#ifdef mcu_stm32f1

#define COL4_Pin GPIO_PIN_0
#define COL4_GPIO_Port GPIOD
#define COL3_Pin GPIO_PIN_1
#define COL3_GPIO_Port GPIOD
#define COL2_Pin GPIO_PIN_2
#define COL2_GPIO_Port GPIOD
#define COL1_Pin GPIO_PIN_3
#define COL1_GPIO_Port GPIOD
#define ROW4_Pin GPIO_PIN_4
#define ROW4_GPIO_Port GPIOD
#define ROW3_Pin GPIO_PIN_5
#define ROW3_GPIO_Port GPIOD
#define ROW2_Pin GPIO_PIN_6
#define ROW2_GPIO_Port GPIOD
#define ROW1_Pin GPIO_PIN_7
#define ROW1_GPIO_Port GPIOD



void setOut(char target, PinState state)
{
	writeRow(target, state);
}
void writeRow(char index, PinState state)
{
	switch (index)
	{
	case 0:
		/****/
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, state);
		break;

	case 1:
		/****/
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, state);
		break;

	case 2:
		/****/
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, state);
		break;

	case 3:
		/****/
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, state);
		break;

	}
}
PinState readCol(char index)
{
	switch (index)
	{
	case 0:
		/****/
		HAL_GPIO_ReadPin(COL1_GPIO_Port, COL1_Pin);
		break;

	case 1:
		/****/
		HAL_GPIO_ReadPin(COL2_GPIO_Port, COL2_Pin);
		break;

	case 2:
		/****/
		HAL_GPIO_ReadPin(COL3_GPIO_Port, COL3_Pin);
		break;

	case 3:
		/****/
		HAL_GPIO_ReadPin(COL4_GPIO_Port, COL4_Pin);
		break;

	}
}

#endif
#endif


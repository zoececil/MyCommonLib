#include "../tftlcd_drv.h"

#ifdef service_display_tftlcd
#ifdef mcu_stm32f1

#define LCD_CTRL   	  	GPIOB
#define LCD_LED        	GPIO_PIN_9
#define LCD_RS         	GPIO_PIN_10
#define LCD_CS        	GPIO_PIN_11
#define LCD_RST     	GPIO_PIN_12
#define LCD_SCL        	GPIO_PIN_13
#define LCD_SDA        	GPIO_PIN_15

void LCD_GPIO_Init(void)
{
}
void LCD_setCS(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_CS,GPIO_PIN_SET);
	LCD_CTRL->BSRR=LCD_CS;
}
void LCD_setRS(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_RS,GPIO_PIN_SET);
	LCD_CTRL->BSRR=LCD_RS;
}
void LCD_setSDA(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_SDA,GPIO_PIN_SET);
	LCD_CTRL->BSRR=LCD_SDA;
}
void LCD_setSCL(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_SCL,GPIO_PIN_SET);
	LCD_CTRL->BSRR=LCD_SCL;
}
void LCD_setRST(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_RST,GPIO_PIN_SET);
	LCD_CTRL->BSRR=LCD_RST;
}
void LCD_setLED(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_LED,GPIO_PIN_SET);
	LCD_CTRL->BSRR=LCD_LED;
}
void LCD_resetCS(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_CS,GPIO_PIN_RESET);
	LCD_CTRL->BRR=LCD_CS;
}
void LCD_resetRS(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_RS,GPIO_PIN_RESET);
	LCD_CTRL->BRR=LCD_RS;
}
void LCD_resetSDA(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_SDA,GPIO_PIN_RESET);
	LCD_CTRL->BRR=LCD_SDA;
}
void LCD_resetSCL(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_SCL,GPIO_PIN_RESET);
	LCD_CTRL->BRR=LCD_SCL;
}
void LCD_resetRST(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_RST,GPIO_PIN_RESET);
	LCD_CTRL->BRR=LCD_RST;
}
void LCD_resetLED(void)
{
//	HAL_GPIO_WritePin(LCD_CTRL, LCD_LED,GPIO_PIN_RESET);
	LCD_CTRL->BRR=LCD_LED;
}
#endif
#endif

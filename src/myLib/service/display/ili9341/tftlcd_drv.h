#include "all_config.h"
#ifdef service_display_tftlcd

#ifndef __TFTLCDDRV_H
#define __TFTLCDDRV_H
#include "myLib/drv/commonDrv/commonDrv.h"

#define Select_Horizontal 0
#define X_SIZE 240
#define Y_SIZE 320

#if Select_Horizontal//如果定义了横屏
#define X_MAX_PIXEL	        Y_SIZE
#define Y_MAX_PIXEL	        X_SIZE
#else
#define X_MAX_PIXEL	        X_SIZE
#define Y_MAX_PIXEL	        Y_SIZE
#endif

void LCD_GPIO_Init(void);

void LCD_setCS(uint8_t i);
void LCD_setRS(uint8_t i);
void LCD_setSDA(uint8_t i);
void LCD_setSCL(uint8_t i);
void LCD_setRST(uint8_t i);
void LCD_setLED(uint8_t i);

#define	LCD_CS_SET  LCD_setCS(1)
#define	LCD_RS_SET  LCD_setRS(1)
#define	LCD_SDA_SET LCD_setSDA(1)
#define	LCD_SCL_SET LCD_setSCL(1)
#define	LCD_RST_SET LCD_setRST(1)
#define	LCD_LED_SET LCD_setLED(1)

#define	LCD_CS_CLR  LCD_setCS(0)
#define	LCD_RS_CLR  LCD_setRS(0)
#define	LCD_SDA_CLR LCD_setSDA(0)
#define	LCD_SCL_CLR LCD_setSCL(0)
#define	LCD_RST_CLR LCD_setRST(0)
#define	LCD_LED_CLR LCD_setLED(0)

#endif

#endif

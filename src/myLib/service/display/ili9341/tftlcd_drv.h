#include "all_config.h"
#ifdef service_display_tftlcd

#ifndef __TFTLCDDRV_H
#define __TFTLCDDRV_H
#include "myLib/drv/commonDrv/commonDrv.h"

#define Select_Horizontal 0
#define X_SIZE 240
#define Y_SIZE 320

#if Select_Horizontal
#define X_MAX_PIXEL	        Y_SIZE
#define Y_MAX_PIXEL	        X_SIZE
#else
#define X_MAX_PIXEL	        X_SIZE
#define Y_MAX_PIXEL	        Y_SIZE
#endif

#define	LCD_CS_SET  LCD_setCS()
#define	LCD_RS_SET  LCD_setRS()
#define	LCD_SDA_SET LCD_setSDA()
#define	LCD_SCL_SET LCD_setSCL()
#define	LCD_RST_SET LCD_setRST()
#define	LCD_LED_SET LCD_setLED()

#define	LCD_CS_CLR  LCD_resetCS()
#define	LCD_RS_CLR  LCD_resetRS()
#define	LCD_SDA_CLR LCD_resetSDA()
#define	LCD_SCL_CLR LCD_resetSCL()
#define	LCD_RST_CLR LCD_resetRST()
#define	LCD_LED_CLR LCD_resetLED()

void LCD_GPIO_Init(void);
void LCD_setCS(void);
void LCD_setRS(void);
void LCD_setSDA(void);
void LCD_setSCL(void);
void LCD_setRST(void);
void LCD_setLED(void);

void LCD_resetCS(void);
void LCD_resetRS(void);
void LCD_resetSDA(void);
void LCD_resetSCL(void);
void LCD_resetRST(void);
void LCD_resetLED(void);

#endif

#endif

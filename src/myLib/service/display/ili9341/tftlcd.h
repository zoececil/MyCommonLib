#include "all_config.h"

#ifdef service_display_tftlcd
#ifndef __TFTLCD_H
#define __TFTLCD_H
#include "tftlcd_drv.h"
#include "myLib/drv/spi/hardware_spi.h"


#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40
#define BRRED 			 0XFC07
#define GRAY  			 0X8430


void LCD_WriteIndex(uint8_t command);
void LCD_WriteData8Bit(uint8_t data);
void LCD_WriteData16Bit(uint16_t data);

void LCD_Reset(void);
void LCD_DisplayON(void);
void LCD_DisplayOFF(void);
void LCD_Init(void);
void LCD_SetXY(uint16_t Xpos, uint16_t Ypos);
void LCD_SetRegion(uint16_t x1, uint16_t y1,uint16_t x2,uint16_t y2);
void LCD_Clear(uint16_t color);

void LCD_Fill(uint16_t x1, uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t data);
void LCD_DrawLine(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t color);
void LCD_DrawCircle(uint16_t x,uint16_t y,uint16_t r,uint16_t fc);

void Color_Test(void);
void Test_Demo(void);

#endif
#endif

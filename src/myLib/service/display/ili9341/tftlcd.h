#include "all_config.h"

#ifdef service_display_tftlcd
#ifndef __TFTLCD_H
#define __TFTLCD_H
#include "tftlcd_drv.h"
#include "myLib/drv/spi/hardware_spi.h"


#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D
#define GRAY1   0x8410
#define GRAY2   0x4208


void LCD_WriteIndex(uint8_t command);
void LCD_WriteData8Bit(uint8_t data);
void LCD_WriteData16Bit(uint16_t data);

void LCD_Reset(void);
void LCD_Init(void);
void LCD_SetXY(uint16_t Xpos, uint16_t Ypos);
void LCD_SetRegion(uint16_t x1, uint16_t y1,uint16_t x2,uint16_t y2);
void LCD_Clear(uint16_t Color);

void Color_Test(void);

void Test_Demo(void);
#endif
#endif

#include "all_config.h"

#ifdef service_display_tftlcd
#include "tftlcd.h"

void LCD_Init(void)
{
	LCD_Reset();

	LCD_WriteIndex(0X11);   //sleep out
	LCD_WriteData8Bit(0x00);

	LCD_WriteIndex(0XCF);   //power control B
	LCD_WriteData8Bit(0x00);
	LCD_WriteData8Bit(0xC1);
	LCD_WriteData8Bit(0x30);

	LCD_WriteIndex(0XED);
	LCD_WriteData8Bit(0x64);
	LCD_WriteData8Bit(0x03);
	LCD_WriteData8Bit(0x12);
	LCD_WriteData8Bit(0x81);

	LCD_WriteIndex(0XE8);
	LCD_WriteData8Bit(0x85);
	LCD_WriteData8Bit(0x11);
	LCD_WriteData8Bit(0x78);

	LCD_WriteIndex(0XF6);
	LCD_WriteData8Bit(0x01);
	LCD_WriteData8Bit(0x30);
	LCD_WriteData8Bit(0x00);

	LCD_WriteIndex(0XCB);
	LCD_WriteData8Bit(0x39);
	LCD_WriteData8Bit(0x2C);
	LCD_WriteData8Bit(0x00);
	LCD_WriteData8Bit(0x34);
	LCD_WriteData8Bit(0x05);

	LCD_WriteIndex(0XF7);
	LCD_WriteData8Bit(0x20);

	LCD_WriteIndex(0XEA);
	LCD_WriteData8Bit(0x00);
	LCD_WriteData8Bit(0x00);

	LCD_WriteIndex(0XC0);
	LCD_WriteData8Bit(0x20);

	LCD_WriteIndex(0XC1);
	LCD_WriteData8Bit(0x11);

	LCD_WriteIndex(0XC5);
	LCD_WriteData8Bit(0x31);
	LCD_WriteData8Bit(0x3C);

	LCD_WriteIndex(0XC7);
	LCD_WriteData8Bit(0xA9);

	LCD_WriteIndex(0X3A);
	LCD_WriteData8Bit(0X55);

	LCD_WriteIndex(0x36);
	#if Select_Horizontal
		LCD_WriteData8Bit(0xE8);//横屏参数
	#else
		LCD_WriteData8Bit(0x48);//竖屏参数
	#endif

	LCD_WriteIndex(0xB1);  /* Frame Rate Control (In Normal Mode/Full Colors) (B1h) */
	LCD_WriteData8Bit(0X00);
	LCD_WriteData8Bit(0X18);

	LCD_WriteIndex(0xB4);
	LCD_WriteData8Bit(0X00);
	LCD_WriteData8Bit(0X00);

	LCD_WriteIndex(0xF2);  /* Enable 3G (F2h) */
	LCD_WriteData8Bit(0X00);

	LCD_WriteIndex(0x26);  /* Gamma Set (26h) */
	LCD_WriteData8Bit(0X01);

	LCD_WriteIndex(0xE0);  /* Positive Gamma Correction */
	LCD_WriteData8Bit(0X0F);
	LCD_WriteData8Bit(0X17);
	LCD_WriteData8Bit(0X14);
	LCD_WriteData8Bit(0X09);
	LCD_WriteData8Bit(0X0C);
	LCD_WriteData8Bit(0X06);
	LCD_WriteData8Bit(0X43);
	LCD_WriteData8Bit(0X75);
	LCD_WriteData8Bit(0X36);
	LCD_WriteData8Bit(0X08);
	LCD_WriteData8Bit(0X13);
	LCD_WriteData8Bit(0X05);
	LCD_WriteData8Bit(0X10);
	LCD_WriteData8Bit(0X0B);
	LCD_WriteData8Bit(0X08);


	LCD_WriteIndex(0xE1);  /* Negative Gamma Correction (E1h) */
	LCD_WriteData8Bit(0X00);
	LCD_WriteData8Bit(0X1F);
	LCD_WriteData8Bit(0X23);
	LCD_WriteData8Bit(0X03);
	LCD_WriteData8Bit(0X0E);
	LCD_WriteData8Bit(0X04);
	LCD_WriteData8Bit(0X39);
	LCD_WriteData8Bit(0X25);
	LCD_WriteData8Bit(0X4D);
	LCD_WriteData8Bit(0X06);
	LCD_WriteData8Bit(0X0D);
	LCD_WriteData8Bit(0X0B);
	LCD_WriteData8Bit(0X33);
	LCD_WriteData8Bit(0X37);
	LCD_WriteData8Bit(0X0F);

	LCD_WriteIndex(0x29);  	/* Display ON (29h) */

}
void LCD_WriteIndex(uint8_t command)
{
	LCD_CS_CLR;
	LCD_RS_CLR;               //D/CX为0，写指令
	spiTransmit(command,1);  //硬件SPI
	LCD_CS_SET;
}
void LCD_WriteData8Bit(uint8_t data)
{
	LCD_CS_CLR;
	LCD_RS_SET;             //D/CX为1，写数据或命令参数
	spiTransmit(data,1);   //硬件SPI
	LCD_CS_SET;
}
void LCD_WriteData16Bit(uint16_t data)
{
	LCD_WriteData8Bit(data>>8);
	LCD_WriteData8Bit(data);
}
void LCD_Reset(void)
{
	LCD_RST_CLR;
	myDelayMS(100);
	LCD_RST_SET;
	myDelayMS(50);
}
void LCD_Clear(uint16_t Color)
{
   unsigned int i;
   LCD_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
   LCD_CS_CLR;
   LCD_RS_SET;
   for(i=0;i<X_MAX_PIXEL*Y_MAX_PIXEL;i++)
   {
	   LCD_WriteData16Bit(Color);

   }
		LCD_CS_SET;
}
void LCD_SetXY(uint16_t Xpos, uint16_t Ypos)
{
	LCD_WriteIndex(0x2A);
	LCD_WriteData16Bit(Xpos);
	LCD_WriteIndex(0x2B);
	LCD_WriteData16Bit(Ypos);
	LCD_WriteIndex(0x2C);
}

void LCD_SetRegion(uint16_t x1, uint16_t y1,uint16_t x2,uint16_t y2)
{
	LCD_WriteIndex(0x2A);
	LCD_WriteData16Bit(x1);
	LCD_WriteData16Bit(x2);
	LCD_WriteIndex(0x2B);
	LCD_WriteData16Bit(y1);
	LCD_WriteData16Bit(y2);
	LCD_WriteIndex(0x2C);
}

#endif

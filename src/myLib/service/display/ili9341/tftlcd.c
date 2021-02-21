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
		LCD_WriteData8Bit(0xE8);
	#else
		LCD_WriteData8Bit(0x48);
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
//void  LCD_Write_spi(uint8_t Data)//软件模拟spi写一个字节
//{
//	unsigned char i=0;
//	for(i=8;i>0;i--)
//	{
//		if(Data&0x80)
//	  LCD_SDA_SET; //输出数据
//      else LCD_SDA_CLR;
//
//      LCD_SCL_CLR;
//      LCD_SCL_SET;
//      Data<<=1;
//	}
//}
void LCD_Write_spi(uint8_t data)//硬件spi
{
	spiTransmit(&data,1);
}
void LCD_WriteIndex(uint8_t command)
{
	LCD_CS_CLR;
	LCD_DC_CLR;
	LCD_Write_spi(command);
	LCD_CS_SET;
}
void LCD_WriteData8Bit(uint8_t data)
{
	LCD_CS_CLR;
	LCD_DC_SET;
	LCD_Write_spi(data);
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
void LCD_Clear(uint16_t color)
{
   unsigned int i;
   LCD_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
   LCD_CS_CLR;
   LCD_DC_SET;
   for(i=0;i<X_MAX_PIXEL*Y_MAX_PIXEL;i++)
   {
//	   LCD_WriteData16Bit(Color);
	   LCD_Write_spi(color>>8);
	   LCD_Write_spi(color);
   }
		LCD_CS_SET;
}
void LCD_Fill(uint16_t x1, uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	   unsigned int i;
	   LCD_SetRegion(x1,y1,x2-1,y2-1);
	   LCD_CS_CLR;
	   LCD_DC_SET;
	   for(i=0;i<x2*y2;i++)
	   {
		   LCD_WriteData16Bit(color);
//		   LCD_Write_spi(color>>8);
//		   LCD_Write_spi(color);
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
void LCD_DisplayON(void)
{
//	LCD_WriteIndex(0x29);
	LCD_LED_SET;
}
void LCD_DisplayOFF(void)
{
//	LCD_WriteIndex(0x28);
	LCD_LED_CLR;
}
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t data)
{
	LCD_SetXY(x,y);
	LCD_WriteData16Bit(data);
}
void LCD_DrawLine(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t color)
{
	int dx,dy,dx2,dy2,x_inc,y_inc,error,index;

	LCD_SetXY(x0,y0);
	dx = x1-x0;
	dy = y1-y0;

	if (dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx = -dx;
	}
	if (dy>=0)
	{
		y_inc = 1;
	}
	else
	{
		y_inc = -1;
		dy = -dy;
	}

	dx2 = dx << 1;
	dy2 = dy << 1;

	if (dx > dy)
	{
		error = dy2 - dx;
		for (index=0;index<=dx;index++)
		{
			LCD_DrawPoint(x0, y0, color);
			if (error >= 0)
			{
				error-=dx2;
				y0+=y_inc;
			}
			error+=dy2;
			x0+=x_inc;
		}
	}
	else
	{
		error = dx2 - dy;
		for (index=0;index <= dy;index++)
		{
			LCD_DrawPoint(x0, y0, color);
			if (error >= 0)
			{
				error-=dy2;
				x0+=x_inc;
			}
			error+=dx2;
			y0+=y_inc;
		}
	}
}
void LCD_DrawCircle(uint16_t x,uint16_t y,uint16_t r,uint16_t fc)
{
	unsigned short a,b;
	int c;
	a=0,b=r,c=3-2*r;
	while(a<b)
	{
		LCD_DrawPoint(x+a, y+b, fc);
		LCD_DrawPoint(x-a, y+b, fc);
		LCD_DrawPoint(x+a, y-b, fc);
		LCD_DrawPoint(x-a, y-b, fc);
		LCD_DrawPoint(x+b, y+a, fc);
		LCD_DrawPoint(x-b, y+a, fc);
		LCD_DrawPoint(x+b, y-a, fc);
		LCD_DrawPoint(x-b, y-a, fc);

		if(c<0)
		{
			c=c+4*a+6;
		}
		else
		{
			c=c+4*(a-b)+10;
			b-=1;
		}
		a+=1;
	}
	if (a==b)
	{
		LCD_DrawPoint(x+a, y+b, fc);
		LCD_DrawPoint(x-a, y+b, fc);
		LCD_DrawPoint(x+a, y-b, fc);
		LCD_DrawPoint(x-a, y-b, fc);
		LCD_DrawPoint(x+b, y+a, fc);
		LCD_DrawPoint(x-b, y+a, fc);
		LCD_DrawPoint(x+b, y-a, fc);
		LCD_DrawPoint(x-b, y-a, fc);
	}
}
void Color_Test(void)
{
	uint8_t i=1;
	LCD_Clear(GRAY);
	myDelayMS(500);

	while(i--)
	{
		LCD_Clear(WHITE); myDelayMS(500);
		LCD_Clear(BLACK); myDelayMS(500);
		LCD_Clear(RED);	  myDelayMS(500);
		LCD_Clear(GREEN); myDelayMS(500);
		LCD_Clear(BLUE);  myDelayMS(500);
	}
}

void Test_Demo(void)
{
	LCD_Init();
	LCD_DisplayON();
	LCD_Clear(WHITE);
	LCD_DrawLine(200, 250, 50, 200, GBLUE);
	LCD_DrawCircle(100, 100, 10, RED);
	LCD_Fill(100, 100, 200, 200, GREEN);
	LCD_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
	LCD_DrawLine(50, 50, 200, 250, RED);
	LCD_DrawLine(200, 50, 50, 250, BLUE);
	LCD_DrawLine(200, 250, 50, 250, BLUE);


	while(1){
//	Color_Test();

//	myDelayMS(1000);
	}
}

#endif

#include "../tftlcd_drv.h"

#ifdef service_display_tftlcd
#ifdef mcu_stm32f1

#define LCD_CTRL   	  	GPIOB		//定义TFT数据端口
#define LCD_LED        	GPIO_PIN_9  //MCU_PB9--->>TFT --BL
#define LCD_RS         	GPIO_PIN_10	//PB11--->>TFT --RS/DC
#define LCD_CS        	GPIO_PIN_11 //MCU_PB11--->>TFT --CS/CE
#define LCD_RST     	GPIO_PIN_12	//PB10--->>TFT --RST
#define LCD_SCL        	GPIO_PIN_13	//PB13--->>TFT --SCL/SCK
#define LCD_SDA        	GPIO_PIN_15	//PB15 MOSI--->>TFT --SDA/DIN

void LCD_GPIO_Init(void)
{

}

void LCD_setCS(uint8_t i)
{
	if(i == 0) {
		LCD_CTRL->BRR=LCD_CS;
	}
	if(i == 1){
		LCD_CTRL->BSRR=LCD_CS;
	}
}
void LCD_setRS(uint8_t i)
{
	if(i == 0) {
		LCD_CTRL->BRR=LCD_RS;
	}
	if(i == 1){
		LCD_CTRL->BSRR=LCD_RS;
	}
}
void LCD_setSDA(uint8_t i)
{
	if(i == 0) {
		LCD_CTRL->BRR=LCD_SDA;
	}
	if(i == 1){
		LCD_CTRL->BSRR=LCD_SDA;
	}
}
void LCD_setSCL(uint8_t i)
{
	if(i == 0) {
		LCD_CTRL->BRR=LCD_SCL;
	}
	if(i == 1){
		LCD_CTRL->BSRR=LCD_SCL;
	}
}
void LCD_setRST(uint8_t i)
{
	if(i == 0) {
		LCD_CTRL->BRR=LCD_RST;
	}
	if(i == 1){
		LCD_CTRL->BSRR=LCD_RST;
	}
}
void LCD_setLED(uint8_t i)
{
	if(i == 0) {
		LCD_CTRL->BRR=LCD_LED;
	}
	if(i == 1){
		LCD_CTRL->BSRR=LCD_LED;
	}
}

#endif
#endif

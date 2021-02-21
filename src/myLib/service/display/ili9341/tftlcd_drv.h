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

#ifdef mcu_stm32f1
#define LCD_CTRL   	  	GPIOB
#define LCD_LED        	GPIO_PIN_9
#define LCD_DC         	GPIO_PIN_10
#define LCD_CS        	GPIO_PIN_11
#define LCD_RST     	GPIO_PIN_12
#define LCD_SCL        	GPIO_PIN_13
#define LCD_SDA        	GPIO_PIN_15

#define	LCD_CS_SET  	LCD_CTRL->BSRR=LCD_CS
#define	LCD_DC_SET  	LCD_CTRL->BSRR=LCD_DC
#define	LCD_SDA_SET  	LCD_CTRL->BSRR=LCD_SDA
#define	LCD_SCL_SET  	LCD_CTRL->BSRR=LCD_SCL
#define	LCD_RST_SET  	LCD_CTRL->BSRR=LCD_RST
#define	LCD_LED_SET  	LCD_CTRL->BSRR=LCD_LED

#define	LCD_CS_CLR  	LCD_CTRL->BRR=LCD_CS
#define	LCD_DC_CLR  	LCD_CTRL->BRR=LCD_DC
#define	LCD_SDA_CLR  	LCD_CTRL->BRR=LCD_SDA
#define	LCD_SCL_CLR  	LCD_CTRL->BRR=LCD_SCL
#define	LCD_RST_CLR  	LCD_CTRL->BRR=LCD_RST
#define	LCD_LED_CLR  	LCD_CTRL->BRR=LCD_LED

#endif


#endif

#endif

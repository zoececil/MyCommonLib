/*
 * spi_stm32f1_hal.c
 *
 *  Created on: 2021Äê2ÔÂ3ÈÕ
 *      Author: 16708
 */
#include "../hardware_spi.h"
#ifdef mcu_stm32f1

extern SPI_HandleTypeDef hspi2;

void spiTransmit(unsigned char data, unsigned int size)
{
	HAL_SPI_Transmit(&hspi2,&data,size,100);
}
void spiReceive(unsigned char *pdata, unsigned int size)
{
	HAL_SPI_Receive(&hspi2,pdata,size,100);
}
void spiTR(unsigned char *pTdata,unsigned char *pRdata,unsigned int size)
{
	HAL_SPI_TransmitReceive(&hspi2,pTdata,pRdata,size,100);
}
void spiTransmit_IT(unsigned char *pdata, unsigned int outsize)
{
	HAL_SPI_Transmit_IT(&hspi2,pdata,outsize);
}
void spiReceive_IT(unsigned char *pdata, unsigned int outsize)
{
	HAL_SPI_Receive_IT(&hspi2,pdata,outsize);
}
void spiTR_IT(unsigned char *pTdata,unsigned char *pRdata,unsigned int outsize)
{
	HAL_SPI_TransmitReceive_IT(&hspi2,pTdata,pRdata,outsize);
}

#endif

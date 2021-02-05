/*
 * hardware_spi.h
 *
 *  Created on: 2021Äê2ÔÂ3ÈÕ
 *      Author: 16708
 */

#ifndef MYCOMMONLIB_SRC_MYLIB_DRV_SPI_HARDWARE_SPI_H_
#define MYCOMMONLIB_SRC_MYLIB_DRV_SPI_HARDWARE_SPI_H_
#include "all_config.h"
#include "../nativeInterface.h"
#include "myLib/drv/commonDrv/commonDrv.h"

void spiTransmit(unsigned char *pdata, unsigned int size);
void spiReceive(unsigned char *pdata, unsigned int size);
void spiTR(unsigned char *pTdata,unsigned char *pRdata,unsigned int size);

void spiTransmit_IT(unsigned char *pdata, unsigned int outsize);
void spiReceive_IT(unsigned char *pdata, unsigned int outsize);
void spiTR_IT(unsigned char *pTdata,unsigned char *pRdata,unsigned int outsize);

#endif /* MYCOMMONLIB_SRC_MYLIB_DRV_SPI_HARDWARE_SPI_H_ */

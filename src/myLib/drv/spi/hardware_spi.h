#ifndef __HARDWARESPI_H_
#define __HARDWARESPI_H_

#include "myLib/drv/commonDrv/commonDrv.h"

void spiTransmit(unsigned char data, unsigned int size);
void spiReceive(unsigned char *pdata, unsigned int size);
void spiTR(unsigned char *pTdata,unsigned char *pRdata,unsigned int size);

void spiTransmit_IT(unsigned char *pdata, unsigned int outsize);
void spiReceive_IT(unsigned char *pdata, unsigned int outsize);
void spiTR_IT(unsigned char *pTdata,unsigned char *pRdata,unsigned int outsize);

#endif

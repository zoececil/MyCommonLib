#ifndef HARDWARE_IIC_H
#define HARDWARE_IIC_H
#include "all_config.h"
#include "../nativeInterface.h"
#include "myLib/drv/commonDrv/commonDrv.h"

void iic_T_write_oneaddr(unsigned char addr,unsigned char *pdata,unsigned int size);
void iic_R_read_oneaddr(unsigned char addr,unsigned char *pdata,unsigned int size);
void iic_T_write_twoaddr(unsigned char addr,unsigned char maddr,unsigned char mlength,unsigned char *pdata,unsigned int size);
void iic_R_read_twoaddr(unsigned char addr,unsigned char maddr,unsigned char mlength,unsigned char *pdata,unsigned int size);



#endif

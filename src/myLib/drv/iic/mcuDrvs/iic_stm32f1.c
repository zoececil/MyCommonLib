#include "../hardware_iic.h"
#ifdef mcu_stm32f1

extern I2C_HandleTypeDef hi2c1;
void iic_T_write_oneaddr(unsigned char addr,unsigned char *pdata,unsigned int size)
{
	HAL_I2C_Master_Transmit(&hi2c1,addr,pdata,size,1000);
}
void iic_R_read_oneaddr(unsigned char addr,unsigned char *pdata,unsigned int size)
{
	HAL_I2C_Master_Receive(&hi2c1,addr,pdata,size,1000);
}
void iic_T_write_twoaddr(unsigned char addr,unsigned char maddr,unsigned char mlength,unsigned char *pdata,unsigned int size)
{
	HAL_I2C_Mem_Write(&hi2c1,addr,maddr,mlength,pdata,size,1000);
}
void iic_R_read_twoaddr(unsigned char addr,unsigned char maddr,unsigned char mlength,unsigned char *pdata,unsigned int size)
{
	HAL_I2C_Mem_Read(&hi2c1,addr,maddr,mlength,pdata,size,1000);
}
#endif

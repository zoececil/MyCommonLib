/*
 * uart_stm32f1_hal.c
 *  deFalut  uart2
 *  Created on: 2021年2月3日
 *      Author: zoececiL
 *  add some changes to main.c
 */
#include "../hardware_uart.h"
#ifdef mcu_stm32f1_hal

//extern UART_HandleTypeDef huart2;
//u16 USART_RX_STA=0;
//u8 USART_RX_BUF[USART_REC_LEN];
//u8 aRxBuffer[RXBUFFERSIZE];
//u8 len;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxCpltCallback could be implemented in the user file
   */
//  if(huart->Instance==USART2)
//  	{
//  		if((USART_RX_STA&0x8000)==0)
//  		{
//  			if(USART_RX_STA&0x4000)
//  			{
//  				if(aRxBuffer[0]!=0x0a)USART_RX_STA=0;
//  				else USART_RX_STA|=0x8000;
//  			}
//  			else
//  			{
//  				if(aRxBuffer[0]==0x0d)USART_RX_STA|=0x4000;
//  				else
//  				{
//  					USART_RX_BUF[USART_RX_STA&0X3FFF]=aRxBuffer[0] ;
//  					USART_RX_STA++;
//  					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;
//  				}
//  			}
//  		}
//
//  	}
}
void sendpro(void)
{
//	  if(USART_RX_STA&0x8000)
//	  {
//	  	len=USART_RX_STA&0x3fff;
//	  	HAL_UART_Transmit(&huart2,(uint8_t*)USART_RX_BUF,len,1000);
//		while(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_TC)!=SET);
//	  	printf("\r\n\r\n");
//	  	USART_RX_STA=0;
//	  }
//	  else
//	  {
//
//		  myDelayMS(500);
//
//	  }
}

//void USART2_IRQHandler(void)
//{
//
//	u32 timeout=0;
//
//  HAL_UART_IRQHandler(&huart2);
//
//  	  timeout=0;
//      while (HAL_UART_GetState(&huart2) != HAL_UART_STATE_READY)//等待就绪
//  	{
//  	 timeout++;
//       if(timeout>HAL_MAX_DELAY) break;
//
//  	}
//
//  	timeout=0;
//  	while(HAL_UART_Receive_IT(&huart2, (u8 *)aRxBuffer, RXBUFFERSIZE) != HAL_OK)//一次处理完成之后，重新开启中断并设置RxXferCount为1
//  	{
//  	 timeout++;
//  	 if(timeout>HAL_MAX_DELAY) break;
//  	}
//
//}

#endif

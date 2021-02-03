#include "all_config.h"
#include "../nativeInterface.h"
#include "myLib/drv/commonDrv/commonDrv.h"

#define USART_REC_LEN  200
#define RXBUFFERSIZE   1

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void sendpro(void);

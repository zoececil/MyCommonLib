#include "../commonDrv.h"

#ifdef mcu_stm32f1_hal
static u32 fac_us=0;
void myDelayUS(u32 nus)
{
	u32 ticks;
	u32 told,tnow,tcnt=0;
	u32 reload=SysTick->LOAD;
	ticks=nus*fac_us;
	told=SysTick->VAL;
	while(1)
	{
		tnow=SysTick->VAL;
		if(tnow!=told)
		{
			if(tnow<told)tcnt+=told-tnow;
			else tcnt+=reload-tnow+told;
			told=tnow;
			if(tcnt>=ticks)break;
		}
	}
}
void myDelayMS(u16 nms)
{
	u32 i;
	for(i=0;i<nms;i++) myDelayUS(1000);
}

void myDelayInit(u8 SYSCLK)
{
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	fac_us=SYSCLK;
}
/*************************/
void myPrint(const char *str)
{
}
#endif


#ifdef mcu_stm32f1_v3_5

#endif

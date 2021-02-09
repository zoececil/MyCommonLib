/*
 * keypad.c
 *
 *  Created on: Feb 5, 2021
 *      Author: 16708zoe
 */
#include "keypad.h"
#ifdef service_input_keypad

unsigned char i,j,k,x,y,sum;

void repeat(callback function,unsigned char x,unsigned char y)
{
	function(x,y);
}
void sum_event(unsigned char sum)
{

	switch (sum)
	{
	case 0:
		printf("no event\r\n");
		break;

	case 1:
		repeat(function1,x,y);
		break;

	case 2:
		repeat(function2,x,y);
		break;

	case 3:
		repeat(function3,x,y);
		break;
	}
}

unsigned char scanKeypad(void)
{
	unsigned char sumxy;

	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			writeRow(i,s_stateMode);
		}
		setOut(j,f_stateMode);
		for(k=0;k<4;k++)
		{
			if(readCol(k)==f_stateMode)
			{
				while(readCol(k)==f_stateMode);
				x=k+1;
				y=j+1;
				sumxy = 4*(y-1)+x;
				return sumxy;
			}
		}
	}
	return 0;
}

#endif



#include "all_config.h"

#ifdef service_input_keypad
#include "keypad.h"

unsigned char i,j,k,x,y,sum,lensize,widsize;
PinState write_pin_state,set_pin_state;

void keypad_init(keypad_select_mode mode,unsigned char len_size,unsigned char wid_size)
{
	lensize = len_size;
	widsize = wid_size;
	if(mode == Pull_Down)
	{
		write_pin_state = PIN_SET;
		set_pin_state = PIN_RESET;
	}
	if(mode == Pull_Up)
	{
		write_pin_state = PIN_RESET;
		set_pin_state = PIN_SET;
	}
}

unsigned char keypad_scan(void)
{
	static unsigned int cnt[36] = {0};

	for(j=0;j<widsize;j++)
	{
		for(i=0;i<widsize;i++)
		{
			writeRow(i,write_pin_state);
		}
		setOut(j,set_pin_state);
		for(k=0;k<lensize;k++)
		{
			if(readCol(k) == set_pin_state)
			{
				if(cnt[widsize*j+k] <= 200)
				{
					cnt[widsize*j+k]++;
				}
			}
			else
			{
				cnt[widsize*j+k] = 0;
			}
			if(cnt[widsize*j+k] == 200)
			{
				x=k+1;
				y=j+1;
				sum = lensize*(y-1)+x;
				sum_event(sum);
				return sum;
			}
		}
	}
	return 0;
}

void repeat(callback function,unsigned char x,unsigned char y)
{
	cfunction = function;
	cfunction(x,y);
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


#endif



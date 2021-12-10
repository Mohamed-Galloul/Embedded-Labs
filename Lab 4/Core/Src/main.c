#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

void delay_ms(int ms);


int main(void) {
	GPIO_Init('A', 0 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 1 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 2 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 3 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 4 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 5 , OUTPUT, PUSH_PULL);
	GPIO_Init('A', 6 , OUTPUT, PUSH_PULL);




	unsigned char hex_numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
									0x6D, 0x7D, 0x07, 0x7F, 0x6F};

	while (1)
	{

		//Iterate on each number in the array
		for(int j=0; j<10; j++)
		{
			//Iterate on each pin in PortB connected to the seven segment
			for(int i=0; i<7; i++)
			{

				if(hex_numbers[j] & (0x01<<i))
				{
					GPIO_WritePin('A', i , 1);
				}

				else
				{
					GPIO_WritePin('A', i , 0);
				}

			}

			delay_ms(500);
		}

  }


  return 0;
}

void delay_ms(int ms)
{
	  for (int i = 0; i < (ms*1000); i++)
	  {
	  }
}


////led on
//GPIO_WritePin('A', 0, 1);
////delay
//for (int i = 0; i < 1000000; i++)
//{
//}
////led of
//GPIO_WritePin('A', 0, 0);
////delay
//for (int i = 0; i < 1000000; i++)
//{
//}

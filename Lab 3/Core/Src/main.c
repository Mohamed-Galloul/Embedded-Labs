#include "stm32f401cc_interface.h"


/*
* General rule for masking is (mask << (size * position)) ; the mask for 1 bit is 0x01
* Clearing: |=
* Setting:  &= ~
* Toggling: ^=
*/


int main(void) {
    //Enable port A
    RCC_AHB1ENR |= (0x01 << (1 * 0));

    //Set pin 0 in port A to be in general output mode
    GPIOA_MODER |= (0x01 << (2 * 0));

    //set output type for pin 0 in port A to be Push-Pull
    GPIOA_OTYPER &= ~ (0x01 << (1 * 0));

    //set bit 0 in port A in output data register
    GPIOA_ODR |= (0x01 << (1 * 0));

	  while (1) {

		  //This loop is for delay
		  for (int i = 0; i < 1000000; i++)
		  {
			{}
		  }

		  //Toggle the led
		  GPIOA_ODR ^= (0x01 << (1 * 0));
  }
  return 0;
}

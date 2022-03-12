/*
 * Author : Mohamed Galloul
 * Date   : 9/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "interrupt.h"
#include "Keypad.h"

void delay_ms(int ms);
void KeypadCallouts_KeyPressNotificaton(void);
void EXTI0_IRQHandler(void);

static unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
										  0x6D, 0x7D, 0x07, 0x7F, 0x6F};


unsigned char toggle_flag = 1;


int main(void) {

		//Enable clock for Port A
		GPIO_EnableClock(0);

		// Set pin 0 to be INPUT with PULL_UP mode, connected to the Push Button
		GPIO_Init(0, 0, INPUT, PULL_UP);
		// Set pin 1 to be OUTPUT with PUSH_PULL mode, connected to the LED
		GPIO_Init(0, 1, OUTPUT, PUSH_PULL);

		//Enable SYSCFG clock, Enable External Interrupts on PA0, Unmask pin0, Select the trigger to falling edge on PA0,
		//and Enable NVIC on line 6 corresponding to EXTI0.
		SYSCFG_EnableClock();
		EXTI_Enable(0);
		EXTI_Unmask(0);
		EXTI_Trigger_Selection(FALLING, 0);
		NVIC_Enable(0, 6);


  while (1) {

  }

  return 0;
}

void EXTI0_IRQHandler(void)
	{

	GPIO_WritePin(0, 1, toggle_flag);

	if(toggle_flag)
	{
		toggle_flag = 0;
	}
	else
	{
		toggle_flag = 1;
	}

	//Clear the pending pin for pin0, after the ISR has finished.
	EXTI_Clear(0);
	}



void delay_ms(int ms) {
  unsigned int i;
  for (i = 0; i < ms *1000; i++) {
  }
}


void KeypadCallouts_KeyPressNotificaton(void){
	int key = Keypad_GetKey();
	if(key != -1){
		//Get the corresponding hex representation of the key
		unsigned char hex_number = sevenSegHex[key];

		//Iterate over each pin in PortB connected to seven segment
		for (int i = 0; i < 7; i++) {
					if(hex_number & (0x01<<i))
						{
							GPIO_WritePin(1, i , 1);
					}
					else{
							GPIO_WritePin(1, i , 0);
					}
			  }
	}

}

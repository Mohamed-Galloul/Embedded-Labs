/*
 * Author : Mohamed Galloul
 * Date   : 1/1/2022
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "USART.h"

void delay_ms(int ms);



unsigned char string [] = "Hello World!";


int main(void) {

		// Enable clock for Port A
		GPIO_EnableClock(0);

		// Set pin  to be ALTERNATIVE_FUN (USART2) with PUSH_PULL mode, connected to the RXD pin in the virtual terminal
		GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);


		// Enable USART2 clock
		USART2_EnableClock();

		// Enable USART2, as a transmitter that transmits data of 8 bit length,
		// at a baud rate of 9600 and 1 stop bit
		// (which is the same baud rate and number of stop bits for the virtual terminal on Proteus)
		USART_Enable();

		unsigned int arrSize = sizeof(string)/sizeof(string[0]);

		// Iterate over each Character on the array and print it on the terminal
		for (int i = 0; i < arrSize-1; i++)
		{

			Write_USART_DR(string[i]); //print the current character
			while(Read_TC_Bit() == 0){} // wait until current character is sent by polling on TC flag
			Clear_TC_Bit(); // Clear the TC flag to send the next character
			delay_ms(10); // wait for 10ms before sending again
		}

  while (1) {

  }

  return 0;
}






void delay_ms(int ms) {
  unsigned int i;
  for (i = 0; i < ms *1000; i++) {
  }
}



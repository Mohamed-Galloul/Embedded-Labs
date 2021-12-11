/*
 * Author : Mohamed Galloul
 * Date   : 9/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

void delay_ms(int ms);
void KeypadCallouts_KeyPressNotificaton(void);


static unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
										  0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(void) {

		Keypad_init();


		GPIO_EnableClock('B');

		//Configure 7-segment pins in port B to be PUSH_PULL
		for (int i = 0; i < 7; i++) {
		GPIO_Init('B', i, OUTPUT, PUSH_PULL);
		}


  while (1) {

		Keypad_manage();

  }

  return 0;
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
							GPIO_WritePin('B', i , 1);
					}
					else{
							GPIO_WritePin('B', i , 0);
					}
			  }
	}

}


void delay_ms(int ms) {
  unsigned int i;
  for (i = 0; i < ms *1000; i++) {
  }
}

//if (buttonState == 0) {
//  if (GPIO_ReadPin('A', 7) == 0) {    //
//    delay30ms();                      // -> Read button
//    if (GPIO_ReadPin('A', 7) == 0) {  //
//      buttonState = 1;
//
//      for (i = 0; i < 7; i++) {
//        GPIO_WritePin('A', i, (sevenSegHex[counter] & (1 << i)) >> i);
//      }
//
//      counter++;
//      if (counter > 9) {
//        counter = 0;
//      }
//    }
//  }
//}
//
//if (GPIO_ReadPin('A', 7) == 1) {    //
//  delay30ms();                      // -> Read button
//  if (GPIO_ReadPin('A', 7) == 1) {  //
//    buttonState = 0;
//  }
//}

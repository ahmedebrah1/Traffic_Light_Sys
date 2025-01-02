/******************************************************************************
 *
 * [FILE NAME]:     led.c
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [DESCRIPTION]:   Source file for LEDDriver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/

#include "led.h"


/*
 * Description :
 * Setup the direction of the required pin output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
 void init_led(DIO_Port port_led ,DIO_Pin pin_led ){
	 DIO_SetPinDirection(port_led,pin_led ,pin_output);
 }

 /*
  * Description :
  * Write the value Logic High  on the required pin.
  * If the input port number or pin number are not correct, The function will not handle the request.
  */
void led_on(DIO_Port port_led ,DIO_Pin pin_led){
#ifdef negtive
	DIO_WritePin(port_led,pin_led, LOGIC_HIGH);
#endif
#ifdef postive
	DIO_WritePin(port_led,pin_led, LOGIC_LOW );
#endif

}

/*
 * Description :
 * Write the value  Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void led_off(DIO_Port port_led ,DIO_Pin pin_led){
#ifdef negtive
	DIO_WritePin(port_led,pin_led,LOGIC_LOW );
#endif
#ifdef postive
	DIO_WritePin(port_led,pin_led, LOGIC_HIGH );
#endif

}


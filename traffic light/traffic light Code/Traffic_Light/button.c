/******************************************************************************
 *
 * [FILE NAME]:     button.c
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [DESCRIPTION]:   Source file for Button Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/


#include"button.h"


/*
 * Description :
 * Setup the direction of the required pin input.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void init_button(DIO_Port port_button ,DIO_Pin pin_button ){
	DIO_SetPinDirection(port_button,pin_button ,pin_input);
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
buttonstate button_getstatus(DIO_Port port_button ,DIO_Pin pin_button){
	uint8 value=0,res=0;
#ifdef pull_up
	value=DIO_ReadPin(port_button,pin_button );
	if(LOGIC_LOW==value){
		res=pressed;
	}
	else{
		res=unpressed;
	}
#endif
#ifdef pull_down
	value=DIO_ReadPin(port_button,pin_button );
	if(LOGIC_HIGH==value){
		res=pressed;
	}
	else{
		res=unpressed;
	}
#endif
	return res;
}

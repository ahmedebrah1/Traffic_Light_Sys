/******************************************************************************
 *
 * [FILE NAME]:     dio.c
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [DESCRIPTION]:   Source file for General IO Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/

#include"dio.h"

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_SetPinDirection(DIO_Port port,DIO_Pin pin ,DioPinDirectioType direction){
	switch(port){
	case DIO_PORTA:
		if(pin_output==direction){
			SET_BIT(DDRA,pin);
		}
		else{
			CLEAR_BIT(DDRA,pin);
		}
		break;
	case DIO_PORTB:
		if(pin_output==direction){
			SET_BIT(DDRB,pin);
		}
		else{
			CLEAR_BIT(DDRB,pin);
		}
			break;
	case DIO_PORTC:
		if(pin_output==direction){
			SET_BIT(DDRC,pin);
		}
		else{
			CLEAR_BIT(DDRC,pin);
		}
		break;
	case DIO_PORTD:
		if(pin_output==direction){
			SET_BIT(DDRD,pin);
		}
		else{
			CLEAR_BIT(DDRD,pin);
		}
		break;

	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_WritePin(DIO_Port port,DIO_Pin pin ,uint8 value){
	switch(port){
	case DIO_PORTA:
		if(LOGIC_HIGH==value){
			SET_BIT(PORTA,pin);
		}
		else{
			CLEAR_BIT(PORTA,pin);
		}
		break;
	case DIO_PORTB:
		if(LOGIC_HIGH==value){
			SET_BIT(PORTB,pin);
		}
		else{
			CLEAR_BIT(PORTB,pin);
		}
			break;
	case DIO_PORTC:
		if(LOGIC_HIGH==value){
			SET_BIT(PORTC,pin);
		}
		else{
			CLEAR_BIT(PORTC,pin);
		}
		break;
	case DIO_PORTD:
		if(LOGIC_HIGH==value){
			SET_BIT(PORTD,pin);
		}
		else{
			CLEAR_BIT(PORTD,pin);
		}
		break;

	}

}


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 DIO_ReadPin(DIO_Port port,DIO_Pin pin ){
	uint8 value=0;
	switch(port){
	case DIO_PORTA:
		value=GET_BIT(PINA,pin);
		break;
	case DIO_PORTB:
		value=GET_BIT(PINB,pin);
		break;
	case DIO_PORTC:
		value=GET_BIT(PINC,pin);
		break;
	case DIO_PORTD:
		value=GET_BIT(PIND,pin);
		break;

	}
	return value;



}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void DIO_SetPortDirection(DIO_Port port,DioPinDirectioType direction){
	switch(port){
	case DIO_PORTA:
		if(port_output==direction){
			DDRA=direction;
		}
		else{
			DDRA=direction;
		}
		break;
	case DIO_PORTB:
		if(port_output==direction){
			DDRB=direction;
		}
		else{
			DDRB=direction;
		}
		break;
	case DIO_PORTC:
		if(port_output==direction){
			DDRC=direction;
		}
		else{
			DDRC=direction;
		}
		break;
	case DIO_PORTD:
		if(port_output==direction){
			DDRD=direction;
		}
		else{
			DDRD=direction;
		}
		break;

	}

}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void DIO_WritePort(DIO_Port port,uint8 value ){
	switch(port){
	case DIO_PORTA:
		PORTA=value;
		break;
	case DIO_PORTB:
		PORTB=value;
		break;
	case DIO_PORTC:
		PORTC=value;
		break;
	case DIO_PORTD:
		PORTD=value;
		break;

	}


}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 DIO_ReadPort(DIO_Port port ){
	uint8 value=0;
	switch(port){
	case DIO_PORTA:
		value=PINA;
		break;
	case DIO_PORTB:
		value=PINB;
		break;
	case DIO_PORTC:
		value=PINC;
		break;
	case DIO_PORTD:
		value=PIND;
		break;
	}

	return value;
}





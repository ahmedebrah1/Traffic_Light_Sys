
/******************************************************************************
 *
 * [FILE NAME]:     dio.h
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [Description]:   Header file for General IO Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/
#ifndef DIO_H_
#define DIO_H_

#include<avr/io.h>
#include"std_types.h"
#include"common_macros.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	pin_input,pin_output
}DioPinDirectioType;
typedef enum{
	port_input,port_output=0xff
}DioPortDirectioType;
typedef enum{
	DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
}DIO_Port;
typedef enum{
	DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3,DIO_PIN4,DIO_PIN5,DIO_PIN6,DIO_PIN7
}DIO_Pin;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_SetPinDirection(DIO_Port port,DIO_Pin pin ,DioPinDirectioType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_WritePin(DIO_Port port,DIO_Pin pin ,uint8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 DIO_ReadPin(DIO_Port port,DIO_Pin pin );

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void DIO_SetPortDirection(DIO_Port port,DioPinDirectioType direction);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void DIO_WritePort(DIO_Port port,uint8 value);

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 DIO_ReadPort(DIO_Port port );


#endif /* DIO_H_ */

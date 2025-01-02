/******************************************************************************
 *
 * [FILE NAME]:     led.h
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [Description]:   Header file for LED Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_
#include"dio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define negtive

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void init_led(DIO_Port port_led ,DIO_Pin pin_led );

/*
 * Description :
 * Write the value Logic High  on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void led_on(DIO_Port port_led ,DIO_Pin pin_led);

/*
 * Description :
 * Write the value  Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void led_off(DIO_Port port_led ,DIO_Pin pin_led);


#endif /* LED_H_ */

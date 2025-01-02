/******************************************************************************
 *
 * [FILE NAME]:     button.h
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [Description]:   Header file for Button Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_
#include"dio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define pull_down

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	unpressed,pressed
}buttonstate;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void init_button(DIO_Port port_button ,DIO_Pin pin_button );

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
buttonstate button_getstatus(DIO_Port port_button ,DIO_Pin pin_button);

#endif /* BUTTON_H_ */

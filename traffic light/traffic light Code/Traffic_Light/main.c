/******************************************************************************
 *
 * [FILE NAME]:     main.c
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [DESCRIPTION]:   Source file for Main Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/


#include "traffic_light.h"

int main(void) {
    // Initialize LEDs for cars and pedestrians
	 initTrafficLightSystem();

    while (1) {
        updateTrafficLights();  // Continuously update traffic lights
    }
}

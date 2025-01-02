/******************************************************************************
 *
 * [FILE NAME]:     traffic_light.h
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [Description]:   Header file for Traffic Light Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/

#ifndef TRAFFIC_LIGHT_H_
#define TRAFFIC_LIGHT_H_

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
    NS_GREEN,
    NS_YELLOW,
    NS_RED,
    EW_GREEN,
    EW_YELLOW,
    EW_RED,
    PED_GREEN,
    PED_RED
} TrafficLightState;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void initTrafficLightSystem();
void handleNSGreen();
void handleNSYellow();
void handleNSRed();
void handleEWGreen();
void handleEWYellow();
void handleEWRed();
void handlePedGreen();
void handlePedRed();
void updateTrafficLights();  // Main FSM handler


#endif /* TRAFFIC_LIGHT_H_ */

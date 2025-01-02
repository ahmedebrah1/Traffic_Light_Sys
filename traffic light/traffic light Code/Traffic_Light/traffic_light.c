
/******************************************************************************
 *
 * [FILE NAME]:     traffic_light.c
 *
 * [AUTHOR]:        Ahmed Ibrahim
 *
 * [DESCRIPTION]:   Source file for Traffic Light Driver
 *
 * [TARGET HW]:		ATmega32
 *
 *******************************************************************************/
#include "traffic_light.h"  // Include the header that contains state definitions and function prototypes
#include "dio.h"
#include "led.h"
#include "button.h"
#include <util/delay.h>
#include <avr/interrupt.h>
TrafficLightState currentState = NS_GREEN;
volatile uint8_t pedestrianButtonPressed = 0;  // Flag to indicate pedestrian button press

// ISR for Pedestrian Button (INT0)
ISR(INT0_vect) {
    pedestrianButtonPressed = 1;  // Set flag when the button is pressed
}

// Main FSM handler
void updateTrafficLights() {
    switch (currentState) {
        case NS_GREEN:
            handleNSGreen();
            break;
        case NS_YELLOW:
            handleNSYellow();
            break;
        case NS_RED:
            handleNSRed();
            break;
        case EW_GREEN:
            handleEWGreen();
            break;
        case EW_YELLOW:
            handleEWYellow();
            break;
        case EW_RED:
            handleEWRed();
            break;
        case PED_GREEN:
            handlePedGreen();
            break;
        case PED_RED:
            handlePedRed();
            break;
    }
}

// North-South Green State
void handleNSGreen() {
    led_on(DIO_PORTA, DIO_PIN0);  // NS Green
    led_off(DIO_PORTA, DIO_PIN1); // NS Yellow
    led_off(DIO_PORTA, DIO_PIN2); // NS Red
    led_off(DIO_PORTB, DIO_PIN0); // EW Green
    led_off(DIO_PORTB, DIO_PIN1); // EW Yellow
    led_on(DIO_PORTB, DIO_PIN2);  // EW Red
    led_on(DIO_PORTC, DIO_PIN2);  // Pedestrian Red

    _delay_ms(5000);  // 5-second green light
    currentState = NS_YELLOW;
}

// North-South Yellow State
void handleNSYellow() {
    led_off(DIO_PORTA, DIO_PIN0);
    led_on(DIO_PORTA, DIO_PIN1);
    _delay_ms(2000);  // 2-second yellow
    currentState = NS_RED;
}

// North-South Red State
void handleNSRed() {
    led_off(DIO_PORTA, DIO_PIN1);
    led_on(DIO_PORTA, DIO_PIN2);
    _delay_ms(1000);  // Pedestrian cross time
    currentState = EW_GREEN;
}

// East-West Green State
void handleEWGreen() {
    led_on(DIO_PORTB, DIO_PIN0);
    led_off(DIO_PORTB, DIO_PIN2);

    _delay_ms(5000);  // 5-second EW green
    currentState = EW_YELLOW;
}

// East-West Yellow State
void handleEWYellow() {
    led_off(DIO_PORTB, DIO_PIN0);
    led_on(DIO_PORTB, DIO_PIN1);
    _delay_ms(2000);  // 2-second yellow
    currentState = EW_RED;
}

// East-West Red State
void handleEWRed() {
    led_off(DIO_PORTB, DIO_PIN1);
    led_on(DIO_PORTB, DIO_PIN2);
    led_on(DIO_PORTA, DIO_PIN2);  // NS Red (ensure both directions red)

    // Wait for pedestrian button press or continue normal cycle
    _delay_ms(1000);  // Pedestrian cross time
        if (pedestrianButtonPressed) {
            currentState = PED_GREEN;
            pedestrianButtonPressed = 0;
            return;

    }
    currentState = NS_GREEN;
}

// Pedestrian Green State
void handlePedGreen() {
    led_on(DIO_PORTC, DIO_PIN0);  // Pedestrian Green
    led_off(DIO_PORTC, DIO_PIN2); // Pedestrian Red
    led_on(DIO_PORTA, DIO_PIN2);  // NS Red
    led_on(DIO_PORTB, DIO_PIN2);  // EW Red

    _delay_ms(5000);  // Pedestrian cross time
    currentState = PED_RED;
}

// Pedestrian Red State (Return to normal cycle)
void handlePedRed() {
    led_off(DIO_PORTC, DIO_PIN0);
    led_on(DIO_PORTC, DIO_PIN2);
    _delay_ms(1000);  // Pedestrian cross time
    currentState = NS_GREEN;
}





// Initialize traffic light system and pedestrian button interrupt
void initTrafficLightSystem() {
    // Initialize traffic light LEDs for NS direction
    init_led(DIO_PORTA, DIO_PIN0);  // NS Green
    init_led(DIO_PORTA, DIO_PIN1);  // NS Yellow
    init_led(DIO_PORTA, DIO_PIN2);  // NS Red

    // Initialize traffic light LEDs for EW direction
    init_led(DIO_PORTB, DIO_PIN0);  // EW Green
    init_led(DIO_PORTB, DIO_PIN1);  // EW Yellow
    init_led(DIO_PORTB, DIO_PIN2);  // EW Red

    // Initialize pedestrian traffic lights
    init_led(DIO_PORTC, DIO_PIN0);  // Pedestrian Green (Walk)
    init_led(DIO_PORTC, DIO_PIN2);  // Pedestrian Red (Don't Walk)

    // Initialize pedestrian button (connected to INT0)
    init_button(DIO_PORTD, DIO_PIN2);

    // Configure INT0 interrupt for RISING EDGE detection
    MCUCR |= (1 << ISC00) | (1 << ISC01);  // RISING EDGE on INT0
    GICR |= (1 << INT0);    // Enable INT0 external interrupt
    sei();                  // Enable global interrupts
}




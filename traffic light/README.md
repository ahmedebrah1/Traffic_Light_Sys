# Traffic Light Control System (Four-Way Intersection)

## Project Overview
This project implements a traffic light control system for a four-way intersection with a pedestrian crossing feature.  
The system uses a Finite State Machine (FSM) to manage traffic light transitions and an interrupt-driven mechanism for pedestrian requests.

---

## Features
- **Finite State Machine (FSM):** Controls traffic light transitions for North-South (NS) and East-West (EW) directions.  
- **Pedestrian Button (Interrupt-Based):** Pedestrian crossing is triggered by an external interrupt (RISING EDGE).  
- **Modular Design:** Each traffic light state is handled by a separate function.  
- **Delay Handling:** Custom delay functions are implemented for precise timing (milliseconds and microseconds).  

---

## Components Required
- **Microcontroller:** ATmega32  
- **LEDs:**  
  - 3 LEDs for North-South (Green, Yellow, Red)  
  - 3 LEDs for East-West (Green, Yellow, Red)  
  - 2 LEDs for pedestrian signals (Walk/Don’t Walk)  
- **Push Button:** For pedestrian crossing    
- **Breadboard and Jumper Wires**  

---

## Circuit Description
- **PORTA:** Controls NS traffic lights.  
- **PORTB:** Controls EW traffic lights.  
- **PORTC:** Controls pedestrian lights.  
- **PORTD (PD2):** Pedestrian button connected to INT0 (External Interrupt).  

---

## How It Works
1. **Normal Cycle:** The system alternates between NS and EW green lights with yellow transitions.  
2. **Pedestrian Request:** When the button is pressed, the system transitions to the pedestrian green state during the red light phase.  
3. **Timeout Mechanism:** If no pedestrian request is made, the system continues in its regular loop.  
4. **Timing:**  
   - Green Light: 5 seconds  
   - Yellow Light: 2 seconds  

---

## How to Run the Project
### 1. Simulation Proteus
- Open the Proteus.  
- Upload the HEX file to the ATmega32 microcontroller.  
- Press the pedestrian button to trigger pedestrian crossing.  

### 2. On Physical Hardware
- Assemble the circuit on a breadboard.  
- Upload the code to the ATmega32 using AVRDUDE or any programmer.  
```bash
avrdude -c usbasp -p m32 -U flash:w:Traffic_Light.hex

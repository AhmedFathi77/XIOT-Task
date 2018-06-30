# XIOT-Task
Embedded systems Task using AVR controller ATMEGA32

## instructions for setting the app up
```
I used ATMEGA32 so you can run the code using C/C++ Eclipse 
Simulation using Proteus 8 Professional (Portable Version)

```

## Assumptions I’ve made
```
F_cpu = 1 MHz 
interrtupt 1 for the switch (INT1_Vect)
Led connected to Pin PC0 in Port C
Pin PA0 in Port A For temprature sensor 

```

## Drivers used
``` 
interrupt Driver contains files (interrupt.c --- interrupt.h)
ADC Driver       contains files (ADC.c --- ADC.H)
Timer Driver     contains files (Timer.c --- Timer.H)
UART Driver      contains files (UART.c --- UART.H)

```

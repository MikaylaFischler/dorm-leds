#ifndef DEV_TYPES_H_
#define DEV_TYPES_H_

// Types of Devices Present in this System
// Type is a 16-bit unsigned int, but it is treated as an 8-bit unsigned int since that is all that is needed

#define DEV_UNKNOWN_DEVICE 0xFFFFFFFF

// Digital I/O
#define DEV_GENERIC_D_INPUT 0x00000000
#define DEV_PUSH_BUTTON 0x00000001

#define DEV_GENERIC_D_OUTPUT 0x0000000F
#define DEV_LED 0x0000001F

// Analog I/O
#define DEV_GENERIC_A_INPUT 0x000000FF

#define DEV_GENERIC_A_OUTPUT 0x00000FFF

// Multi-Component Systems
#define DEV_GENERIC_MCOMPONENT 0x00000FFFF
#define DEV_LED_PUSH_BUTTON 0x00001FFFF

#endif

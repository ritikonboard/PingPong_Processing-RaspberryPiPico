#ifndef _HAL_H_

        #define _HAL_H_               
        #define NUM_LED_SEGMENTS 7   // Do NOT change this
        #define player1 A0
        #define player2 A1
        #define switch1 9
        #define switch2 10

        // HAL: HAL stands for Hardware Abstraction Layer
        // If any hardware wiring etc is changed only this file is affected,
        // remaining software, remains same
        // This is how Embedded Software Engineers do!
        //
        // Also BSP means Board Support Package, which we will study .... some other time.
        // 

        // As per the circuit diagram :
        //                             A1,B1,C1,D1,   E1,F1,G1
        int LEDfirst[NUM_LED_SEGMENTS] = {  9, 10, 11, 12,   13, 14, 15};
        //NOTE     DP is not working the actual display
        //                             A2,B2,C2,D2,   E2,F2,G2
        int LEDsecond[NUM_LED_SEGMENTS] = {  2, 3, 4, 5,   6, 7, 8};
        //NOTE     DP is not working the actual display

#endif  // _HAL_H_

#ifndef _FONT_H_

            #define _FONT_H_               


            #include "hal.h"


            #define NUMBER_OF_SYMBOLS  10 

            ////// Set up which segments have to be turned ON or OFF for each letter or symbol
            ////// you can identify the neccesary pattern using the font.png mapping file
            int fontSymbolBits[NUMBER_OF_SYMBOLS][NUM_LED_SEGMENTS] = { 
            //A, B, C, D,    E, F, G
            { 1, 1, 1, 1,    1, 1, 0}, // 0
            { 0, 0, 0, 0,    1, 1, 0}, // 1
            { 1, 1, 0, 1,    1, 0, 1}, // 2
            { 1, 1, 1, 1,    0, 0, 1}, // 3 
            { 0, 1, 1, 0,    0, 1, 1}, // 4

            //A, B, C, D,    E, F, G   
            { 1, 0, 1, 1,    0, 1, 1}, // 5
            { 1, 0, 1, 1,    1, 1, 1}, // 6
            { 1, 1, 1, 0,    0, 0, 0}, // 7 
            { 1, 1, 1, 1,    1, 1, 1}, // 8
            { 1, 1, 1, 1,    0, 1, 1}, // 9

            };

#endif  // _FONT_H_

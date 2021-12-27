/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#ifndef KEYBOARD_H
    #define KEYBOARD_H
    
    #include "project.h"

    /*** MACROS ***/
    #define keystroke_flag_on keystroke == 1
    #define keystroke_flag_off keystroke = 0
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern volatile uint8 keystroke;
    extern unsigned char key;
    
    /*** FUNCTION PROTOTYPES ***/
    void task_selection(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(KBI);   
    
#endif

/* [] END OF FILE */

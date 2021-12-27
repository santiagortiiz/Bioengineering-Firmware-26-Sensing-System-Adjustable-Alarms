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

#ifndef CHRONOMETER_H
    #define CHRONOMETER_H
    
    #include "project.h"

    /*** MACROS ***/
    #define thousand_miliseconds ms == 1000
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    extern volatile uint16 ms;
    
    /*** FUNCTION PROTOTYPES ***/
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(chronometer);   
    
#endif

/* [] END OF FILE */

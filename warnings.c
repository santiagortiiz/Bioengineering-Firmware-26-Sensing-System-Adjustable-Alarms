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

/*** INCLUDED COMPONENTS ***/
#include "warnings.h"

/*** VARIABLES ***/

/*** FUNCTIONS ***/
uint8 threshold_angle_comparison(uint32 variable, uint32 threshold){    
    if (variable >= threshold) return 1;                                    // Compare the variable and threshold 
    else return 0;                                                          // values, then return 1 or 0 
}                                                                           

uint8 threshold_light_comparison(uint32 variable, uint32 threshold){
    if (variable <= threshold) return 1;
    else return 0;
}

// Test Function (Doesn't Work yet)
uint8 threshold_light_comparison_test(uint32 *variable, uint32 *threshold){
    if (*variable <= *threshold) return 1;
    else return 0;
}    


/*** INTERRUPTS ***/

/* [] END OF FILE */

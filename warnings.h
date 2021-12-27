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

#ifndef WARNINGS_H
    #define WARNINGS_H
    
    #include "project.h"

    /*** MACROS ***/
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    
    /*** FUNCTION PROTOTYPES ***/
    uint8 threshold_angle_comparison(uint32 variable, uint32 threshold);
    uint8 threshold_light_comparison(uint32 variable, uint32 threshold);
    
    // Test Function (Doesn't work yet)
    uint8 threshold_light_comparison_test(uint32 *variable, uint32 *threshold);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */

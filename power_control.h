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

#ifndef POWER_CONTROL_H
    #define POWER_CONTROL_H
    
    #include "project.h"

    /*** MACROS ***/
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    
    /*** FUNCTION PROTOTYPES ***/
    void enter_hibernate_mode(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    CY_ISR_PROTO(wake_up_system);           // PICU of the Wake_up Pin
    
#endif

/* [] END OF FILE */

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
#include "chronometer.h"

/*** VARIABLES ***/
volatile uint16 ms = 0;              // Non optimizable variable

/*** FUNCTIONS ***/


/*** INTERRUPTS ***/
CY_ISR(chronometer){                // Count miliseconds
    ms++;
    if (thousand_miliseconds) ms = 0;
}

/* [] END OF FILE */

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
#include "power_control.h"          // keyboard.h and menu.h are needed to put the
#include "keyboard.h"               // system in the "home" position after wake up 
#include "menu.h"                   // and able wake_up interruption only when key = 'C'

/*** VARIABLES ***/

/*** FUNCTIONS ***/
void enter_hibernate_mode(void){
    CyPmSaveClocks();               // Prepare the clocks and the pheriferics to
                                    // the hibernate mode calling saveConfig() and
    Counter_Sleep();                // component_Stop() methods
    ADC_Sleep();
    LCD_Sleep();
    
    CyPmHibernate();
}

/*** INTERRUPTS ***/
CY_ISR(wake_up_system){
    Wake_up_ClearInterrupt();       // Clean the interrupt of the PICU
    
    if (key == 'C'){
        CyPmRestoreClocks();        // Restore the clocks and the configuration
        Counter_Wakeup();           // of different component calling the 
        ADC_Wakeup();               // RestoreConfig() function
        LCD_Wakeup();
        
        key = '#';                  // Change the key value to avoid falling into
        menu(key);                  // a loop of hibernation
    }
    
}

/* [] END OF FILE */

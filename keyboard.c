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
#include "keyboard.h"
#include "menu.h"
#include "power_control.h"

/*** VARIABLES ***/
volatile uint8 keystroke = 0;
unsigned char key;

/*** FUNCTIONS ***/
void task_selection(void){
    switch(Keyboard_teclaPresionada()){             // Analyze the pressed key and save it into  
        case 'A':                                   // a variable (key) depending on the case
            key = Keyboard_teclaPresionada();       // Then the "menu" function is called
            break;
            
        case 'B':
            key = Keyboard_teclaPresionada();
            break;
            
        case 'C':
            key = Keyboard_teclaPresionada();
            menu(key);
            Buzzer_Write(0);                        // Shut down the Buzzer
            enter_hibernate_mode();                 // Put the system on Hibernate mode
            break;
            
        case '#':
            key = Keyboard_teclaPresionada();
            Buzzer_Write(0);                        // Shut down the Buzzer
            menu(key);                              // Put the home menu in the system
            break;
    }
}

/*** INTERRUPTS ***/
CY_ISR(KBI){
    keystroke = 1;                                  // Enable keyboard flag
}

/* [] END OF FILE */

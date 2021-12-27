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
#include "menu.h"
#include "sense.h"

/*** VARIABLES ***/

/*** FUNCTIONS ***/
void menu(uint8 menu_index){        // Get the key pressed and show the respective menu on the LCD
    LCD_ClearDisplay();                                 
    
    switch(menu_index){
        case '#':
            LCD_Position(0,3);
            LCD_PrintString("Monitor System");
            LCD_Position(1,0);
            LCD_PrintString("A-Angle");
            LCD_Position(2,0);
            LCD_PrintString("B-Reflected Light");
            LCD_Position(3,0);
            LCD_PrintString("C-Hibernate");
            LCD_Position(3,14);
            LCD_PrintString("#-Home");
            break;
            
        case 'A':
            LCD_Position(0,0);
            LCD_PrintString("Angle");
            LCD_Position(1,0);
            LCD_PrintString("Angle = ");
            LCD_PrintNumber(acelerometer_measure);
            
            LCD_Position(2,0);
            LCD_PrintString("Threshold = ");
            LCD_PrintNumber(acelerometer_threshold);
            break;
            
        case 'B':
            LCD_Position(0,0);
            LCD_PrintString("Reflected Light");
            LCD_Position(1,0);
            LCD_PrintString("Light = ");
            LCD_PrintNumber(IR_measure);
            
            LCD_Position(2,0);
            LCD_PrintString("Threshold = ");
            LCD_PrintNumber(IR_threshold);
            break;
            
        case 'C':
            LCD_Position(0,0);
            LCD_PrintString("Hibernating");
            break;
    }
}

/*** INTERRUPTS ***/

/* [] END OF FILE */

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

/* QUESTIONS 
- If you are coding in group, or you have to change something in a project of somebody, is there a way to know
where you can find any function you find in the main? i.e: is there a way to know in which archive is task_selection() ?
    SOLVED - ANSWER: Yes, right click on the function and selecting "Go to definition"

*** PRINCIPAL QUESTION TO SOLVE ***
- How to do the comparison functions of the "warnings.h" with pointers that select the content of the
Variable and the Threshold to compare (threshold_light_comparison_test)?  

- How to assign an output of a function into a variable inside a struct with a specified size
i.e a function return a value of 16 or 32 bits and i want to assign it to a variable:10 inside a struct
I need it for the function angle_calculation & angle_threshold_calculation in "sense.c"

- .c and .h files needs to be documented? or just one of them for each component?
*/

/*** MACROS ***/
#define and &&
#define or ||

/*** INCLUDED COMPONENTS ***/
#include "project.h"
#include "menu.h"
#include "keyboard.h"
#include "chronometer.h"
#include "sense.h"
#include "warnings.h"
#include "power_control.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_keyboard_StartEx(KBI);
    isr_counter_StartEx(chronometer);
    isr_wake_up_StartEx(wake_up_system);
    
    /*** COMPONENTS INITIALIZATION ***/
    Keyboard_Start();
    Counter_Start();
    AMux_Start();
    ADC_Start();
    LCD_Start();
    
    key = '#';                                  // Start the system
    menu(key);
    
    for(;;)
    {
        if (keystroke_flag_on){                 // keystroke is the flag of the keyboard 
            keystroke_flag_off;                 // and it is set when a key is pressed
            task_selection();                   // Then the task selection function is called
        }
        
        switch(key){                            // When the key is 'A' or 'B', the system 
            case 'A':                           // sense 20 times per half second and print
                if (ms%25 == 0){                // the sensed variables 2 times per second
                    sense();
                }
                if (ms%500 == 0){               // Also, after print, the comparison function is called
                    menu(key);                  // to determine the state of the Alert Buzzer
                    Buzzer_Write(threshold_angle_comparison(acelerometer_measure, acelerometer_threshold));
                }
                break;
                    
            case 'B':
                if (ms%25 == 0){ 
                    sense();
                }
                if (ms%500 == 0){
                    menu(key);
                    Buzzer_Write(threshold_light_comparison(IR_measure, IR_threshold));
                    //Buzzer_Write(threshold_light_comparison_test(&measure.sensor_2, &measure.threshold_2));   // Problems
                }
                break;
        }
    }
}

/* [] END OF FILE */

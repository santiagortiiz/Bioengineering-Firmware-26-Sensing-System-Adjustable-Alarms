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

#ifndef SENSE_H
    #define SENSE_H
    
    #include "project.h"

    /*** MACROS ***/
    #define acelerometer_measure measure.sensor_1
    #define acelerometer_threshold measure.threshold_1
    #define IR_measure measure.sensor_2
    #define IR_threshold measure.threshold_2
    
    /*** GLOBAL VARIABLE PROTOTYPES ***/
    typedef struct Measures{ 
        uint32 counter:7;
        
        uint32 acumulated_ADC_1:17;         // acumulated_ADC_X are used to save
        uint32 acumulated_ADC_2:17;         // each sample of the ADC
        uint32 acumulated_ADC_3:17; 
        uint32 acumulated_ADC_4:17; 
        
        uint32 sensor_1:12;                 // Conected to the Acelerometer
        uint32 sensor_2:12;                 // Conected to the Fotointerruptor
        uint32 threshold_1:12;              // Threshold determined by Potentiometer_1
        uint32 threshold_2:12;              // Threshold determined by Potentiometer_2
    } measures;
    
    extern measures measure;
    extern uint16 Z_axis[91];               // Calibration Matrix of the Z Axis of the Acelerometer
    
    /*** FUNCTION PROTOTYPES ***/
    void sense(void);
    void angle_calculation(void);
    void angle_threshold_calculation(void);
    
    /*** INTERRUPTION PROTOTYPES ***/
    
#endif

/* [] END OF FILE */

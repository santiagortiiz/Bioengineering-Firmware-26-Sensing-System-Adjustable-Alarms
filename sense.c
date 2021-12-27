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
#include "sense.h"

/*** VARIABLES ***/
// This is the Calibration Matrix of the Z Axis of the Acelerometer
uint16 Z_axis[91] = {1886,	1892,	1885,	1887,	1889,	1891,	1882,	1886,	1885,	1885,	1884,   // 10	
1875,	1874,	1873,	1873,	1870,	1869,	1867,	1865,	1856,	1851,	1848,	1843,	1832,	1838,   // 24	
1833,	1831,	1829,	1818,	1816,	1793,	1790,	1787,	1784,	1781,	1775,	1771,	1761,	1760,   // 38	
1751,	1739,	1731,	1722,	1715,	1713,	1708,	1689,	1675,	1668,	1659,	1651,	1645,	1633,	// 52
1623,	1616,	1605,	1595,	1581,	1572,	1563,	1557,	1542,	1530,	1519,	1508,	1493,	1484,	// 66
1473,	1460,	1448,	1441,	1431,	1420,	1408,	1396,	1386,	1371,	1360,	1346,	1336,	1325,	// 80
1311,	1298,	1290,	1281,	1264,	1256,	1241,	1223,	1215,	1100};          //78
                        //70                            //60

measures measure;

/*** FUNCTIONS ***/
void sense(void){
    measure.counter++;                                      // Counter up to 20                                                  
    
    AMux_Select(0);                                         // Sensor 1 (Acelerometer) reading routine                               
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    measure.acumulated_ADC_1 += ADC_GetResult16();
    
    AMux_Select(1);                                         // Sensor 2 (Fotointerruptor) reading routine                 
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    measure.acumulated_ADC_2 += ADC_GetResult16();
    
    AMux_Select(2);                                         // Threshold 1 (Potentiometer 1) reading routine                   
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);   
    measure.acumulated_ADC_3 += ADC_GetResult16();
    
    AMux_Select(3);                                         // Threshold 2 (Potentiometer 2) reading routine                      
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    measure.acumulated_ADC_4 += ADC_GetResult16();
    
    if (measure.counter == 20){                             // When the ADC takes 20 samples for each channel                           
        measure.counter = 0;                                // it is averaged and assigned to each variable
        
        measure.sensor_1 = measure.acumulated_ADC_1 /= 20;                         
        measure.sensor_2 = measure.acumulated_ADC_2 /= 20;
        
        measure.threshold_1 = measure.acumulated_ADC_3 /= 20;                                 
        measure.threshold_2 = measure.acumulated_ADC_4 /= 20;
        
        angle_calculation();
        angle_threshold_calculation();
        
        measure.counter = 0;
        measure.acumulated_ADC_1 = 0;                                            
        measure.acumulated_ADC_2 = 0;
        measure.acumulated_ADC_3 = 0;                                            
        measure.acumulated_ADC_4 = 0;
    }
}

void angle_calculation(void){
    for (measure.counter = 0; measure.counter < 92; measure.counter++){     // Search in the LUT the nearst  
        if (Z_axis[measure.counter] <= measure.sensor_1) {                  // position of the ADC read value
            measure.sensor_1 = measure.counter;
            break;
        }
    }
}

void angle_threshold_calculation(void){
    for (measure.counter = 0; measure.counter < 92; measure.counter++){     // Search in the LUT the nearst  
        if (Z_axis[measure.counter] <= measure.threshold_1) {               // position of the ADC read value
            measure.threshold_1 = measure.counter;
            break;
        }
    }
}

/*** INTERRUPTS ***/

/* [] END OF FILE */

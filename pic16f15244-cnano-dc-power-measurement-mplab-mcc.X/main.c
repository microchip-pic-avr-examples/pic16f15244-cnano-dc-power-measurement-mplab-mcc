 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

/******************************************************************************
 *  macro definitions
 *****************************************************************************/
#define VOL_GAIN (uint32_t)(2473)     //Vout (integer conversion) = (ADCValue * Vref/1023)(R1/R1+R2) == R1=12K,R2=1.8K and Vref=3.3, (0.02473)
#define CUR_GAIN (uint32_t)(48)      //(integer conversion)(AdcValu*(Vref/1023)(R23/1000)) == R23 = 680,Vref = 3.3, (0.0048)
#define AFTER_DEC_POINT_ADJ (1000)
/******************************************************************************
 *  Global variables 
 *****************************************************************************/
const uint32_t VOL_ADJ_CONST = 100000;      //Conversion constant 
const uint32_t CUR_ADJ_CONST = 10000;
const uint32_t POW_ADJ_CONST = 100000;
volatile uint16_t timerFlag = 0;

/******************************************************************************
 *  function declaration
 *****************************************************************************/
void Application (void);
void IntToFloatConv(uint32_t *value, uint16_t *valueInt, uint16_t *valueAfterDecimal, uint32_t adjValue);
void UserTMR_InterruptHandler();
/*
                         Main application
 */
int main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    Timer0_OverflowCallbackRegister(UserTMR_InterruptHandler);
    printf("DC Power Measurement \r\n");
   
    while(1)
    {
        Application();
    }    
}

/*******************************************************************************
 * void Application(void)
 *
 * API to run the application, this API calls main application functions.
 * Function calls measure the system power parameters: Voltage, Current and Power.
 *
 * @param None
 * @return None
 ******************************************************************************/
void Application(void)
{
    uint16_t adcResultVoltage, adcResultCurrent = 0; 
    uint32_t dcVoltage, dcCurrent, dcPower = 0;
    uint16_t floatDecimal, floatAfterDecimal = 0;
    
    if(timerFlag <= 10)
    {   
      adcResultVoltage =  ADC_GetConversion(Vol);                 //Read analog voltage signal 
      adcResultCurrent = ADC_GetConversion(Cur);
    }
    else
    {
      timerFlag = 0;
      dcVoltage = ((adcResultVoltage/10) * VOL_GAIN);         //Convert ADC raw data in to voltage data by multiplying the raw adc data with 
                                                   //resistor divider equation and ADC step size value
      IntToFloatConv(&dcVoltage,&floatDecimal,&floatAfterDecimal,VOL_ADJ_CONST);
      printf("Voltage(V): %d.%d\r\n",floatDecimal,floatAfterDecimal);
      
      dcCurrent = ((adcResultCurrent/10) * CUR_GAIN);         /*Convert ADC raw data in to voltage data by multiplying the raw adc data with 
                                                   current mirror circuit equation and ADC step size value*/ 
      IntToFloatConv(&dcCurrent,&floatDecimal,&floatAfterDecimal,CUR_ADJ_CONST);
      printf("Current(A): %d.%d\r\n",floatDecimal,floatAfterDecimal);
    
      dcPower = ((dcVoltage/AFTER_DEC_POINT_ADJ) * (dcCurrent/AFTER_DEC_POINT_ADJ));
      IntToFloatConv(&dcPower,&floatDecimal,&floatAfterDecimal,POW_ADJ_CONST);
      printf("Power(W): %d.%d\r\n\n",floatDecimal,floatAfterDecimal);
    }
 }

void IntToFloatConv(uint32_t *value, uint16_t *valueInt, uint16_t *valueAfterDecimal, uint32_t adjValue)
{
    uint32_t adjustmentValue = 0;
    
    *valueInt = (uint16_t) (*value / adjValue);
    adjustmentValue = *valueInt * adjValue;
    *valueAfterDecimal = (uint16_t)((*value % adjustmentValue) / AFTER_DEC_POINT_ADJ); 
}

void UserTMR_InterruptHandler()
{
    timerFlag += 1;
}
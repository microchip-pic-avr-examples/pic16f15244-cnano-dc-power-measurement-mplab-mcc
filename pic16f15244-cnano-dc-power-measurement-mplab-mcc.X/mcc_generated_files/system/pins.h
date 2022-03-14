/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RB7 aliases
#define Vol_TRIS                 TRISBbits.TRISB7
#define Vol_LAT                  LATBbits.LATB7
#define Vol_PORT                 PORTBbits.RB7
#define Vol_WPU                  WPUBbits.WPUB7
#define Vol_OD                   ODCONBbits.ODCB7
#define Vol_ANS                  ANSELBbits.ANSB7
#define Vol_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Vol_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Vol_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Vol_GetValue()           PORTBbits.RB7
#define Vol_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Vol_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Vol_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Vol_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define Vol_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define Vol_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define Vol_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define Vol_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_RC3 aliases
#define Cur_TRIS                 TRISCbits.TRISC3
#define Cur_LAT                  LATCbits.LATC3
#define Cur_PORT                 PORTCbits.RC3
#define Cur_WPU                  WPUCbits.WPUC3
#define Cur_OD                   ODCONCbits.ODCC3
#define Cur_ANS                  ANSELCbits.ANSC3
#define Cur_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Cur_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Cur_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Cur_GetValue()           PORTCbits.RC3
#define Cur_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Cur_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Cur_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Cur_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Cur_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Cur_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Cur_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Cur_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/
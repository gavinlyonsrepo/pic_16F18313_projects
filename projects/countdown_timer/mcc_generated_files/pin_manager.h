/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18313
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set pinDIO aliases
#define pinDIO_TRIS                 TRISAbits.TRISA0
#define pinDIO_LAT                  LATAbits.LATA0
#define pinDIO_PORT                 PORTAbits.RA0
#define pinDIO_WPU                  WPUAbits.WPUA0
#define pinDIO_OD                   ODCONAbits.ODCA0
#define pinDIO_ANS                  ANSELAbits.ANSA0
#define pinDIO_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define pinDIO_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define pinDIO_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define pinDIO_GetValue()           PORTAbits.RA0
#define pinDIO_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define pinDIO_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define pinDIO_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define pinDIO_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define pinDIO_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define pinDIO_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define pinDIO_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define pinDIO_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set pinClk aliases
#define pinClk_TRIS                 TRISAbits.TRISA1
#define pinClk_LAT                  LATAbits.LATA1
#define pinClk_PORT                 PORTAbits.RA1
#define pinClk_WPU                  WPUAbits.WPUA1
#define pinClk_OD                   ODCONAbits.ODCA1
#define pinClk_ANS                  ANSELAbits.ANSA1
#define pinClk_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define pinClk_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define pinClk_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define pinClk_GetValue()           PORTAbits.RA1
#define pinClk_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define pinClk_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define pinClk_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define pinClk_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define pinClk_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define pinClk_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define pinClk_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define pinClk_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BUT_RA2 aliases
#define BUT_RA2_TRIS                 TRISAbits.TRISA2
#define BUT_RA2_LAT                  LATAbits.LATA2
#define BUT_RA2_PORT                 PORTAbits.RA2
#define BUT_RA2_WPU                  WPUAbits.WPUA2
#define BUT_RA2_OD                   ODCONAbits.ODCA2
#define BUT_RA2_ANS                  ANSELAbits.ANSA2
#define BUT_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BUT_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BUT_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BUT_RA2_GetValue()           PORTAbits.RA2
#define BUT_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BUT_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BUT_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define BUT_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define BUT_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define BUT_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define BUT_RA2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define BUT_RA2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set POT_ANA4 aliases
#define POT_ANA4_TRIS                 TRISAbits.TRISA4
#define POT_ANA4_LAT                  LATAbits.LATA4
#define POT_ANA4_PORT                 PORTAbits.RA4
#define POT_ANA4_WPU                  WPUAbits.WPUA4
#define POT_ANA4_OD                   ODCONAbits.ODCA4
#define POT_ANA4_ANS                  ANSELAbits.ANSA4
#define POT_ANA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POT_ANA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POT_ANA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POT_ANA4_GetValue()           PORTAbits.RA4
#define POT_ANA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POT_ANA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POT_ANA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POT_ANA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POT_ANA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POT_ANA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POT_ANA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define POT_ANA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set BUZZER_RA5 aliases
#define BUZZER_RA5_TRIS                 TRISAbits.TRISA5
#define BUZZER_RA5_LAT                  LATAbits.LATA5
#define BUZZER_RA5_PORT                 PORTAbits.RA5
#define BUZZER_RA5_WPU                  WPUAbits.WPUA5
#define BUZZER_RA5_OD                   ODCONAbits.ODCA5
#define BUZZER_RA5_ANS                  ANSELAbits.ANSA5
#define BUZZER_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define BUZZER_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define BUZZER_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define BUZZER_RA5_GetValue()           PORTAbits.RA5
#define BUZZER_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define BUZZER_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define BUZZER_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define BUZZER_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define BUZZER_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define BUZZER_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define BUZZER_RA5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define BUZZER_RA5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
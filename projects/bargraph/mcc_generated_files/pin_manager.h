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

// get/set SER_595 aliases
#define SER_595_TRIS                 TRISAbits.TRISA0
#define SER_595_LAT                  LATAbits.LATA0
#define SER_595_PORT                 PORTAbits.RA0
#define SER_595_WPU                  WPUAbits.WPUA0
#define SER_595_OD                   ODCONAbits.ODCA0
#define SER_595_ANS                  ANSELAbits.ANSA0
#define SER_595_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SER_595_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SER_595_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SER_595_GetValue()           PORTAbits.RA0
#define SER_595_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SER_595_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SER_595_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SER_595_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SER_595_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SER_595_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SER_595_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SER_595_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RCLK_595 aliases
#define RCLK_595_TRIS                 TRISAbits.TRISA1
#define RCLK_595_LAT                  LATAbits.LATA1
#define RCLK_595_PORT                 PORTAbits.RA1
#define RCLK_595_WPU                  WPUAbits.WPUA1
#define RCLK_595_OD                   ODCONAbits.ODCA1
#define RCLK_595_ANS                  ANSELAbits.ANSA1
#define RCLK_595_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RCLK_595_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RCLK_595_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RCLK_595_GetValue()           PORTAbits.RA1
#define RCLK_595_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RCLK_595_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RCLK_595_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define RCLK_595_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define RCLK_595_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define RCLK_595_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define RCLK_595_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define RCLK_595_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SCLK_595 aliases
#define SCLK_595_TRIS                 TRISAbits.TRISA2
#define SCLK_595_LAT                  LATAbits.LATA2
#define SCLK_595_PORT                 PORTAbits.RA2
#define SCLK_595_WPU                  WPUAbits.WPUA2
#define SCLK_595_OD                   ODCONAbits.ODCA2
#define SCLK_595_ANS                  ANSELAbits.ANSA2
#define SCLK_595_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SCLK_595_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SCLK_595_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SCLK_595_GetValue()           PORTAbits.RA2
#define SCLK_595_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SCLK_595_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SCLK_595_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SCLK_595_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SCLK_595_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SCLK_595_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SCLK_595_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SCLK_595_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set Switch_RA3 aliases
#define Switch_RA3_PORT                 PORTAbits.RA3
#define Switch_RA3_WPU                  WPUAbits.WPUA3
#define Switch_RA3_GetValue()           PORTAbits.RA3
#define Switch_RA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define Switch_RA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set BATIN_ANA4 aliases
#define BATIN_ANA4_TRIS                 TRISAbits.TRISA4
#define BATIN_ANA4_LAT                  LATAbits.LATA4
#define BATIN_ANA4_PORT                 PORTAbits.RA4
#define BATIN_ANA4_WPU                  WPUAbits.WPUA4
#define BATIN_ANA4_OD                   ODCONAbits.ODCA4
#define BATIN_ANA4_ANS                  ANSELAbits.ANSA4
#define BATIN_ANA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define BATIN_ANA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define BATIN_ANA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define BATIN_ANA4_GetValue()           PORTAbits.RA4
#define BATIN_ANA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define BATIN_ANA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define BATIN_ANA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define BATIN_ANA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define BATIN_ANA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define BATIN_ANA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define BATIN_ANA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define BATIN_ANA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set STATUSLED_RA5 aliases
#define STATUSLED_RA5_TRIS                 TRISAbits.TRISA5
#define STATUSLED_RA5_LAT                  LATAbits.LATA5
#define STATUSLED_RA5_PORT                 PORTAbits.RA5
#define STATUSLED_RA5_WPU                  WPUAbits.WPUA5
#define STATUSLED_RA5_OD                   ODCONAbits.ODCA5
#define STATUSLED_RA5_ANS                  ANSELAbits.ANSA5
#define STATUSLED_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define STATUSLED_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define STATUSLED_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define STATUSLED_RA5_GetValue()           PORTAbits.RA5
#define STATUSLED_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define STATUSLED_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define STATUSLED_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define STATUSLED_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define STATUSLED_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define STATUSLED_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define STATUSLED_RA5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define STATUSLED_RA5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

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
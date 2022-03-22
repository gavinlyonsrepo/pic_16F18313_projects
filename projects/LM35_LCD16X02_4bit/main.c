/*
* Project Name: LM35_16F8313_4bit_LCd
* File: main.c 
* Description: Display lM35 sensor data on a HD44780-based character LCD 16X02
* (4 bit mode, shift register)  using PIC16f18313
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18313 
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F18313
* Created May 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18313_projects
*/

#include "mcc_generated_files/mcc.h"
#include "HD44780_4bit_shift_lcd.h"
#include <stdio.h> /* for sprintf */


void DisplayData(void);
/* Main application */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(15);
     LCDInit(LCDCursorTypeOn, 2, 16); 
    LCDGOTO(LCDLineNumberOne, 0);
    LCDSendString("Temperature:");
    
    while (1)
    {
        DisplayData();
        __delay_ms(2000);
        // Add your application code
    }
}

void DisplayData(void)
{
    char stringUpper[4];
    char stringLower[5];
    uint16_t temperature= 0;
    uint16_t ADCValue= 0;
    
    ADCValue=ADC_GetConversion(ANI_5)>>6;
     //eg (30 = 62 *49) =  3083
    temperature=(ADCValue*49);
    sprintf(stringUpper, "%u%u.", (temperature/1000)%10, (temperature/100)%10);
    sprintf(stringLower, "%u%u'C", (temperature/10)%10, (temperature/1)%10);
    
    LCDGOTO(LCDLineNumberTwo, 0);
    LCDSendString(stringUpper);
    LCDSendString(stringLower);
}

/* End of File */

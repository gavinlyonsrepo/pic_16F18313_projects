/*
* Project Name: LM35_16F8313_4bit_LCd
* File: main.c 
* Description: Display lM35 sensor data on a HD44780-based character LCD 16X02
* (4 bit mode, shift register)  using PIC16f18313
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F18313 
* IDE:  MPLAB X v5.05
* Development board: n/a
* Created May 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_16F18313_projects
*/

#include "mcc_generated_files/mcc.h"
#include "lcd.h" 
#include <stdio.h> /* for sprintf */


void DisplayData(void);
/* Main application */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    __delay_ms(15);
     LCDinit(); 

    while (1)
    {
        DisplayData();
        __delay_ms(2000);
        // Add your application code
    }
}

void DisplayData(void)
{
    char str1[3];
    char str2[3];
    uint16_t temperature= 0;
    uint16_t ADC_value= 0;
    
    ADC_value=ADC_GetConversion(ANI_5)>>6;
     //eg (30 = 62 *49) =  3083
    temperature=(ADC_value*49);
    sprintf(str1, "%u%u", (temperature/1000)%10, (temperature/100)%10);
    sprintf(str2, "%u%u", (temperature/10)%10, (temperature/1)%10);

    LCDcmd (LCD_LINE1);
    LCDprint ("Temperature:");
    LCDcmd (LCD_LINE2);
    LCDprint (str1);
    LCDprint (".");
    LCDprint (str2);
    LCDprint ("'C");
}

/* End of File */

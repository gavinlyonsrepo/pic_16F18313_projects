/*
* Project Name: countdown
* File: main.c 
* Description: Kitchen countdown timer with tm1637 module.
* Author: Gavin Lyons.
* Complier: xc8 v2.05 compiler
* PIC: PIC16F1619 
* IDE:  MPLAB X v5.05
* Development board: Microchip Curiosity Board, PIC16F1619
* Created May 2019
*/
 
#include "mcc_generated_files/mcc.h"
#include "TM1637Display.h"

 #define DELAY 500
 
uint8_t time_value = 0;

/* ===== Function prototypes  ==== */
uint8_t map(long x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
void Countdown(void);
void BuzzerOn(void);
void Setup(void);
void Display_done(void);
 

/* ====  Main application ==== */
void main(void)
{
    uint16_t ADC_value= 0;
    Setup();
    while (1)
    {
        ADC_value=ADC_GetConversion(POT_ANA4)>>6;
        time_value =  map(ADC_value, 0, 1024, 1, 100);
        showNumberDec(time_value, true,4,0);
        __delay_ms(DELAY);
        if (Start == true)
        {
            Countdown();
        }
     }
    
}
/* ======  END of MAIN ==== */

/* ===== Function Space ==== */

// Map the ADC to the time 1023-0 99-0
uint8_t map(long x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// initialize the device
void Setup(void)
{
        
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_StopTimer();
    TMR2_StopTimer();
    setBrightness(0x0C, true);
    BUZZER_RA5_SetLow();
}

// Control and display countdown.
void Countdown(void)
{
   uint8_t seconds = 59;
   uint8_t minutes = 0;
   time_value --;
   minutes = time_value;
   TMR0_StartTimer();  // Timer0 make count true every second. 
      
   while (1)
   {     
       if (count == true)
       {
           seconds --;
           count = false;
           if ((seconds == 1) && (minutes == 0)) break;
           if (seconds == 0)
           {
               minutes --;
               seconds = 59; 
           }
       }
       // This displays the seconds in the last two places
        showNumberDecEx(seconds, 0, true, 2, 2);
        // Display the minutes in the first two places, with colon
        showNumberDecEx(minutes, 0x80 >> 3, true, 2, 0);
        
   }
   
   BuzzerOn();
   
}    

//Switch on Buzzer
void BuzzerOn(void)
{  
    while(1)
    {
        
        Display_done();
        TMR2_StartTimer();
    }
}

//Display done on seven segment display.
void Display_done(void)
{
     const uint8_t SEG_DONE[] = {
    SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
    SEG_C | SEG_E | SEG_G,                           // n
    SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
     };
    setSegments(SEG_DONE,4,0);
   
}
/*   End of File  */
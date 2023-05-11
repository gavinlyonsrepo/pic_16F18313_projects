/* 
 * @file  main.c
 * @brief ws2812 RGB LED string project
 * @author Gavin Lyons
 * @note See URL for more details https://github.com/gavinlyonsrepo/pic_16F18313_projects
 */

// Section :: libraries
#include "mcc_generated_files/mcc.h"
#include "WS2812RGBLED.h" //custom
#include "Push_button.h" //custom


//  Section ::  

// Section :: Function prototypes

void LEDdemo(void);
void LEDStartSeq(void);
void SetMode(uint8_t mode);

void LEDUnSteadyMode1(void);
void LEDUnSteadyMode2(void);

void LEDUnSteadyMode3(void);
void LEDUnSteadyMode4(void);
void LEDUnSteadyMode5(void);
void LEDUnSteadyMode6(void);
void LEDUnSteadyMode789(void);
void LEDUnSteadyMode10(void);


/*  Main application */
void main(void)
{
    uint8_t displayMode = 1; // 1-18 dispaly modes
    SYSTEM_Initialize();

    // Enable the Interrupts
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    WS2812RGBLEDInitialize();
    __delay_ms(50);
    
    WS2812RGBLEDClearAll();
    LEDStartSeq();
    WS2812RGBLEDClearAll();
    
    SetMode(displayMode); 
    srand(TMR0L);
    while(1)
    {
        //Check the pushbutton RA4 mode,  timer0 interrupt, every 5mS
        if (gPushButtonModeEvent == true)
        {
            displayMode++;
            if(displayMode <= 10) displayMode = 11; // change from flash to steady
            if (displayMode >= 19 ) displayMode = 11; //  loop around to first steady
            SetMode(displayMode);
            gPushButtonModeEvent = false;
        }
        
        // Check the pushbutton RA1 Brightness, timer0 interrupt , every 5mS
        if (gPushButtonBrightnessEvent == true)
        {
            gWS2812RGBBrightness = gWS2812RGBBrightness + 20;
            if (gWS2812RGBBrightness >= WS2812RGB_MAX_BRIGHTNESS ) gWS2812RGBBrightness = 1;
            SetMode(displayMode);
            gPushButtonBrightnessEvent = false;
        }
        
        // Check the mode,  timer0 interrupt callback every 5S
        if (gLEDunSteadyModeNumber == true)
        {
            if (displayMode >= 11 ) // If in steady mode ignore
                NOP();
            else{    
                displayMode++;
                if(displayMode >= 11) displayMode = 1; // = 10 before increment, loop back
                SetMode(displayMode);
                gLEDunSteadyModeNumber = false;
            }
        }
    }
}
/** End of MAIN */


void SetMode(uint8_t mode)
{
    switch (mode)
    {
        case 1:  LEDUnSteadyMode1(); break; // RGBOORGB
        case 2:  LEDUnSteadyMode2(); break; // Cylon one red
        case 3:  LEDUnSteadyMode3(); break; // RGRG RGRG
        case 4:  LEDUnSteadyMode4(); break; // COCO COCO
        case 5:  LEDUnSteadyMode5(); break; // OYOY OYOY
        case 6:  LEDUnSteadyMode6(); break; // GCGCGCGC
        case 7:  LEDUnSteadyMode789(); break; // random
        case 8:  LEDUnSteadyMode789(); break; // random
        case 9:  LEDUnSteadyMode789(); break; // random
        case 10: LEDUnSteadyMode10(); break; // Cylon two green
        case 11: WS2812RGB_DISPLAY_RED_ALL; break;
        case 12: WS2812RGB_DISPLAY_GREEN_ALL; break;
        case 13: WS2812RGB_DISPLAY_BLUE_ALL; break;
        case 14: WS2812RGB_DISPLAY_OFF_ALL; break;
        case 15: WS2812RGB_DISPLAY_WHITE_ALL; break;
        case 16: WS2812RGB_DISPLAY_CYAN_ALL; break;
        case 17: WS2812RGB_DISPLAY_MAGNETA_ALL; break;
        case 18: WS2812RGB_DISPLAY_YELLOW_ALL; break;
    }
    __delay_ms(10);
}


void LEDStartSeq(void)
{
    WS2812RGB_DISPLAY_GREEN;
    __delay_ms(500);
}


void LEDUnSteadyMode1(void)
{
    WS2812RGB_DISPLAY_RED;
    WS2812RGB_DISPLAY_GREEN;
    WS2812RGB_DISPLAY_BLUE;
    WS2812RGB_DISPLAY_OFF;
    WS2812RGB_DISPLAY_OFF;
    WS2812RGB_DISPLAY_BLUE;
    WS2812RGB_DISPLAY_GREEN;
    WS2812RGB_DISPLAY_RED;
    WS2812RGBLED_RESET_CODE;
}

// cylon red
void LEDUnSteadyMode2(void)
{
    // Count Up 
    for (uint8_t i = 1 ; i < 9 ;  i++ )
    {    
       WS2812RGBLEDSetPixel(i, gWS2812RGBBrightness ,0,0) ;
       __delay_ms(200);
    }
    //count down
    for (int8_t j = 8 ; j > 0 ;  j-- )
    {   
       WS2812RGBLEDSetPixel((uint8_t)j, gWS2812RGBBrightness ,0,0) ;
       __delay_ms(200);
    }
    WS2812RGBLEDClearAll();
}

void LEDUnSteadyMode3(void)
{
    for (uint8_t i = 1 ; i<9 ;i++){
        
        if(i % 2 == 0)
             WS2812RGB_DISPLAY_RED; //odd 
        else
            WS2812RGB_DISPLAY_GREEN; //even
    }
    WS2812RGBLED_RESET_CODE;
}


void LEDUnSteadyMode4(void){
    for (uint8_t i = 1 ; i<9 ;i++){
        
        if(i % 2 == 0)
             WS2812RGB_DISPLAY_CYAN; //odd 
        else
            WS2812RGB_DISPLAY_OFF; //even
    }
    WS2812RGBLED_RESET_CODE;
}


void LEDUnSteadyMode5(void){
    for (uint8_t i = 1 ; i<9 ;i++){
        
        if(i % 2 == 0)
             WS2812RGB_DISPLAY_OFF; //even
        else
            WS2812RGB_DISPLAY_YELLOW; //odd 
           
    }
    WS2812RGBLED_RESET_CODE;
}

void LEDUnSteadyMode6(void){
    for (uint8_t i = 1 ; i<9 ;i++){
        if(i % 2 == 0)
             WS2812RGB_DISPLAY_CYAN; //even
        else
            WS2812RGB_DISPLAY_GREEN;
    }
    WS2812RGBLED_RESET_CODE;
}

void LEDUnSteadyMode789(void)
{
    uint8_t randomRed = rand() % WS2812RGB_DEFAULT_BRIGHTNESS;
    uint8_t randomGreen = rand() % WS2812RGB_DEFAULT_BRIGHTNESS;
    uint8_t randomBlue = rand() % WS2812RGB_DEFAULT_BRIGHTNESS;
    for (uint8_t i = 1 ; i<9 ;i++){
        WS2812RGBLEDSet(randomRed, randomGreen, randomBlue);
    }
    WS2812RGBLED_RESET_CODE;
}


// Cylon green*2
void LEDUnSteadyMode10(void){
    // Count Up 
    for (uint8_t i = 1 ; i < 9 ;  i++ )
    {    
       WS2812RGBLEDSettwoPixel(i,i+1, 0,gWS2812RGBBrightness ,0) ;
       __delay_ms(200);
    }
    
    //count down
    for (int8_t j = 8 ; j > 0 ;  j-- )
    {   
       WS2812RGBLEDSettwoPixel((uint8_t)j,(uint8_t)j-1, 0, gWS2812RGBBrightness ,0) ;
       __delay_ms(200);
    }
    WS2812RGBLEDClearAll();
}



/** End of File */
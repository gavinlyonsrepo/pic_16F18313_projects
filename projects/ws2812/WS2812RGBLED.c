/* 
 * @file  WS2812RGBLED.c
 * @brief handles the ws2812 RGB LED string
 * @author Gavin Lyons
 */

// Section :: libraries
#include "mcc_generated_files/mcc.h"
#include "WS2812RGBLED.h"

uint8_t gWS2812RGBBrightness = WS2812RGB_DEFAULT_BRIGHTNESS;
bool gLEDunSteadyModeNumber = false; 


/*!
 @brief Init the Ws2812
 @note Most of the init is done in the MCC files
 */        
void WS2812RGBLEDInitialize(void){
    SSP1CON1bits.SSPEN = 1;
}

/*!
 @brief clear the  display up to a LED position
 @param EndPosition The last LED position to clear
 */  
void WS2812RGBLEDClear(uint8_t  EndPosition){
    
    for(uint8_t i = 0; i< EndPosition;i++)
    {
        WS2812RGBLEDSet(0,0,0);
    }
  WS2812RGBLED_RESET_CODE; // __delay_us(100);
}

/*!
 @brief Set one LED position
 @param Position The  LED position to set
 @param red Red brightness, 0-Max brightness
 @param green Green brightness, 0-Max brightness
 @param blue Blue brightness, 0-Max brightness
 */  
void WS2812RGBLEDSetPixel(uint8_t position, uint8_t red,uint8_t green,uint8_t blue)
{
    // (1) clear up to pixel position
    for(uint8_t i = 0; i < position-1 ;i++)
    {
        WS2812RGBLEDSet(0,0,0);
    }
    
    // (2) set the position 
     WS2812RGBLEDSet(red,green,blue);
    
    // (3) clear up to last LED 
    for(uint8_t j = position+1; j < WS2812RGB_LED_NUMBER+1 ;j++)
    {
        WS2812RGBLEDSet(0,0,0);
    }
    WS2812RGBLED_RESET_CODE;
}

/*!
 @brief Set two LED's position
 @param Position The LED position to set
 @param PositionTwo The 2nd LED position to set
 @param red Red brightness, 0-Max brightness
 @param green Green brightness, 0-Max brightness
 @param blue Blue brightness, 0-Max brightness
 */  
void WS2812RGBLEDSettwoPixel(uint8_t position, uint8_t positionTwo ,uint8_t red,uint8_t green,uint8_t blue)
{
    //clear up to position 1 
    for(uint8_t i = 0; i < position-1 ;i++)
    {
        WS2812RGBLEDSet(0,0,0);
    }
    // set LED 1 
     WS2812RGBLEDSet(red,green,blue);
     
     //clear up to position 2
     for(uint8_t i = position+1; i < positionTwo-1 ;i++)
     {
        WS2812RGBLEDSet(0,0,0);
     }
     //set LED 2
     WS2812RGBLEDSet(red,green,blue);
     //clear up to end 
    for(uint8_t j = positionTwo+1; j < WS2812RGB_LED_NUMBER+1 ;j++)
    {
        WS2812RGBLEDSet(0,0,0);
    }
    WS2812RGBLED_RESET_CODE;
}

/*!
 @brief clear all  the LEDs in display
 */  
void WS2812RGBLEDClearAll(void)
{
    for(uint8_t i = 1; i < WS2812RGB_LED_NUMBER +1; i++)
    {
        WS2812RGBLEDSet(0,0,0);
    }
  WS2812RGBLED_RESET_CODE; // __delay_us(100);
}

/*!
 @brief Set an LED
 @param red Red brightness, 0-Max brightness
 @param green Green brightness, 0-Max brightness
 @param blue Blue brightness, 0-Max brightness
 */ 
void WS2812RGBLEDSet(uint8_t red,uint8_t green,uint8_t blue){
    
    uint8_t GRBDataBuffer[3];
    
    GRBDataBuffer[0] = green;
    GRBDataBuffer[1] = red;
    GRBDataBuffer[2] = blue;
    SPI1_WriteBlock(GRBDataBuffer, sizeof(GRBDataBuffer));
}

/*!
 @brief Set all LED's
 @param red Red brightness, 0-Max brightness
 @param green Green brightness, 0-Max brightness
 @param blue Blue brightness, 0-Max brightness
 */ 
void WS2812RGBLEDSetAll(uint8_t red,uint8_t green,uint8_t blue){
    
    uint8_t GRBDataBuffer[WS2812RGB_LED_NUMBER*3];
    
    for (uint16_t i =0 ; i < WS2812RGB_LED_NUMBER ; i++ )
    {
        GRBDataBuffer[0 + (i*3) ] = green;
        GRBDataBuffer[1 + (i*3) ] =  red;
        GRBDataBuffer[2 + (i*3) ] =  blue;
    }
    // i = 0  0 1 2 i = 1  3 4 5 i = 2  6 7 8 etc  
    SPI1_WriteBlock(GRBDataBuffer, sizeof(GRBDataBuffer));
}
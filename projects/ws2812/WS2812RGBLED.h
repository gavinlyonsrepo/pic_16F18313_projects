/* 
 * @file  WS2812RGBLED.h
 * @brief handles the ws2812 RGB LED string
 * @author Gavin Lyons
 */

#ifndef WS2812RGBLED_H
#define	WS2812RGBLED_H

#ifdef	__cplusplus
extern "C" {
#endif

    
//  Section :: Macros 

#define WS2812RGBLED_RESET_CODE __delay_us(100) /**< The reset code > 50uS*/
#define WS2812RGB_LED_NUMBER 8    /**< Number of LEDS in string */
#define WS2812RGB_DEFAULT_BRIGHTNESS 20 /**< Default brightness, 0-255 */
#define WS2812RGB_MAX_BRIGHTNESS 200 /**< Max brightness, 0-255 */


#define WS2812RGB_DISPLAY_WHITE  WS2812RGBLEDSet(gWS2812RGBBrightness, gWS2812RGBBrightness , gWS2812RGBBrightness) // all on
#define WS2812RGB_DISPLAY_RED  WS2812RGBLEDSet(gWS2812RGBBrightness, 0 , 0)
#define WS2812RGB_DISPLAY_GREEN  WS2812RGBLEDSet(0, gWS2812RGBBrightness , 0)
#define WS2812RGB_DISPLAY_BLUE WS2812RGBLEDSet(0, 0 , gWS2812RGBBrightness)
#define WS2812RGB_DISPLAY_OFF  WS2812RGBLEDSet(0, 0 , 0)
#define WS2812RGB_DISPLAY_YELLOW  WS2812RGBLEDSet(gWS2812RGBBrightness, gWS2812RGBBrightness , 0) // Red + green on
#define WS2812RGB_DISPLAY_MAGNETA  WS2812RGBLEDSet(gWS2812RGBBrightness, 0 , gWS2812RGBBrightness) // red + blue on
#define WS2812RGB_DISPLAY_CYAN  WS2812RGBLEDSet(0, gWS2812RGBBrightness , gWS2812RGBBrightness) // Blue + green on

#define WS2812RGB_DISPLAY_WHITE_ALL  WS2812RGBLEDSetAll(gWS2812RGBBrightness, gWS2812RGBBrightness , gWS2812RGBBrightness) // all on
#define WS2812RGB_DISPLAY_RED_ALL  WS2812RGBLEDSetAll(gWS2812RGBBrightness, 0 , 0)
#define WS2812RGB_DISPLAY_GREEN_ALL  WS2812RGBLEDSetAll(0, gWS2812RGBBrightness , 0)
#define WS2812RGB_DISPLAY_BLUE_ALL WS2812RGBLEDSetAll(0, 0 , gWS2812RGBBrightness)
#define WS2812RGB_DISPLAY_OFF_ALL  WS2812RGBLEDSetAll(0, 0 , 0)
#define WS2812RGB_DISPLAY_YELLOW_ALL  WS2812RGBLEDSetAll(gWS2812RGBBrightness, gWS2812RGBBrightness , 0) // Red + green on
#define WS2812RGB_DISPLAY_MAGNETA_ALL  WS2812RGBLEDSetAll(gWS2812RGBBrightness, 0 , gWS2812RGBBrightness) // red + blue on
#define WS2812RGB_DISPLAY_CYAN_ALL  WS2812RGBLEDSetAll(0, gWS2812RGBBrightness , gWS2812RGBBrightness) // Blue + green on

// Section ::  Globals
extern uint8_t gWS2812RGBBrightness; /**< To hold current brightness*/
extern bool gLEDunSteadyModeNumber;/**< Flag to hold status of LEDUnsteadyMode, true for change, triggered every 5 seconds by timer 0 callback*/
       

// Section :: Function prototypes

void WS2812RGBLEDInitialize(void);
void WS2812RGBLEDClear(uint8_t ledPosition);
void WS2812RGBLEDClearAll(void);
void WS2812RGBLEDSet(uint8_t red,uint8_t green,uint8_t blue);
void WS2812RGBLEDSetPixel(uint8_t position, uint8_t red,uint8_t green,uint8_t blue);
void WS2812RGBLEDSettwoPixel(uint8_t position, uint8_t positionTwo ,uint8_t red,uint8_t green,uint8_t blue);
void WS2812RGBLEDSetAll(uint8_t red,uint8_t green,uint8_t blue);


#ifdef	__cplusplus
}
#endif

#endif	/* WS2812RGBLED_H */


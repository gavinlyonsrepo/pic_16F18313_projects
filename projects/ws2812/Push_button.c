#include "Push_button.h"
/* 
 * @file  Push_button.h
 * @brief handles the push button control
 * @author gavin lyons
 * @note requires timer on ~5mS tick to set gPushButton_X_Event flag's
 */

bool gPushButtonModeEvent= false; 
bool gPushButtonBrightnessEvent= false; 

/*!
 @brief Routine to de-bounce push button RA4
 Updated every tick by a timer interrupt.
 @return True if button pressed and de-bounced
 */
bool DebounceSwitchRA4(void)
{
    static uint16_t State = 0;
    State = (State <<1) | !BTN_RA4_GetValue() | 0xE000;
    if (State==0xF000)
        return true;
    else
        return false;
}

/*!
 @brief Routine to de-bounce push button RA2
 Updated every tick by a timer interrupt.
 @return True if button pressed and de-bounced
 */
bool DebounceSwitchRA2(void)
{
    static uint16_t State = 0;
    State = (State <<1) | !BTN_RA2_GetValue() | 0xE000;
    if (State==0xF000)
        return true;
    else
        return false;
}
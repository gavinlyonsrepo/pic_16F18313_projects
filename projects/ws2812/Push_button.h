/* 
 * @file  Push_button.h
 * @brief handles the push button control
 * @author gavin lyons
 * @note requires timer on ~5mS tick to set gPushButton_X_Event flag's
 *       Duration of tick will depend on pushbutton type can be varied
 */

#include "mcc_generated_files/mcc.h"

#ifndef PUSH_BUTTON_H
#define	PUSH_BUTTON_H

#ifdef	__cplusplus
extern "C" {
#endif

extern bool gPushButtonModeEvent; /**< Flag to hold status of RA4 push button, true for pressed*/
extern bool gPushButtonBrightnessEvent; /**< Flag to hold status of RA2 push button, true for pressed*/

bool DebounceSwitchRA4(void);
bool DebounceSwitchRA2(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PUSH_BUTTON_H */


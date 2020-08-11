
/* ====== Header =======
 * File: main.c 
 * Author: Gavin Lyons
 * IDE: MPLAB X v5.30
 * Compiler: xc8 v2.10
 * PIC: 16F18313 
 * Description: Ultrasonic sensor HC-SR04 + relay project see URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_16F18313_projects
 * Created on July 2020
 */

/* Libraries */
#include "mcc_generated_files/mcc.h"

uint16_t time_taken = 0;
uint16_t distance = 0;

/* Defines */

//NOTE: Fosc 12Mhz :Timer 1: Fosc/4 + 1:4 prescaler  : 65mS
//12mhz / 4 = 4/3,000,000 = .00000133 S
//Time calculation =  (1/(Fosc/4) * 4) 
//Time = (16-bit register value) * (1/Internal Clock) * (Pre-scale)
//Internal Clock = Fosc/4
//Time = (16-bit register value) * CALC_S

#define CALC_US 1.33 // time calculation in uSeconds
#define CALC_S .000001333 // time calculation in Seconds
#define SPEED 34000 //The speed of us wave (sound) is 34000cm/s.
#define TARGET 15 // distance to target in cm

#define ON_DELAY 5000  // The time the relay stays on after target detected in mS
#define INIT_DELAY 2000 // The delay before relay starts (set to 2<->60 Seconds) inmS
#define TRIGGER_DELAY 10 //The trigger delay in uS
#define HEART_BEAT_LED_DELAY 50 // Time Heartbeat delay comes on for in mS
#define TEST_DELAY 1000 // Time between tests optional,  in mS

#define MAX_DUTY_CYCLE 93 // Servo 10 % duty cycle closed position (Start)
#define MIN_DUTY_CYCLE 46 // Servo 5 % duty cycle open position

/* Function prototypes  */
void SetupPic(void);
void SensorRun(void);
void HeartBeat(void);

/* Main loop */
void main(void) {
    SetupPic();
    while (1) {
        SensorRun();
        }
    
}
/* End of Main */

/* Function Space */

/* Function to set up PIC */
void SetupPic(void) {
    SYSTEM_Initialize();
    PWM5_LoadDutyValue(MAX_DUTY_CYCLE); // servo to close
    LED_RA2_SetHigh();
    __delay_ms(INIT_DELAY);
    LED_RA2_SetLow();
}

/* Function run Sensor test */
void SensorRun(void)
{
        __delay_ms(TEST_DELAY);
        TMR1H = 0;
        TMR1L = 0; //clear the timer bits

        TRIGGER_RA1_SetHigh();
        __delay_us(TRIGGER_DELAY);
        TRIGGER_RA1_SetLow();

        while (ECHO_RA0_PORT == 0);
        TMR1_StartTimer();
        while (ECHO_RA0_PORT == 1);
        TMR1_StopTimer();

        time_taken = (TMR1_ReadTimer());
        distance = ((SPEED * CALC_S) * time_taken) / 2; //Distance = (Speed*Time)/2
        time_taken = time_taken * CALC_US; // time in uS
        
        
        if (distance < TARGET) {
            LED_RA2_SetHigh();
            PWM5_LoadDutyValue(MIN_DUTY_CYCLE); // servo to open
            __delay_ms(ON_DELAY);
            LED_RA2_SetLow();
            PWM5_LoadDutyValue(MAX_DUTY_CYCLE); // servo to close
        }
        HeartBeat();      
}

/*  Function to clear watch dog timer and blink the heartbeat LED*/
void HeartBeat(void)
{
 LED_RA5_SetHigh();
 __delay_ms(HEART_BEAT_LED_DELAY);   
 LED_RA5_SetLow();
 asm("CLRWDT");
}

/*   End of File  */

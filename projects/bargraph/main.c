
/* ====== Header =======
 * File: Battery level tester output to bargraph
 * Author: Gavin Lyons
 * IDE: MPLAB X v5.05
 * Compiler: xc8 v2.05
 * Description: see URL for full details.
 * URL: https://github.com/gavinlyonsrepo/pic_16F18313_projects
 * Created on 01 June 2019
 */

/* ======= Includes ========*/
#include "mcc_generated_files/mcc.h"

/* ======== Defines   ======== */
#define ADCRES 0.00331 // ADC  per volt = 3.39/1023, vcc/adc , 
#define SCLK_DELAY 50 //delay in uS for shift reg clock
#define RCLK_DELAY 500 //delay in uS for shift reg latch
#define INIT_DISPLAY_DELAY 500 //delay in mS during start-up routine

/* ======= Globals========*/
bool mode = false; //true for non-recharge, false for rechargeable(default)

/* ==== Function prototypes ===== */
void Setup(void);
void sclock(void);
void rclock(void);
void DataDisplay(uint8_t);
void ParseValue(uint16_t );
void ReadSwitch(void);
void DataDisplayInit(void);


/* ====== Main loop ======= */
void main(void)
{
    uint16_t ADC_value= 0;
    Setup();
    // First ADC pass and init delay and display, Found that ADC 
    // gave superious results on first pass and needed a delay.
    ADC_value=ADC_GetConversion(BATIN_ANA4)>>6; 
    ADC_value= 0;
    DataDisplayInit();
    
    while (1)
    {
        if (count == true) // count set to true by timer0 every ~two seconds
        {
            count = false;
            //ADC read
            ADC_value=ADC_GetConversion(BATIN_ANA4)>>6;
            //Read the switch
            ReadSwitch();
            //display value
            ParseValue(ADC_value);
        }
    }
}
/* ======== End of Main. =========  */

/* ====== Functions space ======= */

// Setup the PIC. 
void Setup(void)
{
    SYSTEM_Initialize();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    ReadSwitch();
}

//Parses data from ADC and calls DisplayData to set LED bargraph
void ParseValue(uint16_t ADC_value_1)
{
    
    char LEDControl[8] = {0xFF, 0xFD, 0xF9, 0xF1, 0xE1, 0xC1, 0xC0};
    float volt_value = (ADC_value_1*ADCRES); 
    //recharge 
    if (mode == false)
    {
        if (volt_value < 0.5)  
            DataDisplay(LEDControl[0]);
        else if (volt_value>0.5 && volt_value<=0.9)  
            DataDisplay(LEDControl[1]);
        else if (volt_value>0.9 & volt_value<=1.0)  
            DataDisplay(LEDControl[2]);
        else if (volt_value>1.0 && volt_value<=1.1)  
            DataDisplay(LEDControl[3]);
        else if (volt_value>1.1 && volt_value<=1.2) 
            DataDisplay(LEDControl[4]);
        else if (volt_value>1.2 && volt_value<=1.35)  
            DataDisplay(LEDControl[5]);
        else if (volt_value>= 1.35 )  
            DataDisplay(LEDControl[6]);
        
    }else if (mode == true)  //non-recharge
    {
        if (volt_value < 0.8)  
            DataDisplay(LEDControl[0]);
        else if (volt_value>0.81 && volt_value<=1)  
            DataDisplay(LEDControl[1]);
        else if (volt_value>1.0 & volt_value<=1.2)  
            DataDisplay(LEDControl[2]);
        else if (volt_value>1.2 && volt_value<=1.3)  
            DataDisplay(LEDControl[3]);
        else if (volt_value>1.3 && volt_value<=1.4) 
            DataDisplay(LEDControl[4]);
        else if (volt_value>1.4 && volt_value<=1.55)  
            DataDisplay(LEDControl[5]);
        else if (volt_value>= 1.55 )  
            DataDisplay(LEDControl[6]);
    }
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SCLK_595_SetHigh();
    __delay_us(SCLK_DELAY);
   SCLK_595_SetLow();
    __delay_us(SCLK_DELAY);
}

/* rclock:
 * This function will strobe/latch and enable the output trigger of 74HC595
 */
void rclock(void){
    RCLK_595_SetHigh();
    __delay_us(RCLK_DELAY);
    RCLK_595_SetLow();
    }

/* DataDisplay:
 * This function will send the data LSB to serial line 74HC9595
 */
void DataDisplay(uint8_t data){
    for (uint8_t i=0 ; i<8 ; i++){
         SER_595_LAT  = (data >> i) & 0x01; // bit shift and bit mask data. 
        sclock(); //enable data storage clock
    }
    rclock(); // Data latch
}

//  Checks Switch on RA3 defines if user is testing rechargeable or not.
void ReadSwitch(void)
{
    if ( Switch_RA3_PORT == 1) //rechargeable
    {
        mode = false;
        STATUSLED_RA5_SetHigh();
    }else //non- rechargeable
    {
        mode = true;
        STATUSLED_RA5_SetLow();
    }
        
}

// start-up routine displays a pattern on bar-graph
void DataDisplayInit(void)
{
    char LEDControlInit[8] = {0xFF, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF};
    for (uint8_t i=0 ; i<5 ; i++)
    {
        DataDisplay(LEDControlInit[i]);
        __delay_ms(INIT_DISPLAY_DELAY);
    }
    for (uint8_t i=5 ; i>0 ; i--)
    {
        DataDisplay(LEDControlInit[i]);
        __delay_ms(INIT_DISPLAY_DELAY);
    }
    DataDisplay(LEDControlInit[0]);
}

/* ==== End of File  ===== */

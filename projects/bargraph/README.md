
Overview
--------------------------------------------
* Name: bargraph
* Description: A program display AA/AAA battery level on a 
battery level indicator bar-graph LED display 3118BHG module 
using  a PIC 16F18313.
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)


Features
----------------------

A program display AA/AAA battery level on a 
battery level indicator bar-graph LED display 3118BHG module 
using a PIC 16F18313.

GPIO function on PIC

| Function  | 16F18313 pin |
| --- | --- |
| STATUS_LED  | RA5 |
| BAT_TEST_IN | RA4 |
| MODE_SWITCH | RA3 |
| SCLK 74HC595 | RA2 |
| RCLK 74HC595 | RA1 |
| SER 74HC595 | RA0 |

shift register to 3118BHG module

| 3118BHG LEDS | shift register pins |
| --- | --- |
| A |  pin 7 QH |
| B | pin 6 QG |
| C | pin 5 QF |
| D | pin 4 QE |
| E | pin 3 QD|
| F | pin 2 QC |


The system makes a new reading every two seconds on timer0 overflow interrupt.
Two modes defined by switch position.
The SPDT switch on RA3 is read, if it is logic high the unit is set to measure rechargeable,
if set to logic low, non-rechargeable AA/AAA batteries. The status LED(red) is turned on 
for rechargeable and off for non-rechargeable to indicate mode.
A shift register drives the LED 3118BHG module which has six outputs LEDs.
The more LED's the higher battery level.
The battery under test is connected to RA4 and is read using the ADC. 
The software currently assumes a Pic VCC of 3.35 this can be changed 
by changing a define. The data is fed to module LSB and because the 3118BHG
is common cathode it is flipped i.e. zero for LED on one for off.
See code for the voltage ranges applied to bargraph for both modes.

![ PIC ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/bargraph.jpg)

![ PIC2 ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/battery.jpg)

Schematic
------------------------

![ Sch ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/bargraphsch.png)

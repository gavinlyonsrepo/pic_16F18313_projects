Table of contents
---------------------------

  * [Overview](#overview)
  * [Hardware](#hardware)
  * [Software](#software)
  * [Notes](#notes)
 
Overview
--------------------------------------------
* Name: WS2812

* Description: 

A project to drive a string of Neopixel Ws2812 LEDs with a PIC 16F18313.
In this case an 8 LED bar strip.

* Author: Gavin Lyons.

Hardware
----------------------

NeoPixel WS2812 8 LED Bar Strip.

 ![image PIC](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/wseight.jpg)
 
Schematic:

![Schematic ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/ws2812.png)

A push button on RA4 sets the display mode, 1-18 modes.
Another push button on RA2 sets the brightness, 0-200 in steps of 20.
RA5 is connected to Data in pin of 8-LED WS2812 string bar. VCC = 5 volts.

Measured current consumption of unit.

| Color | Brightness | Current | Leds on |
| ---  | --- | ---  |  --- |
| Red  | 20 | 17mA | 8 |
| Red | 200 | 81mA | 8 |
| White | 20 | 32mA | 8 |
| White	| 200 | 220mA | 8 |

Software
------------------------

There is a custom library for the WS2812 and another for the push buttons. 
Timer0's interrupt is used for push button de-bouncing and programming timing.

Timer 2, PWM5 and the SPI bus are used as inputs to the CLC(Configurable Logic Cell)
The Ws2818 requires a near continuous stream of 24-bit data packets, Driving an I/O pin in 
software could create this serial protocol,
but this creates problems, 100% of the CPU is used for the entire duration
of the LED string update. So we can offload the work to the SPI/CLC to  create a custom serial
communications to transmit entire bytes in the correct format & free up the CPU for other tasks.
See Link to AN1606 in notes for more details.

CLC logic 

 ![ CLC ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/wsclc.jpg)

Scope capture of DIn pin of ws2812. Shows the start sequence to set first LED in strip green. A 24 bit stream. First byte green, 2nd red, 3rd blue. Brightness = 20 for green, 0 for blue &  red. Wide pulse = 1 , narrow pulse = 0.

 ![ scope ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/wsscope.jpg)


Notes
-----------------------------------

1. The configuration of the CLC is based on *Microchip* Application note, AN1606.
See [Link](http://ww1.microchip.com/downloads/en/AppNotes/00001606A.pdf)

2. This PIC has limited memory. recommend a larger memory PIC for more advanced LED patterns
and display modes. This small program already takes up 26.2% of data memory and 82.0% of Program memory


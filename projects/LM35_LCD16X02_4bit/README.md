
Overview
--------------------------------------------
* Name: LCD_LM35
* Description: A program to read an LM35 temperature sensor and display it on an 
HD44780 16X2 LCD, with a PIC 12F675.
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)


Features
----------------------

In this folder the source code in C.

**LM35 sensor** 

The LM35 outputs a signal on pin Vout
The LM35 is read via an analog input(RA5) 10mV per degree.
The ADC 10-bit resolution for 5V / 2^10 = 5/1024 = 0.004883.

LM35 calculation:

1. Vout=0.01/°C
2. °C=Vout/0.01
3. °C=Vout*100
4. Vout = ADC_value * (VCC/ADC resolution)
5. °C = (ADC_value * (5/1024)) * 100 
6. °C * 100  =(ADC_value * (5/1024)) * 10000 (turn 0.004883 into 49 to avoid using float)
7.  °C * 100 = 1953 (Solved for an ADC value  of 40) 19.53°C
8. The RHS can then be parsed by code and displayed. 

**74HC595 Shift register**

The LCD is driven using a Shift register 74HC595. 

GPIO PORTC function on PIC, 3 lines to 74HC595

| 74HC595 pin  | Pic 16F1619 pin |
| ------ | ------ |
| SER  14 serial data | RA0 |
| SCLK 11 Storage | RA1 |
| RCLK 12 Latch | RA2 |


**HD44780-based character LCD**

HD44780 based character LCD displays use 14 wire connections: 8 data lines (D0-D7), 3 control lines (RS, E, R/W), and three power lines (Vdd, Vss, Vee). Some LCDs come with backlight features that help reading display data in low illumination conditions. They have two additional connections (LED+ and LED- or A and K).

The control pin RS determines if the data transfer between the LCD module and an external microcontroller are actual character data or command/status. The enable pin (E) initiates the actual data transfer. When writing to the LCD display, the data is transferred only on the high to low transition of the E pin.
Read/Write(RW): This signal is used to write the data/cmd to LCD and reads the busy flag of LCD. For write operation the RW should be LOW and for read operation the R/W should be HIGH.

The Vdd pin (2) should be connected to the positive power supply and Vss (1) to ground. Pin 3 (Vee) is for display contrast adjustment.

Pins 7 to 14 are data lines (D0-D7). Data transfer to and from the display can be achieved either in 8-bit or 4-bit mode. The 8-bit mode uses all eight data lines to transfer a byte, whereas, in 4-bit mode, a byte is transferred as two 4-bit nibbles. In the later case, only the upper 4 data lines (D4-D7) are used. This technique is beneficial as this saves some input/output pins of microcontroller. This example uses 4-bit mode.

![pinout](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/LCD.jpg)


Schematic
------------------------

TODO


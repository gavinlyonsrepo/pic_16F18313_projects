
Overview
--------------------------------------------
* Name: Countdown
* Description: A program to simulate a countdown timer 
and display result on TM1637 based LED segment module with a PIC 16F18313.
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)


Features
----------------------

A countdown timer with a range of 0-99 minutes and a display in minutes and seconds
input from a potentiometer and pushbutton. Output to a buzzer and TM1637
4 digit seven segment module. 


*TM1637*

This folder contains the source code in C (xc8).
The code for TM1637 is in its own library files.
This library is a fork of the Arduino library ATMega328 by "avishorp".
I forked it then converted it from C++ to C and modified it for PIC micro-controller.

These modules have 4 pins, 2 control lines(data and clock) + power. They have a 
4 digit seven segment display(3462BS) and a tm1637 control chip.
These modules are widely available. 
2 pins are connected from  PIC to the data and clock line of the module.
Thus allowing control of a 4 digit seven segment module with just two GPIO lines.

GPIO function on PIC, 2 lines to Tm1637 Module.

| Module pin  | Pic 16F18313 pin |
| --- | --- |
| DIO  | RA0 |
| CLK  | RA1 |

![PICTURE](https://github.com/gavinlyonsrepo/pic_16F1619_projects/blob/master/images/tm1637.jpg)

The pot is connected to RA4 and is read using the ADC. The push button to RA2
is read on a hardware interrupt. Timer0 is used to keep time. Timer2 is used
to run a PWM signal out of  RA5 to drive the output passive buzzer.

The Unit current consumption :

| current consumption   | brightness setting |
| --- | --- |
| 15mA  | 0x02 |
| 25mA  | 0x04 |

Schematic
------------------------

![Schematic PIC](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/countdown.png)

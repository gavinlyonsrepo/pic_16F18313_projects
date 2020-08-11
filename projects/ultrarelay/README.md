
Overview
--------------------------------------------
* Name: Ultra sonic relay
* Description: A program to monitor an ultra sonic sensor HC-SR04, if a target is seen 
A relay module is switched on , uses  a PIC 16F18313. Can be used as basis for automated hand sanitiser
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------
A program to monitor an ultra sonic sensor HC-SR04 if a target is seen 
A relay module is switched on , uses  a PIC 16F18313.
There is another [version](https://github.com/gavinlyonsrepo/pic_16F18313_projects) of this program which uses a servo.
GPIO function on PIC

| Function  | 16F18313 pin |
| --- | --- |
| Heartbeat LED  | RA5 |
| Status LED | RA2 |
| Reset pushbutton | RA3 |
| RELAY module signal | RA4 |
| TRIGGER HC SR04  | RA1 |
| ECHO  HC SR04| RA0 |

The status LED comes on for start-up delay and when 
target is detected. The heart beat LED briefly flashes as watchdog is reset.
The watchdog timer will reset the PIC if the software or hardware hangs up or gets stuck.
It needs to be reset every minute by software. 

**HC SR-04**

The HC-SR04 is an ultrasonic sensor which can be used to measure distance anywhere between 2cm to 450cm. The transmitter emits an US wave at a frequency of 40Hz, this wave travels through the air and gets reflected back when it senses an object. The returning waves are observed by the receiver. Now we know the time taken for this wave to get reflected and come back and the speed of the US wave is also universal (3400cm/s). Using this information and the below high school formulae we can calculate the distance covered. We trigger the sensor then measure the echo. We use timer 1 for this.

Time = (16-bit register value) * (1/Internal Clock) * (Pre-scale), Internal Clock = Fosc/4,
Where in our case, Fosc = 16000000Mhz and Pre-scale = 4,
Hence the value of Internal Clock will be 4000000Mhz and the value of time will be:

1. Time = (16-bit register value) * (1/4000000) * (4)
2. Time  = (16-bit register value) * (4/4000000)
3. Time = (16-bit register value) * 0.000001 seconds (OR)
4. Time = (16-bit register value) * 1 micro seconds

Next we have to find how to calculate the distance. As we know distance = speed * time. But here the result should be divided by 2 since the wave is covering both the transmitting distance and receiving distance. The speed of us wave (sound) is 34000cm/s.

1. Distance = (Speed*Time)/2
2. Distance  = (34000 * (16-bit register value) * 0.000001) /2
3. Distance = (0.034 * 16-bit register value)/2


![ PIC ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/hcsr04.jpg)


**RELAY keyes SR1y module**

If target is detected the relay is turned on for a period 
In this example we use a keys SR1y relay module.
A schematic of this relay can be found [here](https://github.com/gavinlyonsrepo/pic_12F675_projects/tree/master/projects/PIR_alarm) 

![ PIC2](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/keyessr1y.jpg)


Schematic
------------------------

![ Sch ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/hcschr.jpg)

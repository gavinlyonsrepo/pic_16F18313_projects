
Overview
--------------------------------------------
* Name: Ultra sonic Servo
* Description: A program to monitor an ultra sonic sensor HC-SR04, if a target is seen 
A servo is moved , uses  a PIC 16F18313. Can be used as basis for automated hand sanitiser
* Author: Gavin Lyons.

Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)

Features
----------------------
A program to monitor an ultra sonic sensor HC-SR04 if a target is seen 
A servo is moved , uses  a PIC 16F18313. 
There is another [version](https://github.com/gavinlyonsrepo/pic_16F18313_projects) of this program which uses a relay.

GPIO function on PIC

| Function  | 16F18313 pin |
| --- | --- |
| Heartbeat LED  | RA5 |
| Status LED | RA2 |
| Reset pushbutton | RA3 |
| Servo signal | RA4 |
| TRIGGER HC SR04  | RA1 |
| ECHO  HC SR04| RA0 |

The status LED comes on for start-up delay and when 
target is detected. The heart beat LED briefly flashes as watchdog timer is reset.
The watchdog timer will reset the PIC if the software or hardware hangs up or gets stuck.
It needs to be reset every minute by software. 

**HC SR-04**

The HC-SR04 is an ultrasonic sensor which can be used to measure distance anywhere between 2cm to 450cm. The transmitter emits an US wave at a frequency of 40Hz, this wave travels through the air and gets reflected back when it senses an object. The returning waves are observed by the receiver. Now we know the time taken for this wave to get reflected and come back and the speed of the US wave is also universal (3400cm/s). Using this information and the below high school formulae we can calculate the distance covered. We trigger the sensor then measure the echo. We use timer 1 to calculate size of pulse.

Time = (16-bit register value) * (1/Internal Clock) * (Pre-scale), Internal Clock = Fosc/4,
Where in our case, Fosc = 12000000Mhz and clock divider = 4,
Hence the value of Internal Clock will be 4000000Mhz and the value of time will be:

1. Time = (16-bit register value) * (1/3000000) * (4)
2. Time  = (16-bit register value) * (4/3000000)
3. Time = (16-bit register value) * 0.000001333 seconds (OR)
4. Time = (16-bit register value) * 1.3333 micro seconds

Next we have to find how to calculate the distance. As we know distance = speed * time. But here the result should be divided by 2 since the wave is covering both the transmitting distance and receiving distance. The speed of us wave (sound) is 34000cm/s.

1. Distance = (Speed*Time)/2
2. Distance  = (34000 * (16-bit register value) * 0.000001.333) /2
3. Distance = (0.0453 * 16-bit register value)/2


![ PIC ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/hcsr04.jpg)


**Servo**

If target is detected the servo is moved for a period.
Max duty cycle ~10% is issued for "closed" postion.
Min duty cycle ~5%is issued for "open" postion. 
From the data sheet , we see these servos expects a frequency of 50 Hz 
on the control line and the position it moves to depends on the pulse width of the signal.
50Hz gives a period of 20mS (Freq = 1/Period).
Timer 2 and PWM module 5 is used to control this on pin RA4.

![ScreenShot servo](https://github.com/gavinlyonsrepo/RpiMotorLib/blob/master/images/sg90.jpg)

Schematic
------------------------


![ Sch ](https://github.com/gavinlyonsrepo/pic_16F18313_projects/blob/master/images/hcschr2.jpg)

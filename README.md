# Step-tracker
Project created for Wireless and mobile networks' course from universitá degli studi di Milano

## Explanation of the project
The system consists in collecting data provided by sensors and send it to microcontroller for process it. Then, the data is sent to laptop, where data is graphically showed by one graphic interface, doing a simulation like a wearable.
Devices could be divided in three parts:
> -	Microcontroller: Takes the processing of sensors’ data. The microcontroller selected is MSP430G2553 TI launchpad.
>
> -	Sensors:
>
>	o	TSL2561: A luminosity sensor. Takes the measure of ambient light and send the data to microcontroller.
>
>	o	MMA8451: An accelerometer. Takes the measure of amount of acceleration given and send the data to microcontroller.
>
> -	Laptop: Receive the data, shows it in a graphic interface, and program the microcontroller to do a correct processing.

The connection between devices are different. There are two kinds of protocols:
> -	UART: allow data transmission between microcontroller and laptop. The microcontroller sends the data and laptop receive it.
> -	I2C: allow communication between sensors and microcontroller. Microcontroller ask for the data and sensors replies with it. 
The aim of the project consists in develop a low-power system able to guide people in closed areas.

## How to use:

>1) Connect MSP430G2553 to PC.
>2) Load "ProcessingSensors" folder on the device with CCS (import-> CCS Project->...). 
>3) Open Qt Creator.
>4) Load "Interface" folder on QT Creator.
>5) Press Play.
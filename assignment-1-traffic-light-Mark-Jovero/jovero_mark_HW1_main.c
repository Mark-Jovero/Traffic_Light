/**************************************************************
* Class:  CSC-615
* Name:	  Mark Jovero	
* Student ID:	916691664
* Project:	Assignment 1 - Traffic Light
*
* File: mark_jovero_HW1_main.c
*
* Description: Main method for traffic light.
*
**************************************************************/
#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include "assignment1wpi.h"
#include "assignment1b.h"

int main(int argc, char *argv[]) {
	
	
	printf("\nBeginning wiringPi version...\n");
	wpi_set_pins(0, 2, 3);

	for (int i = 0; i < 3; i++) {
		
		set_green(6000);
		set_yellow(1500);
		set_red(5000);
		
	}
	
	
	wpi_reset_leds();
	
	sleep(1);
	
	printf("\nBeginning sysfs version...\n");
	
	
	configureLights(17, 27, 22);
	
	for (int i = 0; i < 3; i++) {
		startLights();
	}
	
	resetGPIO();
	
	printf("Finished!\n");
	
	return 0;
}


/**************************************************************
* Class:  CSC-615
* Name:	  Mark Jovero	
* Student ID:	916691664
* Project:	Assignment 1 - Traffic Light
*
* File: assignment1b.c
*
* Description: Functions to control traffic light using sysfs
*	** WITH HEAVY INSPIRATION FROM https://elinux.org/RPi_GPIO_Code_Samples#sysfs **
*
**************************************************************/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "assignment1b.h"

int GPIOExport(int pin);
int GPIOUnexport(int pin);
int GPIORead(int pin);
int GPIOWrite(int pin, int value);

int red, yellow, green;


/**
Configures the pin to take in values.
Args:
	int pin: pin number to configure
Return:
	0: Success
	-1: Error
**/
int GPIOExport(int pin) {
	char * buffer = malloc(sizeof(int) * 2);
	int fd = open("/sys/class/gpio/export", O_WRONLY);
	if (-1 == fd) {
		printf("Error opening file.\n");
		return -1;
	}

	sprintf(buffer, "%d", pin);
	write(fd, buffer, 4); // Write to file to indicate pin for use
	close(fd);
	free(buffer);
	return 0;
}


/**
Removes pin, no longer take in values.
Args:
	int pin: pin number to configure
Return:
	0: Success
	-1: Error
**/
int GPIOUnexport(int pin) {
	char * buffer = malloc(sizeof(int) * 2);
	int fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (-1 == fd) {
		printf("Error opening file.\n");
		return -1;
	}

	sprintf(buffer, "%d", pin);
	write(fd, buffer, 2); // Write to file to indicate no more use of pin
	close(fd);
	free(buffer);
	return 0;
}


/**
Reads the value of a pin.
Args:
	int pin: pin number to read from.
Return:
	>=0: value of pin
	-1: Error
**/
int GPIORead(int pin) {
	char * path = malloc(sizeof(char) * 30);
	char * buffer = malloc(sizeof(int) * 2);
	int value;

	sprintf(path, "/sys/class/gpio/gpio%d/value", pin);
	int fd = open(path, O_RDONLY);
	if (-1 == fd) {
		printf("Error opening file.\n");
		return -1;
	}

	read(fd, buffer, 3);

	close(fd);
	value = atoi(buffer);
	free(buffer);
	return value;
}


/**
Writes to a pin's file.
Args:
	int pin: pin number to write to
	int value: 0 or 1
Return:
	0: Success
	-1: Error
**/
int GPIOWrite(int pin, int value) {

	char * path = malloc(sizeof(char) * 30);
	char * buffer = malloc(sizeof(char));
	int fd;

	sprintf(path, "/sys/class/gpio/gpio%d/value", pin);
	sprintf(buffer, "%d", value);
	
	fd = open(path, O_WRONLY);
	
	if (-1 == fd) {
		printf("Failed to open gpio value for writing!\n");
		return -1;
	}
	
	int s = write(fd, buffer, sizeof(char));
	close(fd);
	free(path);
	free(buffer);
	return 0;
}


/**
Sets the pins to be used for each light to OUTPUT mode
Args:
	int red_pin: the pin number for red pin
	int yellow_pin: "" yellow pin
	int green_pin: "" green pin
Return: VOID
**/
void configureLights(int red_pin, int yellow_pin, int green_pin) {	
	red = red_pin;
	yellow = yellow_pin;
	green = green_pin;
	
	GPIOExport(red_pin);
	GPIOExport(yellow_pin);
	GPIOExport(green_pin);
}


/**
Starts the light sequence.
Return: VOID
**/
void startLights() {
	GPIOWrite(green, 1);
	sleep(6);
	GPIOWrite(green, 0);
	GPIOWrite(yellow, 1);
	sleep(1.5);
	GPIOWrite(yellow, 0);
	GPIOWrite(red, 1);
	sleep(5);
	GPIOWrite(red, 0);
}


/**
Resets the lights to all off and removes config.
Return: VOID
**/
void resetGPIO() {
	GPIOWrite(red, 0);
	GPIOWrite(yellow, 0);
	GPIOWrite(green, 0);
	
	GPIOUnexport(red);
	GPIOUnexport(yellow);
	GPIOUnexport(green);
}
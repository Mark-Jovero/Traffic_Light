/**************************************************************
* Class:  CSC-615
* Name:	  Mark Jovero	
* Student ID:	916691664
* Project:	Assignment 1 - Traffic Light
*
* File: assignment1wpi.c
*
* Description: Functions to control traffic light using wiringPi
*
**************************************************************/
#include <stdio.h>
#include <wiringPi.h>
#include "assignment1wpi.h"

int red, yellow, green;

/**
Sets the pins to be used for each light to OUTPUT mode
Args:
	int r_pin: the pin number for red pin
	int y_pin: "" yellow pin
	int g_pin: "" green pin
Return: VOID
**/
void wpi_set_pins(int r_pin, int y_pin, int g_pin) {
	
	wiringPiSetup();
	
	red = r_pin;
	yellow = y_pin;
	green = g_pin;
	
	pinMode(r_pin, OUTPUT); // red
	pinMode(y_pin, OUTPUT); // yellow
	pinMode(g_pin, OUTPUT); // green
}


/**
Resets the LEDs to off
**/
void wpi_reset_leds() {
	digitalWrite(red, LOW);
	digitalWrite(yellow, LOW);
	digitalWrite(green, LOW);
}


/**
Sets the red light to on for millis_length
Args:
	int millis_length:
		-1: on indefinitely
		>0: on for x milliseconds
Return: VOID
**/
void set_red(int millis_length) {
	
	digitalWrite(red, HIGH);
	
	// set delay
	if (millis_length > -1)
		delay(millis_length);
	else // forever
		return;
	
	digitalWrite(red, LOW);
}


/**
Sets the yellow light to on for millis_length
Args:
	int millis_length:
		-1: on indefinitely
		>0: on for x milliseconds
Return: VOID
**/
void set_yellow(int millis_length) {
	
	digitalWrite(yellow, HIGH);
	
	// set delay
	if (millis_length > -1)
		delay(millis_length);
	else // forever
		return;
	
	digitalWrite(yellow, LOW);
}


/**
Sets the green light to on for millis_length
Args:
	int millis_length:
		-1: on indefinitely
		>0: on for x milliseconds
Return: VOID
**/
void set_green(int millis_length) {
	
	digitalWrite(green, HIGH);
	
	// set delay
	if (millis_length > -1)
		delay(millis_length);
	else // forever
		return;
	
	digitalWrite(green, LOW);
}

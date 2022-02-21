/**************************************************************
* Class:  CSC-615
* Name:	  Mark Jovero	
* Student ID:	916691664
* Project:	Assignment 1 - Traffic Light
*
* File: assignment1wpi.h
*
* Description: Functions to control traffic light using wiringPi
*
**************************************************************/

void wpi_set_pins(int r_pin, int y_pin, int g_pin);
void wpi_reset_leds();

void set_red(int millis_length);
void set_yellow(int millis_length);
void set_green(int millis_length);
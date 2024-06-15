# Binary-Clock
The binary clock represents time in binary format, with each LED corresponding to a bit. It uses three columns for hours, minutes, and seconds, each split into two 4-bit groups for the digits. LEDs light up according to the current time's binary representation.

Description
The Clock Display Program is written in C and utilizes the Sense HAT library to interact with the LED display. It converts the current time into binary representation and displays it on the LED matrix.


Compile the program:

->make
Usage:
To run the Clock Display Program, execute the following command:


->make run:
This will compile the program and execute the clock.sh script, which continuously updates the display with the current time.

Files
main.c: Contains the main function and orchestrates the display of time.
display.c and display.h: Implement the functions to display the time in binary format on the Sense HAT LED display.
clock.sh: Shell script to run the program and continuously update the display.

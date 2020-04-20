/*	Author: hlee272
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States {Start, wait0, pressPB0, wait1, pressPB1} state;
void Tick();

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRB = 0xFF; PORTB = 0x01; //output	
	state = Start;    
 /* Insert your solution below */
    while (1) {
	Tick();
    }
}
void Tick() {
	switch(state) {//transistions

	case Start:
	PORTB = 0x01;
	state = wait0; 
	break; 

	case wait0: 
	if ((PINA & 0x01) == 0x01) {
		state = pressPB0; 
	}
	else {
		state = wait0; 

	}
	break;

	case pressPB0: 
	if ((PINA & 0x01) == 0x01) {
		state = pressPB0;
	}
	else {
		state = wait1; 
	}
	break;
	
	case wait1: 
	if ((PINA & 0x01) == 0x01) { 
		state = pressPB1;
	}	
	else {
		state = wait1;
	}
	break;
	
	case pressPB1: 
	if ((PINA & 0x01) == 0x01) {
		state = pressPB1; 
	}
	else {
		state = wait0;
	}
	break;

	default: 
	state = Start;
	break; 
}

switch (state) //state actions
{
case Start: 
break;

case wait0:
PORTB = 0x01;
break;

case pressPB0:
PORTB = 0x02;
break;

case wait1: 
PORTB = 0x02;
break;

case pressPB1: 
PORTB = 0x01;
break;

default: 
break;
	}
  
}

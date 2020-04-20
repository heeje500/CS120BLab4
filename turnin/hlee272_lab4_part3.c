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
enum States {Start, init, pound, pound2, wait, y, y2, lock} state;
void Tick();

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRB = 0xFF; PORTB = 0x00;	
	state = Start;    
 /* Insert your solution below */
    while (1) {
	Tick();
    }
}
void Tick() {
	switch(state) {//transistions

	case Start:
	state = init; 
	break; 

	case init: 
	if (PINA == 0x80) {
		state = lock; 
	}
	
	else if (PINA == 0x04) {
		state = pound2;

	}

	else {
		state = init;
	}
	break;

	case pound2:
	if (PINA == 0x00) {
		state = y2;
	}
	else {
		state = pound2;
	}
	break; 
	
	case y2: 
	if (PINA == 0x02) {
		state = pound;
	}
	else if (PINA == 0x00) {
		state = y2;
	}
	else {
		state = wait;
	}
	break;

	case wait:
	if (PINA == 0x00) {
		state = init;
	}
	else {
		state = wait;
	}
	break; 

	case pound:
	if(PINA == 0x00) {
		state = y;
	}
	else if (PINA == 0x80) {
		state = lock;
	}
	else {
		state = pound;
	}
	PORTB = 0x01;
	break;
	
	case y: 
	state = init;
	break;

	case lock: 
	if (PINA == 0x00) {
		state = init;
	}
	else { 
		state = lock;
	}
	break;
  
	default: 
	state = Start;
	break; 
}

switch (state) //state actions
{
case Start: 
PORTB = 0x00;
break;

case init:
break;

case pound2:
break;

case pound:
PORTB = 0x01;
break;

case y2:
break;

case y:
break;

case lock: 
PORTB = 0x00;
break;

default: 
break;
	}
  
}

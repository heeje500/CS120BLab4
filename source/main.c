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
enum States {Start, init, x, y, pound, wait, wait2, unlock, lock} state;
void Tick();

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRB = 0xFF; PORTB = 0x02;
	DDRC = 0xFF; PORTC = 0x00; //output	
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
	if ((PINA & 0x07) == 0x01) {
		state = x; 
	}
	
	else if ((PINA & 0x07) == 0x02) {
		state = y;

	}

	else if ((PINA & 0x07) == 0x04) {
		state = pound;
	}
	
	else {
		state = init;
	} 
	break;

	case x: 
	state = lock;
	break;
	
	case y: 
	state = wait2;
	break;
	
	case pound: 
	state = wait;
	break;

	case wait: 
	if ((PINA & 0x07) == 0x02) {
		state = y;
	}
	else if ((~PINA & 0x07) == 0x02) {
		state = lock;
	}

	else {
		state = init;
	}
	break;

	
	case wait2: 
	if ((~PINA
	break;

	default: 
	state = Start;
	break; 
}

switch (state) //state actions
{
case Start: 
break;

case init:
PORTC = 0x07;
break;

case inc:
if (PORTC >= 0x09) { 
PORTC = 0x09;
}

else {
PORTC = PORTC + 0x01;
}
break;

case dec: 
if (PORTC <= 0x00) {
PORTC = 0x00;
}

else {
PORTC = PORTC - 0x01;
}
break;

case zero: 
PORTC = 0x00;
break;

default: 
break;
	}
  
}

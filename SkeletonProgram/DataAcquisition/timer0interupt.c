/*
 * timer0interupt.c
 *
 * Created: Sep. 2023, Bochert
 *
 * Routines for the timer 0 for interrupt generation.
 * The interrupt service routine at TIMER0_COMP_vect will be called up.
 */

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "timer0interupt.h"

void StartTimer0Interrupt(void)
/*
The timer 0 is initialized to generate an interrupt every 15 ms.
*/
{
  OCR0 = 156;			// 10 ms period
  TCNT0 = 0;			// counter reset
  TCCR0 = 0B10101101;	// start timer with prescaler of 1024 in clear timer on compare match mode (CTC)
  TIMSK |= (1<<OCIE0);	// timer 0 output compare match interrupt enable
}

void StopTimer0Interrupt(void)
/*
The timer 0 is stopped and the interrupt is disabled.
*/
{
  TCCR0 = 0B00000000;	// disable timer 0 
  TIMSK &= ~(1<<OCIE0);	// disable timer 0 interrupt
}

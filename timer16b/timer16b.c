/*
 * timer16b.c
 *
 * Created: 02.07.2021 11:12:12
 * Author : Oleg
 */ 

#include "timer16b.h"
uint16_t timer_value;
void set_mode(uint16_t value)
{
	if(value==1)
	{
		//setting reset on comparing
		TCCR1B |= (1<<WGM12);
	}
	else
	{
		//setting normal mode
		TCCR1B |= (0<<WGM12);
	}
}
void timer_initialisation(void)
{
	set_mode(1);
	//setting bit for allow interruption on comparing
	TIMSK |= (1<<OCIE1A);
	//set the number for timer
	OCR1AH = 0b00111110;
	OCR1AL = 0b10000000;
	sei();
	timer_value=0;
}

ISR(TIMER1_COMPA_vect)
{
	timer_value++;
	if (timer_value>=1000)
	{
		timer_value=0;
	}
}

void set_value(uint16_t value)
{
	timer_value = value;
}
uint16_t get_value()
{
	return timer_value;
}
void timer_start(void)
{
	//starting timer setting no prescaling
	TCCR1B |= (1<<CS10);
}
void timer_stop(void)
{
	//stopping timer
	TCCR1B |= (0<<CS10);
}
void timer_reinitialisation()
{
	timer_stop();
	set_value(0);
	timer_initialisation();
	timer_value=0;
}
void timer_deinitialisation()
{
	set_value(0);
	TCCR1B |= (0<<WGM12);
	TIMSK |= (0<<OCIE1A);
	OCR1AH = 0b00000000;
	OCR1AL = 0b00000000;
	timer_value=0;
}



/*
 * timer16b.h
 *
 * Created: 02.07.2021 13:46:05
 *  Author: Oleg
 */ 

#ifndef TIMER16B_H_
#define TIMER16B_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

//initialisation function
void timer_initialisation(void);
//function for setting mode(0 - Normal, 1 - CTC)
void set_mode(uint16_t value);
//function for setting value to timer
void set_value(uint16_t value);
//function for getting value from timer
uint16_t get_value();
//function for starting the timer
void timer_start(void);
//function for stopping the timer
void timer_stop(void);
//reinitialisation function
void timer_reinitialisation();
//deinitialisation function
void timer_deinitialisation();

#endif
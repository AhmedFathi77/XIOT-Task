/*
 * Timer.h
 *
 *  Created on: Jun 29, 2018
 *      Author: leenovoz510
 */

#ifndef TIMER_H_
#define TIMER_H_

#define F_CPU 1000000UL
#define T_Timer 1UL/F_CPU
#define T_overflow 256*T_Timer 				//8 bit timer -- for 1M freq T_overflow = 256 msec
// we need timer to overflow 2 times to get a 0.5 second
#define num_sec 3							// number of required seconds
#define num_overflow 4*num_sec	//	max number of overflows



void Overflow_TIMER0_Init();

#endif /* TIMER_H_ */

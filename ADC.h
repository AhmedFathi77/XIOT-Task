/*
 * ADC.h
 *
 *  Created on: Jun 29, 2018
 *      Author: leenovoz510
 */

#ifndef ADC_H_
#define ADC_H_
volatile int ADC_Value;
#define ADCH    _SFR_IO8(0x05)
void ADC_Init();
int  ADC_Result(unsigned char channel);
void Terminl_IntegerToStringPrint(int num);
#endif /* ADC_H_ */

/**
 * @file activity2.c
 * @author Kajal (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "activity2.h"

uint16_t ReadADC(uint8_t ch)
{
    ADMUX& = 0xf8;
    ch = ch&0b00000111;
    ADMUX|= ch;
    ADCSRA|= (1<<ADSC);

    while(!(ADCSRA & (1<< ADIF)));
    ADCSRA|= (1<<ADIF);
    return(ADC);
}

void InitADC()
{
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
}
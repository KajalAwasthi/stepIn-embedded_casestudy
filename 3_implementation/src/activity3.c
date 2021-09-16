/**
 * @file activity3.c
 * @author Kajal (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<util/delay.h>
#include<avr/io.h>
#include"activity3.h"

void InitPWM(void)
{
    TCCR1A|=(1<<COM1A1)|(1<<WGM10)|(1<<WGM11);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB|=(1<<PB1);
}

char OutPWM (uint16_t ADC_val)
{
    char temp;
    if((ADC_val>=0) && (ADC_val<=209))
    {
        OCR1A = 205; 
        temp = 20;
        _delay_ms(15);
    }
    else if((ADC_val>=210) && (ADC_val<=509))
    {
        OCR1A = 410; 
        temp = 25;
       _delay_ms(15);
    }
    else if((ADC_val>=510) && (ADC_val<=709))
    {
        OCR1A = 717;
        temp = 29;
        _delay_ms(15);
    }
    else if((ADC_val>=710) && (ADC_val<=1024)){

        OCR1A = 973;
        temp = 33;
        _delay_ms(15);
    }
    else
    {
        OCR1A = 0;
        temp = 0;
    }
    return temp;
}
/**
 * @file activity1.c
 * @author Kajal (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "activity1.h"

void ledstat(unit8_t state)
{
    LED_PORT = (state << LED_PIN);
}
void InitLED(void)
{
    DDRB|= (1<<PB0);
    DDRD&= ~(1<<PD1);
    PORTD|= (1<<PD1);
    PORTD|= (1<<PD2);
}
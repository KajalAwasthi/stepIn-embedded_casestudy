/**
 * @file activity1.h
 * @author Kajal (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _activity1_h_
#define _activity1_h_

#include <avr/io.h>
#include "activity1.h"

#define LEDOFF  (0x00)
#define LEDON   (0x01)

#define LED_PORT  (PORTB)
#define LED_PIN   (PORTB0)
#define SENSORON  !(PIND&(1<<PD1))
#define HEATON  !(PIND&(1<<PD2))

void ledstat(uint8_t state);
void InitLED(void);

#endif
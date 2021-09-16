/**
 * @file main.c
 * @author Kajal (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include<avr/io.h>

void peripheral_init(void)
{
    InitLED();
    InitADC();
    InitPWC();
}

uint16_t temp;
chsr temp_data;
int main(void)
{
    peripheral_init();
    while(1)
    {
        if(SENSORON)
        {
            if(HEATON)
            {
               ledstat(LED_ON);
               temp = ReadADC(0);
               temp_data = OutPWM(temp);
            }
            else
            ledstat(LED_OFF);
        }
        else
        {
            ledstat(LED_OFF);
            OCR1A = 0;
        }
    }
    return 0;
}
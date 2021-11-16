/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.
PwmOut led(PA_15);
InterruptIn button(BUTTON1);

void button_pressed()
{
    led.write(1.0f);
}

void button_released()
{
    led.write(0.0f);  
}

int main()
{
    button.fall(&button_pressed); // Change led delay
    button.rise(&button_released); // Change led
    led.period(0.05f);      //0.05s period
    while (1);
}
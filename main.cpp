/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "Grove_LCD_RGB_Backlight.h"
#include "mbed.h"


#define WAIT_TIME_MS 2000
Grove_LCD_RGB_Backlight rgbLCD(PB_9, PB_8);

AnalogIn sensor(A0);

float NTC;
float temperatura;
char mensaje[16];

int main() {

  while (true) {
    NTC = (5.0 / (sensor.read() * 3.3 / 100000.0)) - 100000.0;
    temperatura = (4250.0 / (log(NTC / 100000.0) + (4250.0 / 298.15))) - 273.15;
    rgbLCD.locate(0, 0);
    rgbLCD.setRGB(0xff, 0xff, 0xff); // set the color
    sprintf(mensaje, "Temp es %.2f", temperatura);
    rgbLCD.print(mensaje);

    thread_sleep_for(WAIT_TIME_MS);
  }
}

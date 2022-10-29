#ifndef DISPLAY_H
#define DISPLAY_H

#include "main.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5
#define WIRE Wire

extern Adafruit_SSD1306 display;

#endif /* DISPLAY_H */
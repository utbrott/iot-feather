#ifndef INDOORSENSORS_H
#define INDOORSENSORS_H

#include "Main.h"

#include <Wire.h>
#include <Adafruit_BME280.h>

extern Adafruit_BME280 bme; // use I2C interface

extern void BME280_Init();
extern float BME280_temperature();
extern float BME280_pressure();
extern float BME280_humidity();
extern void BME280_Read();

#endif /* INDOORSENSORS_H */
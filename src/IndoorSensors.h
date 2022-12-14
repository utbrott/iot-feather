#ifndef INDOORSENSORS_H
#define INDOORSENSORS_H

#include "Main.h"

#include <Wire.h>
#include <Adafruit_BME280.h>
#include <Adafruit_MCP9808.h>

extern Adafruit_BME280 bme;
extern Adafruit_MCP9808 mcp;

extern void BME280_Init();
extern float BME280_temperature();
extern float BME280_pressure();
extern float BME280_humidity();
extern void BME280_Read();
extern void MCP9808_Init();
extern float MCP9808_temperature();
extern void MCP9808_Read();

#endif /* INDOORSENSORS_H */
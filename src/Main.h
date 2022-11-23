#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "WebClient.h"
#include "JsonParser.h"
#include "Display.h"
#include "IndoorSensors.h"

typedef enum
{
  A,
  B,
  C,
  NOT_PRESSED,
} ButtonType_t;

typedef enum
{
  INFO,
  TEMPERATURE,
  AROUND,
  INDOOR
} DataType_t;

extern String location;
extern String real_temperature;
extern String feelslike_temperature;
extern String pressure;
extern String humidity;
extern String indoor_humidity;
extern String indoor_pressure;
extern String indoor_temperature;

extern void OnButtonPress(ButtonType_t btn);
extern void Display_ShowData(DataType_t data);

#endif /* MAIN_H */

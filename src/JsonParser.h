#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "main.h"
#include <ArduinoJson.h>

#define DOC_CAPACITY 1024

extern StaticJsonDocument<DOC_CAPACITY> json_doc;
extern DeserializationError json_error;

extern float main_temp;
extern float main_feels_like;
extern int main_pressure;
extern int main_humidity;

extern const char *sys_country;
extern const char *name;

extern void ParseJson(Stream &res_data);

#endif /* JSONPARSER_H */
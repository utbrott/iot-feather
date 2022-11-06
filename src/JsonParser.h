#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "Main.h"
#include <ArduinoJson.h>
#include <TimeLib.h>

#define DOC_CAPACITY 2048

extern StaticJsonDocument<DOC_CAPACITY> json_doc;
extern DeserializationError json_error;

extern float main_temp;
extern float main_feels_like;
extern int main_pressure;
extern int main_humidity;

extern const char *sys_country;
extern const char *name;
extern long long dt;
extern long long timezone;
extern long long adjusted_dt;
extern String parsed_time;
extern String parsed_date;

extern char time_buffer;
extern char date_buffer;

extern void ParseJson(Stream &res_data);
extern String ParseTime(long long datetime);
extern String ParseDate(long long datetime);

#endif /* JSONPARSER_H */
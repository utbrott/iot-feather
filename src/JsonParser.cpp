#include "JsonParser.h"

float main_temp;
float main_feels_like;
int main_pressure;
int main_humidity;

const char *sys_country;
const char *name;

String parsed_time;
String parsed_date;

String ParseTime(long long datetime);
String ParseDate(long long datetime);

void ParseJson(Stream &res_data)
{
  StaticJsonDocument<DOC_CAPACITY> json_doc;

  DeserializationError json_error = deserializeJson(json_doc, res_data);

  if (json_error)
  {
    Serial.print("JSON deserialization failed: ");
    Serial.println(json_error.f_str());
    return;
  }

  JsonObject main = json_doc["main"];
  main_temp = main["temp"];
  main_feels_like = main["feels_like"];
  main_pressure = main["pressure"];
  main_humidity = main["humidity"];

  JsonObject sys = json_doc["sys"];
  sys_country = sys["country"];
  name = json_doc["name"];
  long long dt = json_doc["dt"];

  parsed_date = ParseDate(dt);
  parsed_time = ParseTime(dt);
}

String ParseTime(long long datetime)
{
  char time_buffer[32];
  sprintf(time_buffer, "%02d:%02d:%02d", hour(datetime), minute(datetime), second(datetime));
  return time_buffer;
}

String ParseDate(long long datetime)
{
  char date_buffer[32];
  sprintf(date_buffer, "%2d/%2d/%4d", day(datetime), month(datetime), year(datetime));
  return date_buffer;
}

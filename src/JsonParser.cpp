#include "JsonParser.h"

float main_temp;
float main_feels_like;
int main_pressure;
int main_humidity;

const char *sys_country;
const char *name;

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
}

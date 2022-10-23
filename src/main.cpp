#include "main.h"
#include "../lib/apiconfig.h"
#include "./wifi/webclient.h"

#define HTTP_PORT 80
#define HTTP_METHOD "GET "

char host_name[] = "api.openweathermap.org";
String weather_api = "https://api.openweathermap.org/data/2.5/weather";
String api_key = "?appid=" + String(API_KEY);
String query = "&lat=" + String(CITY_LAT) + "&lon=" + String(CITY_LON);
String request = HTTP_METHOD + weather_api + api_key + query + " HTTP/1.1";

void setup()
{
  /* Sets up the WiFi Client and Serial, connects to WiFi */
  WiFiSetup();
  Serial.println("\nStarting connection to server...");
  if (client.connect(host_name, HTTP_PORT))
  {
    Serial.println("Connected.");
    client.println(request);
    client.println("Host: " + String(host_name));
    client.println("Connection: close");
    client.println();
  }
}

void loop()
{
  while (client.available())
  {
    char c = client.read();
    Serial.write(c);
  }

  if (!client.connected())
  {
    Serial.println();
    Serial.println("Disconnected.");
    client.stop();

    while (true)
    {
    }
  }
}
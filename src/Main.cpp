#include "main.h"

void ApiRequest();

void setup()
{
  /* Begins Serial at 115200 baud */
  Serial.begin(115200);

  /* WiFi client setup, WiFi network connection */
  WiFiSetup();

  /* Make the request */
  ApiRequest();
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

void ApiRequest()
{
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
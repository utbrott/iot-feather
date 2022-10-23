#include "WebClient.h"

char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;

int status = WL_IDLE_STATUS;

WiFiClient client;

void PrintWiFiStatus();

void WiFiSetup()
{
  WiFi.setPins(WIFI_SHIELD_PINS);

  /* Wait for Serial to init*/
  while (!Serial)
  {
  }

  /* Check if shield is present */
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi Shield not present!");
    while (true)
    {
      /* Infinite loop, do not continue if no shield */
    }
  }

  /* Attempt to initialize connection */
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting connection to: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
    delay(10000);
  }

  Serial.println("Connected.");
}

void PrintWiFiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip_address = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip_address);
  long rssi = WiFi.RSSI();
  Serial.print("Signal (RSSI): ");
  Serial.print(rssi);
  Serial.println("dBm");
}
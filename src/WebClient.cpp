#include "WebClient.h"
#include "Display.h"

char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASS;
bool req_error = false;

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
    Serial.println("\nAttempting connection to: ");
    Serial.println(ssid);

    Display_WiFiMessage();

    status = WiFi.begin(ssid, pass);
    delay(10000);
  }

  Serial.println("\nConnected to:");
  display.println("WiFi connected.");
  display.display();
  PrintWiFiStatus();
}

void PrintWiFiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  long rssi = WiFi.RSSI();
  Serial.print("Signal (RSSI): ");
  Serial.print(rssi);
  Serial.println("dBm");
}

void ApiRequest()
{
  client.setTimeout(10000); /* 10s connection and request timeout */
  Serial.println("\nAttempting connection...");

  Display_ApiMessage();

  if (client.connect(host_name, HTTP_PORT))
  {
    Serial.println("\nConnected to " + String(host_name));
    Display_FetchData();
    client.println(request);
    client.println("Host: " + String(host_name));
    client.println("Connection: close");
    client.println();

    /* Error handling */
    if (client.println() == 0)
    {
      Serial.println("Request failed.");
      req_error = true;
      return;
    }

    char res_status[32] = {0};
    char http_200[] = "HTTP/1.1 200 OK";
    client.readBytesUntil('\r', res_status, sizeof(res_status));
    if (strcmp(res_status, http_200) != 0)
    {
      Serial.print("Unhandled response: ");
      Serial.println(res_status);
      req_error = true;
      return;
    }

    char end_of_headers[] = "\r\n\r\n";
    if (!client.find(end_of_headers))
    {
      Serial.println("Response invalid.");
      req_error = true;
      return;
    }
  }
  else
  {
    Serial.println("Connection failed.");
    req_error = true;
  }
}

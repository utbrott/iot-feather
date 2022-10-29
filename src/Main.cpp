#include "main.h"

/*
 * @brief : Private declarations
 */
/* Private variables*/
bool req_error = false;
String res_data = "";
unsigned long last_response;

/* Private function prototypes*/
void ApiRequest();

/*
 * @brief : Application entry point
 */
void setup()
{
  /* Begins Serial at 115200 baud */
  Serial.begin(115200);

  /* WiFi client setup, WiFi network connection */
  WiFiSetup();

  /* Make the request */
  ApiRequest();

  /* Parse received data */
  ParseJson(client);

  // /* Print the data to Serial */
  Serial.println(String(main_temp));
  Serial.println(String(main_feels_like));
  Serial.println(String(main_pressure));
  Serial.println(String(main_humidity));
  Serial.println(String(sys_country));
  Serial.println(String(name));
}

void loop()
{
}

void ApiRequest()
{
  client.setTimeout(10000); /* 10s connection and request timeout */
  Serial.println("\nStarting connection to server...");
  if (client.connect(host_name, HTTP_PORT))
  {
    Serial.println("\nConnected to " + String(host_name));
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
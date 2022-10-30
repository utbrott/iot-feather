#include "main.h"

/*
 * @brief : Private declarations
 */
/* Private variables*/
String res_data = "";
unsigned long last_response;

String location = String(name) + ", " + String(sys_country);
String real_temperature = "Measured: " + String(main_temp) + "°C";
String feelslike_temperature = "Feels like: " + String(main_feels_like) + "°C";
String pressure = "Pressure: " + String(main_pressure) + "hPa";
String humidity = "Humidity: " + String(main_humidity) + "%";

/* Private function prototypes*/
void OnButtonPress(ButtonType_t btn);
void Display_ShowData(DataType_t data);

/*
 * @brief : Application entry point
 */
void setup()
{
  /* Begins Serial at 115200 baud */
  Serial.begin(115200);

  /* WiFi client setup, WiFi network connection */
  WiFiSetup();

  /* Initialize display and clear it */
  Display_InitScreen();
  Display_Clear();

  Display_InitIO();
  Display_InitText();

  /* Make the request */
  ApiRequest();
  if (req_error)
  {
    Display_FailedMessage();
  }

  /* Parse received data */
  ParseJson(client);

  // /* Print the data to Serial */
  Serial.println(String(main_temp));
  Serial.println(String(main_feels_like));
  Serial.println(String(main_pressure));
  Serial.println(String(main_humidity));
  Serial.println(String(sys_country));
  Serial.println(String(name));
  Serial.println(parsed_date);
  Serial.println(parsed_time);
}

void loop()
{
  if (!digitalRead(BUTTON_A))
  {
    OnButtonPress(A);
  }
}

void OnButtonPress(ButtonType_t btn)
{
  switch (btn)
  {
  case A:
    ApiRequest();

    if (req_error)
    {
      Display_FailedMessage();
      return;
    }

    /* Parse received data */
    ParseJson(client);
    /* Print to Serial for debug */
    Serial.println(location);
    Serial.print(parsed_date);
    Serial.print(" ");
    Serial.println(parsed_time);
    Serial.println(real_temperature);
    Serial.println(feelslike_temperature);
    Serial.println(pressure);
    Serial.println(humidity);
    break;
  case B:
    break;
  case C:
    break;
  default:
    break;
  }
}

void Display_ShowData(DataType_t data)
{
  switch (data)
  {
  case INFO:
    display.println("");
    display.println(location);
    display.print(parsed_date);
    display.print("Last check: ");
    display.print(parsed_time);
    display.display();
    break;
  case TEMPERATURE:
    display.println("");
    display.println(real_temperature);
    display.println(feelslike_temperature);
    display.display();
    break;
  case AROUND:
    display.println("");
    display.println(pressure);
    display.println(humidity);
    display.display();
    break;
  default:
    break;
  }
}
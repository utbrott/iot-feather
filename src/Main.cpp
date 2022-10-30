#include "main.h"

/*
 * @brief : Private declarations
 */
/* Private variables*/
String res_data = "";
unsigned long last_update = 0;
const long update_interval = 5000;
String location;
String real_temperature;
String feelslike_temperature;
String pressure;
String humidity;

/* Private function prototypes*/
void Update_ResponseValues();
void OnButtonPress(ButtonType_t btn);
void Interrupt_ButtonA();
void Display_ShowData(DataType_t data);

/*
 * @brief : Application entry point
 */
void setup()
{
  /* Begins Serial at 115200 baud */
  Serial.begin(115200);

  /* Initialize display and clear it */
  Display_InitScreen();
  Display_Clear();
  Display_InitIO();
  Display_InitText();

  /* WiFi client setup, WiFi network connection */
  WiFiSetup();

  /* Interrupt based api data refresh */
  attachInterrupt(digitalPinToInterrupt(BUTTON_A), Interrupt_ButtonA, RISING);

  /* Make the request */
  ApiRequest();
  if (req_error)
  {
    Display_FailedMessage();
  }
  /* Parse received data */
  ParseJson(client);
  Update_ResponseValues();
  /* Print to Serial for debug */
  Serial.println(name);
  Serial.println(sys_country);
  Serial.println(main_temp);
  Serial.println(main_feels_like);
  Serial.println(main_pressure);
  Serial.println(main_humidity);
}

void loop()
{
  Display_ShowData(INFO);
  delay(2000);
  Display_ShowData(TEMPERATURE);
  delay(2000);
  Display_ShowData(AROUND);
  delay(2000);
}

void Update_ResponseValues()
{
  String location = String(name) + ", " + String(sys_country);
  String real_temperature = "Measured: " + String(main_temp) + "°C";
  String feelslike_temperature = "Feels like: " + String(main_feels_like) + "°C";
  String pressure = "Pressure: " + String(main_pressure) + "hPa";
  String humidity = "Humidity: " + String(main_humidity) + "%";
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

void Interrupt_ButtonA()
{
  OnButtonPress(A);
}

void Display_ShowData(DataType_t data)
{
  switch (data)
  {
  case INFO:
    display.println("");
    display.println(location);
    display.println(parsed_date);
    display.print("Last check: ");
    display.println(parsed_time);
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
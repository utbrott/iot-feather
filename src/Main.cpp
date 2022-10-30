#include "main.h"

/*
 * @brief : Private declarations
 */
/* Private variables*/
String res_data = "";
unsigned long last_response;

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
}
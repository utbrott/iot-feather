#include "Main.h"

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
ButtonType_t flag = NOT_PRESSED;  // A button interrupt flag

/* Private function prototypes*/
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
  location = String(name) + ", " + String(sys_country);

  Display_ShowData(INFO);
  /* Print to Serial for debug */
  Serial.println(location);
  Serial.println(main_temp);
  Serial.println(main_feels_like);
  Serial.println(main_pressure);
  Serial.println(main_humidity);
}

void loop()
{
  if(flag == A) {
    OnButtonPress(A);
    flag = NOT_PRESSED;
  } else if(flag == B) {
    // OnButtonPress(B);
    flag = NOT_PRESSED;
  } else if (flag == C) {
    // OnButtonPress(C);
    flag = NOT_PRESSED;
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
    location = String(name) + ", " + String(sys_country);
    /* Print to Serial for debug */
    
    Serial.println(location);
    Serial.print(parsed_date);
    Serial.print(" ");
    Serial.println(parsed_time);
    Serial.println(real_temperature);
    Serial.println(feelslike_temperature);
    Serial.println(pressure);
    Serial.println(humidity);

    Display_ShowData(INFO);
    delay(2000);
    Display_ShowData(TEMPERATURE);
    delay(2000);
    Display_ShowData(AROUND);
    delay(2000);
    Display_Clear();
    
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
  //OnButtonPress(A);
  flag = A;
}

void Display_ShowData(DataType_t data)
{
  switch (data)
  {
  case INFO:
    Display_Clear();
    //display.print(name);
    //display.print(", ");
    //display.println(sys_country);
    display.println(location);
    display.println("Last fetch:");
    display.println(parsed_date);
    display.println(parsed_time);
    display.display();
    break;
  case TEMPERATURE:
    Display_Clear();
    display.println("");
    display.println(real_temperature);
    display.println(feelslike_temperature);
    display.display();
    break;
  case AROUND:
    Display_Clear();
    display.println("");
    display.println(pressure);
    display.println(humidity);
    display.display();
    break;
  default:
    break;
  }
}

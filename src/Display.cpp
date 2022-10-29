#include "Display.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void Display_InitScreen()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.display();
}

void Display_InitIO()
{
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
}

void Display_Clear()
{
  display.clearDisplay();
  display.display();
}

void Display_InitText()
{
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
}

void Display_ShowData();

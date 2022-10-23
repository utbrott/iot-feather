#include <Arduino.h>

#define BUILTIN_LED 13
void setup()
{
  // put your setup code here, to run once:
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(BUILTIN_LED, 1);
  delay(1000);
  digitalWrite(BUILTIN_LED, 0);
  delay(1000);
}
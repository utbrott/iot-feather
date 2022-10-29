#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "ApiConfig.h"
#include "WebClient.h"
#include "JsonParser.h"
#include "Display.h"

#define HTTP_PORT 80

extern void ApiRequest();
extern void PrintData();

#endif /* MAIN_H */
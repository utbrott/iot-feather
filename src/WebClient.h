#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "main.h"
#include <SPI.h>
#include <WiFi101.h>
#include "WifiConfig.h"
#include "ApiConfig.h"

#define HTTP_PORT 80

/* WiFi Client */
extern WiFiClient client;
extern bool req_error;

/* Setup WiFi */
extern void WiFiSetup();

/* Printing WiFi Status */
extern void PrintWiFiStatus();

/* API Call */
extern void ApiRequest();

#endif /* WEBCLIENT_H */
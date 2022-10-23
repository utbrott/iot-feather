#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "SPI.h"
#include "WiFi101.h"
#include "../lib/wificonfig.h"

#define WIFI_SHIELD_PINS 8, 7, 4, 2

/* WiFi Client */
extern WiFiClient client;

/* Setup WiFi */
extern void WiFiSetup();

/* Printing WiFi Status */
extern void PrintWiFiStatus();

#endif /* WEBCLIENT_H */
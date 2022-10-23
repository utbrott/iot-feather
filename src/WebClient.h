#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "Main.h"
#include <SPI.h>
#include <WiFi101.h>
#include "WifiConfig.h"

/* WiFi Client */
extern WiFiClient client;

/* Setup WiFi */
extern void WiFiSetup();

/* Printing WiFi Status */
extern void PrintWiFiStatus();

#endif /* WEBCLIENT_H */
#ifndef WIFICONFIG_H
#define WIFICONFIG_H

/*
 * Example configuration file for WiFi configuration
 * WIFI_SSID: Network SSID (name)
 * WIFI_PASS: Password to access the SSID
 */

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASS "YOUR_WIFI_PASS"

/*
 * Hardware pinout of the WiFi Shield
 * Used here: Adafruit Feather M0
 *  See: https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500
 */

#define WIFI_SHIELD_PINS 8, 7, 4, 2

#endif /* WIFICONFIG_H */
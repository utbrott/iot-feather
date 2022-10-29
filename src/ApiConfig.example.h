#ifndef APICONFIG_H
#define APICONFIG_H

#include "main.h"

/*
 * Example configuration file to access OpenWeather API
 * API_KEY: Key to access the API calls
 * CITY_LAT, CITY_LON: Geograpical coordinates of target city
 *    See:  https://openweathermap.org/api/geocoding-api#direct_name
 *          https://openweathermap.org/current#geo
 */

#define API_KEY "YOUR_API_KEY"

/* LONDON */
#define CITY_LAT 51.5085
#define CITY_LON -0.1257
#define HTTP_METHOD "GET "

extern char host_name[];
extern String weather_api;
extern String req_base;
extern String query;
extern String request;

#endif /* APICONFIG_H */
#include "apiconfig.h"

char host_name[] = "api.openweathermap.org";
String weather_api = "https://api.openweathermap.org/data/2.5/weather";
String api_key = "?appid=" + String(API_KEY);
String query = "&lat=" + String(CITY_LAT) + "&lon=" + String(CITY_LON);
String request = HTTP_METHOD + weather_api + api_key + query + " HTTP/1.1";
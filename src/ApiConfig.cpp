#include "apiconfig.h"

char host_name[] = "api.openweathermap.org";
String weather_api = "https://api.openweathermap.org/data/2.5/weather";
String req_base = "?appid=" + String(API_KEY) + "&units=metric";
String query = "&lat=" + String(CITY_LAT) + "&lon=" + String(CITY_LON);
String request = HTTP_METHOD + weather_api + req_base + query + " HTTP/1.1";
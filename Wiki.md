# Wiki projektu
IOT Feather jest projektem stworzonym na potrzeby współpracy z 3 grup projektowych z przedmiotu Internet rzeczy. Opiera się na wymienionych w 
[README](https://github.com/utbrott/iot-feather/blob/main/README.md) (sekcja _Build with_) elementach hardware oraz sekcji software, której dokladna zawartość
pokazana jest w sekcji _File structure_ pliku Readme. Na wiki w następujących sekcjach opisana zostanie część software podzielona, jak same pliki projektu, 
na sekcje odpowiedzialne za elementy funkcjonlności, które zostały zgrupowane razem w celu ułatwienia odczytu i modyfikacji.

## Konfiguracja Api
Plik konfiguracji Api, wraz z  plikiem nagłówkowym, zawierają składnię zapytania stworzonego  celu uzyskania danych o pogodzie w danym mieście. Zgodnie z 
informacją zawartą w pliku README projekt opiera się na API pogodowym Openweather. Każde zapytanie musi zawierać koordynaty danego miasta, w przypadku 
przykładowym jest to Londyn - LAT tj. szerokość = 51.5085, LON tj. długość geograficzna = -0.1257. Zmienić je można w pliku _ApiConfig.example.h_

## Konfiguracja wyświetlacza
Konfiguracja wyświetlacza opiera się na podstawowej bilbiotece Adafruit Display - więcej informacji dostępnych jest na 
[stronie Adafruit](https://learn.adafruit.com/adafruit-gfx-graphics-library)

## Obsługa odpowiedzi serwera
Odpowiedź serwera zawiera dużo niepotrzebnych w projekcie danych, więc obsługiwane są jedynie parametry konieczne do funkcjonowania stacji pogodowej.
W module _JsonParser.cpp_ zawarte są funkcje odpowiedzialne za zapis otrzymanej tempertury, temperatury odczuwalnej, ciśnienia i wilgotności, oraz dopasowanie
strefy czasowej, godziny oraz daty.

## Konfiguracja Wi-FI
Aby stacja mogła poprawnie pobierać dane konieczny jest ustawienie nazwy - WIFI_SSID - oraz hasła - WIFI_PASS. 
Umożliwione jest to w pliku _WifiConfig.example.h_.

## Wysłanie zapytania
Jeżeli Wi-FI zostało skonfigurowane poprawnie, to za pomocą funkcji _WiFiSetup_ opisanej w _WebClient.cpp_ ustawione zostanie połączenie umożliwiające 
komunikację. Status połączenia można uyskać za pomocą funkcji _PrintWiFiStatus_, która wyświetli niewrażliwe dane na temat sieci.Zapytanie API odbywa się
poprzez funkcję _ApiRequest_, która podejmuje próbę uzyskania danych pogodowych OpenWeather. Na każdym etapie koneksji użytkownik będzie informowany
w przypadku wystąpienia nieprawiłowości połączenia, zapytania bądź odpowiezi serwera.

## Główne działanie stacji
Działanie stacji opiera się na wyświetlaniu danych pogodowych poprzez rozpoczęcie połączenia z siecią Wi-FI oraz wyświetlaczem i wysłania zapytania do 
serwerów OpenWeather. Odświeżanie informacji odbywa się za pomocą przerwania po naciśnięciu przcisku, ktore wymusza wysłanie ponownego zapytania.
Wszystkie otrzymane dane wyświetlane są zarówno w terminalu jak i na wyświetlaczu.

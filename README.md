# IOT Feather
Embedded Systems IOT project that utilizes Adafruit Feather M0, OpenWeatherMap
to create a simple home weather station. Created for *IOT: Internet of Things*
course @ WUT Warsaw University of Technology.

Visit the [Wiki](https://github.com/utbrott/iot-feather/wiki) to read more about the project.
<h6>Warning: Currently project's Wiki is only in Polish, as the course is in Polish</h6>

# Features
- Requesting data from OpenWeatherMap for outside weather data,
- BME280 Sensor to read surrouding's general temperature, humidity and pressure
- MCP9808 Sensor to read surrouding's accurate temperature.

# Built with
- [Adafruit Feather M0](https://www.adafruit.com/product/3010) (ATSAM21 + ATWINC1500) uController
- Adafruit OLED FeatherWing 128x32 128x32 display shield
- BME280 I2C/SPI Sensor Breakout Board
- MCP9808 I2C/SPI Sensor Breakout Board
- OpenWeatherMap API

# File structure:
```
|
|-- src
|   |
|   |- Main.h (main of the program)
|   |- Main.cpp
|   |- ApiConfig.h (configuration for api calls)
|   |- ApiConfig.cpp
|   |- WebClient.h (webclient for api calls)
|   |- WebClient.cpp
|   |- WifiConfig.h (configuration for wifi connection)
|   |- WifiConfig.cpp
|   |- Display.h (working with oled display)
|   |- Display.cpp
|
|- LICENSE
|- platformio.ini
|- README.md --> This file
```

## Future development note
Project was built using PlatformIO extension for VSCode.
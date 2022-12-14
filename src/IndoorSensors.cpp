#include "IndoorSensors.h"

Adafruit_BME280 bme;

Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();

sensors_event_t temp_event,
    pressure_event, humidity_event;

bool BME_ACTIVE = false;

Adafruit_MCP9808 mcp;
bool MCP_ACTIVE = false;

void BME280_Init()
{
    if (!bme.begin())
    {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
    }
    else
        BME_ACTIVE = true;
}

float BME280_temperature()
{
    if (BME_ACTIVE)
    {
        bme_temp
            ->getEvent(&temp_event);
        return temp_event.temperature;
    }
    else
        return .0;
}

float BME280_pressure()
{
    if (BME_ACTIVE)
    {
        bme_pressure->getEvent(&pressure_event);
        return pressure_event.pressure;
    }
    else
        return .0;
}

float BME280_humidity()
{
    if (BME_ACTIVE)
    {

        bme_humidity->getEvent(&humidity_event);
        return humidity_event.relative_humidity;
    }
    else
        return .0;
}

void BME280_Read()
{
    indoor_humidity = String(BME280_humidity());
    indoor_humidity.concat("%");
    indoor_temperature = String(BME280_temperature());
    indoor_temperature.concat(" *C");
    indoor_pressure = String(BME280_pressure());
    indoor_pressure.concat(" hPa");
}

void MCP9808_Init()
{
    if (!mcp.begin(0x18))
    {
        Serial.println(F("Could not find a valid MCP9808 sensor, check wiring!"));
    }
    else
    {
        mcp.setResolution(3);
        MCP_ACTIVE = true;
    }
}

float MCP9808_temperature()
{
    if (MCP_ACTIVE)
    {
        mcp.wake();
        float temperature = mcp.readTempC();
        mcp.shutdown_wake(1);
        return temperature;
    }
    else
        return .0;
}
void MCP9808_Read()
{
    indoor_humidity = String();
    indoor_temperature = String(MCP9808_temperature());
    indoor_temperature.concat(" *C");
    indoor_pressure = String();
}
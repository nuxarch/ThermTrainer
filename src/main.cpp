/*
- plot temperature and voltage at the display realtime
*/

#include <Arduino.h>
#include "Thermistor.hpp"

#define HEATERPIN       18
#define heaterOff       digitalWrite(HEATERPIN, LOW)
#define heaterOn        digitalWrite(HEATERPIN, HIGH)
Thermistor Therm(16);
xTaskHandle taskSensorReading;
void taskPlotTemp(void * parameter){

    for(;;){
        Serial.println("Thermistor - Voltage :"+String(Therm.ReadVoltage()));
        Serial.println("           - Temp    :"+String(Therm.ReadTemperature()));
        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}
void setup(){
    pinMode(HEATERPIN, OUTPUT);
    heaterOff;
    Serial.begin(115200);
    Serial.println("app begin");
    xTaskCreate(taskPlotTemp,"task blink", 4000,NULL,1,&taskSensorReading);
}

void loop(){
}

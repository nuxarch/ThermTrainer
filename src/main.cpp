#include <Arduino.h>
#include "Sensor.hpp"


Thermistor Therm(16);
xTaskHandle taskBlinkHandle;
void taskBlink(void * parameter){

    for(;;){
        Serial.println("Thermistor - Voltage :"+String(Therm.ReadVoltage()));
        Serial.println("           - Tempe   :"+String(Therm.ReadTemperature()));
        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}
void setup(){
    Serial.begin(115200);
    Serial.println("app begin");
    xTaskCreate(taskBlink,"task blink", 4000,NULL,1,NULL);
}

void loop(){
}

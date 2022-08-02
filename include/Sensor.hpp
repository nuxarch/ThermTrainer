#ifndef __SENSOR_h__
#define __SENSOR_h__

#include <Arduino.h>

class Thermistor
{
private:
    unsigned char pin;
public:
    Thermistor(unsigned char pin);
    unsigned int Read();
    long ReadVoltage();
    long ReadTemperature();
    ~Thermistor();
};

Thermistor::Thermistor(unsigned char _pin)
{
    pin = _pin;
}
unsigned int Thermistor::Read(){
    return analogRead(pin);
}
long Thermistor::ReadVoltage(){
    return map(analogRead(pin),0,4095,0,3.3);
}
long Thermistor::ReadTemperature(){
    return map(analogRead(pin),0,4095,0,3.3);
}
Thermistor::~Thermistor()
{
}
#endif
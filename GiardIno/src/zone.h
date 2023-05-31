#ifndef ZONE_H
#define ZONE_H

#include <Arduino.h>
#include "switchable.h"

class Pump;

class Zone : public Switchable{
private:
    unsigned int pin;
public:
    Zone(Pump*pump, unsigned int pin) : pin(pin){
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }

    void on(){
        digitalWrite(pin, LOW);
        Serial.println("Zone on");
    }

    void off(){
        digitalWrite(pin, HIGH);
        Serial.println("Zone off");
    }  
};

#endif
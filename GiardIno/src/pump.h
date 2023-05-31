#ifndef PUMP_H
#define PUMP_H

#define pumpTiming 200
#include <Arduino.h>
#include "delay.h"


class Pump{
    unsigned int users;
    unsigned int OnPin;
    unsigned int OffPin;
    bool state;
    
    void on(){
        digitalWrite(OnPin, LOW);
        Delay::delay(pumpTiming);
        digitalWrite(OnPin, HIGH);
    }

    void off(){
        digitalWrite(OffPin, LOW);
        Delay::delay(pumpTiming);
        digitalWrite(OffPin, HIGH);
    }

    void setState(){
        Serial.print("Users: ");
        Serial.println(users);
        if(users > 0){
            if(!state){
                on();
                state = true;
            }
        }else{
            if(state){
                off();
                state = false;
            }
        }
    }

public:

    Pump(unsigned int OnPin, unsigned int OffPin)
    : OnPin(OnPin), OffPin(OffPin), users(0), state(false){
        pinMode(OnPin, OUTPUT);
        pinMode(OffPin, OUTPUT);
        digitalWrite(OnPin, HIGH);
        digitalWrite(OffPin, HIGH);
        Serial.println(users);
        Serial.println("Pompa creata");
    }

    void addUser(){
        users = users + 1;
        setState();
    }

    void removeUser(){
        users--;
        setState();
    }
};

#endif
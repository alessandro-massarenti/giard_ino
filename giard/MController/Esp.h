#pragma once

#include "MController.h"

class Esp: public MController{
public:
    //Output
    virtual bool setPumpState(bool state = true);
    virtual bool setZoneState(int zone,bool state = true);
    virtual bool setLedIndicatorState(State state);

    //Input
    virtual int getPressureSensorData();
    virtual int getTemperatureSensorData();
    virtual bool getRunDryState();
};
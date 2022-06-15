#pragma once

class MController{
public:
    enum class State{ Ok, Ready, Error };

    //Output
    virtual bool setPumpState(bool state = true) = 0;
    virtual bool setZoneState(int zone,bool state = true) = 0;
    virtual bool setLedIndicatorState(State state) = 0;

    //Input
    virtual int getPressureSensorData() = 0;
    virtual int getTemperatureSensorData() = 0;
    virtual bool getRunDryState() = 0;

    //Distruttore
    virtual ~MController() = default;
};
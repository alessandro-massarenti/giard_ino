#include "Pump.h"

Pump::Pump(MController* io,double t) : Hardware(io), hotTemp(t){}

void Pump::start() const{
    mController->setPumpState(true);
}
void Pump::stop() const{
    mController->setPumpState(false);
}

bool Pump::isAllOk() const{
    if(mController == nullptr) return false;
    if(isRunningDry()) return false;
    if(isHot()) return false;
    return true;
}

bool Pump::isRunningDry() const{return mController->getRunDryState();}

bool Pump::isHot() const{
    if(mController->getTemperatureSensorData() >= hotTemp)
        return true;
    return false;
}

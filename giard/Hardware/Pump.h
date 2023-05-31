#pragma once

#include "Hardware.h"
#include "Bistable.h"


class Pump : public Hardware, public Bistable{
    static const double defaultHotTemp;
public:
    explicit Pump(MController* mController,double hotTemp = Pump::defaultHotTemp);

    void start() const override;
    void stop() const override;


private:
    bool isAllOk() const;
    //Possible faults
    bool isRunningDry() const;
    bool isHot() const;

/** Data fields */    
private:
    const double hotTemp;
};
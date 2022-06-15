#pragma once

#include "Hardware.h"
#include "Bistable.h"

class Zone: public Hardware, public Bistable{
public:
    explicit Zone(MController * mController);

    void start() const override;
    void stop() const override;

private:
    int id;
};
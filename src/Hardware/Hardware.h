#pragma once

#include "MController/MController.h"

class Hardware{

public:
    explicit Hardware(MController* mController);
protected:
    MController * mController;
};
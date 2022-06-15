#include "Zone.h"

Zone::Zone(MController* c) : Hardware(c){}

void Zone::start() const{ mController->setZoneState(id,true);}
void Zone::stop() const{mController->setZoneState(id,false);}

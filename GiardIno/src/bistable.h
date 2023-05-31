#ifndef BISTABLE_H
#define BISTABLE_H

#include "switchable.h"

class Bistable{

    bool state;
    Switchable* switchable;

public:

    Bistable(Switchable* switchable) : state(false), switchable(switchable) {
        switchable->off();
    }

    void toggle(){
        if(state){
            switchable->off();
        }else{
            switchable->on();
        }
        state = !state;
    }

};

#endif
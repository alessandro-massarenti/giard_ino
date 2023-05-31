#ifndef _DELAY_h
#define _DELAY_h

#include "arduino.h"

//Create a wrapper for the delay function wich is not blocking
class Delay
{
  public:
    static void delay(unsigned long ms)
    {
      unsigned long start = millis();
      while (millis() - start <= ms)
      {
        yield();
      }
    }
};

#endif

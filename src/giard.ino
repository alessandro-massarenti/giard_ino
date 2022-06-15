#define pumpPin 3
#define zoneOnePin 4
#define zoneTwoPin 5
#define userPin 7
#define buttonOnePin 8
#define buttonTwoPin 9

#include "MController/Esp.h"
#include "Hardware/Pump.h"
#include "Hardware/Zone.h"

void setup()
{
    // put your setup code here, to run once:
    pinMode(userPin, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{

    Esp esp;

    Pump pump1(&esp);
    Zone zone1(&esp), zone2(&esp);

    bool user;
    while (true)
    {
        pump1.start();
        zone1.start();
        zone2.start();

        delay(200);
        
        pump1.start();
        zone1.stop();
        zone2.stop();
        
        delay(10);
    }
}

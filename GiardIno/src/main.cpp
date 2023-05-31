#define pumpOnPin 2
#define pumpOffPin 3
#define zoneOnePin 4
#define zoneTwoPin 5
#define userPin 7
#define buttonOnePin 8
#define buttonTwoPin 9

#include "pump.h"
#include "zone.h"
#include "bistable.h"
#include "debounce.h"


void setup() {

  //Initialize button input_pullup on pin 8
  //pinMode(buttonOnePin, INPUT_PULLUP);

  Serial.begin(9600);

  Debounce buttonOne(buttonOnePin, 50, true);
  Debounce buttonTwo(buttonTwoPin, 50, true);

  Debounce user(userPin, 50, true);

  Pump* pump = new Pump(pumpOnPin, pumpOffPin);
  Zone* zoneOne = new Zone(pump, zoneOnePin);
  Zone* zoneTwo = new Zone(pump, zoneTwoPin);

  bool zoneOnestate = false;
  bool zoneTwostate = false;

  bool lastButtonOneState = false;
  bool lastButtonTwoState = false;

  bool userSeen = false;

  while(true){

    bool userState = user.read();
    bool buttonOneState = buttonOne.read();
    bool buttonTwoState = buttonTwo.read();
    
    if(buttonOneState != lastButtonOneState){
      if(buttonOneState == LOW){
        if(zoneOnestate){
          zoneOne->off();
          pump->removeUser();
          zoneOnestate = false;
        }else{
          zoneOne->on();
          pump->addUser();
          zoneOnestate = true;
        }
      }
    }

    if(buttonTwoState != lastButtonTwoState){
      if(buttonTwoState == LOW){
        if(zoneTwostate){
          zoneTwo->off();
          pump->removeUser();
          zoneTwostate = false;
        }else{
          zoneTwo->on();
          pump->addUser();
          zoneTwostate = true;
        }
      }
    }

    if(userState == HIGH){
      if(!userSeen){
        pump->addUser();
        userSeen = true;
        Serial.println("User seen");
      }
    }else{
      if(userSeen){
        pump->removeUser();
        userSeen = false;        
        Serial.println("User gone");
      }
    }

    lastButtonOneState = buttonOneState;
    lastButtonTwoState = buttonTwoState;

  }

}

void loop() {
  // put your main code here, to run repeatedly:
}




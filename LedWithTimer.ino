
#include "LedManager.h"

const int pirPin1 = 2;
const int pirPin2 = 12;

LedManager ledManager(5, 6, 9, 30);
class PIRSensor 
{
  long _interval = 500;
  int pirState1 = LOW;
  int pirState2 = LOW;
  
  public:
    PIRSensor(long interval)
    {
      _interval = interval;
    }

  void Update()
  {  
      int val = digitalRead(pirPin1);
      int val2 = digitalRead(pirPin2);
      Serial.println("PIR1: " + String(val) + "State:" + String(pirState1));
      Serial.println("PIR2: " + String(val2) + "State:" + String(pirState2));
      
      if (val == HIGH)
      {
//        if (pirState1 == LOW)
//        {
          //Serial.println("PIR 1 Active");
          if(ledManager.Status() == 0){
//            pirState1 = HIGH;
            ledManager.CycleColors();
          }
//        }
      }
      else if (val2 == HIGH)
      { 
//        if (pirState2 == LOW)
//        {
          //Serial.println("PIR 2 Active");
          if(ledManager.Status() == 0){
//            pirState2 = HIGH;
            ledManager.CycleColors();
//          }
        }
      }
  }
};

PIRSensor pir(500);

void setup() {
 //Serial.begin(9600);
 Serial.println("Setting up");
 ledManager.Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  takeReading();
  delay(50);
}

void takeReading()
{
  Serial.println("taking reading");
  pir.Update();
}

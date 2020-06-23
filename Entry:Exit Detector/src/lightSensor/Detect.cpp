#include <Arduino.h>
#include "Detect.h"

#define FREESTATE 0
#define ENTERSTATE1 1
#define ENTERSTATE2 2
#define LEAVESTATE1 3
#define LEAVESTATE2 4
int STATE = FREESTATE;

//Detect Constructor
Detect::Detect(){
  detectThresh = 1000;
  numInRoom = 0;
  timeToWait = -1;
}
Detect::Detect(int innerP, int outerP, int timeP, int lampP){
  innerPin = innerP;
  outerPin = outerP;
  timerPin = timeP;
  lampPin  = lampP;
  detectThresh = 1000;
  numInRoom = 0;
  timeToWait = -1;
}

void Detect::startTimer(){
  timeEnter = millis();
}

void Detect::determineNumInRoom(){
  dimmerVal =  (255 * analogRead(16)>>10) + 20;
  if(timeToWait > 0){  
    if((millis() - timeEnter) > timeToWait){
      //assume no one in room (jumped out window)
      analogWrite(lampPin, LOW);
      timeToWait = -1;
      numInRoom = 0;
    }
  }
  switch( STATE ){
    case FREESTATE:{
      if( digitalRead(outerPin) == LOW){
        outerCount++;
        if(outerCount > detectThresh){
          STATE = ENTERSTATE1;
          outerCount = 0;
          innerCount = 0;
          break;
        }
      } else if( digitalRead(innerPin) == LOW){
        innerCount++;
        if(innerCount > detectThresh){
          STATE = LEAVESTATE1;
          innerCount = 0;
          outerCount = 0;
          break;
        }
      }      
      break;
    }
    case ENTERSTATE1:{
      if(digitalRead(innerPin) == LOW){ 
        innerCount++;
        if( innerCount > detectThresh){
          STATE = ENTERSTATE2;
          innerCount = 0;
          break;
        }
      }
      break;
    }
    case ENTERSTATE2:{
      if(digitalRead(innerPin) == HIGH){
        innerCount++;
        if( innerCount > detectThresh){
          numInRoom++;
          startTimer();
          timeToWait =  (540700 * analogRead(timerPin)>>10) + 60000;
          if(numInRoom == 1){
            //first person in room
            analogWrite(lampPin, dimmerVal);
          }
          innerCount = 0;
          STATE = FREESTATE;
          break;
        }
      }
      break;
    }
    case LEAVESTATE1:{
      if(digitalRead(outerPin) == LOW){
        outerCount++;
        if(outerCount > detectThresh){
          STATE = LEAVESTATE2;
          outerCount = 0;
          break;
        }
      }
      break;
    }
    case LEAVESTATE2:{
      if(digitalRead(outerPin) == HIGH){
        outerCount++;
        if(outerCount > detectThresh){
          if( numInRoom!= 0)numInRoom--;
          STATE = FREESTATE;
          if(numInRoom == 0){
            //last person has exited
            analogWrite(lampPin, 0);
          }
          outerCount = 0;
          break;
        }
      }
      break;
    }
  }
}

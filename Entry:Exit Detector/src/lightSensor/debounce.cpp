#include <Arduino.h>
#include "debounce.h"
#include "Detect.h"
#define LAMP     20

Debounce::Debounce(){
  BUTTON = -1;
  buttonState = 0;
  lampOn = 0;
  buttonCount = 0;
  debounceThresh = 1000;
  timer = new Metro(800);
}

//debounce constructor
Debounce::Debounce(int buttonPin, int lampPotIn, int lampOut){
  BUTTON = buttonPin;
  lampPotentiometerInput = lampPotIn;
  buttonState = 0;
  lampOn = 0;
  buttonCount = 0;
  debounceThresh = 1000;
  timer = new Metro(800);
}

void Debounce::debounceButton(){
  int dimmerVal =  (255 * analogRead(lampPotentiometerInput)>>10) + 20;
  //Serial.println(dimmerVal);
  if (buttonState == 0) {
   if (digitalRead(BUTTON) == HIGH)//button pressed
     buttonCount++;
   else
     buttonCount = 0;
   if (buttonCount > debounceThresh) {
     buttonState = 1;
     buttonCount = 0;
     }
   }
  else {
   if (digitalRead(BUTTON) == LOW)//button not pressed
     buttonCount++;
   else
     buttonCount = 0;
   if (buttonCount > debounceThresh){
     buttonState = 0;
     buttonCount = 0;
     button_press(dimmerVal);
   }
  }
  if(lampOn){
    analogWrite(LAMP, dimmerVal);
  }
}

void Debounce::button_press(int dimmerVal){
  if(lampOn){
    analogWrite(LAMP, 0);
    lampOn = 0;
  }
  else {
    analogWrite(LAMP, dimmerVal);
    lampOn = 1;
  }
  //digitalWrite(LED,HIGH);
  timer->reset();
}

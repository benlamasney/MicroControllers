#include "Debounce.h"
#include "Detect.h"
#include <Metro.h>

#define LAMP     20
#define LAMPPOT  16
#define TIMERPOT 14
#define BUTTON   11
#define irLED    10 
#define irRight   5
#define irLeft    4
  

int dimmerVal;
double dimmerMult;
boolean debug;
boolean irOn;
Debounce *bounce;
Detect   *detector;
int      *numInRoom;
void setup() {
  pinMode(TIMERPOT, INPUT);
  pinMode(LAMPPOT,  INPUT);
  pinMode(LAMP,     OUTPUT);
  pinMode(BUTTON,   INPUT);
  pinMode(irLeft,   INPUT);
  pinMode(irRight,  INPUT);
  pinMode(irLED,    OUTPUT);
  dimmerMult = (280 / 1024);
  Serial.begin(9600);
  while(!Serial);
  debug = false;
  irOn = true;
  bounce = new Debounce(BUTTON, LAMPPOT, LAMP);
  detector = new Detect(irRight, irLeft, TIMERPOT, LAMP);
} 

void loop() {
  // put your main code here, to run repeatedly: 
  bounce->debounceButton();
  setIrOnOff();
  //int outer = digitalRead(irOuter);
  //int inner = digitalRead(irInner);
  detector->determineNumInRoom();
  if(debug)getIrValues();
 }

void getIrValues(){
  Serial.print("IR LED_Left_Right: ");
  Serial.print( irOn );
  Serial.print(" ");
  Serial.print( digitalRead(irRight) );
  Serial.print(" ");
  Serial.println( digitalRead(irLeft) );
}

void setIrOnOff(){
  if(irOn){ digitalWrite(irLED, HIGH);}
  else{     digitalWrite(irLED, LOW);}
}

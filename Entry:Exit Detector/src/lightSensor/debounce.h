#ifndef DEBOUNCE_H
#define DEBOUNCE_H
#include <Metro.h>
class Debounce{
private:
 int BUTTON;
 int buttonState;
 int buttonCount;
 int debounceThresh;
 int lampOn;
 int lampPotentiometerInput;
 Metro * timer;

public:
  Debounce();
  Debounce(int buttonPin, int lampPotIn, int lampOut);
  
  void debounceButton();
  void button_press(int dimmerVal);

};

#endif

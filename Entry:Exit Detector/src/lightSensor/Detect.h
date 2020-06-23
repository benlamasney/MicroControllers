#ifndef DETECT_H
#define DETECT_H
#include <Metro.h>

class Detect{
private:
  int numInRoom;
  int dimmerVal;
  int timeEnter;
  int timeToWait;
  int innerPin,outerPin, timerPin, lampPin;
  int innerCount, outerCount;
  int detectThresh;
public:
  Detect();
  Detect(int innerP, int outerP, int timeP, int lampP);

  void startTimer();
  void determineNumInRoom();
};

#endif

#define ON LOW
#define OFF HIGH
#define IR 21

void snake(int wait){
  int i = 0;
  while(i < 10){   
    digitalWrite(1, ON);
    digitalWrite(7, ON);
    delay(wait);
    digitalWrite(1, OFF);
    digitalWrite(6, ON);
    delay(wait);
    digitalWrite(7, OFF);
    digitalWrite(5, ON);
    delay(wait);
    digitalWrite(6, OFF);
    digitalWrite(1, ON);
    delay(wait);
    digitalWrite(5, OFF);
    digitalWrite(4, ON);
    delay(wait);
    digitalWrite(1, OFF);
    digitalWrite(3, ON);
    delay(wait);
    digitalWrite(4, OFF);
    digitalWrite(2, ON);
    delay(wait);
    digitalWrite(3, OFF);
    digitalWrite(1, ON);
    delay(wait);
    digitalWrite(2, OFF);
    i++;
  }
  digitalWrite(1,OFF);
}

void clPattern1(int speed){
  //pattern 1
  for(int j=0;j<6; j++){
    for(int i=0; i<6; i++){
      digitalWrite(2, ON); 
      digitalWrite(4, ON); 
      delay(speed/20);
      digitalWrite(2, OFF); 
      digitalWrite(4, OFF);
      delay(speed/20);
    }
    for(int i=0; i<6; i++){
      digitalWrite(5, ON); 
      digitalWrite(7, ON);
      delay(speed/20);
      digitalWrite(5, OFF); 
      digitalWrite(7, OFF);
      delay(speed/20);
    }
  }
}

void clPattern2(int speed){
  for(int i = 0; i < 12; i++){
    digitalWrite(5, ON); 
    digitalWrite(4, ON);
    delay(speed/20);
    digitalWrite(5, OFF); 
    digitalWrite(4, OFF);
    digitalWrite(2, ON); 
    digitalWrite(7, ON);
    delay(speed/20);
    digitalWrite(2, OFF); 
    digitalWrite(7, OFF);
  }
}

void clPattern3(int speed){
  for(int i = 0; i < 24; i++){
    digitalWrite(1,ON);
    digitalWrite(3,ON);
    digitalWrite(6,ON);
    delay(speed/15);
    digitalWrite(1,OFF);
    digitalWrite(3,OFF);
    digitalWrite(6,OFF);
    digitalWrite(2,ON);
    digitalWrite(4,ON);
    digitalWrite(5,ON);
    digitalWrite(7,ON);
    delay(speed/15);
    digitalWrite(2,OFF);
    digitalWrite(4,OFF);
    digitalWrite(5,OFF);
    digitalWrite(7,OFF);   
  }
}

//takes speeds 0 - 100// 
void copLights(int speed){
  clPattern1(speed/2);
  clPattern2(speed);
  clPattern2(speed);
  clPattern3(speed);
  
  turnAllOff();
}

void turnAllOff(){
  digitalWrite(1,OFF);
  digitalWrite(2,OFF);
  digitalWrite(3,OFF);
  digitalWrite(4,OFF);
  digitalWrite(5,OFF);
  digitalWrite(6,OFF);
  digitalWrite(7,OFF);
  digitalWrite(8,OFF);
}

void turnAllOn(){
  digitalWrite(1,ON);
  digitalWrite(2,ON);
  digitalWrite(3,ON);
  digitalWrite(4,ON);
  digitalWrite(5,ON);
  digitalWrite(6,ON);
  digitalWrite(7,ON);
}

void lightEmUp(){
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(500);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  delay(500);
  digitalWrite(12,LOW);
}

void warning(){
  lightEmUp();
  snake(100);
}

void displayNum(int num) {
  turnAllOff();
  switch(num){
    case 0: {
      digitalWrite(2,ON);
      digitalWrite(3,ON);
      digitalWrite(4,ON);
      digitalWrite(7,ON);
      digitalWrite(6,ON);
      digitalWrite(5,ON);
      break;
    }
    case 1: {
      digitalWrite(4,ON);
      digitalWrite(7,ON);
      break;
    }
    case 2: {
      digitalWrite(1,ON);
      digitalWrite(3,ON);
      digitalWrite(4,ON); 
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      break;
    }
    case 3: {
      digitalWrite(4,ON);
      digitalWrite(7,ON);
      digitalWrite(3,ON);
      digitalWrite(1,ON);
      digitalWrite(6,ON);
      break;
    }
    case 4: {
      digitalWrite(4,ON);
      digitalWrite(7,ON);
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      break;
    }
    case 5: {
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(3,ON);
      digitalWrite(6,ON);
      digitalWrite(7,ON);
      break;
    }
    case 6: {
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(3,ON);    
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      digitalWrite(7,ON);
      break;
    }
    case 7: {
      digitalWrite(3,ON);
      digitalWrite(4,ON);
      digitalWrite(7,ON);
      break;
    }
    case 8: {
      turnAllOn();
      break;
    }
    case 9: {
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(3,ON);    
      digitalWrite(4,ON);
      digitalWrite(6,ON);
      digitalWrite(7,ON);
      break;
    }
  }
}

//Currently: Accepts A - D (only displaying distinguishable character versions)
void displayLetter(char l, int d){
  turnAllOff();
  switch(l) {
    case 'A':{
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(3,ON);
      digitalWrite(4,ON);
      digitalWrite(5,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'a':{
      digitalWrite(1,ON);
      digitalWrite(3,ON);
      digitalWrite(4,ON);
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'B':{
      turnAllOn();
      break;
    }
    case 'b':{
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'C':{
      digitalWrite(2,ON);
      digitalWrite(3,ON);
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      break;
    }
    case 'c':{
      digitalWrite(1,ON);
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      break;
    }
    case 'D':
    case 'd':{
      digitalWrite(1,ON);
      digitalWrite(4,ON);
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'E':
    case 'e':{
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(3,ON);
      digitalWrite(5,ON);
      digitalWrite(6,ON);
      break;
    }
    case 'F':
    case 'f':{
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(3,ON);
      digitalWrite(5,ON);
      break;
    }
    case 'I':
    case 'i':{
      digitalWrite(4,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'S':
    case 's':{
      displayNum(5);
      break;
    }
    case 'H':{
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(4,ON);
      digitalWrite(5,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'h':{
      digitalWrite(1,ON);
      digitalWrite(2,ON);
      digitalWrite(5,ON);
      digitalWrite(7,ON);
      break;
    }
    case 'N':
    case 'n':{
      digitalWrite(1,ON);
      digitalWrite(5,ON);
      digitalWrite(7,ON);
      break;
    }
    case '!':{
      digitalWrite(4,ON);
      digitalWrite(8,ON);
      break;
    }
  }
  delay(d);
  turnAllOff();
}

void displayFinish(int d){
  displayLetter('F',d);
  displayLetter('I',d);
  displayLetter('N',d);
  displayLetter('I',d);
  displayLetter('S',d);
  displayLetter('H',d);
  displayLetter('E',d);
  displayLetter('d',d);
  displayLetter('!',d);
}

void timerCompletionDisplay(){
  copLights(1000);
  for(int i = 0; i < 1; i++){
    displayFinish(1000);
    lightEmUp();
  }
  snake(100);
}

int bitValues[] = {32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
int readTransmission(int bitIndex, int signalValue ){ 
  return signalValue * bitValues[15 - bitIndex];
}
//-------------------------------------------


void setup() {
  //7-segment Pins
  for (int i = 1; i < 9; i++){
     pinMode(i,OUTPUT);
  }
  //LED lights
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  //IR Sensor Input
  pinMode(21,INPUT);
  turnAllOff();
  Serial.begin(9600);
  while(!Serial);
  
}

#define PRESTATE  -1
#define STARTSTATE 0
#define READSTATE  1
#define TIMERSTATE 2
#define ENDSTATE   3

int alarmRan = 0;
int timerIsOn = 0;
int startMilli= 0;
int prev = 0;
int curr = 0;
int state = PRESTATE; //Starting state is the PRESTATE
int bitNum = 15; 
int breakTaken = 0; //signifies the first 8 bits have been read
long timerTime, readTime = 0; //the total timer duration (in seconds)
int initialZero = 0;

void loop() {
  if(!initialZero == 1){
    displayNum(0);
    initialZero = 1;
  }
  switch(state){
    case PRESTATE:{
      //look for high IR value/IR transmitter is pointed at sensor
      if(digitalRead(IR) == HIGH){
        state = STARTSTATE;         //Now ready for initialization signal (drop in IR signal)
      }
      break;
    }
    case STARTSTATE:{
      //look for initialization signal drop
      if(digitalRead(IR) == LOW){
        startMilli = millis();
        state = READSTATE;        //Now ready to read first value
      }
      break;
    }
    case READSTATE:{
      //debug
      Serial.print("Reading Bitnumber: ");
      Serial.println(bitNum);
      ////////////
        if( bitNum == 7 && breakTaken == 0){ //once complete with first 8-bit signal read, reset to PRESTATE to wait for 2nd of 2 transmissions to start
          state = PRESTATE;
          breakTaken = 1;
          break;
        }
        if( bitNum < 0){ //all 16 bits have been read, set timer
          state = TIMERSTATE;
          break;
        }
        delay(10);    //wait 10ms for first signal
        readTime += readTransmission(bitNum,digitalRead(IR));
        if(bitNum == 0) delay(5);
        bitNum -=1;   
      break;
    }
    case TIMERSTATE:{
        //debug
      Serial.print("Time Read: ");
      Serial.println(readTime);
      ////////////
      timerIsOn = 1;
      timerTime = readTime;
      readTime = 0;      //reset readTime for potential future transmissions
      state = PRESTATE;  //set back to prestate for next transmission
      breakTaken = 0;
      bitNum = 15;       //set back to upper most position for next transmission
      int nowMilli = millis();
      int timePassed = nowMilli - startMilli;
      int timeLeft = timerTime - (timePassed/1000);
      if(timeLeft > 540)displayNum(9);
      else if(timeLeft > 480)displayNum(8);
      else if(timeLeft > 420)displayNum(7);
      else if(timeLeft > 360)displayNum(6);
      else if(timeLeft > 300)displayNum(5);
      else if(timeLeft > 240)displayNum(4);
      else if(timeLeft > 180)displayNum(3);
      else if(timeLeft > 120)displayNum(2);
      else if(timeLeft > 60) displayNum(1);
      else if(timeLeft < 60 && timeLeft > 0){
        displayNum(0);
      }
      break;
    }
    case ENDSTATE:{
      //display ALARM MESSAGE... up to you how to interpret that.
      timerCompletionDisplay();
      timerIsOn = 0;
      initialZero = 0;//display 0 on display
      //all values have been reset by this point
      state = PRESTATE;
      break;
    }
  }
  if(timerIsOn == 1){//this will run after timer has started, and needs to update values
    int nowMilli = millis();
    int timePassed = nowMilli - startMilli;
    int timeLeft = timerTime - (timePassed/1000);
    if(timeLeft > 540)displayNum(9);
    else if(timeLeft > 480){
       displayNum(8);
    }
    else if(timeLeft > 420){
      displayNum(7);
    }
    else if(timeLeft > 360){
      displayNum(6);
    }
    else if(timeLeft > 300){
      displayNum(5);
    }
    else if(timeLeft > 240){
      displayNum(4);
    }
    else if(timeLeft > 180){
      displayNum(3);
    }
    else if(timeLeft > 120)displayNum(2);
    else if(timeLeft > 60) displayNum(1);
    else if(timeLeft < 60 && timeLeft > 0){
        displayNum(0);
    }
    else if(timeLeft < 0){
      state = ENDSTATE;
    }
  }
}

/* Program: Triangle.ino
 * author:  Ben LaMasney
 * date:    10/22/19
 * purpose: -Calculate triangle area
 *          -Compare the Triangle class and triStruct sizes
 */
#include <cmath>

double getDiff(double, double);
void printCompare();

struct triStruct {
  double x1, y1;
  double x2, y2;
  double x3, y3;
};

class Triangle {
  public:
    Triangle();
    Triangle(double, double, double, double, double, double);
    ~Triangle();
    double getP1();
    double getP2();
    double getP3();
    void setP1(double, double);
    void setP2(double, double);
    void setP3(double, double);
    double getArea();
    
  private:
    double x1, y1;
    double x2, y2;
    double x3, y3;
};

Triangle::Triangle() {
  this->x1 = 0;
  this->y1 = 0; //base 1
  this->x2 = 0;
  this->y2 = 0; //base 2
  this->x3 = 0;
  this->y3 = 0; //top
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
  this->x3 = x3;
  this->y3 = y3;
}

Triangle::~Triangle() {
  /* free(this);
  do I need this? */
}


void Triangle::setP1(double x1, double y1) {
  this->x1 = x1;
  this->y1 = y1;
}

void Triangle::setP2(double x2, double y2) {
  this->x2 = x2;
  this->y2 = y2;
}

void Triangle::setP3(double x3, double y3) {
  this->x3 = x3;
  this->y3 = y3;
}

double getDiff(double p1, double p2){
  if(p1>p2)return (p1 - p2);
  else return (p2-p1);
}

/* - It is important to note, I procured Heron's area formula
   from: https://www.triangle-calculator.com/
   - I did not copy any program code, nor does the website have any available.
*/
double Triangle::getArea() {
  double l1XDiff, l1YDiff;
  double l2XDiff, l2YDiff;
  double l3XDiff, l3YDiff;
  double l1Length, l2Length, l3Length;
  double perimeter, semiP;
  double heronsArea;
  /* side 1: length */
  l1XDiff  = getDiff(this->x2, this->x1);
  l1YDiff  = getDiff(this->y2, this->y1);
  l1Length = sqrt( pow(l1XDiff, 2.0) + pow(l1YDiff, 2.0));

  /* side 2: length */
  l2XDiff  = getDiff(this->x3, this->x2);
  l2YDiff  = getDiff(this->y3, this->y2);
  l2Length = sqrt( pow(l2XDiff, 2.0) + pow(l2YDiff, 2.0));

  /* side 3: length */
  l3XDiff  = getDiff(this->x1, this->x3);
  l3YDiff  = getDiff(this->y1, this->y3);
  l3Length = sqrt( pow(l3XDiff, 2.0) + pow(l3YDiff, 2.0));

  perimeter = l1Length + l2Length + l3Length;
  semiP = perimeter / 2;
  heronsArea = sqrt( semiP * (semiP - l1Length) * (semiP - l2Length) * (semiP - l3Length));
  return heronsArea;
}

void printCompare() {
  Triangle t = Triangle();
  Serial.print("Size of Triangle class:   ");
  Serial.println(sizeof(t));
  Serial.print("Size of struct triStruct: ");
  Serial.println(sizeof(struct triStruct));
}

int led = 13;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
  printCompare();
}

void loop() { }

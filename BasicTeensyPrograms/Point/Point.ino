void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

class point {

  public:
    point();
    point(double, double, double);
    ~point();
    double getX();
    double getY();
    double getZ();
    void setX(double);
    void setY(double);
    void setZ(double);

  private:
    double x;
    double y;
    double z;
};

point::point() {
  x = 0;
  y = 0;
  z = 0;
}

point::point(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

point::~point() {
  free(this);
}

double point::getX() {
  return x;
}

double point::getY() {
  return y;
}

double point::getZ() {
  return z;
}

void point::setX(double x) {
  this->x = x;
}
void point::setY(double y) {
  this->y = y;
}
void point::setZ(double z) {
  this->z = z;
}

#include "Point.h"

void Point::Input(double x, double y){
    this -> x = x;
    this -> y = y;
}

void Point::Output(){
    cout << "Coordinates: (" << x << ',' << y << ')' << endl << endl;
}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}

double Point::Distance(Point another){
    return sqrt(pow(((this -> x) - another.getX()), 2) + pow(((this -> y) - another.getY()), 2));
}
#include "Point2D.h"

Point2D::Point2D(double x, double y){
    this -> x = x;
    this -> y = y;
}

void Point2D::input(){
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}

void Point2D::display(){
    cout << "(" << x << ", " << y << ")";
}

double Point2D::getX(){
    return x;
}

double Point2D::getY(){
    return y;
}

void Point2D::setX(double x){
    this -> x = x;
}

void Point2D::setY(double y){
    this -> y = y;
}

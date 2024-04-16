#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point2D{
private:
    double x;
    double y;
public:
    Point2D(double x = 0, double y = 0);
    void input();
    void display();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
};

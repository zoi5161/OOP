#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class Point{
private:
    double x;
    double y;
public:
    void Input(double x, double y);
    void Output();
    double getX();
    double getY();
    double Distance(Point another);
};
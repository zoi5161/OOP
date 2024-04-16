#pragma once
#include "Point2D.h"

class Rectangle{
private:
    Point2D* vertices;
public:
    Rectangle();
    ~Rectangle();
    void input();
    bool isValid();
    double perimeter();
    double area();
};

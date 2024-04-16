#pragma once

#include <iostream>
#include <math.h>
using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;
public:
    void enter(int numerator, int denominator);
    int getNumerator();
    int getDenominator();
    Fraction add(Fraction another);
    Fraction sub(Fraction another);
    Fraction multi(Fraction another);
    Fraction divide(Fraction another);
    void print();
};
#pragma once
#include <iostream>

using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;

public:
    Fraction(){
        this -> numerator = 0;
        this -> denominator = 1;
    }

    Fraction(const int numerator, const int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    double getValue(){
        return static_cast<double>(numerator) / denominator;
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction){
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

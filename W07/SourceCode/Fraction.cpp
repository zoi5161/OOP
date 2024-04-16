#include "Fraction.h"

void Fraction::SetValue(int numerator, int denominator){
    if(denominator == 0)
        throw DividedByZeroException();
    this -> numerator = numerator;
    this -> denominator = denominator;
}

int Fraction::GetNumerator() const{
    return numerator;
}

int Fraction::GetDenominator() const{
    return denominator;
}

void Fraction::print() const{
    cout << "Fraction: " << numerator << "/" << denominator << endl << endl;
}
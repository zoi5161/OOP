#include "Fraction.h"

void Fraction::enter(int numerator, int denominator){
    this -> numerator = numerator;
    this -> denominator = denominator;
} 

int Fraction::getNumerator(){
    return numerator;
}

int Fraction::getDenominator(){
    return denominator;
}

Fraction Fraction::add(Fraction another){
    int resNumerator = (this -> numerator) * another.getDenominator() + 
                            (this -> denominator) * another.getNumerator();
    int resDenominator = (this -> denominator) * another.getDenominator();
    Fraction res;
    res.enter(resNumerator, resDenominator);
    return res;
}

Fraction Fraction::sub(Fraction another){
    int resNumerator = (this -> numerator) * another.getDenominator() -
                            (this -> denominator) * another.getNumerator();
    int resDenominator = (this -> denominator) * another.getDenominator();
    Fraction res;
    res.enter(resNumerator, resDenominator);
    return res;
}

Fraction Fraction::multi(Fraction another){
    int resNumerator = (this -> numerator) * another.getNumerator();
    int resDenominator = (this -> denominator) * another.getDenominator();
    Fraction res;
    res.enter(resNumerator, resDenominator);
    return res;
}

Fraction Fraction::divide(Fraction another){
    int resNumerator = (this -> numerator) * another.getDenominator();
    int resDenominator = (this -> denominator) * another.getNumerator();
    Fraction res;
    res.enter(resNumerator, resDenominator);
    return res;
}

void Fraction::print(){
    double res = (this -> numerator) * 1.0 / (this -> denominator);
    cout << "Fraction form : " << (this -> numerator) << '/' << (this -> denominator) << endl;
    cout << "Decimal form: " << res << endl << endl;
}
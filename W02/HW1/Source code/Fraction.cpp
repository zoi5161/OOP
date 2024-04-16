#include "Fraction.h"

Fraction::Fraction(){
    this -> numerator = new int(0);
    this -> denominator = new int(1);
}

Fraction::Fraction(const int a, const int b){
    this -> numerator = new int;
    this -> denominator = new int;

    if(b < 0 && a < 0){
        *this -> numerator = abs(a);
        *this -> denominator = abs(b);
    }
    else if(b < 0){
        *this -> numerator = -a;
        *this -> denominator = abs(b);
    }
    else{
        *this -> numerator = a;
        *this -> denominator = b;
    }
}

Fraction::Fraction(const Fraction &p){
    this -> numerator = new int;
    this -> denominator = new int;

    *this -> numerator = *p.numerator;
    *this -> denominator = *p.denominator;
}

Fraction::~Fraction(){
    if(this -> numerator != NULL)
        delete this -> numerator;
    
    if(this -> denominator != NULL)
        delete this -> denominator;
}

Fraction &Fraction::operator = (const Fraction &p){
    *this -> numerator = *p.numerator;
    *this -> denominator = *p.denominator;
    return *this;
}

Fraction Fraction::operator + (const Fraction &p){
    Fraction c;

    c.numerator = new int;
    c.denominator = new int;

    *c.numerator = (*this -> numerator) * (*p.denominator) + (*this -> numerator) * (*p.numerator);
    *c.denominator = (*this -> denominator) * (*p.denominator);

    return c;
}

Fraction Fraction::operator - (const Fraction &p){
    Fraction c;

    c.numerator = new int;
    c.denominator = new int;

    *c.numerator = (*this -> numerator) * (*p.denominator) - (*this -> denominator) * (*p.numerator);
    *c.denominator = (*this -> denominator) * (*p.denominator);

    return c;
}

Fraction Fraction::operator * (const Fraction &p){
    Fraction c;

    c.numerator = new int;
    c.denominator = new int;

    *c.numerator = (*this -> numerator) * (*p.numerator);
    *c.denominator = (*this -> denominator) * (*p.denominator);

    return c;
}

Fraction Fraction::operator / (const Fraction &p){
    if(*p.numerator == 0){
        cout << "Cannot divide by zero!" << endl;
        return *this;
    }

    Fraction c;

    c.numerator = new int;
    c.denominator = new int;

    *c.numerator = (*this -> numerator) * (*p.denominator);
    *c.denominator = (*this -> denominator) * (*p.numerator);

    return c;
}

bool Fraction::operator == (const Fraction &p) const{
    return (*this -> numerator == *p.numerator) && (*this -> denominator == *p.denominator);
}

bool Fraction::operator != (const Fraction &p) const{
    return !(*this == p);
}

bool Fraction::operator >= (const Fraction& p) const {
    return (*this -> numerator * *p.denominator) >= (*p.numerator * *this -> denominator);
}

bool Fraction::operator > (const Fraction& p) const {
    return (*this -> numerator * *p.denominator) > (*p.numerator * *this -> denominator);
}

bool Fraction::operator <= (const Fraction& p) const {
    return (*this -> numerator * *p.denominator) <= (*p.numerator * *this -> denominator);
}

bool Fraction::operator < (const Fraction& p) const {
    return (*this -> numerator * *p.denominator) < (*p.numerator * *this -> denominator);
}

Fraction Fraction::operator += (const Fraction &p){
    *this -> numerator = (*this -> numerator) * (*p.denominator) + (*this -> denominator) * (*p.numerator);
    *this -> denominator = (*this -> denominator) * (*p.denominator);
    return *this;
}

Fraction Fraction::operator -= (const Fraction &p){
    *this -> numerator = (*this -> numerator) * (*p.denominator) - (*this -> denominator) * (*p.numerator);
    *this -> denominator = (*this -> denominator) * (*p.denominator);
    return *this;
}

Fraction Fraction::operator *= (const Fraction &p){
    *this -> numerator = (*this -> numerator) * (*p.numerator);
    *this -> denominator = (*this -> denominator) * (*p.denominator);
    return *this;
}

Fraction Fraction::operator /= (const Fraction &p){
    if(*p.numerator == 0){
        cout << "Cannot divide by zero!" << endl;
        return *this;
    }
    
    *this -> numerator = (*this -> numerator) * (*p.denominator);
    *this -> denominator = (*this -> denominator) * (*p.numerator);
    return *this;
}

Fraction &Fraction::operator ++ (){
    (*this -> numerator) += (*this -> denominator);
    return *this;
}

Fraction Fraction::operator ++ (int){
    Fraction temp(*this);
    (*this -> numerator) += (*this -> denominator);
    return temp;
}

Fraction &Fraction::operator -- (){
    (*this -> numerator) -= (*this -> denominator);
    return *this;
}

Fraction Fraction::operator -- (int){
    Fraction temp(*this);
    (*this -> numerator) -= (*this -> denominator);
    return temp;
}

Fraction Fraction::operator + (const int x) const{
    return Fraction(*numerator + x * *denominator, *denominator);
}

Fraction Fraction::operator - (const int x) const{
    return Fraction(*numerator - x * *denominator, *denominator);
}

Fraction Fraction::operator * (const int x) const{
    return Fraction(*numerator * x, *denominator);
}

Fraction operator + (int x, const Fraction &p){
    int new_num = x * (*p.denominator) + (*p.numerator);
    int new_denom = *p.denominator;
    Fraction result(new_num, new_denom);
    return result;
}


Fraction operator - (int x, const Fraction &p){
    int new_numerator = x * (*p.denominator) - *p.numerator;
    int new_denominator = *p.denominator;
    Fraction result(new_numerator, new_denominator);
    return result;
}

Fraction operator * (int x, const Fraction &p){
    int new_numerator = x * (*p.numerator);
    int new_denominator = *p.denominator;
    Fraction result(new_numerator, new_denominator);
    return result;
}

ostream &operator << (ostream &out, const Fraction &p){
    out << *p.numerator;
    if (*p.denominator != 1 && *p.numerator != 0)
        out << "/" << *p.denominator;
    return out;
}

Fraction::operator int(){
    return *numerator / *denominator;
}

Fraction::operator float(){
    return static_cast<float>(*numerator) / static_cast<float>(*denominator);
}
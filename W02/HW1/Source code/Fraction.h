#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Fraction{
    private:
        int *numerator;
        int *denominator;
    public:
        Fraction();
        Fraction(const int a, const int b);
        Fraction(const Fraction &p);
        ~Fraction();
        Fraction &operator = (const Fraction &p);
        Fraction operator + (const Fraction &p);
        Fraction operator - (const Fraction &p);      
        Fraction operator * (const Fraction &p);
        Fraction operator / (const Fraction &p);
        bool operator == (const Fraction &p) const;
        bool operator != (const Fraction &p) const;
        bool operator >= (const Fraction &p) const;
        bool operator > (const Fraction &p) const;
        bool operator <= (const Fraction &p) const;
        bool operator < (const Fraction &p) const;
        Fraction operator += (const Fraction &p);
        Fraction operator -= (const Fraction &p);
        Fraction operator *= (const Fraction &p);
        Fraction operator /= (const Fraction &p);
        Fraction &operator ++ ();
        Fraction operator ++ (int);
        Fraction &operator -- ();
        Fraction operator -- (int);
        Fraction operator + (const int x) const;
        Fraction operator - (const int x) const;
        Fraction operator * (const int x) const;
        friend Fraction operator + (int x, const Fraction &p);
        friend Fraction operator - (int x, const Fraction &p);
        friend Fraction operator * (int x, const Fraction &p);
        friend ostream &operator << (ostream &out, const Fraction &p);
        operator int();
        operator float();
};
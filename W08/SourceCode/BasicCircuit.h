#ifndef BASICCIRCUIT_h
#define BASICCIRCUIT_h

#include <iostream>

using namespace std;

class BasicCircuit {
    private:
        double resistance;
    public:
        BasicCircuit(double r) : resistance(r) {}
        virtual double CalculateResistance() const{
            return resistance;
        }
};

#endif

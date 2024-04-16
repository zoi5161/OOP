#ifndef SERIESCIRCUIT_h
#define SERIESCIRCUIT_h

#include "BasicCircuit.h"
#include <iostream>
#include <vector>

using namespace std;

class SeriesCircuit : public BasicCircuit {
    private:
        vector<BasicCircuit*> subCircuits;
    public:
        SeriesCircuit();
        void AddSubCircuit(BasicCircuit* circuit);
        double CalculateResistance() const;
};

#endif

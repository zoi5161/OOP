#ifndef PARALLELCIRCUIT_h
#define PARALLELCIRCUIT_h

#include "BasicCircuit.h"
#include <iostream>
#include <vector>

using namespace std;

class ParallelCircuit : public BasicCircuit {
    private:
        vector<BasicCircuit*> subCircuits;
    public:
        ParallelCircuit();
        void AddSubCircuit(BasicCircuit* circuit);
        double CalculateResistance() const;
};

#endif

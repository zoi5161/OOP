#ifndef SINGLECIRCUIT_h
#define SINGLECIRCUIT_h

#include "BasicCircuit.h"
#include <iostream>

using namespace std;

class SingleCircuit : public BasicCircuit {
    public:
        SingleCircuit(double r);
};

#endif

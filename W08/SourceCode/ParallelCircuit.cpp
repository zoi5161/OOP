#include "ParallelCircuit.h"

ParallelCircuit::ParallelCircuit() : BasicCircuit(0.0) {}

void ParallelCircuit::AddSubCircuit(BasicCircuit* circuit) {
    subCircuits.push_back(circuit);
}

double ParallelCircuit::CalculateResistance() const{
    double reciprocalResistance = 0.0;
    for (int i = 0; i < subCircuits.size(); i++)
        reciprocalResistance += 1.0 / subCircuits[i] -> CalculateResistance();
    return 1.0 / reciprocalResistance;
}
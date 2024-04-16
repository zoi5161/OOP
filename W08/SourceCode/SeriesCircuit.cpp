#include "SeriesCircuit.h"

SeriesCircuit::SeriesCircuit() : BasicCircuit(0.0) {}

void SeriesCircuit::AddSubCircuit(BasicCircuit* circuit) {
    subCircuits.push_back(circuit);
}

double SeriesCircuit::CalculateResistance() const {
    double totalResistance = 0.0;
    for (int i = 0; i < subCircuits.size(); i++)
        totalResistance += subCircuits[i] -> CalculateResistance();
    return totalResistance;
}
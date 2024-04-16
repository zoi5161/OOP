#include "Game.h"
#include "SingleCircuit.h"
#include "SeriesCircuit.h"
#include "ParallelCircuit.h"
#include "BasicCircuit.h"

Ball* Ball::instance = nullptr;

int main(){
    // Bai 1
    Game game;
    Ball::destroyInstance();
    cout << endl;

    // Bai 2
    SingleCircuit singleCircuit(5.0);

    SeriesCircuit seriesCircuit;
    seriesCircuit.AddSubCircuit(new SingleCircuit(2.0));
    seriesCircuit.AddSubCircuit(new SingleCircuit(3.0));

    ParallelCircuit parallelCircuit;
    parallelCircuit.AddSubCircuit(new SingleCircuit(4.0));
    parallelCircuit.AddSubCircuit(new SingleCircuit(6.0));

    cout << "Single Circuit Resistance (There is one circuit has resistance 5.0): " << singleCircuit.CalculateResistance() << " ohms\n";
    cout << "Series Circuit Resistance (There are two circuits have resistance 2.0 and 3.0): " << seriesCircuit.CalculateResistance() << " ohms\n";
    cout << "Parallel Circuit Resistance (There are two circuits have resistance 4.0 and 6.0): " << parallelCircuit.CalculateResistance() << " ohms\n";

    return 0;
}

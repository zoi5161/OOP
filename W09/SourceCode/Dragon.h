#ifndef DRAGON_h
#define DRAGON_h

#include "iostream"
#include "State.h"

using namespace std;

class State;

class Dragon{
    private:
        string name;
        int level;
        double health;
        double attack;
        double defense;
        State* state;
    public:
        Dragon();
        Dragon(string name, int level, double health, double attack, double defense);
        ~Dragon();

        string getName();
        int getLevel();
        double getHealth();
        double getAttack();
        double getDefense();
        
        void setState(State* state);
        void display();
        void displayDragonState();
        void attackState(Dragon& dragon);
        void moveState(Dragon& dragon);
        int calculatePower(Dragon& dragon);
};

#endif 

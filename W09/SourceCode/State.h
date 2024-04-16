#ifndef STATE_h
#define STATE_h

#include <iostream>
#include "Dragon.h"

using namespace std;

class Dragon;

class State{
    public:
        virtual void displayState() = 0;
        virtual int calculatePower(Dragon& dragon) = 0;
        virtual void attack(Dragon& dragon) = 0;
        virtual void move(Dragon& dragon) = 0;
        virtual ~State(){};
};

class NormalState : public State{
    public:
        void displayState();
        int calculatePower(Dragon& dragon);
        void attack(Dragon& dragon);
        void move(Dragon& dragon);
};

class RageState : public State{
    public:
        void displayState();
        int calculatePower(Dragon& dragon);
        void attack(Dragon& dragon);
        void move(Dragon& dragon);
};

class DefenseState : public State{
    public:
        void displayState();
        int calculatePower(Dragon& dragon);
        void attack(Dragon& dragon);
        void move(Dragon& dragon);
};

#endif

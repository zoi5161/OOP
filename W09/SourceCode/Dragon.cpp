#include "Dragon.h"

Dragon::Dragon(){
    this -> name = "N/A";
    this -> level = 0;
    this -> health = 0.0;
    this -> attack = 0.0;
    this -> defense = 0.0;
    state = nullptr;
}

Dragon::Dragon(string name, int level, double health, double attack, double defense){
    this -> name = name;
    this -> level = level;
    this -> health = health;
    this -> attack = attack;
    this -> defense = defense;
    state = nullptr;
}

Dragon::~Dragon(){
    delete state;
}

string Dragon::getName(){
    return name;
}

int Dragon::getLevel(){
    return level;
}

double Dragon::getHealth(){
    return health;
}

double Dragon::getAttack(){
    return attack;
}

double Dragon::getDefense(){
    return defense;
}

void Dragon::setState(State* state){
    if (this -> state != nullptr)
        delete this->state;
    this -> state = state;
}

void Dragon::display(){
    cout << "Tên: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl << endl;
}

void Dragon::displayDragonState(){
    state -> displayState();
}

void Dragon::attackState(Dragon& dragon){
    state -> attack(dragon);
}

void Dragon::moveState(Dragon& dragon){
    state -> move(dragon);
}

int Dragon::calculatePower(Dragon& dragon){
    return state -> calculatePower(dragon);
}
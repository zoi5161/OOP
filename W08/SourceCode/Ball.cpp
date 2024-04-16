#include "Game.h"

Ball* Ball::getInstance(){
    if (instance == NULL){
        instance = new Ball();
        cout << "Khoi tao thanh cong\n";
    }
    cout << "Da ton tai Ball\n";
    return instance;
}

void Ball::destroyInstance(){
    if (instance != NULL){
        delete instance;
        instance = nullptr;
    }
}

Ball::~Ball(){}
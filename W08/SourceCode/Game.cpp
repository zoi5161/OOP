#include "Game.h"

Game::Game(){
    ball = Ball::getInstance();
}

Game::~Game(){
    for (int i = 0; i < bricks.size(); i++)
        delete bricks[i];
    bar = NULL;
    ball = NULL;
}

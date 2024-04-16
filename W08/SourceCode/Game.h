#ifndef GAME_h
#define GAME_h

#include <iostream>
#include <vector>

using namespace std;

class Bar{};

class Ball{
    private:
        static Ball* instance;
        Ball(){}
    public:
        static Ball* getInstance();
        static void destroyInstance();
        ~Ball();
};

class Brick{};

class Game{
    private:
        vector<Brick*> bricks;
        Bar* bar;
        Ball* ball;
    public:
        Game();
        ~Game();
};

#endif

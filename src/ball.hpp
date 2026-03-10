#pragma once
#include<raylib.h>
#include<iostream>

class Ball{
    float velocityX;
    float posX;
    float posY;
    float velocityY;
    float gravity;
    float radius;
    bool applyGravity;
    public:
        Ball();
        void coordinateBall();
        void drawBall() const;
        void moveBall();
};


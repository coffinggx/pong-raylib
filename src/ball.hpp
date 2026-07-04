#ifndef BALL_H
#define BALL_H
#include<raylib.h>
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
        void updateBall(int*, int*);
        void updateBasedOnSlider(Rectangle);
        void resetPos();
};

#endif // !BALL_H

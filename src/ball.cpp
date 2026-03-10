#include "ball.hpp"
#include"config.hpp"
#include<vector>
#include<cmath>
#include<raylib.h>
void Ball::drawBall() const{
    Vector2 ball_coords  { posX,posY};
    DrawCircleV(ball_coords,radius,DARKBROWN);
}
void Ball::coordinateBall(){
    // if (IsKeyDown(KEY_RIGHT)) posX += 2.0f;
    // if (IsKeyDown(KEY_LEFT)) posX -= 2.0f;
    // if (IsKeyDown(KEY_UP)) posY -= 2.0f;
    // if (IsKeyDown(KEY_DOWN)) posY+= 2.0f;
    

}

Ball::Ball(){
    gravity = 800.0f;
    velocityX = 100.0f;
    velocityY = 90.0f;
    radius = 10.0f;
    applyGravity =true;
    posX=(float)width/2;
    posY = (float)height/2;
}

void Ball::moveBall(){
    float dt = GetFrameTime();
    
    if(applyGravity){
        velocityY += gravity * dt;
    }
    float newX = posX + velocityX*dt*10;
    float newY = posY + velocityY * dt * 10;

    if (newX <= radius || newX >= GetScreenWidth() - radius){
        velocityX *= -1.0f;
    }
    if (velocityY == 0){
        velocityX *=  0.0f;
    }
    if (newY >= GetScreenHeight() - radius){
        newY = GetScreenHeight() - radius;     

        if (velocityY > 0.8f)                 
        {
            velocityY *= -0.92f;              
        }
        else
        {
            velocityY = 0.0f;
        }

        const float ground_friction = 0.98f;  
        velocityX *= ground_friction;

        if (fabs(velocityX) < 0.01f)
            velocityX = 0.0f;
    } else if (newY <= radius){
        newY =radius;
        velocityY *= 0.95f;
    }

    posX = newX;
    posY = newY;
}

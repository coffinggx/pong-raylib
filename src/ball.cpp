#include "ball.hpp"
#include<vector>
#include"config.hpp"
#include<raylib.h>
void Ball::drawBall() const{
    Vector2 ball_coords  { posX,posY};
    DrawCircleV(ball_coords,radius,DARKBROWN);
}
Ball::Ball(){
    velocityX = 10.0;
    velocityY = 10.0f;
    radius = 10.0f;
    applyGravity =true;
    posX=(float)width/2;
    posY = (float)height/2;
}
void Ball::resetPos(){
    posY = (float)GetScreenHeight()/2;
    posX = (float)GetScreenWidth()/2;
    std::vector choice  {-1,1};
    velocityX *= choice.at(GetRandomValue(0, 1));
    velocityY *= choice.at(GetRandomValue(0, 1));
}
void Ball::updateBall(){
    posX += velocityX;
    posY +=velocityY;

    if(posY + radius >= GetScreenHeight()|| posY - radius  <= 0){
        velocityY *= -1;
    }
    if (posX+radius >= GetScreenWidth() ){
        resetPos();
    }
    if(posX - radius <= 0){
        resetPos();
    }
 }

void Ball::updateBasedOnSlider(Rectangle rect){
    if(CheckCollisionCircleRec(Vector2{posX,posY}, radius,rect)){
        velocityX *= -1;
    }
}





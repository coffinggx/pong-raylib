#include<raylib.h>
#include "slider.hpp"
Slider::Slider(){
    height = 0;
    width = 0;
}

Slider::Slider(float width, float height, Type type){
    this->width = width;
    this->height = height;
    this->type = type;
    speed = 10.0f;
    if(type == Type::LEFT){
        posX = 10.0f;
        posY = (float)GetScreenHeight() /2 - height/2;
    } else {
        posX =  GetScreenWidth() - width - 10.0f;
        posY = (float)GetScreenHeight() /2 - height/2;
    }
}

void Slider::drawSlider() const{
    DrawRectangle(posX, posY,width,height,DARKPURPLE);
}
Rectangle Slider::getInfo() const{
    return Rectangle{
        posX,
        posY,
        width,
        height
    };
}
void Slider::moveSlider() {
    // std::cout << "PosY: " << posY << "PosX: " << posX << '\n';
    if (type == Type::LEFT){
        if (IsKeyDown(KEY_W) && posY >= 0) posY -= speed;
        if(IsKeyDown(KEY_S) && posY <= GetScreenHeight() - height ) posY += speed;
    } else{
        if (posY <= 0.0f) posY += 0.0f;
        if (IsKeyDown(KEY_UP) && posY >= 0) posY -= speed;
        if(IsKeyDown(KEY_DOWN) && posY<= GetScreenHeight() - height) posY += speed;
    }
}



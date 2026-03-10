#include<iostream>
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
    if(type == Type::LEFT){
        posX = 0.0f;
        posY = 0.0f;
    } else {
        posX =  GetScreenWidth() - width;
        posY = 0;
    }
}

void Slider::drawSlider() const{
    DrawRectangle(posX, posY,width,height,DARKPURPLE);
}

void Slider::moveSlider() {
    // std::cout << "PosY: " << posY << "PosX: " << posX << '\n';
    if (type == Type::LEFT){
        if (IsKeyDown(KEY_W) && posY >= 0) posY -= 5.0f;
        if(IsKeyDown(KEY_S) && posY <= GetScreenHeight() - height ) posY += 5.0f;
    } else{
        if (posY <= 0.0f) posY += 0.0f;
        if (IsKeyDown(KEY_UP) && posY >= 0) posY -= 5.0f;
        if(IsKeyDown(KEY_DOWN) && posY<= GetScreenHeight() - height) posY += 5.0f;
    }
}

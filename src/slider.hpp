#pragma once
#include<raylib.h>
enum class Type{
    LEFT,
    RIGHT
};
class Slider{
    float width;
    float height;
    float posX;
    float posY;
    float speed;
    Type type;
    public:
        Slider();
        Slider(float, float,Type);
        void drawSlider()const;
        void moveSlider();
        Rectangle getInfo() const;
};

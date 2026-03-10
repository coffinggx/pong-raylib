#include <raylib.h>
#include "config.hpp"
#include<iostream>
#include "ball.hpp"
#include "slider.hpp"
int main() 
{
    InitWindow(width,height, "Raylib program");
    SetTargetFPS(1000);
    Ball ball; 
    Slider leftSlider = Slider(10.0f,  GetScreenWidth()/3,Type::LEFT);
    Slider rightSlider = Slider(10.0f, GetScreenWidth()/3,Type::RIGHT);
    while (!WindowShouldClose())
    {
        leftSlider.moveSlider();
        rightSlider.moveSlider();
        int fps = GetFPS();
        const char * fps_s= std::to_string(fps).c_str();
        BeginDrawing();
            DrawText(fps_s, 14,0,16,WHITE);
            ball.drawBall(); 
            leftSlider.drawSlider();
            rightSlider.drawSlider();
            ball.moveBall();
            ClearBackground(Color{ 50, 175, 50, 255 });
        EndDrawing();
    }
    
    CloseWindow();
}

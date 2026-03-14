#include <raylib.h>
#include "config.hpp"
#include "ball.hpp"
#include "slider.hpp"
int main() 
{
    InitWindow(width,height, "Raylib program");
    SetTargetFPS(60);
    Ball ball; 
    Slider leftSlider = Slider(10.0f, 30.0f,Type::LEFT);
    Slider rightSlider = Slider(10.0f,30.0f,Type::RIGHT);
    while (!WindowShouldClose())
    {
        leftSlider.moveSlider();
        rightSlider.moveSlider();
        int fps = GetFPS();
        BeginDrawing();
            DrawText(TextFormat("Player1: %d",4), 14,0,16,WHITE);
            DrawText(TextFormat("Player2: %d",4), width - 100,0,16,WHITE);
            ball.drawBall(); 
            leftSlider.drawSlider();
            rightSlider.drawSlider();
            DrawLine(width/2,0,width/2,height,WHITE);
            ball.updateBall();
            ClearBackground(Color{0, 0, 0, 255 });
            ball.updateBasedOnSlider(leftSlider.getInfo());
            ball.updateBasedOnSlider(rightSlider.getInfo());
        EndDrawing();
    }
    
    CloseWindow();
}

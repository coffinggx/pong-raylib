#include <raylib.h>
#include "config.hpp"
#include "ball.hpp"
#include "slider.hpp"

typedef enum GameScreen { STARTMENU = 0 , GAMESTATE, OVERSCREEN } GameScreen;

int main() 
{
    const float SLIDERHEIGHT { 100.0f };
    const float SLIDERWIDTH { 10.0f };
 
    int player1Score { 0 };
    int player2Score { 0 };
    const int MAXSCORE { 5 };
    InitWindow(width,height, "Raylib program");
    SetTargetFPS(60);
    Ball ball; 
    Slider leftSlider = Slider(SLIDERWIDTH, SLIDERHEIGHT,Type::LEFT);
    Slider rightSlider = Slider(SLIDERWIDTH, SLIDERHEIGHT,Type::RIGHT);
    bool startAgain { 0};
    GameScreen currentScreen { STARTMENU };

    while (!WindowShouldClose())
    {
        switch(currentScreen){
            case STARTMENU:
            {
                if(IsKeyPressed(KEY_SPACE)){
                    currentScreen = GAMESTATE;
                }
            } break;
            
            case GAMESTATE:
            {
                leftSlider.moveSlider();
                rightSlider.moveSlider();
                ball.updateBall(&player1Score, &player2Score);
                ball.updateBasedOnSlider(leftSlider.getInfo());
                ball.updateBasedOnSlider(rightSlider.getInfo());

                if(player1Score == MAXSCORE || player2Score == MAXSCORE){
                    player1Score = 0;
                    player2Score = 0;
                    currentScreen  = OVERSCREEN;
                }
            } break;
            case OVERSCREEN:
            {
                if(IsKeyPressed(KEY_SPACE)){
                    currentScreen = GAMESTATE;
                }
            } break;
            default: break;
        }
            BeginDrawing();
            ClearBackground(Color{1, 0, 0, 255 });
            switch(currentScreen){
                case GAMESTATE:
                {
                    DrawText(TextFormat("Player1: %d",player1Score), 14,0,16,WHITE);
                    // DrawText(TextFormat("Fps: %d", fps), 100, 0, 15, WHITE);
                    DrawText(TextFormat("Player2: %d",player2Score), width - 100,0,16,WHITE);
                    ball.drawBall(); 
                    leftSlider.drawSlider();
                    rightSlider.drawSlider();
                    DrawLine(width/2,0,width/2,height,WHITE);
                } break;
                case STARTMENU:
                {
                    DrawText("Press Space to begin game", width / 3 , height/2, 50, WHITE);
                } break;
                case OVERSCREEN:
                {
                    DrawText("Press Space to restart game again", width / 4 , height/2, 50, WHITE);
                } break;
                default: break;
            }
            EndDrawing();
    }
    
    CloseWindow();
}

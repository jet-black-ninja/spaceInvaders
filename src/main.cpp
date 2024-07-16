#include <raylib.h>
#include "game.hpp"
#include <string>

std:: string FormatWithLeadingZeros(int number , int width){
    std::string numberText = std::to_string(number);
    int leadingZero = width - numberText.length();
    return numberText = std::string(leadingZero, '0') + numberText;
}
int main() {
    int windowWidth = 750;
    int windowHeight = 700;
    int offset = 50;
    Color GREY = {29, 29, 27, 255}; //bg color
    Color yellow = {243, 216, 63 , 255};
    InitWindow(windowWidth + offset, windowHeight+ 2 * offset, "Space Invaders");
    
    Font font = LoadFontEx("Font/monogram.tff", 64 ,0 , 0);
    SetTargetFPS(60);
    Texture2D spaceshipImage= LoadTexture("Graphics/spaceship.png");
    Game game;
    
    while(WindowShouldClose()==false){
    
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(GREY);
        game.Draw();
        DrawRectangleRoundedLines({10,10, 780, 780}, 0.18f, 20, 2 , yellow);
        DrawLineEx({25, 730}, {730, 730 }, 3, yellow);
        if(game.run){
        DrawTextEx(font, "LEVEL 01", {570,740}, 34, 2, yellow);
        } else{
            DrawTextEx(font, "GAME OVER", {570,740}, 34, 2, yellow);
        }
        float x= 50.0;
        for(int i = 0 ; i< game.lives ;i++){
            DrawTextureV(spaceshipImage,{x, 745}, WHITE);
            x+=50;
        }
        DrawTextEx(font ,"SCORE",{50,15},34,2,yellow );
        std::string scoreText = FormatWithLeadingZeros(game.score,5);
        DrawTextEx(font , scoreText.c_str(), {50,40}, 34, 2, yellow);
        EndDrawing();
    
    }
    CloseWindow();
    return 0;
}
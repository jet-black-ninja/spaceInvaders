#include <raylib.h>
#include "game.hpp"


int main() {
    int windowWidth = 1920;
    int windowHeight = 1080;
    Color GREY = {29, 29, 27, 255}; //bg color
    
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(60);
    Game game;
    
    while(WindowShouldClose()==false){
    
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(GREY);
        game.Draw();
        
        EndDrawing();
    
    }
    CloseWindow();
    return 0;
}
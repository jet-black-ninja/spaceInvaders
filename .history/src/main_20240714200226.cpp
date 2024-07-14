#include <raylib.h>
#include "game.hpp"
#include "laser.hpp"
int main() {
    int windowWidth = 1920;
    int windowHeight = 1080;
    Color GREY = {29, 29, 27, 255}; //bg color
    
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(144);
    Game game;
    Laser laser = l
    while(WindowShouldClose()==false){
    
        game.HandleInput();
        BeginDrawing();
        ClearBackground(GREY);
        game.Draw();
        EndDrawing();
    
    }





    CloseWindow();
    return 0;
}
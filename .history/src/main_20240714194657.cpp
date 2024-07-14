#include <raylib.h>
#include "game.hpp";

int main() {
    int windowWidth = 1920;
    int windowHeight = 1080;
    Color GREY = {29, 29, 27, 255}; //bg color
    
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(144);
    Game game;

    while(WindowShouldClose()==false){
    
        BeginDrawing();
        ClearBackground(GREY);
        
        EndDrawing();
    
    }





    CloseWindow();
    return 0;
}
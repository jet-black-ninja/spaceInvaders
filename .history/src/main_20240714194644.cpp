#include <raylib.h>
#include "game.h"

int main() {
    int windowWidth = 1920;
    int windowHeight = 1080;
    Color GREY = {29, 29, 27, 255}; //bg color
    
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(144);
    

    while(WindowShouldClose()==false){
    
        BeginDrawing();
        ClearBackground(GREY);
        spaceship.Draw();
        EndDrawing();
    
    }





    CloseWindow();
    return 0;
}
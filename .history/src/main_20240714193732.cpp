#include <raylib.h>
#include <spaceship.hpp"

int main() {
    int windowWidth = 1920;
    int windowHeight = 1080;
    Color GREY = {29, 29, 27, 255}; //bg color
    SetTargetFPS(144);
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    while(WindowShouldClose()==false){
    
        BeginDrawing();
        ClearBackground(GREY);
        EndDrawing();
    
    }





    CloseWindow();
    return 0;
}
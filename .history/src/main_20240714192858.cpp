#include <raylib.h>


int main() {
    int windowWidth = 1920;
    int windowHeight = 1080;
    Color GREY = (29,29,27255);
    SetTargetFPS(144);
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    while(WindowShouldClose()==false){
    
        BeginDrawing();
        EndDrawing();
    
    }





    CloseWindow();
    return 0;
}
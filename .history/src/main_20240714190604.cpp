#include <raylib.h>


int main()
{
    InitWindow(800, 800, "my first game");
    SetTargetFPS(60);
    
    //Game loop
    while(WindowShouldClose() == false) {
        //event handling

        //updating position

        //drawing
        BeginDrawing();
        DrawCircle()
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
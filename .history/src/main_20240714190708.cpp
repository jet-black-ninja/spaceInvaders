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
        DrawCircle(400, , 20, WHITE);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
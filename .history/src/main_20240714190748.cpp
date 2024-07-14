#include <raylib.h>


int main()
{
    int ballX= 400;
    int ballY= 400
    InitWindow(800, 800, "my first game");
    SetTargetFPS(60);
    
    //Game loop
    while(WindowShouldClose() == false) {
        //event handling

        //updating position

        //drawing
        BeginDrawing();
        DrawCircle(ballX, ball, 20, WHITE);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
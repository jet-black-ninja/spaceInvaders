#include <raylib.h>


int main()
{
    InitWindow(800, 800, "my first game");
    
    //Game loop
    while(WindowShouldClose() == false) {
        //event handling

        //updating position

        //drawing
        BeginDrawing();
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
#include <raylib.h>


int main()
{
    int ballX= 400;
    int ballY= 400;
    int direction = 0;
    Color green = {255, 255 ,0 , 100};
    InitWindow(800, 800, "my first game");
    SetTargetFPS(60);
    
    //Game loop
    while(WindowShouldClose() == false) {
        //event handling

        //updating position 
        if(ballX +20>800){
            direction=1;
        }
        if(ballX-20<0){
            direction=0;
        }
        if(direction){
            ballX-=3;
        } else{
            ballX+=3;
        }

        
        //drawing
        BeginDrawing();
        ClearBackground(gre);
        DrawCircle(ballX, ballY, 20, WHITE);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
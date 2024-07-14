#include "spaceship.hpp"

int moveDegree=5;
int leftBorder= 0;
int rightBorder=
Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() -image.width)/2;
    position.y = GetScreenHeight() - image.height -20;
}

Spaceship::~Spaceship(){
    UnloadTexture(image);
}

void Spaceship::Draw(){
    DrawTextureV(image, position,WHITE);
}

void Spaceship::MoveLeft(){
    position.x-=moveDegree;

    if(position.x<0){
        position.x=0;
    }
}

void Spaceship::MoveRight(){
    position.x+=moveDegree;

    if(positoin.x>GetScreenWidth()-image.width){
        positoin.x=GetScreenWidth()-image.width;
    }
}
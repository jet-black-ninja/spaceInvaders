#include "spaceship.hpp"

int moveDegree=5;
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

    if(position.x> GetScreenWidth()-image.width){
        position.x=GetScreenWidth()-image.width;
    }
}

void Spaceship::FireLaser()
{
    lasers.push_back(Laser({position.x + image.width/2 - 2},-6))
}


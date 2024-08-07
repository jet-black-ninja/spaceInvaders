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

void Spaceship::moveLeft(){
    position.x=-moveDegree;
}

void Spaceship::moveRight(){
    position.x+=moveDegree;
}
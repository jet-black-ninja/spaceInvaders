#include "spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth);
    position.y = 100;
}

Spaceship::~Spaceship(){
    UnloadTexture(image);
}

void Spaceship::Draw(){
    DrawTextureV(image, position,WHITE);
}
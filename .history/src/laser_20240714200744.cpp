#include "laser.hpp"
#include <raylib.h>
Color yellow= {243,216,63,255};
Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
}

void Laser::Draw(){
    DrawRectangle(position.x, position.y, 4, 15, yellow);
}

void Laser::Update(){
    position.y+=speed;
}
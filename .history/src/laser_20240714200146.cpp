#include "laser.hpp"
#include <raylib.h>
Color yellow= {243,216,63,255};
Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
}

void Laser::Draw(){
    DrawRectangle(positon.x, position.y, 4, 15, {});
}
#include "laser.hpp"

Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
}

void Laser::
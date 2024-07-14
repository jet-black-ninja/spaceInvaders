#include "laser.hpp"
#include <raylib.h>
Color yellow= {243,216,63,255};
Laser::Laser(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void Laser::Draw(){
    if(active){
    DrawRectangle(position.x, position.y, 4, 15, yellow);
    }
}

void Laser::Update(){
    position.y+=speed;
    if(active){
        if(position.y > GetScreenHeight() || position.y <0 ){
            
        }
    }
}
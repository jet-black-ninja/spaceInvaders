#pragma once
#include<raylib.h>

#include "laser.h"
class Spaceship{
    public: 
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();

    private:
        Texture2D image;
        Vector2 position;
};
#pragma once
#include <raylib.h>


class Laser{
    public:
        Laser(Vector2 position, int speed);
        void Update();
        void Draw();
        ~Laser();
    private:
    Vector2 position
};
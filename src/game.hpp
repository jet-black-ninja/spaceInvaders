#pragma once
#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();

    private:
    void DeleteInactiveLaser();
    std::vector<Obstacle> CreateObstacles();
    std::vector<Alien> CreateAliens();
    void moveAliens();
    Spaceship spaceship; 
    void AlienShootLaser();
    void MoveDownAliens(int distance);
    std:: vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    int aliensDirection;
    std::vector<Laser> alienLasers;
    constexpr static float alienLaserShootInterval = 0.5;
    float timeLastAlienFired;
};
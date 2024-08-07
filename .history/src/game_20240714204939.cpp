#include "game.hpp"
#include
Game::Game()
{
}

Game::~Game(){

}

void Game::Update() {
    for(auto & laser: spaceship.lasers){
        laser.Update();
    }
    DeleteInactiveLaser();
}

void Game::Draw() {
    spaceship.Draw();
    for (auto & laser : spaceship.lasers) {
        laser.Draw();
    }
}

void Game::HandleInput() {
    if(IsKeyDown(KEY_LEFT)) {
        spaceship.MoveLeft();
    } 
    else if(IsKeyDown(KEY_RIGHT)) {
        spaceship.MoveRight();
    }else if(IsKeyDown(KEY_SPACE)) {
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveLaser()
{
    for(auto it = spaceship.lasers.begin() ; it!= spaceship.lasers.end(); ){
        if(!it->active){
            it = spaceship.lasers.erase(it);
        }else {
            it++;
        }
    }
}

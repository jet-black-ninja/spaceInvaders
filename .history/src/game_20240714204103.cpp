#include "game.hpp"

Game::Game()
{
}

Game::~Game(){

}

void Game::Update(){
    
}

void Game::Draw(){
    spaceship.Draw();
    for (auto & laser : spaceship.lasers){
        laser.Draw();
    }
}

void Game::HandleInput(){
    if(IsKeyDown(KEY_LEFT)){
        spaceship.MoveLeft();
    } 
    else if(IsKeyDown(KEY_RIGHT)){
        spaceship.MoveRight();
    }else if(IsKeyDown(KEY_SPACE)) {
        spaceship.FireLaser();
    }
}
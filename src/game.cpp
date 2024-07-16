#include "game.hpp"
#include <iostream>
#include <fstream>

Game::Game()
{
    music =LoadMusicStream("Sounds/music.ogg");
    explosionSound = LoadSound("Sounds/explosion.ogg");
    PlayMusicStream(music);
    InitGame();
}

Game::~Game(){
Alien::UnloadImages();
UnloadMusicStream(music);
}

void Game::Update() {
    if(run){
        double currentTime = GetTime();
        if(currentTime - timeLastSpawn > mysteryShipSpawnInterval){
            mysteryShip.Spawn();
            timeLastSpawn=GetTime();
            mysteryShipSpawnInterval=GetRandomValue(10,20);
        }
        for(auto & laser: spaceship.lasers){
            laser.Update();
        }
        moveAliens();

        AlienShootLaser();
        for(auto & laser: alienLasers){
            laser.Update();
        }
        DeleteInactiveLaser();
        mysteryShip.Update();
        CheckForCollisions();
    } else {
        if(IsKeyDown(KEY_ENTER)){
            Reset();
            InitGame();
        }
    }
}

void Game::Draw() {
    spaceship.Draw();
    for (auto & laser : spaceship.lasers) {
        laser.Draw();
    }

    for(auto & obstacle: obstacles){
        obstacle.Draw();
    }

    for(auto & alien : aliens){
        alien.Draw();
    }
    for(auto & laser : alienLasers ){
        laser.Draw();
    }
    mysteryShip.Draw();
}

void Game::HandleInput() {
    if(run){    
        if(IsKeyDown(KEY_LEFT)) {
            spaceship.MoveLeft();
        } 
        else if(IsKeyDown(KEY_RIGHT)) {
            spaceship.MoveRight();
        }else if(IsKeyDown(KEY_SPACE)) {
            spaceship.FireLaser();
        }
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
    for(auto it = alienLasers.begin() ; it!= alienLasers.end(); ){
        if(!it->active){
            it = alienLasers.erase(it);
        }else {
            it++;
        }
    }
}


std::vector<Obstacle> Game::CreateObstacles()
{
    int obstacleWidth = Obstacle::grid[0].size() *3;
    float gap = (GetScreenWidth() - (4 * obstacleWidth))/5;
    for(int i = 0; i< 4 ; i++){
        float offsetX = (i+1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX,float(GetScreenHeight() - 200 )}));
    }
    return obstacles;
}

std::vector<Alien> Game::CreateAliens()
{
    std::vector<Alien> aliens;
    for(int row = 0 ;row < 5 ; row++){
        for(int col= 0 ; col < 11 ;col++ ){

            int alienType ;
            if(row == 0){
                alienType = 3;
            } else if (row == 1 || row ==2){
                alienType = 2;
            } else{
                alienType = 1;
            }

            float x = 75 + col * 55;
            float y = 110 + row * 55;
            aliens.push_back(Alien(alienType, {x,y}));
        }
    }
    return aliens;
}

void Game::moveAliens(){
    for(auto & alien: aliens){
        if(alien.position.x + alien.alienImages[alien.type -1].width > GetScreenWidth() -25 ){
            aliensDirection = -1;
            MoveDownAliens(4);
        }
        if(alien.position.x < 25){
            aliensDirection = 1;
            MoveDownAliens(4);
        }
        alien.Update(aliensDirection);
    }

}

void Game::MoveDownAliens(int distance)
{
    for (auto & alien : aliens ){
        alien.position.y += distance;
    }
}

void Game::AlienShootLaser()
{   
    double currentTime =GetTime();
    if(currentTime - timeLastAlienFired >= alienLaserShootInterval && !aliens.empty()){
    int randomIndex = GetRandomValue(0, aliens.size()-1);
    Alien & alien = aliens[randomIndex];
    alienLasers.push_back(Laser({alien.position.x + alien.alienImages[alien.type -1].width/2,
                                alien.position.y + alien.alienImages[alien.type - 1].height },6));
    timeLastAlienFired = GetTime();
    }
}

void Game::CheckForCollisions(){
    //spaceship lasers

    for(auto & laser : spaceship.lasers){
        auto it = aliens.begin();
        while(it!=aliens.end()){
            if(CheckCollisionRecs(it ->getRect(), laser.getRect())){

                PlaySound(explosionSound);
                if(it->type ==1){
                    score += 100;
                }  else if( it-> type==2){
                    score += 200;
                }else if(it->type ==3){
                    score += 300;
                }
                CheckForHighScore();
                it = aliens.erase(it);
                laser.active = false;
            }else{
                ++it;
            }
            
        }
        for(auto & obstacle : obstacles){
            auto it = obstacle.Blocks.begin();
            while(it != obstacle.Blocks.end()){
                if(CheckCollisionRecs(it->getRect() , laser.getRect())){
                    it = obstacle.Blocks.erase(it);
                    laser.active= false;
                }else {
                    it++;
                }
            }
        }
    if(CheckCollisionRecs(mysteryShip.getRect(), laser.getRect())){
        PlaySound(explosionSound);
        score+=500;
        mysteryShip.alive = false;
        laser.active = false;
        CheckForHighScore();
    }
    }

    for(auto & laser : alienLasers){
        if(CheckCollisionRecs(laser.getRect(), spaceship.getRect())){
            laser.active = false;
            lives--;
            if(!lives){
                GameOver();
            }
        }

        for(auto & obstacle : obstacles){
            auto it = obstacle.Blocks.begin();
            while(it != obstacle.Blocks.end()){
                if(CheckCollisionRecs(it->getRect() , laser.getRect())){
                    it = obstacle.Blocks.erase(it);
                    laser.active= false;
                }else {
                    it++;
                }
            }
        }
    }

    //alien collisions

    for(auto & alien : aliens){
        for(auto & obstacle : obstacles){
            auto it= obstacle.Blocks.begin();
            while(it!= obstacle.Blocks.end()){
                if(CheckCollisionRecs(it->getRect(), alien.getRect())){
                    it= obstacle.Blocks.erase(it);
                }else{
                    it++;
                }
            }
        }

        if(CheckCollisionRecs(alien.getRect(),spaceship.getRect())){
            GameOver();
        }
    }
}

void Game::GameOver()
{
    run = false;
}

void Game::InitGame()
{
    obstacles = CreateObstacles();
    aliens = CreateAliens();
    aliensDirection = 1;
    timeLastAlienFired = 0.0;
    timeLastSpawn = 0.0;
    mysteryShipSpawnInterval = GetRandomValue(10,20);
    lives = 3;
    run = true;
    score = 0;
    highScore = loadHighScoreFromFile();

}
void Game::Reset(){
    spaceship.Reset();
    aliens.clear();
    alienLasers.clear();
}

void Game::CheckForHighScore()
{
    if(score>highScore){
        highScore = score;
        saveHighScoreToFile(highScore);
    }
}

void Game::saveHighScoreToFile(int highScore)
{
    std::ofstream highScoreFile("highScore.txt");
    if(highScoreFile.is_open()){
        highScoreFile<< highScore;
        highScoreFile.close();
    }else {
    std:: cerr <<"Failed To Save HighScore To File" << std::endl;
    }
}

int Game::loadHighScoreFromFile()
{
    int loadedHighScore = 0;
    std::ifstream highScoreFile("highScore.txt");
    if(highScoreFile.is_open()){
        highScoreFile >> loadedHighScore;
        highScoreFile.close();
    }else {
        std:: cerr<< "Failed to Load HighScore to File" <<std::endl;
    }
    return loadedHighScore;
}

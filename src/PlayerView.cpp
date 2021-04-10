// Updated by Zack on 3/1
#include "PlayerView.h"

PlayerView::PlayerView(){
    //Will need better idea of what this is keeping track of before implementing
    window.create(sf::VideoMode(800,600,32), "COVID Champion");
    font.loadFromFile("insert font here");
    texture.loadFromFile("insert texture here");
}

void PlayerView::init(){
    //Sets up initial state, probably loads up main menu or something
}

void PlayerView::update(){
    //Will likely want to change return type to better react to this call
}

// void Game::render()
// {
//     this->app.clear();
//     this->app.draw(this->player);
//     this->app.display();
// }

// interpret events here, then send queueEvent to EventManager
// Updated by Zack on 4/10
#include "PlayerView.h"

PlayerView::PlayerView(){
    //Might want additional fonts/textures in future, but early build will just have one texture
    window.create(sf::VideoMode(800,600,32), "COVID Champion");
    font.loadFromFile("insert font here");
    texture.loadFromFile("..\\data\\ThirdSpriteSheet.png");
    background[192];
}

void PlayerView::init(){
    //Sets up initial state, probably loads up main menu or something
}

void PlayerView::createBG(int* map){
    // Creates the inital background state based on map provided by Stage
    int i;
    int Xpos, Ypos;
    for(i = 0; i < sizeof(map)/sizeof(map[0]); i++){
        // Creates sprite for each tile and gives Texture to the sprite
        // Calculates position using integer division before applying to sprite, which uses floats
        Xpos = 50*(i%16);
        Ypos = 50*(i/16);
        background[i] = SpriteActor(Xpos, Ypos, 450, 0, 50, 50);
        background[i].setTexture(texture);

        // Sets the IntRect's location to where the desired image is
        // Currently using ThirdSpriteSheet's layout, will need to update alongside art changes
        switch(map[i]){

            // Basic Background
            case 0:
                // No change necessary, input in constructor defaulted to Basic BG
                break;
            // Home Base. 2 is skipped due to current design
            case 1:
                background[i].setViewLocation(0, 0);
                break;
            // Potential Tower Location, skips 4 since shouldn't be any prebuilt towers
            case 3:
                background[i].setViewLocation(300, 0);
                break;
            // North-South Path
            case 5:
                background[i].setViewLocation(200, 0);
                break;
            // East-West Path
            case 6:
                background[i].setViewLocation(150, 0);
                break;
            // South-East Corner
            case 7:
                background[i].setViewLocation(100, 0);
                break;
            // South-West Corner
            case 8:
                background[i].setViewLocation(400, 0);
                break;
            // North-East Corner
            case 9:
                background[i].setViewLocation(50, 0);
                break;
            // North-West Corner
            case 10:
                background[i].setViewLocation(350, 0);
                break;
        }
    }
}

void Playerview::drawBG(){
    //Draws everything contained in the list of background tiles
    int i;
    for(i = 0; i < sizeof(background)/sizeof(background[0]); i++){
        window.draw(background[i].getSprite());
    }
}

void PlayerView::update(){
    //Will likely want to change return type to better react to this call
    drawBG();
}

// void Game::render()
// {
//     this->app.clear();
//     this->app.draw(this->player);
//     this->app.display();
// }

// interpret events here, then send queueEvent to EventManager
// Updated by Zack on 3/1
#include <SFML/Graphics.hpp>
#include "PlayerView.h"

PlayerView::PlayerView(){
    //Might want additional fonts/textures in future, but early build will just have one texture
    //window.create(sf::VideoMode(800,600,32), "COVID Champion", sf::Style::Close);
    //font.loadFromFile("insert font here");
    texture.loadFromFile("../data/FourthSpriteSheet.png");
    texture2.loadFromFile("../data/covid.png");
    //Fourth sheet is rotated compared to third, all x/y coords are reversed
}

void PlayerView::init(){
    //Sets up initial state, probably loads up main menu or something

    // Initial code just making sure window is created and started, will change later
    if(window.isOpen()){

        sf::Event event;

        window.clear(sf::Color::Green);
        window.display();

        // Waits for any keypress before continuing
        /*
        while(window.waitEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                return;
            }
        }
        */
    }
}

void PlayerView::createBG(int* map){
    // Creates the inital background state based on map provided by Stage
    int i;
    int Xpos, Ypos;
    for(i = 0; i < 192; i++){
        // Creates sprite for each tile and gives Texture to the sprite
        // Calculates position using integer division before applying to sprite, which uses floats
        Xpos = 50*(i%16);
        Ypos = 50*(i/16);

        // These params set initial textureRect to the basic background
        //auto sprite_bg = SpriteActor(Xpos, Ypos, 450, 0, 50, 50);
        background[i] = SpriteActor(Xpos, Ypos, 0, 450, 50, 50);
        background[i].setTexture(&texture);

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
                //(*new_bg)->setViewLocation(300, 0);
                background[i].setViewLocation(0, 300);
                break;
            case 4:

                background[i].setViewLocation(0,250);


                break;
            // North-South Path
            case 5:
                //(*new_bg)->setViewLocation(200, 0);
                background[i].setViewLocation(0, 200);
                break;
            // East-West Path
            case 6:
                //(*new_bg)->setViewLocation(150, 0);
                background[i].setViewLocation(0, 150);
                break;
            // South-East Corner
            case 7:
                //(*new_bg)->setViewLocation(100, 0);
                background[i].setViewLocation(0, 100);
                break;
            // South-West Corner
            case 8:
                //(*new_bg)->setViewLocation(400, 0);
                background[i].setViewLocation(0, 400);
                break;
            // North-East Corner
            case 9:
                //(*new_bg)->setViewLocation(50, 0);
                background[i].setViewLocation(0, 50);
                break;
            // North-West Corner
            case 10:
                //(*new_bg)->setViewLocation(350, 0);
                background[i].setViewLocation(0, 350);
                break;
            default:
            // Shouldn't reach this
                break;
        }
    }
}

void PlayerView::drawBG(sf::RenderWindow* window){
    //Draws everything contained in the list of background tiles
    int i;
    for (i = 0; i < 192; i++)
    {
        window->draw(background[i].getSprite());
        //std::cout << background[i].getLocationX() << ", " << background[i].getLocationY() << endl; Tested that proper pixel location was set
    }
}

// void PlayerView::drawTowers(std::list<Tower*> towers){
//     //Draws everything contained in the list of towers
//     for (auto const& i : towers)
//     {
//         window.draw(i->getSprite());
//     }
// }

void PlayerView::drawViruses(sf::RenderWindow* window, std::list<std::pair<Virus, Int64>>* pairs){
    //Draws everything contained in the list of viruses
    for (auto& i : *pairs)
    {
        if (i.first.isAlive()) {
            window->draw(i.first.getSprite());
        }
    }
}

//void PlayerView::update(Stage stage){
//    //Will likely want to change return type to better react to this call
//    // Needs to draw everything and accept player input
//
//    if(window.isOpen()){
//        // Draws the background, then the towers, then the enemies
//        drawBG();
//        // These gets don't exist yet
//        drawTowers(stage.getTowerList());
//        drawViruses(stage.getVirusList());
//
//        // Leaving room for potential additions
//        window.display();
//
//        // Using pollEvent to check for input
//        sf::Event event;
//        while(window.pollEvent(event)){
//            if(event.type == sf::Event::Closed){
//                window.close();
//            }
//            if(event.type == sf::Event::KeyPressed){
//                // Need to agree on controls, will at least include ability to close window with escape
//                if(event.key.code == sf::Keyboard::Escape){
//                    window.close();
//                }
//            }
//        }
//    }
//}

// void Game::render()
// {
//     app.clear();
//     app.draw(player);
//     app.display();
// }

// interpret events here, then send queueEvent to EventManager

sf::Vector2i PlayerView::getMousePos()
{
    return sf::Mouse::getPosition(window);
}

bool PlayerView::isButtonPressed(sf::Mouse::Button button)
{
    return sf::Mouse::isButtonPressed(button);
}

sf::RenderWindow* PlayerView::getWindow()
{
    return &window;
}

sf::Texture PlayerView::getTexture(){
    return texture;
}

sf::Texture* PlayerView::getTexture2(){
    return &texture2;
}

void PlayerView::setTexture(sf::Texture newText){
    texture = newText;
}

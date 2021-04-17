// Updated by Zack on 3/1
#include <SFML/Graphics.hpp>
#include "PlayerView.h"

PlayerView::PlayerView(){
    //Might want additional fonts/textures in future, but early build will just have one texture
    window.create(sf::VideoMode(800,600,32), "COVID Champion", sf::Style::Close);
    font.loadFromFile("insert font here");
    texture.loadFromFile("..\\data\\ThirdSpriteSheet.png");
}

void PlayerView::init(){
    //Sets up initial state, probably loads up main menu or something

    // Initial code just making sure window is created and started, will change later
    if(window.isOpen()){

        sf::Event event;

        window.clear(sf::Color::Black);
        window.display();

        // Waits for any keypress before continuing
        while(window.waitEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                return;
            }
        }
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
        auto new_bg = std::next(background.begin(), i);
        auto sprite_bg = SpriteActor(Xpos, Ypos, 450, 0, 50, 50);
        *new_bg = &sprite_bg;

        (*new_bg)->setTexture(texture);

        // Sets the IntRect's location to where the desired image is
        // Currently using ThirdSpriteSheet's layout, will need to update alongside art changes
        switch(map[i]){

            // Basic Background
            case 0:
                // No change necessary, input in constructor defaulted to Basic BG
                break;
            // Home Base. 2 is skipped due to current design
            case 1:
                (*new_bg)->setViewLocation(0, 0);
                break;
            // Potential Tower Location, skips 4 since shouldn't be any prebuilt towers
            case 3:
                (*new_bg)->setViewLocation(300, 0);
                break;
            // North-South Path
            case 5:
                (*new_bg)->setViewLocation(200, 0);
                break;
            // East-West Path
            case 6:
                (*new_bg)->setViewLocation(150, 0);
                break;
            // South-East Corner
            case 7:
                (*new_bg)->setViewLocation(100, 0);
                break;
            // South-West Corner
            case 8:
                (*new_bg)->setViewLocation(400, 0);
                break;
            // North-East Corner
            case 9:
                (*new_bg)->setViewLocation(50, 0);
                break;
            // North-West Corner
            case 10:
                (*new_bg)->setViewLocation(350, 0);
                break;
        }
    }
}

void PlayerView::drawBG(){
    //Draws everything contained in the list of background tiles
    for (auto const& i : background)
    {
        window.draw(i->getSprite());
    }
}

void PlayerView::drawTowers(std::list<Tower*> towers){
    //Draws everything contained in the list of towers
    for (auto const& i : towers)
    {
        window.draw(i->getSprite());
    }
}

void PlayerView::drawViruses(std::list<Virus*> viruses){
    //Draws everything contained in the list of viruses
    for (auto const& i : viruses)
    {
        window.draw(i->getSprite());
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
//        // Using pollEvent to check for input, event manager handles something else?
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
//            // switch (Event.type) {
//            //     // Exit
//            //     case(sf::Event::Closed):
//            //     App.close();
//            //     break;
//
//            //     // Mouse Clicked
//            //     case(sf::Event::MouseButtonPressed):
//            //     if (event.mouseButton.button == sf::Mouse::Left)
//            //     {
//            //         game.click(event.mouseButton.x, event.mouseButton.y);
//            //     }
//            //     break;
//            // }
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

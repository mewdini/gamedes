#include "CountryMap.h"
#include <SFML/Graphics.hpp>
CountryMap::CountryMap(){
    Stage::level=0;

}
void CountryMap::startLevel(){
    //notify process manager?
    //CountryMap::player.update(); update player
    //CountryMap::draw(window);
};

void CountryMap::draw(sf::RenderWindow &window){
    sf::Texture texture;
    /*if (!texture.loadFromFile("image.png", sf::IntRect(10, 10, 32, 32)))
{
} */

    texture.update(window);
    //Player::player.draw();

}
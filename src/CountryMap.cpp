#include "CountryMap.h"
#include <SFML/Graphics.hpp>
CountryMap::CountryMap(){
    Stage::level=0;
    static int e[100];
     Stage::enemylist=e;//pointer for enemylist
     //initialize enemylist
     for(int i=0;i<100;i++){
         e[i]==0;
     }; 

     static int m[width*height];
     Stage::map=m; //pointer for map
     //initialize map
     for(int i=0;i<width*height;i++){
         if (i==18||i==27||i==36||i==51){ //some blocks represents levels/cities
             m[i]=1;
         }
         else{
             m[i]=0;
         }
     }
     Stage::gold=0;
     //CountryMap::Player player=Player();
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
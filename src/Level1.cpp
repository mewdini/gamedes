#include "Level1.h"
#include <SFML/Graphics.hpp>

Level1::Level1(){
     Level1::level=1;
     static int e[100];
     Stage::enemylist=e;//pointer for enemylist
     //initialize enemylist
     static int m[100];
     Stage::map=m; //pointer for map
     //initialize map, use 0 for background, 1 for base, 2 for path, 3 for tower positions 
     for(int i=0;i<100;i++){
         if(i==54){
             m[i]=1;
         }
         else if(54<i<60){
             m[i]=2;
         }
         else if(i==48||i==68||i==46||i==66){
             m[i]=3;
         }
         else{
             m[i]=0;
         }
     };
     gold=100; //set start gold
};
void Level1::startLevel1(){
    //notify process manager?
    //update every actors in Level
    //Level1::draw(window);
};
void Level1::draw(sf::RenderWindow &window){
    sf::Texture texture;
    //...
    //for each objects/actors, call draw();
    texture.update(window);
};
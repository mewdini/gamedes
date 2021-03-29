#include "Level1.h"
#include <SFML/Graphics.hpp>

Level1::Level1(){
     Level1::level=1;
     static int e[width*height];
     Stage::enemylist=e;//pointer for enemylist
     //initialize enemylist
     static int m[width*height];
     Stage::map=m; //pointer for map
     //initialize map, use 0 for background, 1 for base, 2 for path, 3 for tower positions 
     for(int i=0;i<width*height;i++){
         if(i==5*width+5){
             m[i]=1;
         }
         else if(5*width+4<i<6*width){
             m[i]=2;
         }
         else if(i==4*width+8||i==6*width+8||i==4*width+6||i==6*width+6){
             m[i]=3;
         }
         else{
             m[i]=0;
         }
     };
     gold=Stage; //set start gold
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
#include "Level1.h"
#include <SFML/Graphics.hpp>

Level1::Level1(){
     Level1::level=1;
     Stage::width=16;
     Stage::height=12;
     static int e[width*height];
     Stage::enemylist=e;//pointer for enemylist
     //initialize enemylist
     static int m[width*height];
     Stage::map=m; //pointer for map
     //initialize map, use 0 for background, 1 for base, 2 for path, 3 for tower positions, 4 for built towers
     for(int i=0;i<width*height;i++){
         //base
         if(i==6*width+7){
             m[i]=1;
         }
         //paths
         else if(1*width+2<i<1*width+11||10*width+2<i<10*width+8||10*width+9<i<10*width+15){
             m[i]=2;
         }
         else if(width<i<width*10){
             if(i % width==3 || i % width==10){
                 m[i]=2;
             }
         }
         else if(i==7*width+7||i==8*width+7||i==9*width+7||i==6*width+14||i==7*width+14||i==8*width+14||i==9*width+14){
             m[i]=2;
         }
         //slots for towers
         else if(i==0*width+6||i==2*width+4||i==2*width+9||i==5*width+4||i==5*width+9||i==7*width+15||i==8*width+9||i==9*width+11||i==9*width+13||i==9*width+4||i==9*width+6||i==11*width+5||i==11*width+12){
             m[i]=3;
         }
         else{
             m[i]=0;
         }
     };
     Stage::setGold(100);
     start1=59;     //the position on the map where the enemies are spawned
     enemycount=10; //set number of enemies in the level and the number of towers
     towercount=5;
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
#include "Level1.h"
#include "Stage.h"
#include <SFML/Graphics.hpp>

Level1::Level1():Stage(){
    level=1;
    width=16;
    height=12;
    base_loc = Vector2i(7,6);
    //static int e[width*height];
    //pointer for enemylist
    //initialize enemylist
    //int m[width*height];
    //map=m; //pointer for map
    int m[192];
    //initialize map, use 0 for background, 1 for base, 3 for tower positions, 4 for built towers， 5 for north-south path, 6 for east-west path, 7 for corner connecting south-east path, 8 for south-west, 9 for north-east, 10 for north-west
    for(int i=0;i<width*height;i++){
        //base
        if(i==6*width+7){
            m[i]=1;
        }
        //paths
        
        else if(1*width+3==i||i==6*width+14 ){
            m[i]=7;
        }
        else if (10*width+3==i||10*width+10==i){
            m[i]=9;
        }
        else if(i==10*width+7||i==10*width+14){
            m[i]=10;
        }
        else if(i==1*width+10){
            m[i]=8;
        }
    //horizontal paths
        else if((1*width+3<i && i<1*width+10)||(10*width+3<i && i<10*width+7)||(10*width+10<i && i<10*width+14)||i==6*width+15){
            m[i]=6;
        }
        //vertical paths
        else if(2*width<i<width*9){                
            if(i % width==3 || i % width==10){
                m[i]=5;
            }
        }
        else if(i==7*width+7||i==8*width+7||i==9*width+7||i==7*width+14||i==8*width+14||i==9*width+14){
            m[i]=5;
        }
        //slots for towers
        else if(i==0*width+6||i==2*width+4||i==2*width+9||i==5*width+4||i==5*width+9||i==7*width+15||i==8*width+9||i==9*width+11||i==9*width+13||i==9*width+4||i==9*width+6||i==11*width+5||i==11*width+12){
            m[i]=3;
        }
        else{
            m[i]=0;
        }
    };

    // populate virus list
    for (int i = 0; i < virus_count; i++) {
        auto temp_virus = Virus(start1, start2, Left, Viruses::covid, 13, m);
        auto temp_pair = std::pair<Virus*, sf::Int64>(&temp_virus, 1000000);
        virus_list.push_back(&temp_pair);
    }
//     setGold(100);
//     start1=15;
//     start2=6;     //the position on the map where the enemies are spawned
};
void Level1::startLevel1(){
    //notify process manager?
    //update every actors in Level
    //Level1::draw(window);
};
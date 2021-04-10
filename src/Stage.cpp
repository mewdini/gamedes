#include "Stage.h"
#include <SFML/Graphics.hpp>
Stage::Stage()
{
    this->height = 16;
    this->width = 12;
};

Stage::Stage(int x, int y)
{
    this->width = x;
    this->heigth = y;
}

int* Stage::getMap()
{
    return this->map;
}

int Stage::getGold()
{
    return gold;
};

void Stage::setGold(int g)
{
    this->gold = g;
};

int Stage::getValueOnMap(int x,int y) //inputs are coordinates on the map, top-left is (0,0)
{
    return this->map[x][y];
};

void Stage::setValueOnMap(int x, int y, int v)
{
    this->map[x][y] = v;
};

void Stage::build(/*Tower1 tower, int posx,int posy */){    //If the player clicks on a slot, the position of the slot should be defense object
    //Stage::gold-=tower.getCost();
    //posx=tower.getx();?
    //posy=tower.gety();?
    //Stage::map[posx+Stage::width*posy]=4;
    //Stage::towerlist[curtower]=tower;
    //curtower+=1;
    ;
};
void Stage::spawnEnemy(){
    if(this->cur_enemy < this->enemy_count){
        //enemy=enemylist[curenemy];
        //enemy.setAlive();
        //enemy.setPosition(start1);
        //curenemy+=1;
        ;
    };
};
void Stage::allAttack(){
    for(int i = 0; i < this->tower_count; i++)
    {
        //tower=&towerlist[i];?
        //tower.attack();
        ;
    }
};

/*void Stage::attackFirstEnemyInRange(Tower tower){  //x,y are coordinates of the tower, and r is the range of the tower 
    for(int i=0;i<enemycount;i++){
        enemy=enemylist[i];
        if(!enemy.isAlive()){
            posx=enemy.getx();
            posy=enemy.gety();
            x=tower.getx();
            y=tower.gety();
            r=tower.getRange();
            if ((posx-x)*(posx-x)+(posy-y)*(posy-y)<=r*r){
                tower.attack(enemy);
            }
        }
    }
}
*/
/*void Stage::updateTowers(){
    for(int i=0;i<curtower;i++){
        
            tower=towerlist[i];
            Stage::attackFirstEnemyInRange(tower);
        
    }
}

*/
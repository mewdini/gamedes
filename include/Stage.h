//Edited by Yixuan Xu on 02/28

#ifndef _STAGE_H_
#define _STAGE_H_

class Stage{
    public:
    Stage(void);
    Stage(int lev,int[800][600],int list[],int g);
    void DisplayStage();
    //void StartStage();
    int getGold();
    void setGold(int g);
    void build(/*Defense defense*/);      //trigger build event

    private:
    int level;
    //int difficulty;
    int map[800][600] ;      //might need to import the size of screen from other files instead of hardcoding
    int enemylist[5];         //the list of enemeies for this level
    int gold;                //used to build defense, increase when enemies are killed (maybe has a static growth rate)
    //Character player;
    //Enemy? 
    
};


#endif /* _STAGE_H_ */
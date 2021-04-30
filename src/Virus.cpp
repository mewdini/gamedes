//
// Created by Miodrag


#include "Virus.h"
#include <cstdlib>
#include <ctime>
using namespace  std;


Virus::Virus()
{
    ;
}

// void Virus::setStage(Stage* s)
// {
//    stage = s;
// }

bool Virus::hit(float damage)
{
    m_Health -= damage;
    if (m_Health <= 0)
    {
        //DEAD
        m_Alive = false;
        //m_Sprite.setTexture(TextureHolder::GetTexture("graphicsHere")
        //this sprite creates a dead Virus on the map if we want that
        // we can just make it disappear
        return true;


    }

    //injured and not dead yet
    return false;

}

// void Virus::movement()
// {
//     stage.getValueOnMap();
//     move(1,1);

// }



bool Virus::isAlive()
{
    return m_Alive;
}

Vector2f Virus::getPosition()
{
    return m_Sprite.getPosition();
}


Sprite Virus::getSprite()
{
   return m_Sprite;
}



// TODOOOOOO

// This function has to update virus location from the base
//void Virus::update(float elapsedTime, Vector2f baseLocation)
//{
//    float baseX = baseLocation.x;
//    float baseY = baseLocation.y;
//    //Update Virus position
//
//
//}
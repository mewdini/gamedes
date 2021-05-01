//
// Created by Miodrag


#include "Virus.h"
#include <cstdlib>
#include <ctime>
using namespace std;


Virus::Virus(int start_x, int start_y, Directions dir, Virus::Viruses type, int seed, Stage* level)
{
    switch(type)
    {
        case Virus::Viruses::covid:
            //Covid Virus
            //this m_Sprite variable will pull the sprite of the Zombie
            //We should probably create a TextureHolder Class from where we
            // load it
            m_Texture.loadFromFile("../data/coronavirus_0.png");
            m_Sprite.setTexture(m_Texture);
            m_Sprite.setOrigin(15, 6);
            m_Speed = COVID_VIRUS_SPEED;
            m_Health = COVID_VIRUS_HEALTH;
            break;

        case Virus::Viruses::resistant:
            // Resistant Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = RESISTANT_STRAIN_SPEED;
            m_Health = RESISTANT_STRAIN_HEALTH;
            break;

        case Virus::Viruses::contagious:
            // Contagious Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = CONTAGIOUS_STRAIN_SPEED;
            m_Health = CONTAGIOUS_STRAIN_HEALTH;
            break;

        case Virus::Viruses::airborn:
            // Airborn Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = AIRBORN_STRAIN_SPEED;
            m_Health = AIRBORN_STRAIN_HEALTH;
            break;

        case Virus::Viruses::coughing:
            // Coughing Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = COUGHING_PERSON_SPEED;
            m_Health = COUGHING_PERSON_HEALTH;
            break;
    }

    m_Alive = false;

    //Every virus has a unique speed
    srand((int)time(0) * seed);
    float modifier = (rand() % MAX_VARIANCE) + OFFSET;
    modifier /= 100;  //it will equal between .7 and 1
    m_Speed *= modifier;

    // Location of the virus
    m_Position.x = start_x;
    m_Position.y = start_y;

    m_Stage = level;
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

bool Virus::isAlive()
{
    return m_Alive;
}

void Virus::setAlive(bool alive)
{
    m_Alive = alive;
}

Vector2f Virus::getPosition()
{
    return m_Sprite.getPosition();
}


Sprite Virus::getSprite()
{
   return m_Sprite;
}

// This function has to update virus location from the base
void Virus::update(Int64 elapsedTime)
{
    if (m_Alive)
    {
        // check value at current tile in grid
        Vector2f pixelPos = getPosition();
        Vector2i gridPos = Stage::pixelToGrid(pixelPos);

        updateDirection();
        moveDir(m_Dir, elapsedTime);

        // check if in new grid position
        // gridPos is old at this point
        if (gridPos != Stage::pixelToGrid(getPosition()))
        {
            // prevents Virus from changing directions more than once at a corner
            m_Turned = false;
        }
    }
}

// irrelevant function since map has corners programmed in
// Directions Virus::pathDir()
// {
//     Vector2f pixelPos = getPosition();
//     Vector2f gridPos{pixelPos.x / 50, pixelPos.y / 50};
//     std::vector<Directions> pot_dirs{Left, Right, Up, Down};

//     // erase direction Virus came from from directions to check
//     auto iter = std::find(pot_dirs.begin(), pot_dirs.end(), last_Direction);
//     if (iter != pot_dirs.end())
//         pot_dirs.erase(iter);

//     // make sure not going out of bounds (fix in the getValueOnMap method?)
//     int pos_path;
//     for (auto const& dir : pot_dirs) {
//         switch (dir)
//         {
//             case Left:
//                 pos_path = stage->getValueOnMap(gridPos.x - 1, gridPos.y);
//                 break;
//             case Right:
//                 pos_path = stage->getValueOnMap(gridPos.x + 1, gridPos.y);
//                 break;
//             case Up:
//                 pos_path = stage->getValueOnMap(gridPos.x, gridPos.y - 1);
//                 break;
//             case Down:
//                 pos_path = stage->getValueOnMap(gridPos.x, gridPos.y + 1);
//         }

//         // check if it's the value for path
//     }    
//     // check remaining directions, but make sure we dont go out of bounds (catch errors?)
//     // stage->getValueOnMap(gridPos.x, gridPos.y);
//     // ^ check opposite of where you were last, then left and right in grid. check for which is path value and return that direction
//     // set last_Direction
// }

void Virus::updateDirection()
{
    Vector2f pixelPos = getPosition();
    Vector2i gridPos = Stage::pixelToGrid(pixelPos);
    int tile_val = m_Stage->getValueOnMap(gridPos.x, gridPos.y);
    if ((tile_val >= 5) && (tile_val <= 10))
    {
        // middle of grid in pixel coords
        Vector2f mid = Stage::gridToPixelMiddle(gridPos);

        switch (m_Dir)
        {
            case Up:
                // if y is less than middle of box's y
                if (pixelPos.y - mid.y <= 0)
                {
                    // turn
                    // 7 for corner connecting south-east path
                    if (tile_val == 7)
                    {
                        m_Dir = Right;
                    }
                    //8 for corner connecting south-west path
                    else if (tile_val == 8)
                    {
                        m_Dir = Left;
                    }
                    m_Turned = true;
                }
                break;
            case Down:
                // if y is more than middle of box's y
                if (pixelPos.y - mid.y >= 0)
                {
                    // turn
                    // 9 for corner connecting north-east path
                    if (tile_val == 9)
                    {
                        m_Dir = Right;
                    }
                    // 10 for corner connecting north-west path
                    else if (tile_val == 10)
                    {
                        m_Dir = Left;
                    }
                    m_Turned = true;
                }
                break;
            case Left:
                // if x is less than middle of grid's x
                if (pixelPos.x - mid.x <= 0)
                {
                    // turn
                    // 7 for corner connecting south-east path
                    if (tile_val == 7)
                    {
                        m_Dir = Down;
                    }
                    // 9 for corner connecting north-east path
                    else if (tile_val == 9)
                    {
                        m_Dir = Up;
                    }
                    m_Turned = true;
                }
                break;
            case Right:
                // if x is more than middle of grid's x
                if (pixelPos.x - mid.x >= 0)
                {
                    // turn
                    // 8 for corner connecting south-west path
                    if (tile_val == 8)
                    {
                        m_Dir = Down;
                    }
                    // 10 for corner connecting north-west path
                    else if (tile_val == 10)
                    {
                        m_Dir = Up;
                    }
                    m_Turned = true;
                }
                break;
        }
    }
}

void Virus::moveDir(Directions dir, Int64 delta)
{
    float pixels_x, pixels_y = 0;
    float C = 1000000; // combats delta being in microseconds
    switch (dir)
    {
        case Up:
            pixels_y = -(m_Speed * (delta / C));
            break;
        case Down:
            pixels_y = m_Speed * (delta / C);
            break;
        case Left:
            pixels_x = -(m_Speed * (delta / C));
            break;
        case Right:
            pixels_x = m_Speed * (delta / C);
    }

    // move virus sprite
    move(pixels_x, pixels_y);
}
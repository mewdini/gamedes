//
// Created by Miodrag


#include "Virus.h"

using namespace std;


Virus::Virus(int start_x, int start_y, Directions dir, Viruses type, int seed, int* level)
{
    // Zack - changed to use existing sprite from inherited SpriteActor
    // doesn't solve problem of loading a new texture, should have reference to
    // PView's texture and load from that instead
    sf::Vector2f pixel_pos;
    switch(type)
    {
        case Viruses::covid:
            //Covid Virus
            //this sprite variable will pull the sprite of the Zombie
            //We should probably create a TextureHolder Class from where we
            // load it
            pixel_pos = gridToPixelTopLeft(Vector2i{15, 6});
            sprite.setPosition(pixel_pos.x, pixel_pos.y);
            m_Speed = COVID_VIRUS_SPEED;
            m_Health = COVID_VIRUS_HEALTH;
            m_Damage = COVID_VIRUS_DAMAGE;
            break;

        case Viruses::resistant:
            // Resistant Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = RESISTANT_STRAIN_SPEED;
            m_Health = RESISTANT_STRAIN_HEALTH;
            m_Damage = RESISTANT_STRAIN_DAMAGE;
            break;

        case Viruses::contagious:
            // Contagious Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = CONTAGIOUS_STRAIN_SPEED;
            m_Health = CONTAGIOUS_STRAIN_HEALTH;
            m_Damage = CONTAGIOUS_STRAIN_DAMAGE;
            break;

        case Viruses::airborn:
            // Airborn Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = AIRBORN_STRAIN_SPEED;
            m_Health = AIRBORN_STRAIN_HEALTH;
            m_Damage = AIRBORN_STRAIN_DAMAGE;
            break;

        case Viruses::coughing:
            // Coughing Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = COUGHING_PERSON_SPEED;
            m_Health = COUGHING_PERSON_HEALTH;
            m_Damage = COUGHING_STRAIN_DAMAGE;
            break;
    }

    m_Alive = false;

    //Every virus has a unique speed
    srand((int)time(0) * seed);
    float modifier = (rand() % MAX_VARIANCE) + OFFSET;
    modifier /= 100;  //it will equal between .7 and 1
    m_Speed *= modifier;

    // Location of the virus
    Vector2i start_grid_pos = Vector2i(start_x, start_y);
    Vector2f start_pixel_pos = gridToPixelTopLeft(start_grid_pos);
    sprite.setPosition(start_pixel_pos.x, start_pixel_pos.y);


    m_Dir = Left;
}

bool Virus::hit(float damage)
{
    m_Health -= damage;
    if (m_Health <= 0)
    {
        //DEAD
        m_Alive = false;
        gainGold=1;
        //sprite.setTexture(TextureHolder::GetTexture("graphicsHere")
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
    return sprite.getPosition();
}


Sprite Virus::getSprite()
{
   return sprite;
}

// This function has to update virus location from the base
int Virus::update(Int64 elapsedTime, Vector2i* base_loc, float* base_health)
{
    if (m_Alive)
    {
        // check value at current tile in grid
        Vector2f pixelPos = getPosition();
        Vector2i gridPos = pixelToGrid(pixelPos);

        updateDirection();
        moveDir(m_Dir, elapsedTime);

        // check if in new grid position
        auto oldGridPos = gridPos;
        gridPos = pixelToGrid(getPosition());
        pixelPos = getPosition();
        // gridPos is old at this point
        if (gridPos != oldGridPos)
        {
            // prevents Virus from changing directions more than once at a corner
            m_Turned = false;
        }

        
        // check if virus hit the tower
        // if in end tile
        if (gridPos == *base_loc)
        {
            // check if at or past middle of grid (using direction)
            bool pastMid = false;
            auto baseMid = gridToPixelMiddle(*base_loc);
            switch (m_Dir)
            {
                case Up:
                    if (baseMid.y >= pixelPos.y)
                        pastMid = true;
                    break;
                case Down:
                    if (baseMid.y <= pixelPos.y)
                        pastMid = true;
                    break;
                case Left:
                    if (baseMid.x >= pixelPos.x)
                        pastMid = true;
                    break;
                case Right:
                    if (baseMid.x <= pixelPos.x)
                        pastMid = true;
                    break;
            }
            if (pastMid)
            {
                setAlive(false);
                *base_health -= m_Damage;

                return 1;
            }
        }
    }
    Vector2f pixelPos = getPosition();
    if(gainGold==1){
        gainGold=0;
        
        return 1;
    }
    else{
        return 0;
    }
    
}

void Virus::updateDirection()
{
    Vector2f pixelPos = getPosition();
    pixelPos.x += 25;
    pixelPos.y += 25;
    Vector2i gridPos = pixelToGrid(pixelPos);
    int tile_val = getValueOnMap(gridPos.x, gridPos.y);
    if ((tile_val >= 5) && (tile_val <= 10)) // if the tile is a corner
    {
        // middle of grid in pixel coords
        Vector2f mid = gridToPixelMiddle(gridPos);

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
    float f_delta = (float) delta;
    float C = 1000000; // combats delta being in microseconds
    switch (dir)
    {
        case Up:
            pixels_y = -(m_Speed * (f_delta / C));
            break;
        case Down:
            pixels_y = m_Speed * (f_delta / C);
            break;
        case Left:
            pixels_x = -(m_Speed * (f_delta / C));
            break;
        case Right:
            pixels_x = m_Speed * (f_delta / C);
    }


    // move virus sprite
    move(pixels_x, pixels_y);
}

Vector2i Virus::pixelToGrid(Vector2f pixel_pos)
{
    Vector2i grid_pos;
    grid_pos.x = floor(pixel_pos.x / 50);
    grid_pos.y = floor(pixel_pos.y / 50);
    return grid_pos;
}

// gets pixel coords of middle of grid square
Vector2f Virus::gridToPixelMiddle(Vector2i grid_pos)
{
    Vector2f mid;
    mid.x = grid_pos.x * 50 + 25;
    mid.y = grid_pos.y * 50 + 25;
    return mid;
}

Vector2f Virus::gridToPixelTopLeft(Vector2i grid_pos)
{
    Vector2f mid;
    mid.x = grid_pos.x * 50;
    mid.y = grid_pos.y * 50;
    return mid;
}

int Virus::getValueOnMap(int x,int y){          //inputs are coordinates on the map, top-left is (0,0)
    return m_Grid[y * 16 + x];
}

Directions Virus::getDirection()
{
    return m_Dir;
}
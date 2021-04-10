//
// Created by Miodrag
#include "Tower.h"
#include <cmath>

using namespace sf;
Tower::Tower(int x, int y, int level)
{
    // these are sf::
    tower_sprite = Sprite();
    tower_tex = Texture();

    TowerLevel(lvl);
    tower_sprite.setPosition(x, y);

}

Tower::Tower()
{
    radius = 128.0f;
}

void Tower::TowerLevel(int lvl);
{
    level = lvl;
    if (lvl == 1)
    {
        tower_sprite.setTexture(*tower_tex);
        radius = 128;
        attack_speed = 1.0f;
        damage = 15;
        gold_cost = 100
    }


    if (lvl == 2)
    {
        tower_sprite.setTexture(*tower_tex);
        radius = 128;
        attack_speed = 2.0f;
        damage = 30;
        gold_cost = 200
    }


    if (lvl == 3)
    {
        tower_sprite.setTexture(*tower_tex);
        radius = 128;
        attack_speed = 3.0f;
        damage = 40;
        gold_cost = 300
    }



    if (lvl == 4)
    {
        tower_sprite.setTexture(*tower_tex);
        radius = 128;
        attack_speed = 4.0f;
        damage = 50;
        gold_cost = 400
    }


    if (lvl == 5)
    {
        tower_sprite.setTexture(*tower_tex);
        radius = 128;
        attack_speed = 4.0f;
        damage = 60;
        gold_cost = 500
    }

}


void Tower::angle_to_point(double x, double y)
{
    double dx = x - (tower_sprite.getPosition().x);
    double dy = y - (tower_srpite.getPosition().y);
    double angle = atan2(dx,dy) * 180 / (atan(1) * 4);
    return angle;
}

void Tower::Update(float elapsedTime)
{
    ;   //still have to figure out how we going to update

}

//void Tower::Draw(RenderTarget *something)
//{

//}

const int Tower::GetX()
{
    return (int)tower_sprite.getPosition().x;
}

const int Tower::GetY()
{
    return (int)tower_sprite.getPosition().y;
}

const float Tower::GetRadius()
{
    return radius;
}

const float Tower::GetAttackSpeed()
{
    return attack_speed;
}

const float Tower::GetDamage()
{
    return damage;
}

const Vector2f Tower::GetPosition()
{
    return tower_sprite.getPosition();
}

const FloatRect Tower::GetBoundingBox()
{
    return tower_sprite.getGlobalBounds;
}

const Vector2f Tower::GetCenteredPosition()
{
    Vector2f vec = tower_sprite.getPosition();
    vec.x += GetBoundingBox().width / 2;
    vec.y += GetBoundingBox().height / 2;
    return vec;
}


const int Tower::GetGoldCost()
{
    return gold_cost;
}

const int Tower::GetUpgradeLevel()
{
    return upgrade_level;
}



//


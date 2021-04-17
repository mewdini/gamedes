//
// Created by Miodrag
//

#pragma once
#include <SFML/Graphics.hpp>
#ifndef GAMEDES_TOWER_H
#define GAMEDES_TOWER_H

using namespace std;
using namespace sf;
class Tower : public SpriteActor
{
public:
    Tower();
    enum Towers {first};
    //void Draw(RenderTarget *Whatever)
    explicit Tower(int x, int y, int level);
    //draw function needs a target to draw
    //void Draw(RenderTarget *something);
    void Update(float elapsedTime);
    const int GetX();
    const int GetY();
    const float GetRadius();
    const float GetAttackSpeed();
    const float GetDamage();
    const Vector2f GetPosition();
    const Vector2f GetCenteredPosition();
    const FloatRect GetBoundingBox();
    const int GetUpgradeLevel();
    const int GetGoldCost(int level);
    void TowerLevel(int lvl);

private:
    Texture *tower_tex;
    Sprite tower_sprite;
    int level;
    float radius;
    float attack_speed;
    float damage;
    double angle_to_point(double x, double y);
    int upgrade_level;
protected:
    float gold_cost;

};



#endif //GAMEDES_TOWER_H

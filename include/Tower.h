//
// Created by Miodrag
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Virus.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

enum Towers{first};
class Tower : public SpriteActor
{
public:
    Tower();
    //void Draw(RenderTarget *Whatever)
    explicit Tower(int x, int y, int level);
    //draw function needs a target to draw
    //void Draw(RenderTarget *something);
    void Update(float elapsedTime);
    const float GetRadius();
    const float GetAttackSpeed();
    const float GetDamage();
    const Vector2f GetPosition();
    const Vector2f GetCenteredPosition();
    const FloatRect GetBoundingBox();
    const int GetUpgradeLevel();
    const int GetGoldCost(int level);
    void TowerLevel(int lvl);
    void Attack(Virus*, Texture*);
    Bullet getBullet();

private:
    Texture tower_tex;
    Sprite tower_sprite;
    int level;
    float radius;
    float attack_speed;
    float damage;
    double angle_to_point(double x, double y);
    int upgrade_level;
    // Multiples Bullets to handle attack speed
    Bullet bullet1;
    Bullet bullet2;
    Bullet bullet3;
    Bullet bullet4;
    // Pixel Position since the sprite isn't storing it
    int pixX;
    int pixY;
protected:
    float gold_cost;

};

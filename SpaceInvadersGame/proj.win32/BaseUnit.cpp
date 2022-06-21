#include "BaseUnit.h"


BaseUnit::BaseUnit(Size visibleSize, Vec2 origin, Scene* scene, Sprite* sprite, float health, int localZOrder)
{
    this->visibleSize = visibleSize;
    this->origin = origin;
    this->sprite = sprite;
    this->health = health;
    scene->addChild(sprite, localZOrder);

}

BaseUnit::BaseUnit()
{
}

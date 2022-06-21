#ifndef __BASEUNIT_H__
#define __BASEUNIT_H__
#include "cocos2d.h"

USING_NS_CC;

class BaseUnit
{
public:
    BaseUnit(Size visibleSize, Vec2 origin, Scene* scene, Sprite* sprite, float health, int localZOrder);
    BaseUnit();
public:
    Size visibleSize;
    Vec2 origin;
    Sprite* sprite;
    float health;
    Scene* scene;

};


#endif // __BASEUNIT_H__
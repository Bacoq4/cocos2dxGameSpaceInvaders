#ifndef __BULLET_H__
#define __BULLET_H__
#include "cocos2d.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Definitions.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Player.h"

USING_NS_CC;

class Bullet 
{
public:
    Bullet(Size visibleSize, Vec2 origin, Scene* scene, int localZOrder, Player player);
    Bullet();
public:
    Size visibleSize;
    Vec2 origin;
    Sprite* sprite;
    Scene* scene;
    // damage variable will be in main scene class (currently : HelloWorldScene) for simplicity sake
};

#endif // __BULLET_H__
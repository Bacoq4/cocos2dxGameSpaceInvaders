#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\BaseUnit.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Player.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Enemy.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Bullet.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Definitions.h"


#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Scene 
{
public:
    CREATE_FUNC(HelloWorld);

    static cocos2d::Scene* createScene();
    HelloWorld();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);

    void update(float);
    void SpawnBullet(float);
    void SpawnEnemy(float);
    void setBulletDamage(float amount);

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    PhysicsWorld* sceneWorld;

    virtual bool onTouchBegan(Touch*, Event*);
    virtual void onTouchEnded(Touch*, Event*);
    virtual void onTouchMoved(Touch*, Event*);
private:
    Player player;
    Enemy enemy;
    Bullet bullet;
    int state = 0;
    Size visSize;
    Vec2 origin;
    int xPos = 50;
    int killCount = 0;
    float bulletDamage = 25;

};

#endif  __HELLOWORLD_SCENE_H__

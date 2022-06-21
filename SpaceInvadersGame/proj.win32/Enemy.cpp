#include "Enemy.h"



Enemy::Enemy(Size visibleSize, Vec2 origin, Scene* scene, float health, int localZOrder)
{
    auto enemySprite = Sprite::create("spaceshipEnemy.png");
    float randomX = random(100, 1900);

    auto enemyBody = PhysicsBody::createBox(enemySprite->getContentSize());
    enemyBody->setDynamic(false);
    enemyBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
    enemyBody->setContactTestBitmask(true);
    enemySprite->setPhysicsBody(enemyBody);
    enemySprite->setScale(1, 1);
    enemySprite->setRotation(180);
    enemySprite->setPosition(Vec2(randomX, visibleSize.height / 2 + 600));
    auto moveAction = MoveBy::create(5, Vec2(0, -1500));
    enemySprite->runAction(moveAction);
}

Enemy::Enemy()
{
}

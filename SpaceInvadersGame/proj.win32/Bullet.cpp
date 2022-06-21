#include "Bullet.h"

Bullet::Bullet(Size visibleSize, Vec2 origin, Scene* scene, int localZOrder, Player player)
{
    auto bulletSprite = Sprite::create("bullet.png");

    this->visibleSize = visibleSize;
    this->origin = origin;
    this->sprite = bulletSprite;
    scene->addChild(sprite, localZOrder);

    auto bulletBody = PhysicsBody::createBox(bulletSprite->getContentSize());
    bulletBody->setDynamic(false);
    bulletBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);
    bulletBody->setContactTestBitmask(true);
    bulletSprite->setPhysicsBody(bulletBody);

    bulletSprite->setScale(0.1, 0.1);
    bulletSprite->setRotation(-90);

    bulletSprite->setPosition(player.sprite->getPosition() + Vec2(0, 50));
    auto moveAction = MoveBy::create(2, Vec2(0, 1000));
    bulletSprite->runAction(moveAction);
}

Bullet::Bullet()
{
}

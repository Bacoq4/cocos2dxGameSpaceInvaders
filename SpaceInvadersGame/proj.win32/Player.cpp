#include "Player.h"

Player::Player(Size visibleSize, Vec2 origin, Scene* scene, float health, int localZOrder)
{
    auto playerSprite = Sprite::create("spaceshipPlayer.png");
    this->sprite = playerSprite;

    auto playerBody = PhysicsBody::createBox(playerSprite->getContentSize());
    playerBody->setDynamic(false);
    playerBody->setCollisionBitmask(PLAYER_COLLISION_BITMASK);
    playerBody->setContactTestBitmask(true);

    // can't find any way to make player physics body working, it everytime returns nullptr 
    //playerSprite->setPhysicsBody(playerBody);


    CCLOG("false");
    
    playerSprite->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2 - 100));
    playerSprite->setScale(1, 1);
}
    
Player::Player()
{
}

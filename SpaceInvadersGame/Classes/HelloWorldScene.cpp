#include "HelloWorldScene.h"

USING_NS_CC;

void HelloWorld::update(float dt)
{
    if (state == 0)
    {
    }
    else if (state == 1)
    {
        player.sprite->setPosition(player.sprite->getPosition() + Vec2(10, 0));
    }
    else if (state == 2)
    {
        player.sprite->setPosition(player.sprite->getPosition() + Vec2(-10, 0));
    }
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    if (touch->getLocation().x > visSize.width / 2)
    {
        state = 1;
    }
    else
    {
        state = 2;
    }
    return true;
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
    state = 0;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
    if (touch->getLocation().x > visSize.width / 2)
    {
        state = 1;
    }
    else
    {
        state = 2;
    }
}

void HelloWorld::SpawnBullet(float dt)
{
    Bullet bullet = Bullet(visSize, origin, this, 100, player);
}

void HelloWorld::SpawnEnemy(float dt)
{
    Enemy enemy = Enemy(visSize, origin, this, 100, 5);
}


HelloWorld::HelloWorld()
{
    // edge collision init
    auto edgeBody = PhysicsBody::createEdgeBox(visSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    edgeBody->setCollisionBitmask(EDGE_COLLISION_BITMASK);
    edgeBody->setContactTestBitmask(true);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visSize.width / 2 + origin.x, visSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
}

Scene* HelloWorld::createScene()
{

    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   
    visSize = visibleSize;
    this->origin = origin;

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::SpawnBullet), 0.3);
    this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::SpawnEnemy), 1);

    player = Player(visSize, origin, this, 100, 5);

    this->scheduleUpdate();

    return true;
}

bool HelloWorld::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();

    Node* nodeA = a->getNode();
    Node* nodeB = b->getNode();

    //Bullet* bulletA = ((Bullet*)nodeA);
    //Bullet* bulletB = ((Bullet*)nodeB);

    Enemy* enemyA = ((Enemy*)nodeA);
    Enemy* enemyB = ((Enemy*)nodeB);

    if (enemyA)
    {
        enemyA->health -= bulletDamage;      
        
        if (enemyA->health <= 0)
        {
            nodeA->removeFromParent();
            killCount++;
            if (killCount % 5 == 0)
            {
                setBulletDamage(100);
                auto delayAction = DelayTime::create(3);  
                auto funcCallback = CallFunc::create([&]() {
                    setBulletDamage(25);
                    });
                this->runAction(Sequence::create(delayAction, funcCallback, NULL));
            }
        }
    }
    else if (enemyB)
    {
        enemyB->health -= bulletDamage;
       
        if (enemyB->health <= 0)
        {
            nodeB->removeFromParent();
            killCount++;
            if (killCount % 5 == 0)
            {
                setBulletDamage(100);
                auto delayAction = DelayTime::create(3);  
                auto funcCallback = CallFunc::create([&]() {
                    setBulletDamage(25);
                 });
                this->runAction(Sequence::create(delayAction, funcCallback, NULL));
            }
        }
    }

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}


void HelloWorld::setBulletDamage(float amount)
{
    bulletDamage = amount;
}
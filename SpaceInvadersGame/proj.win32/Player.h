#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\BaseUnit.h"
#include "Definitions.h"

class Player : public BaseUnit
{
public:
	Player(Size visibleSize, Vec2 origin, Scene* scene, float health, int localZOrder);
	Player();
};


#include "BaseUnit.h"
#include "D:\Cocos\CocosProjects\SpaceInvadersCaseStudy\proj.win32\Definitions.h"

class Enemy : public BaseUnit
{
public:
	Enemy(Size visibleSize, Vec2 origin, Scene* scene, float health, int localZOrder);
	Enemy();
};


#ifndef MYENEMY_H
#define MYENEMY_H

#include <rt2d/entity.h>
#include "entitycollision.h"


class MyEnemy : public EntityCollision {
public:
	MyEnemy();
	virtual ~MyEnemy();

	virtual void update(float deltaTime);

private:
};


#endif // !MYENEMY_H

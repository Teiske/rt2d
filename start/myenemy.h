#ifndef MYENEMY_H
#define MYENEMY_H

#include <rt2d/entity.h>
#include "entitycollision.h"


class MyEnemy : public EntityCollision {
public:
	MyEnemy();

	virtual ~MyEnemy();

	void addForce(Vector2 force);

	virtual void update(float deltaTime);

private:
	Vector2 velocity;
	Vector2 gravity;
	Vector2 acceleration;
};

#endif // !MYENEMY_H

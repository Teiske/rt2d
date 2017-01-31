/**
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 *
 * @file myscene.h
 *
 * @brief description of MyEnemy behavior.
 */

#ifndef MYENEMY_H
#define MYENEMY_H

#include "entitycollision.h"

/// @brief The MyEnemy class is the Scene implementation.
class MyEnemy : public EntityCollision {
public:
	/// @brief Constructor
	MyEnemy();

	/// @brief Destructor
	virtual ~MyEnemy();

	/// @brief addForce used to apply things like gravity or wind pressure
	/// @param Force is what is applied to the entity to make it fall or blown away
	/// @return force
	void addForce(Vector2 force);

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Vector2 velocity;
	Vector2 gravity;
	Vector2 acceleration;
private:
	
};

#endif // !MYENEMY_H

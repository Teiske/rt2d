/**
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 *
 * @file myscene.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYENTITY_H
#define MYENTITY_H

#include "entitycollision.h"

/// @brief The MyEntity class is the Entity implementation.
class MyEntity : public EntityCollision {
public:
	/// @brief Constructor
	MyEntity();

	/// @brief Destructor
	virtual ~MyEntity();

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
	/* add your private declarations */
	
};

#endif /* MYENTITY_H */
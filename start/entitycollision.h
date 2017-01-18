/**
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 *
 * @file myscene.h
 *
 * @brief description of EntityCollision behavior.
 */

#ifndef ENTITYCOLLISION_H
#define ENTITYCOLLISION_H

#include <rt2d\entity.h>

/// @brief The EntityCollision class is the Scene implementation.
class EntityCollision : public Entity {
public:
	/// @brief Constructor
	EntityCollision();

	/// @brief Destructor
	virtual ~EntityCollision();

	/// @brief isCollidingWith is used to check if an entity ic colliding with another entity.
	/// @param Collision detection is used to check to see if something needs to be deleted or if it should stop something form falling.
	/// @return force
	bool isCollidingWith(Entity* other);

private:

};


#endif // !ENTITYCOLLISION_H

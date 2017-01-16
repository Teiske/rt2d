#include "entitycollision.h"

EntityCollision::EntityCollision() {
}

EntityCollision::~EntityCollision() {
}

bool EntityCollision::isCollidingWith(Entity * other) {
	if ((abs(this->position.x - other->position.x) * 2.0f < (sprite()->size.x + other->sprite()->size.x)) &&
		(abs(this->position.y - other->position.y) * 2.0f < (sprite()->size.y + other->sprite()->size.y)))
	{
		return true;
	}
	return false;
}
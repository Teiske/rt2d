/**
* This class describes MyEntity behavior.
*
* Copyright 2016 Teis Gossen <teisgossen@gmail.com>
*/

#include "myentity.h"

MyEntity::MyEntity() : Entity() {
	this->addSprite("assets/square.tga");
	//this->sprite()->color = RED;

	velocity = Vector2(0, 0);
	gravity = Vector2(0, 9);
	acceleration = Vector2(0, 0);
}

MyEntity::~MyEntity() {

}

void MyEntity::addForce(Vector2 force) {
	this->acceleration += force;
}

void MyEntity::update(float deltaTime) {
	this->addForce(gravity);
	this->velocity += acceleration;
	this->position += velocity * deltaTime;

	velocity *= 0.99f;
	acceleration *= 0;

	if (this->position.y >= 600) {
		this->velocity *= -0.9f;
		this->position.y = 600;
	}
}
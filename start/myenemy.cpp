/**
 * This class describes MyEnemy behavior.
 *
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 */


#include "myenemy.h"
#include "myentity.h"

MyEnemy::MyEnemy() : EntityCollision() {
	this->addSprite("assets/squareEnemy.tga");
	this->sprite()->color = RED;

	velocity = Vector2(0, 0);
	gravity = Vector2(0, 9);
	acceleration = Vector2(0, 0);
}

MyEnemy::~MyEnemy() {

}

void MyEnemy::addForce(Vector2 force) {
	this->acceleration += force;
}

void MyEnemy::update(float deltaTime) {
	this->addForce(gravity);
	this->velocity += acceleration;
	this->position += velocity * deltaTime;

	velocity *= 0.99f;
	acceleration *= 0;

	if (this->position.y >= 600) {
		this->velocity *= -0.0f;
		this->position.y = 600;
	}
}

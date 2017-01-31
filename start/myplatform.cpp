/**
* This class describes MyPlatform behavior.
*
* @file myplatform.cpp
*
* Copyright 2017 Teis Gossen <teisgossen@gmail.com>
*/

#include "myplatform.h"

MyPlatform::MyPlatform() : EntityCollision() {
	this->addSprite("assets/squarePlatform.tga");
	this->sprite()->color = GREEN;
}

MyPlatform::~MyPlatform() {
}

void MyPlatform::update(float deltaTime) {
}

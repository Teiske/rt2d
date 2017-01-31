/**
 * This class describes MyScene behavior.
 *
 * @file myscene.cpp
 *
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene() {
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH / 2, 450);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
	
	// add enemies through an array 
	enemySpawn(100, 500);
	enemySpawn(200, 500);
	enemySpawn(300, 500);
	enemySpawn(400, 500);
	enemySpawn(500, 500);

	platformSpawn(1000, 500);
}


MyScene::~MyScene() {
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;

	myenemyVector.clear();
	myplatformVector.clear();
}

void MyScene::enemySpawn(float x, float y) {
	MyEnemy* myenemy = new MyEnemy();
	myenemy->position = Point2(x, y);

	this->addChild(myenemy);
	myenemyVector.push_back(myenemy);
	std::cout << "im spawning" << std::endl;
}

void MyScene::enemyDespawn() {
	std::vector<MyEnemy*>::iterator it = myenemyVector.begin();
	while (it != myenemyVector.end()) {
		if ((*it)->isCollidingWith(myentity)) {
			MyEnemy* e = (*it);
			this->removeChild(e);
			it = myenemyVector.erase(it);
			delete e;
		    std::cout << "Enemy is despawned" << std::endl;
		}
		else {
			it++;
		}
	}
}

void MyScene::platformSpawn(float x, float y) {
	MyPlatform *myplatform = new MyPlatform();
	myplatform->position = Point2(x, y);

	this->addChild(myplatform);
	myplatformVector.push_back(myplatform);
	std::cout << "Platform created" << std::endl;
}

void MyScene::entityOnPlatform() {
	std::vector<MyPlatform*>::iterator it = myplatformVector.begin();
	while (it != myplatformVector.end()) {
		if (myentity->isCollidingWith((*it))) {
			onP = true;
			myentity->velocity.y = 0;
			myentity->position = Point2(myentity->position.x, (*it)->position.y - 45);
			std::cout << "Colliding with platform" << std::endl;
		 }
		else {
			onP = false;
		}
		it++;
	}
}

void MyScene::update(float deltaTime) {
	// Escape key stops the Scene
	if (input()->getKeyUp(GLFW_KEY_ESCAPE)) {
		this->stop();
	}

	// Move entity from left to right	
	if (input()->getKey(GLFW_KEY_LEFT)) {
		myentity->position -= Point2(250, 0) * deltaTime;
	}
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		myentity->position += Point2(250, 0) * deltaTime;
	}

	//Jump the entity
	if (input()->getKeyDown(GLFW_KEY_SPACE)) {
		myentity->addForce(Vector2(0, -950));
	}

	//Function to detect collision and what should when there is collision
	enemyDespawn();
	entityOnPlatform();

	// Rotate color of entity
	//if (t.seconds() > 0.0333f) {
		 //RGBAColor color = myentity->sprite()->color;
		 //myentity->sprite()->color = Color::rotate(color, 0.01f);
		 //t.start();
	//}
}

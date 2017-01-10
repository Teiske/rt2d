/**
* This class describes MyScene behavior.
*
* Copyright 2016 Teis Gossen <teisgossen@gmail.com>
*/

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	myentity->scale = Point2(0.5, 0.5);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
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
		myentity->addForce(Vector2(0, -800));
	}

	// Rotate color of entity
	/**
	* if (t.seconds() > 0.0333f) {
	*	 RGBAColor color = myentity->sprite()->color;
	*	 myentity->sprite()->color = Color::rotate(color, 0.01f);
	*	 t.start();
	* }
	*/
}
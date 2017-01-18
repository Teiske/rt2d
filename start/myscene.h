/**
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <rt2d/vectorx.h>

#include "myentity.h"
#include "myenemy.h"
#include "entitycollision.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene {
public:
	/// @brief Constructor
	MyScene();

	/// @brief Destructor
	virtual ~MyScene();
	
	void enemySpawn(int amount);
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief The squares on the screen
	MyEntity* myentity;

	MyEnemy* myenemy;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	/// @brief a boolean so you can jump
	bool jump = false;
};

#endif /* SCENE00_H */

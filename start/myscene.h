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
#include "myplatform.h"
#include "entitycollision.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene {
public:
	/// @brief Constructor
	MyScene();

	/// @brief Destructor
	virtual ~MyScene();

	/// @brief enemySpawn is used to place enemies in the scene
	/// @param float x and y is used to give the enemies a position in the scene
	/// @return void
	void enemySpawn(float x, float y);

	/// @brief desawnEnemy is used to delete enemies form the scene
	void enemyDespawn();

	/// @brief plaformSpawn is used to place platforms in the scene
	/// @param float x and y is used to give the platforms a position in the scene
	/// @return void
	void platformSpawn(float x, float y);

	/// @brief desawnEnemy is used to delete enemies form the scene
	void entityOnPlatform();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
	

private:
	/// @brief The squares on the screen
	MyEntity* myentity;

	std::vector<MyEnemy*> myenemyVector;
	std::vector<MyPlatform*> myplatformVector;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	/// @brief a boolean so you can jump
	bool jump = false;

	bool onP = false;

	

};

#endif /* SCENE00_H */

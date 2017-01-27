/**
* Copyright 2017 Teis Gossen <teisgossen@gmail.com>
*
* @file myscene.h
*
* @brief description of MyEnemy behavior.
*/

#ifndef MYPLATFORM_H
#define MYPLATFORM_H

#include "entitycollision.h"

class MyPlatform : public EntityCollision {
public:
	/// @brief platform constructor.
	MyPlatform();

	///@brief platform virtual deconstructor.
	virtual ~MyPlatform();

	/// @brief update is automatically called every frame
	/// @param deltatime, time elapsed in seconds.
	/// @return void.
	virtual void update(float deltaTime);


private:

};

#endif // !MYPLATFORM_H
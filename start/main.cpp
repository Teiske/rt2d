/**
 * Copyright 2017 Teis Gossen <teisgossen@gmail.com>
 *
 * @brief MY game I Am The Hero where you can decide if you want te be the hero.
 *
 * @file main.cpp
 *
 * @mainpage I Am The Hero
 *
 * @section intro Introduction
 *
 * My game I Am The Hero is a game where you have the option to load in a character of yourself so you can play the hero and save your prins or prinses.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "myscene.h"

/// @brief main entry point
int main( void ) {
	// Core instance
	Core core;

	// Scene01
	MyScene* myscene = new MyScene(); // create Scene on the heap
	while(myscene->isRunning()) { // check status of Scene every frame
		core.run(myscene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}

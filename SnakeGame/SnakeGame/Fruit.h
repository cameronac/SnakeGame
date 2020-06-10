#pragma once
#include <SDL.h>
#include <stdio.h>
#include "PlayerController.h"
#include "Color.h"
#include "RenderController.h"
#include <cstdlib>

struct Fruit {

//Public Methods
public:
	Fruit();
	void respawn();
	void checkFruit(PlayerController& playerController);
	void renderFruit(RenderController &renderController);

//Public Properties
public:
	SDL_Rect fillRect = { 32, 32, 16, 16 };
	Color color = Color(0x00, 0x00, 0xFF, 0xFF);

};
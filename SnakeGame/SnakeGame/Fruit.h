#pragma once
#include <SDL.h>
#include <stdio.h>
#include "PlayerController.h"
#include "Color.h"
#include "RenderController.h"
#include "WindowController.h"
#include <cstdlib>

struct Fruit {

//Public Methods
public:
	Fruit();
	void respawn();
	void checkFruit(PlayerController& playerController);
	void renderFruit(RenderController& renderController);

//Public Properties
public:
	const int spacing = 30;
	SDL_Rect fillRect = { WindowController::SCREEN_WIDTH/2, WindowController::SCREEN_HEIGHT/2, 16, 16 };
	Color color = Color(0x00, 0x00, 0xFF, 0xFF);

};
#pragma once
#include "SDL.h"
#include "Color.h"
#include "InputController.h"
#include "TailController.h"
#include "RenderController.h"
#include "Direction.h"

class PlayerController
{  
	//Public Properties
	public:
		int spd = 2;
		bool didChangeDirection = false;

		//Render red filled quad
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		InputController* inputController;
		TailController tailController;
		Direction direction;
	
	//Public Methods
	public:
		PlayerController();
		PlayerController(InputController* inputController);
		~PlayerController();
		void checkPlayer();
		void renderPlayer(RenderController* renderController);
};


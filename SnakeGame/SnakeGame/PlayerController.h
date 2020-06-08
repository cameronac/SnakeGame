#pragma once
#include "SDL.h"
#include "Color.h"
#include "InputController.h"
#include "TailController.h"
#include "RenderController.h"
#include "Direction.h"
#include "PositionHolder.h"

class PlayerController
{  
	//Public Properties
	public:
		int spd = 2;
		bool didChangeDirection = false;

		//Pointers
		PositionHolder* positionHolder;
		InputController* inputController;
		TailController* tailController;

		SDL_Rect fillRect = {32, 32, 32, 32};
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		Direction direction = Direction::right;
		
	
	//Public Methods
	public:
		PlayerController(InputController* inputController);
		~PlayerController();
		void checkPlayer();
		void renderPlayer(RenderController* renderController);
};


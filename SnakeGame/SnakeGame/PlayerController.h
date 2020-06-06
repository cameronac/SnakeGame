#pragma once
#include "SDL.h"
#include "Color.h"
#include "InputController.h"
#include "TailController.h"

class PlayerController
{  
	private:
		enum Direction {
			up, down, left, right
		};



	//Public Properties
	public:
		double xPosition = 32;
		double yPosition = 32;
		double spd = 3.0;

		//Render red filled quad
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		InputController* inputController;
		TailController tailController;
		Direction direction = right;
	
	//Public Methods
	public:
		PlayerController();
		PlayerController(InputController* inputController);
		~PlayerController();
		void checkPlayer();
};


#pragma once
#include "SDL.h"
#include "InputController.h"
#include "TailController.h"
#include "RenderController.h"

//Model Libraries
#include "Color.h"
#include "Direction.h"
#include "PositionHolder.h"

class PlayerController
{  
	//Public Properties
	public:
		int spd = 2;
		bool didChangeDirection = false;

		//Pointers
		PositionHolder* positionHolder;	//Player Position
		InputController* inputController;	//Input
		TailController* tailController;	

		SDL_Rect fillRect = {32, 32, 32, 32};
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
		Direction direction = Direction::right;
		
	
	//Public Methods
	public:
		PlayerController(InputController* inputController);	//Constructor
		~PlayerController();	//Destructor
		void checkPlayer();		//Updates the players positions, movement, collision, etc | Should be called every frame
		bool isColliding();		//Is the Head Colliding with a Tail
		void renderPlayer(RenderController* renderController); //Takes in a renderer and adds players elements to it to draw
};


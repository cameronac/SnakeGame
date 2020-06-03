#pragma once
#include "SDL.h"
#include "Color.h"

class PlayerController
{
	//Public Properties
	public:
		double xPosition = 32;
		double yPosition = 32;

		//Render red filled quad
		SDL_Rect fillRect = { 32, 32, 32, 32 };
		Color color = Color(0xFF, 0x00, 0x00, 0xFF);
	
	//Public Methods
	public:
		PlayerController();
		~PlayerController();
};


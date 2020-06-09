#pragma once
#include "SDL.h"

/*
	Handles all rendering tasks and displays objects added to the renderer
*/
class RenderController
{
	//Public Properties
	public:
		SDL_Window** window;
		SDL_Renderer* renderer;

	//Public Methods
	public:
		RenderController(SDL_Window** window);	//Constructor
		~RenderController(); //Destructor
		void DisplayRender();	//Displays Added Objects to the Renderer on the Screen
		void SetupBackground();	//Sets up backdrop of the window to the screen
};


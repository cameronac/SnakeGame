#pragma once
#include "SDL.h"

/*
	Controls all aspects of the Window| Including Window Size (Width, Height), 
	Name, Type, Spawn Position on the Screen, and Window Surface.
*/
class WindowController
{
	//Public Properties
	public:
		SDL_Window* window;
		SDL_Surface* windowSurface;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
	
	//Public Methods
	public:
		WindowController();	//Constructor
		~WindowController(); //Destructor

	//Private Methods
	private:
		void quit();
};


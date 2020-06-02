#pragma once
#include "SDL.h"

class WindowHandler
{
	//Public Properties
	public:
		SDL_Window* window;
		SDL_Surface* windowSurface;
	
	//Public Methods
	public:
		WindowHandler();
		~WindowHandler();

	//Private Methods
	private:
		void quit();
};


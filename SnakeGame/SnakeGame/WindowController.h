#pragma once
#include "SDL.h"

class WindowController
{
	//Public Properties
	public:
		SDL_Window* window;
		SDL_Surface* windowSurface;
	
	//Public Methods
	public:
		WindowController();
		~WindowController();

	//Private Methods
	private:
		void quit();
};


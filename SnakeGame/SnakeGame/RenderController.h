#pragma once
#include "SDL.h"

class RenderController
{
	//Public Properties
	public:
		SDL_Window** window = nullptr;
		SDL_Renderer* renderer;

	//Public Methods
	public:
		void DisplayRender();
		void SetupBackground();
		RenderController(SDL_Window** window);
		~RenderController();

	//Private Methods
	private:
		void RenderPresent();
};


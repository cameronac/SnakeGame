#pragma once
#include "SDL.h"

class RenderController
{
	//Private Properties
	private:
		SDL_Renderer* renderer;

	//Public Properties
	public:
		SDL_Window** window = nullptr;


	//Public Methods
	public:
		void DisplayRender();
		RenderController(SDL_Window** window);
		~RenderController();

	//Private Methods
	private:
		void SetupBackground();
		void RenderPresent();
};


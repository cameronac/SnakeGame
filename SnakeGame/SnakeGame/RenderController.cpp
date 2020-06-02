#include "RenderController.h"
#include <stdio.h>


//Initializer
RenderController::RenderController(SDL_Window** window)
{
	this->window = window;

	//Create Renderer
	this->renderer =
		SDL_CreateRenderer(&**window, -1, SDL_RENDERER_ACCELERATED); 

	if (renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
}

//De-initializer
RenderController::~RenderController()
{
	SDL_DestroyRenderer(renderer);
	free(window);
	renderer = NULL;
	window = NULL;
}


//Public Methods

///Refreshes Screen
void RenderController::DisplayRender()
{
	SetupBackground();
	//TODO: Assign Objects to Renderer
	RenderPresent();
}

//Private Methods
///Sets Up Background Before Rendering Objects Start
void RenderController::SetupBackground()
{
	if (SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF) == -1) {
		printf("Couldn't Set Render Draw Color");
	}

	SDL_RenderClear(renderer);
}

///Updates Screen With Newly assigned objects| Called At the end of DisplayRenderer
void RenderController::RenderPresent() {
	SDL_RenderPresent(renderer);
}
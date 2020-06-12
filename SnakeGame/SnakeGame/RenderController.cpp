#include "RenderController.h"
#include <stdio.h>


//Constructor
RenderController::RenderController()
{
	//Create Renderer
	renderer = SDL_CreateRenderer(&*WindowController::Get().window, -1, SDL_RENDERER_ACCELERATED);

	//Create Renderer
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
}

//Destructor
RenderController::~RenderController()
{
	SDL_DestroyRenderer(renderer);

	renderer = NULL;
}

//Public Methods
SDL_Renderer* RenderController::renderer = nullptr;

///Updates Screen With Newly assigned objects| Should always be called: When Objects are added and background is set then call this to display those objects
void RenderController::DisplayRender()
{
	SDL_RenderPresent(renderer);
}

///Sets Up Background Before Rendering Objects Start| Should always be called: Before calling DisplayRender()
void RenderController::SetupBackground()
{  
	if (SDL_SetRenderDrawColor(renderer, 0x80, 0xFF, 0x80, 0xFF) == -1) {
		printf("Couldn't Set Render Draw Color");
	}

	SDL_RenderClear(renderer);
}
#include "FPSController.h"
#include <stdio.h>

//Initializer
FPSController::FPSController()
{
	lastTime = SDL_GetTicks();
	deltaTime = 0.0;
}

//De-initializer 
FPSController::~FPSController()
{
}

//Public Methods
//Updated in the game loop to keep track of the games delta time
void FPSController::updateFPS()
{
	double startTime = SDL_GetTicks();
	double passedTime = startTime - lastTime;
	lastTime = startTime;
	deltaTime = lastTime * 0.01f;
}

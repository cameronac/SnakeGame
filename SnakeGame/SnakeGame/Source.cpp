#include <iostream>
#include <stdio.h>
#include "SDL.h"

//Managed Libraries
#include "WindowController.h"
#include "InputController.h"
#include "RenderController.h"
#include "GameController.h"

using namespace std;

//Application Starting Point
int main(int argc, char* args[]) {

	//Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		printf("SDL could not Initialize Video!");
	}

	//FPS Variables
	const int fps = 60;
	const int frameDelay = 1000 / fps;
	uint32_t frameStart;
	int frameTime;

	//Controller Objects
	WindowController& windowController = WindowController::Get(); //Handles Window Operations
	InputController& inputController = InputController::Get(); //Handles All Input
	RenderController& renderController = RenderController::Get(); //Handles basic Rendering Tasks
	GameController gameController = GameController(); //Handles Game State 

	//Game Loop
	while (inputController.Get().quit == false) {

		//Start FPS| Determine Ticks to control FPS at the End of the Loop
		frameStart = SDL_GetTicks();

		renderController.SetupBackground(); //Called first so we don't draw over objects
		inputController.checkInput(); // Checks all input including Window and Keyboard
		gameController.GameRefresh(); //Called before Display Render because it needs to add objects to the render first
		renderController.DisplayRender(); //Displays Basic Shapes from the GameController
		
		//End FPS| Delay   
		frameTime = SDL_GetTicks() - frameStart;
	
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return 0;
}
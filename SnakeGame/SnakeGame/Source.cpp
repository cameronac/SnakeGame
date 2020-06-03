#include <iostream>
#include <stdio.h>
#include "SDL.h"

//Managed Libraries
#include "WindowController.h"
#include "InputController.h"
#include "RenderController.h"
#include "GameController.h"
#include "FPSController.h"

using namespace std;

//Application Starting Point
int main(int argc, char* args[]) {

	//Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		printf("SDL could not Initialize Video!");
	}

	//Main Loop flag
	bool quitLoop = false;

	//Controller Objects
	FPSController fpsController = FPSController(); //Handles Delta Time which is used for SPD/Movement, etc
	WindowController windowController = WindowController(); //Handles Window Operations
	InputController inputController = InputController(&quitLoop); //Handles any Input
	RenderController renderController = RenderController(&windowController.window); //Handles basic Rendering Tasks
	GameController gameController = GameController(&renderController, &inputController, &fpsController); //Handles Game State 

	//Game Loop
	while (!quitLoop) {
		fpsController.updateFPS();

		renderController.SetupBackground(); //Called first so we don't draw over objects
		inputController.checkInput(); // Checks all input including Window and Keyboard
		gameController.GameRefresh(); //Called before Display Render because it needs to add objects to the render first
		renderController.DisplayRender(); //Displays Basic Shapes from the GameController
	}

	return 0;
}
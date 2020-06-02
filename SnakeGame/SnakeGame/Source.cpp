#include <iostream>
#include <stdio.h>
#include "SDL.h"

//Managed Libraries
#include "WindowController.h"
#include "InputController.h"
#include "RenderController.h"

using namespace std;

//Application Starting Point
int main(int argc, char* args[]) {

	//Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		printf("SDL could not Initialize Video!");
	}

	//Main Loop flag
	bool quitLoop = false;

	//Objects
	WindowController windowHandler = WindowController(); //Handles Window Operations
	InputController inputHandler = InputController(&quitLoop); //Handles any Input

	//Game Loop
	while (!quitLoop) {

		inputHandler.checkInput(); // Checks all input including Window and Keyboard
	}

	return 0;
}
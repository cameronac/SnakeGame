#include <iostream>
#include <stdio.h>
#include "SDL.h"

//Managed Libraries
#include "WindowHandler.h"
#include "InputHandler.h"

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
	WindowHandler windowHandler = WindowHandler(); //Handles Window Operations
	InputHandler inputHandler = InputHandler(&quitLoop); //Handles any Input


	//Game Loop
	while (!quitLoop) {

		inputHandler.checkInput(); // Checks all input including Window and Keyboard
	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "WindowHandler.h"

using namespace std;

//Application Starting Point
int main(int argc, char* args[]) {

	//Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		printf("SDL could not Initialize Video!");
	}

	//Objects
	WindowHandler windowHandler = WindowHandler(); //Handles Window Operations

	//Main Loop flag
	bool quitLoop = false;
	
	//Event Handler
	SDL_Event e;

	//Game Loop
	while (!quitLoop) {
		//Handle Events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit 
			if (e.type == SDL_QUIT) {
				quitLoop = true;
			}
		}
	}

	return 0;
}
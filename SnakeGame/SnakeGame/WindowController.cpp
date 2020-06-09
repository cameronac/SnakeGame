
#include "WindowController.h"
#include <stdio.h>


//Constructor
WindowController::WindowController() {
	//Creating Window
	window = SDL_CreateWindow("SnakeGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	
	//Get Window Surface
	windowSurface = SDL_GetWindowSurface(window);

	//Update Window Surface
	SDL_UpdateWindowSurface(window);
}

//Destructor
WindowController::~WindowController() {
	quit();
}

//Private Methods
//When Quiting Free/Destroy Variables in Memory
void WindowController::quit() {
	SDL_FreeSurface(windowSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
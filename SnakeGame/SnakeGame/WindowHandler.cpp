
#include "WindowHandler.h"
#include <stdio.h>


//Initializer
WindowHandler::WindowHandler() {
	//Creating Window
	window = SDL_CreateWindow("SnakeGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	
	//Get Window Surface
	windowSurface = SDL_GetWindowSurface(window);

	//Update Window Surface
	SDL_UpdateWindowSurface(window);
}

//De-initializer
WindowHandler::~WindowHandler() {
	quit();
	printf("Deallocated WindowHandler");
}

//Methods
void WindowHandler::quit() {
	SDL_FreeSurface(windowSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
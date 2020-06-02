#include <iostream>
#include <stdio.h>
#include "SDL.h"

using namespace std;

//Function Headers
void quit(SDL_Window* window);


//Application Starting Point
int main(int argc, char* args[]) {
	
	//Setting up surfaces
	SDL_Surface* surface = NULL;

	//Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		cout << "SDL could not Initialize Video!" << endl;
		return 1;
	}
	
	//Creating Window
	SDL_Window* window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	//Get Window Surface
	surface = SDL_GetWindowSurface(window);

	//Update Window Surface
	SDL_UpdateWindowSurface(window);

	SDL_Delay(3000); //window lasts 3 seconds
	quit(window);
	return 0;
}

//Functions
void quit(SDL_Window* window) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
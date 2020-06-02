#include "SDL.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = SDL_CreateWindow("An SDL2 window", 10, 25, 640, 480, SDL_WINDOW_OPENGL);

	SDL_Delay(3000); //window lasts 3 seconds
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
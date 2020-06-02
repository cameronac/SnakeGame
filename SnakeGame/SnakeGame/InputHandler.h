#pragma once
#include "SDL.h"

class InputHandler
{
private:
	SDL_Event event = SDL_Event();
	bool* quitLoop = NULL;

public:
	InputHandler(bool *quitLoop); //Initializer
	~InputHandler(); //De-initializer

	void checkInput(); //Checks all input methods| Should be in game loop

	void windowInput();	//Individual Input Methods
	void keyboardInput();
};


#pragma once
#include "SDL.h"

class InputController
{
private:
	SDL_Event event = SDL_Event();
	bool* quitLoop = NULL;

public:
	InputController(bool *quitLoop); //Initializer
	~InputController(); //De-initializer

	void checkInput(); //Checks all input methods| Should be in game loop

	void windowInput();	//Individual Input Methods
	void keyboardInput();
};


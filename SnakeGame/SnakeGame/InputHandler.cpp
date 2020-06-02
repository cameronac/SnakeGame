#include "InputHandler.h"
#include<stdio.h>
#include <string>

//Initializer
InputHandler::InputHandler(bool* quitLoop)
{
	this->quitLoop = quitLoop;
}

//De-initializer
InputHandler::~InputHandler()
{
	quitLoop = NULL;
}

//Checks all inputs
void InputHandler::checkInput()
{
	windowInput();
	keyboardInput();
}

//Handles Window Input| Quit, etc
void InputHandler::windowInput()
{
	//Handle Events on queue
	while (SDL_PollEvent(&event) != 0) {
		//User requests quit 
		if (event.type == SDL_QUIT) {
			*quitLoop = true;
		}
	}
}

//Handles Key Presses| Specifically Arrow Keys
void InputHandler::keyboardInput()
{
	//Handle Keyboard Events on queue
	if (event.type == SDL_KEYDOWN)
	{
		//Select surfaces based on key press
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			break;

		case SDLK_DOWN:
			break;

		case SDLK_LEFT:
			break;

		case SDLK_RIGHT:
			break;

		default:
			break;
		}
	}
}

#include "InputController.h"
#include<stdio.h>
#include <string>

//Initializer
InputController::InputController(bool* quitLoop)
{
	this->quitLoop = quitLoop;
}

//De-initializer
InputController::~InputController()
{
	quitLoop = NULL;
}

//Checks all inputs
void InputController::checkInput()
{

	spaceKey = false;

	//Handle Keyboard/Window Events on queue
	while (SDL_PollEvent(&event) != 0) {

		//Window Input
		//User requests quit 
		if (event.type == SDL_QUIT) {
			*quitLoop = true;
		}

		//Keyboard Input
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				upKey = true;
				break;

			case SDLK_DOWN:
				downKey = true;
				break;

			case SDLK_LEFT:
				leftKey = true;
				break;

			case SDLK_RIGHT:
				rightKey = true;
				break;

			case SDLK_SPACE:
				if (stopSpaceKey == false) {
					spaceKey = true;
					stopSpaceKey = true;
					printf("Space Pressed");
				}
				break;

			default:
				break;
			}
		}

		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				upKey = false;
				break;

			case SDLK_DOWN:
				downKey = false;
				break;

			case SDLK_LEFT:
				leftKey = false;
				break;

			case SDLK_RIGHT:
				rightKey = false;
				break;

			case SDLK_SPACE:
				stopSpaceKey = false;
				spaceKey = false;
				break;

			default:
				break;
			}
		}
	}
}

void InputController::resetKeys() {
	upKey = false;
	downKey = false;
	rightKey = false;
	leftKey = false;
	spaceKey = false;
}
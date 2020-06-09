#include "InputController.h"

//Constructor
InputController::InputController(bool* quitLoop)
{
	this->quitLoop = quitLoop;
}

//Desctructor 
InputController::~InputController()
{
	quitLoop = NULL;
}

//Public Methods 

//Checks all input types| Should be called so it can update every frame along with the application
void InputController::checkInput()
{
	//Resetting Keys
	spaceKey = false;

	//Handle Keyboard/Window Events on queue
	while (SDL_PollEvent(&event) != 0) {

		//Window Input
		//Quit Pressed
		if (event.type == SDL_QUIT) {
			*quitLoop = true;
		}

		//Keyboard Input

		//Pressed
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
				}
				break;

			default:
				break;
			}
		}

		//Released
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
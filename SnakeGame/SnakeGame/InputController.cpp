#include "InputController.h"

//Constructor
InputController::InputController()
{
}

//Desctructor 
InputController::~InputController()
{
}

//Static Definitions 
bool InputController::rightKey = false;
bool InputController::leftKey = false;
bool InputController::upKey = false;
bool InputController::downKey = false;
bool InputController::quit = false;
SDL_Event InputController::event = SDL_Event();

//Public Methods 

//Checks all input types| Should be called so it can update every frame along with the application
void InputController::checkInput()
{
	//Handle Keyboard/Window Events on queue
	while (SDL_PollEvent(&event) != 0) {

		//Window Input
		//Quit Pressed
		if (event.type == SDL_QUIT) {
			quit = true;
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

			default:
				break;
			}
		}
	}
}
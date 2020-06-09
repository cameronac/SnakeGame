#pragma once
#include "SDL.h"

/*
	Handles all Keyboard/Mouse Input
	Only one of these classes should be created
*/
class InputController
{
	//Private Properties
	private:
		SDL_Event event = SDL_Event();
		bool* quitLoop = NULL;
		bool stopSpaceKey = false;

	//Public Properties
	public: 
		bool rightKey = false;
		bool leftKey = false;
		bool upKey = false;
		bool downKey = false;
		bool spaceKey = false;

	//Public Methods
	public:
		InputController(bool *quitLoop); //Constructor
		~InputController(); //Destructor

		void checkInput(); //Checks all input types| Should be called so it can update every frame along with the application
};


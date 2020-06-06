#pragma once
#include "SDL.h"

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
		InputController(bool *quitLoop); //Initializer
		~InputController(); //De-initializer

		void checkInput(); //Checks all input methods| Should be in game loop
		void resetKeys();	//Sets all keys to false
};


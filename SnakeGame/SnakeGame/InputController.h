#pragma once
#include "SDL.h"

/*
	Singleton:
	Handles all Keyboard/Mouse Input
	Only one of these classes should be created
*/
class InputController
{
	//Private Properties
	private:
		static SDL_Event event;

	//Public Properties
	public:
		static bool quit;
		static bool rightKey;
		static bool leftKey;
		static bool upKey;
		static bool downKey;

	//Public Methods
	public:
		InputController(const InputController&) = delete;	//Copy Constructor

		//Get Input Object
		static InputController& Get() {
			static InputController instance;
			return instance;
		}

		static void checkInput(); //Checks all input types| Should be called so it can update every frame along with the application

	//Private Methods
	private:
		InputController(); //Constructor
		~InputController(); //Destructor

		
};


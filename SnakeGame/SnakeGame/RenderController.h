#pragma once
#include "SDL.h"
#include "WindowController.h"
#include <SDL_ttf.h>
/*
	Singleton:
	Handles all rendering tasks and displays objects added to the renderer
*/
class RenderController
{
	//Public Properties
	public:
		static SDL_Renderer* renderer;

	//Public Methods
	public:
		RenderController(const RenderController&) = delete; //Copy Constructor

		//Returns Singleton Object
		static RenderController& Get() {
			static RenderController instance;
			return instance;
		}
		static void DisplayRender();	//Displays Added Objects to the Renderer on the Screen
		static void SetupBackground();	//Sets up backdrop of the window to the screen


	//Public Methods
	private:
		RenderController();	//Constructor
		~RenderController(); //Destructor	
};


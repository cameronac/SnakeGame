#pragma once
#include "SDL.h"
#include "WindowController.h"
#include <SDL_ttf.h>
#include "TailController.h"

/*
	Singleton:
	Handles all rendering tasks and displays objects added to the renderer
*/
class RenderController
{
	//Public Properties
	public:
		static SDL_Renderer* renderer;
		static TTF_Font* font;
		static SDL_Texture* texture;
		static TailController* tailController;

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
		static void DisplayFont();

	//Public Methods
	private:
		RenderController();	//Constructor
		~RenderController(); //Destructor	
};


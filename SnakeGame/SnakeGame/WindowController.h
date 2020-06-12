#pragma once
#include "SDL.h"

/*
	Singleton Class:
	Controls all aspects of the Window| Including Window Size (Width, Height), 
	Name, Type, Spawn Position on the Screen, and Window Surface.
*/
class WindowController
{
	//Public Properties
	public:
		WindowController(const WindowController&) = delete;	//Copy Constructor

		//Returns Singleton Object
		static WindowController& Get() {
			static WindowController instance;	//In Static Memory So it will be referenced
			return instance;
		}

		SDL_Window* window;
		SDL_Surface* windowSurface;
		const static int SCREEN_WIDTH = 640;
		const static int SCREEN_HEIGHT = 480;
	
	//Private Methods
	private:
		WindowController();	//Constructor
		~WindowController(); //Destructor

	//Private Methods
	private:
		void quit();
};


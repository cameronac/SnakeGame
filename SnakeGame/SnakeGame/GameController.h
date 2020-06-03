#pragma once
#include "SDL.h"
#include "RenderController.h"
#include "InputController.h"
#include "PlayerController.h"
#include "FPSController.h"

class GameController
{
	//Public Variables
	public: 
		RenderController* renderController;
		InputController* inputController;
		FPSController* fpsController;
		PlayerController playerController;

	//Public Methods
	public:
		GameController(RenderController* renderController, InputController* inputController, FPSController* fpsController);
		~GameController();
		void GameRefresh();

	//Private Methods
	private:
		void togglePause();	//Pauses Game
		
};


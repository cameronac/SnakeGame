#pragma once
#include "SDL.h"
#include "RenderController.h"
#include "InputController.h"
#include "PlayerController.h"

class GameController
{
	//Public Variables
	public: 
		//Pointers
		RenderController* renderController;
		InputController* inputController;
		PlayerController* playerController;

	//Public Methods
	public:
		GameController(RenderController* renderController, InputController* inputController);
		~GameController();
		void GameRefresh();

	//Private Methods
	private:
		void togglePause();	//Pauses Game
		
};


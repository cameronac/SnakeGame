#pragma once
#include "SDL.h"
#include "RenderController.h"
#include "InputController.h"
#include "PlayerController.h"

/*
	Keeps Track of GameState and updates objects
*/
class GameController
{
	//Public Variables
	public: 
		RenderController* renderController;	//Renderer
		InputController* inputController;	//Input 
		PlayerController* playerController;	//Player

	//Public Methods
	public:
		GameController(RenderController* renderController, InputController* inputController); //Constructor
		~GameController();	//Destructor
		void GameRefresh();	//Refreshes Game by updating the current state of all objects and adds them to the renderer respectivley
		void RestartGame(); //Restarts the Game


	//Private Methods
	private:
		void togglePause();	//Pauses Game
		
};


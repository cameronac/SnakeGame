#pragma once
#include "SDL.h"
#include "RenderController.h"
#include "InputController.h"
#include "PlayerController.h"
#include "WindowController.h"
#include "Fruit.h"

/*
	Keeps Track of GameState and updates objects
*/
class GameController
{
	//Public Variables
	public: 
		RenderController* renderController = &RenderController::Get();	//Renderer
		InputController* inputController = &InputController::Get();	//Input 
		WindowController* windowController = &WindowController::Get(); //Window
		PlayerController* playerController;	//Player
		
		Fruit* fruit; //Fruit

	//Public Methods
	public:
		GameController(); //Constructor
		~GameController();	//Destructor
		void GameRefresh();	//Refreshes Game by updating the current state of all objects and adds them to the renderer respectivley
		void RestartGame(); //Restarts the Game
};


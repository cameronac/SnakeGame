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
		RenderController* renderController;	//Renderer
		InputController* inputController;	//Input 
		PlayerController* playerController;	//Player
		WindowController* windowController; //Window
		Fruit* fruit; //Fruit

	//Public Methods
	public:
		GameController(RenderController* renderController, InputController* inputController, WindowController* windowController); //Constructor
		~GameController();	//Destructor
		void GameRefresh();	//Refreshes Game by updating the current state of all objects and adds them to the renderer respectivley
		void RestartGame(); //Restarts the Game
};

